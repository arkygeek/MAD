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
  lblMedalCultivation->setVisible(false);
  lblRankingCultivation->setVisible(false);
  lblExample->setVisible(true);
  cbExamples->setDisabled(false);

  gbxPhenology->setChecked(false);
  cbExamplesPhenology->setEnabled(true);
  lblExamplePhenology->setVisible(true);
  lblExamplePhenology->setText("Select Example");
  lblMedalPhenology->setVisible(false);
  lblRankingPhenology->setVisible(false);
  lblExamplePhenology->setVisible(true);
  cbExamplesPhenology->setDisabled(false);

  // These must stay here at the end

  // cultivation connections
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

  // phenology connections
  connect ( sbEmergencePhenology, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePhenologyEmergenceRatingLbl() ));
  connect ( dsbEmergencePhenology, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePhenologyEmergenceRatingLbl() ));
  connect ( sbStemElongationPhenology, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePhenologyStemElongationRatingLbl() ));
  connect ( dsbStemElongationPhenology, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePhenologyStemElongationRatingLbl() ));
  connect ( sbEarEmergencePhenology, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePhenologyEarEmergenceRatingLbl() ));
  connect ( dsbEarEmergencePhenology, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePhenologyEarEmergenceRatingLbl() ));
  connect ( sbFloweringPhenology, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePhenologyFloweringRatingLbl() ));
  connect ( dsbFloweringPhenology, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePhenologyFloweringRatingLbl() ));
  connect ( sbYellowRipenessPhenology, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePhenologyYellowRipenessRatingLbl() ));
  connect ( dsbYellowRipenessPhenology, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePhenologyYellowRipenessRatingLbl() ));

  // prev crop connections
  connect ( sbCropPrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropCropRatingLbl() ));
  connect ( dsbCropPrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropCropRatingLbl() ));
  connect ( sbSowingDatePrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropSowingDateRatingLbl() ));
  connect ( dsbSowingDatePrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropSowingDateRatingLbl() ));
  connect ( sbHarvestDatePrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropHarvestDateRatingLbl() ));
  connect ( dsbHarvestDatePrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropHarvestDateRatingLbl() ));
  connect ( sbYieldPrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropYieldRatingLbl() ));
  connect ( dsbYieldPrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropYieldRatingLbl() ));
  connect ( sbResidueMgmtPrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropResidueMgmtRatingLbl() ));
  connect ( dsbResidueMgmtPrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropResidueMgmtRatingLbl() ));
  connect ( sbFertilisationPrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropFertilisationRatingLbl() ));
  connect ( dsbFertilisationPrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropFertilisationRatingLbl() ));
  connect ( sbIrrigationPrevCrop, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updatePrevCropIrrigationRatingLbl() ));
  connect ( dsbIrrigationPrevCrop, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updatePrevCropIrrigationRatingLbl() ));

  // initial values connections
  connect ( sbSoilMoistureInitialValues, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateInitialValuesSoilMoistureRatingLbl() ));
  connect ( dsbSoilMoistureInitialValues, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateInitialValuesSoilMoistureRatingLbl() ));
  connect ( sbNMinInitialValues, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateInitialValuesNMinRatingLbl() ));
  connect ( dsbNMinInitialValues, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateInitialValuesNMinRatingLbl() ));

  // soil connections
  connect ( sbCOrgSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilCOrgRatingLbl() ));
  connect ( dsbCOrgSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilCOrgRatingLbl() ));
  connect ( sbNOrgSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilNOrgRatingLbl() ));
  connect ( dsbNOrgSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilNOrgRatingLbl() ));
  connect ( sbTextureSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilTextureRatingLbl() ));
  connect ( dsbTextureSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilTextureRatingLbl() ));
  connect ( sbBulkDensitySoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilBulkDensityRatingLbl() ));
  connect ( dsbBulkDensitySoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilBulkDensityRatingLbl() ));
  connect ( sbFieldCapacitySoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilFieldCapacityRatingLbl() ));
  connect ( dsbFieldCapacitySoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilFieldCapacityRatingLbl() ));
  connect ( sbWiltingPointSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilWiltingPointRatingLbl() ));
  connect ( dsbWiltingPointSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilWiltingPointRatingLbl() ));
  connect ( sbPfCurveSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilPfCurveRatingLbl() ));
  connect ( dsbPfCurveSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilPfCurveRatingLbl() ));
  connect ( sbHydrCondCurveSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilHydrCondCurveRatingLbl() ));
  connect ( dsbHydrCondCurveSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilHydrCondCurveRatingLbl() ));
  connect ( sbPhSoil, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSoilPhRatingLbl() ));
  connect ( dsbPhSoil, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSoilPhRatingLbl() ));

  // site data connections
  connect ( sbLatitudeSite, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSiteLatitudeRatingLbl() ));
  connect ( dsbLatitudeSite, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSiteLatitudeRatingLbl() ));
  connect ( sbLongitudeSite, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSiteLongitudeRatingLbl() ));
  connect ( dsbLongitudeSite, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSiteLongitudeRatingLbl() ));
  connect ( sbAltitudeSite, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSiteAltitudeRatingLbl() ));
  connect ( dsbAltitudeSite, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSiteAltitudeRatingLbl() ));

  // weather connections
  connect ( sbPrecipitationWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherPrecipitationRatingLbl() ));
  connect ( dsbPrecipitationWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherPrecipitationRatingLbl() ));
  connect ( sbTAveWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherTAveRatingLbl() ));
  connect ( dsbTAveWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherTAveRatingLbl() ));
  connect ( sbTMinWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherTMinRatingLbl() ));
  connect ( dsbTMinWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherTMinRatingLbl() ));
  connect ( sbTMaxWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherTMaxRatingLbl() ));
  connect ( dsbTMaxWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherTMaxRatingLbl() ));
  connect ( sbRelHumidityWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherRelHumidityRatingLbl() ));
  connect ( dsbRelHumidityWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherRelHumidityRatingLbl() ));
  connect ( sbWindSpeedWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherWindSpeedRatingLbl() ));
  connect ( dsbWindSpeedWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherWindSpeedRatingLbl() ));
  connect ( sbGlobalRadiationWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherGlobalRadiationRatingLbl() ));
  connect ( dsbGlobalRadiationWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherGlobalRadiationRatingLbl() ));
  connect ( sbSunshineHoursWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherSunshineHoursRatingLbl() ));
  connect ( dsbSunshineHoursWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherSunshineHoursRatingLbl() ));
  connect ( sbLeafWetnessWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherLeafWetnessRatingLbl() ));
  connect ( dsbLeafWetnessWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherLeafWetnessRatingLbl() ));
  connect ( sbSoilTempWeather, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateWeatherSoilTempRatingLbl() ));
  connect ( dsbSoilTempWeather, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateWeatherSoilTempRatingLbl() ));

  // state vars connections
  //crop
  connect ( sbSVCropAGrBiomassLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));
  connect ( sbSVCropAGrBiomassObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));
  connect ( sbSVCropAGrBiomassWeight, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));
  connect ( dsbSVCropAGrBiomassReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));

  connect ( sbSVCropWeightOrgansLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));
  connect ( sbSVCropWeightOrgansObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));
  connect ( sbSVCropWeightOrgansWeight, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));
  connect ( dsbSVCropWeightOrgansReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));

  connect ( sbSVCropRootBioMassLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropRootBioMassRatingLbl() ));
  connect ( sbSVCropRootBioMassObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropRootBioMassRatingLbl() ));
  connect ( sbSVCropRootBioMassWeight, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropRootBioMassRatingLbl() ));
  connect ( dsbSVCropRootBioMassReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropRootBioMassRatingLbl() ));

  connect ( sbSVCropNInAGrBioMassLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInAGrBioMassRatingLbl() ));
  connect ( sbSVCropNInAGrBioMassObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInAGrBioMassRatingLbl() ));
  connect ( sbSVCropNInAGrBioMassWeight, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInAGrBioMassRatingLbl() ));
  connect ( dsbSVCropNInAGrBioMassReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInAGrBioMassRatingLbl() ));

  connect ( sbSVCropNInOrgansLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));
  connect ( sbSVCropNInOrgansObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));
  connect ( sbSVCropNInOrgansWeight, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));
  connect ( dsbSVCropNInOrgansReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));

  connect ( sbSVCropLAILayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));
  connect ( sbSVCropLAIObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));
  connect ( sbSVCropLAIWeight, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));
  connect ( dsbSVCropLAIReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));

  // soil
  connect ( sbSVSoilSoilWaterSensorCalLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( sbSVSoilSoilWaterSensorCalObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( sbSVSoilSoilWaterSensorCalWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( dsbSVSoilSoilWaterSensorCalReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));

  connect ( sbSVSoilPressureHeadsLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));
  connect ( sbSVSoilPressureHeadsObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));
  connect ( sbSVSoilPressureHeadsWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));
  connect ( dsbSVSoilPressureHeadsReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));

  connect ( sbSVSoilNMinLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));
  connect ( sbSVSoilNMinObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));
  connect ( sbSVSoilNMinWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));
  connect ( dsbSVSoilNMinReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));

  connect ( sbSVSoilSoilWaterSensorCalLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( sbSVSoilSoilWaterSensorCalObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( sbSVSoilSoilWaterSensorCalWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( dsbSVSoilSoilWaterSensorCalReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));

  connect ( sbSVSoilWaterFluxBottomRootLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));
  connect ( sbSVSoilWaterFluxBottomRootObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));
  connect ( sbSVSoilWaterFluxBottomRootWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));
  connect ( dsbSVSoilWaterFluxBottomRootReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));

  connect ( sbSVSoilNFluxBottomRootLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));
  connect ( sbSVSoilNFluxBottomRootObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));
  connect ( sbSVSoilNFluxBottomRootWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));
  connect ( dsbSVSoilNFluxBottomRootReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));

  // surface fluxes
  connect ( sbSVSurfaceFluxesEtLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));
  connect ( sbSVSurfaceFluxesEtObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));
  connect ( sbSVSurfaceFluxesEtWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));
  connect ( dsbSVSurfaceFluxesEtReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));

  connect ( sbSVSurfaceFluxesNh3LossLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesNh3LossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesNh3LossWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesNh3LossReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));

  connect ( sbSVSurfaceFluxesN2OLossLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));
  connect ( sbSVSurfaceFluxesN2OLossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));
  connect ( sbSVSurfaceFluxesN2OLossWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesN2OLossReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));

  connect ( sbSVSurfaceFluxesN2LossLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesN2LossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesN2LossWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesN2LossReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));

  connect ( sbSVSurfaceFluxesCh4LossLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesCh4LossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesCh4LossWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesCh4LossReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));

  // observations
  connect ( sbSVObservationsLodgingLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));
  connect ( sbSVObservationsLodgingObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));
  connect ( sbSVObservationsLodgingWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));
  connect ( dsbSVObservationsLodgingReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));

  connect ( sbSVObservationsPestsOrDiseasesLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));
  connect ( sbSVObservationsPestsOrDiseasesObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));
  connect ( sbSVObservationsPestsOrDiseasesWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));
  connect ( dsbSVObservationsPestsOrDiseasesReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));

  connect ( sbSVObservationsDamagesLayers, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
  connect ( sbSVObservationsDamagesObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
  connect ( sbSVObservationsLodgingWeightPts, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
  connect ( dsbSVObservationsLodgingReplicates, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
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
void MadDataClassification::on_leDatasetName_textChanged(const QString &theText)
{
    if (theText != "")
    {
      pbSave->setEnabled(true);
    }
    else
    {
      pbSave->setEnabled(false);
    };
}
QString MadDataClassification::makeString(double theValue)
{
  QString myString = QString::number(theValue);
  return myString;
}

   //----------------------------------------//
  //  group box edit and examples combobox  //
 //----------------------------------------//
// cultivation tab (group box edit and examples combobox)
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
  }
}

// phenology tab (group box edit and examples combobox)
void MadDataClassification::on_gbxPhenology_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxPhenology->isChecked())
  {
    lblExamplePhenology->setVisible(false);
    cbExamplesPhenology->setDisabled(true);
  }
  else
  {
    cbExamplesPhenology->setEnabled(true);
    lblExamplePhenology->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesPhenology_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesPhenology->currentText()!="Examples")
  {
    lblExamplePhenology->setText(theValue);
  }
  else
  {
    lblExamplePhenology->setText("Select Example");
  }
}

