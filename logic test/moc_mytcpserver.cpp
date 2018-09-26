/****************************************************************************
** Meta object code from reading C++ file 'mytcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mytcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTcpServer_t {
    QByteArrayData data[30];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTcpServer_t qt_meta_stringdata_MyTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyTcpServer"
QT_MOC_LITERAL(1, 12, 25), // "serverIsConnectedToClient"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 13), // "AntwortAufZug"
QT_MOC_LITERAL(4, 53, 3), // "Cmd"
QT_MOC_LITERAL(5, 57, 10), // "Statuscode"
QT_MOC_LITERAL(6, 68, 17), // "AntwortAufAnfrage"
QT_MOC_LITERAL(7, 86, 28), // "AntwortAufSpielfeldParameter"
QT_MOC_LITERAL(8, 115, 9), // "xGridSize"
QT_MOC_LITERAL(9, 125, 9), // "yGridSize"
QT_MOC_LITERAL(10, 135, 10), // "Rundenzahl"
QT_MOC_LITERAL(11, 146, 11), // "Beginnender"
QT_MOC_LITERAL(12, 158, 22), // "AntwortAufRundenbeginn"
QT_MOC_LITERAL(13, 181, 11), // "Rundenummer"
QT_MOC_LITERAL(14, 193, 16), // "BeginnenderRunde"
QT_MOC_LITERAL(15, 210, 6), // "Fehler"
QT_MOC_LITERAL(16, 217, 1), // "f"
QT_MOC_LITERAL(17, 219, 19), // "disconnectTheClient"
QT_MOC_LITERAL(18, 239, 10), // "openServer"
QT_MOC_LITERAL(19, 250, 19), // "disconnectTheServer"
QT_MOC_LITERAL(20, 270, 14), // "sendParameters"
QT_MOC_LITERAL(21, 285, 6), // "length"
QT_MOC_LITERAL(22, 292, 4), // "var1"
QT_MOC_LITERAL(23, 297, 4), // "var2"
QT_MOC_LITERAL(24, 302, 4), // "var3"
QT_MOC_LITERAL(25, 307, 4), // "var4"
QT_MOC_LITERAL(26, 312, 26), // "processRecievedInformation"
QT_MOC_LITERAL(27, 339, 11), // "closeServer"
QT_MOC_LITERAL(28, 351, 13), // "newConnection"
QT_MOC_LITERAL(29, 365, 12) // "disconnected"

    },
    "MyTcpServer\0serverIsConnectedToClient\0"
    "\0AntwortAufZug\0Cmd\0Statuscode\0"
    "AntwortAufAnfrage\0AntwortAufSpielfeldParameter\0"
    "xGridSize\0yGridSize\0Rundenzahl\0"
    "Beginnender\0AntwortAufRundenbeginn\0"
    "Rundenummer\0BeginnenderRunde\0Fehler\0"
    "f\0disconnectTheClient\0openServer\0"
    "disconnectTheServer\0sendParameters\0"
    "length\0var1\0var2\0var3\0var4\0"
    "processRecievedInformation\0closeServer\0"
    "newConnection\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTcpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    2,  100,    2, 0x06 /* Public */,
       6,    2,  105,    2, 0x06 /* Public */,
       7,    5,  110,    2, 0x06 /* Public */,
      12,    3,  121,    2, 0x06 /* Public */,
      15,    1,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  131,    2, 0x0a /* Public */,
      18,    0,  132,    2, 0x0a /* Public */,
      19,    0,  133,    2, 0x0a /* Public */,
      20,    6,  134,    2, 0x0a /* Public */,
      20,    5,  147,    2, 0x2a /* Public | MethodCloned */,
      20,    4,  158,    2, 0x2a /* Public | MethodCloned */,
      20,    3,  167,    2, 0x2a /* Public | MethodCloned */,
      26,    0,  174,    2, 0x0a /* Public */,
      27,    0,  175,    2, 0x0a /* Public */,
      28,    0,  176,    2, 0x0a /* Public */,
      29,    0,  177,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar,    4,    5,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar,    4,    5,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   13,   14,
    QMetaType::Void, QMetaType::SChar,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   21,   22,   23,   24,   25,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   21,   22,   23,
    QMetaType::Void, QMetaType::SChar, QMetaType::SChar, QMetaType::SChar,    4,   21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTcpServer *_t = static_cast<MyTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serverIsConnectedToClient(); break;
        case 1: _t->AntwortAufZug((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2]))); break;
        case 2: _t->AntwortAufAnfrage((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2]))); break;
        case 3: _t->AntwortAufSpielfeldParameter((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5]))); break;
        case 4: _t->AntwortAufRundenbeginn((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3]))); break;
        case 5: _t->Fehler((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 6: _t->disconnectTheClient(); break;
        case 7: _t->openServer(); break;
        case 8: _t->disconnectTheServer(); break;
        case 9: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5])),(*reinterpret_cast< qint8(*)>(_a[6]))); break;
        case 10: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4])),(*reinterpret_cast< qint8(*)>(_a[5]))); break;
        case 11: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< qint8(*)>(_a[4]))); break;
        case 12: _t->sendParameters((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3]))); break;
        case 13: _t->processRecievedInformation(); break;
        case 14: _t->closeServer(); break;
        case 15: _t->newConnection(); break;
        case 16: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTcpServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::serverIsConnectedToClient)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::AntwortAufZug)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::AntwortAufAnfrage)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(qint8 , qint8 , qint8 , qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::AntwortAufSpielfeldParameter)) {
                *result = 3;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(qint8 , qint8 , qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::AntwortAufRundenbeginn)) {
                *result = 4;
            }
        }
        {
            typedef void (MyTcpServer::*_t)(qint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTcpServer::Fehler)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MyTcpServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyTcpServer.data,
      qt_meta_data_MyTcpServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTcpServer.stringdata0))
        return static_cast<void*>(const_cast< MyTcpServer*>(this));
    return QObject::qt_metacast(_clname);
}

int MyTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MyTcpServer::serverIsConnectedToClient()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MyTcpServer::AntwortAufZug(qint8 _t1, qint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTcpServer::AntwortAufAnfrage(qint8 _t1, qint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTcpServer::AntwortAufSpielfeldParameter(qint8 _t1, qint8 _t2, qint8 _t3, qint8 _t4, qint8 _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTcpServer::AntwortAufRundenbeginn(qint8 _t1, qint8 _t2, qint8 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyTcpServer::Fehler(qint8 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
