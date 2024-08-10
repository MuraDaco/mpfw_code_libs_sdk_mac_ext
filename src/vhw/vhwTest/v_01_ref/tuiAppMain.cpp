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
 * tuiAppMain.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiAppMain.h"

#include "tuiAppUSART_1.h"
#include "tuiAppPinPort.h"
#include "tuiAppBoard.h"
#include "tuiManager.h"


// **********************************************************
// -------- BOX define - start
box_t tuiAppMain_t::g_box = {20, 80, 5, 5};
// -------- BOX define - end

// **********************************************************
// -------- ZONE LIST define - start
void tuiAppMain_t::zone_1_hndl    (void)  {
}

void tuiAppMain_t::zone_2_hndl    (void)  {
}

tuiBaseUnit_t::zone_t tuiAppMain_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_1_hndl}
    ,{{1, 2, 3, 4}, zone_2_hndl}
    ,{{1, 2, 3, 4}, nullptr}
};
// -------- ZONE LIST define - end

// **********************************************************
// -------- ELEMENT LIST define - start
tuiWin_t::element_t tuiAppMain_t::g_elementList[] = {
     {&tuiAppBoard_t::      g_win, 2}
    ,{&tuiAppPinPort_t::    g_win, 7}
    ,{&tuiAppUSART_1_t::    g_win, 5}
    ,{nullptr, 1}
};

tuiBaseListUnit_t::element_t tuiAppMain_t::g_baseElementList[] = {
    //{nullptr, 1}
     {&tuiAppBoard_t::      g_baseWin, 2}
    ,{&tuiAppPinPort_t::    g_baseWin, 7}
    ,{&tuiAppUSART_1_t::    g_baseWin, 5}
    ,{nullptr, 1}
};
// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiWinRoot_t        tuiAppMain_t::g_win     ("Main Window"      ,&g_box ,g_zoneList ,g_elementList);
tuiBaseWinRoot_t    tuiAppMain_t::g_baseWin ("Base Main Window" ,&g_box             ,g_baseElementList);
// -------- MAIN WINDOW define - end


