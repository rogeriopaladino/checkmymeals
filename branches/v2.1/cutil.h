#ifndef CUTIL_H
#define CUTIL_H

#include <QObject>

class CUtil : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool versaoFree READ getVersaoFree)
    Q_PROPERTY(QString numeroVersao READ getNumeroVersao)
public:
    explicit CUtil(QObject *parent = 0);

private:
    bool getVersaoFree();
    QString getNumeroVersao();
    
signals:
    
public slots:
    
};

#endif // CUTIL_H
