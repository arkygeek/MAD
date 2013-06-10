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
#include "lib/dataclassification/maddataclassificationmanagement.h"
#include "lib/dataclassification/maddataclassificationinitialvalues.h"
#include "lib/dataclassification/maddataclassificationphenology.h"
#include "lib/dataclassification/maddataclassificationprevcrop.h"
#include "lib/dataclassification/maddataclassificationsitedata.h"
#include "lib/dataclassification/maddataclassificationsoil.h"
#include "lib/dataclassification/maddataclassificationweather.h"
#include "lib/dataclassification/statevars/madstatevars.h"
#include "lib/maddataset.h"


#include "lib/madutils.h"
#include "lib/madguid.h"
#include "lib/madserialisable.h"
#include "lib/madserialisable.h"



// Qt includes

class MadDataClassification : public QDialog, private Ui::MadDataClassification
{
  Q_OBJECT

public:
  explicit MadDataClassification(QWidget *parent = 0);

protected:
  void changeEvent(QEvent *e);

private slots:

     //-------------------------------------//
    //  link sliders and calculate points  //
   //-------------------------------------//
  // management
  void on_gbxManagement_clicked();
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

  // phenology
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

  // previous crop
  void on_gbxPrevCrop_clicked();
  void on_cbExamplesPrevCrop_currentIndexChanged(const QString &theValue);

  void on_hsldrCropPrevCrop_valueChanged(int theSliderValue);
  void on_hsldrSowingDatePrevCrop_valueChanged(int theSliderValue);
  void on_hsldrHarvestDatePrevCrop_valueChanged(int theSliderValue);
  void on_hsldrYieldPrevCrop_valueChanged(int theSliderValue);
  void on_hsldrResidueMgmtPrevCrop_valueChanged(int theSliderValue);
  void on_hsldrFertilisationPrevCrop_valueChanged(int theSliderValue);
  void on_hsldrIrrigationPrevCrop_valueChanged(int theSliderValue);

  void on_dsbCropPrevCrop_valueChanged(double theValue);
  void on_dsbSowingDatePrevCrop_valueChanged(double theValue);
  void on_dsbHarvestDatePrevCrop_valueChanged(double theValue);
  void on_dsbYieldPrevCrop_valueChanged(double theSliderValue);
  void on_dsbResidueMgmtPrevCrop_valueChanged(double theValue);
  void on_dsbFertilisationPrevCrop_valueChanged(double theValue);
  void on_dsbIrrigationPrevCrop_valueChanged(double theValue);

  // initial values
  void on_gbxInitialValues_clicked();
  void on_cbExamplesInitialValues_currentIndexChanged(const QString &theValue);

  void on_hsldrSoilMoistureInitialValues_valueChanged(int theSliderValue);
  void on_hsldrNMinInitialValues_valueChanged(int theSliderValue);

  void on_dsbSoilMoistureInitialValues_valueChanged(double theValue);
  void on_dsbNMinInitialValues_valueChanged(double theValue);

  // soil
  void on_gbxSoil_clicked();
  void on_cbExamplesSoil_currentIndexChanged(const QString &theValue);

  void on_hsldrCOrgSoil_valueChanged(int theSliderValue);
  void on_hsldrNOrgSoil_valueChanged(int theSliderValue);
  void on_hsldrTextureSoil_valueChanged(int theSliderValue);
  void on_hsldrBulkDensitySoil_valueChanged(int theSliderValue);
  void on_hsldrFieldCapacitySoil_valueChanged(int theSliderValue);
  void on_hsldrWiltingPointSoil_valueChanged(int theSliderValue);
  void on_hsldrPfCurveSoil_valueChanged(int theSliderValue);
  void on_hsldrHydrCondCurveSoil_valueChanged(int theSliderValue);
  void on_hsldrPhSoil_valueChanged(int theSliderValue);

  void on_dsbCOrgSoil_valueChanged(double theValue);
  void on_dsbNOrgSoil_valueChanged(double theValue);
  void on_dsbTextureSoil_valueChanged(double theValue);
  void on_dsbBulkDensitySoil_valueChanged(double theValue);
  void on_dsbFieldCapacitySoil_valueChanged(double theValue);
  void on_dsbWiltingPointSoil_valueChanged(double theValue);
  void on_dsbPfCurveSoil_valueChanged(double theValue);
  void on_dsbHydrCondCurveSoil_valueChanged(double theValue);
  void on_dsbPhSoil_valueChanged(double theValue);

