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
            //Quem chama esta ação quer apenas a consulta de um único cartão e apenas ficará ativa a implementação
            //que processa a bandeira em questão.
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
            //Quem chama esta ação quer a consulta de múltimos cartões, portanto poderá haver mais de uma implementação.
            //Obrigatoriamente deverá ser chamada a ação IniciarConsulta
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
        //Não há mais nenhuma implementação executando tarefas.
        _implsCountFinished = 0;
        _implsCountError = 0;
        _implsCountCancel = 0;
        _implsActiveCards = 0;
    }
}