// prev crop tab (group box edit and examples combobox)
void MadDataClassification::on_gbxPrevCrop_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxPrevCrop->isChecked())
  {
    lblExamplePrevCrop->setVisible(false);
    cbExamplesPrevCrop->setDisabled(true);
  }
  else
  {
    cbExamplesPrevCrop->setEnabled(true);
    lblExamplePrevCrop->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesPrevCrop_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesPrevCrop->currentText()!="Examples")
  {
    lblExamplePrevCrop->setText(theValue);
  }
  else
  {
    lblExamplePrevCrop->setText("Select Example");
  }
}

// initial values tab (group box edit and examples combobox)
void MadDataClassification::on_gbxInitialValues_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxInitialValues->isChecked())
  {
    lblExampleInitialValues->setVisible(false);
    cbExamplesInitialValues->setDisabled(true);
  }
  else
  {
    cbExamplesInitialValues->setEnabled(true);
    lblExampleInitialValues->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesInitialValues_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesInitialValues->currentText()!="Examples")
  {
    lblExampleInitialValues->setText(theValue);
  }
  else
  {
    lblExampleInitialValues->setText("Select Example");
  }
}

// soil tab (group box edit and examples combobox)
void MadDataClassification::on_gbxSoil_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxSoil->isChecked())
  {
    lblExampleSoil->setVisible(false);
    cbExamplesSoil->setDisabled(true);
  }
  else
  {
    cbExamplesSoil->setEnabled(true);
    lblExampleSoil->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesSoil_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesSoil->currentText()!="Examples")
  {
    lblExampleSoil->setText(theValue);
  }
  else
  {
    lblExampleSoil->setText("Select Example");
  }
}

// site tab (group box edit and examples combobox)
void MadDataClassification::on_gbxSite_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxSite->isChecked())
  {
    lblExampleSite->setVisible(false);
    cbExamplesSite->setDisabled(true);
  }
  else
  {
    cbExamplesSite->setEnabled(true);
    lblExampleSite->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesSite_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesSite->currentText()!="Examples")
  {
    lblExampleSite->setText(theValue);
  }
  else
  {
    lblExampleSite->setText("Select Example");
  }
}

// weather tab (group box edit and examples combobox)
void MadDataClassification::on_gbxWeather_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxWeather->isChecked())
  {
    lblExampleWeather->setVisible(false);
    cbExamplesWeather->setDisabled(true);
  }
  else
  {
    cbExamplesWeather->setEnabled(true);
    lblExampleWeather->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesWeather_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesWeather->currentText()!="Examples")
  {
    lblExampleWeather->setText(theValue);
  }
  else
  {
    lblExampleWeather->setText("Select Example");
  }
}

// SV crop tab (group box edit and examples combobox)
void MadDataClassification::on_gbxSVCrop_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxSVCrop->isChecked())
  {
    lblExampleSVCrop->setVisible(false);
    cbExamplesSVCrop->setDisabled(true);
  }
  else
  {
    cbExamplesSVCrop->setEnabled(true);
    lblExampleSVCrop->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesSVCrop_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesSVCrop->currentText()!="Examples")
  {
    lblExampleSVCrop->setText(theValue);
  }
  else
  {
    lblExampleSVCrop->setText("Select Example");
  }
}

// SV soil tab (group box edit and examples combobox)
void MadDataClassification::on_gbxSVSoil_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxSVSoil->isChecked())
  {
    lblExampleSVSoil->setVisible(false);
    cbExamplesSVSoil->setDisabled(true);
  }
  else
  {
    cbExamplesSVSoil->setEnabled(true);
    lblExampleSVSoil->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesSVSoil_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesSVSoil->currentText()!="Examples")
  {
    lblExampleSVSoil->setText(theValue);
  }
  else
  {
    lblExampleSVSoil->setText("Select Example");
  }
}