  // site
  void on_gbxSite_clicked();
  void on_cbExamplesSite_currentIndexChanged(const QString &theValue);

  void on_hsldrLatitudeSite_valueChanged(int theSliderValue);
  void on_hsldrLongitudeSite_valueChanged(int theSliderValue);
  void on_hsldrAltitudeSite_valueChanged(int theSliderValue);

  void on_dsbLatitudeSite_valueChanged(double theValue);
  void on_dsbLongitudeSite_valueChanged(double theValue);
  void on_dsbAltitudeSite_valueChanged(double theValue);

  // weather
  void on_gbxWeather_clicked();
  void on_cbExamplesWeather_currentIndexChanged(const QString &theValue);

  void on_hsldrPrecipitationWeather_valueChanged(int theSliderValue);
  void on_hsldrTAveWeather_valueChanged(int theSliderValue);
  void on_hsldrTMinWeather_valueChanged(int theSliderValue);
  void on_hsldrTMaxWeather_valueChanged(int theSliderValue);
  void on_hsldrRelHumidityWeather_valueChanged(int theSliderValue);
  void on_hsldrWindSpeedWeather_valueChanged(int theSliderValue);
  void on_hsldrGlobalRadiationWeather_valueChanged(int theSliderValue);
  void on_hsldrSunshineHoursWeather_valueChanged(int theSliderValue);
  void on_hsldrLeafWetnessWeather_valueChanged(int theSliderValue);
  void on_hsldrSoilTempWeather_valueChanged(int theSliderValue);

  void on_dsbPrecipitationWeather_valueChanged(double theValue);
  void on_dsbTAveWeather_valueChanged(double theValue);
  void on_dsbTMinWeather_valueChanged(double theValue);
  void on_dsbTMaxWeather_valueChanged(double theValue);
  void on_dsbRelHumidityWeather_valueChanged(double theValue);
  void on_dsbWindSpeedWeather_valueChanged(double theValue);
  void on_dsbGlobalRadiationWeather_valueChanged(double theValue);
  void on_dsbSunshineHoursWeather_valueChanged(double theValue);
  void on_dsbLeafWetnessWeather_valueChanged(double theValue);
  void on_dsbSoilTempWeather_valueChanged(double theValue);

  // state vars (calculate points only - no sliders on form for SV)
  // SV Crop
  void  on_gbxSVCrop_clicked();
  void on_cbExamplesSVCrop_currentIndexChanged(const QString &theValue);

  void on_dsbSVCropAGrBiomassLayers_valueChanged();
  void on_sbSVCropAGrBiomassObservations_valueChanged();
  void on_dsbSVCropAGrBiomassWeightPts_valueChanged();
  void on_dsbSVCropAGrBiomassReplicates_valueChanged();

  void on_dsbSVCropWeightOrgansLayers_valueChanged();
  void on_sbSVCropWeightOrgansObservations_valueChanged();
  void on_dsbSVCropWeightOrgansWeightPts_valueChanged();
  void on_dsbSVCropWeightOrgansReplicates_valueChanged();

  void on_dsbSVCropRootBiomassLayers_valueChanged();
  void on_sbSVCropRootBiomassObservations_valueChanged();
  void on_dsbSVCropRootBiomassWeightPts_valueChanged();
  void on_dsbSVCropRootBiomassReplicates_valueChanged();

  void on_dsbSVCropNInAGrBiomassLayers_valueChanged();
  void on_sbSVCropNInAGrBiomassObservations_valueChanged();
  void on_dsbSVCropNInAGrBiomassWeightPts_valueChanged();
  void on_dsbSVCropNInAGrBiomassReplicates_valueChanged();

  void on_dsbSVCropNInOrgansLayers_valueChanged();
  void on_sbSVCropNInOrgansObservations_valueChanged();
  void on_dsbSVCropNInOrgansWeightPts_valueChanged();
  void on_dsbSVCropNInOrgansReplicates_valueChanged();

  void on_dsbSVCropLAILayers_valueChanged();
  void on_sbSVCropLAIObservations_valueChanged();
  void on_dsbSVCropLAIWeightPts_valueChanged();
  void on_dsbSVCropLAIReplicates_valueChanged();

  // SV Soil
  void  on_gbxSVSoil_clicked();
  void on_cbExamplesSVSoil_currentIndexChanged(const QString &theValue);

  void on_dsbSVSoilSoilWaterGravLayers_valueChanged();
  void on_sbSVSoilSoilWaterGravObservations_valueChanged();
  void on_dsbSVSoilSoilWaterGravWeightPts_valueChanged();
  void on_dsbSVSoilSoilWaterGravReplicates_valueChanged();

