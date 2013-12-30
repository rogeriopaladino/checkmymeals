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

QUrl CVisa::UrlParaConsulta(QString cartao, bool todasAnteriores)
{
    char tpConsultaOk = '0';
    if (todasAnteriores)
        tpConsultaOk = '4';
    return QUrl(_urlConsulta.arg(cartao).arg(tpConsultaOk));
}

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
