/****************************************************************************
** Meta object code from reading C++ file 'madmainwindow.h'
**
** Created: Wed May 22 18:06:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../madmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'madmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MadMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      58,   45,   14,   14, 0x08,
     102,   14,   14,   14, 0x08,
     128,   14,   14,   14, 0x08,
     163,  154,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MadMainWindow[] = {
    "MadMainWindow\0\0on_pbClassification_clicked()\0"
    "theSelection\0on_cbAboutMain_currentIndexChanged(QString)\0"
    "on_pbViewAsText_clicked()\0"
    "on_actionOpen_triggered()\0theIndex\0"
    "on_lvwCurrentInventoryModels_clicked(QModelIndex)\0"
};

void MadMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MadMainWindow *_t = static_cast<MadMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pbClassification_clicked(); break;
        case 1: _t->on_cbAboutMain_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pbViewAsText_clicked(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->on_lvwCurrentInventoryModels_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MadMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MadMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MadMainWindow,
      qt_meta_data_MadMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MadMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MadMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MadMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MadMainWindow))
        return static_cast<void*>(const_cast< MadMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MadMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
