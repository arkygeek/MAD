/***************************************************************************
 *   File:  madcultivation.h created: 20/05/2013                                    *
 *   Class info: MADCultivation                                               *
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

#ifndef MADSVCROP_H
#define MADSVCROP_H
#include "../madsubcategory.h"

class MadSVCrop
{
public:
  MadSVCrop();

  // Accessors
  MadSubCategory agrBiomass() const;
  MadSubCategory weightOrgans() const;
  MadSubCategory rootBiomass() const;
  MadSubCategory nInAGrBiomass() const;
  MadSubCategory nInOrgans() const;
  MadSubCategory lai() const;

  // Mutators
  void setAgrBiomass(MadSubCategory theData);
  void setWeightOrgans(MadSubCategory theData);
  void setRootBiomass(MadSubCategory theData);
  void setNInAGrBiomass(MadSubCategory theData);
  void setNInOrgans(MadSubCategory theData);
  void setLai(MadSubCategory theData);

private:
  MadSubCategory mAgrBiomass;
  MadSubCategory mWeightOrgans;
  MadSubCategory mRootBiomass;
  MadSubCategory mNInAGrBiomass;
  MadSubCategory mNInOrgans;
  MadSubCategory mLai;
};

#endif // MADSVCROP_H
