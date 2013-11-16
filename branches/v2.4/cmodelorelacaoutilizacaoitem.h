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
        totalRole,
        valorTotalVisitaRole
    };

    explicit CModeloRelacaoUtilizacaoItem(QObject *parent = 0);    
    static QHash<int, QByteArray> roleNames();
    QVariant data(int role) const;

    void setNome(const QString &nome);
    void setValor(int valor);
    void setTotal(int total);
    void setValorTotalVisita(double valor);
    QString getNome();
    int getValor();
    int getTotal();
    double getValorTotalVisita();

private:
    QString _nome;
    int _valor, _total;
    double _valorTotalVisita;

signals:
    
public slots:
    
};

inline void CModeloRelacaoUtilizacaoItem::setNome(const QString &nome) { _nome = nome; }
inline void CModeloRelacaoUtilizacaoItem::setValor(int valor) { _valor = valor; }
inline void CModeloRelacaoUtilizacaoItem::setTotal(int total) { _total = total; }
inline void CModeloRelacaoUtilizacaoItem::setValorTotalVisita(double valor) { _valorTotalVisita = valor; }
inline QString CModeloRelacaoUtilizacaoItem::getNome() { return _nome; }
inline int CModeloRelacaoUtilizacaoItem::getValor() { return _valor; }
inline int CModeloRelacaoUtilizacaoItem::getTotal() { return _total; }
inline double CModeloRelacaoUtilizacaoItem::getValorTotalVisita() { return _valorTotalVisita; }

#endif // CMODELORELACAOUTILIZACAOITEM_H
