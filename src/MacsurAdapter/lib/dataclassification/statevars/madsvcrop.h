/***************************************************************************
 *   File:  madcultivation.h created: 20/05/2013                           *
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

#ifndef MADSVCROP_H
#define MADSVCROP_H

class QString;  //  forward declaration

// local includes
#include "../madsubcategory.h"
#include "../../madguid.h"
#include "../../madserialisable.h"

// Qt includes
#include <QString>

class MadSVCrop : public MadSerialisable, public MadGuid
{
public:
  MadSVCrop();

  MadSVCrop(const MadSVCrop& theData);
  MadSVCrop& operator = (const MadSVCrop& theData);

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

  // Text functions

  /** Return an xml representation of this layer
   * @note this class inherits the serialisable interface
   * so it MUST implement this
   */
  QString toXml();

  /** Return a plain text representation of this layer
   */
  QString toText();

  /** Return a html text representation of this layer
   */
  QString toHtml();

  /** Read this object from xml and return result as
   * true for success, false for failure.
   * @see MadSerialisable
   * @note this class inherits the serialisable interface
   * so it MUST implement this
   */
  bool fromXml(const QString theXml);

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
