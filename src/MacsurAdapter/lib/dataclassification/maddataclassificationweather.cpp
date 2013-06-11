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
bool MadDataClassificationWeather::minData() const
{
  return mMinData;
}
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
void MadDataClassificationWeather::setMinData(bool theBool)
{
  mMinData = theBool;
}
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
  QDomElement myTopElement = myDocument.firstChildElement("weather");
  if (myTopElement.isNull())
  {
    // TODO - just make this a warning
    qDebug("the top element couldn't be found!");
    setGuid(myTopElement.attribute("guid"));

    //MadDataClassificationWeather myWeather;
    //QString myPrecipitationXml = QString(QDomDocumentFragment().firstChildElement("precipitation").text());
    //myWeather.setPrecipitation(MadSubCategory::fromXml(myPrecipitationXml));

    // the line below works and does the same as the line below it.
    // (QString(myTopElement.firstChildElement("mindata").text() ))=="0" ? mMinData=false : mMinData=true;
    mMinData = QString(myTopElement.firstChildElement("mindata").text()).toInt();
    MadSubCategory myPrecipitationDetails;
    myPrecipitationDetails.setDepth( QString(myTopElement.firstChildElement("precipitation").nextSiblingElement("details").nextSiblingElement("depth").text()).toFloat());
    //qDebug()

    /* the following doesn't work
    mPrecipitation = MadUtils::xmlDecode(myTopElement.firstChildElement("precipitation").text()).toInt();
    mTAve = MadUtils::xmlDecode(myTopElement.firstChildElement("tave").text()).toInt();
    mTMin = MadUtils::xmlDecode(myTopElement.firstChildElement("tmin").text()).toFloat();
    mTMax = MadUtils::xmlDecode(myTopElement.firstChildElement("tmax").text()).toInt();
    mRelativeHumidity = MadUtils::xmlDecode(myTopElement.firstChildElement("relativehumidity").text()).toInt();
    mWindSpeed = MadUtils::xmlDecode(myTopElement.firstChildElement("windspeed").text()).toInt();
    mGlobalRadiation = MadUtils::xmlDecode(myTopElement.firstChildElement("globalradiation").text()).toInt();
    mSunshineHours = MadUtils::xmlDecode(myTopElement.firstChildElement("sunshinehours").text()).toInt();
    mLeafWetness = MadUtils::xmlDecode(myTopElement.firstChildElement("leafwetness").text()).toInt();
    mSoilTemp = MadUtils::xmlDecode(myTopElement.firstChildElement("soiltemp").text()).toInt();
    */
    return true;
  }
  else
    return false;
}

QString MadDataClassificationWeather::toXml()
{
  QString myString;
  myString+=QString("  <category name=\"weather\" guid=\"" + guid() + "\">\n");

  myString+=QString("    <tab name=\"precipitation\">\n");
  myString+=mPrecipitation.toXml();
  myString+=QString("    </tab>\n");
  
  myString+=QString("    <tab name=\"tAve\">\n");
  myString+=mTAve.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"tMin\">\n");
  myString+=mTMin.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"tMax\">\n");
  myString+=mTMax.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"relativeHumidity\">\n");
  myString+=mRelativeHumidity.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"windSpeed\">\n");
  myString+=mWindSpeed.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"globalRadiation\">\n");
  myString+=mGlobalRadiation.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"sunshineHours\">\n");
  myString+=mSunshineHours.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"leafWetness\">\n");
  myString+=mLeafWetness.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"soilTemp\">\n");
  myString+=mSoilTemp.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("  </category>\n");
  return myString;

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
