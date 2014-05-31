/****************************************************************************
** Meta object code from reading C++ file 'workerall.h'
**
** Created: Sat May 31 16:11:59 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/workerall.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workerall.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ArmController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x05,
      47,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   61,   14,   14, 0x0a,
     102,   84,   14,   14, 0x0a,
     140,   14,   14,   14, 0x0a,
     148,   14,   14,   14, 0x0a,
     162,  160,   14,   14, 0x0a,
     181,   14,   14,   14, 0x0a,
     196,   14,   14,   14, 0x0a,
     211,   14,   14,   14, 0x0a,
     219,   14,   14,   14, 0x0a,
     236,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ArmController[] = {
    "ArmController\0\0out\0toTerminalInternal(QString)\0"
    "Send(QString)\0data\0keyInput(QString)\0"
    "X1,Y1,LT,X2,Y2,RT\0"
    "joystickData(int,int,int,int,int,int)\0"
    "reset()\0timeCheck()\0a\0buttonPressed(int)\0"
    "readyToDrive()\0driveToReady()\0toBin()\0"
    "storageToReady()\0mastRelease()\0"
};

void ArmController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ArmController *_t = static_cast<ArmController *>(_o);
        switch (_id) {
        case 0: _t->toTerminalInternal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->keyInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->joystickData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 4: _t->reset(); break;
        case 5: _t->timeCheck(); break;
        case 6: _t->buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->readyToDrive(); break;
        case 8: _t->driveToReady(); break;
        case 9: _t->toBin(); break;
        case 10: _t->storageToReady(); break;
        case 11: _t->mastRelease(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ArmController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ArmController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ArmController,
      qt_meta_data_ArmController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ArmController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ArmController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ArmController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ArmController))
        return static_cast<void*>(const_cast< ArmController*>(this));
    return QObject::qt_metacast(_clname);
}

int ArmController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ArmController::toTerminalInternal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ArmController::Send(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
