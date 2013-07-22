/***************************************************************************
 *   File:  madmainwindow.h created: 01/05/2013                            *
 *   Class info: MadMainWindow                                             *
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

#ifndef MADMAINWINDOW_H
#define MADMAINWINDOW_H


//Qt includes
#include <QModelIndex>
#include <QSortFilterProxyModel>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStandardItemModel>

//Local includes
#include "ui_madmainwindowbase.h"
#include "gui/maddataclassification.h" //needed if non-modal
#include "gui/madtextdisplayform.h" //needed if non-modal
#include "gui/madcsvreader.h"
#include "lib/mad.h"

//Doxygen stuff
/** @file lib/mad.h */

/**
 * This is the main GUI class
 * @author Jason Jorgenson
 */
class MadMainWindow : public QMainWindow, private Ui::MadMainWindow
{
  Q_OBJECT
  public:
  /**
   * This is the main form GUI of MAD (Macsur ADapter)
   * It sets up the required slot connections
   * and initialises the GUI
   * @param parent
   */
    explicit MadMainWindow(QWidget *parent = 0);

  //
  // Accessors //
  //

  QString modelText() const;
  QString userName() const;

  //
  // Mutators
  //

  void setModelText(QString theModelText);
  void setUserName(const QString& theUserName);

  void subIterate();
private:
    MadDataClassification *mpMadDataClassification;
    MadTextDisplayForm *mpMadTextDisplayForm;

    QString mModelText;
    //QxtCsvModel *pCsvModel;
    QSortFilterProxyModel *pFilterModel;

    QString mUserName;

    //
    // the CSV stuff
    //
    //QList<QStringList> mCsv;
    QStandardItemModel *mpModel;
    //QStandardItemModel *mpModel2;
    QList<QStandardItem*> mpStandardItemList;

    /**
     * @brief loadTextFile to display in the 'about' text display on main page
     * @param theFileToLoad
     */
    void loadTextFile(const QString &theFileToLoad);
    void loadCsvFile(const QString &theFileToLoad);

    void loadHtmlFile(const QString &theFileToLoad);

  public slots:


  protected:
    /**
     * @brief changeEvent for translations in the future
     * @param e
     */
    void changeEvent(QEvent *e);

  private slots:

    void checkString(QString &theTemporary, QChar theCharacter = 0);


    /**
     * @brief on_pbClassification_clicked
     */
    void on_pbClassification_clicked();
    /**
     * @brief on_cbAboutMain_currentIndexChanged
     * Updates the text in the text browser to reflect relevant info chosen
     * in the combo box.  Options are About, CropM, LiveM, TradeM, Credits
     * @param theSelection
     */
    void on_cbAboutMain_currentIndexChanged(const QString &theSelection);
    /**
     * @brief on_pbViewAsText_clicked show model info in new dialog as plain text
     */
    void on_pbViewAsText_clicked();
    /**
     * @brief on_actionOpen_triggered launches open file dialog to load settings
     */
    void on_actionOpen_triggered();
    /**
     * @brief on_lvwCurrentInventoryModels_clicked
     * triggers loading of model details for display in
     * @param theIndex
     */
    void on_lvwCurrentInventoryModels_clicked(const QModelIndex &theIndex);
    /**
     * @brief on_pbViewAsHtml_clicked views model details in HTML format
     */
    void on_pbViewAsHtml_clicked();
    /**
     * @brief on_pbExportCsv_clicked exports model details as a CSV file
     */
    void on_pbExportCsv_clicked();
    /**
     * @brief on_pbTableView_clicked gives a table view of the model details
     */
    void on_pbTableView_clicked();
    void on_modelNameComboBox_currentIndexChanged(const QString &theSelection);
    void on_pbLogin_clicked();
    void slotAcceptUserLogin (QString& theUsername,QString& thePassword);
    void on_pbAddVariable_clicked();
    void on_comboBox_currentIndexChanged(const QString &theSelection);
    void on_pbManageVariablesList_clicked();
    void on_pushButton_clicked();
};

#endif // MADMAINWINDOW_H
