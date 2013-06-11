/***************************************************************************
 *   File:  maddataclassificationsitedata.cpp created: 22/05/2013          *
 *   Class info: MadDataClassificationSiteData                             *
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
#include "maddataclassificationsitedata.h"
#include "madsubcategory.h"
#include "../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationSiteData::MadDataClassificationSiteData() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadDataClassificationSiteData::MadDataClassificationSiteData(const MadDataClassificationSiteData &theData)
{
  setGuid(theData.guid());
  setLatitude(theData.latitude());
  setLongitude(theData.longitude());
  setAltitude(theData.altitude());
}

MadDataClassificationSiteData& MadDataClassificationSiteData::operator =(const MadDataClassificationSiteData& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mLatitude=theData.latitude();
  mLongitude=theData.longitude();
  mAltitude=theData.altitude();
  return *this;
}
// Accessors
MadSubCategory MadDataClassificationSiteData::latitude() const
{
  return mLatitude;
}
MadSubCategory MadDataClassificationSiteData::longitude() const
{
  return mLongitude;
}
MadSubCategory MadDataClassificationSiteData::altitude() const
{
  return mAltitude;
}

// Mutators
void MadDataClassificationSiteData::setLatitude(MadSubCategory theData)
{
  mLatitude = theData;
}

void MadDataClassificationSiteData::setLongitude(MadSubCategory theData)
{
  mLongitude = theData;
}

void MadDataClassificationSiteData::setAltitude(MadSubCategory theData)
{
  mAltitude = theData;
}

bool MadDataClassificationSiteData::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("site");
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

QString MadDataClassificationSiteData::toXml()
{
  QString myString;
  myString+=QString("  <category name=\"site\" guid=\"" + guid() + "\">\n");

  myString+=QString("     <tab name=\"latitude\">\n");
  myString+=mLatitude.toXml();
  myString+=QString("     </tab>\n");

  myString+=QString("     <tab name=\"longitude\">\n");
  myString+=mLongitude.toXml();
  myString+=QString("     </tab>\n");

  myString+=QString("     <tab name=\"altitude\">\n");
  myString+=mAltitude.toXml();
  myString+=QString("     </tab>\n");

  myString+=QString("  </category>\n");
  return myString;

}

QString MadDataClassificationSiteData::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationSiteData::toHtml()
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
