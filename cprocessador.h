#ifndef CPROCESSADOR_H
#define CPROCESSADOR_H

#include <QObject>
#include <QDate>
#include <QRegExp>
#include <QStringList>
#include <QDebug>
#include "cenumsdefinitions.h"

class CProcessador : public QObject
{
    Q_OBJECT

public:
    explicit CProcessador(QObject *parent = 0);

private:
    QDate CriarData(int dia, int mes);
    QDate CriarDataBeneficioDepositado(const QString &diaMes);
    QDate CriarDataBeneficioDepositado(int dia, int mes);
    QDate CriarDataBeneficio(int dia, int mes);
    bool IsCredito(const QString &local) const;

    void processadorVisa(const QString &cartao, const QString &extrato);
    void processadorTicket(const QString &cartao, const QString &extrato);

signals:
    void cartaoInvalido(const QString cartao);
    void cartaoAtualizado(const QString &cartao);
    void nenhumaCompraEfetuada(const QString &cartao);
    void sistemaForaDoAr();
    void compraAnalisada(const QString &numero, const QString &local, const QDate data, const double &valor);    
    void informacoesCartao(const QString &numero, const double &saldo);
    void informacaoBeneficio(const QString &numero, const QDate &data, const double &valor);
    void informacaoProximoBeneficio(const QString &numero, const QDate &data, const double &valor);
    void bandeiraNaoSuportada(const QString &numero);

public slots:
    void processadorExtrato(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira);

};

#endif // CPROCESSADOR_H
