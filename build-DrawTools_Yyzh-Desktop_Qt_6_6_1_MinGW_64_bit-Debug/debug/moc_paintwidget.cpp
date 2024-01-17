/****************************************************************************
** Meta object code from reading C++ file 'paintwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawTools_Yyzh/paintwidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPaintWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPaintWidgetENDCLASS = QtMocHelpers::stringData(
    "PaintWidget",
    "setCurrentShape",
    "",
    "Shape::Code",
    "s",
    "undo",
    "clearAll",
    "setPenWidth",
    "width",
    "copySelectedShapes",
    "showContextMenu",
    "pos",
    "changeSelectedShapeColor",
    "changeSelectedShapePenWidth"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPaintWidgetENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[2];
    char stringdata5[5];
    char stringdata6[9];
    char stringdata7[12];
    char stringdata8[6];
    char stringdata9[19];
    char stringdata10[16];
    char stringdata11[4];
    char stringdata12[25];
    char stringdata13[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPaintWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPaintWidgetENDCLASS_t qt_meta_stringdata_CLASSPaintWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "PaintWidget"
        QT_MOC_LITERAL(12, 15),  // "setCurrentShape"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 11),  // "Shape::Code"
        QT_MOC_LITERAL(41, 1),  // "s"
        QT_MOC_LITERAL(43, 4),  // "undo"
        QT_MOC_LITERAL(48, 8),  // "clearAll"
        QT_MOC_LITERAL(57, 11),  // "setPenWidth"
        QT_MOC_LITERAL(69, 5),  // "width"
        QT_MOC_LITERAL(75, 18),  // "copySelectedShapes"
        QT_MOC_LITERAL(94, 15),  // "showContextMenu"
        QT_MOC_LITERAL(110, 3),  // "pos"
        QT_MOC_LITERAL(114, 24),  // "changeSelectedShapeColor"
        QT_MOC_LITERAL(139, 27)   // "changeSelectedShapePenWidth"
    },
    "PaintWidget",
    "setCurrentShape",
    "",
    "Shape::Code",
    "s",
    "undo",
    "clearAll",
    "setPenWidth",
    "width",
    "copySelectedShapes",
    "showContextMenu",
    "pos",
    "changeSelectedShapeColor",
    "changeSelectedShapePenWidth"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPaintWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x0a,    1 /* Public */,
       5,    0,   65,    2, 0x0a,    3 /* Public */,
       6,    0,   66,    2, 0x0a,    4 /* Public */,
       7,    1,   67,    2, 0x0a,    5 /* Public */,
       9,    0,   70,    2, 0x0a,    7 /* Public */,
      10,    1,   71,    2, 0x0a,    8 /* Public */,
      12,    0,   74,    2, 0x0a,   10 /* Public */,
      13,    0,   75,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PaintWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSPaintWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPaintWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPaintWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PaintWidget, std::true_type>,
        // method 'setCurrentShape'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Shape::Code, std::false_type>,
        // method 'undo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setPenWidth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'copySelectedShapes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'changeSelectedShapeColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeSelectedShapePenWidth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PaintWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PaintWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCurrentShape((*reinterpret_cast< std::add_pointer_t<Shape::Code>>(_a[1]))); break;
        case 1: _t->undo(); break;
        case 2: _t->clearAll(); break;
        case 3: _t->setPenWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->copySelectedShapes(); break;
        case 5: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 6: _t->changeSelectedShapeColor(); break;
        case 7: _t->changeSelectedShapePenWidth(); break;
        default: ;
        }
    }
}

const QMetaObject *PaintWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPaintWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PaintWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
