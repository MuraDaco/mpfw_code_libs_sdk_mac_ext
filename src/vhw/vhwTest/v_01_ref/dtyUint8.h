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

class tuiBaseUnit_t  {

public:
    typedef struct __zone__ {
        box_t box;
        func_t hndl;
    } zone_t;

    tuiBaseUnit_t (zone_t* p_zoneList);
    tuiBaseUnit_t (box_t* p_box, zone_t* p_zoneList);
    virtual void init       	([[maybe_unused]] void* p_poFather)											{				};
    // virtual void EventOn    	([[maybe_unused]] uiBase* p_pFather)            {				};
    virtual void eventOn    	(void)                                  		{				};
    virtual void select     	(void)											{				};
    virtual void deSelect   	(void)											{				};
    virtual void SetEventArrayOfWindow   	(void);
    virtual bool bDisplayable	(void)											{return true;	};

    bool bMouseClickInsideBounds    (point_t p_mouseXY);
    bool bCheckSensitiveZone        (point_t p_mouseXY);


    // // --------------------- Events handler section - START
	// // ..................... Events handler: functions
    // template <uint8_t keycode>
    // static void vEventHndlKey	(void);
	// ..................... Events handler: array
    static event_t* g_eventArray;
    // --------------------- Events handler section - END

    // // --------------------- Pointers section - START
    // // pointer to the list of uiBase objects belonging to one
    // // or more objects of the current class
    // static Element_t*	ro_uiBase;
    // tuiBaseUnit_t*	ro_Father;
    // // --------------------- Pointers section - END

protected:
    //static eventHndl_t eventArray[];
    tuiBaseUnit_t* g_pFather;
    box_t*  g_box;
    zone_t* g_zoneList;
};


#endif 	// TUI_BASE_UNIT_H
