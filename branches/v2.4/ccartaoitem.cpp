#include "ccartaoitem.h"

CCartaoItem::CCartaoItem(QObject *parent) :
    QObject(parent)
{
    _estudos = new CEstudos(this, this);
    QObject::connect(this, SIGNAL(atualizarEstudo()), _estudos, SLOT(calcularSlot()));
}

CCartaoItem::~CCartaoItem()
{
    _compras.clear();
    Q_CHECK_PTR(_estudos);
    delete _estudos;
}

QHash<int, QByteArray> CCartaoItem::roleNames()
{
    QHash<int, QByteArray> roles;
    roles[numeroRole] = "numero";
    roles[descricaoRole] = "descricao";
    roles[saldoRole] = "saldo";
    roles[dataBeneficioRole] = "dataBeneficio";
    roles[valorBeneficioRole] = "valorBeneficio";
    roles[dataProximoBeneficioRole] = "dataProximoBeneficio";
    roles[valorProximoBeneficioRole] = "valorProximoBeneficio";
    roles[comprasRole] = "compras";
    roles[estudosRole] = "estudos";
    roles[bandeiraRole] = "bandeira";
    return roles;
}

QVariant CCartaoItem::data(int role)
{
    switch(role) {
    case numeroRole:
        return this->getNumero();
        break;
    case descricaoRole:
        return getDescricao();
        break;
    case saldoRole:
        return getSaldo();
        break;
    case dataBeneficioRole:
        return getDataBeneficio();
        break;
    case valorBeneficioRole:
        return getValorBeneficio();
        break;
    case dataProximoBeneficioRole:
        return getDataProximoBeneficio();
        break;
    case valorProximoBeneficioRole:
        return getValorProximoBeneficio();
        break;
    case comprasRole:
        return QVariant::fromValue(getCompras());
        break;
    case estudosRole:
        return QVariant::fromValue(getEstudos());
        break;    
    case bandeiraRole:
        return QVariant::fromValue(getBandeira());
        break;
    }
    return QVariant();
}

void CCartaoItem::setDataBeneficio(QDate data)
{
    _dataBeneficio = data;
    emit dataChanged();
}

void CCartaoItem::setDataProximoBeneficio(QDate data)
{
    _dataProximoBeneficio = data;
    emit dataChanged();
}

void CCartaoItem::setValorProximoBeneficio(double valor)
{
    _valorProximoBeneficio = valor;
    emit dataChanged();
}

void CCartaoItem::setNumero(QString numero)
{
    _numero = numero;
    emit dataChanged();
}

void CCartaoItem::setDescricao(QString descricao)
{
    _descricao = descricao;
    emit dataChanged();
}

void CCartaoItem::setSaldo(double saldo)
{
    _saldo = saldo;
    emit dataChanged();
}

void CCartaoItem::setValorBeneficio(double valor)
{
    _valorBeneficio = valor;
    emit dataChanged();
}

void CCartaoItem::setBandeira(int bandeira)
{
    _bandeira = bandeira;
    emit dataChanged();
}

QString CCartaoItem::getNumero()
{
    return _numero;
}

QString CCartaoItem::getDescricao()
{
    return _descricao;
}

double CCartaoItem::getSaldo()
{
    return _saldo;
}

QDate CCartaoItem::getDataBeneficio()
{
    return _dataBeneficio;
}

QDate CCartaoItem::getDataProximoBeneficio()
{
    return _dataProximoBeneficio;
}

double CCartaoItem::getValorProximoBeneficio()
{
    return _valorProximoBeneficio;
}

QList<QObject*> CCartaoItem::getCompras()
{
    return _compras;
}

double CCartaoItem::getValorBeneficio()
{
    return _valorBeneficio;
}

CEstudos *CCartaoItem::getEstudos()
{
    return _estudos;
}

int CCartaoItem::getBandeira()
{
    return (int)_bandeira;
}

void CCartaoItem::atualizarEstudoSlot(const QString &numeroDaVez)
{
    if (this->getNumero() == numeroDaVez)
        emit atualizarEstudo();
}

void CCartaoItem::atualizarEstudoSlot()
{
    emit atualizarEstudo();
}
