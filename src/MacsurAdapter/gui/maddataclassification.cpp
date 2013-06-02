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
  connect ( dsbSVSoilWasterFluxBottomRootReplicates, SIGNAL ( valueChanged(int) ),
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

   //
  //  group box edit and examples combobox
 //
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
    lblExample->setVisible(false);
    cbExamples->setDisabled(true);
  }
  else
  {
    cbExamples->setEnabled(true);
    lblExample->setVisible(true);
  }
}
void MadDataClassification::on_cbExamplesPhenology_currentIndexChanged (const QString &theValue)
{
  // if enabled, set values for corresponding classification
  // options are: Platinum, Gold, Silver, Bronze
  if (cbExamples->currentText()!="Examples")
  {
    lblExample->setText(theValue);
  }
  else
  {
    lblExample->setText("Select Example");
  }
}

// prev crop tab (group box edit and examples combobox)

// initial values tab (group box edit and examples combobox)

// soil tab (group box edit and examples combobox)

// site tab (group box edit and examples combobox)

// weather tab (group box edit and examples combobox)

// SV crop tab (group box edit and examples combobox)

// SV soil tab (group box edit and examples combobox)

// SV surface fluxes tab (group box edit and examples combobox)

// SV observations tab (group box edit and examples combobox)


   //
  //  slider linking and point calcs
 //
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

// initial values tab (slider linking and point calcs)

// soil tab (slider linking and point calcs)

// site tab (slider linking and point calcs)

// weather tab (slider linking and point calcs)

// SV crop tab (slider linking and point calcs)

// SV soil tab (slider linking and point calcs)

// SV surface fluxes tab (slider linking and point calcs)

// SV observations tab (slider linking and point calcs)


   //
  //  double spin box changes
 //
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

// initial values tab (double spin box changes)

// soil tab (double spin box changes)

// site tab (double spin box changes)

// weather tab (double spin box changes)

// SV crop tab (double spin box changes)

// SV soil tab (double spin box changes)

// SV surface fluxes tab (double spin box changes)

// SV observations tab (double spin box changes)


   //
  // label updates (with calcs)
 //
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

// initial values tab (label updates (with calcs))

// soil tab (label updates (with calcs))

// site tab (label updates (with calcs))

// weather tab (label updates (with calcs))

// SV crop tab (label updates (with calcs))

// SV soil tab (label updates (with calcs))

// SV surface fluxes tab (label updates (with calcs))

// SV observations tab (label updates (with calcs))


   //
  //  Update ranking labels and pixmaps
 //
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

   //
  //  Saving the form
 //
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

