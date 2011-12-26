#ifndef CVISA_H
#define CVISA_H

#include <QObject>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QTextCodec>
#include <QDebug>
//#include <e32base.h>

class CVisa : public QObject
{
    Q_OBJECT
public:
    explicit CVisa(QObject *parent = 0);
    virtual ~CVisa();
    Q_INVOKABLE void Consultar(const QString &cartao, bool todasAnteriores);
    Q_INVOKABLE void Cancelar();
private:
    QNetworkAccessManager *_net;
    bool _cancelar;
    QUrl UrlParaConsulta(QString cartao, bool todasAnteriores);
signals:
    void iniciandoConsulta(const QString &cartao);    
    void consultaFinalizada(const QString &extrato);
    void consultaCancelada();
    void erroConexao();

public slots:
    virtual void consultaFinalizadaResposta();
    virtual void baixandoPagina();
};

#endif // CVISA_H
