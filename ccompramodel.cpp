#include "ccompramodel.h"

CCompraModel::CCompraModel(QObject *parent) :
    QAbstractListModel(parent)
{
    this->setRoleNames(CCompraItem::roleNames());
}

QVariant CCompraModel::data(const QModelIndex &index, int role) const
{
    //qDebug() << "ÍNDICE " << index.row() << " | ROLE " << role;
    if ((index.row() >= 0) && (index.row() < this->rowCount()))
        return _compras[index.row()]->dadoCompra(role);
    return QVariant();
}

void CCompraModel::LimparCompras()
{
    if (!_compras.isEmpty()) {
        this->beginResetModel();
        CCompraItem* x;
        while (!_compras.isEmpty()) {
            x = _compras.takeFirst();
            delete x;
        }
        this->endResetModel();
    }
}

void CCompraModel::Carregar(const QString &numero)
{
    QSqlQuery q = this->SelecionarCompras(numero);
    CCompraItem *c;
    if (q.next()) {
        int rowCount = this->rowCount();        
        do {
            if (q.value(1).toString() != "") {                
                this->beginInsertRows(QModelIndex(), rowCount, rowCount+1);
                c = this->CriaCompraItem(q);
                _compras.append(c);
                rowCount++;
                this->endInsertRows();
            }
        } while (q.next());
    }
}

int CCompraModel::rowCount(const QModelIndex &parent) const
{    
    return _compras.count();
}

int CCompraModel::getTamanho()
{
    return _compras.count();
}

void CCompraModel::AdicionarCompra(const QString &numero, const QString &local, QDate data, double valor)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("insert into compra (numero, local, valor, data) "
              "values (:numero, :local, :valor, :data)");
    q.bindValue(":numero", numero);
    q.bindValue(":local", this->LocalCorreto(local));
    q.bindValue(":valor", valor);
    q.bindValue(":data", data);
    q.exec();
}

bool CCompraModel::CompraExiste(const QString &numero, const QString &local, QDate data, double valor)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("select count(*) "
              "from compra "
              "where numero = :numero "
              "and local like :local || '%' "
              "and valor = :valor "
              "and data = :data");
    q.bindValue(":numero", numero);
    /*no visa vale há um bug em que o local, no dia da utilização do cartao,
      aparece cortado e no dia seguinte aparece normal*/
    q.bindValue(":local", local.left(17));
    q.bindValue(":valor", valor);
    q.bindValue(":data", data);
    q.exec();
    q.next();
    return q.value(0).toInt() > 0;
}

void CCompraModel::compraAnalisada(const QString &numero, const QString &local, const QDate &data, const double &valor)
{
    if (!this->CompraExiste(numero, local, data, valor))
        this->AdicionarCompra(numero, local, data, valor);
}

void CCompraModel::selecionarComprasCartao(const QString &numero)
{
    if (_compras.count() > 0)
        if (numero != _compras.at(0)->getCartao())
            this->LimparCompras();
    this->Carregar(numero);
}

QSqlQuery CCompraModel::SelecionarCompras(const QString &numero)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("select b.numero, b.idCompra, b.local, b.data, b.valor "
              "from compra b "
              "where b.numero = :numero "
              "order by b.data desc, b.idCompra desc");
    q.bindValue(":numero", numero);
    q.exec();
    return q;
}

CCompraItem * CCompraModel::CriaCompraItem(const QSqlQuery &q)
{
    CCompraItem *c = new CCompraItem(this);
    c->setCartao(q.value(0).toString());
    c->setId(q.value(1).toInt());
    c->setLocal(q.value(2).toString());
    c->setData(q.value(3).toDate());
    c->setValor(q.value(4).toDouble());
    return c;
}

QString CCompraModel::LocalCorreto(const QString &local)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("select local "
              "from compra "
              "where local = :local");
    q.bindValue(":local", local.left(17));
    q.exec();
    while (q.next()) {
        QString l = q.value(0).toString();
        if (l.length() > local.length())
            return l;
    }
    return local;
}

