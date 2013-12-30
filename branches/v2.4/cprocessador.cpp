#include "cprocessador.h"

CProcessador::CProcessador(QObject *parent) :
    QObject(parent)
{
}

void CProcessador::processadorExtrato(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira)
{
    switch(bandeira)
    {
        case CEnumsDefinitions::Visa:
            this->processadorVisa(cartao, extrato);
            break;
        case CEnumsDefinitions::Ticket:
            this->processadorTicket(cartao, extrato);
            break;
        default:
            emit bandeiraNaoSuportada(cartao);
    }
}

QDate CProcessador::CriarData(int dia, int mes)
{
    QDate ret;
    int ano;
    if (mes > ret.currentDate().month())
        ano = ret.currentDate().year() - 1;
    else
        ano = ret.currentDate().year();
    ret.setDate(ano, mes, dia);
    return ret;
}

QDate CProcessador::CriarDataBeneficioDepositado(const QString &diaMes)
{
    QStringList dataLst = diaMes.split('/');
    int dia, mes;
    dia = dataLst[0].toInt();
    mes = dataLst[1].toInt();
    return this->CriarDataBeneficioDepositado(dia, mes);
}

QDate CProcessador::CriarDataBeneficioDepositado(int dia, int mes)
{
    QDate ret;
    int ano;
    if (mes > ret.currentDate().month())
        ano = ret.currentDate().year() - 1;
    else
        ano = ret.currentDate().year();
    ret.setDate(ano, mes, dia);
    return ret;
}

QDate CProcessador::CriarDataBeneficio(int dia, int mes)
{
    QDate ret;
    int ano;
    if (mes < ret.currentDate().month())
        ano = ret.currentDate().year() + 1;
    else
        ano = ret.currentDate().year();
    ret.setDate(ano, mes, dia);
    return ret;
}

bool CProcessador::IsCredito(const QString &local) const
{
    QRegExp rx;
    rx.setMinimal(false);
    rx.setPatternSyntax(QRegExp::RegExp2);
    rx.setPattern("Disponibiliza[cç][aã]o de Benef[ií]cio");
    return rx.indexIn(local) != -1;
}

