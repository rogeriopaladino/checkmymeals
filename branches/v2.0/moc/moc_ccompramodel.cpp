/****************************************************************************
** Meta object code from reading C++ file 'ccompramodel.h'
**
** Created: Mon 20. Aug 17:30:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ccompramodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccompramodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCompraModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   31,   13,   13, 0x0a,
     108,  101,   13,   13, 0x0a,

 // methods: signature, parameters, type, tag, flags
     148,  141,   13,   13, 0x02,
     166,   13,   13,   13, 0x02,

 // properties: name, type, flags
     186,  182, 0x02495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_CCompraModel[] = {
    "CCompraModel\0\0tamanhoChanged()\0"
    "numero,local,data,valor\0"
    "compraAnalisada(QString,QString,QDate,double)\0"
    "numero\0selecionarComprasCartao(QString)\0"
    "cartao\0Carregar(QString)\0LimparCompras()\0"
    "int\0tamanho\0"
};

const QMetaObject CCompraModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_CCompraModel,
      qt_meta_data_CCompraModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CCompraModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CCompraModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CCompraModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCompraModel))
        return static_cast<void*>(const_cast< CCompraModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int CCompraModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: tamanhoChanged(); break;
        case 1: compraAnalisada((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QDate(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4]))); break;
        case 2: selecionarComprasCartao((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: Carregar((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: LimparCompras(); break;
        default: ;
        }
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getTamanho(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CCompraModel::tamanhoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
