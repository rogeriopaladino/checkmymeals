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
        valorRole
    };

    explicit CModeloRelacaoUtilizacaoItem(QObject *parent = 0);    
    static QHash<int, QByteArray> roleNames();
    QVariant data(int role) const;

    void setNome(const QString &nome);
    void setValor(int valor);
    QString getNome();
    int getValor();

private:
    QString _nome;
    int _valor;

signals:
    
public slots:
    
};

inline void CModeloRelacaoUtilizacaoItem::setNome(const QString &nome) { _nome = nome; }
inline void CModeloRelacaoUtilizacaoItem::setValor(int valor) { _valor = valor; }
inline QString CModeloRelacaoUtilizacaoItem::getNome() { return _nome; }
inline int CModeloRelacaoUtilizacaoItem::getValor() { return _valor; }


#endif // CMODELORELACAOUTILIZACAOITEM_H
