/***************************************************************************
 *   File:  madsubcategory.cpp created: 21/05/2013                         *
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

#include "madsubcategory.h"

MadSubCategory::MadSubCategory()
{
}

// accessors

bool MadSubCategory::minData() const
{
  return mMinData;
}

float MadSubCategory::depth() const
{
  return mDepth;
}

int MadSubCategory::observations() const
{
  return mObservations;
}

float MadSubCategory::weightPoints() const
{
  return mWeightPoints;
}

int MadSubCategory::replicates() const
{
  return mReplicates;
}

// Mutators
void MadSubCategory::setMinData(bool theBool)
{
  mMinData = theBool;
}

void MadSubCategory::setDepth(float theValue)
{
  mDepth = theValue;
}

void MadSubCategory::setObservations(int theValue)
{
  mObservations = theValue;
}

void MadSubCategory::setWeightPoints(float theValue)
{
  mWeightPoints = theValue;
}

void MadSubCategory::setReplicates(int theValue)
{
  mReplicates = theValue;
}
