#ifndef CDADOCOMPRA_H
#define CDADOCOMPRA_H

#include <QObject>
#include <QtDeclarative>
#include <QDate>
#include <QHash>

class CCompraItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getId WRITE setId NOTIFY compraChanged)
    Q_PROPERTY(QString local READ getLocal WRITE setLocal NOTIFY compraChanged)
    Q_PROPERTY(double valor READ getValor WRITE setValor NOTIFY compraChanged)
    Q_PROPERTY(QDate data READ getData WRITE setData NOTIFY compraChanged)

public:
    enum Roles {
        idRole = Qt::UserRole + 1,
        localRole,
        valorRole,
        dataRole
    };

    explicit CCompraItem(QObject *parent = 0);
    static QHash<int, QByteArray> roleNames();
    QVariant dadoCompra(int role);

    //gets
    int getId();
    double getValor() const;
    QDate getData() const;
    QString getLocal() const;
    //sets
    void setId(int id);
    void setValor(double valor);
    void setData(QDate data);
    void setLocal(QString local);

private:
    int _id;
    double _valor;
    QDate _data;
    QString _local;

signals:    
    void compraChanged();

public slots:

};

Q_DECLARE_METATYPE(CCompraItem*)

#endif // CCOMPRA_H
