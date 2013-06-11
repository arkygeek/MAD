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
#include <QDomDocument>
#include <QDomElement>
#include <QDir>

//Local includes
#include "maddataclassification.h"
#include "lib/mad.h"
#include "lib/madutils.h"
#include "lib/madguid.h"

QString makeString();

MadDataClassification::MadDataClassification(QWidget *parent) : QDialog(parent)
{
  setupUi(this);
  gbxManagement->setChecked(false);
  cbExamples->setEnabled(true);
  lblExample->setVisible(true);
  lblExample->setText("Select Example");
  lblMedalManagement->setVisible(false);
  lblRankingManagement->setVisible(false);
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

  // management connections
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
  connect ( dsbSVCropAGrBiomassLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));
  connect ( sbSVCropAGrBiomassObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));
  connect ( dsbSVCropAGrBiomassWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));
  connect ( dsbSVCropAGrBiomassReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropAGrBiomassRatingLbl() ));

  connect ( dsbSVCropWeightOrgansLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));
  connect ( sbSVCropWeightOrgansObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));
  connect ( dsbSVCropWeightOrgansWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));
  connect ( dsbSVCropWeightOrgansReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropWeightOrgansRatingLbl() ));

  connect ( dsbSVCropRootBiomassLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropRootBiomassRatingLbl() ));
  connect ( sbSVCropRootBiomassObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropRootBiomassRatingLbl() ));
  connect ( dsbSVCropRootBiomassWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropRootBiomassRatingLbl() ));
  connect ( dsbSVCropRootBiomassReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropRootBiomassRatingLbl() ));

  connect ( dsbSVCropNInAGrBiomassLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropNInAGrBiomassRatingLbl() ));
  connect ( sbSVCropNInAGrBiomassObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInAGrBiomassRatingLbl() ));
  connect ( dsbSVCropNInAGrBiomassWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropNInAGrBiomassRatingLbl() ));
  connect ( dsbSVCropNInAGrBiomassReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropNInAGrBiomassRatingLbl() ));

  connect ( dsbSVCropNInOrgansLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));
  connect ( sbSVCropNInOrgansObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));
  connect ( dsbSVCropNInOrgansWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));
  connect ( dsbSVCropNInOrgansReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropNInOrgansRatingLbl() ));

  connect ( dsbSVCropLAILayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));
  connect ( sbSVCropLAIObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));
  connect ( dsbSVCropLAIWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));
  connect ( dsbSVCropLAIReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVCropLAIRatingLbl() ));

  // soil
  connect ( dsbSVSoilSoilWaterSensorCalLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( sbSVSoilSoilWaterSensorCalObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( dsbSVSoilSoilWaterSensorCalWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( dsbSVSoilSoilWaterSensorCalReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));

  connect ( dsbSVSoilPressureHeadsLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));
  connect ( sbSVSoilPressureHeadsObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));
  connect ( dsbSVSoilPressureHeadsWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));
  connect ( dsbSVSoilPressureHeadsReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilPressureHeadsRatingLbl() ));

  connect ( dsbSVSoilNMinLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));
  connect ( sbSVSoilNMinObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));
  connect ( dsbSVSoilNMinWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));
  connect ( dsbSVSoilNMinReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilNMinRatingLbl() ));

  connect ( dsbSVSoilSoilWaterSensorCalLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( sbSVSoilSoilWaterSensorCalObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( dsbSVSoilSoilWaterSensorCalWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));
  connect ( dsbSVSoilSoilWaterSensorCalReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilSoilWaterSensorCalRatingLbl() ));

  connect ( dsbSVSoilWaterFluxBottomRootLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));
  connect ( sbSVSoilWaterFluxBottomRootObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));
  connect ( dsbSVSoilWaterFluxBottomRootWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));
  connect ( dsbSVSoilWaterFluxBottomRootReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilWaterFluxBottomRootRatingLbl() ));

  connect ( dsbSVSoilNFluxBottomRootLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));
  connect ( sbSVSoilNFluxBottomRootObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));
  connect ( dsbSVSoilNFluxBottomRootWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));
  connect ( dsbSVSoilNFluxBottomRootReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSoilNFluxBottomRootRatingLbl() ));

  // surface fluxes
  connect ( dsbSVSurfaceFluxesEtLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));
  connect ( sbSVSurfaceFluxesEtObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));
  connect ( dsbSVSurfaceFluxesEtWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));
  connect ( dsbSVSurfaceFluxesEtReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesEtRatingLbl() ));

  connect ( dsbSVSurfaceFluxesNh3LossLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesNh3LossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesNh3LossWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesNh3LossReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesNh3LossRatingLbl() ));

  connect ( dsbSVSurfaceFluxesN2OLossLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));
  connect ( sbSVSurfaceFluxesN2OLossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesN2OLossWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesN2OLossReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesN2OLossRatingLbl() ));

  connect ( dsbSVSurfaceFluxesN2LossLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesN2LossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesN2LossWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesN2LossReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesN2LossRatingLbl() ));

  connect ( dsbSVSurfaceFluxesCh4LossLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));
  connect ( sbSVSurfaceFluxesCh4LossObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesCh4LossWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));
  connect ( dsbSVSurfaceFluxesCh4LossReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVSurfaceFluxesCh4LossRatingLbl() ));

  // observations
  connect ( dsbSVObservationsLodgingLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));
  connect ( sbSVObservationsLodgingObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));
  connect ( dsbSVObservationsLodgingWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));
  connect ( dsbSVObservationsLodgingReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsLodgingRatingLbl() ));

  connect ( dsbSVObservationsPestsOrDiseasesLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));
  connect ( sbSVObservationsPestsOrDiseasesObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));
  connect ( dsbSVObservationsPestsOrDiseasesWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));
  connect ( dsbSVObservationsPestsOrDiseasesReplicates, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsPestsOrDiseasesRatingLbl() ));

  connect ( dsbSVObservationsDamagesLayers, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
  connect ( sbSVObservationsDamagesObservations, SIGNAL ( valueChanged(int) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
  connect ( dsbSVObservationsLodgingWeightPts, SIGNAL ( valueChanged(double) ),
            this, SLOT ( updateSVObservationsDamagesRatingLbl() ));
  connect ( dsbSVObservationsLodgingReplicates, SIGNAL ( valueChanged(double) ),
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
// management tab (group box edit and examples combobox)
void MadDataClassification::on_gbxManagement_clicked()
{
  // if values are editable, should not be able to select for any
  // examples to be shown as it will destroy destroy current settings
  if (gbxManagement->isChecked())
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
// management (slider linking and point calcs)
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
void MadDataClassification::on_hsldrRelHumidityWeather_valueChanged(int theSliderValue)
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
// management (double spin box changes)
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
void MadDataClassification::on_dsbRelHumidityWeather_valueChanged(double theValue)
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
void MadDataClassification::on_dsbSVCropAGrBiomassLayers_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}
void MadDataClassification::on_sbSVCropAGrBiomassObservations_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropAGrBiomassWeightPts_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropAGrBiomassReplicates_valueChanged()
{
  updateSVCropAGrBiomassRatingLbl();
}

void MadDataClassification::on_dsbSVCropWeightOrgansLayers_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}
void MadDataClassification::on_sbSVCropWeightOrgansObservations_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}
void MadDataClassification::on_dsbSVCropWeightOrgansWeightPts_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}
void MadDataClassification::on_dsbSVCropWeightOrgansReplicates_valueChanged()
{
  updateSVCropWeightOrgansRatingLbl();
}

void MadDataClassification::on_dsbSVCropRootBiomassLayers_valueChanged()
{
  updateSVCropRootBiomassRatingLbl();
}
void MadDataClassification::on_sbSVCropRootBiomassObservations_valueChanged()
{
  updateSVCropRootBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropRootBiomassWeightPts_valueChanged()
{
  updateSVCropRootBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropRootBiomassReplicates_valueChanged()
{
  updateSVCropRootBiomassRatingLbl();
}

void MadDataClassification::on_dsbSVCropNInAGrBiomassLayers_valueChanged()
{
  updateSVCropNInAGrBiomassRatingLbl();
}
void MadDataClassification::on_sbSVCropNInAGrBiomassObservations_valueChanged()
{
  updateSVCropNInAGrBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropNInAGrBiomassWeightPts_valueChanged()
{
  updateSVCropNInAGrBiomassRatingLbl();
}
void MadDataClassification::on_dsbSVCropNInAGrBiomassReplicates_valueChanged()
{
  updateSVCropNInAGrBiomassRatingLbl();
}

void MadDataClassification::on_dsbSVCropNInOrgansLayers_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}
void MadDataClassification::on_sbSVCropNInOrgansObservations_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}
void MadDataClassification::on_dsbSVCropNInOrgansWeightPts_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}
void MadDataClassification::on_dsbSVCropNInOrgansReplicates_valueChanged()
{
  updateSVCropNInOrgansRatingLbl();
}

void MadDataClassification::on_dsbSVCropLAILayers_valueChanged()
{
  updateSVCropLAIRatingLbl();
}
void MadDataClassification::on_sbSVCropLAIObservations_valueChanged()
{
  updateSVCropLAIRatingLbl();
}
void MadDataClassification::on_dsbSVCropLAIWeightPts_valueChanged()
{
  updateSVCropLAIRatingLbl();
}
void MadDataClassification::on_dsbSVCropLAIReplicates_valueChanged()
{
  updateSVCropLAIRatingLbl();
}

// SV soil tab (spin box changes)
void MadDataClassification::on_dsbSVSoilSoilWaterGravLayers_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}
void MadDataClassification::on_sbSVSoilSoilWaterGravObservations_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}
void MadDataClassification::on_dsbSVSoilSoilWaterGravWeightPts_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}
void MadDataClassification::on_dsbSVSoilSoilWaterGravReplicates_valueChanged()
{
  updateSVSoilSoilWaterGravRatingLbl();
}

void MadDataClassification::on_dsbSVSoilPressureHeadsLayers_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}
void MadDataClassification::on_sbSVSoilPressureHeadsObservations_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}
void MadDataClassification::on_dsbSVSoilPressureHeadsWeightPts_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}
void MadDataClassification::on_dsbSVSoilPressureHeadsReplicates_valueChanged()
{
  updateSVSoilPressureHeadsRatingLbl();
}

