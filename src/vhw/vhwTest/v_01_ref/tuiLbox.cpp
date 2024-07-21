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


tuiBaseUnit_t::tuiBaseUnit_t (zone_t* p_zoneList) :
    g_zoneList      {p_zoneList}
{}

tuiBaseUnit_t::tuiBaseUnit_t (box_t* p_box, zone_t* p_zoneList) :
     g_box              {p_box}
    ,g_zoneList         {p_zoneList}
{}


void tuiBaseUnit_t::SetEventArrayOfWindow   	(void)      {
    g_pFather->SetEventArrayOfWindow();
}

bool tuiBaseUnit_t::bMouseClickInsideBounds (point_t p_mouseXY)      {
    bool l_result = false;

    if(
        ((g_box->xStart <= p_mouseXY.x) && (p_mouseXY.x < (g_box->xStart+g_box->width ))) &&
        ((g_box->yStart <= p_mouseXY.y) && (p_mouseXY.y < (g_box->yStart+g_box->height)))
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