  void on_dsbSVSoilPressureHeadsLayers_valueChanged();
  void on_sbSVSoilPressureHeadsObservations_valueChanged();
  void on_dsbSVSoilPressureHeadsWeightPts_valueChanged();
  void on_dsbSVSoilPressureHeadsReplicates_valueChanged();

  void on_dsbSVSoilNMinLayers_valueChanged();
  void on_sbSVSoilNMinObservations_valueChanged();
  void on_dsbSVSoilNMinWeightPts_valueChanged();
  void on_dsbSVSoilNMinReplicates_valueChanged();

  void on_dsbSVSoilSoilWaterSensorCalLayers_valueChanged();
  void on_sbSVSoilSoilWaterSensorCalObservations_valueChanged();
  void on_dsbSVSoilSoilWaterSensorCalWeightPts_valueChanged();
  void on_dsbSVSoilSoilWaterSensorCalReplicates_valueChanged();

  void on_dsbSVSoilWaterFluxBottomRootLayers_valueChanged();
  void on_sbSVSoilWaterFluxBottomRootObservations_valueChanged();
  void on_dsbSVSoilWaterFluxBottomRootWeightPts_valueChanged();
  void on_dsbSVSoilWaterFluxBottomRootReplicates_valueChanged();

  void on_dsbSVSoilNFluxBottomRootLayers_valueChanged();
  void on_sbSVSoilNFluxBottomRootObservations_valueChanged();
  void on_dsbSVSoilNFluxBottomRootWeightPts_valueChanged();
  void on_dsbSVSoilNFluxBottomRootReplicates_valueChanged();

  // SV surface fluxes
  void  on_gbxSVSurfaceFluxes_clicked();
  void on_cbExamplesSVSurfaceFluxes_currentIndexChanged(const QString &theValue);

  void on_dsbSVSurfaceFluxesEtLayers_valueChanged();
  void on_sbSVSurfaceFluxesEtObservations_valueChanged();
  void on_dsbSVSurfaceFluxesEtWeightPts_valueChanged();
  void on_dsbSVSurfaceFluxesEtReplicates_valueChanged();

  void on_dsbSVSurfaceFluxesNh3LossLayers_valueChanged();
  void on_sbSVSurfaceFluxesNh3LossObservations_valueChanged();
  void on_dsbSVSurfaceFluxesNh3LossWeightPts_valueChanged();
  void on_dsbSVSurfaceFluxesNh3LossReplicates_valueChanged();

  void on_dsbSVSurfaceFluxesN2OLossLayers_valueChanged();
  void on_sbSVSurfaceFluxesN2OLossObservations_valueChanged();
  void on_dsbSVSurfaceFluxesN2OLossWeightPts_valueChanged();
  void on_dsbSVSurfaceFluxesN2OLossReplicates_valueChanged();

  void on_dsbSVSurfaceFluxesN2LossLayers_valueChanged();
  void on_sbSVSurfaceFluxesN2LossObservations_valueChanged();
  void on_dsbSVSurfaceFluxesN2LossWeightPts_valueChanged();
  void on_dsbSVSurfaceFluxesN2LossReplicates_valueChanged();

  void on_dsbSVSurfaceFluxesCh4LossLayers_valueChanged();
  void on_sbSVSurfaceFluxesCh4LossObservations_valueChanged();
  void on_dsbSVSurfaceFluxesCh4LossWeightPts_valueChanged();
  void on_dsbSVSurfaceFluxesCh4LossReplicates_valueChanged();

  // SV observations
  void  on_gbxSVObservations_clicked();
  void on_cbExamplesSVObservations_currentIndexChanged(const QString &theValue);

  void on_dsbSVObservationsLodgingLayers_valueChanged();
  void on_sbSVObservationsLodgingObservations_valueChanged();
  void on_dsbSVObservationsLodgingWeightPts_valueChanged();
  void on_dsbSVObservationsLodgingReplicates_valueChanged();

  void on_dsbSVObservationsPestsOrDiseasesLayers_valueChanged();
  void on_sbSVObservationsPestsOrDiseasesObservations_valueChanged();
  void on_dsbSVObservationsPestsOrDiseasesWeightPts_valueChanged();
  void on_dsbSVObservationsPestsOrDiseasesReplicates_valueChanged();

