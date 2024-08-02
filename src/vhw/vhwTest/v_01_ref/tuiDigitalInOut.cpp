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
 * tuiDigitalInOut.cpp
 *
 *  Created on: Jul, 21th 2024
 *      Author: Marco Dau
 */
 

#include "tuiDigitalInOut.h"


dimension_t tuiDigitalInOut_t::g_boxDim = {40, 1};

tuiDigitalInOut_t*	tuiDigitalInOut_t::g_po = nullptr;

tuiDigitalInOut_t::tuiDigitalInOut_t      (point_t p_origin                               )     :
     tuiBaseUnit_t          (&g_box, g_zoneList)
    ,g_strName              {nullptr}
    ,g_box                  {g_boxDim.height, g_boxDim.width, p_origin.y, p_origin.x}
{}

tuiDigitalInOut_t::tuiDigitalInOut_t      (                   dtyUint8_t* p_pDtyStatus    )     :
     tuiBaseUnit_t          (&g_box, g_zoneList)
    ,g_strName              {nullptr}
    ,g_pDtyStatus           {p_pDtyStatus}
    ,g_boxOrigin            {0, 0}
    ,g_box                  {g_boxDim.height, g_boxDim.width, g_boxOrigin.y, g_boxOrigin.x}
{}

tuiDigitalInOut_t::tuiDigitalInOut_t      (point_t p_origin, dtyUint8_t* p_pDtyStatus     )     :
     tuiBaseUnit_t          (&g_box, g_zoneList)
    ,g_strName              {nullptr}
    ,g_pDtyStatus           {p_pDtyStatus}
    ,g_box                  {g_boxDim.height, g_boxDim.width, p_origin.y, p_origin.x}
{}

tuiDigitalInOut_t::tuiDigitalInOut_t      (const char* p_strName, point_t p_origin, dtyUint8_t* p_pDtyStatus     )     :
     tuiBaseUnit_t          (&g_box, g_zoneList)
    ,g_strName              {p_strName}
    ,g_pDtyStatus           {p_pDtyStatus}
    ,g_box                  {g_boxDim.height, g_boxDim.width, p_origin.y, p_origin.x}
{}


void tuiDigitalInOut_t::init       (void* p_poFather) 	{
    g_poFather = static_cast<tuiBaseUnit_t*>(p_poFather);
    mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    wrefresh(g_ncursWinSelected);
}

bool tuiDigitalInOut_t::loop            (void)  {
    bool l_result = false;

    return l_result;
}


void tuiDigitalInOut_t::selectByKey         (void)    {
    wattron(g_ncursWinSelected, A_UNDERLINE);
    mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    wattroff(g_ncursWinSelected, A_UNDERLINE);
    //box(g_ncursWinSelected, 0, 0);
    wrefresh(g_ncursWinSelected);
}

void tuiDigitalInOut_t::selectByMouse       (void)    {
    selectByKey();
    // wattron(g_ncursWinSelected, A_UNDERLINE);
    // mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    // wattroff(g_ncursWinSelected, A_UNDERLINE);
    // //box(g_ncursWinSelected, 0, 0);
    // wrefresh(g_ncursWinSelected);
}

void tuiDigitalInOut_t::display          (void)    {
//    mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "name: %s - %02x - x: %02d - y: %02d - mx: %2d - my: %02d", g_strName, *g_pDtyStatus->g_pValue, 
//    mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "name: %s - x: %02d - y: %02d - mx: %2d - my: %02d", g_strName, 
//                                                                                    g_pBox->xStart,
//                                                                                    g_pBox->yStart,
//                                                                                    g_mouseXY.x,
//                                                                                    g_mouseXY.y);
    //box(g_ncursWinSelected, 0, 0);
    mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    wrefresh(g_ncursWinSelected);
}

void tuiDigitalInOut_t::deSelect        (void)    {
    mvwprintw(g_ncursWinSelected, g_box.yStart, g_box.xStart, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    wrefresh(g_ncursWinSelected);
}

void tuiDigitalInOut_t::eventOn         (void)    {
    g_po = this;
    tuiBaseUnit_t::g_eventArray  = g_eventArray;
}

void tuiDigitalInOut_t::zone_hndl_1     (void)  {

}

void tuiDigitalInOut_t::zone_hndl_2     (void)  {

}

tuiBaseUnit_t::zone_t tuiDigitalInOut_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_hndl_1}
    ,{{1, 2, 3, 4}, zone_hndl_2}
    ,{{1, 4, 3, 4}, zone_hndl_2}
    ,{{1, 2, 3, 4}, nullptr}
    //,nullptr
};


void tuiDigitalInOut_t::vEventHndlKey_down	(void)  {
}

void tuiDigitalInOut_t::vEventHndlKey_up	(void)  {
    g_po->g_pDtyStatus->vInc();
}

void tuiDigitalInOut_t::vEventHndlKey_left	(void)  {
}

void tuiDigitalInOut_t::vEventHndlKey_right	(void)  {
}

void tuiDigitalInOut_t::vEventHndlKey_enter	(void)  {
}

void tuiDigitalInOut_t::vEventHndlKey_home	(void)  {
}

void tuiDigitalInOut_t::vEventHndlMouse	(void)  {
}

event_t tuiDigitalInOut_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
    ,vEventHndlMouse
};


