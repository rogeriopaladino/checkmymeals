#ifndef CENUMSDEFINITIONS_H
#define CENUMSDEFINITIONS_H

#include <QObject>

class CEnumsDefinitions : public QObject
{
    Q_OBJECT

    Q_ENUMS(TipoBandeiraCartaoEnum)

public:
    enum TipoBandeiraCartaoEnum { Desconhecido, Visa, Ticket };

    explicit CEnumsDefinitions(QObject *parent = 0);
    ~CEnumsDefinitions();
};

#endif // CENUMSDEFINITIONS_H
