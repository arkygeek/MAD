/***************************************************************************
 *   File:  maddataclassificationmanagement.h created: 22/05/2013         *
 *   Class info: MadDataClassificationManagement                          *
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

#ifndef MADDATACLASSIFICATIONMANAGEMENT_H
#define MADDATACLASSIFICATIONMANAGEMENT_H

class QString; // forward declaration

// local includes
#include "madsubcategory.h"
#include "../madguid.h"
#include "../madserialisable.h"

// Qt includes
#include <QString>

class MadDataClassificationManagement : public MadSerialisable, public MadGuid
{
public:
  MadDataClassificationManagement();
  MadDataClassificationManagement(const MadDataClassificationManagement& theData);
  MadDataClassificationManagement& operator = (const MadDataClassificationManagement& theData);

// Accessors
  MadSubCategory variety() const;
  MadSubCategory sowing() const;
  MadSubCategory harvest() const;
  MadSubCategory fertilisation() const;
  MadSubCategory irrigation() const;
  MadSubCategory seedDensity() const;
  MadSubCategory yield() const;
  MadSubCategory tillage() const;


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

/**
* true for success, false for failure.
* @see MadSerialisable
* @note this class inherits the serialisable interface
* so it MUST implement this
*/
bool fromXml(const QString theXml);


// Mutators
void setVariety(MadSubCategory theData);
void setSowing(MadSubCategory theData);
void setHarvest(MadSubCategory theData);
void setFertilisation(MadSubCategory theData);
void setIrrigation(MadSubCategory theData);
void setSeedDensity(MadSubCategory theData);
void setYield(MadSubCategory theData);
void setTillage(MadSubCategory theData);

private:
MadSubCategory mVariety;
MadSubCategory mSowing;
MadSubCategory mHarvest;
MadSubCategory mFertilisation;
MadSubCategory mIrrigation;
MadSubCategory mSeedDensity;
MadSubCategory mYield;
MadSubCategory mTillage;

};

#endif // MADDATACLASSIFICATIONMANAGEMENT_H
