/****************************************************************************
** Meta object code from reading C++ file 'square.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../square.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'square.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Square_t {
    QByteArrayData data[13];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Square_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Square_t qt_meta_stringdata_Square = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Square"
QT_MOC_LITERAL(1, 7, 10), // "left_click"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "right_click"
QT_MOC_LITERAL(4, 31, 9), // "game_over"
QT_MOC_LITERAL(5, 41, 16), // "reveal_neighbour"
QT_MOC_LITERAL(6, 58, 6), // "reveal"
QT_MOC_LITERAL(7, 65, 7), // "flagged"
QT_MOC_LITERAL(8, 73, 6), // "isMine"
QT_MOC_LITERAL(9, 80, 9), // "unflagged"
QT_MOC_LITERAL(10, 90, 11), // "first_click"
QT_MOC_LITERAL(11, 102, 7), // "Square*"
QT_MOC_LITERAL(12, 110, 8) // "revealed"

    },
    "Square\0left_click\0\0right_click\0game_over\0"
    "reveal_neighbour\0reveal\0flagged\0isMine\0"
    "unflagged\0first_click\0Square*\0revealed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Square[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    1,   64,    2, 0x06 /* Public */,
       9,    1,   67,    2, 0x06 /* Public */,
      10,    1,   70,    2, 0x06 /* Public */,
      12,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,

       0        // eod
};

void Square::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Square *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->left_click(); break;
        case 1: _t->right_click(); break;
        case 2: _t->game_over(); break;
        case 3: _t->reveal_neighbour(); break;
        case 4: _t->reveal(); break;
        case 5: _t->flagged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->unflagged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->first_click((*reinterpret_cast< Square*(*)>(_a[1]))); break;
        case 8: _t->revealed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Square* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Square::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::left_click)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::right_click)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::game_over)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::reveal_neighbour)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::reveal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Square::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::flagged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Square::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::unflagged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Square::*)(Square * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::first_click)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Square::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Square::revealed)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Square::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_Square.data,
    qt_meta_data_Square,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Square::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Square::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Square.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int Square::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void Square::left_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Square::right_click()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Square::game_over()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Square::reveal_neighbour()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Square::reveal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Square::flagged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Square::unflagged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Square::first_click(Square * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Square::revealed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
