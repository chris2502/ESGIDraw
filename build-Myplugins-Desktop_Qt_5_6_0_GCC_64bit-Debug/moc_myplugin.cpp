/****************************************************************************
** Meta object code from reading C++ file 'myplugin.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Myplugins/myplugin.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myplugin.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyPlugin_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPlugin_t qt_meta_stringdata_MyPlugin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyPlugin"
QT_MOC_LITERAL(1, 9, 8), // "mySignal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 15), // "QGraphicsScene*"
QT_MOC_LITERAL(4, 35, 14), // "signalOpenfile"
QT_MOC_LITERAL(5, 50, 12) // "slotOpenfile"

    },
    "MyPlugin\0mySignal\0\0QGraphicsScene*\0"
    "signalOpenfile\0slotOpenfile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MyPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPlugin *_t = static_cast<MyPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mySignal((*reinterpret_cast< QGraphicsScene*(*)>(_a[1]))); break;
        case 1: _t->signalOpenfile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotOpenfile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsScene* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyPlugin::*_t)(QGraphicsScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlugin::mySignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyPlugin::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPlugin::signalOpenfile)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MyPlugin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyPlugin.data,
      qt_meta_data_MyPlugin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyPlugin.stringdata0))
        return static_cast<void*>(const_cast< MyPlugin*>(this));
    if (!strcmp(_clname, "AbstractMenu"))
        return static_cast< AbstractMenu*>(const_cast< MyPlugin*>(this));
    if (!strcmp(_clname, "ID.AbstractMenu"))
        return static_cast< AbstractMenu*>(const_cast< MyPlugin*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyPlugin::mySignal(QGraphicsScene * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyPlugin::signalOpenfile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
