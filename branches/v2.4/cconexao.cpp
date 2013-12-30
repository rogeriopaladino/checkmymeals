#include "cconexao.h"

CConexao::CConexao(QObject *parent)
    :CConexaoDefaultImplementation(parent)
{    
    this->Factory();
    _implsCountFinished = 0;
    _implsCountError = 0;
    _implsCountCancel = 0;
    _implsActiveCards = 0;
}

void CConexao::Consultar(const QString &cartao, int bandeira)
{
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        CConexaoImplementationSpecificInterface *implO = qobject_cast<CConexaoImplementationSpecificInterface*>(impl);
        if (implO->PossoProcessar(bandeira))
        {
            //Quem chama esta a��o quer apenas a consulta de um �nico cart�o e apenas ficar� ativa a implementa��o
            //que processa a bandeira em quest�o.
            _implsActiveCards = 1;
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
            //Quem chama esta a��o quer a consulta de m�ltimos cart�es, portanto poder� haver mais de uma implementa��o.
            //Obrigatoriamente dever� ser chamada a a��o IniciarConsulta
            _implsActiveCards++;
           impl->AdicionarParaConsulta(cartao);
        }
    }
}

void CConexao::IniciarConsulta()
{    
    foreach(CConexaoDefaultImplementation *impl, _impls)
    {
        impl->IniciarConsulta();
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
        QObject::connect(impl, SIGNAL(consultaCartaoFinalizada(QString,QString,CEnumsDefinitions::TipoBandeiraCartaoEnum)), this, SLOT(consultaCartaoFinalizadaSlot(QString,QString,CEnumsDefinitions::TipoBandeiraCartaoEnum)));
        QObject::connect(impl, SIGNAL(consultaFinalizada()), this, SLOT(consultaFinalizadaSlot()));
        QObject::connect(impl, SIGNAL(erroConexao()), this, SLOT(erroConexaoSlot()));
        QObject::connect(impl, SIGNAL(iniciandoConsulta(QString)), this, SLOT(iniciandoConsultaSlot(QString)));

        QObject::connect(impl, SIGNAL(consultaCancelada()), this, SLOT(processamentoFinalSlot()));
        QObject::connect(impl, SIGNAL(consultaFinalizada()), this, SLOT(processamentoFinalSlot()));
        QObject::connect(impl, SIGNAL(erroConexao()), this, SLOT(processamentoFinalSlot()));
    }
}

bool CConexao::FinalDoProcessamento()
{
    return (_implsCountFinished + _implsCountError + _implsCountCancel) == _implsActiveCards;
}

void CConexao::consultaCanceladaSlot()
{
    _implsCountCancel++;
}

void CConexao::consultaCartaoFinalizadaSlot(const QString &cartao, const QString &extrato, CEnumsDefinitions::TipoBandeiraCartaoEnum bandeira)
{
    _implsCountFinished++;
    emit consultaCartaoFinalizada(cartao, extrato, bandeira);
}

void CConexao::consultaFinalizadaSlot()
{
    //_implsCountFinished++;
}

void CConexao::erroConexaoSlot()
{
    _implsCountError++;
}

void CConexao::iniciandoConsultaSlot(const QString &cartao)
{    
    emit iniciandoConsulta(cartao);
}

void CConexao::processamentoFinalSlot()
{
    if (this->FinalDoProcessamento())
    {
        if (_implsCountError == _implsActiveCards)
            emit erroConexao();
        else if (_implsCountCancel == _implsActiveCards)
            emit consultaCancelada();
        else if (_implsCountFinished == _implsActiveCards)
            emit consultaFinalizada();
        else
        {
            if (_implsCountFinished > 0)
                emit consultaFinalizada();
            else if (_implsCountCancel > 0)
                emit consultaCancelada();
            else if (_implsCountError > 0)
                emit erroConexao();
        }
        //N�o h� mais nenhuma implementa��o executando tarefas.
        _implsCountFinished = 0;
        _implsCountError = 0;
        _implsCountCancel = 0;
        _implsActiveCards = 0;
    }
}

