/****************************************************************************
** Meta object code from reading C++ file 'tictactoe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ticTacToe/Source/tictactoe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tictactoe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Lib__ticTacToe__TicTacToe_t {
    QByteArrayData data[12];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Lib__ticTacToe__TicTacToe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Lib__ticTacToe__TicTacToe_t qt_meta_stringdata_Lib__ticTacToe__TicTacToe = {
    {
QT_MOC_LITERAL(0, 0, 25), // "Lib::ticTacToe::TicTacToe"
QT_MOC_LITERAL(1, 26, 15), // "selectedChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 15), // "gameModeChanged"
QT_MOC_LITERAL(4, 59, 13), // "playerChanged"
QT_MOC_LITERAL(5, 73, 14), // "gameInterfaced"
QT_MOC_LITERAL(6, 88, 17), // "ui_welcomeMessage"
QT_MOC_LITERAL(7, 106, 9), // "ui_select"
QT_MOC_LITERAL(8, 116, 11), // "ui_gameMode"
QT_MOC_LITERAL(9, 128, 9), // "ui_player"
QT_MOC_LITERAL(10, 138, 7), // "ui_slot"
QT_MOC_LITERAL(11, 146, 9) // "ui_winner"

    },
    "Lib::ticTacToe::TicTacToe\0selectedChanged\0"
    "\0gameModeChanged\0playerChanged\0"
    "gameInterfaced\0ui_welcomeMessage\0"
    "ui_select\0ui_gameMode\0ui_player\0ui_slot\0"
    "ui_winner"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Lib__ticTacToe__TicTacToe[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       6,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00095401,
       7, QMetaType::QString, 0x00495003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::QString, 0x00495003,
      10, QMetaType::Int, 0x00495003,
      11, QMetaType::QString, 0x00095401,

 // properties: notify_signal_id
       0,
       0,
       0,
       2,
       3,
       0,

       0        // eod
};

void Lib::ticTacToe::TicTacToe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TicTacToe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectedChanged(); break;
        case 1: _t->gameModeChanged(); break;
        case 2: _t->playerChanged(); break;
        case 3: _t->gameInterfaced(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TicTacToe::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacToe::selectedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TicTacToe::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacToe::gameModeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TicTacToe::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacToe::playerChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TicTacToe::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacToe::gameInterfaced)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TicTacToe *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->welcomeMessage; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getSelected(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getMode(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getDefaultPlayer(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getSlot(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getWinner(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TicTacToe *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSelected(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setMode(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setDefaultPlayer(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->interfaceGame(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Lib::ticTacToe::TicTacToe::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Lib__ticTacToe__TicTacToe.data,
    qt_meta_data_Lib__ticTacToe__TicTacToe,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Lib::ticTacToe::TicTacToe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Lib::ticTacToe::TicTacToe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Lib__ticTacToe__TicTacToe.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Lib::ticTacToe::TicTacToe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Lib::ticTacToe::TicTacToe::selectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Lib::ticTacToe::TicTacToe::gameModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Lib::ticTacToe::TicTacToe::playerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Lib::ticTacToe::TicTacToe::gameInterfaced()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
