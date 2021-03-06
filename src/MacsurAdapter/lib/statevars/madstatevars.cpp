/***************************************************************************
 *   File:  madstatevars.cpp created: 21/05/2013                                    *
 *   Class info: MadStateVars                                               *
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

#include "madstatevars.h"
#include "madsvcrop.h"
#include "madsvsoil.h"
#include "madsvsurfacefluxes.h"
#include "madsvobservations.h"
#include "../madsubcategory.h"

MadStateVars::MadStateVars()
{
}

// Accessors
MadSVCrop MadStateVars::cropCategories() const
{
  return mCropCategories;
}
MadSVSoil MadStateVars::soilCategories() const
{
  return mSoilCategories;
}
MadSVSurfaceFluxes MadStateVars::surfaceFluxes() const
{
  return mSurfaceFluxes;
}
MadSVObservations MadStateVars::observationCategories() const
{
  return mObservations;
}

// Mutators

void MadStateVars::setCropCategories(MadSVCrop theMadSVCrop)
{
  mCropCategories = theMadSVCrop;
}
void MadStateVars::setSoilCategories(MadSVSoil theMadSVSoil)
{
  mSoilCategories = theMadSVSoil;
}

void MadStateVars::setSurfaceFluxes(MadSVSurfaceFluxes theMadSVSurfaceFluxes)
{
  mSurfaceFluxes = theMadSVSurfaceFluxes;
}

void MadStateVars::setObservationCategories(MadSVObservations theMadSVObservations)
{
  mObservations = theMadSVObservations;
}
