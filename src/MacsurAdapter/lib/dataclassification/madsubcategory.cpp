/***************************************************************************
 *   File:  madsubcategory.cpp created: 21/05/2013                         *
 *   Class info: MadSubCategory                                            *
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
#include "madsubcategory.h"
#include "../madutils.h"

// Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

// Constructor
MadSubCategory::MadSubCategory() : MadSerialisable(), MadGuid()
{
  setGuid();
  mMinData= 0;
  mDepth = 0.0;
  mObservations = 0;
  mWeightPoints = 0.0;
  mReplicates = 0;
}

// copy constructor
MadSubCategory::MadSubCategory(const MadSubCategory &theSubCategory)
{
  setGuid(theSubCategory.guid());
  mMinData = theSubCategory.minData();
  mDepth = theSubCategory.depth();
  mObservations = theSubCategory.observations();
  mWeightPoints = theSubCategory.weightPoints();
  mReplicates = theSubCategory.replicates();
}

MadSubCategory & MadSubCategory::operator = (const MadSubCategory& theSubCategory)
{
  // gracefully handles self assignment
  if (this == &theSubCategory) return *this;
  setGuid(theSubCategory.guid());
  mMinData = theSubCategory.minData();
  mDepth = theSubCategory.depth();
  mObservations = theSubCategory.observations();
  mWeightPoints = theSubCategory.weightPoints();
  mReplicates = theSubCategory.replicates();
  return *this;
}

// accessors

bool MadSubCategory::minData() const
{
  return mMinData;
}

float MadSubCategory::depth() const
{
  return mDepth;
}

int MadSubCategory::observations() const
{
  return mObservations;
}

float MadSubCategory::weightPoints() const
{
  return mWeightPoints;
}

int MadSubCategory::replicates() const
{
  return mReplicates;
}

// Mutators
void MadSubCategory::setMinData(bool theBool)
{
  mMinData = theBool;
}

void MadSubCategory::setDepth(float theValue)
{
  mDepth = theValue;
}

void MadSubCategory::setObservations(int theValue)
{
  mObservations = theValue;
}

void MadSubCategory::setWeightPoints(float theValue)
{
  mWeightPoints = theValue;
}

void MadSubCategory::setReplicates(int theValue)
{
  mReplicates = theValue;
}

bool MadSubCategory::fromXml(const QString theXml)
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

QString MadSubCategory::toXml()
{
  QString myString;
  //myString+=QString("<dataset guid=\"" + guid() + "\">\n");
  myString+=QString("      <minData>" + QString::number(mMinData) + "</minData>\n");
  myString+=QString("      <depth>" + QString::number(mDepth) + "</depth>\n");
  myString+=QString("      <observations>" + QString::number(mObservations) + "</observations>\n");
  myString+=QString("      <weightPoints>" + QString::number(mWeightPoints) + "</weightPoints>\n");
  myString+=QString("      <replicates>" + QString::number(mReplicates) + "</replicates>\n");
  //myString+=QString("</dataset>\n");
  return myString;
}

QString MadSubCategory::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadSubCategory::toHtml()
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
