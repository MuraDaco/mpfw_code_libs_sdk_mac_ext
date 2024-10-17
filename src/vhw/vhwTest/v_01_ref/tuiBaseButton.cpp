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
 * tuiBaseButton.cpp
 *
 *  Created on: Sep, 9th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseButton.h"


//tuiBaseButton_t*	tuiBaseButton_t::g_po = nullptr;

tuiBaseButton_t::tuiBaseButton_t      (const char* p_strName  ,uint8_t p_sizeName   ,box_t p_box    ,func_t p_func)   :
     tuiBase_t          (p_strName, p_box)
    ,g_func             {p_func}
{
    g_w = p_sizeName;
}


bool tuiBaseButton_t::loop            (void)  {
    bool l_result = false;

    return l_result;
}


bool tuiBaseButton_t::select         (void)    {
    nameOnly(tuiMode_t::select);
    return true;
}

bool tuiBaseButton_t::deSelect        (void)    {
    nameOnly(tuiMode_t::deselect);
    return true;
}

bool tuiBaseButton_t::selectByMouse       (void)    {
    deselectBackNselect(true);
    g_poFather->deselectBackNeventOn(true, true);
    eventOn();
    return true;
}

void tuiBaseButton_t::display          (void)    {
    nameOnly();
}

void tuiBaseButton_t::display         ([[maybe_unused]] bool p_recursively)  {
    nameOnly();
}  

void tuiBaseButton_t::setThis            (void)  {
}

void tuiBaseButton_t::eventOn         (void)    {
    ////tuiBaseAction_t::g_eventArray  = g_eventArray;
    //tuiBaseAction_t::eventOn();
    //g_poFather->deselectBackNeventOn();
    g_func();
}

event_t* tuiBaseButton_t::pEventArrayGet	(void)      {
    return nullptr;
}

