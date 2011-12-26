#include "cestudos.h"

CEstudos::CEstudos(QObject *parent, CCartaoItem *cartao) :
    QObject(parent)
{
    _cartao = cartao;
    _maiorCompra = new CCompraItem(this);
    _ultimaCompra = new CCompraItem(this);
    _gastoMedioDiario = 0;
    _localFavorito = "";
    _vezesNoLocalFavorito = 0;
}

CEstudos::~CEstudos()
{
    _cartao = NULL;
}

void CEstudos::GastoMedio()
{
    if (_cartao != NULL) {
        double saldo = _cartao->getSaldo();
        QDate now = QDate::currentDate();
        QDate benef = _cartao->getDataBeneficio();
        QDate proxBenef = _cartao->getDataProximoBeneficio();
        int diasRestantes = 0, diasUteis = 0;
        if (!proxBenef.isNull())
            diasRestantes = now.daysTo(proxBenef);
        else if (!benef.isNull())
            diasRestantes = now.daysTo(benef.addMonths(1));
        double gastoMedioDiario = 0;
        if (diasRestantes > 0) {
            for(int i = 0; i <= diasRestantes; i++) {
                int diaSemana = now.addDays(i).dayOfWeek();
                if ((diaSemana != 6) && (diaSemana != 7))
                    diasUteis++;
            }
            gastoMedioDiario = saldo / diasUteis;
        }
        setGastoMedioDiario(gastoMedioDiario);
    }
}

void CEstudos::MaiorCompra()
{
    if (_cartao != NULL) {
        QSqlQuery q(QSqlDatabase::database("default"));
        q.prepare("select idCompra, data, local, valor "
                  "from compra "
                  "where numero = :numero "
                  "order by valor desc ");
        q.bindValue(":numero", _cartao->getNumero());
        q.exec();        
        if (q.next()) {
            _maiorCompra->setId(q.value(0).toInt());
            _maiorCompra->setData(q.value(1).toDate());
            _maiorCompra->setLocal(q.value(2).toString());
            _maiorCompra->setValor(q.value(3).toDouble());
        }
    }
}

void CEstudos::LocalFavorito()
{
    if (_cartao != NULL) {
        QSqlQuery q(QSqlDatabase::database("default"));
        q.prepare("select local, count(*) vezes "
                  "from compra "
                  "where numero = :numero "
                  "group by local "
                  "order by count(*) desc ");
        q.bindValue(":numero", _cartao->getNumero());
        q.exec();
        if (q.next()) {
            setLocalFavorito(q.value(0).toString());
            setVezesNoLocalFavorito(q.value(1).toInt());
        }
    }
}

CCompraItem * CEstudos::getMaiorCompra()
{
    return _maiorCompra;
}

double CEstudos::getGastoMedioDiario()
{
    return _gastoMedioDiario;
}

QString CEstudos::getLocalFavorito()
{
    return _localFavorito;
}

int CEstudos::getVezesNoLocalFavorito()
{
    return _vezesNoLocalFavorito;
}

void CEstudos::setGastoMedioDiario(double gastoMedioDiario)
{
    _gastoMedioDiario = gastoMedioDiario;
}

void CEstudos::setLocalFavorito(QString local)
{
    _localFavorito = local;
}

void CEstudos::setVezesNoLocalFavorito(const int &vezes)
{
    _vezesNoLocalFavorito = vezes;
}

void CEstudos::calcularSlot()
{
    if (_cartao) {
        this->GastoMedio();
        this->MaiorCompra();
        this->LocalFavorito();
        this->UltimaCompra();
        emit dataChanged();
    }
}

CCompraItem * CEstudos::getUltimaCompra()
{
    return _ultimaCompra;
}

void CEstudos::UltimaCompra()
{
    if (_cartao) {
        QSqlQuery q(QSqlDatabase::database("default"));
        q.prepare("select idCompra, local, data, valor "
                  "from compra "
                  "where numero = :numero "
                  "order by data desc, idCompra desc "
                  "limit 0, 1");
        q.bindValue(":numero", _cartao->getNumero());
        q.exec();
        if (q.next()) {
            _ultimaCompra->setId(q.value(0).toInt());
            _ultimaCompra->setLocal(q.value(1).toString());
            _ultimaCompra->setData(q.value(2).toDate());
            _ultimaCompra->setValor(q.value(3).toDouble());
        }
    }
}


