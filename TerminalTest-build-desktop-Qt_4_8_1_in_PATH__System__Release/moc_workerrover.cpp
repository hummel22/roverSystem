/****************************************************************************
** Meta object code from reading C++ file 'workerrover.h'
**
** Created: Fri May 30 20:50:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/workerrover.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workerrover.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RoverController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x05,
      49,   17,   16,   16, 0x05,
      69,   63,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      91,   86,   16,   16, 0x0a,
     127,  109,   16,   16, 0x0a,
     165,   16,   16,   16, 0x0a,
     177,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RoverController[] = {
    "RoverController\0\0out\0toTerminalInternal(QString)\0"
    "Send(QString)\0Power\0powerUpdate(int)\0"
    "data\0keyInput(QString)\0X1,Y1,LT,X2,Y2,RT\0"
    "joystickData(int,int,int,int,int,int)\0"
    "timeCheck()\0buttonPress(int)\0"
};

void RoverController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RoverController *_t = static_cast<RoverController *>(_o);
        switch (_id) {
        case 0: _t->toTerminalInternal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->powerUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->keyInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->joystickData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 5: _t->timeCheck(); break;
        case 6: _t->buttonPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RoverController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RoverController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RoverController,
      qt_meta_data_RoverController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RoverController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RoverController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RoverController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoverController))
        return static_cast<void*>(const_cast< RoverController*>(this));
    return QObject::qt_metacast(_clname);
}

int RoverController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RoverController::toTerminalInternal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RoverController::Send(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RoverController::powerUpdate(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
