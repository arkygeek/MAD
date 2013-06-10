/***************************************************************************
 *   File:  maddataclassificationmanagement.cpp created: 22/05/2013       *
 *   Class info: MadDataClassificationManagement                          *
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
#include "maddataclassificationmanagement.h"
#include "madsubcategory.h"
#include "../madutils.h"

// Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationManagement::MadDataClassificationManagement() : MadSerialisable(), MadGuid()
{
    setGuid();
}

MadDataClassificationManagement::MadDataClassificationManagement(const MadDataClassificationManagement &theData)
{
    setGuid(theData.guid());
    setVariety(theData.variety());
    setSowing(theData.sowing());
    setHarvest(theData.harvest());
    setFertilisation(theData.fertilisation());
    setIrrigation(theData.irrigation());
    setSeedDensity(theData.seedDensity());
    setYield(theData.yield());
    setTillage(theData.tillage());
}

MadDataClassificationManagement& MadDataClassificationManagement::operator = (const MadDataClassificationManagement& theData)
{
    // gracefully handles self assignment
    if (this == &theData) return *this;
    setGuid(theData.guid());
    mVariety=theData.variety();
    mSowing=theData.sowing();
    mHarvest=theData.harvest();
    mFertilisation=theData.fertilisation();
    mIrrigation=theData.irrigation();
    mSeedDensity=theData.seedDensity();
    mYield=theData.yield();
    mTillage=theData.tillage();
    return *this;
}

// Accessors
MadSubCategory MadDataClassificationManagement::variety () const
{
    return mVariety;
}
MadSubCategory MadDataClassificationManagement::sowing () const
{
    return mSowing;
}
MadSubCategory MadDataClassificationManagement::harvest () const
{
    return mHarvest;
}
MadSubCategory MadDataClassificationManagement::fertilisation () const
{
    return mFertilisation;
}
MadSubCategory MadDataClassificationManagement::irrigation () const
{
    return mIrrigation;
}
MadSubCategory MadDataClassificationManagement::seedDensity () const
{
    return mSeedDensity;
}
MadSubCategory MadDataClassificationManagement::yield () const
{
    return mYield;
}
MadSubCategory MadDataClassificationManagement::tillage () const
{
    return mTillage;
}

// Mutators
void MadDataClassificationManagement::setVariety(MadSubCategory theData)
{
    mVariety = theData;
}
void MadDataClassificationManagement::setSowing(MadSubCategory theData)
{
    mSowing = theData;
}
void MadDataClassificationManagement::setHarvest(MadSubCategory theData)
{
    mHarvest = theData;
}
void MadDataClassificationManagement::setFertilisation(MadSubCategory theData)
{
    mFertilisation = theData;
}
void MadDataClassificationManagement::setIrrigation(MadSubCategory theData)
{
    mIrrigation = theData;
}
void MadDataClassificationManagement::setSeedDensity(MadSubCategory theData)
{
    mSeedDensity = theData;
}
void MadDataClassificationManagement::setYield(MadSubCategory theData)
{
    mYield = theData;
}
void MadDataClassificationManagement::setTillage(MadSubCategory theData)
{
    mTillage = theData;
}


bool MadDataClassificationManagement::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("management");
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

QString MadDataClassificationManagement::toXml()
{
  QString myString;
  myString+=QString("  <management guid=\"" + guid() + "\">\n");

  myString+=QString("    <variety>\n");
  myString+=mVariety.toXml();
  myString+=QString("    </variety>\n");

  myString+=QString("    <sowing>\n");
  myString+=mSowing.toXml();
  myString+=QString("    </sowing>\n");

  myString+=QString("    <harvest>\n");
  myString+=mHarvest.toXml();
  myString+=QString("    </harvest>\n");

  myString+=QString("    <fertilisation>\n");
  myString+=mFertilisation.toXml();
  myString+=QString("    </fertilisation>\n");

  myString+=QString("    <irrigation>\n");
  myString+=mIrrigation.toXml();
  myString+=QString("    </irrigation>\n");

  myString+=QString("    <seeddensity>\n");
  myString+=mSeedDensity.toXml();
  myString+=QString("    </seeddensity>\n");

  myString+=QString("    <yield>\n");
  myString+=mYield.toXml();
  myString+=QString("    </yield>\n");

  myString+=QString("    <tillage>\n");
  myString+=mTillage.toXml();
  myString+=QString("    </tillage>\n");

  myString+=QString("  </management>\n");

  return myString;
}

QString MadDataClassificationManagement::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationManagement::toHtml()
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
