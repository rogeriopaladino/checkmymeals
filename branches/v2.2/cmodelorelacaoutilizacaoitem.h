#ifndef CMODELORELACAOUTILIZACAOITEM_H
#define CMODELORELACAOUTILIZACAOITEM_H

#include <QObject>
#include <QHash>
#include <QVariant>

class CModeloRelacaoUtilizacaoItem : public QObject
{
    Q_OBJECT
public:
    enum ROLES {
        nomeRole = Qt::UserRole + 1,
        valorRole,
        totalRole
    };

    explicit CModeloRelacaoUtilizacaoItem(QObject *parent = 0);    
    static QHash<int, QByteArray> roleNames();
    QVariant data(int role) const;

    void setNome(const QString &nome);
    void setValor(int valor);
    void setTotal(int total);
    QString getNome();
    int getValor();
    int getTotal();

private:
    QString _nome;
    int _valor;
    int _total;

signals:
    
public slots:
    
};

inline void CModeloRelacaoUtilizacaoItem::setNome(const QString &nome) { _nome = nome; }
inline void CModeloRelacaoUtilizacaoItem::setValor(int valor) { _valor = valor; }
inline void CModeloRelacaoUtilizacaoItem::setTotal(int total) { _total = total; }
inline QString CModeloRelacaoUtilizacaoItem::getNome() { return _nome; }
inline int CModeloRelacaoUtilizacaoItem::getValor() { return _valor; }
inline int CModeloRelacaoUtilizacaoItem::getTotal() { return _total; }


#endif // CMODELORELACAOUTILIZACAOITEM_H
