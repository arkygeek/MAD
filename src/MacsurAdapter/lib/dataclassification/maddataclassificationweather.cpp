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

// Local includes
#include "maddataclassificationweather.h"
#include "madsubcategory.h"
#include "../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationWeather::MadDataClassificationWeather() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadDataClassificationWeather::MadDataClassificationWeather(const MadDataClassificationWeather &theData)
{
  setGuid(theData.guid());
  setPrecipitation(theData.precipitation());
  setTAve(theData.tAve());
  setTMin(theData.tMin());
  setTMax(theData.tMax());
  setRelativeHumidity(theData.relativeHumidity());
  setWindSpeed(theData.windSpeed());
  setGlobalRadiation(theData.globalRadiation());
  setSunshineHours(theData.sunshineHours());
  setLeafWetness(theData.leafWetness());
  setSoilTemp(theData.soilTemp());
}

MadDataClassificationWeather& MadDataClassificationWeather::operator =(const MadDataClassificationWeather& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  //setGuid(theData.guid());
  mPrecipitation=theData.precipitation();
  mTAve=theData.tAve();
  mTMin=theData.tMin();
  mTMax=theData.tMax();
  mRelativeHumidity=theData.relativeHumidity();
  mWindSpeed=theData.windSpeed();
  mGlobalRadiation=theData.globalRadiation();
  mSunshineHours=theData.sunshineHours();
  mLeafWetness=theData.leafWetness();
  mSoilTemp=theData.soilTemp();

  return *this;
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

bool MadDataClassificationWeather::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("model");
    if (myTopElement.isNull())
    {
        //TODO - just make this a warning
        qDebug("the top element couldn't be found!");
        setGuid(myTopElement.attribute("guid"));
        //mName=MadUtils::xmlDecode(myTopElement.firstChildElement("name").text());
        //mDescription=MadUtils::xmlDecode(myTopElement.firstChildElement("description").text());
        //mImageFile=QString(myTopElement.firstChildElement("imageFile").text());
        return true;
    }
    else
    return false;
}

QString MadDataClassificationWeather::toXml()
{
  QString myString;
  myString+=QString("<dataset guid=\"" + guid() + "\">\n");
  //myString+=QString("  <name>" + MadUtils::xmlEncode(mName) + "</name>\n");
  //myString+=QString("  <description>" + MadUtils::xmlEncode(mDescription) + "</description>\n");
  //myString+=QString("  <imageFile>" + MadUtils::xmlEncode(mImageFile) + "</imageFile>\n");
  myString+=QString("</dataset>\n");
  return myString;

  /*   example structure of xml file

    <dataset guid="hj243g5hjk34gjh2g43">
      <name>Some name</name>
      <description>The given description</description>
      <imageFile>/home/arkygeek/.macsurAdapter/images/image.png</imageFile>
      <cultivation>
        <variety>
          <minData>true</minData>
          <depth>1.0</depth>
          <observations>3</observations>
          <weightPoints>2.0</weightPoints>
          <replicates>3</replicates>
        </variety>
        <sowing>
          <minData>true</minData>
          <depth>1.0</depth>
          <observations>3</observations>
          <weightPoints>2.0</weightPoints>
          <replicates>3</replicates>
        </sowing>
        <harvest>
          <minData>true</minData>
          <depth>1.0</depth>
          <observations>3</observations>
          <weightPoints>2.0</weightPoints>
          <replicates>3</replicates>
        </harvest>
      </cultivation>
    </dataset>



  */
}

QString MadDataClassificationWeather::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationWeather::toHtml()
{
  QString myString;
  //myString+="<h3>Details for " + MadUtils::xmlEncode(mName) + "</h3>";
    //myString+="<p>GUID:" + guid() + "</p>";
  myString+="<table>";
  //myString+="<tr><td><b>Description: </b></td><td>" + mDescription + "</td></tr>";

  //
  // the following shows example of how to do a couple of things
  //

  //myString+="<tr><td><b>Cals/Kg: </b></td><td>" + QString::number(mCropCalories) + "</td></tr>";
  //QString myCropFodderEnergyType = (mCropFodderEnergyType==0) ? "KCalories" : "TDN";
  //QString myUnits = (mAreaUnits==0) ? "Dunum" : "Hectare";
  //myString+="<tr><td><b>Fodder (kg/" + myUnits + "): </b></td><td>" + QString::number(mCropFodderProduction) + "</td></tr>";
  //myString+="<tr><td><b>Fodder Value/Kg: </b></td><td>" + QString::number(mCropFodderValue) + "</td></tr>";
  //myString+="<tr><td><b>FodderEnergyType: </b></td><td>" + myCropFodderEnergyType + "</td></tr>";
  //myString+="<tr><td><b>AreaUnits: </b></td><td>" + myUnits + "</td></tr>";
  myString+="</table>";
  return myString;
}