  void on_dsbSVObservationsDamagesLayers_valueChanged();
  void on_sbSVObservationsDamagesObservations_valueChanged();
  void on_dsbSVObservationsDamagesWeightPts_valueChanged();
  void on_dsbSVObservationsDamagesReplicates_valueChanged();


     //----------------//
    // update labels  //
   //----------------//
  // management
  void updateVarietyRatingLbl();
  void updateSowingRatingLbl();
  void updateHarvestRatingLbl();
  void updateFertilisationRatingLbl();
  void updateIrrigationRatingLbl();
  void updateSeedDensityRatingLbl();
  void updateYieldRatingLbl();
  void updateTillageRatingLbl();
  void updateManagementLabels();

  // phenology
  void updatePhenologyEmergenceRatingLbl();
  void updatePhenologyStemElongationRatingLbl();
  void updatePhenologyEarEmergenceRatingLbl();
  void updatePhenologyFloweringRatingLbl();
  void updatePhenologyYellowRipenessRatingLbl();
  void updatePhenologyLabels();

  // previous crop
  void updatePrevCropCropRatingLbl();
  void updatePrevCropSowingDateRatingLbl();
  void updatePrevCropHarvestDateRatingLbl();
  void updatePrevCropYieldRatingLbl();
  void updatePrevCropResidueMgmtRatingLbl();
  void updatePrevCropFertilisationRatingLbl();
  void updatePrevCropIrrigationRatingLbl();
  void updatePrevCropLabels();

  // initial values
  void updateInitialValuesSoilMoistureRatingLbl();
  void updateInitialValuesNMinRatingLbl();
  void updateInitialValuesLabels();

  // soil
  void updateSoilCOrgRatingLbl();
  void updateSoilNOrgRatingLbl();
  void updateSoilTextureRatingLbl();
  void updateSoilBulkDensityRatingLbl();
  void updateSoilFieldCapacityRatingLbl();
  void updateSoilWiltingPointRatingLbl();
  void updateSoilPfCurveRatingLbl();
  void updateSoilHydrCondCurveRatingLbl();
  void updateSoilPhRatingLbl();
  void updateSoilLabels();

  // site
  void updateSiteLatitudeRatingLbl();
  void updateSiteLongitudeRatingLbl();
  void updateSiteAltitudeRatingLbl();
  void updateSiteLabels();

  // weather
  void updateWeatherPrecipitationRatingLbl();
  void updateWeatherTAveRatingLbl();
  void updateWeatherTMinRatingLbl();
  void updateWeatherTMaxRatingLbl();
  void updateWeatherRelHumidityRatingLbl();
  void updateWeatherWindSpeedRatingLbl();
  void updateWeatherGlobalRadiationRatingLbl();
  void updateWeatherSunshineHoursRatingLbl();
  void updateWeatherLeafWetnessRatingLbl();
  void updateWeatherSoilTempRatingLbl();
  void updateWeatherLabels();

  // state vars
  // SV crop
  void updateSVCropAGrBiomassRatingLbl();
  void updateSVCropWeightOrgansRatingLbl();
  void updateSVCropRootBiomassRatingLbl();
  void updateSVCropNInAGrBiomassRatingLbl();
  void updateSVCropNInOrgansRatingLbl();
  void updateSVCropLAIRatingLbl();
  void updateSVCropLabels();

  // SV soil
  void updateSVSoilSoilWaterGravRatingLbl();
  void updateSVSoilPressureHeadsRatingLbl();
  void updateSVSoilNMinRatingLbl();
  void updateSVSoilSoilWaterSensorCalRatingLbl();
  void updateSVSoilWaterFluxBottomRootRatingLbl();
  void updateSVSoilNFluxBottomRootRatingLbl();
  void updateSVSoilLabels();

  // SV surface fluxes
  void updateSVSurfaceFluxesEtRatingLbl();
  void updateSVSurfaceFluxesNh3LossRatingLbl();
  void updateSVSurfaceFluxesN2OLossRatingLbl();
  void updateSVSurfaceFluxesN2LossRatingLbl();
  void updateSVSurfaceFluxesCh4LossRatingLbl();
  void updateSVSurfaceFluxesLabels();

  // SV observations
  void updateSVObservationsLodgingRatingLbl();
  void updateSVObservationsPestsOrDiseasesRatingLbl();
  void updateSVObservationsDamagesRatingLbl();
  void updateSVObservationsLabels();


     //----------//
    //  others  //
   //----------//
  QString makeString(double theValue);
  void on_pbSave_clicked();
  void on_leDatasetName_textChanged(const QString &theText);

};

#endif // MADDATACLASSIFICATION_H
