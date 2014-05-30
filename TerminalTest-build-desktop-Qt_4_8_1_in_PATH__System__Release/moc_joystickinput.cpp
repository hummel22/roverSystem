/****************************************************************************
** Meta object code from reading C++ file 'joystickinput.h'
**
** Created: Tue May 27 12:36:43 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/joystickinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joystickinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_joystickInput[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   15,   14,   14, 0x05,
      73,   71,   14,   14, 0x05,
      97,   92,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_joystickInput[] = {
    "joystickInput\0\0X1,Y1,LT,X2,Y2,RT\0"
    "joyStickData(int,int,int,int,int,int)\0"
    "b\0buttonPressed(int)\0send\0"
    "toTerminalInternal(QString)\0"
};

void joystickInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        joystickInput *_t = static_cast<joystickInput *>(_o);
        switch (_id) {
        case 0: _t->joyStickData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 1: _t->buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toTerminalInternal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData joystickInput::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject joystickInput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_joystickInput,
      qt_meta_data_joystickInput, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &joystickInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *joystickInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *joystickInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_joystickInput))
        return static_cast<void*>(const_cast< joystickInput*>(this));
    return QObject::qt_metacast(_clname);
}

int joystickInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void joystickInput::joyStickData(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void joystickInput::buttonPressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void joystickInput::toTerminalInternal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
