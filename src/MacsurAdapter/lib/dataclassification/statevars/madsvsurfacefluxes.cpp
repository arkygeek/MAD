/***************************************************************************
 *   File:  madsvsurfacefluxes.cpp created: 21/05/2013                     *
 *   Class info: MadSVSurfaceFluxes                                        *
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

#include "madsvsurfacefluxes.h"
#include "../madsubcategory.h"
#include "../../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadSVSurfaceFluxes::MadSVSurfaceFluxes() : MadSerialisable(), MadGuid()
{
  setGuid();

  MadSubCategory mEt;
  MadSubCategory mNh3Loss;
  MadSubCategory mN2oLoss;
  MadSubCategory mN2Loss;
  MadSubCategory mCh4Loss;
}

MadSVSurfaceFluxes::MadSVSurfaceFluxes(const MadSVSurfaceFluxes &theData)
{
  setGuid(theData.guid());
  setEt(theData.et());
  setNh3Loss(theData.nh3Loss());
  setN2oLoss(theData.n2oLoss());
  setN2Loss(theData.n2Loss());
  setCh4Loss(theData.ch4Loss());
}

MadSVSurfaceFluxes& MadSVSurfaceFluxes::operator =(const MadSVSurfaceFluxes& theData)
{
  // gracefully handles self assignment
  if (this == &theData) return *this;
  setGuid(theData.guid());
  mEt=theData.et();
  mNh3Loss=theData.nh3Loss();
  mN2oLoss=theData.n2oLoss();
  mN2Loss=theData.n2Loss();
  mCh4Loss=theData.ch4Loss();
  return *this;
}

// Accessors
MadSubCategory MadSVSurfaceFluxes::et() const
{
  return mEt;
}
MadSubCategory MadSVSurfaceFluxes::nh3Loss() const
{
  return mNh3Loss;
}

MadSubCategory MadSVSurfaceFluxes::n2oLoss() const
{
  return mN2oLoss;
}

MadSubCategory MadSVSurfaceFluxes::n2Loss() const
{
  return mN2Loss;
}

MadSubCategory MadSVSurfaceFluxes::ch4Loss() const
{
  return mCh4Loss;
}

// Mutators
void MadSVSurfaceFluxes::setEt(MadSubCategory theData)
{
  mEt = theData;
}

void MadSVSurfaceFluxes::setNh3Loss(MadSubCategory theData)
{
  mNh3Loss = theData;
}

void MadSVSurfaceFluxes::setN2oLoss(MadSubCategory theData)
{
  mN2oLoss = theData;
}

void MadSVSurfaceFluxes::setN2Loss(MadSubCategory theData)
{
  mN2Loss = theData;
}

void MadSVSurfaceFluxes::setCh4Loss(MadSubCategory theData)
{
  mCh4Loss = theData;
}

bool MadSVSurfaceFluxes::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("surfacefluxes");
    if (myTopElement.isNull())
    {
        //TODO - just make this a warning
        qDebug("the top element couldn't be found!");
        setGuid(myTopElement.attribute("guid"));
        //mEt=MadUtils::xmlDecode(myTopElement.firstChildElement("et").text());
        //mNh3Loss=MadUtils::xmlDecode(myTopElement.firstChildElement("nh3Loss").text());
        //mN2oLoss=MadUtils::xmlDecode(myTopElement.firstChildElement("n2oLoss").text());
        //mN2Loss=MadUtils::xmlDecode(myTopElement.firstChildElement("n2Loss").text());
        //ch4Loss()=MadUtils::xmlDecode(myTopElement.firstChildElement("ch4Loss").text());
        return true;
    }
    else
    return false;
}

QString MadSVSurfaceFluxes::toXml()
{
  QString myString;
  myString+=QString("     <subTab name=\"surfaceFluxes\" guid=\"" + guid() + "\">\n");

  myString+=QString("      <subCategory name=\"ET\">\n");
  myString+=mEt.toXml();
  myString+=QString("      </subCategory>\n");

  myString+=QString("      <subCategory name=\"NH3loss\">\n");
  myString+=mNh3Loss.toXml();
  myString+=QString("      </subCategory>\n");

  myString+=QString("      <subCategory name=\"N2Oloss\">\n");
  myString+=mN2oLoss.toXml();
  myString+=QString("      </subCategory>\n");

  myString+=QString("      <subCategory name=\"N2loss\">\n");
  myString+=mN2Loss.toXml();
  myString+=QString("      </subCategory>\n");

  myString+=QString("      <subCategory name=\"CH4loss\">\n");
  myString+=mCh4Loss.toXml();
  myString+=QString("      </subCategory>\n");

  myString+=QString("     </subTab>\n");
  return myString;
}

QString MadSVSurfaceFluxes::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  /** @TODO I need to figure out how to turn the sub category into text */
  //myString+=QString("et=>" + MadUtils::xmlEncode(mEt) + "</et>\n");
  //myString+=QString("nh3Loss=>" + MadUtils::xmlEncode(mNh3Loss) + "</nh3Loss>\n");
  //myString+=QString("n2oLoss=>" + MadUtils::xmlEncode(mN2oLoss) + "</n2oLoss>\n");
  //myString+=QString("n2Loss=>" + MadUtils::xmlEncode(mN2Loss) + "</n2Loss>\n");
  //myString+=QString("ch4Loss=>" + MadUtils::xmlEncode(mCh4Loss) + "</ch4Loss>\n");
  return myString;
}

QString MadSVSurfaceFluxes::toHtml()
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
