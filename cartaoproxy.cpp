#include "cartaoproxy.h"

CartaoProxy::CartaoProxy(QObject *parent) :
    QSortFilterProxyModel(parent),
    _descricao(""),
    _numero("")
{
}

void CartaoProxy::LimparFiltros()
{
    _numero = "";
    _descricao = "";
    emit invalidateFilter();
}

void CartaoProxy::SelecionarPorCartao(const QString &numero)
{
    _numero = numero;
    emit invalidateFilter();
    emit filtrarComprarDoCartao(numero);
}

void CartaoProxy::SelecionarPorDescricao(const QString &descricao)
{
    _descricao = descricao;
    emit invalidateFilter();
}

bool CartaoProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool ret = true;
    if (_descricao != "")        
        ret = (this->sourceModel()->data(createIndex(source_row, 0), CCartaoItem::descricaoRole).toString().contains(_descricao, Qt::CaseInsensitive));
    if (_numero != "")
        ret &= (this->sourceModel()->data(createIndex(source_row, 0), CCartaoItem::numeroRole).toString() == _numero);
    return ret;
}
