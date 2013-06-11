/***************************************************************************
 *   File:  maddataclassificationsoil.cpp created: 22/05/2013                                    *
 *   Class info: MadDataClassificationSoil                                               *
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
#include "maddataclassificationsoil.h"
#include "madsubcategory.h"
#include "../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationSoil::MadDataClassificationSoil() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadDataClassificationSoil::MadDataClassificationSoil(const MadDataClassificationSoil &theData)
{
  setGuid(theData.guid());
  setCarbonOrganic(theData.carbonOrganic());
  setNitrogenOrganic(theData.nitrogenOrganic());
  setTexture(theData.texture());
  setBulkDensity(theData.bulkDensity());
  setFieldCapacityMeas(theData.fieldCapacityMeas());
  setWiltingPointMeas(theData.wiltingPointMeas());
  setPfCurve(theData.pfCurve());
  setHydrCondCurve(theData.hydrCondCurve());
  setPh(theData.pH());
}

MadDataClassificationSoil& MadDataClassificationSoil::operator =(const MadDataClassificationSoil& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mCarbonOrganic=theData.carbonOrganic();
  mNitrogenOrganic=theData.nitrogenOrganic();
  mTexture=theData.texture();
  mBulkDensity=theData.bulkDensity();
  mFieldCapacityMeas=theData.fieldCapacityMeas();
  mWiltingPointMeas=theData.wiltingPointMeas();
  mPfCurve=theData.pfCurve();
  mHydrCondCurve=theData.hydrCondCurve();
  mPH=theData.mPH;
  return *this;
}

// Accessors
MadSubCategory MadDataClassificationSoil::carbonOrganic() const
{
  return mCarbonOrganic;
}
MadSubCategory MadDataClassificationSoil::nitrogenOrganic() const
{
  return mNitrogenOrganic;
}
MadSubCategory MadDataClassificationSoil::texture() const
{
  return mTexture;
}
MadSubCategory MadDataClassificationSoil::bulkDensity() const
{
  return mBulkDensity;
}
MadSubCategory MadDataClassificationSoil::fieldCapacityMeas() const
{
  return mFieldCapacityMeas;
}
MadSubCategory MadDataClassificationSoil::wiltingPointMeas() const
{
  return mWiltingPointMeas;
}
MadSubCategory MadDataClassificationSoil::pfCurve() const
{
  return mPfCurve;
}
MadSubCategory MadDataClassificationSoil::hydrCondCurve() const
{
  return mHydrCondCurve;
}
MadSubCategory MadDataClassificationSoil::pH() const
{
  return mPH;
}
// Mutators
void MadDataClassificationSoil::setCarbonOrganic(MadSubCategory theData)
{
  mCarbonOrganic = theData;
}

void MadDataClassificationSoil::setNitrogenOrganic(MadSubCategory theData)
{
  mNitrogenOrganic = theData;
}

void MadDataClassificationSoil::setTexture(MadSubCategory theData)
{
  mTexture = theData;
}

void MadDataClassificationSoil::setBulkDensity(MadSubCategory theData)
{
  mBulkDensity = theData;
}

void MadDataClassificationSoil::setFieldCapacityMeas(MadSubCategory theData)
{
  mFieldCapacityMeas = theData;
}

void MadDataClassificationSoil::setWiltingPointMeas(MadSubCategory theData)
{
  mWiltingPointMeas = theData;
}

void MadDataClassificationSoil::setPfCurve(MadSubCategory theData)
{
  mPfCurve = theData;
}

void MadDataClassificationSoil::setHydrCondCurve(MadSubCategory theData)
{
  mHydrCondCurve = theData;
}

void MadDataClassificationSoil::setPh(MadSubCategory theData)
{
  mPH = theData;
}


bool MadDataClassificationSoil::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("soil");
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

QString MadDataClassificationSoil::toXml()
{
  QString myString;
  myString+=QString("  <category name=\"soil\" guid=\"" + guid() + "\">\n");

  myString+=QString("    <tab name=\"Corg\">\n");
  myString+=mCarbonOrganic.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"Norg\">\n");
  myString+=mNitrogenOrganic.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"texture\">\n");
  myString+=mTexture.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"bulkDensity\">\n");
  myString+=mBulkDensity.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"fieldCapacity\">\n");
  myString+=mFieldCapacityMeas.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"wiltingPoint\">\n");
  myString+=mWiltingPointMeas.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"pfCurve\">\n");
  myString+=mPfCurve.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"hydrCondCurve\">\n");
  myString+=mHydrCondCurve.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"pH\">\n");
  myString+=mPH.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("  </category>\n");
  return myString;

}

QString MadDataClassificationSoil::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationSoil::toHtml()
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
