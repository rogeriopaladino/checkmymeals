#ifndef CCOMPRAMODEL_H
#define CCOMPRAMODEL_H

#include <QAbstractListModel>
#include <QtSql>
#include "ccompraitem.h"


class CCompraModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int tamanho READ getTamanho NOTIFY tamanhoChanged)
public:
    explicit CCompraModel(QObject *parent = 0);
    ~CCompraModel();

    Q_INVOKABLE void Carregar(const QString &cartao);
    Q_INVOKABLE void LimparCompras();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;    
    //gets
    int getTamanho();
private:
    QList<CCompraItem*> _compras;

    bool CompraExiste(const QString &numero, const QString &local, QDate data, double valor);
    void AdicionarCompra(const QString &numero, const QString &local, QDate data, double valor);
    QSqlQuery SelecionarCompras(const QString &numero);
    CCompraItem *CriaCompraItem(const QSqlQuery &q);
    QString LocalCorreto(const QString &local);    

signals:
    void tamanhoChanged();

public slots:
    void compraAnalisada(const QString &numero, const QString &local, const QDate &data, const double &valor);
    void selecionarComprasCartao(const QString &numero);
};

#endif // CCOMPRAMODEL_H
