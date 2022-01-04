/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "preview"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "reset"
QT_MOC_LITERAL(4, 26, 9), // "startTask"
QT_MOC_LITERAL(5, 36, 22), // "on_NextTaskBtn_clicked"
QT_MOC_LITERAL(6, 59, 18), // "on_Preview_clicked"
QT_MOC_LITERAL(7, 78, 20), // "on_PlaySound_clicked"
QT_MOC_LITERAL(8, 99, 24), // "on_SubmitWorkBtn_clicked"
QT_MOC_LITERAL(9, 124, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 146, 19), // "on_VisGuide_clicked"
QT_MOC_LITERAL(11, 166, 7), // "checked"
QT_MOC_LITERAL(12, 174, 19), // "on_ClearBtn_clicked"
QT_MOC_LITERAL(13, 194, 21), // "on_SaveTskBtn_clicked"
QT_MOC_LITERAL(14, 216, 21), // "on_PrevTskBtn_clicked"
QT_MOC_LITERAL(15, 238, 15), // "on_OffG_clicked"
QT_MOC_LITERAL(16, 254, 19), // "on_PartialG_clicked"
QT_MOC_LITERAL(17, 274, 16), // "on_FullG_clicked"
QT_MOC_LITERAL(18, 291, 5), // "popup"
QT_MOC_LITERAL(19, 297, 4), // "text"
QT_MOC_LITERAL(20, 302, 12) // "correct_Cred"

    },
    "MainWindow\0preview\0\0reset\0startTask\0"
    "on_NextTaskBtn_clicked\0on_Preview_clicked\0"
    "on_PlaySound_clicked\0on_SubmitWorkBtn_clicked\0"
    "on_pushButton_clicked\0on_VisGuide_clicked\0"
    "checked\0on_ClearBtn_clicked\0"
    "on_SaveTskBtn_clicked\0on_PrevTskBtn_clicked\0"
    "on_OffG_clicked\0on_PartialG_clicked\0"
    "on_FullG_clicked\0popup\0text\0correct_Cred"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      10,    1,  113,    2, 0x08 /* Private */,
      12,    0,  116,    2, 0x08 /* Private */,
      13,    0,  117,    2, 0x08 /* Private */,
      14,    0,  118,    2, 0x08 /* Private */,
      15,    1,  119,    2, 0x08 /* Private */,
      16,    1,  122,    2, 0x08 /* Private */,
      17,    1,  125,    2, 0x08 /* Private */,
      18,    1,  128,    2, 0x08 /* Private */,
      20,    0,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preview(); break;
        case 1: _t->reset(); break;
        case 2: _t->startTask(); break;
        case 3: _t->on_NextTaskBtn_clicked(); break;
        case 4: _t->on_Preview_clicked(); break;
        case 5: _t->on_PlaySound_clicked(); break;
        case 6: _t->on_SubmitWorkBtn_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_VisGuide_clicked(); break;
        case 9: _t->on_VisGuide_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_ClearBtn_clicked(); break;
        case 11: _t->on_SaveTskBtn_clicked(); break;
        case 12: _t->on_PrevTskBtn_clicked(); break;
        case 13: _t->on_OffG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_PartialG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_FullG_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->popup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->correct_Cred(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::preview)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::reset)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startTask)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::preview()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::reset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::startTask()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
