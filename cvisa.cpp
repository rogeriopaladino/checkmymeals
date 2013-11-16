#include "cvisa.h"

CVisa::CVisa(QObject *parent)     
    :CConexaoDefaultImplementation(parent),
      _urlConsulta("http://www.cartoesbeneficio.com.br/inst/convivencia/SaldoExtrato.jsp?numeroCartao=%1&periodoSelecionado=%2"),
      _urlReferer("http://www.cartoesbeneficio.com.br/inst/SaldoExtratoFiltro.jsp")
{
    _bandeira = CEnumsDefinitions::Visa;
}

CVisa::~CVisa()
{    
}

/*void CVisa::IniciarCosulta()
{
    if (_cartoes.count() > 0) {
        QString cartao = _cartoes.at(0);        
        emit iniciandoConsulta(cartao);
        _cancelar = false;
        _net = new QNetworkAccessManager(this);
        QNetworkRequest r(this->UrlParaConsulta(cartao, true));
        r.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");
        QByteArray referer;
        r.setRawHeader(QByteArray("Referer"), referer.append(_urlReferer));
        QNetworkReply *reply = _net->get(r);
        QObject::connect(reply, SIGNAL(finished()), this, SLOT(consultaFinalizadaResposta()));
        QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(baixandoPagina()));
        QObject::connect(this, SIGNAL(erroConexao()), this, SLOT(erroConexaoHandlerSlot()));
    }
}*/

/*void CVisa::consultaFinalizadaResposta()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(this->sender());
    QString cartao = _cartoes.at(0);
    _cartoes.pop_front();        
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray resposta = reply->readAll();
        reply->close();
        reply->deleteLater();
        emit consultaCartaoFinalizada(cartao, resposta);
        if (_cartoes.count() == 0)
            emit consultaFinalizada();
        else
            IniciarCosulta();
    } else if (reply->error() == QNetworkReply::OperationCanceledError) {
        reply->deleteLater();
    } else {
        reply->abort();
        reply->deleteLater();
        emit erroConexao();
    }
}*/

/*void CVisa::baixandoPagina()
{
    if (_cancelar) {
        _cancelar = false;
        QNetworkReply *objNet = qobject_cast<QNetworkReply*>(this->sender());
        objNet->abort();
        objNet->deleteLater();        
        _cartoes.clear();
    }
}*/

QUrl CVisa::UrlParaConsulta(QString cartao, bool todasAnteriores)
{
    char tpConsultaOk = '0';
    if (todasAnteriores)
        tpConsultaOk = '4';
    return QUrl(_urlConsulta.arg(cartao).arg(tpConsultaOk));
}

/*void CVisa::Cancelar()
{
    _cancelar = true;
    emit consultaCancelada();
}*/

bool CVisa::PossoProcessar(int bandeira)
{
    return bandeira == _bandeira;
}

QNetworkRequest CVisa::MontarRequisicao(const QString &cartao)
{
    QNetworkRequest r(this->UrlParaConsulta(cartao, true));
    r.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");
    QByteArray referer;
    r.setRawHeader(QByteArray("Referer"), referer.append(_urlReferer));
    return r;
}

/*void CVisa::erroConexaoHandlerSlot()
{
    _cartoes.clear();    
}*/
