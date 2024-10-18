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
 * dtyTuiBaseUnit.h
 *
 *  Created on: Sep, 24th 2024
 *      Author: Marco Dau
 *
 */
 
#ifndef DTY_TUI_BASE_UNIT_H
#define DTY_TUI_BASE_UNIT_H

#include <cstdint>
#include "tuiBase.h"

class dtyTuiBaseUnit_t  {

public:
    // ****************************************************
    // section start **** GENERAL *****

    dtyTuiBaseUnit_t   (tuiBase_t* p_unit);

    // section end   **** GENERAL ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****


    // section end   **** WRITE ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** DISPLAY *****


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****

    // section end   **** SELECT ***** 
    // ****************************************************


protected:

    // ****************************************************
    // section start **** GENERAL *****


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****


    // section end   **** WRITE ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** DISPLAY *****


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****

    // section **** SELECT ****

    // section end   **** SELECT ***** 
    // ****************************************************

private:

    tuiBase_t* g_unit;
    uint16_t g_id;
    uint8_t  g_flag;

};


#endif 	// DTY_TUI_BASE_UNIT_H
