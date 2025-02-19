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
 * tuiLbox.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiLbox.h"


tuiLbox_t*	tuiLbox_t::g_po = nullptr;


tuiLbox_t::tuiLbox_t      (const char* p_strName, box_t* p_pBox, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseWlistUnit_t         (p_strName, p_pBox, p_zoneList, p_elementList)
    ,tuiDrawerBase_t            (p_strName, p_pBox)
{}

void tuiLbox_t::init       (void* p_poFather) 	{
    // 1. backup pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather = static_cast<tuiBaseUnit_t*>(p_poFather);

    g_ncursWin = g_poFather->g_ncursWin;
    g_pNcursWin = g_poFather->g_ncursWin;

    //g_box.draw(g_ncursWin);    
    frame(tuiMode_t::deselect);
    tuiDrawer__mvprintw(0, 5, " *~ %s ~* ", tuiDrawerBase_t::g_strName);

    //tuiDrawer__name(0, 85);

    //g_box.drawFrame(g_ncursWin, SELECT/DESELECT);    
    //g_box.drawName(g_ncursWin, SELECT/DESELECT);    
    //g_box.drawStatus(g_ncursWin, SELECT/DESELECT);    
    //g_box.draw(g_ncursWin, g_box.g_y0, g_box.g_x0 + 5, " *~ %s ~* ", g_strName);

    //g_box.draw_name(g_ncursWin);    
    //g_box.draw_value(g_ncursWin, SELECT/DESELECT);    
    //g_box.draw_element(g_ncursWin, DESELECT/SELECT, );    // the element has the coords where draw the name and the value
    //g_box.draw_elements(g_ncursWin);
    //tuiGraphicBox__draw(g_ncursWin, g_box.g_y0, g_box.g_x0 + 5, " *~ %s ~* ", tuiDrawerBase_t::g_strName);
    point_t l_point0 = {g_x0, g_y0};
    initElementsList(l_point0);
    //initElementsList();

}


void tuiLbox_t::select         (void)    {
    frame(tuiMode_t::select);
}

void tuiLbox_t::selectByMouse         (void)    {
    if(selectElements()) {
        select();
    } else {
        selectX();
        eventOn();
    }
    
}

void tuiLbox_t::display               (void)    {
    frame(tuiMode_t::deselect);
}

void tuiLbox_t::deSelect        (void)    {
    frame(tuiMode_t::deselect);
}


void tuiLbox_t::eventOn     (void)    {
    g_po = this;
    tuiBaseUnit_t::g_eventArray  = g_eventArray;
}

void tuiLbox_t::vEventHndlKey_up	(void)  {
    prevElement(g_po);
}

void tuiLbox_t::vEventHndlKey_down	(void)  {
    nextElement(g_po);
}

void tuiLbox_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiLbox_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiLbox_t::vEventHndlKey_enter	(void)  {
    g_po->g_pCurrentElement->element->eventOn();
}

void tuiLbox_t::vEventHndlKey_home	(void)  {
    g_po->selectX();
    if(g_po->g_poFather) g_po->g_poFather->eventOn();

}


event_t tuiLbox_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};
