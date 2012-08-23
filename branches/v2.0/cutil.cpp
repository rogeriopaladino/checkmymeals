#include "cutil.h"

CUtil::CUtil(QObject *parent) :
    QObject(parent)
{
}

bool CUtil::getVersaoFree()
{
#ifdef VERSAO_FREE
    return true;
#else
    return false;
#endif
}

QString CUtil::getNumeroVersao()
{
    return QString(VERSION);
}
