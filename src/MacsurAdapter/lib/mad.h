/***************************************************************************
 *   File:  mad.h created: 02/05/2013                                    *
 *   Class info:                                                *
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

/**
 * @file mad.h
 */

#ifndef MAD_H
#define MAD_H

//Qt Includes
#include <QMap>
#include <QPair>
#include <QString>

//Local includes
#include "madmodel.h"
#include "maddata.h"

/*
 * struct Category { QString name; QList<SubCategory> children; };
 * struct SubCategory { QString name; bool minData; int depth; ... };
 * QList<Category>
 *
 */




//typedef QPair <QString, QList<MadSubCategory> > MadCategory;

/**
 * @brief MadTripleMap
 */
typedef QMap <QString,QPair<bool,QString> > MadTripleMap;
/**
 * @brief MadModelInfo
 */
typedef QPair <QPair<QString,QString>, QPair<QString,QString> > MadModelInfo;
/**
 * @brief MadModelMap
 */
//typedef QMap < QString, MadModel > MadModelMap;
//typedef QMap <QString,QPair<QString,float> > MadReportMap;
/**
 * @brief The ModelTheme enum
 */
enum ModelTheme {CropM, LiveM, TradeM};
/**
 * @brief The Scale enum
 */
enum Scale {Farm, Locality, Region, National, International, Global};
/**
 * @brief The Nuts enum
 */
enum Nuts {Nuts1, Nuts2, Nuts3};
/**
 * @brief The AreaUnits enum
 */
enum AreaUnits {Dunum, Hectare, Acre, SquareKm, SquareMile};
/**
 * @brief The FileType enum
 */
enum FileType {CSV, TAB, OtherDelimited, Binary};
/**
 * @brief The EnergyType enum
 */
enum EnergyType {KCalories, TDN};
/**
 * @brief The DataClass enum
 */
enum DataClass {Platinum, Gold, Silver, Bronze};

#endif // MAD_H
