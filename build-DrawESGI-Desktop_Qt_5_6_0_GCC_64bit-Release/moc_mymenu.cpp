/****************************************************************************
** Meta object code from reading C++ file 'mymenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DrawESGI/mymenu.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyMenu_t {
    QByteArrayData data[13];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyMenu_t qt_meta_stringdata_MyMenu = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyMenu"
QT_MOC_LITERAL(1, 7, 8), // "mySignal"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 15), // "QGraphicsScene*"
QT_MOC_LITERAL(4, 33, 14), // "signalOpenfile"
QT_MOC_LITERAL(5, 48, 8), // "QAction*"
QT_MOC_LITERAL(6, 57, 16), // "signalClearScene"
QT_MOC_LITERAL(7, 74, 17), // "signalSavePicture"
QT_MOC_LITERAL(8, 92, 18), // "signalPrintPicture"
QT_MOC_LITERAL(9, 111, 12), // "slotOpenfile"
QT_MOC_LITERAL(10, 124, 14), // "slotClearScene"
QT_MOC_LITERAL(11, 139, 15), // "slotSavePicture"
QT_MOC_LITERAL(12, 155, 16) // "slotPrintPicture"

    },
    "MyMenu\0mySignal\0\0QGraphicsScene*\0"
    "signalOpenfile\0QAction*\0signalClearScene\0"
    "signalSavePicture\0signalPrintPicture\0"
    "slotOpenfile\0slotClearScene\0slotSavePicture\0"
    "slotPrintPicture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    2,   62,    2, 0x06 /* Public */,
       6,    1,   67,    2, 0x06 /* Public */,
       7,    0,   70,    2, 0x06 /* Public */,
       8,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   72,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyMenu *_t = static_cast<MyMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mySignal((*reinterpret_cast< QGraphicsScene*(*)>(_a[1]))); break;
        case 1: _t->signalOpenfile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QAction*(*)>(_a[2]))); break;
        case 2: _t->signalClearScene((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->signalSavePicture(); break;
        case 4: _t->signalPrintPicture(); break;
        case 5: _t->slotOpenfile(); break;
        case 6: _t->slotClearScene(); break;
        case 7: _t->slotSavePicture(); break;
        case 8: _t->slotPrintPicture(); break;
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
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyMenu::*_t)(QGraphicsScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMenu::mySignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyMenu::*_t)(QString , QAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMenu::signalOpenfile)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyMenu::*_t)(QAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMenu::signalClearScene)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMenu::signalSavePicture)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyMenu::signalPrintPicture)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MyMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyMenu.data,
      qt_meta_data_MyMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyMenu.stringdata0))
        return static_cast<void*>(const_cast< MyMenu*>(this));
    if (!strcmp(_clname, "AbstractMenu"))
        return static_cast< AbstractMenu*>(const_cast< MyMenu*>(this));
    if (!strcmp(_clname, "fr.ESGI.abstractmenu"))
        return static_cast< AbstractMenu*>(const_cast< MyMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyMenu::mySignal(QGraphicsScene * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyMenu::signalOpenfile(QString _t1, QAction * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyMenu::signalClearScene(QAction * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyMenu::signalSavePicture()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MyMenu::signalPrintPicture()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
