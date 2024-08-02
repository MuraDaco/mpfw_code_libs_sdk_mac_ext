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
 * tuiBaseUnit.h
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_UNIT_H
#define TUI_BASE_UNIT_H

#include "tuiGraphicTypes.h"
#include "uyTypesDefs.h"
#include <ncurses.h>

class tuiBaseUnit_t  {

public:
    typedef struct __zone__ {
        box_t box;
        func_t hndl;
    } zone_t;

    tuiBaseUnit_t (zone_t* p_zoneList);
    tuiBaseUnit_t (box_t* p_pBox, zone_t* p_zoneList);
    virtual void init       	([[maybe_unused]] void* p_poFather)				{				};
    virtual bool loop       	(void)											;
    // virtual void EventOn    	([[maybe_unused]] uiBase* p_pFather)            {				};
    virtual void eventOn    	(void)                                  		{				};
    virtual void display   	    (void)											{				};
    virtual void select     	(void)											{				};
    virtual void selectByKey  	(void)											{				};
    virtual void selectByMouse 	(void)											{				};
    virtual void deSelect   	(void)											{				};
    bool bMouseClickInsideBounds    (point_t p_mouseXY);
    bool bMouseClickInsideBounds    (void);

    virtual void SetEventArrayOfWindow   	(void);
    virtual bool bDisplayable	(void)											{return true;	};
    bool bCheckSensitiveZone        (point_t p_mouseXY);

    void deSelectX(tuiBaseUnit_t* p_poDeselectEnd);
    void selectX(void);
    void selectX(tuiBaseUnit_t* p_poFather);

    // // --------------------- Pointers section - START
    // // pointer to the list of uiBase objects belonging to one
    // // or more objects of the current class
    // static Element_t*	ro_uiBase;
    // tuiBaseUnit_t*	ro_Father;
    // // --------------------- Pointers section - END

    uint32_t     g_selCnt;
    box_t*  g_pBox;

protected:

    // // --------------------- Events handler section - START
	// // ..................... Events handler: functions
    // template <uint8_t keycode>
    // static void vEventHndlKey	(void);
	// ..................... Events handler: array
    static event_t* g_eventArray;
    // --------------------- Events handler section - END

    tuiBaseUnit_t* g_pFather;
//    box_t*  g_pBox;
    zone_t* g_zoneList;

    static point_t g_mouseXY;
    static void setMouseXY(point_t p_mouseXY);
    static void resetMouseXY(void);
    static void deSelectSelected(tuiBaseUnit_t* p_pSelected);
    static bool bTstSelCnts(uint8_t p_selCnt1, uint8_t p_selCnt2);
    static tuiBaseUnit_t* g_poSelected;
    static uint32_t g_currentSelCnt;
//    uint32_t     g_selCnt;
    static tuiBaseUnit_t* g_pSelectedOld;
    static void setNcursWindow(WINDOW* p_ncursWinSelected);
    static WINDOW* g_ncursWinSelected;
    static WINDOW* g_ncursWinSelectedOld;

    static void vEventHndlKey_moveForward    (void);

};


#endif 	// TUI_BASE_UNIT_H
