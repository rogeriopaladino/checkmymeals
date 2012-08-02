#include "cartaoproxy.h"

CartaoProxy::CartaoProxy(QObject *parent) :
    QSortFilterProxyModel(parent),
    _descricao("")
{
}

void CartaoProxy::Selecionar(const QString &descricao)
{
    _descricao = descricao;
    emit invalidateFilter();
}

bool CartaoProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if (_descricao != "")
        return (this->sourceModel()->data(createIndex(source_row, 0), CCartaoItem::descricaoRole).toString().contains(_descricao, Qt::CaseInsensitive));
    else
        return true;
}
