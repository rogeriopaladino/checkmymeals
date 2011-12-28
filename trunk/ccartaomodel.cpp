#include "ccartaomodel.h"

CCartaoModel::CCartaoModel(QObject *parent)
    :QAbstractListModel(parent)
{
    if (!QSqlDatabase::contains("default"))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "default");
        db.setDatabaseName("visa.db");
        if (db.open("subarashi.visaaaaa", "#e3xte3rminio0"))
            this->PrepararDataBase();
        this->MostrarInfoDebug(db.lastError());
    }    
    this->setRoleNames(CCartaoItem::roleNames());    
    this->CarregarDados();
}

CCartaoModel::~CCartaoModel()
{    
}

int CCartaoModel::rowCount(const QModelIndex &parent) const
{
    return _cartoes.count();
}

QVariant CCartaoModel::data(const QModelIndex &index, int role) const
{
    return _cartoes.at(index.row())->data(role);
}

void CCartaoModel::handleItemChanged()
{
    CCartaoItem *cartao = qobject_cast<CCartaoItem*>(this->sender());
    QModelIndex indice = this->IndexFromNumero(cartao->getNumero());
    if (indice.isValid())
        emit dataChanged(indice, indice);
}

void CCartaoModel::AdicionarCartao(const QString &numero, const QString &descricao)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("insert into cartao(numero, descricao)"
              "values (:numero, :descricao)");
    q.bindValue(":numero", numero);
    q.bindValue(":descricao", descricao);
    bool e = q.exec();
    this->MostrarInfoDebug(q.lastError());
    if (e) {        
        CCartaoItem *c = new CCartaoItem(this);
        c->setNumero(numero);
        c->setDescricao(descricao);
        c->setSaldo(0);
        c->setDataBeneficio(QDate());
        c->setValorBeneficio(0);
        c->setDataProximoBeneficio(QDate());
        c->setValorProximoBeneficio(0);
        this->AdicionarCartaoPreparado(c);
        emit tamanhoChanged();
        emit novoCartaoAdicionado(this->rowCount() - 1);
    }
}

void CCartaoModel::AdicionarCartaoPreparado(CCartaoItem *cartao)
{
    QObject::connect(cartao, SIGNAL(dataChanged()), this, SLOT(handleItemChanged()));
    QObject::connect(this, SIGNAL(atualizarEstudo(QString)), cartao, SLOT(atualizarEstudoSlot(QString)));
    QObject::connect(this, SIGNAL(atualizarEstudo()), cartao, SLOT(atualizarEstudoSlot()));
    this->beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());    
    _cartoes.append(cartao);
    this->endInsertRows();
}

void CCartaoModel::RemoverCartao(const QString &numero)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("delete from cartao "
              "where numero = :numero ");
    q.bindValue(":numero", numero);
    q.exec();
    this->MostrarInfoDebug(q.lastError());
    q.prepare("delete from compra "
              "where numero = :numero");
    q.bindValue(":numero", numero);
    q.exec();
    this->MostrarInfoDebug(q.lastError());
    q.prepare("delete from beneficio "
              "where numero = :numero");
    q.bindValue(":numero", numero);
    q.exec();
    this->MostrarInfoDebug(q.lastError());
    q.prepare("delete from proximoBeneficio "
              "where numero = :numero");
    q.bindValue(":numero", numero);
    bool e = q.exec();
    this->MostrarInfoDebug(q.lastError());
    if (e) {
        QModelIndex index = this->IndexFromNumero(numero);
        this->beginRemoveRows(QModelIndex(), index.row(), index.row());
        CCartaoItem *c = _cartoes.takeAt(index.row());
        delete c;
        this->endRemoveRows();
        emit tamanhoChanged();
    }
}

void CCartaoModel::AtualizarCartao(const QString &numero, const QString &descricao)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("update cartao "
              "set descricao = :descricao "
              "where numero = :numero");
    q.bindValue(":descricao", descricao);
    q.bindValue(":numero", numero);
    bool e = q.exec();
    this->MostrarInfoDebug(q.lastError());
    if (e) {
        CCartaoItem *c = this->AcharCartao(numero);
        if (c != NULL)
            c->setDescricao(descricao);
    }
}

CCartaoItem *CCartaoModel::InfoCartao(const QString &numero)
{
    QModelIndex index = this->IndexFromNumero(numero);
    return _cartoes.at(index.row());
}

void CCartaoModel::MostrarInfoDebug(QSqlError err)
{
    if (err.text() != " ")
        qDebug() << err.text();
}

