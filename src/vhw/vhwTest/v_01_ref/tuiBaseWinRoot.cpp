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
 * tuiBaseWin.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseWinRoot.h"



tuiBaseWinRoot_t::tuiBaseWinRoot_t      (const char* p_strName, box_t* p_box, element_t* p_elementList) :
     tuiBaseWin_t       (p_strName, p_box, p_elementList)
{}

void tuiBaseWinRoot_t::init       (void) 	{
    // 1. init TUI environment
    initGraphEnv();
    initGraphEnvColor();

    g_lvl1X0a = 0;
    g_lvl1Y0a = 0;

    // 3. init elements and its sub-elements
    initElementsList();

    g_poSelected = this;

    // 4. activate the ehandler event array of the current root window
    deselectBackNeventOn(true, true);
    displayElements(true); // "true" means that the elements are displayed recursively

}

bool tuiBaseWinRoot_t::loop            (void)  {
    bool l_result = true;
    tuiEventCode_t l_handlerEventCode = tuiEventCode_t::noEvent;

    if(uiEventStatus())   {
        int l_uiEventKeyCode = uiEventKeyCode();
        if((TUI_KEY_CTRL_Q == l_uiEventKeyCode) || (TUI_KEY_CTRL_X == l_uiEventKeyCode) ){
            l_result = false;
            deinitGraphEnv();
        } else {
            l_handlerEventCode = uiHandlerEventCode();
        }
    }

    if(tuiEventCode_t::mouse == l_handlerEventCode) {
        if(uiMouseEventStatus())
        {

            if(uiMouseEventCode_ButtonPressed())
            {

                if(selectElements()) {
                    frameBox(tuiMode_t::select);
                    refreshElements();
                    debugStatus();
                } else {
                    deselectBackNeventOn(true, true);
                }
            }

        }
    } else {
        if(
            (tuiEventCode_t::noEvent != l_handlerEventCode) &&
            (tuiEventCodeNum(l_handlerEventCode) < g_poEventOn->eventArraySizeGet())
        )   {
            g_poEventOn->g_eventArray[tuiEventCodeNum(l_handlerEventCode)]();
            debugStatus();
        }
    }

    return l_result;
}


void tuiBaseWinRoot_t::end 	        (void)      {
    endGraphEnv();
}


bool tuiBaseWinRoot_t::deSelect     (void)    {

    if(tuiBaseWin_t::deSelect())    {
        // ... its elements
        refreshElements();
        return true;
    }

    return false;
}

void tuiBaseWinRoot_t::debugStatus  (void)  {

}