void CProcessador::processadorVisa(const QString &cartao, const QString &extrato)
{
    if (extrato != "")
    {
        QRegExp regex;
        regex.setMinimal(true);
        regex.setPatternSyntax(QRegExp::RegExp2);
        regex.setCaseSensitivity(Qt::CaseInsensitive);
        regex.setPattern("Cartão inválido");
        if (regex.indexIn(extrato) > 0)
        {
            emit cartaoInvalido(cartao);
        }
        else
        {
            regex.setPattern("indisponível no momento");
            if (regex.indexIn(extrato) > 0)
            {
                emit sistemaForaDoAr();
            }
            else
            {
                QString numeroCartao("");
                QString saldoDisponivel("");
                QString dataBeneficio("");
                QString valorBeneficio("");
                QString dataProximoBeneficio("");
                QString valorProximoBeneficio("");
                regex.setPattern("N&uacute;mero do cart&atilde;o:.+(\\d{16})<\\/td>");
                if (regex.indexIn(extrato) > 0)
                    numeroCartao = regex.cap(1);
                regex.setPattern("Saldo dispon&iacute;vel:.+R\\$\\s*([\\d,]+)<\\/td>");
                if (regex.indexIn(extrato) > 0)
                    saldoDisponivel = regex.cap(1);
                regex.setPattern("Data da &uacute;ltima disponibiliza&ccedil;&atilde;o do benef&iacute;cio:.*<td.*>(\\d\\d\\/\\d\\d)<\\/td>\\W*<td.*>Valor:R\\$([\\d,]+)<\\/td>");
                if (regex.indexIn(extrato) > 0)
                {
                    dataBeneficio = regex.cap(1);
                    valorBeneficio = regex.cap(2);
                }
                regex.setPattern("Data da pr&oacute;xima disponibiliza&ccedil;&atilde;o do benef&iacute;cio:.*<td.*>(\\d\\d\\/\\d\\d)<\\/td>\\W*<td.*>Valor:R\\$([\\d,]+)<\\/td>");
                if (regex.indexIn(extrato) > 0)
                {
                    dataProximoBeneficio = regex.cap(1);
                    valorProximoBeneficio = regex.cap(2);
                }
                //qDebug() << extrato;
                if (valorProximoBeneficio != "")
                {
                    QStringList dataLstPB;
                    dataLstPB = dataProximoBeneficio.split('/');
                    QDate dataProximoBeneficio = this->CriarDataBeneficio(dataLstPB[0].toInt(), dataLstPB[1].toInt());
                    emit informacaoProximoBeneficio(numeroCartao, dataProximoBeneficio, valorProximoBeneficio.toDouble());
                }
                emit informacoesCartao(numeroCartao, saldoDisponivel.toDouble());
                regex.setPattern("<tr class=\"rowTable\">\\W+<td style=\"width:50px\">(\\d\\d\\/\\d\\d)<\\/td>\\W*<td style=\"width:400px\">(.*)<\\/td>\\W*<td class=\"corUm\" style=\"width:50px\" align=\"right\">R\\$&nbsp;([\\d,]+)<\\/td>");
                int k = 0, dia, mes;
                bool ok, compraEfetuada, houveCredito = false;
                QString localStr, valorStr, dataStr;
                QDate data;
                double valor;
                QStringList dataLst;
                while ((k = regex.indexIn(extrato, k)) > 0)
                {
                    compraEfetuada = true;
                    localStr = regex.cap(2);
                    valorStr = regex.cap(3);
                    dataStr = regex.cap(1);
                    dataLst = dataStr.split('/');
                    dia = dataLst[0].toInt(&ok, 10);
                    if (ok)
                        mes = dataLst[1].toInt(&ok, 10);
                    if (ok)
                    {
                        data = this->CriarData(dia, mes);
                        valor = valorStr.replace(',', '.').toDouble(&ok);
                        if (ok)
                        {
                            if (this->IsCredito(localStr))
                            {
                                houveCredito = true;
                                data = this->CriarDataBeneficioDepositado(dia, mes);
                                emit informacaoBeneficio(numeroCartao, data, valor);
                            }
                            else
                                emit compraAnalisada(numeroCartao, localStr, data, valor);
                        }
                    }
                    k += regex.matchedLength();
                }
                /*apenas para garantir, pois pode acontecer de o crédito não estar presente
                  no extrato do cartão.*/
                if (!houveCredito)
                {
                    data = this->CriarDataBeneficioDepositado(dataBeneficio);
                    valor = valorBeneficio.toDouble();
                    emit informacaoBeneficio(numeroCartao, data, valor);
                }
                emit cartaoAtualizado(numeroCartao);
                if (!compraEfetuada)
                {
                    emit nenhumaCompraEfetuada(numeroCartao);
                }
            }
        }
    }
    else
    {
        emit sistemaForaDoAr();
    }
}

void CProcessador::processadorTicket(const QString &cartao, const QString &extrato)
{
    if (extrato != "")
    {
        QRegExp rx;
        rx.setMinimal(true);
        rx.setCaseSensitivity(Qt::CaseInsensitive);
        rx.setPatternSyntax(QRegExp::RegExp2);
        //saldo atual do cartão
        rx.setPattern("balance.*\"value\"\\:\"(.*)\"");
        int k;
        if ((k = rx.indexIn(extrato)) != -1)
        {            
            QString valorDisponivel = rx.cap(1);
            emit informacoesCartao(cartao, valorDisponivel.toDouble());
            k += rx.matchedLength();
            rx.setPattern("\"date\":\"([\\d]{2}\\/[\\d]{2}\\/[\\d]{4})\"\\,\"value\":\"([\\d\\,]+)\"\\,\"description\":\"(COMPRAS|DISPONIB. DE CREDITO) - (.*)\"");
            bool houveCompra = false;
            while ((k = rx.indexIn(extrato, k)) != -1)
            {
                QString operacao, descricao;
                double valor;
                QDate data;
                valor = rx.cap(2).toDouble();
                qDebug() << rx.cap(1);
                data = QDate::fromString(rx.cap(1), "dd/MM/yyyy");
                operacao = rx.cap(3);
                descricao = rx.cap(4);
                if (operacao == "COMPRAS")
                {
                    houveCompra = true;
                    emit compraAnalisada(cartao, descricao, data, valor);
                }
                else if (operacao == "DISPONIB. DE CREDITO")
                {
                    emit informacaoBeneficio(cartao, data, valor);
                }
                else
                {
                    //verificar quando for outro evento
                    qDebug() << "NÃO DETECTADO - " << rx.cap(0);
                }
                k += rx.matchedLength();
            }
            emit cartaoAtualizado(cartao);
            if (!houveCompra)
                emit nenhumaCompraEfetuada(cartao);
        }
        else
        {
            emit cartaoInvalido(cartao);
        }
    }
}

