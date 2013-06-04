/***************************************************************************
 *   File:  madsvobservations.cpp created: 21/05/2013                      *
 *   Class info: MadSVObservations                                         *
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
#include "madsvobservations.h"
#include "../madsubcategory.h"
#include "../../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadSVObservations::MadSVObservations() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadSVObservations::MadSVObservations(const MadSVObservations &theData)
{
  setGuid(theData.guid());
  setLodging(theData.lodging());
  setPestsOrDiseases(theData.pestsOrDiseases());
  setDamages(theData.damages());
}

MadSVObservations& MadSVObservations::operator =(const MadSVObservations& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mLodging=theData.lodging();
  mPestsOrDiseases=theData.pestsOrDiseases();
  mDamages=theData.damages();
  return *this;
}

// Accessors
MadSubCategory MadSVObservations::lodging() const
{
  return mLodging;
}
MadSubCategory MadSVObservations::pestsOrDiseases() const
{
  return mPestsOrDiseases;
}
MadSubCategory MadSVObservations::damages() const
{
  return mDamages;
}

// Mutators
void MadSVObservations::setLodging(MadSubCategory theData)
{
  mLodging = theData;
}

void MadSVObservations::setPestsOrDiseases(MadSubCategory theData)
{
  mPestsOrDiseases = theData;
}

void MadSVObservations::setDamages(MadSubCategory theData)
{
  mDamages = theData;
}

bool MadSVObservations::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("svobservations");
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

QString MadSVObservations::toXml()
{
  QString myString;
  myString+=QString("    <svobservations guid=\"" + guid() + "\">\n");

  myString+=QString("     <lodging>\n");
  myString+=mLodging.toXml();
  myString+=QString("     </lodging>\n");

  myString+=QString("     <pestsordiseases>\n");
  myString+=mPestsOrDiseases.toXml();
  myString+=QString("     </pestsordiseases>\n");

  myString+=QString("     <damage>\n");
  myString+=mDamages.toXml();
  myString+=QString("     </damage>\n");

  myString+=QString("    </svobservations>\n");
  return myString;

}

QString MadSVObservations::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadSVObservations::toHtml()
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
