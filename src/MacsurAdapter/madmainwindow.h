/***************************************************************************
 *   File:  madmainwindow.h created: 01/05/2013                                    *
 *   Class info: MadMainWindow                                               *
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
#include "gui/maddataclassification.h" //this is only needed if non-modal

//Qt includes
#include <QModelIndex>


//Local includes
#include "ui_madmainwindowbase.h"

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

  private:
    MadDataClassification *pMadDataClassification;

  public slots:


  protected:
    /**
     * @brief changeEvent for translations in the future
     * @param e
     */
    void changeEvent(QEvent *e);

  private slots:
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
     * @brief loadTextFile to display in the 'about' text display on main page
     * @param theFileToLoad
     */
    void loadTextFile(const QString &theFileToLoad);
};

#endif // MADMAINWINDOW_H
