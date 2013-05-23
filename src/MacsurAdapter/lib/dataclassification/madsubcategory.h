/***************************************************************************
 *   File:  madsubcategory.h created: 21/05/2013                           *
 *   Class info: MadSubCategory                                            *
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

#ifndef MADSUBCATEGORY_H
#define MADSUBCATEGORY_H

// Local includes
#include "../madguid.h"
#include "../madserialisable.h"

// Qt includes
#include <QString>

class MadSubCategory : public MadSerialisable, public MadGuid
{
public:
  MadSubCategory();
  MadSubCategory(const MadSubCategory& theData);
  MadSubCategory& operator = (const MadSubCategory& theData);

  // Accessors
  bool minData() const;
  float depth() const;
  int observations() const;
  float weightPoints() const;
  int replicates() const;

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
  void setMinData(bool theBool);
  void setDepth(float theValue);
  void setObservations(int theValue);
  void setWeightPoints(float theValue);
  void setReplicates(int theValue);

private:
  bool mMinData;
  float mDepth;
  int mObservations;
  float mWeightPoints;
  int mReplicates;

};

#endif // MADSUBCATEGORY_H
