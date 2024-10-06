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
 

#include "tuiBaseWin.h"

#define P_PO_FATHER static_cast<tuiBase_t*>(p_poFather)

tuiBaseWin_t*	tuiBaseWin_t::g_po = nullptr;

tuiBaseWin_t::tuiBaseWin_t      (const char* p_strName, box_t* p_box, element_t* p_elementList) :
     tuiBaseListUnit_t          (p_strName, p_box, p_elementList)
{}

tuiBaseWin_t::tuiBaseWin_t      (const char* p_strName, box_t* p_box, margins_t p_margins, element_t* p_elementList) :
     tuiBaseListUnit_t          (p_strName, p_box, p_margins, p_elementList)
{}

void tuiBaseWin_t::init       (void* p_poFather) 	{
    // 1. set pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather  = P_PO_FATHER;
    g_x0a       = P_PO_FATHER->g_x0a    + g_x0r;
    g_y0a       = P_PO_FATHER->g_y0a    + g_y0r;

    //g_x0a           = P_PO_FATHER->getRefX0()    + g_x0r;
    //g_y0a           = P_PO_FATHER->getRefX0()    + g_y0r;
    //l_rootX0a       = P_PO_FATHER->getRefX0() + g_lvl1X0r;
    //l_rootY0a       = P_PO_FATHER->getRefY0() + g_lvl1Y0r;

    g_lvl1X0a       = 0;
    g_displayBoxW   = P_PO_FATHER->getDisplayMaxW();
    g_lvl1Y0a       = 0;
    g_displayBoxH   = P_PO_FATHER->getDisplayMaxH();

    g_boundUpper = 0;
    g_boundLower = g_h;
    //g_boundUpper = MAX(G_PO_FATHER->g_boundUpper, g_lvl1Y0a);
    //g_boundLower = MIN(G_PO_FATHER->g_boundLower, g_lvl1Y0a + g_h);

    // crete new ncurses window
    initWin();

    //initTuiNcursesBox();
    //frameBox();

    initElementsList();
    

}

void tuiBaseWin_t::display     (void)    {
    frameBox();
}

void tuiBaseWin_t::display               (bool p_recursively)    {
    display();
    if(p_recursively) displayElements(p_recursively);
}


bool tuiBaseWin_t::select     (void)    {
    return frameBox(tuiMode_t::select);
    //return true;
}

bool tuiBaseWin_t::deSelect     (void)    {
    return frameBox(tuiMode_t::deselect);
    //return true;
}

void tuiBaseWin_t::setThis            (void)  {
    g_po = this;
}


void tuiBaseWin_t::eventOn     (void)    {
    g_po = this;
    //deselectBackNeventOn();

    frameBox(tuiMode_t::eventOn);
    if(!g_poFather) refreshElements();
}

event_t* tuiBaseWin_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

void tuiBaseWin_t::vEventHndlKey_up	(void)  {
    if(g_po)
    prevElement(g_po);
}

void tuiBaseWin_t::vEventHndlKey_down	(void)  {
    if(g_po)
    nextElement(g_po);
}

void tuiBaseWin_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseWin_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseWin_t::vEventHndlKey_enter	(void)  {
    if(g_po->g_pCurrentElement->element->isSelected())  {
        g_po->frameBox(tuiMode_t::select);  // to remove
        if(!g_po->g_poFather) g_po->refreshElements();
        g_po->g_pCurrentElement->element->deselectBackNeventOn(true, true);
    }
}

void tuiBaseWin_t::vEventHndlKey_home	(void)  {
    if(g_po->g_poFather) {
        g_po->g_poFather->deselectBackNeventOn(true, true);
    }

}


event_t tuiBaseWin_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};


