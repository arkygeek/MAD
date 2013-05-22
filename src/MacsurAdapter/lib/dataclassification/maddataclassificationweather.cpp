/***************************************************************************
 *   File:  maddataclassificationweather.cpp created: 22/05/2013                                    *
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

#include "maddataclassificationweather.h"
#include "madsubcategory.h"

MadDataClassificationWeather::MadDataClassificationWeather()
{
}

// Accessors
MadSubCategory MadDataClassificationWeather::precipitation() const
{
  return mPrecipitation;
}
MadSubCategory MadDataClassificationWeather::tAve() const
{
  return mTAve;
}
MadSubCategory MadDataClassificationWeather::tMin() const
{
  return mTMin;
}
MadSubCategory MadDataClassificationWeather::tMax() const
{
  return mTMax;
}
MadSubCategory MadDataClassificationWeather::relativeHumidity() const
{
  return mRelativeHumidity;
}
MadSubCategory MadDataClassificationWeather::windSpeed() const
{
  return mWindSpeed;
}
MadSubCategory MadDataClassificationWeather::globalRadiation() const
{
  return mGlobalRadiation;
}
MadSubCategory MadDataClassificationWeather::sunshineHours() const
{
  return mSunshineHours;
}
MadSubCategory MadDataClassificationWeather::leafWetness() const
{
  return mLeafWetness;
}
MadSubCategory MadDataClassificationWeather::soilTemp() const
{
  return mSoilTemp;
}

// Mutators
void MadDataClassificationWeather::setPrecipitation(MadSubCategory theData)
{
  mPrecipitation = theData;
}

void MadDataClassificationWeather::setTAve(MadSubCategory theData)
{
  mTAve = theData;
}

void MadDataClassificationWeather::setTMin(MadSubCategory theData)
{
  mTMin = theData;
}

void MadDataClassificationWeather::setTMax(MadSubCategory theData)
{
  mTMax = theData;
}

void MadDataClassificationWeather::setRelativeHumidity(MadSubCategory theData)
{
  mRelativeHumidity = theData;
}

void MadDataClassificationWeather::setWindSpeed(MadSubCategory theData)
{
  mWindSpeed = theData;
}

void MadDataClassificationWeather::setGlobalRadiation(MadSubCategory theData)
{
  mGlobalRadiation = theData;
}

void MadDataClassificationWeather::setSunshineHours(MadSubCategory theData)
{
  mSunshineHours = theData;
}

void MadDataClassificationWeather::setLeafWetness(MadSubCategory theData)
{
  mLeafWetness = theData;
}

void MadDataClassificationWeather::setSoilTemp(MadSubCategory theData)
{
  mSoilTemp = theData;
}
