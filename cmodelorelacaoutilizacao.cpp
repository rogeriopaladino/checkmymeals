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
    if (_lista.count() > 0)
    {
        beginRemoveRows(QModelIndex(), 0, _lista.count() - 1);
        for (int i = 0; i < _lista.count(); i++)
            delete _lista.at(i);
        _lista.clear();
        endRemoveRows();
    }
}

void CModeloRelacaoUtilizacao::filtrarRelacao(const QString &cartao)
{
    this->LimparModelo();
    QSqlQuery q(QSqlDatabase::database("default"));
    q.exec("drop table if exists temp.relacao");

    q.prepare("create temp table relacao as "
              "select substr(local, 1, 16) local, count(*) vezes, 0 total, sum(valor) valorTotalVisita "
              "from compra "
              "where numero = :numero "
              "group by substr(local, 1, 16)");
    q.bindValue(":numero", cartao);
    q.exec();

    q.prepare("update temp.relacao "
              "set total = (select sum(vezes) from temp.relacao) ");
    q.exec();

    q.prepare("select local, vezes, total, valorTotalVisita "
              "from temp.relacao ");
    q.exec();

    while (q.next())
    {
        CModeloRelacaoUtilizacaoItem *item = new CModeloRelacaoUtilizacaoItem();
        item->setNome(q.value(0).toString());
        item->setValor(q.value(1).toInt());
        item->setTotal(q.value(2).toInt());
        item->setValorTotalVisita(q.value(3).toDouble());
        beginInsertRows(QModelIndex(), _lista.count(), _lista.count());
        _lista.append(item);
        endInsertRows();
    }
}
