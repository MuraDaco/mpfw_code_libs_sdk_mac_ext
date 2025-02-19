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
 * tuiBaseLboxX.h
 *
 *  Created on: Oct, 9th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_LBOX_X_H
#define TUI_BASE_LBOX_X_H

#include "tuiBaseCntnrX.h"
#include "dtyTuiBase.h"

class tuiBaseLboxX_t : public tuiBaseCntnrX_t    {

public:

    tuiBaseLboxX_t (const char* p_strName, box_t* p_pBox, dtyTuiBase_t* p_elementList);

    void init               (void* p_poFather) 		override;
    bool select             (void)                  override;
    bool deSelect           (void)                  override;

    void clear              (void)                  override;
    void display            (void)                  override;
    void display            (bool p_recursively)    override;

    void setThis            (void)                  override;
    void eventOn            (void)                  override;
    event_t* pEventArrayGet	(void)                  override;

protected:

    // --------------------- Object pointers section - START
    // pointer to the list of uiBase objects belonging to one
    // or more objects of the current class
    static tuiBaseLboxX_t*	g_po;
    //tuiBaseUnit_t*	    g_poFather; // to initialize in the init function
    // --------------------- Object pointers section - END

private:

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

public:
    void_f_pVoid_t* pEventMouseArrayGet	(void)      override;
private:
    static void vEventHndlMouse_rollUp	    (void* p_this);
    static void vEventHndlMouse_rollDown	(void* p_this);
    static void_f_pVoid_t g_eventMouseArray[];

};


#endif 	// TUI_BASE_LBOX_X_H