void CCartaoModel::PrepararDataBase()
{
    qDebug() << "Início da manutenção da estrutura.";
    QSqlQuery q(QSqlDatabase::database("default"));
    q.exec("PRAGMA foreign_keys = ON;");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create table if not exists cartao ("
                  "numero varchar(16) primary key,"
                  "descricao varchar (35),"
                  "saldo numeric(6, 2) default 0)");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create table if not exists beneficio ("
           "seq integer primary key autoincrement,"
           "numero varchar(16) not null references cartao(numero) on delete cascade,"
           "data date,"
           "valor numeric(6, 2))");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create table if not exists proximoBeneficio ("
           "seq integer primary key autoincrement,"
           "numero varchar(16) not null references cartao(numero) on delete cascade,"
           "data date,"
           "valor numeric(6, 2))");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create table if not exists compra ("
           "numero varchar(16) not null references cartao(numero) on delete cascade,"
           "idCompra integer primary key autoincrement,"
           "local varchar(50),"
           "valor numeric(6, 2),"
           "data date)");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create unique index if not exists beneficio_idx on beneficio(numero, data, valor)");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create unique index if not exists proxBeneficio_idx on proximoBeneficio (numero, data, valor)");
    this->MostrarInfoDebug(q.lastError());
    q.exec("create unique index if not exists compra_idx on compra(numero, local, valor, data)");
    this->MostrarInfoDebug(q.lastError());
    qDebug() << "Fim da manutenção da estrutura.";
}

CCartaoItem *CCartaoModel::AcharCartao(const QString &numero)
{
    QModelIndex index = this->IndexFromNumero(numero);
    if (index.isValid())
        return _cartoes.at(index.row());
    return NULL;
}

QModelIndex CCartaoModel::IndexFromNumero(const QString &numero)
{
    for (int i = 0; i < rowCount(); i++) {
        if (_cartoes.at(i)->getNumero() == numero)
            return this->index(i);
    }
    return QModelIndex();
}

void CCartaoModel::CarregarDados()
{
    _cartoes.clear();
    QSqlQuery q(QSqlDatabase::database("default"));
    q.exec("select a.numero, a.descricao, a.saldo, max(w.data) dtProxBenef, w.valor vlProxBenef, max(x.data) dtBenef, x.valor vlBenef "
           "from cartao a "
           "left outer join beneficio x on a.numero = x.numero "
           "left outer join proximoBeneficio w on a.numero = w.numero "
           "group by a.numero");
    CCartaoItem *c;
    while (q.next()) {
        QDate dtBenef = q.value(5).toDate();
        QDate dtProxBenef = q.value(3).toDate();
        c = new CCartaoItem(this);        
        c->setNumero(q.value(0).toString());
        c->setDescricao(q.value(1).toString());
        c->setSaldo(q.value(2).toDouble());
        c->setDataBeneficio(dtBenef);
        c->setValorBeneficio(q.value(6).toDouble());
        if (!dtProxBenef.isNull() && !dtBenef.isNull() && (dtBenef < dtProxBenef)) {
            c->setDataProximoBeneficio(dtProxBenef);
            c->setValorProximoBeneficio(q.value(4).toDouble());
        } else {
            c->setDataProximoBeneficio(QDate());
            c->setValorProximoBeneficio(0);
        }        
        this->AdicionarCartaoPreparado(c);
    }
    emit atualizarEstudo();
    this->MostrarInfoDebug(q.lastError());
}


int CCartaoModel::getTamanho()
{
    return rowCount();
}

void CCartaoModel::atualizarSaldo(const QString &numero, const double &saldo)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("update cartao set saldo = :saldo "
              "where numero = :numero ");
    q.bindValue(":saldo", saldo);
    q.bindValue(":numero", numero);
    q.exec();
    this->MostrarInfoDebug(q.lastError());
    CCartaoItem *c = this->AcharCartao(numero);
    if (c != NULL) {
        c->setSaldo(saldo);
    }
}

void CCartaoModel::atualizarBeneficio(const QString &numero, const QDate &data, const double &valor)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare(" insert or ignore into beneficio (numero, data, valor) "
              " values (:numero, :data, :valor) ");
    q.bindValue(":numero", numero);
    q.bindValue(":data", data);
    q.bindValue(":valor", valor);
    bool e = q.exec();
    this->MostrarInfoDebug(q.lastError());
    CCartaoItem *c = this->AcharCartao(numero);
    if (c != NULL && e && c->getDataBeneficio() < data) {
        c->setDataBeneficio(data);
        c->setValorBeneficio(valor);
    }
    if (c != NULL && e && c->getDataProximoBeneficio() < data) {
        c->setDataProximoBeneficio(QDate());
        c->setValorProximoBeneficio(0);
    }
}

void CCartaoModel::atualizarProximoBeneficio(const QString &numero, const QDate &data, const double &valor)
{
    QSqlQuery q(QSqlDatabase::database("default"));
    q.prepare("insert or ignore into proximoBeneficio (numero, data, valor) "
              "values (:numero, :data, :valor) ");
    q.bindValue(":numero", numero);
    q.bindValue(":data", data);
    q.bindValue(":valor", valor);
    CCartaoItem *c = this->AcharCartao(numero);
    if (c != NULL) {
        if (((!c->getDataProximoBeneficio().isNull() && c->getDataProximoBeneficio() < data))
                || c->getDataProximoBeneficio().isNull())
        {
            q.exec();
            this->MostrarInfoDebug(q.lastError());
            c->setDataProximoBeneficio(data);
            c->setValorProximoBeneficio(valor);
        } else {
            c->setDataProximoBeneficio(QDate());
            c->setValorProximoBeneficio(0);
        }
    }
}

void CCartaoModel::atualizacaoFinalizada(const QString &numero)
{
    /*forçar atualização dos estudos de uma única vez*/
    emit atualizarEstudo(numero);
}
