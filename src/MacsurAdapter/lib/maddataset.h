/***************************************************************************
 *   File:  maddataset.h created: 28/05/2013                                    *
 *   Class info: MadDataset                                               *
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

#ifndef MADDATASET_H
#define MADDATASET_H

// local includes
#include "madguid.h"
#include "madserialisable.h"
#include "ui_maddataclassificationbase.h"
#include "dataclassification/maddataclassificationcultivation.h"
#include "dataclassification/maddataclassificationinitialvalues.h"
#include "dataclassification/maddataclassificationphenology.h"
#include "dataclassification/maddataclassificationprevcrop.h"
#include "dataclassification/maddataclassificationsitedata.h"
#include "dataclassification/maddataclassificationsoil.h"
#include "dataclassification/maddataclassificationweather.h"
#include "dataclassification/statevars/madstatevars.h"

// Qt includes
#include <QString>

class MadDataset : public MadSerialisable, public MadGuid
{
public:
  MadDataset();
  MadDataset(const MadDataset& theData);
  MadDataset& operator = (const MadDataset& theDataset);

  // Accessors
  MadDataClassificationCultivation cultivation() const;
  MadDataClassificationInitialValues initialValues() const;
  MadDataClassificationPhenology phenology() const;
  MadDataClassificationPrevCrop prevCrop() const;
  MadDataClassificationSiteData siteData() const;
  MadDataClassificationSoil soil() const;
  MadDataClassificationWeather weather() const;
  MadStateVars stateVars() const;

  // Text functions

  /** Return an xml representation of this layer
   * @note this class inherits the serialisable interface
   * so it MUST implement this
   */
  QString toXml();

  /** Return a plain text representation of this layer
   */
  QString toText();

  /** Return a html text representation of this layer
   */
  QString toHtml();

  /** Read this object from xml and return result as
   * true for success, false for failure.
   * @see MadSerialisable
   * @note this class inherits the serialisable interface
   * so it MUST implement this
   */
  bool fromXml(const QString theXml);

  // Mutators

  void setCultivation(MadDataClassificationCultivation theCultivationData);
  void setInitialValues(MadDataClassificationInitialValues theInitialValues);
  void setPhenology(MadDataClassificationPhenology thePhenologyData);
  void setPrevCrop(MadDataClassificationPrevCrop thePrevCropData);
  void setSiteData(MadDataClassificationSiteData theSiteData);
  void setSoil(MadDataClassificationSoil theSoilData);
  void setWeather(MadDataClassificationWeather theWeatherData);
  void setStateVars(MadStateVars theStateVarsData);

private:
  MadDataClassificationCultivation mCultivation;
  MadDataClassificationInitialValues mInitialValues;
  MadDataClassificationPhenology mPhenology;
  MadDataClassificationPrevCrop mPrevCrop;
  MadDataClassificationSiteData mSiteData;
  MadDataClassificationSoil mSoil;
  MadDataClassificationWeather mWeather;
  MadStateVars mStateVars;
};

#endif // MADDATASET_H
