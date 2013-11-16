#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QtDeclarative>
#include <QtDeclarative/qdeclarativeengine.h>
#include <QScopedPointer>

//#include "cvisa.h"
#include "cprocessador.h"
#include "ccartaoitem.h"
#include "cestudos.h"
#include "ccartaomodel.h"
#include "ccompramodel.h"
#include "ccompraitem.h"
#include "cartaoproxy.h"
#include "cutil.h"
#include "cmodelorelacaoutilizacao.h"
#include "cconexao.h"
#include "cenumsdefinitions.h"


int main(int argc, char *argv[])
{
    QLocale::setDefault(QLocale(QLocale::Portuguese, QLocale::Brazil));
    QApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_S60DisablePartialScreenInputMode, false);

    qmlRegisterType<CEnumsDefinitions>("com.rogerio.definitions", 1, 0, "EnumsDefinitions");

    //qmlRegisterType<CVisa>("com.rogerio.processador", 1, 0, "Visa");
    qmlRegisterType<CConexao>("com.rogerio.processaor", 1, 0, "Conexao");
    qmlRegisterType<CProcessador>("com.rogerio.processador", 1, 0, "Processador");

    qRegisterMetaType<CEnumsDefinitions::TipoBandeiraCartaoEnum>("TipoBandeiraCartaoEnum");

    qmlRegisterType<CEstudos>("com.rogerio.estudos", 1, 0, "Estudos");
    qmlRegisterType<CCompraModel>("com.rogerio.model", 1, 0, "CompraModel");
    qmlRegisterType<CCompraItem>("com.rogerio.model", 1, 0, "CompraItem");
    qmlRegisterType<CCartaoItem>("com.rogerio.model", 1, 0, "CartaoItem");
    qmlRegisterType<CCartaoModel>("com.rogerio.model", 1, 0, "CartaoModel");
    qmlRegisterType<CartaoProxy>("com.rogerio.proxy", 1, 0, "CartaoProxy");
    qmlRegisterType<CUtil>("com.rogerio.util", 1, 0, "Util");
    qmlRegisterType<CModeloRelacaoUtilizacao>("com.rogerio.model", 1, 0, "ModeloRelacaoUtilizacao");

    //QScopedPointer<CVisa> visa(new CVisa());
    QScopedPointer<CConexao> conexao(new CConexao());
    //CVisa *visa = new CVisa();
    //CProcessador *processador = new CProcessador(visa.data());
    CProcessador *processador = new CProcessador(conexao.data());
    //CCompraModel *compraModel = new CCompraModel(visa.data());
    CCompraModel *compraModel = new CCompraModel(conexao.data());
    //CCartaoModel *cartaoModel = new CCartaoModel(visa.data());
    CCartaoModel *cartaoModel = new CCartaoModel(conexao.data());
    //CartaoProxy *cartaoProxy = new CartaoProxy(visa.data());
    CartaoProxy *cartaoProxy = new CartaoProxy(conexao.data());
    cartaoProxy->setSourceModel(cartaoModel);
    //QScopedPointer<CUtil> util(new CUtil(visa.data()));
    QScopedPointer<CUtil> util(new CUtil(conexao.data()));
    //CModeloRelacaoUtilizacao *modeloRelacaoUtilizacao = new CModeloRelacaoUtilizacao(visa.data());
    CModeloRelacaoUtilizacao *modeloRelacaoUtilizacao = new CModeloRelacaoUtilizacao(conexao.data());

    /*conexões*/
    //QObject::connect(visa.data(), SIGNAL(consultaCartaoFinalizada(QString, QString)), processador, SLOT(processadorExtrato(QString, QString)));
    QObject::connect(conexao.data(), SIGNAL(consultaCartaoFinalizada(QString, QString,CEnumsDefinitions::TipoBandeiraCartaoEnum)), processador, SLOT(processadorExtrato(QString, QString,CEnumsDefinitions::TipoBandeiraCartaoEnum)));
    QObject::connect(processador, SIGNAL(informacaoBeneficio(QString,QDate,double)), cartaoModel, SLOT(atualizarBeneficio(QString,QDate,double)));
    QObject::connect(processador, SIGNAL(informacoesCartao(QString,double)), cartaoModel, SLOT(atualizarSaldo(QString,double)));
    QObject::connect(processador, SIGNAL(informacaoProximoBeneficio(QString,QDate,double)), cartaoModel, SLOT(atualizarProximoBeneficio(QString,QDate,double)));
    QObject::connect(processador, SIGNAL(compraAnalisada(QString,QString,QDate,double)), compraModel, SLOT(compraAnalisada(QString,QString,QDate,double)));
    QObject::connect(processador, SIGNAL(cartaoAtualizado(QString)), cartaoModel, SLOT(atualizacaoFinalizada(QString)));
    QObject::connect(cartaoProxy, SIGNAL(filtrarComprarDoCartao(QString)), compraModel, SLOT(selecionarComprasCartao(QString)));
    QObject::connect(cartaoProxy, SIGNAL(filtrarComprarDoCartao(QString)), modeloRelacaoUtilizacao, SLOT(filtrarRelacao(QString)));

    QmlApplicationViewer viewer;
    //viewer.rootContext()->setContextProperty("visa", visa.data());
    viewer.rootContext()->setContextProperty("conexao", conexao.data());
    viewer.rootContext()->setContextProperty("processador", processador);
    viewer.rootContext()->setContextProperty("cartaoModel", cartaoModel);
    viewer.rootContext()->setContextProperty("compraModel", compraModel);
    viewer.rootContext()->setContextProperty("cartaoProxy", cartaoProxy);
    viewer.rootContext()->setContextProperty("util", util.data());
    viewer.rootContext()->setContextProperty("modeloRelacaoUtilizacao", modeloRelacaoUtilizacao);
    viewer.addImportPath("qml/Componentes");
    viewer.setMainQmlFile(QLatin1String("qml/CheckMyMeals/MainWindow.qml"));
    //viewer.setSource(QUrl("qrc:///qml/CheckMyMeals/MainWindow.qml"));
    #if defined Q_OS_SYMBIAN
    viewer.showFullScreen();
    #elif defined Q_OS_WIN
    viewer.showExpanded();
    #endif

    return app.exec();
}

