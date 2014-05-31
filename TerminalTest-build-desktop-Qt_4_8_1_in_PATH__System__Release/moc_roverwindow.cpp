/****************************************************************************
** Meta object code from reading C++ file 'roverwindow.h'
**
** Created: Fri May 30 20:50:29 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/roverwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roverwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_roverWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      35,   31,   12,   12, 0x0a,
      63,   57,   12,   12, 0x0a,
      82,   76,   12,   12, 0x0a,
     101,   76,   12,   12, 0x0a,
     121,   76,   12,   12, 0x0a,
     139,   76,   12,   12, 0x0a,
     158,   76,   12,   12, 0x0a,
     171,   76,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_roverWindow[] = {
    "roverWindow\0\0showWindowClick()\0but\0"
    "showWindowButton(int)\0Power\0repaint(int)\0"
    "Angle\0frontleftSLOT(int)\0frontrightSLOT(int)\0"
    "backleftSLOT(int)\0backrightSLOT(int)\0"
    "panSLOT(int)\0tiltSLOT(int)\0"
};

void roverWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        roverWindow *_t = static_cast<roverWindow *>(_o);
        switch (_id) {
        case 0: _t->showWindowClick(); break;
        case 1: _t->showWindowButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->repaint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->frontleftSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->frontrightSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->backleftSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->backrightSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->panSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->tiltSLOT((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData roverWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject roverWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_roverWindow,
      qt_meta_data_roverWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &roverWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *roverWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *roverWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_roverWindow))
        return static_cast<void*>(const_cast< roverWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int roverWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
