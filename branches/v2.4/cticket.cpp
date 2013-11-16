#include "cticket.h"

CTicket::CTicket(QObject *parent)
    :CConexaoDefaultImplementation(parent),
      _urlToken("http://www.ticket.com.br/portal-web/consult-card/balance/json?chkProduto=TR&card=%1"),
      _urlReferer("http://www.ticket.com.br/portal/portalcorporativo/home/home.htm"),
      _urlExtrato("http://www.ticket.com.br/portal-web/consult-card/release/json?txtOperacao=lancamentos&token=%1&card=%2&rows=50")
{
    _bandeira = CEnumsDefinitions::Ticket;
}

CTicket::~CTicket()
{
}


bool CTicket::PossoProcessar(int bandeira)
{
    return bandeira == _bandeira;
}

QNetworkRequest CTicket::MontarRequisicao(const QString &cartao)
{
    //primeiro é necessário o token
    QEventLoop espera;
    QNetworkRequest r(_urlToken.arg(cartao));
    r.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray referer;
    referer.append(_urlToken);
    r.setRawHeader(QByteArray("Referer"), referer);
    r.setRawHeader(QByteArray("X-Requested-With"), QByteArray("XMLHttpRequest"));
    QNetworkReply *response = _net->get(r);
    QObject::connect(response, SIGNAL(finished()), &espera, SLOT(quit()));
    espera.exec();
    QString resultado = QString(response->readAll());
    response->deleteLater();
    qDebug() << resultado;
    QRegExp rx("\"token\"\\:\"(.*)\"", Qt::CaseInsensitive, QRegExp::RegExp2);
    rx.setMinimal(true);
    if (rx.indexIn(resultado) > 0)
    {
        QString token = rx.cap(1);
        r.setUrl(_urlExtrato.arg(token).arg(cartao));
        return r;
    }
    else
    {
        return QNetworkRequest();
    }
}
