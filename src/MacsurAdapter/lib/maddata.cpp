/***************************************************************************
 *   File:  maddata.cpp created: 09/05/2013                                    *
 *   Class info: MadData                                               *
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

//Local includes
#include "maddata.h"
#include "madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadData::MadData() : MadSerialisable(), MadGuid()
{
    setGuid();
    mName="No Name Set";
    mDescription="Not Set";
}

MadData::MadData(const MadData &theData)
{
    mName=theData.name();
    mDescription=theData.description();
    setGuid(theData.guid());
    mImageFile=theData.imageFile();
}

MadData& MadData::operator =(const MadData& theData)
{
    if (this == &theData) return *this; // gracefully handles self assignment

    mName=theData.name();
    mDescription=theData.description();
    setGuid(theData.guid());
    mImageFile=theData.imageFile();
    return *this;
}

QString MadData::name() const
{
    return mName;
}

QString MadData::description() const
{
    return mDescription;
}

QString MadData::imageFile() const
{
    return mImageFile;
}

/*****************/

void MadData::setName(QString theName)
{
    mName=theName;
}

void MadData::setDescription(QString theDescription)
{
    mDescription=theDescription;
}

void MadData::setImageFile(QString theImageFileName)
{
    mImageFile=theImageFileName;
}

bool MadData::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("model");
    if (myTopElement.isNull())
    {
        //TODO - just make this a warning
        qDebug("the top element couldn't be found!");
        setGuid(myTopElement.attribute("guid"));
        mName=MadUtils::xmlDecode(myTopElement.firstChildElement("name").text());
        mDescription=MadUtils::xmlDecode(myTopElement.firstChildElement("description").text());
        mImageFile=QString(myTopElement.firstChildElement("imageFile").text());
        return true;
    }
    else
    return false;
}

QString MadData::toXml()
{
  QString myString;
  myString+=QString("<model guid=\"" + guid() + "\">\n");
    myString+=QString("  <name>" + MadUtils::xmlEncode(mName) + "</name>\n");
  myString+=QString("  <description>" + MadUtils::xmlEncode(mDescription) + "</description>\n");


//  switch (mAreaUnits)
//  {
//    case Dunum:
//      myString+=QString("  <areaUnits>Dunum</areaUnits>\n");
//      break;
//    case Hectare:
//      myString+=QString("  <areaUnits>Hectare</areaUnits>\n");
//      break;
//  }
  myString+=QString("  <imageFile>" + MadUtils::xmlEncode(mImageFile) + "</imageFile>\n");
  myString+=QString("</model>\n");
  return myString;
}

