/****************************************************************************
** Meta object code from reading C++ file 'rfiddll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bankSimul/headers/rfiddll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rfiddll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RfidDLL_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RfidDLL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RfidDLL_t qt_meta_stringdata_RfidDLL = {
    {
QT_MOC_LITERAL(0, 0, 7), // "RfidDLL"
QT_MOC_LITERAL(1, 8, 18), // "signaaliRpSignaali"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "lahetaCardSerialNumber"
QT_MOC_LITERAL(4, 51, 5), // "value"
QT_MOC_LITERAL(5, 57, 17), // "rajapintaSignaali"
QT_MOC_LITERAL(6, 75, 8) // "tulostus"

    },
    "RfidDLL\0signaaliRpSignaali\0\0"
    "lahetaCardSerialNumber\0value\0"
    "rajapintaSignaali\0tulostus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RfidDLL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void RfidDLL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RfidDLL *_t = static_cast<RfidDLL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signaaliRpSignaali(); break;
        case 1: _t->lahetaCardSerialNumber((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->rajapintaSignaali(); break;
        case 3: { QString _r = _t->tulostus();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RfidDLL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RfidDLL::signaaliRpSignaali)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RfidDLL::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RfidDLL::lahetaCardSerialNumber)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RfidDLL::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RfidDLL.data,
      qt_meta_data_RfidDLL,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RfidDLL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RfidDLL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RfidDLL.stringdata0))
        return static_cast<void*>(const_cast< RfidDLL*>(this));
    return QObject::qt_metacast(_clname);
}

int RfidDLL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RfidDLL::signaaliRpSignaali()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RfidDLL::lahetaCardSerialNumber(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