// SV surface fluxes tab (group box edit and examples combobox)
void MadDataClassification::on_gbxSVSurfaceFluxes_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxSVSurfaceFluxes->isChecked())
  {
    lblExampleSVSurfaceFluxes->setVisible(false);
    cbExamplesSVSurfaceFluxes->setDisabled(true);
  }
  else
  {
    cbExamplesSVSurfaceFluxes->setEnabled(true);
    lblExampleSVSurfaceFluxes->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesSVSurfaceFluxes_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesSVSurfaceFluxes->currentText()!="Examples")
  {
    lblExampleSVSurfaceFluxes->setText(theValue);
  }
  else
  {
    lblExampleSVSurfaceFluxes->setText("Select Example");
  }
}

// SV observations tab (group box edit and examples combobox)
void MadDataClassification::on_gbxSVObservations_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings

  if (gbxSVObservations->isChecked())
  {
    lblExampleSVObservations->setVisible(false);
    cbExamplesSVObservations->setDisabled(true);
  }
  else
  {
    cbExamplesSVObservations->setEnabled(true);
    lblExampleSVObservations->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesSVObservations_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamplesSVObservations->currentText()!="Examples")
  {
    lblExampleSVObservations->setText(theValue);
  }
  else
  {
    lblExampleSVObservations->setText("Select Example");
  }
}


   //----------------------------------//
  //  slider linking and point calcs  //
 //----------------------------------//
// cultivation (slider linking and point calcs)
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
void MadDataClassification::on_hsldrSowing_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbSowing->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrHarvest_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbHarvest->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrFertilisation_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbFertilisation->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrIrrigation_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbIrrigation->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrSeedDensity_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbSeedDensity->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrYield_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbYield->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrTillage_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbTillage->setValue(myPreciseValue);
}

// phenology (slider linking and point calcs)
void MadDataClassification::on_hsldrEmergencePhenology_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbEmergencePhenology->setValue(myPreciseValue);
  updatePhenologyEmergenceRatingLbl();
}
void MadDataClassification::on_hsldrEarEmergencePhenology_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbEarEmergencePhenology->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrStemElongationPhenology_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbStemElongationPhenology->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrFloweringPhenology_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbFloweringPhenology->setValue(myPreciseValue);
}
void MadDataClassification::on_hsldrYellowRipenessPhenology_valueChanged(int theSliderValue)
{
  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbYellowRipenessPhenology->setValue(myPreciseValue);
}

// prev crop tab (slider linking and point calcs)
void MadDataClassification::on_hsldrCropPrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbCropPrevCrop->setValue(myPreciseValue);
  updatePrevCropCropRatingLbl();
}
void MadDataClassification::on_hsldrSowingDatePrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbSowingDatePrevCrop->setValue(myPreciseValue);
  updatePrevCropSowingDateRatingLbl();
}
void MadDataClassification::on_hsldrHarvestDatePrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbHarvestDatePrevCrop->setValue(myPreciseValue);
  updatePrevCropHarvestDateRatingLbl();
}
void MadDataClassification::on_hsldrYieldPrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbYieldPrevCrop->setValue(myPreciseValue);
  updatePrevCropYieldRatingLbl();
}
void MadDataClassification::on_hsldrResidueMgmtPrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbResidueMgmtPrevCrop->setValue(myPreciseValue);
  updatePrevCropResidueMgmtRatingLbl();
}
void MadDataClassification::on_hsldrFertilisationPrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbFertilisationPrevCrop->setValue(myPreciseValue);
  updatePrevCropFertilisationRatingLbl();
}
void MadDataClassification::on_hsldrIrrigationPrevCrop_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbIrrigationPrevCrop->setValue(myPreciseValue);
  updatePrevCropIrrigationRatingLbl();
}

// initial values tab (slider linking and point calcs)
void MadDataClassification::on_hsldrSoilMoistureInitialValues_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbSoilMoistureInitialValues->setValue(myPreciseValue);
  updateInitialValuesSoilMoistureRatingLbl();
}
void MadDataClassification::on_hsldrNMinInitialValues_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbNMinInitialValues->setValue(myPreciseValue);
  updateInitialValuesNMinRatingLbl();
}

// soil tab (slider linking and point calcs)
void MadDataClassification::on_hsldrCOrgSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbCOrgSoil->setValue(myPreciseValue);
  updateSoilCOrgRatingLbl();
}
void MadDataClassification::on_hsldrNOrgSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbNOrgSoil->setValue(myPreciseValue);
  updateSoilNOrgRatingLbl();
}
void MadDataClassification::on_hsldrTextureSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbTextureSoil->setValue(myPreciseValue);
  updateSoilTextureRatingLbl();
}
void MadDataClassification::on_hsldrBulkDensitySoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbBulkDensitySoil->setValue(myPreciseValue);
  updateSoilBulkDensityRatingLbl();
}
void MadDataClassification::on_hsldrFieldCapacitySoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbFieldCapacitySoil->setValue(myPreciseValue);
  updateSoilFieldCapacityRatingLbl();
}
void MadDataClassification::on_hsldrWiltingPointSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbWiltingPointSoil->setValue(myPreciseValue);
  updateSoilWiltingPointRatingLbl();
}
void MadDataClassification::on_hsldrPfCurveSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbPfCurveSoil->setValue(myPreciseValue);
  updateSoilPfCurveRatingLbl();
}
void MadDataClassification::on_hsldrHydrCondCurveSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbHydrCondCurveSoil->setValue(myPreciseValue);
  updateSoilHydrCondCurveRatingLbl();
}
void MadDataClassification::on_hsldrPhSoil_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbPhSoil->setValue(myPreciseValue);
  updateSoilPhRatingLbl();
}

// site tab (slider linking and point calcs)
void MadDataClassification::on_hsldrLatitudeSite_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbLatitudeSite->setValue(myPreciseValue);
  updateSiteLatitudeRatingLbl();
}
void MadDataClassification::on_hsldrLongitudeSite_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbLongitudeSite->setValue(myPreciseValue);
  updateSiteLongitudeRatingLbl();
}
void MadDataClassification::on_hsldrAltitudeSite_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbAltitudeSite->setValue(myPreciseValue);
  updateSiteAltitudeRatingLbl();
}

// weather tab (slider linking and point calcs)
void MadDataClassification::on_hsldrPrecipitationWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbPrecipitationWeather->setValue(myPreciseValue);
  updateWeatherPrecipitationRatingLbl();
}
void MadDataClassification::on_hsldrTAveWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbTAveWeather->setValue(myPreciseValue);
  updateWeatherTAveRatingLbl();
}
void MadDataClassification::on_hsldrTMinWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbTMinWeather->setValue(myPreciseValue);
  updateWeatherTMinRatingLbl();
}
void MadDataClassification::on_hsldrTMaxWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbTMaxWeather->setValue(myPreciseValue);
  updateWeatherTMaxRatingLbl();
}
void MadDataClassification::on_hsldrRelativeHumidityWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbRelHumidityWeather->setValue(myPreciseValue);
  updateWeatherRelHumidityRatingLbl();
}
void MadDataClassification::on_hsldrWindSpeedWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbWindSpeedWeather->setValue(myPreciseValue);
  updateWeatherWindSpeedRatingLbl();
}
void MadDataClassification::on_hsldrGlobalRadiationWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbGlobalRadiationWeather->setValue(myPreciseValue);
  updateWeatherGlobalRadiationRatingLbl();
}
void MadDataClassification::on_hsldrSunshineHoursWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbSunshineHoursWeather->setValue(myPreciseValue);
  updateWeatherSunshineHoursRatingLbl();
}
void MadDataClassification::on_hsldrLeafWetnessWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbLeafWetnessWeather->setValue(myPreciseValue);
  updateWeatherLeafWetnessRatingLbl();
}
void MadDataClassification::on_hsldrSoilTempWeather_valueChanged(int theSliderValue)
{
  // update label according to desired resolution
  // hardcoded for now at a range of 1 to 5
  // slider goes from 0 to 1000

  int myValue = (theSliderValue/100);
  float myPreciseValue = myValue/2.0;
  dsbSoilTempWeather->setValue(myPreciseValue);
  updateWeatherSoilTempRatingLbl();
}



   //---------------------------//
  //  double spin box changes  //
 //---------------------------//
// cultivation (double spin box changes)
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

