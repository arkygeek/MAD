/***************************************************************************
 *   File:  madsvobservations.h created: 21/05/2013                                    *
 *   Class info: MadSVObservations                                               *
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

#ifndef MADSVOBSERVATIONS_H
#define MADSVOBSERVATIONS_H
#include "../madsubcategory.h"

class MadSVObservations
{
public:
  MadSVObservations();

  // Accessors
  MadSubCategory lodging() const;
  MadSubCategory pestsOrDiseases() const;
  MadSubCategory damages() const;

  // Mutators
  void setLodging(MadSubCategory theData);
  void setPestsOrDiseases(MadSubCategory theData);
  void setDamages(MadSubCategory theData);

private:
  MadSubCategory mLodging;
  MadSubCategory mPestsOrDiseases;
  MadSubCategory mDamages;
};

#endif // MADSVOBSERVATIONS_H
