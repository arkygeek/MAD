/***************************************************************************
 *   File:  madsvsurfacefluxes.h created: 21/05/2013                                    *
 *   Class info: MadSVSurfaceFluxes                                               *
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

#ifndef MADSVSURFACEFLUXES_H
#define MADSVSURFACEFLUXES_H

#include "../madsubcategory.h"

/**
 * @brief The MadSVSurfaceFluxes class
 */
class MadSVSurfaceFluxes
{
public:
  MadSVSurfaceFluxes();

  // Accessors
  /**
   * @brief et
   * @return
   */
  MadSubCategory et() const;
  /**
   * @brief nh3Loss
   * @return
   */
  MadSubCategory nh3Loss() const;
  /**
   * @brief n2oLoss
   * @return
   */
  MadSubCategory n2oLoss() const;
  /**
   * @brief n2Loss
   * @return
   */
  MadSubCategory n2Loss() const;
  /**
   * @brief ch4Loss
   * @return
   */
  MadSubCategory ch4Loss() const;

  // Mutators
  /**
   * @brief setEt
   * @param theData
   */
  void setEt(MadSubCategory theData);
  /**
   * @brief setNh3Loss
   * @param theData
   */
  void setNh3Loss(MadSubCategory theData);
  /**
   * @brief setN2oLoss
   * @param theData
   */
  void setN2oLoss(MadSubCategory theData);
  /**
   * @brief setN2Loss
   * @param theData
   */
  void setN2Loss(MadSubCategory theData);
  /**
   * @brief setCh4Loss
   * @param theData
   */
  void setCh4Loss(MadSubCategory theData);

private:
  /**
   * @brief mEt
   */
  MadSubCategory mEt;
  /**
   * @brief mNh3Loss
   */
  MadSubCategory mNh3Loss;
  /**
   * @brief mN2oLoss
   */
  MadSubCategory mN2oLoss;
  /**
   * @brief mN2Loss
   */
  MadSubCategory mN2Loss;
  /**
   * @brief mCh4Loss
   */
  MadSubCategory mCh4Loss;
};

#endif // MADSVSURFACEFLUXES_H