// phenology (double spin box changes)
void MadDataClassification::on_dsbEmergencePhenology_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrEmergencePhenology->setSliderPosition(myPosition);
  float myResult = dsbEmergencePhenology->value() * sbEmergencePhenology->value();
  lblEmergenceRatingPhenology->setText(makeString(myResult));
}
void MadDataClassification::on_dsbStemElongationPhenology_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrStemElongationPhenology->setSliderPosition(myPosition);
  float myResult = dsbStemElongationPhenology->value() * sbStemElongationPhenology->value();
  lblStemElongationRatingPhenology->setText(makeString(myResult));
}
void MadDataClassification::on_dsbEarEmergencePhenology_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrEarEmergencePhenology->setSliderPosition(myPosition);
  float myResult = dsbEarEmergencePhenology->value() * sbEarEmergencePhenology->value();
  lblEarEmergenceRatingPhenology->setText(makeString(myResult));
}
void MadDataClassification::on_dsbFloweringPhenology_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrFloweringPhenology->setSliderPosition(myPosition);
  float myResult = dsbFloweringPhenology->value() * sbFloweringPhenology->value();
  lblFloweringRatingPhenology->setText(makeString(myResult));
}
void MadDataClassification::on_dsbYellowRipenessPhenology_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrYellowRipenessPhenology->setSliderPosition(myPosition);
  float myResult = dsbYellowRipenessPhenology->value() * sbYellowRipenessPhenology->value();
  lblYellowRipenessRatingPhenology->setText(makeString(myResult));
}

// prev crop tab (double spin box changes)
void MadDataClassification::on_dsbCropPrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrCropPrevCrop->setSliderPosition(myPosition);
  float myResult = dsbCropPrevCrop->value() * sbCropPrevCrop->value();
  lblCropRatingPrevCrop->setText(makeString(myResult));
}
void MadDataClassification::on_dsbSowingDatePrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrSowingDatePrevCrop->setSliderPosition(myPosition);
  float myResult = dsbSowingDatePrevCrop->value() * sbSowingDatePrevCrop->value();
  lblSowingDateRatingPrevCrop->setText(makeString(myResult));
}
void MadDataClassification::on_dsbHarvestDatePrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrHarvestDatePrevCrop->setSliderPosition(myPosition);
  float myResult = dsbHarvestDatePrevCrop->value() * sbHarvestDatePrevCrop->value();
  lblHarvestDateRatingPrevCrop->setText(makeString(myResult));
}
void MadDataClassification::on_dsbYieldPrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrYieldPrevCrop->setSliderPosition(myPosition);
  float myResult = dsbYieldPrevCrop->value() * sbYieldPrevCrop->value();
  lblYieldRatingPrevCrop->setText(makeString(myResult));
}
void MadDataClassification::on_dsbResidueMgmtPrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrResidueMgmtPrevCrop->setSliderPosition(myPosition);
  float myResult = dsbResidueMgmtPrevCrop->value() * sbResidueMgmtPrevCrop->value();
  lblResidueMgmtRatingPrevCrop->setText(makeString(myResult));
}
void MadDataClassification::on_dsbFertilisationPrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrFertilisationPrevCrop->setSliderPosition(myPosition);
  float myResult = dsbFertilisationPrevCrop->value() * sbFertilisationPrevCrop->value();
  lblFertilisationRatingPrevCrop->setText(makeString(myResult));
}
void MadDataClassification::on_dsbIrrigationPrevCrop_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrIrrigationPrevCrop->setSliderPosition(myPosition);
  float myResult = dsbIrrigationPrevCrop->value() * sbIrrigationPrevCrop->value();
  lblIrrigationRatingPrevCrop->setText(makeString(myResult));
}

// initial values tab (double spin box changes)
void MadDataClassification::on_dsbSoilMoistureInitialValues_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrSoilMoistureInitialValues->setSliderPosition(myPosition);
  float myResult = dsbSoilMoistureInitialValues->value() * sbSoilMoistureInitialValues->value();
  lblSoilMoistureRatingInitialValues->setText(makeString(myResult));
}
void MadDataClassification::on_dsbNMinInitialValues_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrNMinInitialValues->setSliderPosition(myPosition);
  float myResult = dsbNMinInitialValues->value() * sbNMinInitialValues->value();
  lblNMinRatingInitialValues->setText(makeString(myResult));
}

// soil tab (double spin box changes)
void MadDataClassification::on_dsbCOrgSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrCOrgSoil->setSliderPosition(myPosition);
  float myResult = dsbCOrgSoil->value() * sbCOrgSoil->value();
  lblCOrgRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbNOrgSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrNOrgSoil->setSliderPosition(myPosition);
  float myResult = dsbNOrgSoil->value() * sbNOrgSoil->value();
  lblNOrgRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbTextureSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrTextureSoil->setSliderPosition(myPosition);
  float myResult = dsbTextureSoil->value() * sbTextureSoil->value();
  lblTextureRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbBulkDensitySoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrBulkDensitySoil->setSliderPosition(myPosition);
  float myResult = dsbBulkDensitySoil->value() * sbBulkDensitySoil->value();
  lblBulkDensityRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbFieldCapacitySoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrFieldCapacitySoil->setSliderPosition(myPosition);
  float myResult = dsbFieldCapacitySoil->value() * sbFieldCapacitySoil->value();
  lblFieldCapacityRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbWiltingPointSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrWiltingPointSoil->setSliderPosition(myPosition);
  float myResult = dsbWiltingPointSoil->value() * sbWiltingPointSoil->value();
  lblWiltingPointRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbPfCurveSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrPfCurveSoil->setSliderPosition(myPosition);
  float myResult = dsbPfCurveSoil->value() * sbPfCurveSoil->value();
  lblPfCurveRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbHydrCondCurveSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrHydrCondCurveSoil->setSliderPosition(myPosition);
  float myResult = dsbHydrCondCurveSoil->value() * sbHydrCondCurveSoil->value();
  lblHydrCondCurveRatingSoil->setText(makeString(myResult));
}
void MadDataClassification::on_dsbPhSoil_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrPhSoil->setSliderPosition(myPosition);
  float myResult = dsbPhSoil->value() * sbPhSoil->value();
  lblPhRatingSoil->setText(makeString(myResult));
}

// site tab (double spin box changes)
void MadDataClassification::on_dsbLatitudeSite_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrLatitudeSite->setSliderPosition(myPosition);
  float myResult = dsbLatitudeSite->value() * sbLatitudeSite->value();
  lblLatitudeRatingSite->setText(makeString(myResult));
}
void MadDataClassification::on_dsbLongitudeSite_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrLongitudeSite->setSliderPosition(myPosition);
  float myResult = dsbLongitudeSite->value() * sbLongitudeSite->value();
  lblLongitudeRatingSite->setText(makeString(myResult));
}
void MadDataClassification::on_dsbAltitudeSite_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrAltitudeSite->setSliderPosition(myPosition);
  float myResult = dsbAltitudeSite->value() * sbAltitudeSite->value();
  lblAltitudeRatingSite->setText(makeString(myResult));
}

// weather tab (double spin box changes)
void MadDataClassification::on_dsbPrecipitationWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrPrecipitationWeather->setSliderPosition(myPosition);
  float myResult = dsbPrecipitationWeather->value() * sbPrecipitationWeather->value();
  lblPrecipitationRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbTAveWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrTAveWeather->setSliderPosition(myPosition);
  float myResult = dsbTAveWeather->value() * sbTAveWeather->value();
  lblTAveRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbTMinWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrTMinWeather->setSliderPosition(myPosition);
  float myResult = dsbTMinWeather->value() * sbTMinWeather->value();
  lblTMinRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbTMaxWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrTMaxWeather->setSliderPosition(myPosition);
  float myResult = dsbTMaxWeather->value() * sbTMaxWeather->value();
  lblTMaxRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbRelativeHumidityWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrRelHumidityWeather->setSliderPosition(myPosition);
  float myResult = dsbRelHumidityWeather->value() * sbRelHumidityWeather->value();
  lblRelHumidityRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbWindSpeedWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrWindSpeedWeather->setSliderPosition(myPosition);
  float myResult = dsbWindSpeedWeather->value() * sbWindSpeedWeather->value();
  lblWindSpeedRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbGlobalRadiationWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrGlobalRadiationWeather->setSliderPosition(myPosition);
  float myResult = dsbGlobalRadiationWeather->value() * sbGlobalRadiationWeather->value();
  lblGlobalRadiationRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbSunshineHoursWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrSunshineHoursWeather->setSliderPosition(myPosition);
  float myResult = dsbSunshineHoursWeather->value() * sbSunshineHoursWeather->value();
  lblSunshineHoursRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbLeafWetnessWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrLeafWetnessWeather->setSliderPosition(myPosition);
  float myResult = dsbLeafWetnessWeather->value() * sbLeafWetnessWeather->value();
  lblLeafWetnessRatingWeather->setText(makeString(myResult));
}
void MadDataClassification::on_dsbSoilTempWeather_valueChanged(double theValue)
{
  int myPosition;
  myPosition = theValue * 200;
  hsldrSoilTempWeather->setSliderPosition(myPosition);
  float myResult = dsbSoilTempWeather->value() * sbSoilTempWeather->value();
  lblSoilTempRatingWeather->setText(makeString(myResult));
}

