#include "cutil.h"

CUtil::CUtil(QObject *parent) :
    QObject(parent)
{
}

bool CUtil::getVersaoFree()
{
#if VERSAO_FREE
    return true;
#else
    return false;
#endif
}

QString CUtil::getNumeroVersao()
{
    return QString(VERSION);
}
