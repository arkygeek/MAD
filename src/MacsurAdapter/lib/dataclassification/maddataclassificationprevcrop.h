/***************************************************************************
 *   File:  maddataclassificationprevcrop.h created: 22/05/2013            *
 *   Class info: MadDataClassificationPrevCrop                             *
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

#ifndef MADDATACLASSIFICATIONPREVCROP_H
#define MADDATACLASSIFICATIONPREVCROP_H
#include "madsubcategory.h"

class MadDataClassificationPrevCrop
{
public:
  MadDataClassificationPrevCrop();

  // Accessors
  MadSubCategory crop() const;
  MadSubCategory sowingDate() const;
  MadSubCategory harvestDate() const;
  MadSubCategory yield() const;
  MadSubCategory residueMgmt() const;
  MadSubCategory fertilisation() const;
  MadSubCategory irrigation() const;

  // Mutators
  void setCrop(MadSubCategory theData);
  void setSowingDate(MadSubCategory theData);
  void setHarvestDate(MadSubCategory theData);
  void setYield(MadSubCategory theData);
  void setResidueMgmt(MadSubCategory theData);
  void setFertilisation(MadSubCategory theData);
  void setIrrigation(MadSubCategory theData);

private:
  MadSubCategory mCrop;
  MadSubCategory mSowingDate;
  MadSubCategory mHarvestDate;
  MadSubCategory mYield;
  MadSubCategory mResidueMgmt;
  MadSubCategory mFertilisation;
  MadSubCategory mIrrigation;

};

#endif // MADDATACLASSIFICATIONPREVCROP_H
