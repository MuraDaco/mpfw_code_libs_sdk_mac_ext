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
 * tuiBaseAction.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseAction.h"

event_t*            tuiBaseAction_t::g_eventArray = nullptr;
tuiBaseAction_t*    tuiBaseAction_t::g_poSelected = nullptr;
tuiBaseAction_t*    tuiBaseAction_t::g_poEventOn  = nullptr;

tuiBaseAction_t::tuiBaseAction_t    (void)  :
    g_poFather  {nullptr}
{}


//void tuiBaseAction_t::selectByMouse         (void)    {
//    if(selectElements()) {
//        // a sub-element has been selected
//        select();
//    } else {
//        // none sub-element has been selected
//        deselectBackNselect();
//        //g_po = this;
//        setThis();
//        eventOn();
//    }
//    display();
//    
//}

bool tuiBaseAction_t::deselectBack(tuiBaseAction_t* p_poDeselectEnd, bool p_isSelecting) {
    bool l_result = true;
    if(this != p_poDeselectEnd) {
        deSelect();    
        if(g_poFather) {
            g_poFather->deselectBack(p_poDeselectEnd, p_isSelecting);
        } else {
            // the current function belong to rootWindow, therefore ...
            // no other deSelect functions have to be called
        }
        
        //if(
        //        (p_isSelecting)   
        //    &&  (p_poDeselectEnd == g_poFather)
        //)
        //{
        //    // p_poDeselectEnd = selecting element
        //    if(this == g_poEventOn) {
        //        l_result = false;
        //        select();
        //    } else
        //        deSelect();    
        //} else {
        //    deSelect();
        //    if(g_poFather) {
        //        g_poFather->deselectBack(p_poDeselectEnd, p_isSelecting);
        //    } else {
        //        // the current function belong to rootWindow, therefore ...
        //        // no other deSelect functions have to be called
        //    }
        //}

    } else {
        // the elemet that is going to be selected is the element that the current function belong to, therefore ...
        // do nothing ...
        // 
        // p_poDeselectEnd = selecting element

    }
    return l_result;
}

void  tuiBaseAction_t::deselectBackNselect  (void) {
    if(g_poSelected)    {
        if(g_poSelected->deselectBack(this, true))  {
            g_poSelected = this;
            select();
        }
    } else {
        g_poSelected = this;
        select();
    }
}

void  tuiBaseAction_t::deselectBackNselect(tuiBaseAction_t* p_poFather) {
    if(g_poSelected)    {
        if(g_poSelected->deselectBack(p_poFather, false))   {
            g_poSelected = this;
            select();
        }
    } else {
        g_poSelected = this;
        select();
    }
}

uint8_t tuiBaseAction_t::eventArraySizeGet     (void)    {
    return constEventArraySize;
}

//void tuiBaseAction_t::eventOn     (void)    {
//    tuiBaseAction_t::g_eventArray  = g_eventArray;
//}

void tuiBaseAction_t::eventOn     (void)    {
    g_poEventOn = this;
    tuiBaseAction_t::g_eventArray  = pEventArrayGet();
}