QString MadData::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadData::toHtml()
{
  QString myString;
  myString+="<h3>Details for " + MadUtils::xmlEncode(mName) + "</h3>";
    //myString+="<p>GUID:" + guid() + "</p>";
  myString+="<table>";
  myString+="<tr><td><b>Description: </b></td><td>" + mDescription + "</td></tr>";

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

  /*****************/
 /*    CLASSES    */
/*****************/

class Cultivation
{
public:
  MadSubCategory variety;
  MadSubCategory sowing;
  MadSubCategory harvest;
  MadSubCategory fertilisation;
  MadSubCategory irrigation;
  MadSubCategory seedDensity;
  MadSubCategory yield;
  MadSubCategory tillage;

private:
  MadSubCategory mVariety;
  MadSubCategory mSowing;
  MadSubCategory mHarvest;
  MadSubCategory mFertilisation;
  MadSubCategory mIrrigation;
  MadSubCategory mSeedDensity;
  MadSubCategory mYield;
  MadSubCategory mTillage;

};

class Phenology
{
public:
  MadSubCategory mEmergence;
  MadSubCategory mStemElongation;
  MadSubCategory mEarEmergence;
  MadSubCategory mFlowering;
  MadSubCategory mYellowRipeness;

};

class PreviousCrop
{
public:
  MadSubCategory mCrop;
  MadSubCategory mSowingDate;
  MadSubCategory mHarvestDate;
  MadSubCategory mYield;
  MadSubCategory mResidueMgmt;
  MadSubCategory mFertilisation;
  MadSubCategory mIrrigation;

};

class InitialValues
{
public:
  MadSubCategory mSoilMoisture;
  MadSubCategory mNitrogenMin;

};

class Soil
{
public:
  MadSubCategory mCarbonOrganic;
  MadSubCategory mNitrogenOrganic;
  MadSubCategory mTexture;
  MadSubCategory mBulkDensity;
  MadSubCategory mFieldCapacityMeas;
  MadSubCategory mWiltingPointMeas;
  MadSubCategory mPfCurve;
  MadSubCategory mHydrCondCurve;
  MadSubCategory mPh;

};

class SiteData
{
public:
  MadSubCategory mLatitude;
  MadSubCategory mLongitude;
  MadSubCategory mAltitude;

};

class WeatherData
{
public:
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

class StateVars
{

public:
  class Cultivation
  {
  public:
    MadSubCategory mVariety;
    MadSubCategory mSowing;
    MadSubCategory mHarvest;
    MadSubCategory mFertilisation;
    MadSubCategory mIrrigation;
    MadSubCategory mSeedDensity;
    MadSubCategory mYield;
    MadSubCategory mTillage;

  };

  class Phenology
  {
  public:
    MadSubCategory mEmergence;
    MadSubCategory mStemElongation;
    MadSubCategory mEarEmergence;
    MadSubCategory mFlowering;
    MadSubCategory mYellowRipeness;

  };

  class PreviousCrop
  {
  public:
    MadSubCategory mCrop;
    MadSubCategory mSowingDate;
    MadSubCategory mHarvestDate;
    MadSubCategory mYield;
    MadSubCategory mResidueMgmt;
    MadSubCategory mFertilisation;
    MadSubCategory mIrrigation;

  };

  class InitialValues
  {
  public:
    MadSubCategory mSoilMoisture;
    MadSubCategory mNitrogenMin;

  };

  class Soil
  {
  public:
    MadSubCategory mCarbonOrganic;
    MadSubCategory mNitrogenOrganic;
    MadSubCategory mTexture;
    MadSubCategory mBulkDensity;
    MadSubCategory mFieldCapacityMeas;
    MadSubCategory mWiltingPointMeas;
    MadSubCategory mPfCurve;
    MadSubCategory mHydrCondCurve;
    MadSubCategory mPh;

  };

  class SiteData
  {
  public:
    MadSubCategory mLatitude;
    MadSubCategory mLongitude;
    MadSubCategory mAltitude;

  };

  class WeatherData
  {
  public:
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

  class StateVariables // this has 4 sub classes
  {
  public:
    class crop
    {
    public:
      MadSubCategory mAgrBiomass;
      MadSubCategory mWeightOrgans;
      MadSubCategory mRootBiomass;
      MadSubCategory mNInAGrBiomass;
      MadSubCategory mNInOrgans;
      MadSubCategory mLai;

    };

    class Soil
    {
    public:
      MadSubCategory mSoilWaterGrav;
      MadSubCategory mPressureHeads;
      MadSubCategory mNMin;
      MadSubCategory mSoilWaterSensorCal;
      MadSubCategory mWaterFluxBottomRoot;
      MadSubCategory mNitrogenFluxBottomRoot;

    };

    class SurfaceFluxes
    {
    public:
      MadSubCategory mEt;
      MadSubCategory mNH3Loss;
      MadSubCategory mN2OLosse;
      MadSubCategory mN2Loss;
      MadSubCategory mCH4Loss;

    };

    class Observations
    {
    public:
      MadSubCategory mLodging;
      MadSubCategory mPestsOrDiseases;
      MadSubCategory mDamages;

    };
  };
};
