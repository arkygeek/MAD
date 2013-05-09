/***************************************************************************
 *   File:  madguid.cpp created: 09/05/2013                                    *
 *   Class info: MadGuid                                               *
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
#include "madguid.h"

//Qt includes
#include <QUuid>


MadGuid::MadGuid()
{
}

//MadGuid::~MadGuid() // gives error - improper use of implicitly declared...
//{
//}

/**
 * @brief MadGuid::guid
 * @return
 */
QString MadGuid::guid() const
{
    return mGuid;
}

void MadGuid::setGuid(QString theGuid)
{
    if (theGuid.isEmpty())
    {
        mGuid=QUuid::createUuid().toString().replace("{","").replace("}","");
    }
    else
    {
        mGuid=theGuid;
    }
}
