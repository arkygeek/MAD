/****************************************************************************
** Meta object code from reading C++ file 'maddataclassification.h'
**
** Created: Sun May 19 18:37:07 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gui/maddataclassification.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maddataclassification.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MadDataClassification[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      60,   51,   22,   22, 0x08,
     118,  103,   22,   22, 0x08,
     152,  103,   22,   22, 0x08,
     185,  103,   22,   22, 0x08,
     219,  103,   22,   22, 0x08,
     259,  103,   22,   22, 0x08,
     296,  103,   22,   22, 0x08,
     334,  103,   22,   22, 0x08,
     366,  103,   22,   22, 0x08,
     409,  400,   22,   22, 0x08,
     455,   51,   22,   22, 0x08,
     490,   51,   22,   22, 0x08,
     524,   51,   22,   22, 0x08,
     559,   51,   22,   22, 0x08,
     600,   51,   22,   22, 0x08,
     638,   51,   22,   22, 0x08,
     677,   51,   22,   22, 0x08,
     710,   51,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MadDataClassification[] = {
    "MadDataClassification\0\0"
    "on_gbxCultivation_clicked()\0theValue\0"
    "on_cbExamples_currentIndexChanged(QString)\0"
    "theSliderValue\0on_hsldrVariety_valueChanged(int)\0"
    "on_hsldrSowing_valueChanged(int)\0"
    "on_hsldrHarvest_valueChanged(int)\0"
    "on_hsldrFertilisation_valueChanged(int)\0"
    "on_hsldrIrrigation_valueChanged(int)\0"
    "on_hsldrSeedDensity_valueChanged(int)\0"
    "on_hsldrYield_valueChanged(int)\0"
    "on_hsldrTillage_valueChanged(int)\0"
    "theIndex\0on_cbCultivation_currentIndexChanged(QString)\0"
    "on_dsbVariety_valueChanged(double)\0"
    "on_dsbSowing_valueChanged(double)\0"
    "on_dsbHarvest_valueChanged(double)\0"
    "on_dsbFertilisation_valueChanged(double)\0"
    "on_dsbIrrigation_valueChanged(double)\0"
    "on_dsbSeedDensity_valueChanged(double)\0"
    "on_dsbYield_valueChanged(double)\0"
    "on_dsbTillage_valueChanged(double)\0"
};

void MadDataClassification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MadDataClassification *_t = static_cast<MadDataClassification *>(_o);
        switch (_id) {
        case 0: _t->on_gbxCultivation_clicked(); break;
        case 1: _t->on_cbExamples_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_hsldrVariety_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_hsldrSowing_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_hsldrHarvest_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_hsldrFertilisation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_hsldrIrrigation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_hsldrSeedDensity_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_hsldrYield_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_hsldrTillage_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_cbCultivation_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_dsbVariety_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_dsbSowing_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_dsbHarvest_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_dsbFertilisation_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_dsbIrrigation_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_dsbSeedDensity_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->on_dsbYield_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_dsbTillage_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MadDataClassification::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MadDataClassification::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MadDataClassification,
      qt_meta_data_MadDataClassification, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MadDataClassification::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MadDataClassification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MadDataClassification::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MadDataClassification))
        return static_cast<void*>(const_cast< MadDataClassification*>(this));
    return QDialog::qt_metacast(_clname);
}

int MadDataClassification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
