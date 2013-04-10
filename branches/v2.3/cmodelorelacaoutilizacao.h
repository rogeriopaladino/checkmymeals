#ifndef CMODELORELACAOUTILIZACAO_H
#define CMODELORELACAOUTILIZACAO_H

#include <QAbstractListModel>
#include <QList>
#include <QtSql>
#include <QDebug>

#include <cmodelorelacaoutilizacaoitem.h>

class CModeloRelacaoUtilizacao : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CModeloRelacaoUtilizacao(QObject *parent = 0);
    ~CModeloRelacaoUtilizacao();

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QList<CModeloRelacaoUtilizacaoItem*> _lista;

    void LimparModelo();

signals:
    
public slots:
    void filtrarRelacao(const QString &cartao);
    
};

#endif // CMODELORELACAOUTILIZACAO_H
