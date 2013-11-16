#ifndef CCONEXAO_H
#define CCONEXAO_H

#include <QObject>
#include <QNetworkRequest>
#include <QList>
#include <QMutex>
#include "cconexaodefaultimplementation.h"
#include "cvisa.h"
#include "cticket.h"
#include "cenumsdefinitions.h"

class CConexao : public CConexaoDefaultImplementation
{
    Q_OBJECT

public:    
    explicit CConexao(QObject *parent = 0);
    Q_INVOKABLE void Consultar(const QString &cartao, int bandeira);
    Q_INVOKABLE void AdicionarParaConsulta(const QString &cartao, int bandeira);
    Q_INVOKABLE void IniciarCosulta();
    Q_INVOKABLE void Cancelar();

protected:

private:
    QList<CConexaoDefaultImplementation*> _impls;
    QMutex _lock;
    int _implsCountFinished, _implsCountError;

    void Factory();
    void BindSignals();
    
signals:
    
public slots:
    void consultaCanceladaSlot();
    void ConsultaCartaoFinalizadaSlot(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira);
    void ConsultaFinalizadaSlot();
    void erroConexaoSlot();
    void iniciandoConsultaSlot(const QString &cartao);
};

#endif // CCONEXAO_H
