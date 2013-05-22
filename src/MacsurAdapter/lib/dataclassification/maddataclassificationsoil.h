/***************************************************************************
 *   File:  maddataclassificationsoil.h created: 22/05/2013                                    *
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

#ifndef MADDATACLASSIFICATIONSOIL_H
#define MADDATACLASSIFICATIONSOIL_H
#include "madsubcategory.h"

class MadDataClassificationSoil
{
public:
  MadDataClassificationSoil();

  // Accessors
  MadSubCategory carbonOrganic() const;
  MadSubCategory nitrogenOrganic() const;
  MadSubCategory texture() const;
  MadSubCategory bulkDensity() const;
  MadSubCategory fieldCapacityMeas() const;
  MadSubCategory wiltingPointMeas() const;
  MadSubCategory pfCurve() const;
  MadSubCategory hydrCondCurve() const;
  MadSubCategory pH() const;

  // Mutators
  void setCarbonOrganic(MadSubCategory theData);
  void setNitrogenOrganic(MadSubCategory theData);
  void setTexture(MadSubCategory theData);
  void setBulkDensity(MadSubCategory theData);
  void setFieldCapacityMeas(MadSubCategory theData);
  void setWiltingPointMeas(MadSubCategory theData);
  void setPfCurve(MadSubCategory theData);
  void setHydrCondCurve(MadSubCategory theData);
  void setPH(MadSubCategory theData);

private:
  MadSubCategory mCarbonOrganic;
  MadSubCategory mNitrogenOrganic;
  MadSubCategory mTexture;
  MadSubCategory mBulkDensity;
  MadSubCategory mFieldCapacityMeas;
  MadSubCategory mWiltingPointMeas;
  MadSubCategory mPfCurve;
  MadSubCategory mHydrCondCurve;
  MadSubCategory mPH;

};

#endif // MADDATACLASSIFICATIONSOIL_H
