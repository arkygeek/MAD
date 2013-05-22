/***************************************************************************
 *   File:  madsoil.cpp created: 21/05/2013                                *
 *   Class info: madSoil                                                   *
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

#include "madsvsoil.h"
#include "../madsubcategory.h"

MadSVSoil::MadSVSoil()
{
}

// Accessors
MadSubCategory MadSVSoil::soilWaterGrav() const
{
  return mSoilWaterGrav;
}

MadSubCategory MadSVSoil::pressureHeads() const
{
  return mPressureHeads;
}

MadSubCategory MadSVSoil::nMin() const
{
  return mNMin;
}

MadSubCategory MadSVSoil::soilWaterSensorCal() const
{
  return mSoilWaterSensorCal;
}

MadSubCategory MadSVSoil::waterFluxBottomRoot() const
{
  return mWaterFluxBottomRoot;
}

MadSubCategory MadSVSoil::nitrogenFluxBottomRoot() const
{
  return mNitrogenFluxBottomRoot;
}

// Mutators
void MadSVSoil::setSoilWaterGrav(MadSubCategory theData)
{
  mSoilWaterGrav = theData;
}

void MadSVSoil::setPressureHeads(MadSubCategory theData)
{
  mPressureHeads = theData;
}

void MadSVSoil::setNMin(MadSubCategory theData)
{
  mNMin = theData;
}

void MadSVSoil::setSoilWaterSensorCal(MadSubCategory theData)
{
  mSoilWaterSensorCal = theData;
}

void MadSVSoil::setWaterFluxBottomRoot(MadSubCategory theData)
{
  mWaterFluxBottomRoot = theData;
}

void MadSVSoil::setNitrogenFluxBottomRoot(MadSubCategory theData)
{
  mNitrogenFluxBottomRoot = theData;
}
