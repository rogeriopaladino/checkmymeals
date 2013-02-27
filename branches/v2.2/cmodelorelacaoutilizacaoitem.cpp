#include "cmodelorelacaoutilizacaoitem.h"

CModeloRelacaoUtilizacaoItem::CModeloRelacaoUtilizacaoItem(QObject *parent) :
    QObject(parent),
    _nome(""),
    _valor(0)
{
}

QHash<int, QByteArray> CModeloRelacaoUtilizacaoItem::roleNames()
{
    QHash<int, QByteArray> roles;
    roles[nomeRole] = "nomeRole";
    roles[valorRole] = "valorRole";
    return roles;
}

QVariant CModeloRelacaoUtilizacaoItem::data(int role) const
{
    switch(role)
    {
        case nomeRole:
        return _nome;
        break;

        case valorRole:
        return _valor;
        break;

    default:
        return QVariant();
    }
}
