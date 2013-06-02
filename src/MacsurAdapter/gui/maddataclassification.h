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

     //-------------------------------------//
    //  link sliders and calculate points  //
   //-------------------------------------//
  // cultivation
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
  void on_hsldrFertilisationPrevCrop_valueChanged(int theValue);
  void on_hsldrIrrigationPrevCrop_valueChanged(int theValue);

  void on_dsbCropPrevCrop_valueChanged(double theSliderValue);
  void on_dsbSowingDatePrevCrop_valueChanged(double theSliderValue);
  void on_dsbHarvestDatePrevCrop_valueChanged(double theSliderValue);
  void on_dsbYieldPrevCrop_valueChanged(double theSliderValue);
  void on_dsbResidueMgmtPrevCrop_valueChanged(double theSliderValue);
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
  void on_hsldrRelativeHumidityWeather_valueChanged(int theSliderValue);
  void on_hsldrWindSpeedWeather_valueChanged(int theSliderValue);
  void on_hsldrGlobalRadiationWeather_valueChanged(int theSliderValue);
  void on_hsldrSunshineHoursWeather_valueChanged(int theSliderValue);
  void on_hsldrLeafWetnessWeather_valueChanged(int theSliderValue);
  void on_hsldrSoilTempWeather_valueChanged(int theSliderValue);

  void on_dsbPrecipitationWeather_valueChanged(double theValue);
  void on_dsbTAveWeather_valueChanged(double theValue);
  void on_dsbTMinWeather_valueChanged(double theValue);
  void on_dsbTMaxWeather_valueChanged(double theValue);
  void on_dsbRelativeHumidityWeather_valueChanged(double theValue);
  void on_dsbWindSpeedWeather_valueChanged(double theValue);
  void on_dsbGlobalRadiationWeather_valueChanged(double theValue);
  void on_dsbSunshineHoursWeather_valueChanged(double theValue);
  void on_dsbLeafWetnessWeather_valueChanged(int theSliderValue);
  void on_dsbSoilTempWeather_valueChanged(int theSliderValue);

  // state vars (calculate points only - no sliders on form for SV)
  // SV Crop
  void  on_gbxSVCrop_clicked();
  void on_cbExamplesSVCrop_currentIndexChanged(const QString &theValue);

  void on_sbSVCropAGrBiomassLayers_valueChanged(int theValue);
  void on_sbSVCropAGrBiomassObservations_valueChanged(int theValue);
  void on_sbSVCropAGrBiomassWeightPts_valueChanged(int theValue);
  void on_dsbSVCropAGrBiomassReplicates_valueChanged(double theValue);

  void on_sbSVCropWeightOrgansLayers_valueChanged(int theValue);
  void on_sbSVCropWeightOrgansObservations_valueChanged(int theValue);
  void on_sbSVCropWeightOrgansWeightPts_valueChanged(int theValue);
  void on_dsbSVCropWeightOrgansReplicates_valueChanged(double theValue);

  void on_sbSVCropRootBioMassLayers_valueChanged(int theValue);
  void on_sbSVCropRootBioMassObservations_valueChanged(int theValue);
  void on_sbSVCropRootBioMassWeightPts_valueChanged(int theValue);
  void on_dsbSVCropRootBioMassReplicates_valueChanged(double theValue);

  void on_sbSVCropNInAGrBioMassLayers_valueChanged(int theValue);
  void on_sbSVCropNInAGrBioMassObservations_valueChanged(int theValue);
  void on_sbSVCropNInAGrBioMassWeightPts_valueChanged(int theValue);
  void on_dsbSVCropNInAGrBioMassReplicates_valueChanged(double theValue);

  void on_sbSVCropNInOrgansLayers_valueChanged(int theValue);
  void on_sbSVCropNInOrgansObservations_valueChanged(int theValue);
  void on_sbSVCropNInOrgansWeightPts_valueChanged(int theValue);
  void on_dsbSVCropNInOrgansReplicates_valueChanged(double theValue);

  void on_sbSVCropLAILayers_valueChanged(int theValue);
  void on_sbSVCropLAIObservations_valueChanged(int theValue);
  void on_sbSVCropLAIWeightPts_valueChanged(int theValue);
  void on_dsbSVCropLAIReplicates_valueChanged(double theValue);

  // SV Soil
  void  on_gbxSVSoil_clicked();
  void on_cbExamplesSVSoil_currentIndexChanged(const QString &theValue);

  void on_sbSVSoilSoilWaterGravLayers_valueChanged(int theValue);
  void on_sbSVSoilSoilWaterGravObservations_valueChanged(int theValue);
  void on_sbSVSoilSoilWaterGravWeightPts_valueChanged(int theValue);
  void on_dsbSVSoilSoilWaterGravReplicates_valueChanged(double theValue);

  void on_sbSVSoilPressureHeadsLayers_valueChanged(int theValue);
  void on_sbSVSoilPressureHeadsObservations_valueChanged(int theValue);
  void on_sbSVSoilPressureHeadsWeightPts_valueChanged(int theValue);
  void on_dsbSVSoilPressureHeadsReplicates_valueChanged(double theValue);

  void on_sbSVSoilNMinLayers_valueChanged(int theValue);
  void on_sbSVSoilNMinObservations_valueChanged(int theValue);
  void on_sbSVSoilNMinWeightPts_valueChanged(int theValue);
  void on_dsbSVSoilNMinReplicates_valueChanged(double theValue);

  void on_sbSVSoilSoilWaterSensorCalLayers_valueChanged(int theValue);
  void on_sbSVSoilSoilWaterSensorCalObservations_valueChanged(int theValue);
  void on_sbSVSoilSoilWaterSensorCalWeightPts_valueChanged(int theValue);
  void on_dsbSVSoilSoilWaterSensorCalReplicates_valueChanged(double theValue);

  void on_sbSVSoilWaterFluxBottomRootLayers_valueChanged(int theValue);
  void on_sbSVSoilWaterFluxBottomRootObservations_valueChanged(int theValue);
  void on_sbSVSoilWaterFluxBottomRootWeightPts_valueChanged(int theValue);
  void on_dsbSVSoilWaterFluxBottomRootReplicates_valueChanged(double theValue);

  void on_sbSVSoilNFluxBottomRootLayers_valueChanged(int theValue);
  void on_sbSVSoilNFluxBottomRootObservations_valueChanged(int theValue);
  void on_sbSVSoilNFluxBottomRootWeightPts_valueChanged(int theValue);
  void on_dsbSVSoilNFluxBottomRootReplicates_valueChanged(double theValue);

  // SV surface fluxes
  void  on_gbxSVSurfaceFluxes_clicked();
  void on_cbExamplesSVSurfaceFluxes_currentIndexChanged(const QString &theValue);

  void on_sbSVSurfaceFluxesEtLayers_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesEtObservations_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesEtWeightPts_valueChanged(int theValue);
  void on_dsbSVSurfaceFluxesEtReplicates_valueChanged(double theValue);

  void on_sbSVSurfaceFluxesNh3LossLayers_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesNh3LossObservations_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesNh3LossWeightPts_valueChanged(int theValue);
  void on_dsbSVSurfaceFluxesNh3LossReplicates_valueChanged(double theValue);

  void on_sbSVSurfaceFluxesN2OLossLayers_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesN2OLossObservations_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesN2OLossWeightPts_valueChanged(int theValue);
  void on_dsbSVSurfaceFluxesN2OLossReplicates_valueChanged(double theValue);

  void on_sbSVSurfaceFluxesN2LossLayers_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesN2LossObservations_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesN2LossWeightPts_valueChanged(int theValue);
  void on_dsbSVSurfaceFluxesN2LossReplicates_valueChanged(double theValue);

  void on_sbSVSurfaceFluxesCh4LossLayers_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesCh4LossObservations_valueChanged(int theValue);
  void on_sbSVSurfaceFluxesCh4LossWeightPts_valueChanged(int theValue);
  void on_dsbSVSurfaceFluxesCh4LossReplicates_valueChanged(double theValue);

  // SV observations
  void  on_gbxSVObservations_clicked();
  void on_cbExamplesSVObservations_currentIndexChanged(const QString &theValue);

  void on_sbSVObservationsLodgingLayers_valueChanged(int theValue);
  void on_sbSVObservationsLodgingObservations_valueChanged(int theValue);
  void on_sbSVObservationsLodgingWeightPts_valueChanged(int theValue);
  void on_dsbSVObservationsLodgingReplicates_valueChanged(double theValue);

  void on_sbSVObservationsPestsOrDiseasesLayers_valueChanged(int theValue);
  void on_sbSVObservationsPestsOrDiseasesObservations_valueChanged(int theValue);
  void on_sbSVObservationsPestsOrDiseasesWeightPts_valueChanged(int theValue);
  void on_dsbSVObservationsPestsOrDiseasesReplicates_valueChanged(double theValue);

  void on_sbSVObservationsDamagesLayers_valueChanged(int theValue);
  void on_sbSVObservationsDamagesObservations_valueChanged(int theValue);
  void on_sbSVObservationsDamagesWeightPts_valueChanged(int theValue);
  void on_dsbSVObservationsDamagesReplicates_valueChanged(double theValue);


     //----------------//
    // update labels  //
   //----------------//
  // cultivation
  void updateVarietyRatingLbl();
  void updateSowingRatingLbl();
  void updateHarvestRatingLbl();
  void updateFertilisationRatingLbl();
  void updateIrrigationRatingLbl();
  void updateSeedDensityRatingLbl();
  void updateYieldRatingLbl();
  void updateTillageRatingLbl();
  void updateCultivationLabels();

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

  // initial values
  void updateInitialValuesSoilMoistureRatingLbl();
  void updateInitialValuesNMinRatingLbl();

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

  // site
  void updateSiteLatitudeRatingLbl();
  void updateSiteLongitudeRatingLbl();
  void updateSiteAltitudeRatingLbl();

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

  // state vars
  // SV crop
  void updateSVCropAGrBiomassRatingLbl();
  void updateSVCropWeightOrgansRatingLbl();
  void updateSVCropRootBioMassRatingLbl();
  void updateSVCropNInAGrBioMassRatingLbl();
  void updateSVCropNInOrgansRatingLbl();
  void updateSVCropLAIRatingLbl();
  // SV soil
  void updateSVSoilSoilWaterGravRatingLbl();
  void updateSVSoilPressureHeadsRatingLbl();
  void updateSVSoilNMinRatingLbl();
  void updateSVSoilSoilWaterSensorCalRatingLbl();
  void updateSVSoilWaterFluxBottomRootRatingLbl();
  void updateSVSoilNFluxBottomRootRatingLbl();

  // SV surface fluxes
  void updateSVSurfaceFluxesEtRatingLbl();
  void updateSVSurfaceFluxesNh3LossRatingLbl();
  void updateSVSurfaceFluxesN2OLossRatingLbl();
  void updateSVSurfaceFluxesN2LossRatingLbl();
  void updateSVSurfaceFluxesCh4LossRatingLbl();

  // SV observations
  void updateSVObservationsLodgingRatingLbl();
  void updateSVObservationsPestsOrDiseasesRatingLbl();
  void updateSVObservationsDamagesRatingLbl();


     //----------//
    //  others  //
   //----------//
  QString makeString(double theValue);
  void on_pbSave_clicked();
  void on_leDatasetName_textChanged(const QString &theText);

};

#endif // MADDATACLASSIFICATION_H
