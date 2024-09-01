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
 * tuiBaseLboxY.cpp
 *
 *  Created on: Aug, 12th 2024
 *      Author: Marco Dau
 */
 
#include <stdio.h>  // sprintf

#include "tuiBaseLboxY.h"

tuiBaseLboxY_t*	tuiBaseLboxY_t::g_po = nullptr;


tuiBaseLboxY_t::tuiBaseLboxY_t      (const char* p_strName, uint8_t p_height    ,tuiBaseListElem_t* p_elementList) :
     tuiBaseListUnitY_t         (p_strName, {p_height, 0, 0, 0}, p_elementList)
{}
tuiBaseLboxY_t::tuiBaseLboxY_t      (const char* p_strName, box_t* p_pBox       ,tuiBaseListElem_t* p_elementList) :
     tuiBaseListUnitY_t         (p_strName, p_pBox, p_elementList)
{}

void tuiBaseLboxY_t::init       (void* p_poFather) 	{
    // 1. backup pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather  = static_cast<tuiBase_t*>(p_poFather);
    g_pNcursWin = static_cast<tuiBase_t*>(p_poFather)->g_pNcursWin;
    g_x0Win     = static_cast<tuiBase_t*>(p_poFather)->g_x0Win  + g_x0r;
    g_y0Win     = static_cast<tuiBase_t*>(p_poFather)->g_y0Win  + g_y0r;
    g_x0a       = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a       = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;

    //frameNname();

    initElementsList();

}

void tuiBaseLboxY_t::setThis            (void)  {
    g_po = this;
}

//void tuiBaseLboxY_t::selectByMouse         (void)    {
//    if(selectElements()) {
//        // a sub-element has been selected
//        select();
//    } else {
//        // none sub-element has been selected
//        deselectBackNselect();
//        eventOn();
//    }
//    display();
//    
//}

void tuiBaseLboxY_t::display               (bool p_recursively)    {
    display();
    if(p_recursively) displayElements(p_recursively);
}

#define SIZE_OF_STATUS_STR  10
void tuiBaseLboxY_t::getStrStatus               (char* p_str)    {
    uint8_t l_idSelected = 0;
    // check status mode of current element: is it selected or not?
    if(g_pCurrentElement->g_pUnit->isSelectedOrEventOn()) {
        l_idSelected = g_pCurrentElement->g_id + 1;
    }
    snprintf(p_str, SIZE_OF_STATUS_STR,"%03d / %03d", l_idSelected, g_elementNum);
}

void tuiBaseLboxY_t::display               (void)    {
    char l_str[SIZE_OF_STATUS_STR];
    getStrStatus(l_str);
    frameNameNstatus(l_str);
}

void tuiBaseLboxY_t::select         (void)    {
    char l_str[SIZE_OF_STATUS_STR];
    getStrStatus(l_str);
    frameNameNstatus(tuiMode_t::select, l_str);
}


void tuiBaseLboxY_t::deSelect        (void)    {
    char l_str[SIZE_OF_STATUS_STR];
    getStrStatus(l_str);
    frameNameNstatus(tuiMode_t::deselect, l_str);
}


void tuiBaseLboxY_t::eventOn     (void)    {
    char l_str[SIZE_OF_STATUS_STR];
    g_po = this;
    tuiBaseAction_t::g_eventArray  = g_eventArray;
    getStrStatus(l_str);
    frameNameNstatus(tuiMode_t::eventOn, l_str);
}

void tuiBaseLboxY_t::vEventHndlKey_up	(void)  {
    prevElement(g_po);
}

void tuiBaseLboxY_t::vEventHndlKey_down	(void)  {
    nextElement(g_po);
}

void tuiBaseLboxY_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseLboxY_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseLboxY_t::vEventHndlKey_enter	(void)  {
    if(g_po->g_pCurrentElement->g_pUnit->isSelected())  {
        g_po->frameNname(tuiMode_t::select);
        g_po->g_pCurrentElement->g_pUnit->eventOn();
    }
}

void tuiBaseLboxY_t::vEventHndlKey_home	(void)  {
    g_po->deselectBackNselect();
    if(g_po->g_poFather) g_po->g_poFather->eventOn();

}


event_t tuiBaseLboxY_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};
