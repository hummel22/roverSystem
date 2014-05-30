/****************************************************************************
** Meta object code from reading C++ file 'receiveswitch.h'
**
** Created: Tue May 27 12:36:42 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/receiveswitch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receiveswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_receiveSwitch[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x05,
      51,   14,   14,   14, 0x05,
      70,   65,   14,   14, 0x05,
      86,   84,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,  109,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_receiveSwitch[] = {
    "receiveSwitch\0\0display\0"
    "toTerminalInternal(QString)\0resetHeader()\0"
    "send\0Send(QString)\0x\0servoAttributes(int[])\0"
    "receive\0interpret(QString)\0"
};

void receiveSwitch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        receiveSwitch *_t = static_cast<receiveSwitch *>(_o);
        switch (_id) {
        case 0: _t->toTerminalInternal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->resetHeader(); break;
        case 2: _t->Send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->servoAttributes((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 4: _t->interpret((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData receiveSwitch::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject receiveSwitch::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_receiveSwitch,
      qt_meta_data_receiveSwitch, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &receiveSwitch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *receiveSwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *receiveSwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_receiveSwitch))
        return static_cast<void*>(const_cast< receiveSwitch*>(this));
    return QObject::qt_metacast(_clname);
}

int receiveSwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void receiveSwitch::toTerminalInternal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void receiveSwitch::resetHeader()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void receiveSwitch::Send(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void receiveSwitch::servoAttributes(int _t1[])
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
