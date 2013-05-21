/***************************************************************************
 *   File:  maddataclassification.cpp created: 08/05/2013                                    *
 *   Class info: MadDataClassification                                               *
 *   Copyright (C) 2013 by: Jason S. Jorgenson                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <iomanip>

//Qt includes

//Local includes
#include "maddataclassification.h"
#include "lib/mad.h"

MadDataClassification::MadDataClassification(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    gbxCultivation->setChecked(false);
    cbExamples->setEnabled(true);
    lblExample->setVisible(true);
    lblExample->setText("Select Example");
}

void MadDataClassification::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void MadDataClassification::on_gbxCultivation_clicked()
{
    // if values are editable, should not be able to select for any
    // examples to be shown as it will destroy destroy current settings

    if (gbxCultivation->isChecked())
    {
        lblExample->setVisible(false);
        cbExamples->setDisabled(true);
    }
    else
    {
        cbExamples->setEnabled(true);
        lblExample->setVisible(true);
    }
}

void MadDataClassification::on_cbExamples_currentIndexChanged (const QString &theValue)
{
    // if enabled, set values for corresponding classification
    // options are: Platinum, Gold, Silver, Bronze
    if (cbExamples->currentText()!="Examples")
    {
        lblExample->setText(theValue);
    } //end if
    else
    {
        lblExample->setText("Select Example");
    } //end else
}

/**
 * @brief MadDataClassification::on_hsldrVariety_valueChanged
 * update label according to desired resolution
 * hardcoded for now at a range of 1 to 5
 * default values for slider range set in form at 0 to 1000
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrVariety_valueChanged(int theSliderValue)
{
    // update label according to desired resolution
    // hardcoded for now at a range of 1 to 5
    // slider goes from 0 to 1000

    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbVariety->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrSowing_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrSowing_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbSowing->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrHarvest_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrHarvest_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbHarvest->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrFertilisation_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrFertilisation_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbFertilisation->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrIrrigation_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrIrrigation_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbIrrigation->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrSeedDensity_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrSeedDensity_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbSeedDensity->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrYield_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrYield_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbYield->setValue(myPreciseValue);
}

/**
 * @brief MadDataClassification::on_hsldrTillage_valueChanged
 * @param theSliderValue
 */
void MadDataClassification::on_hsldrTillage_valueChanged(int theSliderValue)
{
    int myValue = (theSliderValue/100);
    float myPreciseValue = myValue/2.0;
    dsbTillage->setValue(myPreciseValue);
}

void MadDataClassification::on_cbCultivation_currentIndexChanged(const QString &theIndex)
{
    QString myIndex=theIndex;
    //this will do something...
}

void MadDataClassification::on_dsbVariety_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrVariety->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbSowing_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrSowing->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbHarvest_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrHarvest->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbFertilisation_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrFertilisation->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbIrrigation_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrIrrigation->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbSeedDensity_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrSeedDensity->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbYield_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrYield->setSliderPosition(myPosition);
}
void MadDataClassification::on_dsbTillage_valueChanged(double theValue)
{
    int myPosition;
    myPosition = theValue * 200;
    hsldrTillage->setSliderPosition(myPosition);
}




/*
class cultivation
{
public:
  MadSubCategory variety;
  MadSubCategory sowing;
  MadSubCategory harvest;
  MadSubCategory fertilisation;
  MadSubCategory irrigation;
  MadSubCategory seedDensity;
  MadSubCategory yield;
  MadSubCategory tillage;

};

class phenology
{
public:
  MadSubCategory emergence;
  MadSubCategory stemElongation;
  MadSubCategory earEmergence;
  MadSubCategory flowering;
  MadSubCategory yellowRipeness;

};

class previousCrop
{
public:
  MadSubCategory crop;
  MadSubCategory sowingDate;
  MadSubCategory harvestDate;
  MadSubCategory yield;
  MadSubCategory residueMgmt;
  MadSubCategory fertilisation;
  MadSubCategory irrigation;

};

class initialValues
{
public:
  MadSubCategory soilMoisture;
  MadSubCategory nitrogenMin;

};

class soil
{
public:
  MadSubCategory carbonOrganic;
  MadSubCategory nitrogenOrganic;
  MadSubCategory texture;
  MadSubCategory bulkDensity;
  MadSubCategory fieldCapacityMeas;
  MadSubCategory wiltingPointMeas;
  MadSubCategory pfCurve;
  MadSubCategory hydrCondCurve;
  MadSubCategory pH;

};

class siteData
{
public:
  MadSubCategory latitude;
  MadSubCategory longitude;
  MadSubCategory altitude;

};

class weatherData
{
public:
  MadSubCategory precipitation;
  MadSubCategory tAve;
  MadSubCategory tMin;
  MadSubCategory tMax;
  MadSubCategory relativeHumidity;
  MadSubCategory windSpeed;
  MadSubCategory globalRadiation;
  MadSubCategory sunshineHours;
  MadSubCategory leafWetness;
  MadSubCategory soilTemp;

};

class stateVariables // this has 4 sub classes
{
public:
  class crop
  {
  public:
    MadSubCategory aGrBiomass;
    MadSubCategory weightOrgans;
    MadSubCategory rootBiomass;
    MadSubCategory nInAGrBiomass;
    MadSubCategory nInOrgans;
    MadSubCategory lai;

  };

  class soil
  {
  public:
    MadSubCategory soilWaterGrav;
    MadSubCategory pressureHeads;
    MadSubCategory nMin;
    MadSubCategory soilWaterSensorCal;
    MadSubCategory waterFluxBottomRoot;
    MadSubCategory nitrogenFluxBottomRoot;

  };

  class surfaceFluxes
  {
  public:
    MadSubCategory et;
    MadSubCategory nh3Loss;
    MadSubCategory n2oLosse;
    MadSubCategory n2Loss;
    MadSubCategory ch4Loss;

  };

  class observations
  {
  public:
    MadSubCategory lodging;
    MadSubCategory pestsOrDiseases;
    MadSubCategory damages;

  };
};
*/
