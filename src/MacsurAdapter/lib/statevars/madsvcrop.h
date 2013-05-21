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
  /**
   * @brief agrBiomass
   * @return
   */
  MadSubCategory agrBiomass() const;
  /**
   * @brief weightOrgans
   * @return
   */
  MadSubCategory weightOrgans() const;
  /**
   * @brief rootBiomass
   * @return
   */
  MadSubCategory rootBiomass() const;
  /**
   * @brief nInAGrBiomass
   * @return
   */
  MadSubCategory nInAGrBiomass() const;
  /**
   * @brief nInOrgans
   * @return
   */
  MadSubCategory nInOrgans() const;
  /**
   * @brief lai
   * @return
   */
  MadSubCategory lai() const;

  // Mutators
  /**
   * @brief setAgrBiomass
   * @param theData
   */
  void setAgrBiomass(MadSubCategory theData);
  /**
   * @brief setWeightOrgans
   * @param theData
   */
  void setWeightOrgans(MadSubCategory theData);
  /**
   * @brief setRootBiomass
   * @param theData
   */
  void setRootBiomass(MadSubCategory theData);
  /**
   * @brief setNInAGrBiomass
   * @param theData
   */
  void setNInAGrBiomass(MadSubCategory theData);
  /**
   * @brief setNInOrgans
   * @param theData
   */
  void setNInOrgans(MadSubCategory theData);
  /**
   * @brief setLai
   * @param theData
   */
  void setLai(MadSubCategory theData);

private:

  MadSubCategory mAgrBiomass;
  /**
   * @brief mWeightOrgans
   */
  MadSubCategory mWeightOrgans;
  /**
   * @brief mRootBiomass
   */
  MadSubCategory mRootBiomass;
  /**
   * @brief mNInAGrBiomass
   */
  MadSubCategory mNInAGrBiomass;
  /**
   * @brief mNInOrgans
   */
  MadSubCategory mNInOrgans;
  /**
   * @brief mLai
   */
  MadSubCategory mLai;
};

#endif // MADSVCROP_H
