/****************************************************************************
** Meta object code from reading C++ file 'cprocessador.h'
**
** Created: Fri 24. Aug 16:22:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cprocessador.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cprocessador.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CProcessador[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   14,   13,   13, 0x05,
      45,   14,   13,   13, 0x05,
      71,   14,   13,   13, 0x05,
     102,   13,   13,   13, 0x05,
     144,  120,   13,   13, 0x05,
     203,  190,   13,   13, 0x05,
     255,  237,   13,   13, 0x05,
     297,  237,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     361,  346,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CProcessador[] = {
    "CProcessador\0\0cartao\0cartaoInvalido(QString)\0"
    "cartaoAtualizado(QString)\0"
    "nenhumaCompraEfetuada(QString)\0"
    "sistemaForaDoAr()\0numero,local,data,valor\0"
    "compraAnalisada(QString,QString,QDate,double)\0"
    "numero,saldo\0informacoesCartao(QString,double)\0"
    "numero,data,valor\0"
    "informacaoBeneficio(QString,QDate,double)\0"
    "informacaoProximoBeneficio(QString,QDate,double)\0"
    "cartao,extrato\0processadorExtrato(QString,QString)\0"
};

const QMetaObject CProcessador::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CProcessador,
      qt_meta_data_CProcessador, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CProcessador::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CProcessador::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CProcessador::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CProcessador))
        return static_cast<void*>(const_cast< CProcessador*>(this));
    return QObject::qt_metacast(_clname);
}

int CProcessador::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cartaoInvalido((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: cartaoAtualizado((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: nenhumaCompraEfetuada((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: sistemaForaDoAr(); break;
        case 4: compraAnalisada((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QDate(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4]))); break;
        case 5: informacoesCartao((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 6: informacaoBeneficio((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 7: informacaoProximoBeneficio((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 8: processadorExtrato((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CProcessador::cartaoInvalido(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CProcessador::cartaoAtualizado(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CProcessador::nenhumaCompraEfetuada(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CProcessador::sistemaForaDoAr()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CProcessador::compraAnalisada(const QString & _t1, const QString & _t2, const QDate _t3, const double & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CProcessador::informacoesCartao(const QString & _t1, const double & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CProcessador::informacaoBeneficio(const QString & _t1, const QDate & _t2, const double & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CProcessador::informacaoProximoBeneficio(const QString & _t1, const QDate & _t2, const double & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
