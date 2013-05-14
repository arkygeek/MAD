/***************************************************************************
 *   File:  madguid.h created: 09/05/2013                                  *
 *   Class info: MadGuid                                                   *
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

#ifndef MADGUID_H
#define MADGUID_H

#include <QString>

/**
 * @brief The MadGuid class
 * An abstract base class that has a Globally Unique Identifier (GUID)
 * to represent a unique instance
 */
class MadGuid
{
public:
    /**   Constructor  */
    MadGuid();

    /**   Destructor   */
    //virtual ~MadGuid(); //throws a compiler error

    /** Retrieve the GUID */
    QString guid() const;

    void setGuid(QString theGuid="");

private:
    /**  A Globally Unique IDentifier (GUID) for this model */
    QString mGuid;

};

#endif // MADGUID_H