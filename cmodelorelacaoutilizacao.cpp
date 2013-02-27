#include "cmodelorelacaoutilizacao.h"

CModeloRelacaoUtilizacao::CModeloRelacaoUtilizacao(QObject *parent) :
    QAbstractListModel(parent)
{
    this->setRoleNames(CModeloRelacaoUtilizacaoItem::roleNames());
}

CModeloRelacaoUtilizacao::~CModeloRelacaoUtilizacao()
{
    this->LimparModelo();
}

int CModeloRelacaoUtilizacao::rowCount(const QModelIndex &parent) const
{
    return _lista.count();
}

QVariant CModeloRelacaoUtilizacao::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        return _lista.at(index.row())->data(role);
    }
    return QVariant();
}

void CModeloRelacaoUtilizacao::LimparModelo()
{
    beginRemoveRows(QModelIndex(), 0, _lista.count() - 1);
    for (int i = 0; i < _lista.count(); i++)
        delete _lista.at(i);
    _lista.clear();
    endRemoveRows();
}

void CModeloRelacaoUtilizacao::filtrarRelacao(const QString &cartao)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("select local, count(*) vezes "
              "from compra "
              "where numero = :numero "
              "group by local");
    q.bindValue(":numero", cartao);
    q.exec();
    while (q.next())
    {
        CModeloRelacaoUtilizacaoItem *item = new CModeloRelacaoUtilizacaoItem();
        item->setNome(q.value(0).toString());
        item->setValor(q.value(1).toInt());
        beginInsertRows(QModelIndex(), _lista.count(), _lista.count());
        _lista.append(item);
        endInsertRows();
    }
}
