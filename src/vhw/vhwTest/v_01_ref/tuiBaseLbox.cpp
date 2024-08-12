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
 * tuiBaseLbox.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseLbox.h"


tuiBaseLbox_t*	tuiBaseLbox_t::g_po = nullptr;


tuiBaseLbox_t::tuiBaseLbox_t      (const char* p_strName, box_t* p_pBox, element_t* p_elementList) :
     tuiBaseListUnit_t         (p_strName, p_pBox, p_elementList)
{}

void tuiBaseLbox_t::init       (void* p_poFather) 	{
    // 1. backup pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather = static_cast<tuiBase_t*>(p_poFather);
    g_pNcursWin = static_cast<tuiBase_t*>(p_poFather)->g_pNcursWin;
    g_x0Win     = static_cast<tuiBase_t*>(p_poFather)->g_x0Win  + g_x0r;
    g_y0Win     = static_cast<tuiBase_t*>(p_poFather)->g_y0Win  + g_y0r;
    g_x0a       = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a       = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;


    //g_box.draw(g_ncursWin);    
    frameNname(tuiMode_t::deselect);

    //tuiBaseDrawer__name(0, 85);

    //g_box.drawFrame(g_ncursWin, SELECT/DESELECT);    
    //g_box.drawName(g_ncursWin, SELECT/DESELECT);    
    //g_box.drawStatus(g_ncursWin, SELECT/DESELECT);    
    //g_box.draw(g_ncursWin, g_box.g_y0r, g_box.g_x0r + 5, " *~ %s ~* ", g_strName);

    //g_box.draw_name(g_ncursWin);    
    //g_box.draw_value(g_ncursWin, SELECT/DESELECT);    
    //g_box.draw_element(g_ncursWin, DESELECT/SELECT, );    // the element has the coords where draw the name and the value
    //g_box.draw_elements(g_ncursWin);
    //tuiGraphicBox__draw(g_ncursWin, g_box.g_y0r, g_box.g_x0r + 5, " *~ %s ~* ", tuiDrawerBase_t::g_strName);
    // point_t l_point0 = {g_x0r, g_y0r};
    // initElementsList(l_point0);
    initElementsList();

}


void tuiBaseLbox_t::select         (void)    {
    frameNname(tuiMode_t::select);
}

void tuiBaseLbox_t::selectByMouse         (void)    {
    if(selectElements()) {
        select();
    } else {
        deselectBackNselect();
        g_po = this;
        eventOn();
    }
    
}

void tuiBaseLbox_t::display               (void)    {
    frameNname(tuiMode_t::deselect);
}

void tuiBaseLbox_t::deSelect        (void)    {
    frameNname(tuiMode_t::deselect);
}


void tuiBaseLbox_t::eventOn     (void)    {
    g_po = this;
    tuiBaseAction_t::g_eventArray  = g_eventArray;
    frameNname(tuiMode_t::eventOn);
}

void tuiBaseLbox_t::vEventHndlKey_up	(void)  {
    prevElement(g_po);
}

void tuiBaseLbox_t::vEventHndlKey_down	(void)  {
    nextElement(g_po);
}

void tuiBaseLbox_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseLbox_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiBaseLbox_t::vEventHndlKey_enter	(void)  {
    if(g_po->g_pCurrentElement->element->isSelected())  {
        g_po->frameNname(tuiMode_t::select);
        g_po->g_pCurrentElement->element->eventOn();
    }
}

void tuiBaseLbox_t::vEventHndlKey_home	(void)  {
    g_po->deselectBackNselect();
    if(g_po->g_poFather) g_po->g_poFather->eventOn();

}


event_t tuiBaseLbox_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};