void MadDataClassification::on_dsbSVSoilNMinLayers_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}
void MadDataClassification::on_sbSVSoilNMinObservations_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}
void MadDataClassification::on_dsbSVSoilNMinWeightPts_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}
void MadDataClassification::on_dsbSVSoilNMinReplicates_valueChanged()
{
  updateSVSoilNMinRatingLbl();
}

void MadDataClassification::on_dsbSVSoilSoilWaterSensorCalLayers_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}
void MadDataClassification::on_sbSVSoilSoilWaterSensorCalObservations_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}
void MadDataClassification::on_dsbSVSoilSoilWaterSensorCalWeightPts_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}
void MadDataClassification::on_dsbSVSoilSoilWaterSensorCalReplicates_valueChanged()
{
  updateSVSoilSoilWaterSensorCalRatingLbl();
}

void MadDataClassification::on_dsbSVSoilWaterFluxBottomRootLayers_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}
void MadDataClassification::on_sbSVSoilWaterFluxBottomRootObservations_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}
void MadDataClassification::on_dsbSVSoilWaterFluxBottomRootWeightPts_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}
void MadDataClassification::on_dsbSVSoilWaterFluxBottomRootReplicates_valueChanged()
{
  updateSVSoilWaterFluxBottomRootRatingLbl();
}

void MadDataClassification::on_dsbSVSoilNFluxBottomRootLayers_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}
void MadDataClassification::on_sbSVSoilNFluxBottomRootObservations_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}
void MadDataClassification::on_dsbSVSoilNFluxBottomRootWeightPts_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}
void MadDataClassification::on_dsbSVSoilNFluxBottomRootReplicates_valueChanged()
{
  updateSVSoilNFluxBottomRootRatingLbl();
}

// SV surface fluxes tab (spin box changes)
void MadDataClassification::on_dsbSVSurfaceFluxesEtLayers_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesEtObservations_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesEtWeightPts_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesEtReplicates_valueChanged()
{
  updateSVSurfaceFluxesEtRatingLbl();
}

void MadDataClassification::on_dsbSVSurfaceFluxesNh3LossLayers_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesNh3LossObservations_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesNh3LossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesNh3LossReplicates_valueChanged()
{
  updateSVSurfaceFluxesNh3LossRatingLbl();
}

void MadDataClassification::on_dsbSVSurfaceFluxesN2OLossLayers_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesN2OLossObservations_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesN2OLossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesN2OLossReplicates_valueChanged()
{
  updateSVSurfaceFluxesN2OLossRatingLbl();
}

void MadDataClassification::on_dsbSVSurfaceFluxesN2LossLayers_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesN2LossObservations_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesN2LossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesN2LossReplicates_valueChanged()
{
  updateSVSurfaceFluxesN2LossRatingLbl();
}

void MadDataClassification::on_dsbSVSurfaceFluxesCh4LossLayers_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}
void MadDataClassification::on_sbSVSurfaceFluxesCh4LossObservations_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesCh4LossWeightPts_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}
void MadDataClassification::on_dsbSVSurfaceFluxesCh4LossReplicates_valueChanged()
{
  updateSVSurfaceFluxesCh4LossRatingLbl();
}

// SV observations tab (spin box changes)
void MadDataClassification::on_dsbSVObservationsLodgingLayers_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}
void MadDataClassification::on_sbSVObservationsLodgingObservations_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsLodgingWeightPts_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsLodgingReplicates_valueChanged()
{
  updateSVObservationsLodgingRatingLbl();
}

void MadDataClassification::on_dsbSVObservationsPestsOrDiseasesLayers_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}
void MadDataClassification::on_sbSVObservationsPestsOrDiseasesObservations_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsPestsOrDiseasesWeightPts_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsPestsOrDiseasesReplicates_valueChanged()
{
  updateSVObservationsPestsOrDiseasesRatingLbl();
}

void MadDataClassification::on_dsbSVObservationsDamagesLayers_valueChanged()
{
  updateSVObservationsDamagesRatingLbl();
}
void MadDataClassification::on_sbSVObservationsDamagesObservations_valueChanged()
{
  updateSVObservationsDamagesRatingLbl();
}
void MadDataClassification::on_dsbSVObservationsDamagesWeightPts_valueChanged()
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
// management tab (label updates (with calcs))
void MadDataClassification::updateVarietyRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbVariety->value();
  float myGivenWeighting = dsbVariety->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblVarietyRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateSowingRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSowing->value();
  float myGivenWeighting = dsbSowing->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSowingRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateHarvestRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbHarvest->value();
  float myGivenWeighting = dsbHarvest->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblHarvestRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateFertilisationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbFertilisation->value();
  float myGivenWeighting = dsbFertilisation->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblFertilisationRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateIrrigationRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbIrrigation->value();
  float myGivenWeighting = dsbIrrigation->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblIrrigationRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateSeedDensityRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSeedDensity->value();
  float myGivenWeighting = dsbSeedDensity->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSeedDensityRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateYieldRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbYield->value();
  float myGivenWeighting = dsbYield->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblYieldRating->setText(myText);
  updateManagementLabels();
}
void MadDataClassification::updateTillageRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbTillage->value();
  float myGivenWeighting = dsbTillage->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblTillageRating->setText(myText);
  updateManagementLabels();
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
  float myGivenWeighting = dsbSVCropAGrBiomassWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropAGrBiomassPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropWeightOrgansRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropWeightOrgansObservations->value();
  float myGivenWeighting = dsbSVCropWeightOrgansWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropWeightOrgansPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropRootBiomassRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropRootBiomassObservations->value();
  float myGivenWeighting = dsbSVCropRootBiomassWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropRootBiomassPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropNInAGrBiomassRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropNInAGrBiomassObservations->value();
  float myGivenWeighting = dsbSVCropNInAGrBiomassWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropNInAGrBiomassPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropNInOrgansRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropNInOrgansObservations->value();
  float myGivenWeighting = dsbSVCropNInOrgansWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVCropNInOrgansPoints->setText(myText);
  updateSVCropLabels();
}
void MadDataClassification::updateSVCropLAIRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVCropLAIObservations->value();
  float myGivenWeighting = dsbSVCropLAIWeightPts->value();
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
  float myGivenWeighting = dsbSVSoilSoilWaterGravWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilSoilWaterGravPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilPressureHeadsRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilPressureHeadsObservations->value();
  float myGivenWeighting = dsbSVSoilPressureHeadsWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilPressureHeadsPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilNMinRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilNMinObservations->value();
  float myGivenWeighting = dsbSVSoilNMinWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilNMinPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilSoilWaterSensorCalRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilSoilWaterSensorCalObservations->value();
  float myGivenWeighting = dsbSVSoilSoilWaterSensorCalWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilSoilWaterSensorCalPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilWaterFluxBottomRootRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilWaterFluxBottomRootObservations->value();
  float myGivenWeighting = dsbSVSoilWaterFluxBottomRootWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSoilWaterFluxBottomRootPoints->setText(myText);
  updateSVSoilLabels();
}
void MadDataClassification::updateSVSoilNFluxBottomRootRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSoilNFluxBottomRootObservations->value();
  float myGivenWeighting = dsbSVSoilNFluxBottomRootWeightPts->value();
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
  float myGivenWeighting = dsbSVSurfaceFluxesEtWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesEtPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesNh3LossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesNh3LossObservations->value();
  float myGivenWeighting = dsbSVSurfaceFluxesNh3LossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesNh3LossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesN2OLossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesN2OLossObservations->value();
  float myGivenWeighting = dsbSVSurfaceFluxesN2OLossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesN2OLossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesN2LossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesN2LossObservations->value();
  float myGivenWeighting = dsbSVSurfaceFluxesN2LossWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVSurfaceFluxesN2LossPoints->setText(myText);
  updateSVSurfaceFluxesLabels();
}
void MadDataClassification::updateSVSurfaceFluxesCh4LossRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVSurfaceFluxesCh4LossObservations->value();
  float myGivenWeighting = dsbSVSurfaceFluxesCh4LossWeightPts->value();
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
  float myGivenWeighting = dsbSVObservationsLodgingWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVObservationsLodgingPoints->setText(myText);
  updateSVObservationsLabels();
}
void MadDataClassification::updateSVObservationsPestsOrDiseasesRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVObservationsPestsOrDiseasesObservations->value();
  float myGivenWeighting = dsbSVObservationsPestsOrDiseasesWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVObservationsPestsOrDiseasesPoints->setText(myText);
  updateSVObservationsLabels();
}
void MadDataClassification::updateSVObservationsDamagesRatingLbl()
{
  // calculate weight and update the label
  int myObservations = sbSVObservationsDamagesObservations->value();
  float myGivenWeighting = dsbSVObservationsDamagesWeightPts->value();
  float myWeight = myObservations * myGivenWeighting;
  QString myText = makeString(myWeight);
  lblSVObservationsDamagesPoints->setText(myText);
  updateSVObservationsLabels();
}


   //-------------------------------------//
  //  Update ranking labels and pixmaps  //
 //-------------------------------------//
