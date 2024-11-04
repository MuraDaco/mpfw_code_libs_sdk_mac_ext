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
 * tuiGraphicUnitRoot.cpp
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicUnitRoot.h"



tuiGraphicUnitRoot_t::tuiGraphicUnitRoot_t      (tuiUnitAbstract_t* p_pUnit) :
     tuiGraphicUnit_t       (p_pUnit    )
{}

tuiGraphicUnitRoot_t::tuiGraphicUnitRoot_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    ) :
     tuiGraphicUnit_t       (p_pUnit    ,p_box  )
{}

tuiGraphicUnitRoot_t::tuiGraphicUnitRoot_t      (tuiUnitAbstract_t* p_pUnit                 ,margins_t p_margin) :
     tuiGraphicUnit_t       (p_pUnit            ,p_margin)
{}

#define RECURSIVE_DISPLAY       true
#define NOT_RECURSIVE_DISPLAY   false

bool tuiGraphicUnitRoot_t::init       (void) 	{
    // 1. init TUI environment
    tuiGraphicState_t::setParent(nullptr);
    tuiGraphicCoord_t::setParent(nullptr);
    initGraphEnv();
    initGraphEnvColor();

    initWinRootDims();
    initBoundsWinRoot();

    // 2. init children and nephew graphic unit (recursive procedure)
    g_pUnit->initChildren(this);


    // 3. activate the handler event array of the current root window
    selectNeventOnInit();
    g_pUnit->eventOn(this);

    // 4. display children and nephew graphic unit (recursive procedure) 
    g_pUnit->displayChildren(this, RECURSIVE_DISPLAY);


    return true;

}

bool tuiGraphicUnitRoot_t::initChildren       (void) 	{
    return true;
}

bool tuiGraphicUnitRoot_t::init       ([[maybe_unused]] tuiGraphicUnit_t* p_pParent) 	{
    return false;
}

bool tuiGraphicUnitRoot_t::loopChildren    (void)  {
    return true;
}

bool tuiGraphicUnitRoot_t::loop            (void)  {
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

    if(
            (tuiEventCode_t::noEvent != l_handlerEventCode)
        &&  (tuiEventCode_t::mouse   <= l_handlerEventCode)
    ) {
        if(uiMouseEventStatus())
        {

            if(uiMouseEventCode_ButtonPressed())
            {
                if(!g_pUnit->clickingChild(this)) {
                    deselectBackNeventOn();
                }
            } else {
                if(tuiEventCode_t::mouse < l_handlerEventCode)  {
                    g_eventMouseArray[tuiEventCodeNum(l_handlerEventCode) - (static_cast<uint8_t>(tuiEventCode_t::mouse)+1)](static_cast<tuiGraphicAbstract_t*>(g_poEventOn));
                    
                }
            }

        }
    } else {
        if(tuiEventCode_t::noEvent != l_handlerEventCode)   {
            g_eventKeyArray[tuiEventCodeNum(l_handlerEventCode)](static_cast<tuiGraphicAbstract_t*>(g_poEventOn));
        }
    }

    return l_result;
}


void tuiGraphicUnitRoot_t::end 	        (void)      {
    endGraphEnv();
}

void tuiGraphicUnitRoot_t::endChildren  (void)      {
}


void tuiGraphicUnitRoot_t::refreshWinChildren       (void)  {
    //g_pUnit->refreshChildren(this, false);
    g_pUnit->displayChildren(this, false);
}


bool tuiGraphicUnitRoot_t::eventOnTst       (void)  {
    return true;
}

void tuiGraphicUnitRoot_t::debug_01         (void)  {

}

