#ifndef CESTUDOS_H
#define CESTUDOS_H

#include <QObject>
#include <QtSql>
#include "ccompraitem.h"
#include "ccartaoitem.h"

class CCartaoItem;

class CEstudos : public QObject
{
    Q_OBJECT

    Q_PROPERTY(CCompraItem *maiorCompra READ getMaiorCompra NOTIFY dataChanged)
    Q_PROPERTY(double gastoMedioDiario READ getGastoMedioDiario WRITE setGastoMedioDiario NOTIFY dataChanged)
    Q_PROPERTY(QString localFavorito READ getLocalFavorito WRITE setLocalFavorito NOTIFY dataChanged)
    Q_PROPERTY(int vezesNoLocalFavorito READ getVezesNoLocalFavorito WRITE setVezesNoLocalFavorito NOTIFY dataChanged)
    Q_PROPERTY(CCompraItem *ultimaCompra READ getUltimaCompra NOTIFY dataChanged)

public:
    explicit CEstudos(QObject *parent = 0, CCartaoItem* cartao = 0);
    ~CEstudos();
    //gets
    CCompraItem *getMaiorCompra();
    double getGastoMedioDiario();
    QString getLocalFavorito();
    int getVezesNoLocalFavorito();
    CCompraItem *getUltimaCompra();
    //sets
    void setGastoMedioDiario(double gastoMedioDiario);
    void setLocalFavorito(QString local);
    void setVezesNoLocalFavorito(const int &vezes);



private:
    QSqlDatabase _db;
    CCartaoItem *_cartao;
    CCompraItem *_maiorCompra, *_ultimaCompra;
    double _gastoMedioDiario;
    QString _localFavorito;
    int _vezesNoLocalFavorito;

    void MaiorCompra();
    void GastoMedio();
    void LocalFavorito();
    void UltimaCompra();

signals:
    void dataChanged();

public slots:
    void calcularSlot();

};

Q_DECLARE_METATYPE(CEstudos*);

#endif // CESTUDOS_H
