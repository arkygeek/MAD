/***************************************************************************
 *   File:  madsvobservations.cpp created: 21/05/2013                      *
 *   Class info: MadSVObservations                                         *
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

#include "madsvobservations.h"
#include "../madsubcategory.h"

MadSVObservations::MadSVObservations()
{
}

// Accessors
MadSubCategory MadSVObservations::lodging() const
{
  return mLodging;
}
MadSubCategory MadSVObservations::pestsOrDiseases() const
{
  return mPestsOrDiseases;
}
MadSubCategory MadSVObservations::damages() const
{
  return mDamages;
}

// Mutators
void MadSVObservations::setLodging(MadSubCategory theData)
{
  mLodging = theData;
}

void MadSVObservations::setPestsOrDiseases(MadSubCategory theData)
{
  mPestsOrDiseases = theData;
}

void MadSVObservations::setDamages(MadSubCategory theData)
{
  mDamages = theData;
}
