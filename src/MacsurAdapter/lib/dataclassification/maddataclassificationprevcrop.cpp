/***************************************************************************
 *   File:  maddataclassificationprevcrop.cpp created: 22/05/2013          *
 *   Class info: MadDataClassificationPrevCrop                             *
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
#include "maddataclassificationprevcrop.h"
#include "madsubcategory.h"
#include "../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadDataClassificationPrevCrop::MadDataClassificationPrevCrop() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadDataClassificationPrevCrop::MadDataClassificationPrevCrop(const MadDataClassificationPrevCrop &theData)
{
  setGuid(theData.guid());
  setCrop(theData.crop());
  setSowingDate(theData.sowingDate());
  setHarvestDate(theData.harvestDate());
  setYield(theData.yield());
  setResidueMgmt(theData.residueMgmt());
  setFertilisation(theData.fertilisation());
  setIrrigation(theData.irrigation());
}

MadDataClassificationPrevCrop& MadDataClassificationPrevCrop::operator =(const MadDataClassificationPrevCrop& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mCrop=theData.crop();
  mSowingDate=theData.sowingDate();
  mHarvestDate=theData.harvestDate();
  mYield=theData.yield();
  mResidueMgmt=theData.residueMgmt();
  mFertilisation=theData.fertilisation();
  mIrrigation=theData.irrigation();
  return *this;
}


// Accessors
MadSubCategory MadDataClassificationPrevCrop::crop() const
{
  return mCrop;
}
MadSubCategory MadDataClassificationPrevCrop::sowingDate() const
{
  return mSowingDate;
}
MadSubCategory MadDataClassificationPrevCrop::harvestDate() const
{
  return mHarvestDate;
}
MadSubCategory MadDataClassificationPrevCrop::yield() const
{
  return mYield;
}
MadSubCategory MadDataClassificationPrevCrop::residueMgmt() const
{
  return mResidueMgmt;
}
MadSubCategory MadDataClassificationPrevCrop::fertilisation() const
{
  return mFertilisation;
}
MadSubCategory MadDataClassificationPrevCrop::irrigation() const
{
  return mIrrigation;
}

// Mutators
void MadDataClassificationPrevCrop::setCrop(MadSubCategory theData)
{
  mCrop = theData;
}

void MadDataClassificationPrevCrop::setSowingDate(MadSubCategory theData)
{
  mSowingDate = theData;
}

void MadDataClassificationPrevCrop::setHarvestDate(MadSubCategory theData)
{
  mHarvestDate = theData;
}

void MadDataClassificationPrevCrop::setYield(MadSubCategory theData)
{
  mYield = theData;
}

void MadDataClassificationPrevCrop::setResidueMgmt(MadSubCategory theData)
{
  mResidueMgmt = theData;
}

void MadDataClassificationPrevCrop::setFertilisation(MadSubCategory theData)
{
  mFertilisation = theData;
}

void MadDataClassificationPrevCrop::setIrrigation(MadSubCategory theData)
{
  mIrrigation = theData;
}

bool MadDataClassificationPrevCrop::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("prevcrop");
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

QString MadDataClassificationPrevCrop::toXml()
{
  QString myString;
  myString+=QString("  <prevcrop guid=\"" + guid() + "\">\n");

  myString+=QString("    <crop>\n");
  myString+=mCrop.toXml();
  myString+=QString("    </crop>\n");

  myString+=QString("    <sowingdate>\n");
  myString+=mSowingDate.toXml();
  myString+=QString("    </sowingdate>\n");

  myString+=QString("    <harvestdate>\n");
  myString+=mHarvestDate.toXml();
  myString+=QString("    </harvestdate>\n");

  myString+=QString("    <yield>\n");
  myString+=mYield.toXml();
  myString+=QString("    </yield>\n");

  myString+=QString("    <residuemgmt>\n");
  myString+=mResidueMgmt.toXml();
  myString+=QString("    </residuemgmt>\n");

  myString+=QString("    <fertilisation>\n");
  myString+=mFertilisation.toXml();
  myString+=QString("    </fertilisation>\n");

  myString+=QString("    <irrigation>\n");
  myString+=mIrrigation.toXml();
  myString+=QString("    </irrigation>\n");

  myString+=QString("  </prevcrop>\n");
  return myString;

}

QString MadDataClassificationPrevCrop::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadDataClassificationPrevCrop::toHtml()
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
