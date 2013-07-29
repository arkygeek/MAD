// based on code from:
/***************************************************************************
                          lacrop.h  -  A crop class
                             -------------------
    begin                : March 2006
    copyright            : (C) 2003 by Tim Sutton  tim@linfiniti.com
                         :     2007 by Jason Jorgenson  arkygeek@gmail.com
 ***************************************************************************/


/***************************************************************************
 *   File:  madmodel.h created: 02/05/2013                                 *
 *   Class info: MADModel                                                  *
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

#ifndef MADMODEL_H
#define MADMODEL_H


// forward declarations
class QString;

//Local includes
#include "madserialisable.h"
#include "madguid.h"
#include "mad.h"

//Qt includes
#include <QString>
//#include <QDomDocument>
//#include <QDomElement>
//#include <QDebug>


/**
 * @brief The MadModel class, to represent a ModelTheme
 */
class MadModel : public MadSerialisable, public MadGuid
{
public:
  /** Constructor . */
  MadModel();
  /** Destructor . */
  //~MadModel();
  /** copy constructor */
  MadModel(const MadModel& theModel);
  /** Assignement operator */
  MadModel& operator = (const MadModel& theModel);

  //
  // Accessors
  //

  /** The name of this model */
  QString name() const;
  /** The description of this model */
  QString description() const;

  /** The image file associated with the model */
  QString imageFile() const;


  //
  // Mutators
  //

  /** Set the modelName
   * @see name()
   */
  void setName(QString theName);

  /** Set the model description
   * @see description()
   */
  void setDescription(QString theDescription);

  /** Set the image file
   * @see imageFile()
   */
  void setImageFile(QString theImageFileName);

  /** Return an xml representation of this layer
   * @note this class inherits the serialisable interface so it MUST implement this
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
   * @note this class inherits the serialisable interface so it MUST implement this
   */
  bool fromXml(const QString theXml);



private:
  /** The name for this model */
  QString mName;

  /** The description for this model */
  QString mDescription;
  QString mImageFile;


};

#endif // MADMODEL_H

