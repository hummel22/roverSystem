/****************************************************************************
** Meta object code from reading C++ file 'diagnostics.h'
**
** Created: Tue Apr 29 16:42:20 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../operator/diagnostics.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagnostics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Diagnostics[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,
      46,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   12,   12,   12, 0x0a,
      73,   12,   12,   12, 0x0a,
      90,   88,   12,   12, 0x0a,
     115,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Diagnostics[] = {
    "Diagnostics\0\0send\0toInternalTerminal(QString)\0"
    "Send(QString)\0showWindow()\0updateButton()\0"
    "x\0receiveAttributes(int[])\0syncAll()\0"
};

void Diagnostics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Diagnostics *_t = static_cast<Diagnostics *>(_o);
        switch (_id) {
        case 0: _t->toInternalTerminal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->showWindow(); break;
        case 3: _t->updateButton(); break;
        case 4: _t->receiveAttributes((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 5: _t->syncAll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Diagnostics::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Diagnostics::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Diagnostics,
      qt_meta_data_Diagnostics, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Diagnostics::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Diagnostics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Diagnostics::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Diagnostics))
        return static_cast<void*>(const_cast< Diagnostics*>(this));
    return QObject::qt_metacast(_clname);
}

int Diagnostics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Diagnostics::toInternalTerminal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Diagnostics::Send(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
