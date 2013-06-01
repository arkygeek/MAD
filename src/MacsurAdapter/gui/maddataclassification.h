/***************************************************************************
 *   File:  maddataclassification.h created: 08/05/2013          *
 *   Class info: MadDataClassification                   *
 *   Copyright (C) 2013 by: Jason S. Jorgenson               *
 *                                     *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or   *
 *   (at your option) any later version.                   *
 *                                     *
 *   This program is distributed in the hope that it will be useful,     *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 *   GNU General Public License for more details.              *
 *                                     *
 *   You should have received a copy of the GNU General Public License   *
 *   along with this program; if not, write to the             *
 *   Free Software Foundation, Inc.,                     *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.       *
 ***************************************************************************/

#ifndef MADDATACLASSIFICATION_H
#define MADDATACLASSIFICATION_H

// Local includes
#include "ui_maddataclassificationbase.h"
#include "lib/dataclassification/maddataclassificationcultivation.h"
#include "lib/dataclassification/maddataclassificationinitialvalues.h"
#include "lib/dataclassification/maddataclassificationphenology.h"
#include "lib/dataclassification/maddataclassificationprevcrop.h"
#include "lib/dataclassification/maddataclassificationsitedata.h"
#include "lib/dataclassification/maddataclassificationsoil.h"
#include "lib/dataclassification/maddataclassificationweather.h"
#include "lib/dataclassification/statevars/madstatevars.h"

// Qt includes

class MadDataClassification : public QDialog, private Ui::MadDataClassification
{
  Q_OBJECT

public:
  explicit MadDataClassification(QWidget *parent = 0);

protected:
  void changeEvent(QEvent *e);

private slots:
  void on_gbxCultivation_clicked();
  void on_cbExamples_currentIndexChanged(const QString &theValue);
  void on_hsldrVariety_valueChanged(int theSliderValue);
  void on_hsldrSowing_valueChanged(int theSliderValue);
  void on_hsldrHarvest_valueChanged(int theSliderValue);
  void on_hsldrFertilisation_valueChanged(int theSliderValue);
  void on_hsldrIrrigation_valueChanged(int theSliderValue);
  void on_hsldrSeedDensity_valueChanged(int theSliderValue);
  void on_hsldrYield_valueChanged(int theSliderValue);
  void on_hsldrTillage_valueChanged(int theSliderValue);
  void on_dsbVariety_valueChanged(double theValue);
  void on_dsbSowing_valueChanged(double theValue);
  void on_dsbHarvest_valueChanged(double theValue);
  void on_dsbFertilisation_valueChanged(double theValue);
  void on_dsbIrrigation_valueChanged(double theValue);
  void on_dsbSeedDensity_valueChanged(double theValue);
  void on_dsbYield_valueChanged(double theValue);
  void on_dsbTillage_valueChanged(double theValue);
  QString makeString(double theValue);

  void updateVarietyRatingLbl();
  void updateSowingRatingLbl();
  void updateHarvestRatingLbl();
  void updateFertilisationRatingLbl();
  void updateIrrigationRatingLbl();
  void updateSeedDensityRatingLbl();
  void updateYieldRatingLbl();
  void updateTillageRatingLbl();

  void on_pbSave_clicked();
  //void on_pbCultivationSet_clicked();
  void on_leDatasetName_textChanged(const QString &theText);
  void updateCultivationLabels();


  void on_gbxPhenology_clicked();
  void on_cbExamplesPhenology_currentIndexChanged(const QString &theValue);
  void on_hsldrEmergencePhenology_valueChanged(int theSliderValue);
  void on_hsldrStemElongationPhenology_valueChanged(int theSliderValue);
  void on_hsldrEarEmergencePhenology_valueChanged(int theSliderValue);
  void on_hsldrFloweringPhenology_valueChanged(int theSliderValue);
  void on_hsldrYellowRipenessPhenology_valueChanged(int theSliderValue);
  void on_dsbEmergencePhenology_valueChanged(double theValue);
  void on_dsbStemElongationPhenology_valueChanged(double theValue);
  void on_dsbEarEmergencePhenology_valueChanged(double theValue);
  void on_dsbFloweringPhenology_valueChanged(double theValue);
  void on_dsbYellowRipenessPhenology_valueChanged(double theValue);

  void updatePhenologyEmergenceRatingLbl();
  void updatePhenologyStemElongationRatingLbl();
  void updatePhenologyEarEmergenceRatingLbl();
  void updatePhenologyFloweringRatingLbl();
  void updatePhenologyYellowRipenessRatingLbl();

  //void on_pbPhenologySave_clicked();
  //void on_pbPhenologySet_clicked();
  void updatePhenologyLabels();

};

#endif // MADDATACLASSIFICATION_H