// SV crop tab (spin box changes)
void MadDataClassification::on_sbSVCropAGrBiomassLayers_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}
void MadDataClassification::on_sbSVCropAGrBiomassObservations_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}
void MadDataClassification::on_sbSVCropAGrBiomassWeightPts_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropAGrBiomassReplicates_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}

void MadDataClassification::on_sbSVCropWeightOrgansLayers_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}
void MadDataClassification::on_sbSVCropWeightOrgansObservations_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}
void MadDataClassification::on_sbSVCropWeightOrgansWeightPts_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}
void MadDataClassification::on_dsbSVCropWeightOrgansReplicates_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}

void MadDataClassification::on_sbSVCropRootBioMassLayers_valueChanged()
{
  updateSVCropRootBioMassRatingLbl();
}
void MadDataClassification::on_sbSVCropRootBioMassObservations_valueChanged()
{
  updateSVCropRootBioMassRatingLbl();
}
void MadDataClassification::on_sbSVCropRootBioMassWeightPts_valueChanged()
{
  updateSVCropRootBioMassRatingLbl();
}
void MadDataClassification::on_dsbSVCropRootBioMassReplicates_valueChanged()
{
  updateSVCropRootBioMassRatingLbl();
}

void MadDataClassification::on_sbSVCropNInAGrBioMassLayers_valueChanged()
{
  updateSVCropNInAGrBioMassRatingLbl();
}
void MadDataClassification::on_sbSVCropNInAGrBioMassObservations_valueChanged()
{
  updateSVCropNInAGrBioMassRatingLbl();
}
void MadDataClassification::on_sbSVCropNInAGrBioMassWeightPts_valueChanged()
{
  updateSVCropNInAGrBioMassRatingLbl();
}
void MadDataClassification::on_dsbSVCropNInAGrBioMassReplicates_valueChanged()
{
  updateSVCropNInAGrBioMassRatingLbl();
}

void MadDataClassification::on_sbSVCropNInOrgansLayers_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}
void MadDataClassification::on_sbSVCropNInOrgansObservations_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}
void MadDataClassification::on_sbSVCropNInOrgansWeightPts_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}
void MadDataClassification::on_dsbSVCropNInOrgansReplicates_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}

void MadDataClassification::on_sbSVCropLAILayers_valueChanged()
{
  updateSVCropLAIRatingLbl();
}
void MadDataClassification::on_sbSVCropLAIObservations_valueChanged()
{
  updateSVCropLAIRatingLbl();
}
void MadDataClassification::on_sbSVCropLAIWeightPts_valueChanged()
{
  updateSVCropLAIRatingLbl();
}
void MadDataClassification::on_dsbSVCropLAIReplicates_valueChanged()
{
  updateSVCropLAIRatingLbl();
}

// SV soil tab (spin box changes)
void MadDataClassification::on_sbSVSoilSoilWaterGravLayers_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}
void MadDataClassification::on_sbSVSoilSoilWaterGravObservations_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}
void MadDataClassification::on_sbSVSoilSoilWaterGravWeightPts_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}
void MadDataClassification::on_dsbSVSoilSoilWaterGravReplicates_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}

void MadDataClassification::on_sbSVSoilPressureHeadsLayers_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}
void MadDataClassification::on_sbSVSoilPressureHeadsObservations_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}
void MadDataClassification::on_sbSVSoilPressureHeadsWeightPts_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}
void MadDataClassification::on_dsbSVSoilPressureHeadsReplicates_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}

void MadDataClassification::on_sbSVSoilNMinLayers_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}
void MadDataClassification::on_sbSVSoilNMinObservations_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}
void MadDataClassification::on_sbSVSoilNMinWeightPts_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}
void MadDataClassification::on_dsbSVSoilNMinReplicates_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}

void MadDataClassification::on_sbSVSoilSoilWaterSensorCalLayers_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}
void MadDataClassification::on_sbSVSoilSoilWaterSensorCalObservations_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}
void MadDataClassification::on_sbSVSoilSoilWaterSensorCalWeightPts_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}
void MadDataClassification::on_dsbSVSoilSoilWaterSensorCalReplicates_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}

void MadDataClassification::on_sbSVSoilWaterFluxBottomRootLayers_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}
void MadDataClassification::on_sbSVSoilWaterFluxBottomRootObservations_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}
void MadDataClassification::on_sbSVSoilWaterFluxBottomRootWeightPts_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}
void MadDataClassification::on_dsbSVSoilWaterFluxBottomRootReplicates_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}

void MadDataClassification::on_sbSVSoilNFluxBottomRootLayers_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}
void MadDataClassification::on_sbSVSoilNFluxBottomRootObservations_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}
void MadDataClassification::on_sbSVSoilNFluxBottomRootWeightPts_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}
void MadDataClassification::on_dsbSVSoilNFluxBottomRootReplicates_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}

// SV surface fluxes tab (spin box changes)
void MadDataClassification::on_sbSVSurfaceFluxesEtLayers_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesEtObservations_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesEtWeightPts_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesEtReplicates_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}

void MadDataClassification::on_sbSVSurfaceFluxesNh3LossLayers_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesNh3LossObservations_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesNh3LossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesNh3LossReplicates_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}

void MadDataClassification::on_sbSVSurfaceFluxesN2OLossLayers_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesN2OLossObservations_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesN2OLossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesN2OLossReplicates_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}

void MadDataClassification::on_sbSVSurfaceFluxesN2LossLayers_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesN2LossObservations_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesN2LossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesN2LossReplicates_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}

void MadDataClassification::on_sbSVSurfaceFluxesCh4LossLayers_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesCh4LossObservations_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesCh4LossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesCh4LossReplicates_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}

// SV observations tab (spin box changes)
void MadDataClassification::on_sbSVObservationsLodgingLayers_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}
void MadDataClassification::on_sbSVObservationsLodgingObservations_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}
void MadDataClassification::on_sbSVObservationsLodgingWeightPts_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsLodgingReplicates_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}

void MadDataClassification::on_sbSVObservationsPestsOrDiseasesLayers_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}
void MadDataClassification::on_sbSVObservationsPestsOrDiseasesObservations_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}
void MadDataClassification::on_sbSVObservationsPestsOrDiseasesWeightPts_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsPestsOrDiseasesReplicates_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}

