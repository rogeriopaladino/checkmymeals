#ifndef CCARTAOITEM_H
#define CCARTAOITEM_H

#include <QDeclarativeContext>
#include <QObject>
#include <QHash>
#include <QList>
#include <QVariant>
#include "cestudos.h"
#include "cenumsdefinitions.h"

class CEstudos;

class CCartaoItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString numero READ getNumero())
    Q_PROPERTY(QString descricao READ getDescricao())
    Q_PROPERTY(int bandeira READ getBandeira())
    Q_PROPERTY(CEstudos *estudos READ getEstudos())

public:
    enum Roles {
        numeroRole = Qt::UserRole + 1,
        descricaoRole,
        saldoRole,
        dataBeneficioRole,
        valorBeneficioRole,
        dataProximoBeneficioRole,
        valorProximoBeneficioRole,
        comprasRole,
        estudosRole,
        bandeiraRole
    };
    explicit CCartaoItem(QObject *parent = 0);
    ~CCartaoItem();
    void AdicionarCompra(int id, QString local, double valor, QDate data);

    static QHash<int, QByteArray> roleNames();
    QVariant data(int role);

    //sets
    void setDescricao(QString descricao);
    void setNumero(QString numero);
    void setSaldo(double saldo);
    void setDataBeneficio(QDate data);
    void setDataProximoBeneficio(QDate data);
    void setValorProximoBeneficio(double valor);
    void setValorBeneficio(double valor);
    void setBandeira(int bandeira);

    QString getNumero();
    QString getDescricao();
    double getSaldo();
    QDate getDataBeneficio();
    double getValorBeneficio();
    QDate getDataProximoBeneficio();
    double getValorProximoBeneficio();
    QList<QObject*> getCompras();
    CEstudos *getEstudos();
    int getBandeira();

private:
    QString _numero, _descricao;
    double _saldo, _valorBeneficio, _valorProximoBeneficio;
    QDate _dataBeneficio, _dataProximoBeneficio;
    QList<QObject*> _compras;
    CEstudos *_estudos;
    int _bandeira;

signals:
    void dataChanged();
    void atualizarEstudo();

public slots:
    void atualizarEstudoSlot(); //geral
    void atualizarEstudoSlot(const QString &numeroDaVez);

};

#endif // CCARTAOITEM_H
