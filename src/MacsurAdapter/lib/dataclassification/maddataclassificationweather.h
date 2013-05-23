/***************************************************************************
 *   File:  maddataclassificationweather.h created: 22/05/2013                                    *
 *   Class info: MadDataClassificationWeather                                               *
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

#ifndef MADDATACLASSIFICATIONWEATHER_H
#define MADDATACLASSIFICATIONWEATHER_H

class QString;  //  forward declaration

// local includes
#include "madsubcategory.h"
#include "../madguid.h"
#include "../madserialisable.h"

// Qt includes
#include <QString>

class MadDataClassificationWeather : public MadSerialisable, public MadGuid
{
public:
  MadDataClassificationWeather();
  MadDataClassificationWeather(const MadDataClassificationWeather& theData);
  MadDataClassificationWeather& operator = (const MadDataClassificationWeather& theData);


  // Accessors
  MadSubCategory precipitation() const;
  MadSubCategory tAve() const;
  MadSubCategory tMin() const;
  MadSubCategory tMax() const;
  MadSubCategory relativeHumidity() const;
  MadSubCategory windSpeed() const;
  MadSubCategory globalRadiation() const;
  MadSubCategory sunshineHours() const;
  MadSubCategory leafWetness() const;
  MadSubCategory soilTemp() const;

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
  void setPrecipitation(MadSubCategory theData);
  void setTAve(MadSubCategory theData);
  void setTMin(MadSubCategory theData);
  void setTMax(MadSubCategory theData);
  void setRelativeHumidity(MadSubCategory theData);
  void setWindSpeed(MadSubCategory theData);
  void setGlobalRadiation(MadSubCategory theData);
  void setSunshineHours(MadSubCategory theData);
  void setLeafWetness(MadSubCategory theData);
  void setSoilTemp(MadSubCategory theData);

private:
  MadSubCategory mPrecipitation;
  MadSubCategory mTAve;
  MadSubCategory mTMin;
  MadSubCategory mTMax;
  MadSubCategory mRelativeHumidity;
  MadSubCategory mWindSpeed;
  MadSubCategory mGlobalRadiation;
  MadSubCategory mSunshineHours;
  MadSubCategory mLeafWetness;
  MadSubCategory mSoilTemp;
};

#endif // MADDATACLASSIFICATIONWEATHER_H

