#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QtDeclarative>
#include <QtDeclarative/qdeclarativeengine.h>
#include "cvisa.h"
#include "cprocessador.h"
#include "ccartaoitem.h"
#include "cestudos.h"
#include "ccartaomodel.h"
#include "ccompramodel.h"
#include "ccompraitem.h"
#include "cartaoproxy.h"
#include "cutil.h"

int main(int argc, char *argv[])
{
    QLocale::setDefault(QLocale(QLocale::Portuguese, QLocale::Brazil));
    QApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_S60DisablePartialScreenInputMode, false);

    qmlRegisterType<CVisa>("com.rogerio.processador", 1, 0, "Visa");
    qmlRegisterType<CProcessador>("com.rogerio.processador", 1, 0, "Processador");

    qmlRegisterType<CEstudos>("com.rogerio.estudos", 1, 0, "Estudos");
    qmlRegisterType<CCompraModel>("com.rogerio.model", 1, 0, "CompraModel");
    qmlRegisterType<CCompraItem>("com.rogerio.model", 1, 0, "CompraItem");
    qmlRegisterType<CCartaoItem>("com.rogerio.model", 1, 0, "CartaoItem");
    qmlRegisterType<CCartaoModel>("com.rogerio.model", 1, 0, "CartaoModel");
    qmlRegisterType<CartaoProxy>("com.rogerio.proxy", 1, 0, "CartaoProxy");
    qmlRegisterType<CUtil>("com.rogerio.util", 1, 0, "Util");

    CVisa *visa = new CVisa();
    CProcessador *processador = new CProcessador(visa);
    CCompraModel *compraModel = new CCompraModel(visa);
    CCartaoModel *cartaoModel = new CCartaoModel(visa);
    CartaoProxy *cartaoProxy = new CartaoProxy(visa);
    cartaoProxy->setSourceModel(cartaoModel);
    CUtil *util = new CUtil(visa);

    /*conex�es*/
    QObject::connect(visa, SIGNAL(consultaCartaoFinalizada(QString, QString)), processador, SLOT(processadorExtrato(QString, QString)));
    QObject::connect(processador, SIGNAL(informacaoBeneficio(QString,QDate,double)), cartaoModel, SLOT(atualizarBeneficio(QString,QDate,double)));
    QObject::connect(processador, SIGNAL(informacoesCartao(QString,double)), cartaoModel, SLOT(atualizarSaldo(QString,double)));
    QObject::connect(processador, SIGNAL(informacaoProximoBeneficio(QString,QDate,double)), cartaoModel, SLOT(atualizarProximoBeneficio(QString,QDate,double)));
    QObject::connect(processador, SIGNAL(compraAnalisada(QString,QString,QDate,double)), compraModel, SLOT(compraAnalisada(QString,QString,QDate,double)));
    QObject::connect(processador, SIGNAL(cartaoAtualizado(QString)), cartaoModel, SLOT(atualizacaoFinalizada(QString)));
    QObject::connect(cartaoProxy, SIGNAL(filtrarComprarDoCartao(QString)), compraModel, SLOT(selecionarComprasCartao(QString)));

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("visa", visa);
    viewer.rootContext()->setContextProperty("processador", processador);
    viewer.rootContext()->setContextProperty("cartaoModel", cartaoModel);
    viewer.rootContext()->setContextProperty("compraModel", compraModel);
    viewer.rootContext()->setContextProperty("cartaoProxy", cartaoProxy);
    viewer.rootContext()->setContextProperty("util", util);
    viewer.addImportPath("qml/Componentes");
    viewer.setMainQmlFile(QLatin1String("qml/CheckMyMeals/MainWindow.qml"));
    //viewer.setSource(QUrl("qrc:///qml/CheckMyMeals/MainWindow.qml"));
    #if defined Q_OS_SYMBIAN
    viewer.showFullScreen();
    #elif defined Q_OS_WIN
    viewer.showExpanded();
    #endif

    int x = app.exec();
    delete visa;
    return x;
}

