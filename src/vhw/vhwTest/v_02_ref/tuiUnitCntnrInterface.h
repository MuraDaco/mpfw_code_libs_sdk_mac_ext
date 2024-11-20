//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork
//  Copyright (C) (2023) Marco Dau
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  You can contact me by the following email address
//  marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
//  
//  *******************************************************************************

/*
 * tuiUnitCntnrInterface_t.h
 *
 *  Created on: Nov,  5th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_CNTNR_INTERFACE_H
#define TUI_UNIT_CNTNR_INTERFACE_H

class dtyString_t;
class dtyStringInfo_t;
class tuiGraphicAbstract_t;

class tuiUnitCntnrInterface_t {

public:

// ****************************************************
// section start **** CHILDREN MANAGEMENT *****

    // to be implemented whether the class manages children
    virtual void updCoordNboundsChilds          (void) {};

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STREAM CONTAINER DATA BLOCK MANAGEMENT *****

    virtual void cntnrInit           ([[maybe_unused]] dtyString_t* p_pString, [[maybe_unused]] dtyStringInfo_t* p_pStringInfo) {};
    virtual void cntnrUpdParams      ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};

    // section end   **** STREAM CONTAINER DATA BLOCK MANAGEMENT *****
    // ****************************************************
    // --------------------------



};

#endif 	// TUI_UNIT_CNTNR_INTERFACE_H
