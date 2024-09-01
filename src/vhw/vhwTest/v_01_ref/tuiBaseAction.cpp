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

void tuiBaseAction_t::deselectBack(tuiBaseAction_t* p_poDeselectEnd) {
    if(this != p_poDeselectEnd)   {
        deSelect();
        if(g_poFather) {
            g_poFather->deselectBack(p_poDeselectEnd);
        } else {
            // the current function belong to rootWindow, therefore ...
            // no other deSelect functions have to be called
        }

    } else {
        // the elemet that is going to be selected is the element that the current function belong to, therefore ...
        // do nothing ...
        // 
    }
}

void  tuiBaseAction_t::deselectBackNselect() {
    if(g_poSelected)
        g_poSelected->deselectBack(this);
    g_poSelected = this;
    select();
}

void  tuiBaseAction_t::deselectBackNselect(tuiBaseAction_t* p_poFather) {
    if(g_poSelected)
        g_poSelected->deselectBack(p_poFather);
    g_poSelected = this;
    select();
}

//void tuiBaseAction_t::eventOn     (void)    {
//    tuiBaseAction_t::g_eventArray  = g_eventArray;
//}
