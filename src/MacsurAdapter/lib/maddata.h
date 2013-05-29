/***************************************************************************
 *   File:  maddata.h created: 09/05/2013                                  *
 *   Class info: MadData                                                   *
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

#ifndef MADDATA_H
#define MADDATA_H

class QString;  // forward declaration

//Local includes
#include "madserialisable.h"
#include "madguid.h"
#include "mad.h"

//Qt includes
#include <QString>

/**
 * @brief The MadData class
 */
class MadData : public MadSerialisable, public MadGuid
{
public:
  MadData();

  /** copy constructor */
  MadData(const MadData& theData);
  /** Assignement operator */
  MadData& operator = (const MadData& theData);

  //
  // Accessors
  //

  /**
   * @brief name (accessor) this is the dataset's name
   * @return
   */
  QString name() const;
  /**
   * @brief description (accessor) this is the dataset's description
   * @return
   */
  QString description() const;
  /** The image file associated with the dataset */
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



private:
  /** The name for this dataset */
  QString mName;
  /** The description for this dataset */
  QString mDescription;
  QString mImageFile;

};


#endif // MADDATA_H
