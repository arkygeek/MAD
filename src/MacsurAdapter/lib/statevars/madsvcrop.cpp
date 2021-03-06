/***************************************************************************
 *   File:  madcultivation.cpp created: 20/05/2013                         *
 *   Class info: MADCultivation                                            *
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

#include "madsvcrop.h"
#include "../madsubcategory.h"

MadSVCrop::MadSVCrop()
{
}

// Accessors
MadSubCategory MadSVCrop::agrBiomass() const
{
  return mAgrBiomass;
}
MadSubCategory MadSVCrop::weightOrgans() const
{
  return mWeightOrgans;
}

MadSubCategory MadSVCrop::rootBiomass() const
{
  return mRootBiomass;
}

MadSubCategory MadSVCrop::nInAGrBiomass() const
{
  return mNInAGrBiomass;
}

MadSubCategory MadSVCrop::nInOrgans() const
{
  return mNInOrgans;
}

MadSubCategory MadSVCrop::lai() const
{
  return mLai;
}

// Mutators
void MadSVCrop::setAgrBiomass(MadSubCategory theData)
{
  mAgrBiomass = theData;
}

void MadSVCrop::setWeightOrgans(MadSubCategory theData)
{
  mWeightOrgans = theData;
}

void MadSVCrop::setRootBiomass(MadSubCategory theData)
{
  mRootBiomass = theData;
}

void MadSVCrop::setNInAGrBiomass(MadSubCategory theData)
{
  mNInAGrBiomass = theData;
}

void MadSVCrop::setNInOrgans(MadSubCategory theData)
{
  mNInOrgans = theData;
}

void MadSVCrop::setLai(MadSubCategory theData)
{
  mLai = theData;
}
