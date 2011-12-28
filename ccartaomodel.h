#ifndef CCARTAOMODEL_H
#define CCARTAOMODEL_H

#include <QtDeclarative>
#include <QAbstractListModel>
#include <QRegExp>
#include <QStringList>
#include <QtSql>
#include "ccartaoitem.h"
#include "ccompramodel.h"

class CCartaoModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int tamanho READ getTamanho NOTIFY tamanhoChanged)
    Q_PROPERTY(QStringList cartoesCadastrados READ getCartoesCadastrados NOTIFY tamanhoChanged)

public:
    explicit CCartaoModel(QObject *parent = 0);
    ~CCartaoModel();

    Q_INVOKABLE void AdicionarCartao(const QString &numero, const QString &descricao);
    void AdicionarCartaoPreparado(CCartaoItem *cartao);
    Q_INVOKABLE void RemoverCartao(const QString &numero);
    Q_INVOKABLE void AtualizarCartao(const QString &numero, const QString &descricao);
    Q_INVOKABLE CCartaoItem *InfoCartao(const QString &numero);    

    QModelIndex IndexFromNumero(const QString &numero);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;    

    int getTamanho();
    QStringList getCartoesCadastrados();
private:
    QList<CCartaoItem*> _cartoes;

    void CarregarDados();
    void MostrarInfoDebug(QSqlError err);
    void PrepararDataBase();        
    CCartaoItem *AcharCartao(const QString &numero);

signals:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void tamanhoChanged();
    void novoCartaoAdicionado(const int &indice);
    void atualizarEstudo(); //geral
    void atualizarEstudo(const QString &numero);

private slots:
    void handleItemChanged();

public slots:
    void atualizacaoFinalizada(const QString &numero);
    void atualizarSaldo(const QString &numero, const double &saldo);
    void atualizarBeneficio(const QString &numero, const QDate &data, const double &valor);
    void atualizarProximoBeneficio(const QString &numero, const QDate &data, const double &valor);
};

#endif // CCARTAOMODEL_H
