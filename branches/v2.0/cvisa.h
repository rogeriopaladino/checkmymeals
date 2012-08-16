#ifndef CVISA_H
#define CVISA_H

#include <QObject>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>
//#include <e32base.h>

class CVisa : public QObject
{
    Q_OBJECT
public:
    explicit CVisa(QObject *parent = 0);
    virtual ~CVisa();
    Q_INVOKABLE void Consultar(const QString &cartao);
    Q_INVOKABLE void AdicionarParaConsulta(const QString &cartao);
    Q_INVOKABLE void IniciarCosulta();
    Q_INVOKABLE void Cancelar();
private:
    QNetworkAccessManager *_net;
    bool _cancelar/*, _lote*/;
    QStringList _cartoes;
    QUrl UrlParaConsulta(QString cartao, bool todasAnteriores);
signals:
    //void iniciandoConsultaLote();
    //void consultaLoteFinalizada();
    void consultaFinalizada();
    void iniciandoConsulta(const QString &cartao);
    void consultaCartaoFinalizada(const QString &cartao, const QString &extrato);
    void consultaCancelada();
    void erroConexao();

private slots:
    void erroConexaoHandlerSlot();

public slots:
    virtual void consultaFinalizadaResposta();
    virtual void baixandoPagina();
};

#endif // CVISA_H
