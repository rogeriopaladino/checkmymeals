#ifndef CCONEXAODEFAULTIMPLEMENTATIONINTERFACE_H
#define CCONEXAODEFAULTIMPLEMENTATIONINTERFACE_H

#include <QObject>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QStringList>
#include "cenumsdefinitions.h"

class CConexaoDefaultImplementation : public QObject
{
    Q_OBJECT    

public:    

    CConexaoDefaultImplementation(QObject *parent = 0);
    Q_INVOKABLE virtual void Consultar(const QString &cartao);
    Q_INVOKABLE virtual void AdicionarParaConsulta(const QString &cartao);
    Q_INVOKABLE virtual void IniciarCosulta();
    Q_INVOKABLE virtual void Cancelar();

protected:
    QNetworkAccessManager *_net;
    QStringList _cartoes;
    bool _cancelar;
    //deve ser setado na classe filha
    CEnumsDefinitions::TipoBandeiraCartaoEnum _bandeira;

    virtual QNetworkRequest MontarRequisicao(const QString &cartao);

signals:
    void consultaFinalizada();
    void iniciandoConsulta(const QString &cartao);
    void consultaCartaoFinalizada(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira);
    void consultaCancelada();
    void erroConexao();

public slots:
    void consultaFinalizadaResposta();
    void baixandoPagina();
    void erroConexaoHandlerSlot();
};


#endif // CCONEXAOPRIVATE_H
