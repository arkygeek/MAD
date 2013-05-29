/***************************************************************************
 *   File:  maddataclassification.cpp created: 08/05/2013                  *
 *   Class info: MadDataClassification                                     *
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
#include <QString>
#include <QPixmap>

//Local includes
#include "maddataclassification.h"
#include "lib/mad.h"

QString makeString();

MadDataClassification::MadDataClassification(QWidget *parent) : QDialog(parent)
{
  setupUi(this);
  gbxCultivation->setChecked(false);
  cbExamples->setEnabled(true);
  lblExample->setVisible(true);
  lblExample->setText("Select Example");
  lblMedal->setVisible(false);
  lblRanking->setVisible(false);
  lblExample->setVisible(true);
  cbExamples->setDisabled(false);

  // These must stay here at the end
  connect ( sbVariety, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateVarietyRatingLbl() ));
  connect ( dsbVariety, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateVarietyRatingLbl() ));
  connect ( sbSowing, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSowingRatingLbl() ));
  connect ( dsbSowing, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSowingRatingLbl() ));
  connect ( sbHarvest, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateHarvestRatingLbl() ));
  connect ( dsbHarvest, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateHarvestRatingLbl() ));
  connect ( sbFertilisation, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateFertilisationRatingLbl() ));
  connect ( dsbFertilisation, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateFertilisationRatingLbl() ));
  connect ( sbIrrigation, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateIrrigationRatingLbl() ));
  connect ( dsbIrrigation, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateIrrigationRatingLbl() ));
  connect ( sbSeedDensity, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSeedDensityRatingLbl() ));
  connect ( dsbSeedDensity, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSeedDensityRatingLbl() ));
  connect ( sbYield, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateYieldRatingLbl() ));
  connect ( dsbYield, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateYieldRatingLbl() ));
  connect ( sbTillage, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateTillageRatingLbl() ));
  connect ( dsbTillage, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateTillageRatingLbl() ));
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
  updateVarietyRatingLbl();
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

void MadDataClassification::on_dsbVariety_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrVariety->setSliderPosition(myPosition);
  float myResult = dsbVariety->value() * sbVariety->value();
  lblVarietyRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbSowing_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrSowing->setSliderPosition(myPosition);
  float myResult = dsbSowing->value() * sbSowing->value();
  lblSowingRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbHarvest_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrHarvest->setSliderPosition(myPosition);
  float myResult = dsbHarvest->value() * sbHarvest->value();
  lblHarvestRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbFertilisation_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrFertilisation->setSliderPosition(myPosition);
  float myResult = dsbFertilisation->value() * sbFertilisation->value();
  lblFertilisationRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbIrrigation_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrIrrigation->setSliderPosition(myPosition);
  float myResult = dsbIrrigation->value() * sbIrrigation->value();
  lblIrrigationRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbSeedDensity_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrSeedDensity->setSliderPosition(myPosition);
  float myResult = dsbSeedDensity->value() * sbSeedDensity->value();
  lblSeedDensityRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbYield_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrYield->setSliderPosition(myPosition);
  float myResult = dsbYield->value() * sbYield->value();
  lblYieldRating->setText(makeString(myResult));
}
void MadDataClassification::on_dsbTillage_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrTillage->setSliderPosition(myPosition);
  float myResult = dsbTillage->value() * sbTillage->value();
  lblTillageRating->setText(makeString(myResult));
}

QString MadDataClassification::makeString(double theValue)
{
  QString myString = QString::number(theValue);
  return myString;
}

void MadDataClassification::updateVarietyRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbVariety->value();
  float myGivenWeighting = dsbVariety->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblVarietyRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateSowingRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSowing->value();
  float myGivenWeighting = dsbSowing->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSowingRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateHarvestRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbHarvest->value();
  float myGivenWeighting = dsbHarvest->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblHarvestRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateFertilisationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbFertilisation->value();
  float myGivenWeighting = dsbFertilisation->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblFertilisationRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateIrrigationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbIrrigation->value();
  float myGivenWeighting = dsbIrrigation->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblIrrigationRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateSeedDensityRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSeedDensity->value();
  float myGivenWeighting = dsbSeedDensity->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSeedDensityRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateYieldRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbYield->value();
  float myGivenWeighting = dsbYield->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblYieldRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateTillageRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbTillage->value();
  float myGivenWeighting = dsbTillage->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblTillageRating->setText(myText);
  updateCultivationLabels();
}
void MadDataClassification::updateCultivationLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblVarietyRating->text().toFloat();
  myTotal += lblSowingRating->text().toFloat();
  myTotal += lblHarvestRating->text().toFloat();
  myTotal += lblFertilisationRating->text().toFloat();
  myTotal += lblIrrigationRating->text().toFloat();
  myTotal += lblSeedDensityRating->text().toFloat();
  myTotal += lblYieldRating->text().toFloat();
  myTotal += lblTillageRating->text().toFloat();
  lblCombinedTotal->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 24) myRank=24;
  else if (myTotal >= 23) myRank=23;
  else if (myTotal >= 22) myRank=22;
  else if (myTotal >= 21) myRank=21;

  switch (myRank)
  {
    case 24: lblMedal->setVisible(true);
             lblMedal->setScaledContents(true);
             lblMedal->setPixmap(QPixmap( ":platinum.png" ));
             lblRanking->setVisible(true);
             lblRanking->setText("Platinum");
      break;

    case 23: lblMedal->setVisible(true);
             lblMedal->setScaledContents(true);
             lblMedal->setPixmap(QPixmap( ":gold.png" ));
             lblRanking->setVisible(true);
             lblRanking->setText("Gold");
      break;

    case 22: lblMedal->setVisible(true);
             lblMedal->setScaledContents(true);
             lblMedal->setPixmap(QPixmap( ":silver.png" ));
             lblRanking->setVisible(true);
             lblRanking->setText("Silver");
      break;

    case 21: lblMedal->setVisible(true);
             lblMedal->setScaledContents(true);
             lblMedal->setPixmap(QPixmap( ":bronze.png" ));
             lblRanking->setVisible(true);
             lblRanking->setText("Bronze");
      break;

    default: // hide
             lblRanking->setVisible(false);
             lblMedal->setVisible(false);
      break;
  }
}

void MadDataClassification::on_pbCultivationSave_clicked()
{
  // save current settings for cultivation to xml file
  // first we have to get the values
  MadDataClassificationCultivation myCultSet;
  MadSubCategory mySubCat;

  mySubCat.setMinData(chbxVariety->isChecked());
  mySubCat.setDepth(0);
  mySubCat.setWeightPoints(dsbVariety->value());
  mySubCat.setObservations(sbVariety->value());
  mySubCat.setReplicates(0);
  myCultSet.setVariety(mySubCat);




  //myCultSet.variety().minData(chbxVariety->isChecked());
  //myCultSet.variety().setDepth(sbVariety->value());
  //myCultSet.variety().setWeightPoints(dsbVariety->value());
  //myCultSet.variety().setObservations(0);
  //myCultSet.variety().setReplicates(0);

  QString myString;
  //myString = mySubCat.toXml();
  myString = myCultSet.toXml();
  textEdit->setText(myString);


  //mCrop.toXmlFile( LaUtils::userCropProfilesDirPath() +
  //    QDir::separator() + mCrop.guid() + ".xml");
}

void MadDataClassification::on_pbCultivationSet_clicked()
{
    // sets variables for cultivation
}
void MadDataClassification::on_lineEdit_2_textChanged(const QString &theText)
{
    if (theText != "")
    {
      pbCultivationSave->setEnabled(true);
    }
    else
    {
      pbCultivationSave->setEnabled(false);
    };
}
