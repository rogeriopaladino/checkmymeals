/****************************************************************************
** Meta object code from reading C++ file 'cvisa.h'
**
** Created: Fri 24. Aug 16:21:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cvisa.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cvisa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CVisa[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      35,   28,    6,    6, 0x05,
      77,   62,    6,    6, 0x05,
     119,    6,    6,    6, 0x05,
     139,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     153,    6,    6,    6, 0x08,
     178,    6,    6,    6, 0x0a,
     207,    6,    6,    6, 0x0a,

 // methods: signature, parameters, type, tag, flags
     224,   28,    6,    6, 0x02,
     243,   28,    6,    6, 0x02,
     274,    6,    6,    6, 0x02,
     291,    6,    6,    6, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_CVisa[] = {
    "CVisa\0\0consultaFinalizada()\0cartao\0"
    "iniciandoConsulta(QString)\0cartao,extrato\0"
    "consultaCartaoFinalizada(QString,QString)\0"
    "consultaCancelada()\0erroConexao()\0"
    "erroConexaoHandlerSlot()\0"
    "consultaFinalizadaResposta()\0"
    "baixandoPagina()\0Consultar(QString)\0"
    "AdicionarParaConsulta(QString)\0"
    "IniciarCosulta()\0Cancelar()\0"
};

const QMetaObject CVisa::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CVisa,
      qt_meta_data_CVisa, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CVisa::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CVisa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CVisa::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CVisa))
        return static_cast<void*>(const_cast< CVisa*>(this));
    return QObject::qt_metacast(_clname);
}

int CVisa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: consultaFinalizada(); break;
        case 1: iniciandoConsulta((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: consultaCartaoFinalizada((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: consultaCancelada(); break;
        case 4: erroConexao(); break;
        case 5: erroConexaoHandlerSlot(); break;
        case 6: consultaFinalizadaResposta(); break;
        case 7: baixandoPagina(); break;
        case 8: Consultar((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: AdicionarParaConsulta((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: IniciarCosulta(); break;
        case 11: Cancelar(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CVisa::consultaFinalizada()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CVisa::iniciandoConsulta(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CVisa::consultaCartaoFinalizada(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CVisa::consultaCancelada()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CVisa::erroConexao()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
