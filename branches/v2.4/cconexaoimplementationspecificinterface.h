#ifndef CCONEXAOIMPLEMENTATIONSPECIFICINTERFACE_H
#define CCONEXAOIMPLEMENTATIONSPECIFICINTERFACE_H

#include <QObject>

class CConexaoImplementationSpecificInterface
{

public:
    virtual bool PossoProcessar(int bandeira) = 0;

};

Q_DECLARE_INTERFACE(CConexaoImplementationSpecificInterface, "com.rogerio.objects.interfaces/CConexaoImplementationSpecificInterface_1.0")

#endif // CCONEXAOIMPLEMENTATIONSPECIFIC_H
