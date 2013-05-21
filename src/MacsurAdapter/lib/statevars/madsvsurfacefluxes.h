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


class MadSVSurfaceFluxes
{
public:
  MadSVSurfaceFluxes();

  // Accessors
  MadSubCategory et() const;
  MadSubCategory nh3Loss() const;
  MadSubCategory n2oLoss() const;
  MadSubCategory n2Loss() const;
  MadSubCategory ch4Loss() const;

  // Mutators
  void setEt(MadSubCategory theData);
  void setNh3Loss(MadSubCategory theData);
  void setN2oLoss(MadSubCategory theData);
  void setN2Loss(MadSubCategory theData);
  void setCh4Loss(MadSubCategory theData);

private:
  MadSubCategory mEt;
  MadSubCategory mNh3Loss;
  MadSubCategory mN2oLoss;
  MadSubCategory mN2Loss;
  MadSubCategory mCh4Loss;
};

#endif // MADSVSURFACEFLUXES_H

