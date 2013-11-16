#include "cconexao.h"

CConexao::CConexao(QObject *parent)
    :CConexaoDefaultImplementation(parent)
{
    this->Factory();
}

void CConexao::Consultar(const QString &cartao, int bandeira)
{
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        CConexaoImplementationSpecificInterface *implO = qobject_cast<CConexaoImplementationSpecificInterface*>(impl);
        if (implO->PossoProcessar(bandeira))
        {
           impl->Consultar(cartao);
        }
    }
}

void CConexao::AdicionarParaConsulta(const QString &cartao, int bandeira)
{
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        CConexaoImplementationSpecificInterface *implO = qobject_cast<CConexaoImplementationSpecificInterface*>(impl);
        if (implO->PossoProcessar(bandeira))
        {
           impl->AdicionarParaConsulta(cartao);
        }
    }
}

void CConexao::IniciarCosulta()
{
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        impl->IniciarCosulta();
    }
}

void CConexao::Cancelar()
{
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        impl->Cancelar();
    }
}

void CConexao::Factory()
{
    _impls.append(new CVisa(this));
    _impls.append(new CTicket(this));
    this->BindSignals();
}

void CConexao::BindSignals()
{
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        QObject::connect(impl, SIGNAL(consultaCancelada()), this, SLOT(consultaCanceladaSlot()));
        QObject::connect(impl, SIGNAL(consultaCartaoFinalizada(QString,QString,CEnumsDefinitions::TipoBandeiraCartaoEnum)), this, SLOT(ConsultaCartaoFinalizadaSlot(QString,QString,CEnumsDefinitions::TipoBandeiraCartaoEnum)));
        QObject::connect(impl, SIGNAL(consultaFinalizada()), this, SLOT(ConsultaFinalizadaSlot()));
        QObject::connect(impl, SIGNAL(erroConexao()), this, SLOT(erroConexaoSlot()));
        QObject::connect(impl, SIGNAL(iniciandoConsulta(QString)), this, SLOT(iniciandoConsultaSlot(QString)));
    }
}

void CConexao::consultaCanceladaSlot()
{
    emit consultaCancelada();
}

void CConexao::ConsultaCartaoFinalizadaSlot(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira)
{
    emit consultaCartaoFinalizada(cartao, extrato, bandeira);
}

void CConexao::ConsultaFinalizadaSlot()
{
    emit consultaFinalizada();
}

void CConexao::erroConexaoSlot()
{
    emit erroConexao();
}

void CConexao::iniciandoConsultaSlot(const QString &cartao)
{
    emit iniciandoConsulta(cartao);
}

