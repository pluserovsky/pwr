/****************************************************************************
** Meta object code from reading C++ file 'inwentarz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inwentarz/inwentarz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inwentarz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_inwentarz_t {
    QByteArrayData data[8];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_inwentarz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_inwentarz_t qt_meta_stringdata_inwentarz = {
    {
QT_MOC_LITERAL(0, 0, 9), // "inwentarz"
QT_MOC_LITERAL(1, 10, 28), // "on_pushButton_zapisz_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 39), // "on_spinBox_nrPomieszczenia_va..."
QT_MOC_LITERAL(4, 80, 4), // "arg1"
QT_MOC_LITERAL(5, 85, 40), // "on_comboBox_komputer_currentI..."
QT_MOC_LITERAL(6, 126, 5), // "index"
QT_MOC_LITERAL(7, 132, 29) // "on_spinBox_ilosc_valueChanged"

    },
    "inwentarz\0on_pushButton_zapisz_clicked\0"
    "\0on_spinBox_nrPomieszczenia_valueChanged\0"
    "arg1\0on_comboBox_komputer_currentIndexChanged\0"
    "index\0on_spinBox_ilosc_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_inwentarz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void inwentarz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        inwentarz *_t = static_cast<inwentarz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_zapisz_clicked(); break;
        case 1: _t->on_spinBox_nrPomieszczenia_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_komputer_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spinBox_ilosc_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject inwentarz::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_inwentarz.data,
      qt_meta_data_inwentarz,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *inwentarz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *inwentarz::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_inwentarz.stringdata0))
        return static_cast<void*>(const_cast< inwentarz*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int inwentarz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_END_MOC_NAMESPACE
