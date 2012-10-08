#include "cvisa.h"

CVisa::CVisa(QObject *parent)
    :QObject(parent)/*,
      _lote(false)*/
{    
}

CVisa::~CVisa()
{    
}

void CVisa::Consultar(const QString &cartao)
{
    this->AdicionarParaConsulta(cartao);
    this->IniciarCosulta();
}

void CVisa::AdicionarParaConsulta(const QString &cartao)
{
    _cartoes.append(cartao);
}

void CVisa::IniciarCosulta()
{
    if (_cartoes.count() > 0) {
        QString cartao = _cartoes.at(0);        
        emit iniciandoConsulta(cartao);
        _cancelar = false;
        _net = new QNetworkAccessManager(this);
        QNetworkRequest r(this->UrlParaConsulta(cartao, true));
        r.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");
        QNetworkReply *reply = _net->get(r);
        QObject::connect(reply, SIGNAL(finished()), this, SLOT(consultaFinalizadaResposta()));
        QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(baixandoPagina()));
        QObject::connect(this, SIGNAL(erroConexao()), this, SLOT(erroConexaoHandlerSlot()));
    }
}

void CVisa::consultaFinalizadaResposta()
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
}

void CVisa::baixandoPagina()
{
    if (_cancelar) {
        _cancelar = false;
        QNetworkReply *objNet = qobject_cast<QNetworkReply*>(this->sender());
        objNet->abort();
        objNet->deleteLater();        
        _cartoes.clear();
    }
}

QUrl CVisa::UrlParaConsulta(QString cartao, bool todasAnteriores)
{
    static QString urlPadrao("http://www.cartoesbeneficio.com.br/inst/convivencia/SaldoExtrato.jsp?numeroCartao=%1&periodoSelecionado=%2");
    char tpConsultaOk = '0';
    if (todasAnteriores)
        tpConsultaOk = '4';
    return QUrl(urlPadrao.arg(cartao).arg(tpConsultaOk));
}

void CVisa::Cancelar()
{
    _cancelar = true;
    emit consultaCancelada();
}

void CVisa::erroConexaoHandlerSlot()
{
    _cartoes.clear();
    //_lote = false;
}
