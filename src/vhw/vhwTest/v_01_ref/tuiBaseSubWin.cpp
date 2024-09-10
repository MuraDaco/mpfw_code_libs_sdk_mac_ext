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
 * tuiBaseSubWin.cpp
 *
 *  Created on: Sep, 7th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseSubWin.h"


tuiBaseSubWin_t*	tuiBaseSubWin_t::g_po = nullptr;

tuiBaseSubWin_t::tuiBaseSubWin_t      (const char* p_strName, box_t* p_box, element_t* p_elementList) :
     tuiBaseListUnit_t          (p_strName, p_box, p_elementList)
{}


void tuiBaseSubWin_t::init       (void* p_poFather) 	{
    tuiBase_t::init(p_poFather);
    initElementsList();
}

void tuiBaseSubWin_t::display     (void)    {
    frameNname();
}

void tuiBaseSubWin_t::display               (bool p_recursively)    {
    display();
    if(p_recursively) displayElements(p_recursively);
}


void tuiBaseSubWin_t::select     (void)    {
    frameNname(tuiMode_t::select);
}

void tuiBaseSubWin_t::deSelect     (void)    {
    frameNname(tuiMode_t::deselect);
}

void tuiBaseSubWin_t::setThis            (void)  {
    g_po = this;
}


void tuiBaseSubWin_t::eventOn     (void)    {
    g_po = this;
    tuiBaseAction_t::eventOn();

    frameNname(tuiMode_t::eventOn);
    if(!g_poFather) refreshElements();
}

event_t* tuiBaseSubWin_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

void tuiBaseSubWin_t::vEventHndlKey_up	(void)  {
    if(g_po)
    prevElement(g_po);
}

void tuiBaseSubWin_t::vEventHndlKey_down	(void)  {
    if(g_po)
    nextElement(g_po);
}

void tuiBaseSubWin_t::vEventHndlKey_left	(void)  {
}

void tuiBaseSubWin_t::vEventHndlKey_right	(void)  {
}

void tuiBaseSubWin_t::vEventHndlKey_enter	(void)  {
    if(g_po->g_pCurrentElement->element->isSelected())  {
        g_po->frameNname(tuiMode_t::select);
        if(!g_po->g_poFather) g_po->refreshElements();
        g_po->g_pCurrentElement->element->eventOn();
    }
}

void tuiBaseSubWin_t::vEventHndlKey_home	(void)  {
    if(g_po->g_poFather) {
        g_po->deselectBackNselect();
        g_po->g_poFather->eventOn();
    }

}


event_t tuiBaseSubWin_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};


