/***************************************************************************
 *   File:  madutils.h created: 06/05/2013                                 *
 *   Class info: MadUtils                                                  *
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

#ifndef MADUTILS_H
#define MADUTILS_H

class QString;
class QStringList;

//Local includes
#include "mad.h"
#include "madmodel.h"
#include "maddata.h"

//QtIncludes
#include <QHash>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QColumnView>
#include <QStandardItemModel>


class MadUtils
{
public:
    MadUtils();
    /** @brief userSettingsDirPath
     * Find the place on the filesystem where user data is stored
     *
     * Typically, this will be ~/.macsurAdapter
     *
     * @return QString containing the relevant directory name
     */
    static const QString userSettingsDirPath();

    /** @brief uerModelProfilesDirPath
     * Find the place on the filesystem where user defined model
     * profiles are stored.
     *
     * Typically this will be ~/.macsurAdapter/modelProfiles
     *
     * @return QString containing the relevant directory name
     */
    static const QString userDatasetClassificationDirPath();

    /**
     * @brief userDatasetParametersDirPath
     * Find the place on the filesystem where user defined model
     * parameter profiles are stored.
     *
     * Typically this will be ~/.macsurAdapter/animalParameters
     *
     * @return QString containing the relevant directory name
     */
    static const QString userDatasetParametersDirPath();

    /**
     * @brief getModelOutputDir
     * Get the place where model outputs are to be stored.
     * By default this is in ~/.macsurAdapter/modelOutputs
     * But if modelOutputsDir is specified in QSettings, it will override
     * the default.
     */
    static const QString getModelOutputDir();

    /**
     * @brief userImagesDirPath
     * Find the place on the filesystem where user images
     * are stored.
     *
     * Typically this will be ~/.macsurAdapter/images
     *
     * @return QString containing the relevant directory name
     */
    static const QString userImagesDirPath();

    /**
     * @brief ModelMap (typedef)
     * This typedef is used to refer to a collection of layersets.
     * the key is the layerset name
     * the value is the layerset itself
     */
    typedef QMap<QString,MadModel> ModelMap;

    /**
     * @brief getAvailableModels
     * Get a QMap of the avaliable layersets in the users layersets directory
     * @return a QMap<QString,OmgLayerSet> where
     * the QString key is the layerset name
     **/
    static MadUtils::ModelMap getAvailableModels();

    /**
     * @brief getModel
     * Get a MadModel given its GUID.
     * If no matching model is found, a blank one is
     * returned.
     */
    static MadModel getModel(QString theGuid);

    /** @brief sortList
     * Sort a string list into descending alphabetic order
     * and return the result.
     * @param theList - the QStringList to be sorted
     * @return QStringList - sorted in descending alphabetical order
     */
    static QStringList sortList(QStringList theList);

    /** @brief uniqueList
     * Remove any duplucate entries from a sorted list
     * @param theList - the QStringList to be sorted
     * @return QStringList - a list with no sequential duplicates
     */
    static QStringList uniqueList(QStringList theList);

    /** @brief createTextFile
     * A helper method to easily write a file to disk.
     * @param theFileName - the filename to be created or overwritten
     * @param theData - the data that will be written into the file
     * @return bool - false if the file could not be written
     */
    static bool createTextFile(QString theFileName, QString theData);

    /** @brief xmlEncode
     * A helper method to xml encode any special chars in a string
     * (< > & etc) will become (&lt; &gt; &amp; etc)
     * @param QString - the string to be properly encoded
     * @return A QString with the special chars properly encoded
     */
    static QString xmlEncode(QString theString);

    /** @brief xmlDecode
     * A helper method to xml deencode any special chars in a string
     * (&lt; &gt; &amp; etc) will become (< > & etc)
     * @param QString - the string to be properly decoded
     * @return A QString with the encoded chars properly decoded
     */
    static QString xmlDecode(QString theString);

    /**
     * @brief csvDecode
     * @param theString
     * @return
     */
    QStandardItemModel &csvDecodeToQSIModel(const QString theFileToLoad);


    /** @brief getStandardCss
     * Get the standard style sheet for reports. Typically this will be
     * used like this:
     * QString myStyle = getStandardCss();
     * textBrowserFoo->document()->setDefaultStylesheet(myStyle);
     */
    static QString getStandardCss();

    /**
        * Find the place on the filesystem where user created
        * conversion tables in csv format are stored
        *
        * Typically this will be ~/.macsurAdapter/conversionTables
        *
        * @return QString containing the relevant directory name
        */
       static const QString userConversionTablesDirPath();

    QString openGraphicFile();
    QString saveFile();

private:
  void checkString(QString &theTemporary, QChar theCharacter);
  //QStandardItemModel *mpModel;
  QList<QStandardItem*> mpStandardItemList;
  QStandardItemModel *mpModelFromCsv;

};

#endif // MADUTILS_H
