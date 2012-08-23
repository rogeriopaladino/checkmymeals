/****************************************************************************
** Meta object code from reading C++ file 'cartaoproxy.h'
**
** Created: Thu 23. Aug 17:11:42 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cartaoproxy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cartaoproxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CartaoProxy[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x05,

 // methods: signature, parameters, type, tag, flags
      52,   12,   12,   12, 0x02,
      68,   13,   12,   12, 0x02,
     107,   97,   12,   12, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_CartaoProxy[] = {
    "CartaoProxy\0\0numero\0filtrarComprarDoCartao(QString)\0"
    "LimparFiltros()\0SelecionarPorCartao(QString)\0"
    "descricao\0SelecionarPorDescricao(QString)\0"
};

const QMetaObject CartaoProxy::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_CartaoProxy,
      qt_meta_data_CartaoProxy, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CartaoProxy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CartaoProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CartaoProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CartaoProxy))
        return static_cast<void*>(const_cast< CartaoProxy*>(this));
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int CartaoProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: filtrarComprarDoCartao((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: LimparFiltros(); break;
        case 2: SelecionarPorCartao((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: SelecionarPorDescricao((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CartaoProxy::filtrarComprarDoCartao(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
