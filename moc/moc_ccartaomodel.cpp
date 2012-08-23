/****************************************************************************
** Meta object code from reading C++ file 'ccartaomodel.h'
**
** Created: Thu 23. Aug 17:10:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ccartaomodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccartaomodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCartaoModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   14,   13,   13, 0x05,
      71,   13,   13,   13, 0x05,
      95,   88,   13,   13, 0x05,
     121,   13,   13,   13, 0x05,
     146,  139,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     171,   13,   13,   13, 0x08,
     191,  139,   13,   13, 0x0a,
     235,  222,   13,   13, 0x0a,
     284,  266,   13,   13, 0x0a,
     325,  266,   13,   13, 0x0a,

 // methods: signature, parameters, type, tag, flags
     390,  373,   13,   13, 0x02,
     423,  139,   13,   13, 0x02,
     446,  373,   13,   13, 0x02,
     492,  139,  479,   13, 0x02,

 // properties: name, type, flags
     516,  512, 0x02495001,
     536,  524, 0x0b495001,

 // properties: notify_signal_id
       1,
       1,

       0        // eod
};

static const char qt_meta_stringdata_CCartaoModel[] = {
    "CCartaoModel\0\0topLeft,bottomRight\0"
    "dataChanged(QModelIndex,QModelIndex)\0"
    "tamanhoChanged()\0indice\0"
    "novoCartaoAdicionado(int)\0atualizarEstudo()\0"
    "numero\0atualizarEstudo(QString)\0"
    "handleItemChanged()\0atualizacaoFinalizada(QString)\0"
    "numero,saldo\0atualizarSaldo(QString,double)\0"
    "numero,data,valor\0"
    "atualizarBeneficio(QString,QDate,double)\0"
    "atualizarProximoBeneficio(QString,QDate,double)\0"
    "numero,descricao\0AdicionarCartao(QString,QString)\0"
    "RemoverCartao(QString)\0"
    "AtualizarCartao(QString,QString)\0"
    "CCartaoItem*\0InfoCartao(QString)\0int\0"
    "tamanho\0QStringList\0cartoesCadastrados\0"
};

const QMetaObject CCartaoModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_CCartaoModel,
      qt_meta_data_CCartaoModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CCartaoModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CCartaoModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CCartaoModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCartaoModel))
        return static_cast<void*>(const_cast< CCartaoModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int CCartaoModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: tamanhoChanged(); break;
        case 2: novoCartaoAdicionado((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: atualizarEstudo(); break;
        case 4: atualizarEstudo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: handleItemChanged(); break;
        case 6: atualizacaoFinalizada((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: atualizarSaldo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 8: atualizarBeneficio((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 9: atualizarProximoBeneficio((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3]))); break;
        case 10: AdicionarCartao((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: RemoverCartao((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: AtualizarCartao((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: { CCartaoItem* _r = InfoCartao((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CCartaoItem**>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getTamanho(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = getCartoesCadastrados(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CCartaoModel::dataChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CCartaoModel::tamanhoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CCartaoModel::novoCartaoAdicionado(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CCartaoModel::atualizarEstudo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CCartaoModel::atualizarEstudo(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
