/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GameOfLife/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[48];
    char stringdata0[516];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "nextGeneration"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "ok"
QT_MOC_LITERAL(4, 30, 15), // "startButclicked"
QT_MOC_LITERAL(5, 46, 14), // "stopButclicked"
QT_MOC_LITERAL(6, 61, 15), // "clearButclicked"
QT_MOC_LITERAL(7, 77, 14), // "saveButclicked"
QT_MOC_LITERAL(8, 92, 14), // "loadButclicked"
QT_MOC_LITERAL(9, 107, 15), // "colorButclicked"
QT_MOC_LITERAL(10, 123, 21), // "rulesContValueChanged"
QT_MOC_LITERAL(11, 145, 21), // "iterInterValueChanged"
QT_MOC_LITERAL(12, 167, 22), // "heightContValueChanged"
QT_MOC_LITERAL(13, 190, 21), // "widthContValueChanged"
QT_MOC_LITERAL(14, 212, 13), // "newGeneration"
QT_MOC_LITERAL(15, 226, 17), // "selectMasterColor"
QT_MOC_LITERAL(16, 244, 9), // "startGame"
QT_MOC_LITERAL(17, 254, 8), // "stopGame"
QT_MOC_LITERAL(18, 263, 7), // "getNext"
QT_MOC_LITERAL(19, 271, 11), // "getUniverse"
QT_MOC_LITERAL(20, 283, 9), // "setHeight"
QT_MOC_LITERAL(21, 293, 1), // "h"
QT_MOC_LITERAL(22, 295, 8), // "setWidth"
QT_MOC_LITERAL(23, 304, 1), // "w"
QT_MOC_LITERAL(24, 306, 8), // "interval"
QT_MOC_LITERAL(25, 315, 11), // "setInterval"
QT_MOC_LITERAL(26, 327, 4), // "msec"
QT_MOC_LITERAL(27, 332, 11), // "masterColor"
QT_MOC_LITERAL(28, 344, 14), // "setMasterColor"
QT_MOC_LITERAL(29, 359, 5), // "color"
QT_MOC_LITERAL(30, 365, 7), // "setNext"
QT_MOC_LITERAL(31, 373, 18), // "std::vector<bool>&"
QT_MOC_LITERAL(32, 392, 1), // "n"
QT_MOC_LITERAL(33, 394, 11), // "setUniverse"
QT_MOC_LITERAL(34, 406, 1), // "u"
QT_MOC_LITERAL(35, 408, 10), // "needUpdate"
QT_MOC_LITERAL(36, 419, 8), // "startBut"
QT_MOC_LITERAL(37, 428, 7), // "stopBut"
QT_MOC_LITERAL(38, 436, 8), // "clearBut"
QT_MOC_LITERAL(39, 445, 7), // "saveBut"
QT_MOC_LITERAL(40, 453, 7), // "loadBut"
QT_MOC_LITERAL(41, 461, 8), // "colorBut"
QT_MOC_LITERAL(42, 470, 9), // "rulesCont"
QT_MOC_LITERAL(43, 480, 1), // "r"
QT_MOC_LITERAL(44, 482, 9), // "iterInter"
QT_MOC_LITERAL(45, 492, 2), // "it"
QT_MOC_LITERAL(46, 495, 10), // "heightCont"
QT_MOC_LITERAL(47, 506, 9) // "widthCont"

    },
    "MainWindow\0nextGeneration\0\0ok\0"
    "startButclicked\0stopButclicked\0"
    "clearButclicked\0saveButclicked\0"
    "loadButclicked\0colorButclicked\0"
    "rulesContValueChanged\0iterInterValueChanged\0"
    "heightContValueChanged\0widthContValueChanged\0"
    "newGeneration\0selectMasterColor\0"
    "startGame\0stopGame\0getNext\0getUniverse\0"
    "setHeight\0h\0setWidth\0w\0interval\0"
    "setInterval\0msec\0masterColor\0"
    "setMasterColor\0color\0setNext\0"
    "std::vector<bool>&\0n\0setUniverse\0u\0"
    "needUpdate\0startBut\0stopBut\0clearBut\0"
    "saveBut\0loadBut\0colorBut\0rulesCont\0r\0"
    "iterInter\0it\0heightCont\0widthCont"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x06 /* Public */,
       4,    1,  197,    2, 0x06 /* Public */,
       5,    1,  200,    2, 0x06 /* Public */,
       6,    1,  203,    2, 0x06 /* Public */,
       7,    1,  206,    2, 0x06 /* Public */,
       8,    1,  209,    2, 0x06 /* Public */,
       9,    1,  212,    2, 0x06 /* Public */,
      10,    1,  215,    2, 0x06 /* Public */,
      11,    1,  218,    2, 0x06 /* Public */,
      12,    1,  221,    2, 0x06 /* Public */,
      13,    1,  224,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  227,    2, 0x0a /* Public */,
      15,    0,  230,    2, 0x0a /* Public */,
      16,    0,  231,    2, 0x0a /* Public */,
      17,    0,  232,    2, 0x0a /* Public */,
      18,    0,  233,    2, 0x0a /* Public */,
      19,    0,  234,    2, 0x0a /* Public */,
      20,    1,  235,    2, 0x0a /* Public */,
      22,    1,  238,    2, 0x0a /* Public */,
      24,    0,  241,    2, 0x0a /* Public */,
      25,    1,  242,    2, 0x0a /* Public */,
      27,    0,  245,    2, 0x0a /* Public */,
      28,    1,  246,    2, 0x0a /* Public */,
      30,    1,  249,    2, 0x0a /* Public */,
      33,    1,  252,    2, 0x0a /* Public */,
      35,    0,  255,    2, 0x0a /* Public */,
      36,    0,  256,    2, 0x0a /* Public */,
      37,    0,  257,    2, 0x0a /* Public */,
      38,    0,  258,    2, 0x0a /* Public */,
      39,    0,  259,    2, 0x0a /* Public */,
      40,    0,  260,    2, 0x0a /* Public */,
      41,    0,  261,    2, 0x0a /* Public */,
      42,    1,  262,    2, 0x0a /* Public */,
      44,    1,  265,    2, 0x0a /* Public */,
      46,    1,  268,    2, 0x0a /* Public */,
      47,    1,  271,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::QColor,
    QMetaType::Void, QMetaType::QColor,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 31,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::Int,   45,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nextGeneration((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->startButclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->stopButclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->clearButclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->saveButclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->loadButclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->colorButclicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->rulesContValueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->iterInterValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->heightContValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->widthContValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->newGeneration((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->selectMasterColor(); break;
        case 13: _t->startGame(); break;
        case 14: _t->stopGame(); break;
        case 15: _t->getNext(); break;
        case 16: _t->getUniverse(); break;
        case 17: _t->setHeight((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 18: _t->setWidth((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 19: { int _r = _t->interval();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->setInterval((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 21: { QColor _r = _t->masterColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->setMasterColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 23: _t->setNext((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 24: _t->setUniverse((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 25: _t->needUpdate(); break;
        case 26: _t->startBut(); break;
        case 27: _t->stopBut(); break;
        case 28: _t->clearBut(); break;
        case 29: _t->saveBut(); break;
        case 30: _t->loadBut(); break;
        case 31: _t->colorBut(); break;
        case 32: _t->rulesCont((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->iterInter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->heightCont((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->widthCont((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::nextGeneration)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startButclicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::stopButclicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::clearButclicked)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::saveButclicked)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::loadButclicked)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::colorButclicked)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::rulesContValueChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::iterInterValueChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::heightContValueChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::widthContValueChanged)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::nextGeneration(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::startButclicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::stopButclicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::clearButclicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::saveButclicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::loadButclicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::colorButclicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::rulesContValueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::iterInterValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::heightContValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::widthContValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
