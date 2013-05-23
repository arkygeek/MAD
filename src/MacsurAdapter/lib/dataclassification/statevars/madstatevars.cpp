/***************************************************************************
 *   File:  madstatevars.cpp created: 21/05/2013                           *
 *   Class info: MadStateVars                                              *
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

#include "madstatevars.h"
#include "madsvcrop.h"
#include "madsvsoil.h"
#include "madsvsurfacefluxes.h"
#include "madsvobservations.h"
#include "../madsubcategory.h"
#include "../../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadStateVars::MadStateVars() : MadSerialisable(), MadGuid()
{
  setGuid();
}

MadStateVars::MadStateVars(const MadStateVars &theData)
{
  setGuid(theData.guid());
}

MadStateVars& MadStateVars::operator =(const MadStateVars& theData)
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

MadSVCrop MadStateVars::cropCategories() const
{
  return mCropCategories;
}
MadSVSoil MadStateVars::soilCategories() const
{
  return mSoilCategories;
}
MadSVSurfaceFluxes MadStateVars::surfaceFluxesCategories() const
{
  return mSurfaceFluxes;
}
MadSVObservations MadStateVars::observationCategories() const
{
  return mObservations;
}

// Mutators

void MadStateVars::setCropCategories(MadSVCrop theMadSVCrop)
{
  mCropCategories = theMadSVCrop;
}
void MadStateVars::setSoilCategories(MadSVSoil theData)
{
  mSoilCategories = theData;
}

void MadStateVars::setSurfaceFluxesCategories(MadSVSurfaceFluxes theMadSVSurfaceFluxes)
{
  mSurfaceFluxes = theMadSVSurfaceFluxes;
}

void MadStateVars::setObservationCategories(MadSVObservations theData)
{
  mObservations = theData;
}

bool MadStateVars::fromXml(const QString theXml)
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

QString MadStateVars::toXml()
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

QString MadStateVars::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  //myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  //myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}
