/***************************************************************************
 *   File:  maddataclassificationsoil.cpp created: 22/05/2013                                    *
 *   Class info: MadDataClassificationSoil                                               *
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

#include "maddataclassificationsoil.h"
#include "madsubcategory.h"

MadDataClassificationSoil::MadDataClassificationSoil()
{
}

// Accessors
MadSubCategory MadDataClassificationSoil::carbonOrganic() const
{
  return mCarbonOrganic;
}
MadSubCategory MadDataClassificationSoil::nitrogenOrganic() const
{
  return mNitrogenOrganic;
}
MadSubCategory MadDataClassificationSoil::texture() const
{
  return mTexture;
}
MadSubCategory MadDataClassificationSoil::bulkDensity() const
{
  return mBulkDensity;
}
MadSubCategory MadDataClassificationSoil::fieldCapacityMeas() const
{
  return mFieldCapacityMeas;
}
MadSubCategory MadDataClassificationSoil::wiltingPointMeas() const
{
  return mWiltingPointMeas;
}
MadSubCategory MadDataClassificationSoil::pfCurve() const
{
  return mPfCurve;
}
MadSubCategory MadDataClassificationSoil::hydrCondCurve() const
{
  return mHydrCondCurve;
}
MadSubCategory MadDataClassificationSoil::pH() const
{
  return mPH;
}
// Mutators
void MadDataClassificationSoil::setCarbonOrganic(MadSubCategory theData)
{
  mCarbonOrganic = theData;
}

void MadDataClassificationSoil::setNitrogenOrganic(MadSubCategory theData)
{
  mNitrogenOrganic = theData;
}

void MadDataClassificationSoil::setTexture(MadSubCategory theData)
{
  mTexture = theData;
}

void MadDataClassificationSoil::setBulkDensity(MadSubCategory theData)
{
  mBulkDensity = theData;
}

void MadDataClassificationSoil::setFieldCapacityMeas(MadSubCategory theData)
{
  mFieldCapacityMeas = theData;
}

void MadDataClassificationSoil::setWiltingPointMeas(MadSubCategory theData)
{
  mWiltingPointMeas = theData;
}

void MadDataClassificationSoil::setPfCurve(MadSubCategory theData)
{
  mPfCurve = theData;
}

void MadDataClassificationSoil::setHydrCondCurve(MadSubCategory theData)
{
  mHydrCondCurve = theData;
}

void MadDataClassificationSoil::setPH(MadSubCategory theData)
{
  mPH = theData;
}