// management (ranking labels and pixmaps)
void MadDataClassification::updateManagementLabels()
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
    case 24: lblMedalManagement->setVisible(true);
             lblMedalManagement->setScaledContents(true);
             lblMedalManagement->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingManagement->setVisible(true);
             lblRankingManagement->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(0, (QIcon( ":platinum.png")));

      break;

    case 23: lblMedalManagement->setVisible(true);
             lblMedalManagement->setScaledContents(true);
             lblMedalManagement->setPixmap(QPixmap( ":gold.png" ));
             lblRankingManagement->setVisible(true);
             lblRankingManagement->setText("Gold");
             tabWidgetDataClassification->setTabIcon(0, (QIcon( ":gold.png")));

      break;

    case 22: lblMedalManagement->setVisible(true);
             lblMedalManagement->setScaledContents(true);
             lblMedalManagement->setPixmap(QPixmap( ":silver.png" ));
             lblRankingManagement->setVisible(true);
             lblRankingManagement->setText("Silver");
             tabWidgetDataClassification->setTabIcon(0, (QIcon( ":silver.png")));

      break;

    case 21: lblMedalManagement->setVisible(true);
             lblMedalManagement->setScaledContents(true);
             lblMedalManagement->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingManagement->setVisible(true);
             lblRankingManagement->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(0, (QIcon( ":bronze.png")));

      break;

    default: // hide
             lblRankingManagement->setVisible(false);
             lblMedalManagement->setVisible(false);
             tabWidgetDataClassification->setTabIcon(0, (QIcon()));

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
  if (myTotal >= 14) myRank=14;
  else if (myTotal >= 14) myRank=14;
  else if (myTotal >= 11) myRank=11;
  else if (myTotal >= 8) myRank=8;

  switch (myRank)
  {
    case 14: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(1, (QIcon( ":platinum.png")));

      break;

    case 11: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":gold.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Gold");
             tabWidgetDataClassification->setTabIcon(1, (QIcon( ":gold.png")));
      break;

    case 10: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":silver.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Silver");
             tabWidgetDataClassification->setTabIcon(1, (QIcon( ":silver.png")));
      break;

    case 8: lblMedalPhenology->setVisible(true);
             lblMedalPhenology->setScaledContents(true);
             lblMedalPhenology->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingPhenology->setVisible(true);
             lblRankingPhenology->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(1, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingPhenology->setVisible(false);
             lblMedalPhenology->setVisible(false);
             tabWidgetDataClassification->setTabIcon(1, (QIcon()));
      break;
  }
}

// prev crop tab (ranking labels and pixmaps)
void MadDataClassification::updatePrevCropLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblCropRatingPrevCrop->text().toFloat();
  myTotal += lblSowingDateRatingPrevCrop->text().toFloat();
  myTotal += lblHarvestDateRatingPrevCrop->text().toFloat();
  myTotal += lblYieldRatingPrevCrop->text().toFloat();
  myTotal += lblResidueMgmtRatingPrevCrop->text().toFloat();
  myTotal += lblFertilisationRatingPrevCrop->text().toFloat();
  myTotal += lblIrrigationRatingPrevCrop->text().toFloat();
  lblOverallRatingPrevCrop->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 11) myRank=11;
  else if (myTotal >= 10) myRank=10;
  else if (myTotal >= 8) myRank=8;
  else if (myTotal >= 5) myRank=5;

  switch (myRank)
  {
    case 11: lblMedalPrevCrop->setVisible(true);
             lblMedalPrevCrop->setScaledContents(true);
             lblMedalPrevCrop->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingPrevCrop->setVisible(true);
             lblRankingPrevCrop->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(2, (QIcon( ":platinum.png")));
      break;

    case 12: lblMedalPrevCrop->setVisible(true);
             lblMedalPrevCrop->setScaledContents(true);
             lblMedalPrevCrop->setPixmap(QPixmap( ":gold.png" ));
             lblRankingPrevCrop->setVisible(true);
             lblRankingPrevCrop->setText("Gold");
             tabWidgetDataClassification->setTabIcon(2, (QIcon( ":gold.png")));
      break;

    case 10: lblMedalPrevCrop->setVisible(true);
             lblMedalPrevCrop->setScaledContents(true);
             lblMedalPrevCrop->setPixmap(QPixmap( ":silver.png" ));
             lblRankingPrevCrop->setVisible(true);
             lblRankingPrevCrop->setText("Silver");
             tabWidgetDataClassification->setTabIcon(2, (QIcon( ":silver.png")));
      break;

    case 8: lblMedalPrevCrop->setVisible(true);
             lblMedalPrevCrop->setScaledContents(true);
             lblMedalPrevCrop->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingPrevCrop->setVisible(true);
             lblRankingPrevCrop->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(2, (QIcon( ":bronze.png")));

      break;

    default: // hide
             lblRankingPrevCrop->setVisible(false);
             lblMedalPrevCrop->setVisible(false);
             tabWidgetDataClassification->setTabIcon(2, (QIcon()));
      break;
  }
}

// initial values tab (ranking labels and pixmaps)
void MadDataClassification::updateInitialValuesLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblSoilMoistureRatingInitialValues->text().toFloat();
  myTotal += lblNMinRatingInitialValues->text().toFloat();
  lblOverallRatingInitialValues->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 8) myRank=8;
  else if (myTotal >= 7) myRank=7;
  else if (myTotal >= 6) myRank=6;
  else if (myTotal >= 4) myRank=4;

  switch (myRank)
  {
    case 8: lblMedalInitialValues->setVisible(true);
             lblMedalInitialValues->setScaledContents(true);
             lblMedalInitialValues->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingInitialValues->setVisible(true);
             lblRankingInitialValues->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(3, (QIcon( ":platinum.png")));
      break;

    case 7: lblMedalInitialValues->setVisible(true);
             lblMedalInitialValues->setScaledContents(true);
             lblMedalInitialValues->setPixmap(QPixmap( ":gold.png" ));
             lblRankingInitialValues->setVisible(true);
             lblRankingInitialValues->setText("Gold");
             tabWidgetDataClassification->setTabIcon(3, (QIcon( ":gold.png")));
      break;

    case 6: lblMedalInitialValues->setVisible(true);
             lblMedalInitialValues->setScaledContents(true);
             lblMedalInitialValues->setPixmap(QPixmap( ":silver.png" ));
             lblRankingInitialValues->setVisible(true);
             lblRankingInitialValues->setText("Silver");
             tabWidgetDataClassification->setTabIcon(3, (QIcon( ":silver.png")));
      break;

    case 4: lblMedalInitialValues->setVisible(true);
             lblMedalInitialValues->setScaledContents(true);
             lblMedalInitialValues->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingInitialValues->setVisible(true);
             lblRankingInitialValues->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(3, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingInitialValues->setVisible(false);
             lblMedalInitialValues->setVisible(false);
             tabWidgetDataClassification->setTabIcon(3, (QIcon()));
      break;
  }
}

// soil tab (ranking labels and pixmaps)
void MadDataClassification::updateSoilLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblCOrgRatingSoil->text().toFloat();
  myTotal += lblNOrgRatingSoil->text().toFloat();
  myTotal += lblTextureRatingSoil->text().toFloat();
  myTotal += lblBulkDensityRatingSoil->text().toFloat();
  myTotal += lblFieldCapacityRatingSoil->text().toFloat();
  myTotal += lblWiltingPointRatingSoil->text().toFloat();
  myTotal += lblPfCurveRatingSoil->text().toFloat();
  myTotal += lblHydrCondCurveRatingSoil->text().toFloat();
  myTotal += lblPhRatingSoil->text().toFloat();
  lblOverallRatingSoil->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 40) myRank=40;
  else if (myTotal >= 29) myRank=29;
  else if (myTotal >= 14) myRank=14;
  else if (myTotal >= 5) myRank=5;

  switch (myRank)
  {
    case 40: lblMedalSoil->setVisible(true);
             lblMedalSoil->setScaledContents(true);
             lblMedalSoil->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingSoil->setVisible(true);
             lblRankingSoil->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(4, (QIcon( ":platinum.png")));
      break;

    case 29: lblMedalSoil->setVisible(true);
             lblMedalSoil->setScaledContents(true);
             lblMedalSoil->setPixmap(QPixmap( ":gold.png" ));
             lblRankingSoil->setVisible(true);
             lblRankingSoil->setText("Gold");
             tabWidgetDataClassification->setTabIcon(4, (QIcon( ":gold.png")));

      break;

    case 14: lblMedalSoil->setVisible(true);
             lblMedalSoil->setScaledContents(true);
             lblMedalSoil->setPixmap(QPixmap( ":silver.png" ));
             lblRankingSoil->setVisible(true);
             lblRankingSoil->setText("Silver");
             tabWidgetDataClassification->setTabIcon(4, (QIcon( ":silver.png")));
      break;

    case 5: lblMedalSoil->setVisible(true);
             lblMedalSoil->setScaledContents(true);
             lblMedalSoil->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingSoil->setVisible(true);
             lblRankingSoil->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(4, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingSoil->setVisible(false);
             lblMedalSoil->setVisible(false);
             tabWidgetDataClassification->setTabIcon(4, (QIcon()));
      break;
  }
}

// site tab (ranking labels and pixmaps)
void MadDataClassification::updateSiteLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblLatitudeRatingSite->text().toFloat();
  myTotal += lblLongitudeRatingSite->text().toFloat();
  myTotal += lblAltitudeRatingSite->text().toFloat();
  lblOverallRatingSite->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 8) myRank=8;
  else if (myTotal >= 7) myRank=7;
  else if (myTotal >= 6) myRank=6;
  else if (myTotal >= 5) myRank=5;

  switch (myRank)
  {
    case 8: lblMedalSite->setVisible(true);
             lblMedalSite->setScaledContents(true);
             lblMedalSite->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingSite->setVisible(true);
             lblRankingSite->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(5, (QIcon( ":platinum.png")));
      break;

    case 9: lblMedalSite->setVisible(true);
             lblMedalSite->setScaledContents(true);
             lblMedalSite->setPixmap(QPixmap( ":gold.png" ));
             lblRankingSite->setVisible(true);
             lblRankingSite->setText("Gold");
             tabWidgetDataClassification->setTabIcon(5, (QIcon( ":gold.png")));
      break;

    case 10: lblMedalSite->setVisible(true);
             lblMedalSite->setScaledContents(true);
             lblMedalSite->setPixmap(QPixmap( ":silver.png" ));
             lblRankingSite->setVisible(true);
             lblRankingSite->setText("Silver");
             tabWidgetDataClassification->setTabIcon(5, (QIcon( ":silver.png")));
      break;

    case 11: lblMedalSite->setVisible(true);
             lblMedalSite->setScaledContents(true);
             lblMedalSite->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingSite->setVisible(true);
             lblRankingSite->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(5, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingSite->setVisible(false);
             lblMedalSite->setVisible(false);
             tabWidgetDataClassification->setTabIcon(5, (QIcon()));
      break;
  }
}

