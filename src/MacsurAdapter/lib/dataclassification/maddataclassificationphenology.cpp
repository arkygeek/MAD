/***************************************************************************
 *   File:  maddataclassificationphenology.cpp created: 22/05/2013         *
 *   Class info: MadDataClassificationPhenology                            *
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

#include "maddataclassificationphenology.h"
#include "madsubcategory.h"

MadDataClassificationPhenology::MadDataClassificationPhenology()
{
}

// Accessors
MadSubCategory MadDataClassificationPhenology::emergence() const
{
  return mEmergence;
}
MadSubCategory MadDataClassificationPhenology::stemElongation() const
{
  return mStemElongation;
}
MadSubCategory MadDataClassificationPhenology::earEmergence() const
{
  return mEarEmergence;
}
MadSubCategory MadDataClassificationPhenology::flowering() const
{
  return mFlowering;
}
MadSubCategory MadDataClassificationPhenology::yellowRipeness() const
{
  return mYellowRipeness;
}

// Mutators
void MadDataClassificationPhenology::setEmergence(MadSubCategory theData)
{
  mEmergence = theData;
}

void MadDataClassificationPhenology::setStemElongation(MadSubCategory theData)
{
  mStemElongation = theData;
}

void MadDataClassificationPhenology::setEarEmergence(MadSubCategory theData)
{
  mEarEmergence = theData;
}

void MadDataClassificationPhenology::setFlowering(MadSubCategory theData)
{
  mFlowering = theData;
}

void MadDataClassificationPhenology::setYellowRipeness(MadSubCategory theData)
{
  mYellowRipeness = theData;
}
