/***************************************************************************
 *   File:  maddataclassificationphenology.h created: 22/05/2013           *
 *   Class info: MadDataClassificationPhenology                            *
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

#ifndef MADDATACLASSIFICATIONPHENOLOGY_H
#define MADDATACLASSIFICATIONPHENOLOGY_H
#include "madsubcategory.h"

class MadDataClassificationPhenology
{
public:
  MadDataClassificationPhenology();

  // Accessors
  MadSubCategory emergence() const;
  MadSubCategory stemElongation() const;
  MadSubCategory earEmergence() const;
  MadSubCategory flowering() const;
  MadSubCategory yellowRipeness() const;

  // Mutators
  void setEmergence(MadSubCategory theData);
  void setStemElongation(MadSubCategory theData);
  void setEarEmergence(MadSubCategory theData);
  void setFlowering(MadSubCategory theData);
  void setYellowRipeness(MadSubCategory theData);

private:
  MadSubCategory mEmergence;
  MadSubCategory mStemElongation;
  MadSubCategory mEarEmergence;
  MadSubCategory mFlowering;
  MadSubCategory mYellowRipeness;

};

#endif // MADDATACLASSIFICATIONPHENOLOGY_H
