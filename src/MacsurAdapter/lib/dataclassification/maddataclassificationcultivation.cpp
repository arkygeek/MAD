/***************************************************************************
 *   File:  maddataclassificationcultivation.cpp created: 22/05/2013       *
 *   Class info: MadDataClassificationCultivation                          *
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
#include "maddataclassificationcultivation.h"
#include "madsubcategory.h"
#include "../madutils.h"

// Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationCultivation::MadDataClassificationCultivation() : MadSerialisable(), MadGuid()
{
    setGuid();
}

MadDataClassificationCultivation::MadDataClassificationCultivation(const MadDataClassificationCultivation &theData)
{
    setGuid(theData.guid());
}

MadDataClassificationCultivation& MadDataClassificationCultivation::operator = (const MadDataClassificationCultivation& theData)
{
    // gracefully handles self assignment
    if (this == &theData) return *this;
    //mName=theData.name();
    //mDescription=theData.description();
    //setGuid(theData.guid());
    //mImageFile=theData.imageFile();
    return *this;
}

// Accessors
MadSubCategory MadDataClassificationCultivation::variety () const
{
    return mVariety;
}
MadSubCategory MadDataClassificationCultivation::sowing () const
{
    return mSowing;
}
MadSubCategory MadDataClassificationCultivation::harvest () const
{
    return mHarvest;
}
MadSubCategory MadDataClassificationCultivation::fertilisation () const
{
    return mFertilisation;
}
MadSubCategory MadDataClassificationCultivation::irrigation () const
{
    return mIrrigation;
}
MadSubCategory MadDataClassificationCultivation::seedDensity () const
{
    return mSeedDensity;
}
MadSubCategory MadDataClassificationCultivation::yield () const
{
    return mYield;
}
MadSubCategory MadDataClassificationCultivation::tillage () const
{
    return mTillage;
}

// Mutators
void MadDataClassificationCultivation::setVariety(MadSubCategory theData)
{
    mVariety = theData;
}
void MadDataClassificationCultivation::setSowing(MadSubCategory theData)
{
    mSowing = theData;
}
void MadDataClassificationCultivation::setHarvest(MadSubCategory theData)
{
    mHarvest = theData;
}
void MadDataClassificationCultivation::setFertilisation(MadSubCategory theData)
{
    mFertilisation = theData;
}
void MadDataClassificationCultivation::setIrrigation(MadSubCategory theData)
{
    mIrrigation = theData;
}
void MadDataClassificationCultivation::setSeedDensity(MadSubCategory theData)
{
    mSeedDensity = theData;
}
void MadDataClassificationCultivation::setYield(MadSubCategory theData)
{
    mYield = theData;
}
void MadDataClassificationCultivation::setTillage(MadSubCategory theData)
{
    mTillage = theData;
}


bool MadDataClassificationCultivation::fromXml(const QString theXml)
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

QString MadDataClassificationCultivation::toXml()
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

QString MadDataClassificationCultivation::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationCultivation::toHtml()
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
