/****************************************************************************
** Meta object code from reading C++ file 'joystickwindow.h'
**
** Created: Tue Apr 29 16:42:17 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/joystickwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joystickwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_joystickWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   16,   15,   15, 0x0a,
      74,   72,   15,   15, 0x0a,
      93,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_joystickWindow[] = {
    "joystickWindow\0\0X1,Y1,LT,X2,Y2,RT\0"
    "joystickData(int,int,int,int,int,int)\0"
    "b\0buttonPressed(int)\0showWindow()\0"
};

void joystickWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        joystickWindow *_t = static_cast<joystickWindow *>(_o);
        switch (_id) {
        case 0: _t->joystickData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 1: _t->buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->showWindow(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData joystickWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject joystickWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_joystickWindow,
      qt_meta_data_joystickWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &joystickWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *joystickWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *joystickWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_joystickWindow))
        return static_cast<void*>(const_cast< joystickWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int joystickWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
