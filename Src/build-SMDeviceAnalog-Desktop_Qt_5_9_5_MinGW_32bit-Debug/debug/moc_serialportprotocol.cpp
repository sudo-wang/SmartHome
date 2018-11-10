/****************************************************************************
** Meta object code from reading C++ file 'serialportprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SMDeviceAnalog/SerialPort/serialportprotocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportprotocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortProtocol_t {
    QByteArrayData data[14];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortProtocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortProtocol_t qt_meta_stringdata_SerialPortProtocol = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SerialPortProtocol"
QT_MOC_LITERAL(1, 19, 24), // "newAirConditionerControl"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 5), // "index"
QT_MOC_LITERAL(4, 51, 5), // "model"
QT_MOC_LITERAL(5, 57, 2), // "te"
QT_MOC_LITERAL(6, 60, 3), // "fun"
QT_MOC_LITERAL(7, 64, 13), // "newLedControl"
QT_MOC_LITERAL(8, 78, 1), // "b"
QT_MOC_LITERAL(9, 80, 16), // "newHeaterControl"
QT_MOC_LITERAL(10, 97, 18), // "newCurtainsControl"
QT_MOC_LITERAL(11, 116, 3), // "pos"
QT_MOC_LITERAL(12, 120, 18), // "readFromSerialSlot"
QT_MOC_LITERAL(13, 139, 4) // "data"

    },
    "SerialPortProtocol\0newAirConditionerControl\0"
    "\0index\0model\0te\0fun\0newLedControl\0b\0"
    "newHeaterControl\0newCurtainsControl\0"
    "pos\0readFromSerialSlot\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortProtocol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    2,   48,    2, 0x06 /* Public */,
       9,    2,   53,    2, 0x06 /* Public */,
      10,    2,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   63,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   13,

       0        // eod
};

void SerialPortProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortProtocol *_t = static_cast<SerialPortProtocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newAirConditionerControl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->newLedControl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->newHeaterControl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->newCurtainsControl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->readFromSerialSlot((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SerialPortProtocol::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortProtocol::newAirConditionerControl)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialPortProtocol::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortProtocol::newLedControl)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialPortProtocol::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortProtocol::newHeaterControl)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SerialPortProtocol::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPortProtocol::newCurtainsControl)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SerialPortProtocol::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortProtocol.data,
      qt_meta_data_SerialPortProtocol,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortProtocol.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPortProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SerialPortProtocol::newAirConditionerControl(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPortProtocol::newLedControl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialPortProtocol::newHeaterControl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialPortProtocol::newCurtainsControl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
