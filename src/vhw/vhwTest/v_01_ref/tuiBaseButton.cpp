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


tuiBaseButton_t*	tuiBaseButton_t::g_po = nullptr;

tuiBaseButton_t::tuiBaseButton_t      (const char* p_strName    ,uint8_t p_height   ,dtyUint8_t* p_pDtyStatus   )   :
     tuiBase_t          (p_strName, {p_height, 0, 0, 1}, p_pDtyStatus)
    ,g_pDtyStatus           {p_pDtyStatus}
{}

tuiBaseButton_t::tuiBaseButton_t      (const char* p_strName    ,box_t p_box        ,dtyUint8_t* p_pDtyStatus   )   :
     tuiBase_t          (p_strName, p_box, p_pDtyStatus)
    ,g_pDtyStatus           {p_pDtyStatus}
{}


void tuiBaseButton_t::init       (void* p_poFather) 	{
    g_poFather      = static_cast<tuiBase_t*>(p_poFather);
    g_pNcursWin     = static_cast<tuiBase_t*>(p_poFather)->g_pNcursWin;
    g_x0Win         = static_cast<tuiBase_t*>(p_poFather)->g_x0Win  + g_x0r;
    g_y0Win         = static_cast<tuiBase_t*>(p_poFather)->g_y0Win  + g_y0r;
    g_x0a           = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a           = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;
    if(!g_w) g_w    = static_cast<tuiBase_t*>(p_poFather)->g_w - 2;
}

bool tuiBaseButton_t::loop            (void)  {
    bool l_result = false;

    return l_result;
}


void tuiBaseButton_t::select         (void)    {
    nameNstatus(tuiMode_t::select);
}

void tuiBaseButton_t::selectByMouse       (void)    {
    deselectBackNselect(g_poFather);
    eventOn();
}

void tuiBaseButton_t::display          (void)    {
    nameNstatus();
}

void tuiBaseButton_t::display         ([[maybe_unused]] bool p_recursively)  {
    display();
}  

void tuiBaseButton_t::deSelect        (void)    {
    nameNstatus(tuiMode_t::deselect);
}

void tuiBaseButton_t::setThis            (void)  {
    g_po = this;
}

void tuiBaseButton_t::eventOn         (void)    {
    g_po = this;
    //tuiBaseAction_t::g_eventArray  = g_eventArray;
    tuiBaseAction_t::eventOn();
    nameNstatus(tuiMode_t::eventOn);
}

event_t* tuiBaseButton_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

void tuiBaseButton_t::vEventHndlKey_down	(void)  {
}

void tuiBaseButton_t::vEventHndlKey_up	(void)  {
}

void tuiBaseButton_t::vEventHndlKey_left	(void)  {
}

void tuiBaseButton_t::vEventHndlKey_right	(void)  {
}

void tuiBaseButton_t::vEventHndlKey_enter	(void)  {
    g_po->g_pDtyStatus->vInc();
}

void tuiBaseButton_t::vEventHndlKey_home	(void)  {
    g_po->deselectBackNselect();
    g_po->g_poFather->eventOn();

}

event_t tuiBaseButton_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};