void MadDataClassification::on_sbSVObservationsDamagesLayers_valueChanged()
{
  updateSVObservationsDamagesRatingLbl();
}
void MadDataClassification::on_sbSVObservationsDamagesObservations_valueChanged()
{
  updateSVObservationsDamagesRatingLbl();
}
void MadDataClassification::on_sbSVObservationsDamagesWeightPts_valueChanged()
{
  updateSVObservationsDamagesRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsDamagesReplicates_valueChanged()
{
  updateSVObservationsDamagesRatingLbl();
}


   //-----------------------------//
  // label updates (with calcs)  //
 //-----------------------------//
// cultivation tab (label updates (with calcs))
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

// phenology tab (label updates (with calcs))
void MadDataClassification::updatePhenologyEmergenceRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbEmergencePhenology->value();
  float myGivenWeighting = dsbEmergencePhenology->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblEmergenceRatingPhenology->setText(myText);
  updatePhenologyLabels();
}
void MadDataClassification::updatePhenologyStemElongationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbStemElongationPhenology->value();
  float myGivenWeighting = dsbStemElongationPhenology->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblStemElongationRatingPhenology->setText(myText);
  updatePhenologyLabels();
}
void MadDataClassification::updatePhenologyEarEmergenceRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbEarEmergencePhenology->value();
  float myGivenWeighting = dsbEarEmergencePhenology->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblEarEmergenceRatingPhenology->setText(myText);
  updatePhenologyLabels();
}
void MadDataClassification::updatePhenologyFloweringRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbFloweringPhenology->value();
  float myGivenWeighting = dsbFloweringPhenology->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblFloweringRatingPhenology->setText(myText);
  updatePhenologyLabels();
}
void MadDataClassification::updatePhenologyYellowRipenessRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbYellowRipenessPhenology->value();
  float myGivenWeighting = dsbYellowRipenessPhenology->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblYellowRipenessRatingPhenology->setText(myText);
  updatePhenologyLabels();
}

// prev crop tab (label updates (with calcs))
void MadDataClassification::updatePrevCropCropRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbCropPrevCrop->value();
  float myGivenWeighting = dsbCropPrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblCropRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}
void MadDataClassification::updatePrevCropSowingDateRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSowingDatePrevCrop->value();
  float myGivenWeighting = dsbSowingDatePrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSowingDateRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}
void MadDataClassification::updatePrevCropHarvestDateRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbHarvestDatePrevCrop->value();
  float myGivenWeighting = dsbHarvestDatePrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblHarvestDateRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}
void MadDataClassification::updatePrevCropYieldRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbYieldPrevCrop->value();
  float myGivenWeighting = dsbYieldPrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblYieldRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}
void MadDataClassification::updatePrevCropResidueMgmtRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbResidueMgmtPrevCrop->value();
  float myGivenWeighting = dsbResidueMgmtPrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblResidueMgmtRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}
void MadDataClassification::updatePrevCropFertilisationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbFertilisationPrevCrop->value();
  float myGivenWeighting = dsbFertilisationPrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblFertilisationRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}
void MadDataClassification::updatePrevCropIrrigationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbIrrigationPrevCrop->value();
  float myGivenWeighting = dsbIrrigationPrevCrop->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblIrrigationRatingPrevCrop->setText(myText);
  updatePrevCropLabels();
}

// initial values tab (label updates (with calcs))
void MadDataClassification::updateInitialValuesSoilMoistureRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSoilMoistureInitialValues->value();
  float myGivenWeighting = dsbSoilMoistureInitialValues->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSoilMoistureRatingInitialValues->setText(myText);
  updateInitialValuesLabels();
}
void MadDataClassification::updateInitialValuesNMinRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbNMinInitialValues->value();
  float myGivenWeighting = dsbNMinInitialValues->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblNMinRatingInitialValues->setText(myText);
  updateInitialValuesLabels();
}

// soil tab (label updates (with calcs))
void MadDataClassification::updateSoilCOrgRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbCOrgSoil->value();
  float myGivenWeighting = dsbCOrgSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblCOrgRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilNOrgRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbNOrgSoil->value();
  float myGivenWeighting = dsbNOrgSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblNOrgRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilTextureRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbTextureSoil->value();
  float myGivenWeighting = dsbTextureSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblTextureRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilBulkDensityRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbBulkDensitySoil->value();
  float myGivenWeighting = dsbBulkDensitySoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblBulkDensityRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilFieldCapacityRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbFieldCapacitySoil->value();
  float myGivenWeighting = dsbFieldCapacitySoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblFieldCapacityRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilWiltingPointRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbWiltingPointSoil->value();
  float myGivenWeighting = dsbWiltingPointSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblWiltingPointRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilPfCurveRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbPfCurveSoil->value();
  float myGivenWeighting = dsbPfCurveSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblPfCurveRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilHydrCondCurveRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbHydrCondCurveSoil->value();
  float myGivenWeighting = dsbHydrCondCurveSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblHydrCondCurveRatingSoil->setText(myText);
  updateSoilLabels();
}
void MadDataClassification::updateSoilPhRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbPhSoil->value();
  float myGivenWeighting = dsbPhSoil->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblPhRatingSoil->setText(myText);
  updateSoilLabels();
}

// site tab (label updates (with calcs))
void MadDataClassification::updateSiteLatitudeRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbLatitudeSite->value();
  float myGivenWeighting = dsbLatitudeSite->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblLatitudeRatingSite->setText(myText);
  updateSiteLabels();
}
void MadDataClassification::updateSiteLongitudeRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbLongitudeSite->value();
  float myGivenWeighting = dsbLongitudeSite->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblLongitudeRatingSite->setText(myText);
  updateSiteLabels();
}
void MadDataClassification::updateSiteAltitudeRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbAltitudeSite->value();
  float myGivenWeighting = dsbAltitudeSite->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblAltitudeRatingSite->setText(myText);
  updateSiteLabels();
}

// weather tab (label updates (with calcs))
void MadDataClassification::updateWeatherPrecipitationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbPrecipitationWeather->value();
  float myGivenWeighting = dsbPrecipitationWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblPrecipitationRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherTAveRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbTAveWeather->value();
  float myGivenWeighting = dsbTAveWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblTAveRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherTMinRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbTMinWeather->value();
  float myGivenWeighting = dsbTMinWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblTMinRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherTMaxRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbTMaxWeather->value();
  float myGivenWeighting = dsbTMaxWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblTMaxRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherRelHumidityRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbRelHumidityWeather->value();
  float myGivenWeighting = dsbRelHumidityWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblRelHumidityRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherWindSpeedRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbWindSpeedWeather->value();
  float myGivenWeighting = dsbWindSpeedWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblWindSpeedRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherGlobalRadiationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbGlobalRadiationWeather->value();
  float myGivenWeighting = dsbGlobalRadiationWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblGlobalRadiationRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherSunshineHoursRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSunshineHoursWeather->value();
  float myGivenWeighting = dsbSunshineHoursWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSunshineHoursRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherLeafWetnessRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbLeafWetnessWeather->value();
  float myGivenWeighting = dsbLeafWetnessWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblLeafWetnessRatingWeather->setText(myText);
  updateWeatherLabels();
}
void MadDataClassification::updateWeatherSoilTempRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSoilTempWeather->value();
  float myGivenWeighting = dsbSoilTempWeather->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSoilTempRatingWeather->setText(myText);
  updateWeatherLabels();
}

// SV crop tab (label updates (with calcs))
void MadDataClassification::updateSVCropAGrBiomassRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropAGrBiomassObservations->value();
  float myGivenWeighting = sbSVCropAGrBiomassWeight->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropAGrBiomassPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropWeightOrgansRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropWeightOrgansObservations->value();
  float myGivenWeighting = sbSVCropWeightOrgansWeight->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropWeightOrgansPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropRootBioMassRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropRootBioMassObservations->value();
  float myGivenWeighting = sbSVCropRootBioMassWeight->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropRootBiomassPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropNInAGrBioMassRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropNInAGrBioMassObservations->value();
  float myGivenWeighting = sbSVCropNInAGrBioMassWeight->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropNInAGrBiomassPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropNInOrgansRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropNInOrgansObservations->value();
  float myGivenWeighting = sbSVCropNInOrgansWeight->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropNInOrgansPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropLAIRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropLAIObservations->value();
  float myGivenWeighting = sbSVCropLAIWeight->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropLAIPoints->setText(myText);
  updateSVCropLabels();
}

// SV soil tab (label updates (with calcs))
void MadDataClassification::updateSVSoilSoilWaterGravRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilSoilWaterGravObservations->value();
  float myGivenWeighting = sbSVSoilSoilWaterGravWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilSoilWaterGravPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilPressureHeadsRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilPressureHeadsObservations->value();
  float myGivenWeighting = sbSVSoilPressureHeadsWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilPressureHeadsPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilNMinRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilNMinObservations->value();
  float myGivenWeighting = sbSVSoilNMinWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilNMinPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilSoilWaterSensorCalRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilSoilWaterSensorCalObservations->value();
  float myGivenWeighting = sbSVSoilSoilWaterSensorCalWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilSoilWaterSensorCalPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilWaterFluxBottomRootRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilWaterFluxBottomRootObservations->value();
  float myGivenWeighting = sbSVSoilWaterFluxBottomRootWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilWaterFluxBottomRootPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilNFluxBottomRootRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilNFluxBottomRootObservations->value();
  float myGivenWeighting = sbSVSoilNFluxBottomRootWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilNFluxBottomRootPoints->setText(myText);
  updateSVSoilLabels();
}

