/****************************************************************************
** Meta object code from reading C++ file 'v2rayLauncher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../v2rayLauncher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'v2rayLauncher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_v2rayLauncher_t {
    QByteArrayData data[12];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_v2rayLauncher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_v2rayLauncher_t qt_meta_stringdata_v2rayLauncher = {
    {
QT_MOC_LITERAL(0, 0, 13), // "v2rayLauncher"
QT_MOC_LITERAL(1, 14, 9), // "showAbout"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "startServer"
QT_MOC_LITERAL(4, 37, 10), // "stopServer"
QT_MOC_LITERAL(5, 48, 13), // "restartServer"
QT_MOC_LITERAL(6, 62, 7), // "quitApp"
QT_MOC_LITERAL(7, 70, 8), // "showMenu"
QT_MOC_LITERAL(8, 79, 17), // "trayiconActivated"
QT_MOC_LITERAL(9, 97, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(10, 131, 6), // "reason"
QT_MOC_LITERAL(11, 138, 16) // "ProcessIsCreated"

    },
    "v2rayLauncher\0showAbout\0\0startServer\0"
    "stopServer\0restartServer\0quitApp\0"
    "showMenu\0trayiconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0ProcessIsCreated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_v2rayLauncher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Bool,

       0        // eod
};

void v2rayLauncher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        v2rayLauncher *_t = static_cast<v2rayLauncher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showAbout(); break;
        case 1: _t->startServer(); break;
        case 2: _t->stopServer(); break;
        case 3: _t->restartServer(); break;
        case 4: _t->quitApp(); break;
        case 5: _t->showMenu(); break;
        case 6: _t->trayiconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 7: { bool _r = _t->ProcessIsCreated();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject v2rayLauncher::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_v2rayLauncher.data,
      qt_meta_data_v2rayLauncher,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *v2rayLauncher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *v2rayLauncher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_v2rayLauncher.stringdata0))
        return static_cast<void*>(const_cast< v2rayLauncher*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int v2rayLauncher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
