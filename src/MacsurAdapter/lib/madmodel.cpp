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


