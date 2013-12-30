#ifndef CCONEXAO_H
#define CCONEXAO_H

#include <QObject>
#include <QNetworkRequest>
#include <QList>
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
    Q_INVOKABLE void IniciarConsulta();
    Q_INVOKABLE void Cancelar();

protected:

private:
    QList<CConexaoDefaultImplementation*> _impls;
    int _implsCountFinished, _implsCountError, _implsCountCancel, _implsActiveCards;

    void Factory();
    void BindSignals();
    inline bool FinalDoProcessamento();
    
signals:
    
public slots:
    void consultaCanceladaSlot();
    void consultaCartaoFinalizadaSlot(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira);
    void consultaFinalizadaSlot();
    void erroConexaoSlot();
    void iniciandoConsultaSlot(const QString &cartao);
    void processamentoFinalSlot();
};

#endif // CCONEXAO_H
