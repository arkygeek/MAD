/***************************************************************************
 *   File:  madsoil.cpp created: 21/05/2013                                *
 *   Class info: madSoil                                                   *
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
#include "madsvsoil.h"
#include "../madsubcategory.h"
#include "../../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>


MadSVSoil::MadSVSoil() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadSVSoil::MadSVSoil(const MadSVSoil &theData)
{
  setGuid(theData.guid());
  setSoilWaterGrav(theData.soilWaterGrav());
  setPressureHeads(theData.pressureHeads());
  setNMin(theData.nMin());
  setSoilWaterSensorCal(theData.soilWaterSensorCal());
  setWaterFluxBottomRoot(theData.waterFluxBottomRoot());
  setNitrogenFluxBottomRoot(theData.nitrogenFluxBottomRoot());
}

MadSVSoil& MadSVSoil::operator =(const MadSVSoil& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mSoilWaterGrav=theData.soilWaterGrav();
  mPressureHeads=theData.pressureHeads();
  mNMin=theData.nMin();
  mSoilWaterSensorCal=theData.soilWaterSensorCal();
  mWaterFluxBottomRoot=theData.waterFluxBottomRoot();
  mNitrogenFluxBottomRoot=theData.nitrogenFluxBottomRoot();
  return *this;
}


// Accessors
MadSubCategory MadSVSoil::soilWaterGrav() const
{
  return mSoilWaterGrav;
}

MadSubCategory MadSVSoil::pressureHeads() const
{
  return mPressureHeads;
}

MadSubCategory MadSVSoil::nMin() const
{
  return mNMin;
}

MadSubCategory MadSVSoil::soilWaterSensorCal() const
{
  return mSoilWaterSensorCal;
}

MadSubCategory MadSVSoil::waterFluxBottomRoot() const
{
  return mWaterFluxBottomRoot;
}

MadSubCategory MadSVSoil::nitrogenFluxBottomRoot() const
{
  return mNitrogenFluxBottomRoot;
}

// Mutators
void MadSVSoil::setSoilWaterGrav(MadSubCategory theData)
{
  mSoilWaterGrav = theData;
}

void MadSVSoil::setPressureHeads(MadSubCategory theData)
{
  mPressureHeads = theData;
}

void MadSVSoil::setNMin(MadSubCategory theData)
{
  mNMin = theData;
}

void MadSVSoil::setSoilWaterSensorCal(MadSubCategory theData)
{
  mSoilWaterSensorCal = theData;
}

void MadSVSoil::setWaterFluxBottomRoot(MadSubCategory theData)
{
  mWaterFluxBottomRoot = theData;
}

void MadSVSoil::setNitrogenFluxBottomRoot(MadSubCategory theData)
{
  mNitrogenFluxBottomRoot = theData;
}

bool MadSVSoil::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("svsoil");
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

QString MadSVSoil::toXml()
{
  QString myString;
  myString+=QString("    <subTab name=\"svsoil\" guid=\"" + guid() + "\">\n");

  myString+=QString("     <subCategory name=\"soilWaterGrav\">\n");
  myString+=mSoilWaterGrav.toXml();
  myString+=QString("     </subCategory>\n");

  myString+=QString("     <subCategory name=\"pressureHeads\">\n");
  myString+=mPressureHeads.toXml();
  myString+=QString("     </subCategory>\n");

  myString+=QString("     <subCategory name=\"Nmin\">\n");
  myString+=mNMin.toXml();
  myString+=QString("     </subCategory>\n");

  myString+=QString("     <subCategory name=\"soilWaterSensorCal\">\n");
  myString+=mSoilWaterSensorCal.toXml();
  myString+=QString("     </subCategory>\n");

  myString+=QString("     <subCategory name=\"waterFluxBottomRoot\">\n");
  myString+=mWaterFluxBottomRoot.toXml();
  myString+=QString("     </subCategory>\n");

  myString+=QString("     <subCategory name=\"NitrogenFluxBottomRoot\">\n");
  myString+=mNitrogenFluxBottomRoot.toXml();
  myString+=QString("     </subCategory>\n");

  myString+=QString("    </subTab>\n");
  return myString;


}

QString MadSVSoil::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadSVSoil::toHtml()
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