// weather tab (ranking labels and pixmaps)
void MadDataClassification::updateWeatherLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblPrecipitationRatingWeather->text().toFloat();
  myTotal += lblTAveRatingWeather->text().toFloat();
  myTotal += lblTMinRatingWeather->text().toFloat();
  myTotal += lblTMaxRatingWeather->text().toFloat();
  myTotal += lblRelHumidityRatingWeather->text().toFloat();
  myTotal += lblWindSpeedRatingWeather->text().toFloat();
  myTotal += lblGlobalRadiationRatingWeather->text().toFloat();
  myTotal += lblSunshineHoursRatingWeather->text().toFloat();
  myTotal += lblLeafWetnessRatingWeather->text().toFloat();
  myTotal += lblSoilTempRatingWeather->text().toFloat();
  lblOverallRatingWeather->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 30) myRank=30;
  else if (myTotal >= 20) myRank=20;
  else if (myTotal >= 10) myRank=10;
  else if (myTotal >= 5) myRank=5;

  switch (myRank)
  {
    case 30: lblMedalWeather->setVisible(true);
             lblMedalWeather->setScaledContents(true);
             lblMedalWeather->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingWeather->setVisible(true);
             lblRankingWeather->setText("Platinum");
             tabWidgetDataClassification->setTabIcon(6, (QIcon( ":platinum.png")));
      break;

    case 99: lblMedalWeather->setVisible(true);
             lblMedalWeather->setScaledContents(true);
             lblMedalWeather->setPixmap(QPixmap( ":gold.png" ));
             lblRankingWeather->setVisible(true);
             lblRankingWeather->setText("Gold");
             tabWidgetDataClassification->setTabIcon(6, (QIcon( ":gold.png")));

      break;

    case 20: lblMedalWeather->setVisible(true);
             lblMedalWeather->setScaledContents(true);
             lblMedalWeather->setPixmap(QPixmap( ":silver.png" ));
             lblRankingWeather->setVisible(true);
             lblRankingWeather->setText("Silver");
             tabWidgetDataClassification->setTabIcon(6, (QIcon( ":silver.png")));

      break;

    case 10: lblMedalWeather->setVisible(true);
             lblMedalWeather->setScaledContents(true);
             lblMedalWeather->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingWeather->setVisible(true);
             lblRankingWeather->setText("Bronze");
             tabWidgetDataClassification->setTabIcon(6, (QIcon( ":bronze.png")));

      break;

    default: // hide
             lblRankingWeather->setVisible(false);
             lblMedalWeather->setVisible(false);
             tabWidgetDataClassification->setTabIcon(6, (QIcon()));

      break;
  }
}

// SV crop tab (ranking labels and pixmaps)
void MadDataClassification::updateSVCropLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblSVCropAGrBiomassPoints->text().toFloat();
  myTotal += lblSVCropWeightOrgansPoints->text().toFloat();
  myTotal += lblSVCropRootBiomassPoints->text().toFloat();
  myTotal += lblSVCropNInAGrBiomassPoints->text().toFloat();
  myTotal += lblSVCropNInOrgansPoints->text().toFloat();
  myTotal += lblSVCropLAIPoints->text().toFloat();
  lblOverallRatingSVCrop->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 24) myRank=24;
  else if (myTotal >= 23) myRank=23;
  else if (myTotal >= 22) myRank=22;
  else if (myTotal >= 21) myRank=21;

  switch (myRank)
  {
    case 24: lblMedalSVCrop->setVisible(true);
             lblMedalSVCrop->setScaledContents(true);
             lblMedalSVCrop->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingSVCrop->setVisible(true);
             lblRankingSVCrop->setText("Platinum");
             //tabWidgetDataClassification->tab setTabIcon(7, (QIcon( ":platinum.png")));
             toolBoxStateVars->setItemIcon(0, (QIcon( ":platinum.png")));
      break;

    case 23: lblMedalSVCrop->setVisible(true);
             lblMedalSVCrop->setScaledContents(true);
             lblMedalSVCrop->setPixmap(QPixmap( ":gold.png" ));
             lblRankingSVCrop->setVisible(true);
             lblRankingSVCrop->setText("Gold");
             toolBoxStateVars->setItemIcon(0, (QIcon( ":gold.png")));
      break;

    case 22: lblMedalSVCrop->setVisible(true);
             lblMedalSVCrop->setScaledContents(true);
             lblMedalSVCrop->setPixmap(QPixmap( ":silver.png" ));
             lblRankingSVCrop->setVisible(true);
             lblRankingSVCrop->setText("Silver");
             toolBoxStateVars->setItemIcon(0, (QIcon( ":silver.png")));
      break;

    case 21: lblMedalSVCrop->setVisible(true);
             lblMedalSVCrop->setScaledContents(true);
             lblMedalSVCrop->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingSVCrop->setVisible(true);
             lblRankingSVCrop->setText("Bronze");
             toolBoxStateVars->setItemIcon(0, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingSVCrop->setVisible(false);
             lblMedalSVCrop->setVisible(false);
             toolBoxStateVars->setItemIcon(0, (QIcon()));
      break;
  }
}

// SV soil tab (ranking labels and pixmaps)
void MadDataClassification::updateSVSoilLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblSVSoilSoilWaterGravPoints->text().toFloat();
  myTotal += lblSVSoilPressureHeadsPoints->text().toFloat();
  myTotal += lblSVSoilNMinPoints->text().toFloat();
  myTotal += lblSVSoilSoilWaterSensorCalPoints->text().toFloat();
  myTotal += lblSVSoilWaterFluxBottomRootPoints->text().toFloat();
  myTotal += lblSVSoilNFluxBottomRootPoints->text().toFloat();
  lblOverallRatingSVSoil->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 24) myRank=24;
  else if (myTotal >= 23) myRank=23;
  else if (myTotal >= 22) myRank=22;
  else if (myTotal >= 21) myRank=21;

  switch (myRank)
  {
    case 24: lblMedalSVSoil->setVisible(true);
             lblMedalSVSoil->setScaledContents(true);
             lblMedalSVSoil->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingSVSoil->setVisible(true);
             lblRankingSVSoil->setText("Platinum");
             toolBoxStateVars->setItemIcon(1, (QIcon( ":platinum.png")));
      break;

    case 23: lblMedalSVSoil->setVisible(true);
             lblMedalSVSoil->setScaledContents(true);
             lblMedalSVSoil->setPixmap(QPixmap( ":gold.png" ));
             lblRankingSVSoil->setVisible(true);
             lblRankingSVSoil->setText("Gold");
             toolBoxStateVars->setItemIcon(1, (QIcon( ":gold.png")));
      break;

    case 22: lblMedalSVSoil->setVisible(true);
             lblMedalSVSoil->setScaledContents(true);
             lblMedalSVSoil->setPixmap(QPixmap( ":silver.png" ));
             lblRankingSVSoil->setVisible(true);
             lblRankingSVSoil->setText("Silver");
             toolBoxStateVars->setItemIcon(1, (QIcon( ":silver.png")));
      break;

    case 21: lblMedalSVSoil->setVisible(true);
             lblMedalSVSoil->setScaledContents(true);
             lblMedalSVSoil->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingSVSoil->setVisible(true);
             lblRankingSVSoil->setText("Bronze");
             toolBoxStateVars->setItemIcon(1, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingSVSoil->setVisible(false);
             lblMedalSVSoil->setVisible(false);
             toolBoxStateVars->setItemIcon(1, (QIcon()));
      break;
  }
}

// SV surface fluxes tab (ranking labels and pixmaps)
void MadDataClassification::updateSVSurfaceFluxesLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblSVSurfaceFluxesEtPoints->text().toFloat();
  myTotal += lblSVSurfaceFluxesNh3LossPoints->text().toFloat();
  myTotal += lblSVSurfaceFluxesN2OLossPoints->text().toFloat();
  myTotal += lblSVSurfaceFluxesN2LossPoints->text().toFloat();
  myTotal += lblSVSurfaceFluxesCh4LossPoints->text().toFloat();
  lblOverallRatingSVSurfaceFluxes->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 24) myRank=24;
  else if (myTotal >= 23) myRank=23;
  else if (myTotal >= 22) myRank=22;
  else if (myTotal >= 21) myRank=21;

  switch (myRank)
  {
    case 24: lblMedalSVSurfaceFluxes->setVisible(true);
             lblMedalSVSurfaceFluxes->setScaledContents(true);
             lblMedalSVSurfaceFluxes->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingSVSurfaceFluxes->setVisible(true);
             lblRankingSVSurfaceFluxes->setText("Platinum");
             toolBoxStateVars->setItemIcon(2, (QIcon( ":platinum.png")));
      break;

    case 23: lblMedalSVSurfaceFluxes->setVisible(true);
             lblMedalSVSurfaceFluxes->setScaledContents(true);
             lblMedalSVSurfaceFluxes->setPixmap(QPixmap( ":gold.png" ));
             lblRankingSVSurfaceFluxes->setVisible(true);
             lblRankingSVSurfaceFluxes->setText("Gold");
             toolBoxStateVars->setItemIcon(2, (QIcon( ":gold.png")));
      break;

    case 22: lblMedalSVSurfaceFluxes->setVisible(true);
             lblMedalSVSurfaceFluxes->setScaledContents(true);
             lblMedalSVSurfaceFluxes->setPixmap(QPixmap( ":silver.png" ));
             lblRankingSVSurfaceFluxes->setVisible(true);
             lblRankingSVSurfaceFluxes->setText("Silver");
             toolBoxStateVars->setItemIcon(2, (QIcon( ":silver.png")));
      break;

    case 21: lblMedalSVSurfaceFluxes->setVisible(true);
             lblMedalSVSurfaceFluxes->setScaledContents(true);
             lblMedalSVSurfaceFluxes->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingSVSurfaceFluxes->setVisible(true);
             lblRankingSVSurfaceFluxes->setText("Bronze");
             toolBoxStateVars->setItemIcon(2, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingSVSurfaceFluxes->setVisible(false);
             lblMedalSVSurfaceFluxes->setVisible(false);
             toolBoxStateVars->setItemIcon(2, (QIcon()));
      break;
  }
}

