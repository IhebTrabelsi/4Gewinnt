/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "createServer"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "server"
QT_MOC_LITERAL(4, 32, 4), // "port"
QT_MOC_LITERAL(5, 37, 2), // "ip"
QT_MOC_LITERAL(6, 40, 12), // "createClient"
QT_MOC_LITERAL(7, 53, 11), // "spieleStein"
QT_MOC_LITERAL(8, 65, 1), // "x"
QT_MOC_LITERAL(9, 67, 10), // "signalQuit"
QT_MOC_LITERAL(10, 78, 13), // "signalSetSize"
QT_MOC_LITERAL(11, 92, 1), // "y"
QT_MOC_LITERAL(12, 94, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 116, 26), // "on_pushButton_Send_clicked"
QT_MOC_LITERAL(14, 143, 29), // "on_pushButton_Connect_clicked"
QT_MOC_LITERAL(15, 173, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(16, 195, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(17, 217, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(18, 237, 23), // "on_ButtonClient_clicked"
QT_MOC_LITERAL(19, 261, 23) // "on_ButtonServer_clicked"

    },
    "MainWindow\0createServer\0\0server\0port\0"
    "ip\0createClient\0spieleStein\0x\0signalQuit\0"
    "signalSetSize\0y\0on_pushButton_clicked\0"
    "on_pushButton_Send_clicked\0"
    "on_pushButton_Connect_clicked\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked\0"
    "on_checkBox_clicked\0on_ButtonClient_clicked\0"
    "on_ButtonServer_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       6,    3,   86,    2, 0x06 /* Public */,
       7,    1,   93,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    2,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::UShort, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::UShort, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::UChar,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,    8,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createServer((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->createClient((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->spieleStein((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 3: _t->signalQuit(); break;
        case 4: _t->signalSetSize((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_Send_clicked(); break;
        case 7: _t->on_pushButton_Connect_clicked(); break;
        case 8: _t->on_checkBox_2_clicked(); break;
        case 9: _t->on_checkBox_3_clicked(); break;
        case 10: _t->on_checkBox_clicked(); break;
        case 11: _t->on_ButtonClient_clicked(); break;
        case 12: _t->on_ButtonServer_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(bool , quint16 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::createServer)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool , quint16 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::createClient)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::spieleStein)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalQuit)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(quint8 , quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalSetSize)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::createServer(bool _t1, quint16 _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::createClient(bool _t1, quint16 _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::spieleStein(quint8 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::signalSetSize(quint8 _t1, quint8 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
