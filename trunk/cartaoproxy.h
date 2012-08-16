#ifndef CARTAOPROXY_H
#define CARTAOPROXY_H

#include <QSortFilterProxyModel>
#include "ccartaoitem.h"

class CartaoProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CartaoProxy(QObject *parent = 0);

    Q_INVOKABLE void Selecionar(const QString &descricao);

private:
    QString _descricao;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    
signals:
    
public slots:
    
};

#endif // CARTAOPROXY_H
