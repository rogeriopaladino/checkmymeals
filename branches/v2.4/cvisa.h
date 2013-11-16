#ifndef CVISA_H
#define CVISA_H

#include <QObject>
#include <QtNetwork/qnetworkrequest.h>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>
#include "cconexaodefaultimplementation.h"
#include "cconexaoimplementationspecificinterface.h"

class CVisa : public CConexaoDefaultImplementation, public CConexaoImplementationSpecificInterface
{
    Q_OBJECT
    Q_INTERFACES(CConexaoImplementationSpecificInterface)

public:
    explicit CVisa(QObject *parent = 0);
    virtual ~CVisa();
    bool PossoProcessar(int bandeira);

protected:
    QNetworkRequest MontarRequisicao(const QString &cartao);

private:
    /*QNetworkAccessManager *_net;
    bool _cancelar;
    QStringList _cartoes;*/
    QUrl UrlParaConsulta(QString cartao, bool todasAnteriores);
    const QString _urlConsulta, _urlReferer;

signals:    
    /*void consultaFinalizada();
    void iniciandoConsulta(const QString &cartao);
    void consultaCartaoFinalizada(const QString &cartao, const QString &extrato);
    void consultaCancelada();
    void erroConexao();*/

public slots:
    /*void consultaFinalizadaResposta();
    void baixandoPagina();
    void erroConexaoHandlerSlot();*/
};

#endif // CVISA_H
