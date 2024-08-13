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
 * tuiBaseListUnitY.h
 *
 *  Created on: Aug, 12th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_LIST_UNIT_Y_H
#define TUI_BASE_LIST_UNIT_Y_H

#include "tuiBase.h"

class tuiBaseListUnitY_t : public tuiBase_t {

public:

    typedef struct __element__	{
    	tuiBase_t*	element;
    	uint8_t	    flag;
    } element_t;

    tuiBaseListUnitY_t      (const char* p_strName, box_t  p_box,   element_t* p_elementList);
    tuiBaseListUnitY_t      (const char* p_strName, box_t* p_pBox,  element_t* p_elementList);

    void selectByMouse 	(void) override;

    void initElementsList               (void); // initElementsList
    bool selectElements                 (void);
    static void nextElement             (tuiBaseListUnitY_t* p_po);  // it is a static function because it will be called by a static function
    static void prevElement             (tuiBaseListUnitY_t* p_po);  // it is a static function because it will be called by a static function
    void refreshElements                (void);
    void displayElements            (bool p_recursively);
    // --------------------- Element pointers section - START
    // pointer to the list of uiBase objects belonging to one
    // or more objects of the current class
    element_t*	g_elementList;
    element_t*  g_pCurrentElement;
    element_t*  g_pLastElement;
    bool g_bElementList;
    // --------------------- Element pointers section - END


protected:
    uint32_t    g_originWin;



};


#endif 	// TUI_BASE_LIST_UNIT_Y_H
