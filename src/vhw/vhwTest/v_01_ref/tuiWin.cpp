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
 * tuiWin.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiWin.h"


//#define NCURS_COLOR_PAIR_INIT(name)    NCURS_COLOR_PAIR_##name
//#define NCURS_COLOR_PAIR_SET(WINDOW_SELECT)

tuiWin_t*	tuiWin_t::g_po = nullptr;

// tuiWin_t::tuiWin_t      (void)    :
//     tuiBaseUnit_t(g_zoneList)
// {}
// 
tuiWin_t::tuiWin_t      (box_t* p_box)    :
    tuiBaseUnit_t           (p_box, g_zoneList)
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, element_t* p_elementList)    :
     tuiBaseUnit_t          (p_box, g_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, zone_t* p_zoneList)    :
    tuiBaseUnit_t           (p_box, p_zoneList)
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseUnit_t          (p_box, p_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (const char* p_strName, box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseUnit_t          (p_strName, p_box, p_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {nullptr}
{}


void tuiWin_t::initTuiNcursesBox       (void)         {

    if(g_poFather)  wattron(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_DESELECT);
    else            wattron(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_SELECT);

    // b) enable color windows management
    box(g_ncursWin, 0, 0);                  // BE CAREFUL !! - if (g_ncursWin==stdscr) this instructions clear all sub-windows and you have to repaint the box and refresh subwindow
    mvwprintw(g_ncursWin, 0, 10, " *** window name: %s *** ", g_strName);

    if(g_poFather)  wattroff(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_DESELECT);
    else            wattroff(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_SELECT);
    wrefresh(g_ncursWin);

}


void tuiWin_t::initElementsList       (void) 	{
    // c) initialize all elements of the its own element list that is
    element_t* l_element = g_elementList;

    // c.1) run [init] function for each [child] element
    while(l_element->element)    {
        //g_pLastElement = l_element;
        l_element->element->init(this);
        l_element++;
    }

    // c.2) determine the existence of an elements list
    if(l_element == g_elementList) {
        g_bElementList = false;
    } else {
        g_bElementList = true;
        // initialize last Element of the list
        g_pLastElement = l_element;
    }

}


void tuiWin_t::init       (void* p_poFather) 	{
    // 1. set pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather = static_cast<tuiWin_t*>(p_poFather);

    // crete new ncurses window
    g_ncursWin = newwin(g_pBox->height, g_pBox->width, g_pBox->yStart, g_pBox->xStart);

    initTuiNcursesBox();

    initElementsList();
    

}



//void EventOn    (uiBase* p_pFather) override;

void tuiWin_t::display     (void)    {
}

void tuiWin_t::selectByMouse     (void)    {

    if(selectElements()) {
        select();
    } else {
        selectX();
        eventOn();
    }

}

bool tuiWin_t::selectElements     (void)    {
    bool l_result = false;

    element_t* l_element = g_elementList;
    while(l_element->element)    {
        if(l_element->element->bMouseClickInsideBounds()) {
            if(g_pCurrentElement) g_pCurrentElement->element->deSelect();   // because of mouse event management
            g_pCurrentElement = l_element;
            l_element->element->selectByMouse();
            l_result = true;
        } else {
            l_element->element->display();
        }
        l_element++;
    }

    return l_result;
}

void tuiWin_t::select     (void)    {
    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    box(g_ncursWin, 0, 0);
    mvwprintw(g_ncursWin, 0, 10, " *** window name: %s *** ", g_strName);
    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    wrefresh(g_ncursWin);

}

void tuiWin_t::deSelect     (void)    {
    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    box(g_ncursWin, 0, 0);
    mvwprintw(g_ncursWin, 0, 10, " *** window name: %s *** ", g_strName);
    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    wrefresh(g_ncursWin);
}

void tuiWin_t::eventOn     (void)    {
    g_po = this;
    tuiBaseUnit_t::g_eventArray  = g_eventArray;
}

void tuiWin_t::zone_hndl_1  (void)  {

}

void tuiWin_t::zone_hndl_2  (void)  {

}

tuiBaseUnit_t::zone_t tuiWin_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_hndl_1}
    ,{{1, 2, 3, 4}, zone_hndl_2}
    ,{{1, 4, 3, 4}, zone_hndl_2}
    ,{{1, 2, 3, 4}, nullptr}
};


void tuiWin_t::vEventHndlKey_up	(void)  {
    if(g_po->g_bElementList) {
        if(g_po->g_pCurrentElement) {
            if(g_po->g_elementList == g_po->g_pCurrentElement)
                g_po->g_pCurrentElement = g_po->g_pLastElement;
            g_po->g_pCurrentElement--;
        } else {
            g_po->g_pCurrentElement = g_po->g_elementList;
        }
        g_po->g_pCurrentElement->element->selectX(g_po);
    } else
        mvwprintw(g_po->g_ncursWin, 4, 5, "NO ELEMENTS");
}

void tuiWin_t::vEventHndlKey_down	(void)  {
    if(g_po->g_bElementList) {
        if(g_po->g_pCurrentElement) {
            g_po->g_pCurrentElement++;
            if(g_po->g_pLastElement == g_po->g_pCurrentElement)
                g_po->g_pCurrentElement = g_po->g_elementList;
        } else {
            g_po->g_pCurrentElement = g_po->g_elementList;
        }
        g_po->g_pCurrentElement->element->selectX(g_po);
    }
}

void tuiWin_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_enter	(void)  {
    g_po->g_pCurrentElement->element->eventOn();
}

void tuiWin_t::vEventHndlKey_home	(void)  {
    g_po->selectX();
    if(g_po->g_poFather) g_po->g_poFather->eventOn();

}


event_t tuiWin_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};


