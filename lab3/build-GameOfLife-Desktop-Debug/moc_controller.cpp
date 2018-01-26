/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GameOfLife/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[30];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 18), // "environmentChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 2), // "ok"
QT_MOC_LITERAL(4, 34, 8), // "gameEnds"
QT_MOC_LITERAL(5, 43, 8), // "saveGame"
QT_MOC_LITERAL(6, 52, 8), // "loadGame"
QT_MOC_LITERAL(7, 61, 9), // "startGame"
QT_MOC_LITERAL(8, 71, 8), // "stopGame"
QT_MOC_LITERAL(9, 80, 5), // "clear"
QT_MOC_LITERAL(10, 86, 17), // "selectMasterColor"
QT_MOC_LITERAL(11, 104, 8), // "gameRule"
QT_MOC_LITERAL(12, 113, 7), // "setRule"
QT_MOC_LITERAL(13, 121, 1), // "r"
QT_MOC_LITERAL(14, 123, 11), // "cellsHeight"
QT_MOC_LITERAL(15, 135, 9), // "setHeight"
QT_MOC_LITERAL(16, 145, 1), // "h"
QT_MOC_LITERAL(17, 147, 10), // "cellsWidth"
QT_MOC_LITERAL(18, 158, 8), // "setWidth"
QT_MOC_LITERAL(19, 167, 1), // "w"
QT_MOC_LITERAL(20, 169, 8), // "interval"
QT_MOC_LITERAL(21, 178, 11), // "setInterval"
QT_MOC_LITERAL(22, 190, 4), // "msec"
QT_MOC_LITERAL(23, 195, 11), // "masterColor"
QT_MOC_LITERAL(24, 207, 14), // "setMasterColor"
QT_MOC_LITERAL(25, 222, 5), // "color"
QT_MOC_LITERAL(26, 228, 13), // "newGeneration"
QT_MOC_LITERAL(27, 242, 10), // "finishGame"
QT_MOC_LITERAL(28, 253, 8), // "lostGame"
QT_MOC_LITERAL(29, 262, 10) // "needUpdate"

    },
    "Controller\0environmentChanged\0\0ok\0"
    "gameEnds\0saveGame\0loadGame\0startGame\0"
    "stopGame\0clear\0selectMasterColor\0"
    "gameRule\0setRule\0r\0cellsHeight\0setHeight\0"
    "h\0cellsWidth\0setWidth\0w\0interval\0"
    "setInterval\0msec\0masterColor\0"
    "setMasterColor\0color\0newGeneration\0"
    "finishGame\0lostGame\0needUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    1,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  130,    2, 0x0a /* Public */,
       6,    0,  131,    2, 0x0a /* Public */,
       7,    0,  132,    2, 0x0a /* Public */,
       8,    0,  133,    2, 0x0a /* Public */,
       9,    0,  134,    2, 0x0a /* Public */,
      10,    0,  135,    2, 0x0a /* Public */,
      11,    0,  136,    2, 0x0a /* Public */,
      12,    1,  137,    2, 0x0a /* Public */,
      14,    0,  140,    2, 0x0a /* Public */,
      15,    1,  141,    2, 0x0a /* Public */,
      17,    0,  144,    2, 0x0a /* Public */,
      18,    1,  145,    2, 0x0a /* Public */,
      20,    0,  148,    2, 0x0a /* Public */,
      21,    1,  149,    2, 0x0a /* Public */,
      23,    0,  152,    2, 0x0a /* Public */,
      24,    1,  153,    2, 0x0a /* Public */,
      26,    0,  156,    2, 0x08 /* Private */,
      27,    0,  157,    2, 0x08 /* Private */,
      28,    0,  158,    2, 0x08 /* Private */,
      29,    0,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::QColor,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->environmentChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->gameEnds((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->saveGame(); break;
        case 3: _t->loadGame(); break;
        case 4: _t->startGame(); break;
        case 5: _t->stopGame(); break;
        case 6: _t->clear(); break;
        case 7: _t->selectMasterColor(); break;
        case 8: { QString _r = _t->gameRule();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setRule((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: { int _r = _t->cellsHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setHeight((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 12: { int _r = _t->cellsWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setWidth((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 14: { int _r = _t->interval();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->setInterval((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 16: { QColor _r = _t->masterColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->setMasterColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 18: _t->newGeneration(); break;
        case 19: _t->finishGame(); break;
        case 20: _t->lostGame(); break;
        case 21: _t->needUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::environmentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::gameEnds)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QWidget::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Controller::environmentChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::gameEnds(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
