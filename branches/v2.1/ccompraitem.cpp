#include "ccompraitem.h"

CCompraItem::CCompraItem(QObject *parent) :
    QObject(parent)
{
    _local = "";
    _data = QDate();
    _valor = 0;
}

void CCompraItem::setValor(double valor)
{
    _valor = valor;
}

void CCompraItem::setData(QDate data)
{
    _data = data;
}

void CCompraItem::setLocal(QString local)
{
    _local = local;
}

double CCompraItem::getValor() const
{
    return _valor;
}

QDate CCompraItem::getData() const
{
    return _data;
}

QString CCompraItem::getLocal() const
{
    return _local;
}

int CCompraItem::getId()
{
    return _id;
}

void CCompraItem::setId(int id)
{
    _id = id;
}

QHash<int, QByteArray> CCompraItem::roleNames()
{
    QHash<int, QByteArray> roles;
    roles[idRole] = "id";
    roles[localRole] = "local";
    roles[dataRole] = "dataCompra";
    roles[valorRole] = "valor";
    return roles;
}

QVariant CCompraItem::dadoCompra(int role)
{
    switch(role) {
    case idRole:
        return getId();
        break;
    case localRole:
        return getLocal();
        break;
    case dataRole:
        return getData();
        break;
    case valorRole:
        return getValor();
        break;
    }
    return QVariant();
}