// SV surface fluxes tab (label updates (with calcs))
void MadDataClassification::updateSVSurfaceFluxesEtRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesEtObservations->value();
  float myGivenWeighting = sbSVSurfaceFluxesEtWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesEtPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesNh3LossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesNh3LossObservations->value();
  float myGivenWeighting = sbSVSurfaceFluxesNh3LossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesNh3LossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesN2OLossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesN2OLossObservations->value();
  float myGivenWeighting = sbSVSurfaceFluxesN2OLossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesN2OLossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesN2LossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesN2LossObservations->value();
  float myGivenWeighting = sbSVSurfaceFluxesN2LossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesN2LossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesCh4LossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesCh4LossObservations->value();
  float myGivenWeighting = sbSVSurfaceFluxesCh4LossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesCh4LossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}

// SV observations tab (label updates (with calcs))
void MadDataClassification::updateSVObservationsLodgingRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVObservationsLodgingObservations->value();
  float myGivenWeighting = sbSVObservationsLodgingWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVObservationsLodgingPoints->setText(myText);
  updateSVObservationsLabels();
}
void MadDataClassification::updateSVObservationsPestsOrDiseasesRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVObservationsPestsOrDiseasesObservations->value();
  float myGivenWeighting = sbSVObservationsPestsOrDiseasesWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVObservationsPestsOrDiseasesPoints->setText(myText);
  updateSVObservationsLabels();
}
void MadDataClassification::updateSVObservationsDamagesRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVObservationsDamagesObservations->value();
  float myGivenWeighting = sbSVObservationsDamagesWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVObservationsDamagesPoints->setText(myText);
  updateSVObservationsLabels();
}


   //-------------------------------------//
  //  Update ranking labels and pixmaps  //
 //-------------------------------------//
// cultivation (ranking labels and pixmaps)
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
    case 24: lblMedalCultivation->setVisible(true);
             lblMedalCultivation->setScaledContents(true);
             lblMedalCultivation->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingCultivation->setVisible(true);
             lblRankingCultivation->setText("Platinum");
      break;

    case 23: lblMedalCultivation->setVisible(true);
             lblMedalCultivation->setScaledContents(true);
             lblMedalCultivation->setPixmap(QPixmap( ":gold.png" ));
             lblRankingCultivation->setVisible(true);
             lblRankingCultivation->setText("Gold");
      break;

    case 22: lblMedalCultivation->setVisible(true);
             lblMedalCultivation->setScaledContents(true);
             lblMedalCultivation->setPixmap(QPixmap( ":silver.png" ));
             lblRankingCultivation->setVisible(true);
             lblRankingCultivation->setText("Silver");
      break;

    case 21: lblMedalCultivation->setVisible(true);
             lblMedalCultivation->setScaledContents(true);
             lblMedalCultivation->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingCultivation->setVisible(true);
             lblRankingCultivation->setText("Bronze");
      break;

    default: // hide
             lblRankingCultivation->setVisible(false);
             lblMedalCultivation->setVisible(false);
      break;
  }
}

// phenology (ranking labels and pixmaps)
void MadDataClassification::updatePhenologyLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblEmergenceRatingPhenology->text().toFloat();
  myTotal += lblStemElongationRatingPhenology->text().toFloat();
  myTotal += lblEarEmergenceRatingPhenology->text().toFloat();
  myTotal += lblFloweringRatingPhenology->text().toFloat();
  myTotal += lblYellowRipenessRatingPhenology->text().toFloat();
  lblCombinedTotalPhenology->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 24) myRank=24;
  else if (myTotal >= 23) myRank=23;
  else if (myTotal >= 22) myRank=22;
  else if (myTotal >= 21) myRank=21;

  switch (myRank)
  {
    case 24: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Platinum");
      break;

    case 23: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":gold.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Gold");
      break;

    case 22: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":silver.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Silver");
      break;

    case 21: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Bronze");
      break;

    default: // hide
             lblRankingPhenology->setVisible(false);
             lblMedalPhenology->setVisible(false);
      break;
  }
}

// prev crop tab (ranking labels and pixmaps)

// initial values tab (ranking labels and pixmaps)

// soil tab (ranking labels and pixmaps)

// site tab (ranking labels and pixmaps)

// weather tab (ranking labels and pixmaps)

// SV crop tab (ranking labels and pixmaps)

// SV soil tab (ranking labels and pixmaps)

// SV surface fluxes tab (ranking labels and pixmaps)

// SV observations tab (ranking labels and pixmaps)

   //-------------------//
  //  Saving the form  //
 //-------------------//