// SV observations tab (ranking labels and pixmaps)
void MadDataClassification::updateSVObservationsLabels()
{
  // updates totals
  float myTotal = 0.0;
  //QPixmap pixmap;
  myTotal += lblSVObservationsLodgingPoints->text().toFloat();
  myTotal += lblSVObservationsPestsOrDiseasesPoints->text().toFloat();
  myTotal += lblSVObservationsDamagesPoints->text().toFloat();
  lblOverallRatingSVObservations->setText(makeString(myTotal));
  int myRank = 0;
  if (myTotal >= 24) myRank=24;
  else if (myTotal >= 23) myRank=23;
  else if (myTotal >= 22) myRank=22;
  else if (myTotal >= 21) myRank=21;

  switch (myRank)
  {
    case 24: lblMedalSVObservations->setVisible(true);
             lblMedalSVObservations->setScaledContents(true);
             lblMedalSVObservations->setPixmap(QPixmap( ":platinum.png" ));
             lblRankingSVObservations->setVisible(true);
             lblRankingSVObservations->setText("Platinum");
             toolBoxStateVars->setItemIcon(3, (QIcon( ":platinum.png")));
      break;

    case 23: lblMedalSVObservations->setVisible(true);
             lblMedalSVObservations->setScaledContents(true);
             lblMedalSVObservations->setPixmap(QPixmap( ":gold.png" ));
             lblRankingSVObservations->setVisible(true);
             lblRankingSVObservations->setText("Gold");
             toolBoxStateVars->setItemIcon(3, (QIcon( ":gold.png")));
      break;

    case 22: lblMedalSVObservations->setVisible(true);
             lblMedalSVObservations->setScaledContents(true);
             lblMedalSVObservations->setPixmap(QPixmap( ":silver.png" ));
             lblRankingSVObservations->setVisible(true);
             lblRankingSVObservations->setText("Silver");
             toolBoxStateVars->setItemIcon(3, (QIcon( ":silver.png")));
      break;

    case 21: lblMedalSVObservations->setVisible(true);
             lblMedalSVObservations->setScaledContents(true);
             lblMedalSVObservations->setPixmap(QPixmap( ":bronze.png" ));
             lblRankingSVObservations->setVisible(true);
             lblRankingSVObservations->setText("Bronze");
             toolBoxStateVars->setItemIcon(3, (QIcon( ":bronze.png")));
      break;

    default: // hide
             lblRankingSVObservations->setVisible(false);
             lblMedalSVObservations->setVisible(false);
             toolBoxStateVars->setItemIcon(3, (QIcon()));
      break;
  }
}


   //-------------------//
  //  Saving the form  //
 //-------------------//
