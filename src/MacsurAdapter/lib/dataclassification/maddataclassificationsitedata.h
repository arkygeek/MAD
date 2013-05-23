/***************************************************************************
 *   File:  maddataclassificationsitedata.h created: 22/05/2013            *
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

#ifndef MADDATACLASSIFICATIONSITEDATA_H
#define MADDATACLASSIFICATIONSITEDATA_H


class QString;  //  forward declaration

// local includes
#include "madsubcategory.h"
#include "../madguid.h"
#include "../madserialisable.h"

// Qt includes
#include <QString>

class MadDataClassificationSiteData : public MadSerialisable, public MadGuid
{
public:
  MadDataClassificationSiteData();
  MadDataClassificationSiteData(const MadDataClassificationSiteData& theData);
  MadDataClassificationSiteData& operator = (const MadDataClassificationSiteData& theData);

  // Accessors
  MadSubCategory latitude() const;
  MadSubCategory longitude() const;
  MadSubCategory altitude() const;

  // Text functions

  /** Return an xml representation of this layer
   * @note this class inherits the serialisable interface
   * so it MUST implement this
   */
  QString toXml();

  /** Return a plain text representation of this layer
   */
  QString toText();

  /** Return a html text representation of this layer
   */
  QString toHtml();

  /** Read this object from xml and return result as
   * true for success, false for failure.
   * @see MadSerialisable
   * @note this class inherits the serialisable interface
   * so it MUST implement this
   */
  bool fromXml(const QString theXml);

  // Mutators
  void setLatitude(MadSubCategory theData);
  void setLongitude(MadSubCategory theData);
  void setAltitude(MadSubCategory theData);

private:
  MadSubCategory mLatitude;
  MadSubCategory mLongitude;
  MadSubCategory mAltitude;

};

#endif // MADDATACLASSIFICATIONSITEDATA_H
