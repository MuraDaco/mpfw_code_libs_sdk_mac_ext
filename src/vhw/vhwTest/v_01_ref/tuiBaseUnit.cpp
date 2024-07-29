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
 * tuiBaseUnit.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseUnit.h"

event_t* tuiBaseUnit_t::g_eventArray = nullptr;

uint32_t tuiBaseUnit_t::g_currentSelCnt = 0;

tuiBaseUnit_t*  tuiBaseUnit_t::g_poSelected;
tuiBaseUnit_t*  tuiBaseUnit_t::g_pSelectedOld;
WINDOW*         tuiBaseUnit_t::g_ncursWinSelected;
WINDOW*         tuiBaseUnit_t::g_ncursWinSelectedOld;


tuiBaseUnit_t::tuiBaseUnit_t (zone_t* p_zoneList) :
     g_pBox           {nullptr}
    ,g_zoneList      {p_zoneList}
{}

tuiBaseUnit_t::tuiBaseUnit_t (box_t* p_pBox, zone_t* p_zoneList) :
     g_pBox             {p_pBox}
    ,g_zoneList         {p_zoneList}
{}

bool tuiBaseUnit_t::loop       	(void)  {
    //if(g_pSelectedOld != g_poSelected)   {
    //    g_pSelectedOld->deSelect();
    //    if(g_ncursWinSelectedOld != g_ncursWinSelected) {
    //        wrefresh(g_ncursWinSelectedOld);
    //        g_ncursWinSelectedOld = g_ncursWinSelected;
    //    } else {
    //        wrefresh(g_ncursWinSelected);
    //    }
    //    g_pSelectedOld = g_poSelected;
    //}

    return true;	
}

void tuiBaseUnit_t::deSelectSelected         (tuiBaseUnit_t* p_pSelected)    {
    // de-select the previous element
    g_poSelected->deSelect();
    g_poSelected = p_pSelected;
    g_currentSelCnt++;
    p_pSelected->g_selCnt = g_currentSelCnt;
}

bool tuiBaseUnit_t::bTstSelCnts    (uint8_t p_selCnt1, uint8_t p_selCnt2)  {
    bool l_result = false;
    if(p_selCnt2 != g_currentSelCnt)  {
        if(p_selCnt1 < p_selCnt2)   {
            l_result = true;
        }
    } else {
        l_result = true;
    }

    return l_result;
}

//void tuiBaseUnit_t::setSelected         (WINDOW* p_ncursWinSelected, tuiBaseUnit_t* p_pSelected)    {
//    g_poSelected->deSelect();
//    if(g_ncursWinSelectedOld != g_ncursWinSelected) {
//        wrefresh(g_ncursWinSelected);
//        g_ncursWinSelectedOld = g_ncursWinSelected;
//    } else {
//        wrefresh(g_ncursWinSelected);
//    }
//    g_poSelected = p_pSelected;
//}

void tuiBaseUnit_t::setNcursWindow      (WINDOW* p_ncursWinSelected)    {
    g_ncursWinSelectedOld = g_ncursWinSelected;
    g_ncursWinSelected    = p_ncursWinSelected;
}



void tuiBaseUnit_t::SetEventArrayOfWindow   	(void)      {
    g_pFather->SetEventArrayOfWindow();
}

bool tuiBaseUnit_t::bMouseClickInsideBounds (point_t p_mouseXY)      {
    bool l_result = false;

    if(
        ((g_pBox->xStart <= p_mouseXY.x) && (p_mouseXY.x < (g_pBox->xStart+g_pBox->width ))) &&
        ((g_pBox->yStart <= p_mouseXY.y) && (p_mouseXY.y < (g_pBox->yStart+g_pBox->height)))
    ) {
        l_result = true;
        //select();
        //if(!bCheckSensitiveZone(p_mouseXY))  {
        //    //for_each(element of elementList)   {
        //    //    if(elementList[element]->bMouseClickInsideBounds(p_mouseXY))    {
        //    //        l_result = true;
        //    //        break;
        //    //    }
        //    //}
        //}
    }
    return l_result;
}

bool tuiBaseUnit_t::bCheckSensitiveZone (point_t p_mouseXY)      {
    bool l_result = false;
    zone_t* l_zoneList = g_zoneList;
    while(l_zoneList->hndl)   {
        if(
            (l_zoneList->box.xStart <= p_mouseXY.x < (l_zoneList->box.xStart+l_zoneList->box.width)) &&
            (l_zoneList->box.yStart <= p_mouseXY.y < (l_zoneList->box.yStart+l_zoneList->box.height))
        ) {
            l_result = true;
            //l_zoneList->hndl();
            //setEventWinTbl()
            break;
        }
        l_zoneList++;
    }

    return l_result;
}
