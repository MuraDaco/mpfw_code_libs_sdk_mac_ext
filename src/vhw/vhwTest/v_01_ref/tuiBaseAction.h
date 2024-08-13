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
 * tuiBaseAction.h
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_ACTION_H
#define TUI_BASE_ACTION_H

#include "uyTypesDefs.h"
#include <ncurses.h>

class tuiBaseAction_t  {

public:
    tuiBaseAction_t (void);
    
    // virtual functions
    virtual void init       	(void)				                                                    {};
    virtual void init       	([[maybe_unused]] void* p_poFather)				                        {};

    virtual bool loop       	(void)  {return true;};
    virtual void end       	    (void)  {};
    virtual void eventOn    	(void)  {};
    virtual void display   	    (void)  {};
    virtual void display   	    ([[maybe_unused]] bool p_recursively)  {};
    virtual void select     	(void)  {};
    virtual void deSelect   	(void)  {};
    virtual void selectByMouse 	(void)  {};
    virtual bool bDisplayable	(void)  {return true;};

    // common functions
    void deselectBack           (tuiBaseAction_t* p_poDeselectEnd);
    void deselectBackNselect    (void);
    void deselectBackNselect    (tuiBaseAction_t* p_poFather);




    //const char* g_strName;

    // --------------------- ncurses section - START
    //WINDOW* g_ncursWin;
    // --------------------- ncurses section - END

    // // --------------------- Pointers section - START
    // // pointer to the list of uiBase objects belonging to one
    // // or more objects of the current class
    // static Element_t*	ro_uiBase;
    // tuiBaseAction_t*	ro_Father;
    // // --------------------- Pointers section - END

    //box_t*  g_pBox;

protected:

    // // --------------------- Events handler section - START
	// // ..................... Events handler: functions
    // template <uint8_t keycode>
    // static void vEventHndlKey	(void);
	// ..................... Events handler: array
    static event_t* g_eventArray;
    // --------------------- Events handler section - END

    tuiBaseAction_t* g_poFather;

    //static point_t g_mouseXY;
    //static void setMouseXY(point_t p_mouseXY);
    static tuiBaseAction_t* g_poSelected;


};


#endif 	// TUI_BASE_ACTION_H
