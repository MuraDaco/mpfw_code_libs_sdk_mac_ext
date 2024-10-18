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
 * tuiBaseCntnrX.h
 *
 *  Created on: Sep, 21st 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_CNTNR_X_H
#define TUI_BASE_CNTNR_X_H

#include "tuiBase.h"
#include "dtyBaseCntnrUnitX.h"

class tuiBaseCntnrX_t : public tuiBase_t {

public:

    tuiBaseCntnrX_t      (const char* p_strName, box_t  p_box,  dtyBaseCntnrUnitX_t* p_pCntr)   ;
    tuiBaseCntnrX_t      (const char* p_strName, box_t* p_pBox, dtyBaseCntnrUnitX_t* p_pCntr)   ;


    void initElementsList               (void); // initElementsList
    void displayElements                (bool p_recursively);
    
    bool selectByMouse 	                (void) override;
    void updCoordNboundsChilds          (void) override;

    bool selectElements                 (void);
    static void selectPrev              (tuiBaseCntnrX_t* p_po);
    static void selectNext              (tuiBaseCntnrX_t* p_po);
    static void rollUp                  (tuiBaseCntnrX_t* p_po);
    static void rollDown                (tuiBaseCntnrX_t* p_po);
    void refreshElements                (void);


    // --------------------- Element pointers section - START
    // pointer to the list of uiBase objects belonging to one
    // or more objects of the current class
    dtyBaseCntnrUnitX_t* g_pCntnr;
    // --------------------- Element pointers section - END


protected:


    uint16_t   g_elementNum;



};


#endif 	// TUI_BASE_CNTNR_X_H
