/***************************************************************************
 *   File:  madmodel.cpp created: 02/05/2013                                    *
 *   Class info: MADModel                                               *
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

//Local includes
#include "madmodel.h"
#include "madutils.h"


//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadModel::MadModel() : MadSerialisable(), MadGuid()
{
    setGuid();
    mName="No Name Set";
    mDescription="Not Set";
}

//MadModel::~MadModel()
//{
//}

// copy constructor

MadModel::MadModel(const MadModel &theModel)
{
    mName=theModel.name();
    mDescription=theModel.description();
    setGuid(theModel.guid());
    mImageFile=theModel.imageFile();
}

MadModel& MadModel::operator =(const MadModel& theModel)
{
    if (this == &theModel) return *this; // gracefully handles self assignment

    mName=theModel.name();
    mDescription=theModel.description();
    setGuid(theModel.guid());
    mImageFile=theModel.imageFile();
    return *this;
}

QString MadModel::name() const
{
    return mName;
}

QString MadModel::description() const
{
    return mDescription;
}

QString MadModel::imageFile() const
{
    return mImageFile;
}

/*****************/

void MadModel::setName(QString theName)
{
    mName=theName;
}

void MadModel::setDescription(QString theDescription)
{
    mDescription=theDescription;
}

void MadModel::setImageFile(QString theImageFileName)
{
    mImageFile=theImageFileName;
}

bool MadModel::fromXml(const QString theXml)
{
    QDomDocument myDocument("mydocument");
    myDocument.setContent(theXml);
    QDomElement myTopElement = myDocument.firstChildElement("model");
    if (myTopElement.isNull())
    {
        //TODO - just make this a warning
        qDebug("the top element couldn't be found!");
        setGuid(myTopElement.attribute("guid"));
        mName=MadUtils::xmlDecode(myTopElement.firstChildElement("name").text());
        mDescription=MadUtils::xmlDecode(myTopElement.firstChildElement("description").text());
        mImageFile=QString(myTopElement.firstChildElement("imageFile").text());
        return true;
    }
    else
    return false;
}

QString MadModel::toXml()
{
  QString myString;
  myString+=QString("<model guid=\"" + guid() + "\">\n");
    myString+=QString("  <name>" + MadUtils::xmlEncode(mName) + "</name>\n");
  myString+=QString("  <description>" + MadUtils::xmlEncode(mDescription) + "</description>\n");


//  switch (mAreaUnits)
//  {
//    case Dunum:
//      myString+=QString("  <areaUnits>Dunum</areaUnits>\n");
//      break;
//    case Hectare:
//      myString+=QString("  <areaUnits>Hectare</areaUnits>\n");
//      break;
//  }
  myString+=QString("  <imageFile>" + MadUtils::xmlEncode(mImageFile) + "</imageFile>\n");
  myString+=QString("</model>\n");
  return myString;
}

QString MadModel::toText()
{
  QString myString;
  myString+=QString("guid=>" + guid() + "\n");
  myString+=QString("name=>" + MadUtils::xmlEncode(mName) + "\n");
  myString+=QString("description=>" + MadUtils::xmlEncode(mDescription) + "\n");
  return myString;
}

QString MadModel::toHtml()
{
  QString myString;
  myString+="<h3>Details for " + MadUtils::xmlEncode(mName) + "</h3>";
    //myString+="<p>GUID:" + guid() + "</p>";
  myString+="<table>";
  myString+="<tr><td><b>Description: </b></td><td>" + mDescription + "</td></tr>";

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
