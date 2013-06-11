/***************************************************************************
 *   File:  maddataclassificationphenology.cpp created: 22/05/2013         *
 *   Class info: MadDataClassificationPhenology                            *
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
#include "maddataclassificationphenology.h"
#include "madsubcategory.h"
#include "../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationPhenology::MadDataClassificationPhenology() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadDataClassificationPhenology::MadDataClassificationPhenology(const MadDataClassificationPhenology &theData)
{
  setGuid(theData.guid());
  setEmergence(theData.emergence());
  setStemElongation(theData.stemElongation());
  setEarEmergence(theData.earEmergence());
  setFlowering(theData.flowering());
  setYellowRipeness(theData.yellowRipeness());
}

MadDataClassificationPhenology& MadDataClassificationPhenology::operator = (const MadDataClassificationPhenology& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mEmergence=theData.emergence();
  mStemElongation=theData.stemElongation();
  mEarEmergence=theData.earEmergence();
  mFlowering=theData.flowering();
  mYellowRipeness=theData.yellowRipeness();
  return *this;
}
// Accessors
MadSubCategory MadDataClassificationPhenology::emergence() const
{
  return mEmergence;
}
MadSubCategory MadDataClassificationPhenology::stemElongation() const
{
  return mStemElongation;
}
MadSubCategory MadDataClassificationPhenology::earEmergence() const
{
  return mEarEmergence;
}
MadSubCategory MadDataClassificationPhenology::flowering() const
{
  return mFlowering;
}
MadSubCategory MadDataClassificationPhenology::yellowRipeness() const
{
  return mYellowRipeness;
}

// Mutators
void MadDataClassificationPhenology::setEmergence(MadSubCategory theData)
{
  mEmergence = theData;
}

void MadDataClassificationPhenology::setStemElongation(MadSubCategory theData)
{
  mStemElongation = theData;
}

void MadDataClassificationPhenology::setEarEmergence(MadSubCategory theData)
{
  mEarEmergence = theData;
}

void MadDataClassificationPhenology::setFlowering(MadSubCategory theData)
{
  mFlowering = theData;
}

void MadDataClassificationPhenology::setYellowRipeness(MadSubCategory theData)
{
  mYellowRipeness = theData;
}


bool MadDataClassificationPhenology::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("phenology");
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

QString MadDataClassificationPhenology::toXml()
{
  QString myString;
  myString+=QString("  <category name=\"phenology\" guid=\"" + guid() + "\">\n");

  myString+=QString("    <tab name=\"emergence\">\n");
  myString+=mEmergence.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"stemelongation\">\n");
  myString+=mStemElongation.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"earemergence\">\n");
  myString+=mEarEmergence.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"flowering\">\n");
  myString+=mFlowering.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("    <tab name=\"yellowripeness\">\n");
  myString+=mYellowRipeness.toXml();
  myString+=QString("    </tab>\n");

  myString+=QString("  </category>\n");
  return myString;
}

QString MadDataClassificationPhenology::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationPhenology::toHtml()
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
