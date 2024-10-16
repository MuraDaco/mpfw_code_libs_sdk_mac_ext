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
 * tuiBaseLboxX.cpp
 *
 *  Created on: Oct, 9th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseLboxX.h"


tuiBaseLboxX_t*	tuiBaseLboxX_t::g_po = nullptr;


tuiBaseLboxX_t::tuiBaseLboxX_t      (const char* p_strName, box_t* p_pBox, dtyTuiBase_t* p_elementList) :
     tuiBaseCntnrX_t         (p_strName, p_pBox, p_elementList)
{}

void tuiBaseLboxX_t::init       (void* p_poFather) 	{
    tuiBase_t::init(p_poFather);
    initElementsList();

}


bool tuiBaseLboxX_t::select         (void)    {
    frameNname(tuiMode_t::select);
    return true;
}

bool tuiBaseLboxX_t::deSelect        (void)    {
    frameNname(tuiMode_t::deselect);
    return true;
}

void tuiBaseLboxX_t::display               (void)    {
    frameNname();
}

void tuiBaseLboxX_t::display               (bool p_recursively)    {
    display();
    if(p_recursively) displayElements(p_recursively);
}


void tuiBaseLboxX_t::setThis            (void)  {
    g_po = this;
}

void tuiBaseLboxX_t::eventOn     (void)    {
    g_po = this;
    frameNname(tuiMode_t::eventOn);
}

event_t* tuiBaseLboxX_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

void tuiBaseLboxX_t::vEventHndlKey_up	(void)  {
    selectPrev(g_po);
}

void tuiBaseLboxX_t::vEventHndlKey_down	(void)  {
    selectNext(g_po);
}

void tuiBaseLboxX_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseLboxX_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseLboxX_t::vEventHndlKey_enter	(void)  {
    tuiBase_t* l_element = static_cast<tuiBase_t*>(g_po->g_pCntnr->getSelect());
    if(l_element->isSelected())  {
       l_element->deselectBackNeventOn(true, true);
    }
}

void tuiBaseLboxX_t::vEventHndlKey_home	(void)  {
    if(g_po->g_poFather) g_po->g_poFather->deselectBackNeventOn(true, true);

}


event_t tuiBaseLboxX_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};

#define P_THIS static_cast<tuiBaseLboxX_t*>(p_this)

void_f_pVoid_t* tuiBaseLboxX_t::pEventMouseArrayGet	(void)      {
    return g_eventMouseArray;
}

void tuiBaseLboxX_t::vEventHndlMouse_rollUp	(void* p_this)  {
    P_THIS->rollUp(P_THIS);

}

void tuiBaseLboxX_t::vEventHndlMouse_rollDown	(void* p_this)  {
    P_THIS->rollDown(P_THIS);
}

void_f_pVoid_t tuiBaseLboxX_t::g_eventMouseArray[]  = {
     vEventHndlMouse_rollUp
    ,vEventHndlMouse_rollDown
};
