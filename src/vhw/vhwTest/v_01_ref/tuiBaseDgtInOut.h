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
 * tuiBaseDgtInOut.h
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_DGT_IN_OUT_H
#define TUI_BASE_DGT_IN_OUT_H

#include "tuiMacroDefine.h"
#include "tuiBase.h"
#include "dtyUint8.h"


class tuiBaseDgtInOut_t : public tuiBase_t  {

public:
    tuiBaseDgtInOut_t       (const char* p_strName  ,uint8_t p_height   ,dtyUint8_t* p_pDtyStatus   );
    tuiBaseDgtInOut_t       (const char* p_strName  ,box_t p_box        ,dtyUint8_t* p_pDtyStatus   );

    void init               (void* p_poFather) 		override;
    bool loop       	    (void)					override;
    void display            (void)                  override;
    void display            (bool p_recursively)    override;
    void select             (void)                  override;
    void selectByMouse      (void)                  override;
    void deSelect           (void)                  override;
    void eventOn            (void)                  override;


private:
//    const char* g_strName;
    
    // // --------------------- Events handler section - START
	// // ..................... Events handler: functions
    // the "event" & the "event array" is equal for all the instanticies of the current class therefore ...
    // the event handler function & the event array must to be defined as static
    // template <uint8_t keycode>
    // static void vEventHndlKey	(void);
    static void vEventHndlKey_down	(void);
    static void vEventHndlKey_up	(void);
    static void vEventHndlKey_left	(void);
    static void vEventHndlKey_right	(void);
    static void vEventHndlKey_enter	(void);
    static void vEventHndlKey_home	(void);
	// ..................... Events handler: array
    static event_t g_eventArray[];
    // --------------------- Events handler section - END

    // --------------------- Object pointers section - START
    // pointer to the list of uiBase objects belonging to one
    // or more objects of the current class
    static tuiBaseDgtInOut_t*	g_po;
    //tuiBaseUnit_t*	    g_poFather; // to initialize in the init function
    // --------------------- Object pointers section - END


    // --------------------- Data section - START
    dtyUint8_t* g_pDtyStatus;
    // --------------------- Data section - END

};


#endif 	// TUI_BASE_DGT_IN_OUT_H
