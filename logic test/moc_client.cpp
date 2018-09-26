/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[28];
    char stringdata0[350];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 25), // "clientIsConnectedtoServer"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "AntwortAufZug"
QT_MOC_LITERAL(4, 48, 3), // "Cmd"
QT_MOC_LITERAL(5, 52, 10), // "Statuscode"
QT_MOC_LITERAL(6, 63, 17), // "AntwortAufAnfrage"
QT_MOC_LITERAL(7, 81, 28), // "AntwortAufSpielfeldParameter"
QT_MOC_LITERAL(8, 110, 9), // "xGridSize"
QT_MOC_LITERAL(9, 120, 9), // "yGridSize"
QT_MOC_LITERAL(10, 130, 10), // "Rundenzahl"
QT_MOC_LITERAL(11, 141, 11), // "Beginnender"
QT_MOC_LITERAL(12, 153, 22), // "AntwortAufRundenbeginn"
QT_MOC_LITERAL(13, 176, 11), // "Rundenummer"
QT_MOC_LITERAL(14, 188, 16), // "BeginnenderRunde"
QT_MOC_LITERAL(15, 205, 6), // "Fehler"
QT_MOC_LITERAL(16, 212, 1), // "f"
QT_MOC_LITERAL(17, 214, 15), // "connectToServer"
QT_MOC_LITERAL(18, 230, 14), // "sendParameters"
QT_MOC_LITERAL(19, 245, 6), // "length"
QT_MOC_LITERAL(20, 252, 4), // "var1"
QT_MOC_LITERAL(21, 257, 4), // "var2"
QT_MOC_LITERAL(22, 262, 4), // "var3"
QT_MOC_LITERAL(23, 267, 4), // "var4"
QT_MOC_LITERAL(24, 272, 20), // "disconnectFromServer"
QT_MOC_LITERAL(25, 293, 16), // "enableConnection"
QT_MOC_LITERAL(26, 310, 26), // "processRecievedInformation"
QT_MOC_LITERAL(27, 337, 12) // "disconnected"

    },
    "Client\0clientIsConnectedtoServer\0\0"
    "AntwortAufZug\0Cmd\0Statuscode\0"
    "AntwortAufAnfrage\0AntwortAufSpielfeldParameter\0"
    "xGridSize\0yGridSize\0Rundenzahl\0"
    "Beginnender\0AntwortAufRundenbeginn\0"
    "Rundenummer\0BeginnenderRunde\0Fehler\0"
    "f\0connectToServer\0sendParameters\0"
    "length\0var1\0var2\0var3\0var4\0"
    "disconnectFromServer\0enableConnection\0"
    "processRecievedInformation\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    2,   90,    2, 0x06 /* Public */,
       6,    2,   95,    2, 0x06 /* Public */,
       7,    5,  100,    2, 0x06 /* Public */,
      12,    3,  111,    2, 0x06 /* Public */,
      15,    1,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  121,    2, 0x0a /* Public */,
      18,    6,  122,    2, 0x0a /* Public */,
      18,    5,  135,    2, 0x2a /* Public | MethodCloned */,
      18,    4,  146,    2, 0x2a /* Public | MethodCloned */,
      18,    3,  155,    2, 0x2a /* Public | MethodCloned */,
      24,    0,  162,    2, 0x0a /* Public */,
      25,    0,  163,    2, 0x0a /* Public */,
      26,    0,  164,    2, 0x0a /* Public */,
      27,    0,  165,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar,    4,    5,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar,    4,    5,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   13,   14,
    QMetaType::Void, QMetaType::SChar,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   19,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   19,   20,   21,   22,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   19,   20,   21,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientIsConnectedtoServer(); break;
        case 1: _t->AntwortAufZug((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2]))); break;
        case 2: _t->AntwortAufAnfrage((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2]))); break;
        case 3: _t->AntwortAufSpielfeldParameter((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5]))); break;
        case 4: _t->AntwortAufRundenbeginn((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3]))); break;
        case 5: _t->Fehler((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 6: _t->connectToServer(); break;
        case 7: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5])),(*reinterpret_cast< qint8(*)>(_a[6]))); break;
        case 8: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5]))); break;
        case 9: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4]))); break;
        case 10: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3]))); break;
        case 11: _t->disconnectFromServer(); break;
        case 12: _t->enableConnection(); break;
        case 13: _t->processRecievedInformation(); break;
        case 14: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::clientIsConnectedtoServer)) {
                *result = 0;
            }
        }
        {
            typedef void (Client::*_t)(qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::AntwortAufZug)) {
                *result = 1;
            }
        }
        {
            typedef void (Client::*_t)(qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::AntwortAufAnfrage)) {
                *result = 2;
            }
        }
        {
            typedef void (Client::*_t)(qint8 , qint8 , qint8 , qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::AntwortAufSpielfeldParameter)) {
                *result = 3;
            }
        }
        {
            typedef void (Client::*_t)(qint8 , qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::AntwortAufRundenbeginn)) {
                *result = 4;
            }
        }
        {
            typedef void (Client::*_t)(qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::Fehler)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Client::clientIsConnectedtoServer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Client::AntwortAufZug(qint8 _t1, qint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::AntwortAufAnfrage(qint8 _t1, qint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::AntwortAufSpielfeldParameter(qint8 _t1, qint8 _t2, qint8 _t3, qint8 _t4, qint8 _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::AntwortAufRundenbeginn(qint8 _t1, qint8 _t2, qint8 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::Fehler(qint8 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
