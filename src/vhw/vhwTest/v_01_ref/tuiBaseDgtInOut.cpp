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
 * tuiBaseDgtInOut.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseDgtInOut.h"


tuiBaseDgtInOut_t*	tuiBaseDgtInOut_t::g_po = nullptr;

tuiBaseDgtInOut_t::tuiBaseDgtInOut_t      (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus     )     :
     tuiBase_t          (p_strName, p_box, p_pDtyStatus)
    ,g_pDtyStatus           {p_pDtyStatus}
{}


void tuiBaseDgtInOut_t::init       (void* p_poFather) 	{
    g_poFather  = static_cast<tuiBase_t*>(p_poFather);
    g_pNcursWin = static_cast<tuiBase_t*>(p_poFather)->g_pNcursWin;
    g_x0Win     = static_cast<tuiBase_t*>(p_poFather)->g_x0Win  ; // + g_x0r;
    g_y0Win     = static_cast<tuiBase_t*>(p_poFather)->g_y0Win  ; // + g_y0r;
    g_x0a       = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a       = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;

    nameNstatus();
}

bool tuiBaseDgtInOut_t::loop            (void)  {
    bool l_result = false;

    return l_result;
}


void tuiBaseDgtInOut_t::select         (void)    {
    //wattron(g_ncursWin, A_UNDERLINE);
    //mvwprintw(g_ncursWin, g_box.yStart, g_box.xStart, "-- %s -- %02d", tuiBase_t::g_strName, *g_pDtyStatus->g_pValue);
    //wattroff(g_ncursWin, A_UNDERLINE);
    //wrefresh(g_ncursWin);
    //-- point_t l_point0 = { reinterpret_cast<tuiBaseDrawer_t*>(g_poFather)->g_x0r,  reinterpret_cast<tuiBaseDrawer_t*>(g_poFather)->g_y0r};
    //-- nameNstatus(tuiMode_t::select, l_point0);

    nameNstatus(tuiMode_t::select);

}

void tuiBaseDgtInOut_t::selectByMouse       (void)    {
    deselectBackNselect(g_poFather);
    eventOn();
}

void tuiBaseDgtInOut_t::display          (void)    {
    //nameNstatus(tuiMode_t::deselect);
    //point_t l_point0 = { g_poFather->g_pBox->xStart,  g_poFather->g_pBox->yStart};
    //-- nameNstatus(tuiMode_t::deselect, { reinterpret_cast<tuiBaseDrawer_t*>(g_poFather)->g_x0r,  reinterpret_cast<tuiBaseDrawer_t*>(g_poFather)->g_y0r});
    nameNstatus(tuiMode_t::deselect);

    // mvwprintw(g_ncursWin, g_box.yStart, g_box.xStart, "-- %s -- %02d", tuiBase_t::g_strName, *g_pDtyStatus->g_pValue);
    // wrefresh(g_ncursWin);
}

void tuiBaseDgtInOut_t::deSelect        (void)    {
    //point_t l_point0 = { g_poFather->g_pBox->xStart,  g_poFather->g_pBox->yStart};
    //nameNstatus(tuiMode_t::deselect, { reinterpret_cast<tuiBaseDrawer_t*>(g_poFather)->g_x0r,  reinterpret_cast<tuiBaseDrawer_t*>(g_poFather)->g_y0r});
    nameNstatus(tuiMode_t::deselect);
    // mvwprintw(g_ncursWin, g_box.yStart, g_box.xStart, "-- %s -- %02d", tuiBase_t::g_strName, *g_pDtyStatus->g_pValue);
    // wrefresh(g_ncursWin);
}

void tuiBaseDgtInOut_t::eventOn         (void)    {
    g_po = this;
    tuiBaseAction_t::g_eventArray  = g_eventArray;
    nameNstatus(tuiMode_t::eventOn);
}

void tuiBaseDgtInOut_t::vEventHndlKey_down	(void)  {
}

void tuiBaseDgtInOut_t::vEventHndlKey_up	(void)  {
}

void tuiBaseDgtInOut_t::vEventHndlKey_left	(void)  {
}

void tuiBaseDgtInOut_t::vEventHndlKey_right	(void)  {
}

void tuiBaseDgtInOut_t::vEventHndlKey_enter	(void)  {
    g_po->g_pDtyStatus->vInc();
}

void tuiBaseDgtInOut_t::vEventHndlKey_home	(void)  {
    g_po->deselectBackNselect();
    g_po->g_poFather->eventOn();

}


event_t tuiBaseDgtInOut_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};


