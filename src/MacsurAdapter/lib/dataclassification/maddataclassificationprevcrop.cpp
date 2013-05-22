/***************************************************************************
 *   File:  maddataclassificationprevcrop.cpp created: 22/05/2013          *
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

#include "maddataclassificationprevcrop.h"
#include "madsubcategory.h"

MadDataClassificationPrevCrop::MadDataClassificationPrevCrop()
{
}

// Accessors
MadSubCategory MadDataClassificationPrevCrop::crop() const
{
  return mCrop;
}
MadSubCategory MadDataClassificationPrevCrop::sowingDate() const
{
  return mSowingDate;
}
MadSubCategory MadDataClassificationPrevCrop::harvestDate() const
{
  return mHarvestDate;
}
MadSubCategory MadDataClassificationPrevCrop::yield() const
{
  return mYield;
}
MadSubCategory MadDataClassificationPrevCrop::residueMgmt() const
{
  return mResidueMgmt;
}
MadSubCategory MadDataClassificationPrevCrop::fertilisation() const
{
  return mFertilisation;
}
MadSubCategory MadDataClassificationPrevCrop::irrigation() const
{
  return mIrrigation;
}

// Mutators
void MadDataClassificationPrevCrop::setCrop(MadSubCategory theData)
{
  mCrop = theData;
}

void MadDataClassificationPrevCrop::setSowingDate(MadSubCategory theData)
{
  mSowingDate = theData;
}

void MadDataClassificationPrevCrop::setHarvestDate(MadSubCategory theData)
{
  mHarvestDate = theData;
}

void MadDataClassificationPrevCrop::setYield(MadSubCategory theData)
{
  mYield = theData;
}

void MadDataClassificationPrevCrop::setResidueMgmt(MadSubCategory theData)
{
  mResidueMgmt = theData;
}

void MadDataClassificationPrevCrop::setFertilisation(MadSubCategory theData)
{
  mFertilisation = theData;
}

void MadDataClassificationPrevCrop::setIrrigation(MadSubCategory theData)
{
  mIrrigation = theData;
}
