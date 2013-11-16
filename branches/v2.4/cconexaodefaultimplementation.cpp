#include "cconexaodefaultimplementation.h"


CConexaoDefaultImplementation::CConexaoDefaultImplementation(QObject *parent)
    :QObject(parent)
{
    _net = new QNetworkAccessManager(this);
}

void CConexaoDefaultImplementation::Consultar(const QString &cartao)
{
    this->AdicionarParaConsulta(cartao);
    this->IniciarCosulta();
}

void CConexaoDefaultImplementation::AdicionarParaConsulta(const QString &cartao)
{
    _cartoes.append(cartao);
}

void CConexaoDefaultImplementation::IniciarCosulta()
{
    if (_cartoes.count() > 0) {
        QString cartao = _cartoes.at(0);
        emit iniciandoConsulta(cartao);
        _cancelar = false;
        QNetworkRequest r = this->MontarRequisicao(cartao);
        if (r.url().path() != "")
        {
            QNetworkReply *reply = _net->get(r);
            QObject::connect(reply, SIGNAL(finished()), this, SLOT(consultaFinalizadaResposta()));
            QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(baixandoPagina()));
            QObject::connect(this, SIGNAL(erroConexao()), this, SLOT(erroConexaoHandlerSlot()));
        }
        else
        {
            emit consultaCartaoFinalizada(cartao, "", _bandeira);
        }
    }
}

void CConexaoDefaultImplementation::Cancelar()
{
    _cancelar = true;
    emit consultaCancelada();
}

QNetworkRequest CConexaoDefaultImplementation::MontarRequisicao(const QString &cartao)
{
    return QNetworkRequest();
}

void CConexaoDefaultImplementation::consultaFinalizadaResposta()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(this->sender());
    QString cartao = _cartoes.at(0);
    _cartoes.pop_front();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray resposta = reply->readAll();
        reply->close();
        reply->deleteLater();
        emit consultaCartaoFinalizada(cartao, resposta, _bandeira);
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

void CConexaoDefaultImplementation::baixandoPagina()
{
    if (_cancelar) {
        _cancelar = false;
        QNetworkReply *objNet = qobject_cast<QNetworkReply*>(this->sender());
        objNet->abort();
        objNet->deleteLater();
        _cartoes.clear();
    }
}

void CConexaoDefaultImplementation::erroConexaoHandlerSlot()
{
    _cartoes.clear();
}
