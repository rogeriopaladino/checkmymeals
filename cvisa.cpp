#include "cvisa.h"

CVisa::CVisa(QObject *parent)
    :QObject(parent)
{
}

CVisa::~CVisa()
{    
}

void CVisa::Consultar(const QString &cartao, bool todasAnteriores)
{    
    emit iniciandoConsulta(cartao);
    _cancelar = false;
    _net = new QNetworkAccessManager(this);
    QNetworkRequest r(this->UrlParaConsulta(cartao, todasAnteriores));
    r.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");
    QNetworkReply *reply = _net->get(r);
    this->connect(reply, SIGNAL(finished()), this, SLOT(consultaFinalizadaResposta()));        
    this->connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(baixandoPagina()));
}

void CVisa::consultaFinalizadaResposta()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(this->sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray resposta = reply->readAll();        
        reply->close();
        reply->deleteLater();
        emit consultaFinalizada(resposta);
    } else
        emit erroConexao();
}

void CVisa::baixandoPagina()
{
    if (_cancelar) {
        _cancelar = false;
        QNetworkReply *objNet = qobject_cast<QNetworkReply*>(this->sender());
        objNet->abort();
        objNet->deleteLater();
        emit consultaCancelada();
    }
}

QUrl CVisa::UrlParaConsulta(QString cartao, bool todasAnteriores)
{
    static QString urlPadrao("http://www.cbss.com.br/inst/convivencia/SaldoExtrato.jsp?numeroCartao=%1&periodoSelecionado=%2");
    char tpConsultaOk = '0';
    if (todasAnteriores)
        tpConsultaOk = '4';
    return QUrl(urlPadrao.arg(cartao).arg(tpConsultaOk));
}

void CVisa::Cancelar()
{
    _cancelar = true;
}