//  when save button is pressed, it gets converted to xml here
void MadDataClassification::on_pbSave_clicked()
{
  // save current settings for phenology to xml file

  // first we have to get the values
  // initialise variables
  MadDataset myDataset;
  MadDataClassificationManagement myManagement;
  MadDataClassificationPhenology myPhenology;
  MadDataClassificationPrevCrop myPrevCrop;
  MadDataClassificationInitialValues myInitialValues;
  MadDataClassificationSoil mySoil;
  MadDataClassificationSiteData mySite;
  MadDataClassificationWeather myWeather;
  MadStateVars mySV;
  MadSVCrop mySVCrop;
  MadSVSoil mySVSoil;
  MadSVSurfaceFluxes mySVSurfaceFluxes;
  MadSVObservations mySVObservations;

  // dataset (initialise variables)
  QString mName;// = leDatasetName->text();
  QString mDescription; // = leDescription->text();

  // management (initialise variables)
  MadSubCategory myCultVariety;
  MadSubCategory myCultSowing;
  MadSubCategory myCultHarvest;
  MadSubCategory myCultFertilisation;
  MadSubCategory myCultIrrigation;
  MadSubCategory myCultSeedDensity;
  MadSubCategory myCultYield;
  MadSubCategory myCultTillage;

  // phenology (initialise variables)
  MadSubCategory myPhenologyEmergence;
  MadSubCategory myPhenologyStemElongation;
  MadSubCategory myPhenologyEarEmergence;
  MadSubCategory myPhenologyFlowering;
  MadSubCategory myPhenologyYellowRipeness;

  // prev crop (initialise variables)
  MadSubCategory myPrevCropCrop;
  MadSubCategory myPrevCropSowingDate;
  MadSubCategory myPrevCropHarvestDate;
  MadSubCategory myPrevCropYield;
  MadSubCategory myPrevCropResidueMgmt;
  MadSubCategory myPrevCropFertilisation;
  MadSubCategory myPrevCropIrrigation;

  //initial values (initialise variables)
  MadSubCategory myInitialValuesSoilMoisture;
  MadSubCategory myInitialValuesNMin;

  // soil (initialise variables)
  MadSubCategory mySoilCOrg;
  MadSubCategory mySoilNOrg;
  MadSubCategory mySoilTexture;
  MadSubCategory mySoilBulkDensity;
  MadSubCategory mySoilFieldCapacity;
  MadSubCategory mySoilWiltingPoint;
  MadSubCategory mySoilPfCurve;
  MadSubCategory mySoilHydrCondCurve;
  MadSubCategory mySoilPh;

  // site (initialise variables)
  MadSubCategory mySiteLatitude;
  MadSubCategory mySiteLongitude;
  MadSubCategory mySiteAltitude;

  //weather (initialise variables)
  MadSubCategory myWeatherPrecipitation;
  MadSubCategory myWeatherTAve;
  MadSubCategory myWeatherTMin;
  MadSubCategory myWeatherTMax;
  MadSubCategory myWeatherRelHumidity;
  MadSubCategory myWeatherWindSpeed;
  MadSubCategory myWeatherGlobalRadiation;
  MadSubCategory myWeatherSunshineHours;
  MadSubCategory myWeatherLeafWetness;
  MadSubCategory myWeatherSoilTemp;


  //state vars - soil (initialise variables)
  MadSubCategory mySVSoilSoilWaterGrav;
  MadSubCategory mySVSoilPressureHeads;
  MadSubCategory mySVSoilNMin;
  MadSubCategory mySVSoilSoilWaterSensorCal;
  MadSubCategory mySVSoilWaterFluxBottomRoot;
  MadSubCategory mySVSoilNFluxBottomRoot;

  // state vars - crop (initialise variables)
  MadSubCategory mySVCropAGrBiomass;
  MadSubCategory mySVCropWeightOrgans;
  MadSubCategory mySVCropRootBiomass;
  MadSubCategory mySVCropNInAGrBiomass;
  MadSubCategory mySVCropNInOrgans;
  MadSubCategory mySVCropLAI;

  // state vars - surface fluxes (initialise variables)
  MadSubCategory mySVSurfaceFluxesEt;
  MadSubCategory mySVSurfaceFluxesNh3Loss;
  MadSubCategory mySVSurfaceFluxesN2OLoss;
  MadSubCategory mySVSurfaceFluxesN2Loss;
  MadSubCategory mySVSurfaceFluxesCh4Loss;

  // state vars - observation data (initialise variables)
  MadSubCategory mySVObservationsLodging;
  MadSubCategory mySVObservationsPestsOrDiseases;
  MadSubCategory mySVObservationsDamages;

     //------------------------------//
    //get the values from the form  //
   //------------------------------//

  // Dataset
  myDataset.setName(leDatasetName->text());
  myDataset.setDescription(leDescription->text());


  //
  // Management - set the values from form
  //

  // variety (set values from form)
  myCultVariety.setMinData(chbxVariety->isChecked());
  myCultVariety.setDepth(0);
  myCultVariety.setWeightPoints(dsbVariety->value());
  myCultVariety.setObservations(sbVariety->value());
  myCultVariety.setReplicates(0);
  // sowing (set values from form)
  myCultSowing.setMinData(chbxSowing->isChecked());
  myCultSowing.setDepth(0);
  myCultSowing.setWeightPoints(dsbSowing->value());
  myCultSowing.setObservations(sbSowing->value());
  myCultSowing.setReplicates(0);
  // harvest (set values from form)
  myCultHarvest.setMinData(chbxHarvest->isChecked());
  myCultHarvest.setDepth(0);
  myCultHarvest.setWeightPoints(dsbHarvest->value());
  myCultHarvest.setObservations(sbHarvest->value());
  myCultHarvest.setReplicates(0);
  // fertilisation (set values from form)
  myCultFertilisation.setMinData(chbxFertilisation->isChecked());
  myCultFertilisation.setDepth(0);
  myCultFertilisation.setWeightPoints(dsbFertilisation->value());
  myCultFertilisation.setObservations(sbFertilisation->value());
  myCultFertilisation.setReplicates(0);
  // irrigation (set values from form)
  myCultIrrigation.setMinData(chbxIrrigation->isChecked());
  myCultIrrigation.setDepth(0);
  myCultIrrigation.setWeightPoints(dsbIrrigation->value());
  myCultIrrigation.setObservations(sbIrrigation->value());
  myCultIrrigation.setReplicates(0);
  // seed density (set values from form)
  myCultSeedDensity.setMinData(chbxSeedDensity->isChecked());
  myCultSeedDensity.setDepth(0);
  myCultSeedDensity.setWeightPoints(dsbSeedDensity->value());
  myCultSeedDensity.setObservations(sbSeedDensity->value());
  myCultSeedDensity.setReplicates(0);
  // yield (set values from form)
  myCultYield.setMinData(chbxYield->isChecked());
  myCultYield.setDepth(0);
  myCultYield.setWeightPoints(dsbYield->value());
  myCultYield.setObservations(sbYield->value());
  myCultYield.setReplicates(0);
  // tillage (set values from form)
  myCultYield.setMinData(chbxTillage->isChecked());
  myCultTillage.setDepth(0);
  myCultTillage.setWeightPoints(dsbTillage->value());
  myCultTillage.setObservations(sbTillage->value());
  myCultTillage.setReplicates(0);

  //
  // Phenology set values from form
  //

  // emergence (set values from form)
  myPhenologyEmergence.setMinData(chbxEmergencePhenology->isChecked());
  myPhenologyEmergence.setDepth(0);
  myPhenologyEmergence.setWeightPoints(dsbEmergencePhenology->value());
  myPhenologyEmergence.setObservations(sbEmergencePhenology->value());
  myPhenologyEmergence.setReplicates(0);
  // stem elongation (set values from form)
  myPhenologyStemElongation.setMinData(chbxStemElongationPhenology->isChecked());
  myPhenologyStemElongation.setDepth(0);
  myPhenologyStemElongation.setWeightPoints(dsbStemElongationPhenology->value());
  myPhenologyStemElongation.setObservations(sbStemElongationPhenology->value());
  myPhenologyStemElongation.setReplicates(0);
  // ear emergence (set values from form)
  myPhenologyEarEmergence.setMinData(chbxEarEmergencePhenology->isChecked());
  myPhenologyEarEmergence.setDepth(0);
  myPhenologyEarEmergence.setWeightPoints(dsbEarEmergencePhenology->value());
  myPhenologyEarEmergence.setObservations(sbEarEmergencePhenology->value());
  myPhenologyEarEmergence.setReplicates(0);
  // flowering (set values from form)
  myPhenologyFlowering.setMinData(chbxFloweringPhenology->isChecked());
  myPhenologyFlowering.setDepth(0);
  myPhenologyFlowering.setWeightPoints(dsbFloweringPhenology->value());
  myPhenologyFlowering.setObservations(sbFloweringPhenology->value());
  myPhenologyFlowering.setReplicates(0);
  // yellow ripeness (set values from form)
  myPhenologyYellowRipeness.setMinData(chbxYellowRipenessPhenology->isChecked());
  myPhenologyYellowRipeness.setDepth(0);
  myPhenologyYellowRipeness.setWeightPoints(dsbYellowRipenessPhenology->value());
  myPhenologyYellowRipeness.setObservations(sbYellowRipenessPhenology->value());
  myPhenologyYellowRipeness.setReplicates(0);

  //
  // PrevCrop set values from form
  //

  // crop (set values from form)
  myPrevCropCrop.setMinData(chbxCropPrevCrop->isChecked());
  myPrevCropCrop.setDepth(0);
  myPrevCropCrop.setWeightPoints(dsbCropPrevCrop->value());
  myPrevCropCrop.setObservations(sbCropPrevCrop->value());
  myPrevCropCrop.setReplicates(0);

  // sowing date (set values from form)
  myPrevCropSowingDate.setMinData(chbxSowingDatePrevCrop->isChecked());
  myPrevCropSowingDate.setDepth(0);
  myPrevCropSowingDate.setWeightPoints(dsbSowingDatePrevCrop->value());
  myPrevCropSowingDate.setObservations(sbSowingDatePrevCrop->value());
  myPrevCropSowingDate.setReplicates(0);

  // harvest date (set values from form)
  myPrevCropHarvestDate.setMinData(chbxHarvestDatePrevCrop->isChecked());
  myPrevCropHarvestDate.setDepth(0);
  myPrevCropHarvestDate.setWeightPoints(dsbHarvestDatePrevCrop->value());
  myPrevCropHarvestDate.setObservations(sbHarvestDatePrevCrop->value());
  myPrevCropHarvestDate.setReplicates(0);

  // yield (set values from form)
  myPrevCropYield.setMinData(chbxYieldPrevCrop->isChecked());
  myPrevCropYield.setDepth(0);
  myPrevCropYield.setWeightPoints(dsbYieldPrevCrop->value());
  myPrevCropYield.setObservations(sbYieldPrevCrop->value());
  myPrevCropYield.setReplicates(0);

  // residue mgmt (set values from form)
  myPrevCropResidueMgmt.setMinData(chbxResidueMgmtPrevCrop->isChecked());
  myPrevCropResidueMgmt.setDepth(0);
  myPrevCropResidueMgmt.setWeightPoints(dsbResidueMgmtPrevCrop->value());
  myPrevCropResidueMgmt.setObservations(sbResidueMgmtPrevCrop->value());
  myPrevCropResidueMgmt.setReplicates(0);

  // fertilisation (set values from form)
  myPrevCropFertilisation.setMinData(chbxFertilisationPrevCrop->isChecked());
  myPrevCropFertilisation.setDepth(0);
  myPrevCropFertilisation.setWeightPoints(dsbFertilisationPrevCrop->value());
  myPrevCropFertilisation.setObservations(sbFertilisationPrevCrop->value());
  myPrevCropFertilisation.setReplicates(0);

  // irrigation (set values from form)
  myPrevCropIrrigation.setMinData(chbxIrrigationPrevCrop->isChecked());
  myPrevCropIrrigation.setDepth(0);
  myPrevCropIrrigation.setWeightPoints(dsbIrrigationPrevCrop->value());
  myPrevCropIrrigation.setObservations(sbIrrigationPrevCrop->value());
  myPrevCropIrrigation.setReplicates(0);


  //
  // Initial Values set values from form
  //

  // soil moisture (set values from form)
  myInitialValuesSoilMoisture.setMinData(chbxSoilMoistureInitialValues->isChecked());
  myInitialValuesSoilMoisture.setDepth(0);
  myInitialValuesSoilMoisture.setWeightPoints(dsbSoilMoistureInitialValues->value());
  myInitialValuesSoilMoisture.setObservations(sbSoilMoistureInitialValues->value());
  myInitialValuesSoilMoisture.setReplicates(0);

  // nitrogen min (set values from form)
  myInitialValuesNMin.setMinData(chbxNMinInitialValues->isChecked());
  myInitialValuesNMin.setDepth(0);
  myInitialValuesNMin.setWeightPoints(dsbNMinInitialValues->value());
  myInitialValuesNMin.setObservations(sbNMinInitialValues->value());
  myInitialValuesNMin.setReplicates(0);


  //
  // Soil set values from form
  //

  // Carbon organic (set values from form)
  mySoilCOrg.setMinData(chbxCOrgSoil->isChecked());
  mySoilCOrg.setDepth(0);
  mySoilCOrg.setWeightPoints(dsbCOrgSoil->value());
  mySoilCOrg.setObservations(sbCOrgSoil->value());
  mySoilCOrg.setReplicates(0);

  // Nitrogen organic (set values from form)
  mySoilNOrg.setMinData(chbxNOrgSoil->isChecked());
  mySoilNOrg.setDepth(0);
  mySoilNOrg.setWeightPoints(dsbNOrgSoil->value());
  mySoilNOrg.setObservations(sbNOrgSoil->value());
  mySoilNOrg.setReplicates(0);

  // texture (set values from form)
  mySoilTexture.setMinData(chbxTextureSoil->isChecked());
  mySoilTexture.setDepth(0);
  mySoilTexture.setWeightPoints(dsbTextureSoil->value());
  mySoilTexture.setObservations(sbTextureSoil->value());
  mySoilTexture.setReplicates(0);

  // bulk density (set values from form)
  mySoilBulkDensity.setMinData(chbxBulkDensitySoil->isChecked());
  mySoilBulkDensity.setDepth(0);
  mySoilBulkDensity.setWeightPoints(dsbBulkDensitySoil->value());
  mySoilBulkDensity.setObservations(sbBulkDensitySoil->value());
  mySoilBulkDensity.setReplicates(0);

  // field capacity (set values from form)
  mySoilFieldCapacity.setMinData(chbxFieldCapacitySoil->isChecked());
  mySoilFieldCapacity.setDepth(0);
  mySoilFieldCapacity.setWeightPoints(dsbFieldCapacitySoil->value());
  mySoilFieldCapacity.setObservations(sbFieldCapacitySoil->value());
  mySoilFieldCapacity.setReplicates(0);

  // wilting point (set values from form)
  mySoilWiltingPoint.setMinData(chbxWiltingPointSoil->isChecked());
  mySoilWiltingPoint.setDepth(0);
  mySoilWiltingPoint.setWeightPoints(dsbWiltingPointSoil->value());
  mySoilWiltingPoint.setObservations(sbWiltingPointSoil->value());
  mySoilWiltingPoint.setReplicates(0);

  // pf curve (set values from form)
  mySoilPfCurve.setMinData(chbxPfCurveSoil->isChecked());
  mySoilPfCurve.setDepth(0);
  mySoilPfCurve.setWeightPoints(dsbPfCurveSoil->value());
  mySoilPfCurve.setObservations(sbPfCurveSoil->value());
  mySoilPfCurve.setReplicates(0);

  // hydr. cond. curve (set values from form)
  mySoilHydrCondCurve.setMinData(chbxHydrCondCurveSoil->isChecked());
  mySoilHydrCondCurve.setDepth(0);
  mySoilHydrCondCurve.setWeightPoints(dsbHydrCondCurveSoil->value());
  mySoilHydrCondCurve.setObservations(sbHydrCondCurveSoil->value());
  mySoilHydrCondCurve.setReplicates(0);


  //
  // Site set values from form
  //

  // latitude (set values from form)
  mySiteLatitude.setMinData(chbxLatitudeSite->isChecked());
  mySiteLatitude.setDepth(0);
  mySiteLatitude.setWeightPoints(dsbLatitudeSite->value());
  mySiteLatitude.setObservations(sbLatitudeSite->value());
  mySiteLatitude.setReplicates(0);

  // longitude (set values from form)
  mySiteLongitude.setMinData(chbxLongitudeSite->isChecked());
  mySiteLongitude.setDepth(0);
  mySiteLongitude.setWeightPoints(dsbLongitudeSite->value());
  mySiteLongitude.setObservations(sbLongitudeSite->value());
  mySiteLongitude.setReplicates(0);

  // altitude (set values from form)
  mySiteAltitude.setMinData(chbxAltitudeSite->isChecked());
  mySiteAltitude.setDepth(0);
  mySiteAltitude.setWeightPoints(dsbAltitudeSite->value());
  mySiteAltitude.setObservations(sbAltitudeSite->value());
  mySiteAltitude.setReplicates(0);


  //
  // Weather set values from form
  //

  // precipitation (set values from form)
  myWeatherPrecipitation.setMinData(chbxPrecipitationWeather->isChecked());
  myWeatherPrecipitation.setDepth(0);
  myWeatherPrecipitation.setWeightPoints(dsbPrecipitationWeather->value());
  myWeatherPrecipitation.setObservations(sbPrecipitationWeather->value());
  myWeatherPrecipitation.setReplicates(0);

  // T ave (set values from form)
  myWeatherTAve.setMinData(chbxTAveWeather->isChecked());
  myWeatherTAve.setDepth(0);
  myWeatherTAve.setWeightPoints(dsbTAveWeather->value());
  myWeatherTAve.setObservations(sbTAveWeather->value());
  myWeatherTAve.setReplicates(0);

  // T min (set values from form)
  myWeatherTMin.setMinData(chbxTMinWeather->isChecked());
  myWeatherTMin.setDepth(0);
  myWeatherTMin.setWeightPoints(dsbTMinWeather->value());
  myWeatherTMin.setObservations(sbTMinWeather->value());
  myWeatherTMin.setReplicates(0);

  // T max (set values from form)
  myWeatherTMax.setMinData(chbxTMaxWeather->isChecked());
  myWeatherTMax.setDepth(0);
  myWeatherTMax.setWeightPoints(dsbTMaxWeather->value());
  myWeatherTMax.setObservations(sbTMaxWeather->value());
  myWeatherTMax.setReplicates(0);

  // relative humidity (set values from form)
  myWeatherRelHumidity.setMinData(chbxRelHumidityWeather->isChecked());
  myWeatherRelHumidity.setDepth(0);
  myWeatherRelHumidity.setWeightPoints(dsbRelHumidityWeather->value());
  myWeatherRelHumidity.setObservations(sbRelHumidityWeather->value());
  myWeatherRelHumidity.setReplicates(0);

  // wind speed (set values from form)
  myWeatherWindSpeed.setMinData(chbxWindSpeedWeather->isChecked());
  myWeatherWindSpeed.setDepth(0);
  myWeatherWindSpeed.setWeightPoints(dsbWindSpeedWeather->value());
  myWeatherWindSpeed.setObservations(sbWindSpeedWeather->value());
  myWeatherWindSpeed.setReplicates(0);

  // global radiation (set values from form)
  myWeatherGlobalRadiation.setMinData(chbxGlobalRadiationWeather->isChecked());
  myWeatherGlobalRadiation.setDepth(0);
  myWeatherGlobalRadiation.setWeightPoints(dsbGlobalRadiationWeather->value());
  myWeatherGlobalRadiation.setObservations(sbGlobalRadiationWeather->value());
  myWeatherGlobalRadiation.setReplicates(0);

  // sunshine hours (set values from form)
  myWeatherSunshineHours.setMinData(chbxSunshineHoursWeather->isChecked());
  myWeatherSunshineHours.setDepth(0);
  myWeatherSunshineHours.setWeightPoints(dsbSunshineHoursWeather->value());
  myWeatherSunshineHours.setObservations(sbSunshineHoursWeather->value());
  myWeatherSunshineHours.setReplicates(0);


  //
  // Sate Vars set from Form
  //

  // CROP a. gr. biomass (set values from form)
  mySVCropAGrBiomass.setMinData(chbxSVCropAGrBiomass->isChecked());
  mySVCropAGrBiomass.setDepth(dsbSVCropAGrBiomassLayers->value());
  mySVCropAGrBiomass.setWeightPoints(dsbSVCropAGrBiomassWeightPts->value());
  mySVCropAGrBiomass.setObservations(sbSVCropAGrBiomassObservations->value());
  mySVCropAGrBiomass.setReplicates(dsbSVCropAGrBiomassReplicates->value());

  // CROP weight organs (set values from form)
  mySVCropWeightOrgans.setMinData(chbxSVCropWeightOrgans->isChecked());
  mySVCropWeightOrgans.setDepth(dsbSVCropWeightOrgansLayers->value());
  mySVCropWeightOrgans.setWeightPoints(dsbSVCropWeightOrgansWeightPts->value());
  mySVCropWeightOrgans.setObservations(sbSVCropWeightOrgansObservations->value());
  mySVCropWeightOrgans.setReplicates(dsbSVCropWeightOrgansReplicates->value());

  // CROP root biomass (set values from form)
  mySVCropRootBiomass.setMinData(chbxSVCropRootBiomass->isChecked());
  mySVCropRootBiomass.setDepth(dsbSVCropRootBiomassLayers->value());
  mySVCropRootBiomass.setWeightPoints(dsbSVCropRootBiomassWeightPts->value());
  mySVCropRootBiomass.setObservations(sbSVCropRootBiomassObservations->value());
  mySVCropRootBiomass.setReplicates(dsbSVCropRootBiomassReplicates->value());

  // CROP N in a. gr. biomass (set values from form)
  mySVCropNInAGrBiomass.setMinData(chbxSVCropNInAGrBiomass->isChecked());
  mySVCropNInAGrBiomass.setDepth(dsbSVCropNInAGrBiomassLayers->value());
  mySVCropNInAGrBiomass.setWeightPoints(dsbSVCropNInAGrBiomassWeightPts->value());
  mySVCropNInAGrBiomass.setObservations(sbSVCropNInAGrBiomassObservations->value());
  mySVCropNInAGrBiomass.setReplicates(dsbSVCropNInAGrBiomassReplicates->value());

  // CROP N in organs (set values from form)
  mySVCropNInOrgans.setMinData(chbxSVCropNInOrgans->isChecked());
  mySVCropNInOrgans.setDepth(dsbSVCropNInOrgansLayers->value());
  mySVCropNInOrgans.setWeightPoints(dsbSVCropNInOrgansWeightPts->value());
  mySVCropNInOrgans.setObservations(sbSVCropNInOrgansObservations->value());
  mySVCropNInOrgans.setReplicates(dsbSVCropNInOrgansReplicates->value());

  // CROP LAI (set values from form)
  mySVCropLAI.setMinData(chbxSVCropLAI->isChecked());
  mySVCropLAI.setDepth(dsbSVCropLAILayers->value());
  mySVCropLAI.setWeightPoints(dsbSVCropLAIWeightPts->value());
  mySVCropLAI.setObservations(sbSVCropLAIObservations->value());
  mySVCropLAI.setReplicates(dsbSVCropLAIReplicates->value());

  // SOIL soil water grav. (set values from form)
  mySVSoilSoilWaterGrav.setMinData(chbxSVSoilSoilWaterGrav->isChecked());
  mySVSoilSoilWaterGrav.setDepth(dsbSVSoilSoilWaterGravLayers->value());
  mySVSoilSoilWaterGrav.setWeightPoints(dsbSVSoilSoilWaterGravWeightPts->value());
  mySVSoilSoilWaterGrav.setObservations(sbSVSoilSoilWaterGravObservations->value());
  mySVSoilSoilWaterGrav.setReplicates(dsbSVSoilSoilWaterGravReplicates->value());

  // SOIL pressure heads (set values from form)
  mySVSoilPressureHeads.setMinData(chbxSVSoilPressureHeads->isChecked());
  mySVSoilPressureHeads.setDepth(dsbSVSoilPressureHeadsLayers->value());
  mySVSoilPressureHeads.setWeightPoints(dsbSVSoilPressureHeadsWeightPts->value());
  mySVSoilPressureHeads.setObservations(sbSVSoilPressureHeadsObservations->value());
  mySVSoilPressureHeads.setReplicates(dsbSVSoilPressureHeadsReplicates->value());

  // SOIL N min. (set values from form)
  mySVSoilNMin.setMinData(chbxSVSoilNMin->isChecked());
  mySVSoilNMin.setDepth(dsbSVSoilNMinLayers->value());
  mySVSoilNMin.setWeightPoints(dsbSVSoilNMinWeightPts->value());
  mySVSoilNMin.setObservations(sbSVSoilNMinObservations->value());
  mySVSoilNMin.setReplicates(dsbSVSoilNMinReplicates->value());

  // SOIL soil water sensor cal. (set values from form)
  mySVSoilSoilWaterSensorCal.setMinData(chbxSVSoilSoilWaterSensorCal->isChecked());
  mySVSoilSoilWaterSensorCal.setDepth(dsbSVSoilSoilWaterSensorCalLayers->value());
  mySVSoilSoilWaterSensorCal.setWeightPoints(dsbSVSoilSoilWaterSensorCalWeightPts->value());
  mySVSoilSoilWaterSensorCal.setObservations(sbSVSoilSoilWaterSensorCalObservations->value());
  mySVSoilSoilWaterSensorCal.setReplicates(dsbSVSoilSoilWaterSensorCalReplicates->value());

  // SOIL water flux bottom root (set values from form)
  mySVSoilWaterFluxBottomRoot.setMinData(chbxSVSoilWaterFluxBottomRoot->isChecked());
  mySVSoilWaterFluxBottomRoot.setDepth(dsbSVSoilWaterFluxBottomRootLayers->value());
  mySVSoilWaterFluxBottomRoot.setWeightPoints(dsbSVSoilWaterFluxBottomRootWeightPts->value());
  mySVSoilWaterFluxBottomRoot.setObservations(sbSVSoilWaterFluxBottomRootObservations->value());
  mySVSoilWaterFluxBottomRoot.setReplicates(dsbSVSoilWaterFluxBottomRootReplicates->value());

  // SOIL N flux bottom root (set values from form)
  mySVSoilNFluxBottomRoot.setMinData(chbxSVSoilNFluxBottomRoot->isChecked());
  mySVSoilNFluxBottomRoot.setDepth(dsbSVSoilNFluxBottomRootLayers->value());
  mySVSoilNFluxBottomRoot.setWeightPoints(dsbSVSoilNFluxBottomRootWeightPts->value());
  mySVSoilNFluxBottomRoot.setObservations(sbSVSoilNFluxBottomRootObservations->value());
  mySVSoilNFluxBottomRoot.setReplicates(dsbSVSoilNFluxBottomRootReplicates->value());

  // SURFACEFLUXES ET (set values from form)
  mySVSurfaceFluxesEt.setMinData(chbxSVSurfaceFluxesEt->isChecked());
  mySVSurfaceFluxesEt.setDepth(dsbSVSurfaceFluxesEtLayers->value());
  mySVSurfaceFluxesEt.setWeightPoints(dsbSVSurfaceFluxesEtWeightPts->value());
  mySVSurfaceFluxesEt.setObservations(sbSVSurfaceFluxesEtObservations->value());
  mySVSurfaceFluxesEt.setReplicates(dsbSVSurfaceFluxesEtReplicates->value());

  // SURFACEFLUXES NH3 Loss (set values from form)
  mySVSurfaceFluxesNh3Loss.setMinData(chbxSVSurfaceFluxesNh3Loss->isChecked());
  mySVSurfaceFluxesNh3Loss.setDepth(dsbSVSurfaceFluxesNh3LossLayers->value());
  mySVSurfaceFluxesNh3Loss.setWeightPoints(dsbSVSurfaceFluxesNh3LossWeightPts->value());
  mySVSurfaceFluxesNh3Loss.setObservations(sbSVSurfaceFluxesNh3LossObservations->value());
  mySVSurfaceFluxesNh3Loss.setReplicates(dsbSVSurfaceFluxesNh3LossReplicates->value());

  // SURFACEFLUXES N2O Loss (set values from form)
  mySVSurfaceFluxesN2OLoss.setMinData(chbxSVSurfaceFluxesN2OLoss->isChecked());
  mySVSurfaceFluxesN2OLoss.setDepth(dsbSVSurfaceFluxesN2OLossLayers->value());
  mySVSurfaceFluxesN2OLoss.setWeightPoints(dsbSVSurfaceFluxesN2OLossWeightPts->value());
  mySVSurfaceFluxesN2OLoss.setObservations(sbSVSurfaceFluxesN2OLossObservations->value());
  mySVSurfaceFluxesN2OLoss.setReplicates(dsbSVSurfaceFluxesN2OLossReplicates->value());

  // SURFACEFLUXES N2 Loss (set values from form)
  mySVSurfaceFluxesN2Loss.setMinData(chbxSVSurfaceFluxesN2Loss->isChecked());
  mySVSurfaceFluxesN2Loss.setDepth(dsbSVSurfaceFluxesN2LossLayers->value());
  mySVSurfaceFluxesN2Loss.setWeightPoints(dsbSVSurfaceFluxesN2LossWeightPts->value());
  mySVSurfaceFluxesN2Loss.setObservations(sbSVSurfaceFluxesN2LossObservations->value());
  mySVSurfaceFluxesN2Loss.setReplicates(dsbSVSurfaceFluxesN2LossReplicates->value());

  // SURFACEFLUXES CH4 Loss (set values from form)
  mySVSurfaceFluxesCh4Loss.setMinData(chbxSVSurfaceFluxesCh4Loss->isChecked());
  mySVSurfaceFluxesCh4Loss.setDepth(dsbSVSurfaceFluxesCh4LossLayers->value());
  mySVSurfaceFluxesCh4Loss.setWeightPoints(dsbSVSurfaceFluxesCh4LossWeightPts->value());
  mySVSurfaceFluxesCh4Loss.setObservations(sbSVSurfaceFluxesCh4LossObservations->value());
  mySVSurfaceFluxesCh4Loss.setReplicates(dsbSVSurfaceFluxesCh4LossReplicates->value());

  // OBSERVATIONS lodging (set values from form)
  mySVObservationsLodging.setMinData(chbxSVObservationsLodging->isChecked());
  mySVObservationsLodging.setDepth(dsbSVObservationsLodgingLayers->value());
  mySVObservationsLodging.setWeightPoints(dsbSVObservationsLodgingWeightPts->value());
  mySVObservationsLodging.setObservations(sbSVObservationsLodgingObservations->value());
  mySVObservationsLodging.setReplicates(dsbSVObservationsLodgingReplicates->value());

  // OBSERVATIONS pests or diseases (set values from form)
  mySVObservationsPestsOrDiseases.setMinData(chbxSVObservationsPestsOrDiseases->isChecked());
  mySVObservationsPestsOrDiseases.setDepth(dsbSVObservationsPestsOrDiseasesLayers->value());
  mySVObservationsPestsOrDiseases.setWeightPoints(dsbSVObservationsPestsOrDiseasesWeightPts->value());
  mySVObservationsPestsOrDiseases.setObservations(sbSVObservationsPestsOrDiseasesObservations->value());
  mySVObservationsPestsOrDiseases.setReplicates(dsbSVObservationsPestsOrDiseasesReplicates->value());

  // OBSERVATIONS damages (set values from form)
  mySVObservationsDamages.setMinData(chbxSVObservationsDamages->isChecked());
  mySVObservationsDamages.setDepth(dsbSVObservationsDamagesLayers->value());
  mySVObservationsDamages.setWeightPoints(dsbSVObservationsDamagesWeightPts->value());
  mySVObservationsDamages.setObservations(sbSVObservationsDamagesObservations->value());
  mySVObservationsDamages.setReplicates(dsbSVObservationsDamagesReplicates->value());


    //-----------------//
   // set the values  //
  //-----------------//

  //
  // set management values
  //
  myManagement.setVariety(myCultVariety);
  myManagement.setSowing(myCultSowing);
  myManagement.setHarvest(myCultHarvest);
  myManagement.setFertilisation(myCultFertilisation);
  myManagement.setIrrigation(myCultIrrigation);
  myManagement.setSeedDensity(myCultSeedDensity);
  myManagement.setYield(myCultYield);
  myManagement.setTillage(myCultTillage);

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
  myPrevCrop.setCrop(myPrevCropCrop);
  myPrevCrop.setSowingDate(myPrevCropSowingDate);
  myPrevCrop.setHarvestDate(myPrevCropHarvestDate);
  myPrevCrop.setYield(myPrevCropYield);
  myPrevCrop.setResidueMgmt(myPrevCropResidueMgmt);
  myPrevCrop.setFertilisation(myPrevCropFertilisation);
  myPrevCrop.setIrrigation(myPrevCropIrrigation);

  //
  // set InitialValues values
  //
  myInitialValues.setSoilMoisture(myInitialValuesSoilMoisture);
  myInitialValues.setNitrogenMin(myInitialValuesNMin);

  //
  // set soil values
  //
  mySoil.setCarbonOrganic(mySoilCOrg);
  mySoil.setNitrogenOrganic(mySoilNOrg);
  mySoil.setTexture(mySoilTexture);
  mySoil.setBulkDensity(mySoilBulkDensity);
  mySoil.setFieldCapacityMeas(mySoilFieldCapacity);
  mySoil.setWiltingPointMeas(mySoilWiltingPoint);
  mySoil.setPfCurve(mySoilPfCurve);
  mySoil.setHydrCondCurve(mySoilHydrCondCurve);
  mySoil.setPh(mySoilPh);

  //
  // set site values
  //
  mySite.setLatitude(mySiteLatitude);
  mySite.setLongitude(mySiteLongitude);
  mySite.setAltitude(mySiteAltitude);

  //
  // set weather values
  //
  myWeather.setPrecipitation(myWeatherPrecipitation);
  myWeather.setTAve(myWeatherTAve);
  myWeather.setTMin(myWeatherTMin);
  myWeather.setTMax(myWeatherTMax);
  myWeather.setRelativeHumidity(myWeatherRelHumidity);
  myWeather.setWindSpeed(myWeatherWindSpeed);
  myWeather.setGlobalRadiation(myWeatherGlobalRadiation);
  myWeather.setSunshineHours(myWeatherSunshineHours);
  myWeather.setLeafWetness(myWeatherLeafWetness);
  myWeather.setSoilTemp(myWeatherSoilTemp);

  //
  // set state vars values
  //
  //state vars - soil (initialise variables)
  mySVSoil.setSoilWaterGrav(mySVSoilSoilWaterGrav);
  mySVSoil.setPressureHeads(mySVSoilPressureHeads);
  mySVSoil.setNMin(mySVSoilNMin);
  mySVSoil.setSoilWaterSensorCal(mySVSoilSoilWaterSensorCal);
  mySVSoil.setWaterFluxBottomRoot(mySVSoilWaterFluxBottomRoot);
  mySVSoil.setNitrogenFluxBottomRoot(mySVSoilNFluxBottomRoot);

  mySV.setSoilCategories(mySVSoil);

  // state vars - crop (initialise variables)
  mySVCrop.setAgrBiomass(mySVCropAGrBiomass);
  mySVCrop.setWeightOrgans(mySVCropWeightOrgans);
  mySVCrop.setRootBiomass(mySVCropRootBiomass);
  mySVCrop.setNInAGrBiomass(mySVCropNInAGrBiomass);
  mySVCrop.setNInOrgans(mySVCropNInOrgans);
  mySVCrop.setLai(mySVCropLAI);

  mySV.setCropCategories(mySVCrop);

  // state vars - surface fluxes (initialise variables)
  mySVSurfaceFluxes.setEt(mySVSurfaceFluxesEt);
  mySVSurfaceFluxes.setNh3Loss(mySVSurfaceFluxesNh3Loss);
  mySVSurfaceFluxes.setN2oLoss(mySVSurfaceFluxesN2OLoss);
  mySVSurfaceFluxes.setN2Loss(mySVSurfaceFluxesN2Loss);
  mySVSurfaceFluxes.setCh4Loss(mySVSurfaceFluxesCh4Loss);

  mySV.setSurfaceFluxesCategories(mySVSurfaceFluxes);

  // state vars - observation data (initialise variables)
  mySVObservations.setLodging(mySVObservationsLodging);
  mySVObservations.setPestsOrDiseases(mySVObservationsPestsOrDiseases);
  mySVObservations.setDamages(mySVObservationsDamages);

  mySV.setObservationCategories(mySVObservations);




  QString myString;
  //myString+=QString("<dataset guid=\"" + guid() + "\">\n");
  //myString+=QString(" <name>" + MadUtils::xmlEncode(myName) + "</name>\n");
  //myString+=QString(" <description>" + MadUtils::xmlEncode(myDescription) + "</description>\n");
  myString += myDataset.toXml();
  myString += myManagement.toXml();
  myString += myPhenology.toXml();
  myString += myPrevCrop.toXml();
  myString += myInitialValues.toXml();
  myString += mySoil.toXml();
  myString += mySite.toXml();
  myString += myWeather.toXml();
  myString += mySV.toXml();

  myString+=QString("</dataset>\n");

  textEditSide->setText(myString);

  // send values to MadDataset so it has the proper values to write instead of all zeros!
  myDataset.setManagement(myManagement);
  myDataset.setPhenology(myPhenology);
  myDataset.setPrevCrop(myPrevCrop);
  myDataset.setInitialValues(myInitialValues);
  myDataset.setSoil(mySoil);
  myDataset.setSiteData(mySite);
  myDataset.setWeather(myWeather);
  myDataset.setStateVars(mySV);

  myDataset.toXmlFile( MadUtils::userDatasetClassificationDirPath()
                       + QDir::separator() + myDataset.guid() + ".xml");

  //mCrop.toXmlFile( LaUtils::userCropProfilesDirPath() +
  //    QDir::separator() + mCrop.guid() + ".xml");
}

