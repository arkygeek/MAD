/***************************************************************************
 *   File:  madcsv.cpp created: 11/07/2013                                 *
 *   Class info: MadCsv                                                    *
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
#include "madcsv.h"

//Qt includes
#include <QString>


MadCsv::MadCsv()
{
}


/*
 *

//Local includes
#include "maddata.h"
#include "madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

MadData::MadData() : MadSerialisable(), MadGuid()
{
    setGuid();
    mName="No Name Set";
    mDescription="Not Set";
}

MadData::MadData(const MadData &theData)
{
    mName=theData.name();
    mDescription=theData.description();
    setGuid(theData.guid());
    mImageFile=theData.imageFile();
}

MadData& MadData::operator =(const MadData& theData)
{
    if (this == &theData) return *this; // gracefully handles self assignment

    mName=theData.name();
    mDescription=theData.description();
    setGuid(theData.guid());
    mImageFile=theData.imageFile();
    return *this;
}

// Accessors

QString MadData::name() const
{
    return mName;
}

QString MadData::description() const
{
    return mDescription;
}

QString MadData::imageFile() const
{
    return mImageFile;
}

// Mutators

void MadData::setName(QString theName)
{
    mName=theName;
}

void MadData::setDescription(QString theDescription)
{
    mDescription=theDescription;
}

void MadData::setImageFile(QString theImageFileName)
{
    mImageFile=theImageFileName;
}

// Others

bool MadData::fromXml(const QString theXml)
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

 *
 *
 */
