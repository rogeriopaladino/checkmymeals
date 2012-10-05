#ifndef CARTAOPROXY_H
#define CARTAOPROXY_H

#include <QSortFilterProxyModel>
#include "ccartaoitem.h"

class CartaoProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CartaoProxy(QObject *parent = 0);

    Q_INVOKABLE void LimparFiltros();
    Q_INVOKABLE void SelecionarPorCartao(const QString &numero);
    Q_INVOKABLE void SelecionarPorDescricao(const QString &descricao);

private:
    QString _descricao, _numero;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    
signals:
    void filtrarComprarDoCartao(const QString &numero);
    
public slots:
    
};

#endif // CARTAOPROXY_H