//  when save button is pressed, it gets converted to xml here
void MadDataClassification::on_pbSave_clicked()
{
  // save current settings for phenology to xml file
  // first we have to get the values

  MadDataClassificationCultivation myCultivation;
  MadDataClassificationPhenology myPhenology;
  MadDataClassificationPrevCrop myPrevCropSet;
  MadDataClassificationInitialValues myInitialValues;
  MadDataClassificationSoil mySoil;
  MadDataClassificationSiteData mySiteData;
  MadDataClassificationWeather myWeather;
  MadStateVars myStateVars;

  // cultivation
  MadSubCategory myCultVariety;
  MadSubCategory myCultSowing;
  MadSubCategory myCultHarvest;
  MadSubCategory myCultFertilisation;
  MadSubCategory myCultIrrigation;
  MadSubCategory myCultSeedDensity;
  MadSubCategory myCultYield;
  MadSubCategory myCultTillage;

  // phenology
  MadSubCategory myPhenologyEmergence;
  MadSubCategory myPhenologyStemElongation;
  MadSubCategory myPhenologyEarEmergence;
  MadSubCategory myPhenologyFlowering;
  MadSubCategory myPhenologyYellowRipeness;

  // prev crop
  MadSubCategory myPrevCropCrop;
  MadSubCategory myPrevCropSowingDate;
  MadSubCategory myPrevCropHarvestDate;
  MadSubCategory myPrevCropYield;
  MadSubCategory myPrevCropResidueMgmt;
  MadSubCategory myPrevCropFertilisation;
  MadSubCategory myPrevCropIrrigation;

  //initial values
  MadSubCategory myInitialValuesSoilMoisture;
  MadSubCategory myInitialValuesNitrogenMin;

  // soil
  MadSubCategory mySoilCarbonOrganic;
  MadSubCategory mySoilNitrogenOrganic;
  MadSubCategory mySoilTexture;
  MadSubCategory mySoilBulkDensity;
  MadSubCategory mySoilFieldCapacity;
  MadSubCategory mySoilWiltingPoint;
  MadSubCategory mySoilPfCurve;
  MadSubCategory mySoilHydrCondState;

  // site
  MadSubCategory mySiteDataLatitude;
  MadSubCategory mySiteDataLongitude;
  MadSubCategory mySiteDataAltitude;

  //weather
  MadSubCategory myWeatherPrecipitation;
  MadSubCategory myWeatherTAve;
  MadSubCategory myWeatherTMin;
  MadSubCategory myWeatherTMax;
  MadSubCategory myWeatherRelativeHumidity;
  MadSubCategory myWeatherWindSpeed;
  MadSubCategory myWeatherGlobalRadiation;
  MadSubCategory myWeatherSunshineHours;

  //state vars - soil
  MadSubCategory myStateVarsSoilSoilWaterGrav;
  MadSubCategory myStateVarsSoilPressureHeads;
  MadSubCategory myStateVarsSoilNMin;
  MadSubCategory myStateVarsSoilSoilWaterSensorCal;
  MadSubCategory myStateVarsSoilWaterFluxBottomRoot;
  MadSubCategory myStateVarsSoilNFluxBottomRoot;

  // state vars - crop
  MadSubCategory myStateVarsCropAGrBiomass;
  MadSubCategory myStateVarsCropWeightOrgans;
  MadSubCategory myStateVarsCropRootBiomass;
  MadSubCategory myStateVarsCropNInAGrBiomass;
  MadSubCategory myStateVarsCropNInOrgans;
  MadSubCategory myStateVarsCropLAI;

  // state vars - surface fluxes
  MadSubCategory myStateVarsSurfaceFluxesEt;
  MadSubCategory myStateVarsSurfaceFluxesNh3Loss;
  MadSubCategory myStateVarsSurfaceFluxesN2OLoss;
  MadSubCategory myStateVarsSurfaceFluxesN2Loss;
  MadSubCategory myStateVarsSurfaceFluxesCh4Loss;

  // state vars - observation data
  MadSubCategory myStateVarsObservationsLodging;
  MadSubCategory myStateVarsObservationsPestsOrDiseases;
  MadSubCategory myStateVarsObservationsDamages;

    //////////////////////////////////
   //get the values from the form  //
  //////////////////////////////////

  //
  // Cultivation values from form
  //

  // variety
  myCultVariety.setMinData(chbxVariety->isChecked());
  myCultVariety.setDepth(0);
  myCultVariety.setWeightPoints(dsbVariety->value());
  myCultVariety.setObservations(sbVariety->value());
  myCultVariety.setReplicates(0);
  // sowing
  myCultSowing.setMinData(chbxSowing->isChecked());
  myCultSowing.setDepth(0);
  myCultSowing.setWeightPoints(dsbSowing->value());
  myCultSowing.setObservations(sbSowing->value());
  myCultSowing.setReplicates(0);
  // harvest
  myCultHarvest.setMinData(chbxHarvest->isChecked());
  myCultHarvest.setDepth(0);
  myCultHarvest.setWeightPoints(dsbHarvest->value());
  myCultHarvest.setObservations(sbHarvest->value());
  myCultHarvest.setReplicates(0);
  // fertilisation
  myCultFertilisation.setMinData(chbxFertilisation->isChecked());
  myCultFertilisation.setDepth(0);
  myCultFertilisation.setWeightPoints(dsbFertilisation->value());
  myCultFertilisation.setObservations(sbFertilisation->value());
  myCultFertilisation.setReplicates(0);
  // irrigation
  myCultIrrigation.setMinData(chbxIrrigation->isChecked());
  myCultIrrigation.setDepth(0);
  myCultIrrigation.setWeightPoints(dsbIrrigation->value());
  myCultIrrigation.setObservations(sbIrrigation->value());
  myCultIrrigation.setReplicates(0);
  // seed density
  myCultSeedDensity.setMinData(chbxSeedDensity->isChecked());
  myCultSeedDensity.setDepth(0);
  myCultSeedDensity.setWeightPoints(dsbSeedDensity->value());
  myCultSeedDensity.setObservations(sbSeedDensity->value());
  myCultSeedDensity.setReplicates(0);
  // yield
  myCultYield.setMinData(chbxYield->isChecked());
  myCultYield.setDepth(0);
  myCultYield.setWeightPoints(dsbYield->value());
  myCultYield.setObservations(sbYield->value());
  myCultYield.setReplicates(0);
  // tillage
  myCultYield.setMinData(chbxTillage->isChecked());
  myCultTillage.setDepth(0);
  myCultTillage.setWeightPoints(dsbTillage->value());
  myCultTillage.setObservations(sbTillage->value());
  myCultTillage.setReplicates(0);

  // Phenology values from form
  // emergence
  myPhenologyEmergence.setMinData(chbxEmergencePhenology->isChecked());
  myPhenologyEmergence.setDepth(0);
  myPhenologyEmergence.setWeightPoints(dsbEmergencePhenology->value());
  myPhenologyEmergence.setObservations(sbEmergencePhenology->value());
  myPhenologyEmergence.setReplicates(0);
  // stem elongation
  myPhenologyStemElongation.setMinData(chbxStemElongationPhenology->isChecked());
  myPhenologyStemElongation.setDepth(0);
  myPhenologyStemElongation.setWeightPoints(dsbStemElongationPhenology->value());
  myPhenologyStemElongation.setObservations(sbStemElongationPhenology->value());
  myPhenologyStemElongation.setReplicates(0);
  // ear emergence
  myPhenologyEarEmergence.setMinData(chbxEarEmergencePhenology->isChecked());
  myPhenologyEarEmergence.setDepth(0);
  myPhenologyEarEmergence.setWeightPoints(dsbEarEmergencePhenology->value());
  myPhenologyEarEmergence.setObservations(sbEarEmergencePhenology->value());
  myPhenologyEarEmergence.setReplicates(0);
  // flowering
  myPhenologyFlowering.setMinData(chbxFloweringPhenology->isChecked());
  myPhenologyFlowering.setDepth(0);
  myPhenologyFlowering.setWeightPoints(dsbFloweringPhenology->value());
  myPhenologyFlowering.setObservations(sbFloweringPhenology->value());
  myPhenologyFlowering.setReplicates(0);
  // yellow ripeness
  myPhenologyYellowRipeness.setMinData(chbxYellowRipenessPhenology->isChecked());
  myPhenologyYellowRipeness.setDepth(0);
  myPhenologyYellowRipeness.setWeightPoints(dsbYellowRipenessPhenology->value());
  myPhenologyYellowRipeness.setObservations(sbYellowRipenessPhenology->value());
  myPhenologyYellowRipeness.setReplicates(0);

  //
  // PrevCrop values from form
  //

  // crop

  // sowing date

  // harvest date

  // yield

  // residue mgmt

  // fertilisation

  // irrigation

  //
  // Initial Values values from form
  //

  // soil moisture

  // nitrogen min

  //
  // Soil values from form
  //

  // Carbon organic

  // Nitrogen organic

  // texture

  // bulk density

  // field capacity

  // wilting point

  // pf curve

  // hydr. cond. curve

  //
  // Site values from form
  //

  // latitude

  // longitude

  // altitude

  //
  // Weather values from form
  //

  // precipitation

  // T ave

  // T min

  // T max

  // relative humidity

  // wind speed

  // global radiation

  // sunshine hours

  //
  // Sate Vars from Form
  //

  // CROP a. gr. biomass

  // CROP weight organs

  // CROP root biomass

  // CROP N in a. gr. biomass

  // CROP N in organs

  // CROP LAI

  // SOIL soil water grav.

  // SOIL pressure heads

  // SOIL nitrogen min.

  // SOIL soil water sensor cal.

  // SOIL water flux bottom root

  // SOIL N flux bottom root

  // SURFACE FLUXES ET

  // SURFACE FLUXES NH3 Loss

  // SURFACE FLUXES N2O Loss

  // SURFACE FLUXES N2 Loss

  // SURFACE FLUXES CH4 Loss

  // OBSERVATIONS lodging

  // OBSERVATIONS pests or diseases

  // OBSERVATIONS damages

    /////////////////////
   // set the values  //
  /////////////////////

  //
  // set cultivation values
  //
  myCultivation.setVariety(myCultVariety);
  myCultivation.setSowing(myCultSowing);
  myCultivation.setHarvest(myCultHarvest);
  myCultivation.setFertilisation(myCultFertilisation);
  myCultivation.setIrrigation(myCultIrrigation);
  myCultivation.setSeedDensity(myCultSeedDensity);
  myCultivation.setYield(myCultYield);
  myCultivation.setTillage(myCultTillage);

  //
  // set phenology values
  //
  myPhenology.setEmergence(myPhenologyEmergence);
  myPhenology.setStemElongation(myPhenologyStemElongation);
  myPhenology.setEarEmergence(myPhenologyEarEmergence);
  myPhenology.setFlowering(myPhenologyFlowering);
  myPhenology.setYellowRipeness(myPhenologyYellowRipeness);

  //
  // set previous crop values
  //


  //
  // set initial values values
  //


  //
  // set soil values
  //


  //
  // set site values
  //


  //
  // set weather values
  //


  //
  // set state vars values
  //



  QString myString;
  myString = myCultivation.toXml();
  myString += myPhenology.toXml();
  textEditSide->setText(myString);


  //mCrop.toXmlFile( LaUtils::userCropProfilesDirPath() +
  //    QDir::separator() + mCrop.guid() + ".xml");
}

