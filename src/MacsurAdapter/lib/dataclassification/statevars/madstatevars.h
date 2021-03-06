/***************************************************************************
 *   File:  madstatevars.h created: 21/05/2013                             *
 *   Class info: MadStateVars                                              *
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

#ifndef MADSTATEVARS_H
#define MADSTATEVARS_H

// local includes
#include "madsvcrop.h"
#include "madsvsoil.h"
#include "madsvsurfacefluxes.h"
#include "madsvobservations.h"
#include "../madsubcategory.h"
#include "../../madutils.h"

//Qt includes
#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

/**
 * @brief The MadStateVars class.  This contains 4 sub categories
 * @file "madsvcrop.h"
 */
class MadStateVars : public MadSerialisable, public MadGuid
{
public:
  MadStateVars();
  MadStateVars(const MadStateVars& theData);
  MadStateVars& operator = (const MadStateVars& theData);

  // Accessors
  MadSVCrop cropCategories() const;
  MadSVSoil soilCategories() const;
  MadSVSurfaceFluxes surfaceFluxesCategories() const;
  MadSVObservations observationCategories() const;

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

  void setCropCategories(MadSVCrop theMadSVCrop);
  void setSoilCategories(MadSVSoil theData);
  void setSurfaceFluxesCategories(MadSVSurfaceFluxes theData);
  void setObservationCategories(MadSVObservations theData);

private:
  MadSVCrop mCropCategories;
  MadSVSoil mSoilCategories;
  MadSVSurfaceFluxes mSurfaceFluxes;
  MadSVObservations mObservations;
};

#endif // MADSTATEVARS_H
