/****************************************************************************
** Meta object code from reading C++ file 'cestudos.h'
**
** Created: Thu 23. Aug 17:10:42 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cestudos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cestudos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CEstudos[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       6,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,    9,    9,    9, 0x0a,

 // properties: name, type, flags
      52,   39, 0x00495009,
      71,   64, 0x06495103,
      96,   88, 0x0a495103,
     114,  110, 0x02495103,
     135,   64, 0x06495103,
     156,   39, 0x00495009,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_CEstudos[] = {
    "CEstudos\0\0dataChanged()\0calcularSlot()\0"
    "CCompraItem*\0maiorCompra\0double\0"
    "gastoMedioDiario\0QString\0localFavorito\0"
    "int\0vezesNoLocalFavorito\0valorNoLocalFavorito\0"
    "ultimaCompra\0"
};

const QMetaObject CEstudos::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CEstudos,
      qt_meta_data_CEstudos, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CEstudos::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CEstudos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CEstudos::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CEstudos))
        return static_cast<void*>(const_cast< CEstudos*>(this));
    return QObject::qt_metacast(_clname);
}

int CEstudos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataChanged(); break;
        case 1: calcularSlot(); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< CCompraItem**>(_v) = getMaiorCompra(); break;
        case 1: *reinterpret_cast< double*>(_v) = getGastoMedioDiario(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getLocalFavorito(); break;
        case 3: *reinterpret_cast< int*>(_v) = getVezesNoLocalFavorito(); break;
        case 4: *reinterpret_cast< double*>(_v) = getValorNoLocalFavorito(); break;
        case 5: *reinterpret_cast< CCompraItem**>(_v) = getUltimaCompra(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setGastoMedioDiario(*reinterpret_cast< double*>(_v)); break;
        case 2: setLocalFavorito(*reinterpret_cast< QString*>(_v)); break;
        case 3: setVezesNoLocalFavorito(*reinterpret_cast< int*>(_v)); break;
        case 4: setValorNoLocalFavorito(*reinterpret_cast< double*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CEstudos::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
