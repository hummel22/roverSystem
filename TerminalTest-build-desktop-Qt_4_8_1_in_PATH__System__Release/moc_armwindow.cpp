/****************************************************************************
** Meta object code from reading C++ file 'armwindow.h'
**
** Created: Tue Apr 29 16:42:19 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/armwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'armwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_armWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x0a,
      27,   11,   10,   10, 0x0a,
      41,   11,   10,   10, 0x0a,
      52,   11,   10,   10, 0x0a,
      67,   11,   10,   10, 0x0a,
      84,   11,   10,   10, 0x0a,
     106,   11,   10,   10, 0x0a,
     121,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_armWindow[] = {
    "armWindow\0\0Angle\0Base(int)\0Shoulder(int)\0"
    "Elbow(int)\0WristBend(int)\0WristRotate(int)\0"
    "showWindowButton(int)\0ClawAngle(int)\0"
    "ShowWindowClick()\0"
};

void armWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        armWindow *_t = static_cast<armWindow *>(_o);
        switch (_id) {
        case 0: _t->Base((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Shoulder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Elbow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->WristBend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->WristRotate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->showWindowButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ClawAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ShowWindowClick(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData armWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject armWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_armWindow,
      qt_meta_data_armWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &armWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *armWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *armWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_armWindow))
        return static_cast<void*>(const_cast< armWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int armWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
