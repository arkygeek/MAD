/****************************************************************************
** Meta object code from reading C++ file 'madcsvreader.h'
**
** Created: Mon Jul 29 13:52:29 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/madcsvreader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'madcsvreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MadCsvReader[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      60,   40,   13,   13, 0x08,
     102,   91,   13,   13, 0x28,

       0        // eod
};

static const char qt_meta_stringdata_MadCsvReader[] = {
    "MadCsvReader\0\0on_pbSelectFile_clicked()\0"
    "theQString,theQChar\0checkTheString(QString&,QChar)\0"
    "theQString\0checkTheString(QString&)\0"
};

void MadCsvReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MadCsvReader *_t = static_cast<MadCsvReader *>(_o);
        switch (_id) {
        case 0: _t->on_pbSelectFile_clicked(); break;
        case 1: _t->checkTheString((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QChar(*)>(_a[2]))); break;
        case 2: _t->checkTheString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MadCsvReader::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MadCsvReader::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MadCsvReader,
      qt_meta_data_MadCsvReader, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MadCsvReader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MadCsvReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MadCsvReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MadCsvReader))
        return static_cast<void*>(const_cast< MadCsvReader*>(this));
    return QDialog::qt_metacast(_clname);
}

int MadCsvReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
