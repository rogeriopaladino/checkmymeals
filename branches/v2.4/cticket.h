#ifndef CTICKET_H
#define CTICKET_H

#include <QObject>
#include <QString>
#include <QEventLoop>
#include <QDebug>
#include <QRegExp>
#include "cconexaodefaultimplementation.h"
#include "cconexaoimplementationspecificinterface.h"

class CTicket : public CConexaoDefaultImplementation, public CConexaoImplementationSpecificInterface
{
    Q_OBJECT    
    Q_INTERFACES(CConexaoImplementationSpecificInterface)

public:
    explicit CTicket(QObject *parent = 0);
    virtual ~CTicket();
    bool PossoProcessar(int bandeira);
    
protected:
    QNetworkRequest MontarRequisicao(const QString &cartao);

private:
    const QString _urlToken, _urlReferer, _urlExtrato;

signals:    
    /*void consultaFinalizada();
    void iniciandoConsulta(const QString &cartao);
    void consultaCartaoFinalizada(const QString &cartao, const QString &extrato);
    void consultaCancelada();
    void erroConexao();*/
    
public slots:

    
};

#endif // CTICKET_H
