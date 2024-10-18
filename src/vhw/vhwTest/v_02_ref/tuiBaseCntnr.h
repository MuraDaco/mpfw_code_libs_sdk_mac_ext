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
 * tuiBaseCntnr.h
 *
 *  Created on: Aug, 12th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_CNTNR_H
#define TUI_BASE_CNTNR_H

#include "tuiBase.h"
#include "dtyBaseCntnrUnit.h"

class tuiBaseCntnr_t : public tuiBase_t {

public:

    tuiBaseCntnr_t      (const char* p_strName, box_t  p_box,   dtyBaseCntnrUnit_t* p_pCntr);


    void initElementsList               (void); // initElementsList
    void displayElements                (bool p_recursively);
    bool selectByMouse 	                (void) override;
    bool selectElements                 (void);
    static void nextElement             (tuiBaseCntnr_t* p_po);  // it is a static function because it will be called by a static function
    static void prevElement             (tuiBaseCntnr_t* p_po);  // it is a static function because it will be called by a static function
    void refreshElements                (void);


    // --------------------- Element pointers section - START
    // pointer to the list of uiBase objects belonging to one
    // or more objects of the current class
    dtyBaseCntnrUnit_t* g_pCntnr;
    // --------------------- Element pointers section - END


protected:

    uint8_t markerToColor     (dtyBaseCntnrUnit_t::kMarker_t p_marker);

    uint16_t   g_elementNum;



};


#endif 	// TUI_BASE_CNTNR_H
