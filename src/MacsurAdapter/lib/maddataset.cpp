/***************************************************************************
 *   File:  maddataset.cpp created: 28/05/2013                                    *
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

#include <iomanip>

// Local includes
#include "maddataset.h"
#include "madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataset::MadDataset() : MadSerialisable(), MadGuid()
{
 setGuid();
 mName="No Name Set";
 mDescription="Not Set";
 // we can put in other defaults here, such as
 // mTheme="Valid for all themes";  <-- this doesn't exist though haha
}

MadDataset::MadDataset(const MadDataset &theData)
{
  mName=theData.name();
  mDescription=theData.description();
  setGuid(theData.guid());
  mManagement=theData.management();
  mInitialValues=theData.initialValues();
  mPhenology=theData.phenology();
  mPrevCrop=theData.prevCrop();
  mSiteData=theData.siteData();
  mSoil=theData.soil();
  mWeather=theData.weather();
  mStateVars=theData.stateVars();
}

MadDataset& MadDataset::operator =(const MadDataset& theData)
{
 // gracefully handles self assignment
 if (this == &theData) return *this;
 mName=theData.name();
 mDescription=theData.description();
 setGuid(theData.guid());
 mManagement=theData.management();
 mInitialValues=theData.initialValues();
 mPhenology=theData.phenology();
 mPrevCrop=theData.prevCrop();
 mSiteData=theData.siteData();
 mSoil=theData.soil();
 mWeather=theData.weather();
 mStateVars=theData.stateVars();
 return *this;
}

// Accessors
QString MadDataset::name() const
{
  return mName;
}
QString MadDataset::description() const
{
  return mDescription;
}

MadDataClassificationManagement MadDataset::management() const
{
  return mManagement;
}
MadDataClassificationInitialValues MadDataset::initialValues() const
{
  return mInitialValues;
}
MadDataClassificationPhenology MadDataset::phenology() const
{
  return mPhenology;
}
MadDataClassificationPrevCrop MadDataset::prevCrop() const
{
  return mPrevCrop;
}
MadDataClassificationSiteData MadDataset::siteData() const
{
  return mSiteData;
}
MadDataClassificationSoil MadDataset::soil() const
{
  return mSoil;
}
MadDataClassificationWeather MadDataset::weather() const
{
  return mWeather;
}
MadStateVars MadDataset::stateVars() const
{
  return mStateVars;
}

// Mutators

void MadDataset::setName(QString theName)
{
  mName = theName;
}

void MadDataset::setDescription(QString theDescription)
{
  mDescription = theDescription;
}

void MadDataset::setManagement(MadDataClassificationManagement theManagementData)
{
  mManagement = theManagementData;
}

void MadDataset::setInitialValues(MadDataClassificationInitialValues theInitialValues)
{
  mInitialValues = theInitialValues;
}

void MadDataset::setPhenology(MadDataClassificationPhenology thePhenologyData)
{
  mPhenology = thePhenologyData;
}

void MadDataset::setPrevCrop(MadDataClassificationPrevCrop thePrevCropData)
{
  mPrevCrop = thePrevCropData;
}

void MadDataset::setSiteData(MadDataClassificationSiteData theSiteData)
{
  mSiteData = theSiteData;
}

void MadDataset::setSoil(MadDataClassificationSoil theSoilData)
{
  mSoil = theSoilData;
}

void MadDataset::setWeather(MadDataClassificationWeather theWeatherData)
{
  mWeather = theWeatherData;
}

void MadDataset::setStateVars(MadStateVars theStateVarsData)
{
  mStateVars = theStateVarsData;
}

bool MadDataset::fromXml(const QString theXml)
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



        //mImageFile=QString(myTopElement.firstChildElement("imageFile").text());
        return true;
    }
    else
    return false;
}

QString MadDataset::toXml()
{
  QString myString;
  myString+=QString("<dataset guid=\"" + guid() + "\">\n");
  myString+=QString(" <name>" + MadUtils::xmlEncode(mName) + "</name>\n");
  myString+=QString(" <description>" + MadUtils::xmlEncode(mDescription) + "</description>\n");
  myString+=mManagement.toXml();
  myString+=mPhenology.toXml();
  myString+=mPrevCrop.toXml();
  myString+=mInitialValues.toXml();
  myString+=mSoil.toXml();
  myString+=mSiteData.toXml();
  myString+=mWeather.toXml();
  myString+=mStateVars.toXml();
  myString+=QString("</dataset>\n");

  return myString;
}

QString MadDataset::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataset::toHtml()
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
