/****************************************************************************
** Meta object code from reading C++ file 'ccompraitem.h'
**
** Created: Fri 24. Aug 16:22:10 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ccompraitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccompraitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCompraItem[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       4,   19, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // properties: name, type, flags
      33,   29, 0x02495103,
      44,   36, 0x0a495103,
      57,   50, 0x06495103,
      69,   63, 0x0e495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_CCompraItem[] = {
    "CCompraItem\0\0compraChanged()\0int\0id\0"
    "QString\0local\0double\0valor\0QDate\0data\0"
};

const QMetaObject CCompraItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CCompraItem,
      qt_meta_data_CCompraItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CCompraItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CCompraItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CCompraItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCompraItem))
        return static_cast<void*>(const_cast< CCompraItem*>(this));
    return QObject::qt_metacast(_clname);
}

int CCompraItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: compraChanged(); break;
        default: ;
        }
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getLocal(); break;
        case 2: *reinterpret_cast< double*>(_v) = getValor(); break;
        case 3: *reinterpret_cast< QDate*>(_v) = getData(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setId(*reinterpret_cast< int*>(_v)); break;
        case 1: setLocal(*reinterpret_cast< QString*>(_v)); break;
        case 2: setValor(*reinterpret_cast< double*>(_v)); break;
        case 3: setData(*reinterpret_cast< QDate*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CCompraItem::compraChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
