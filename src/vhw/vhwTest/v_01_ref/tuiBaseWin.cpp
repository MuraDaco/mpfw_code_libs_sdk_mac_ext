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


tuiBaseWin_t*	tuiBaseWin_t::g_po = nullptr;

tuiBaseWin_t::tuiBaseWin_t      (const char* p_strName, box_t* p_box, element_t* p_elementList) :
     tuiBaseListUnit_t          (p_strName, p_box, p_elementList)
{}


void tuiBaseWin_t::init       (void* p_poFather) 	{
    // 1. set pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather  = static_cast<tuiBase_t*>(p_poFather);
    g_x0a       = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a       = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;

    // crete new ncurses window
    initWin();

    //initTuiNcursesBox();
    frameBox();

    initElementsList();
    

}

void tuiBaseWin_t::display     (void)    {
    frameBox();
}

void tuiBaseWin_t::select     (void)    {
    frameBox(tuiMode_t::select);
    // wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    // box(g_ncursWin, 0, 0);
    // mvwprintw(g_ncursWin, 0, 10, " *** window name: %s *** ", g_strName);
    // wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    // wrefresh(g_ncursWin);

}

void tuiBaseWin_t::deSelect     (void)    {
    frameBox(tuiMode_t::deselect);
    // wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    // box(g_ncursWin, 0, 0);
    // mvwprintw(g_ncursWin, 0, 10, " *** window name: %s *** ", g_strName);
    // wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    // wrefresh(g_ncursWin);
}

void tuiBaseWin_t::eventOn     (void)    {
    // if(tuiMode_t::select == g_status) {
        g_po = this;
        tuiBaseAction_t::g_eventArray  = g_eventArray;
        frameBox(tuiMode_t::eventOn);
        if(!g_poFather) refreshElements();
    // }
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
        g_po->frameBox(tuiMode_t::select);
        if(!g_po->g_poFather) g_po->refreshElements();
        g_po->g_pCurrentElement->element->eventOn();
    }
}

void tuiBaseWin_t::vEventHndlKey_home	(void)  {
    if(g_po->g_poFather) {
        g_po->deselectBackNselect();
        g_po->g_poFather->eventOn();
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


