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
 * tuiAppBoard.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiAppBoard.h"

#include "tuiAppPinPort.h"
#include "tuiDigitalInOut.h"
#include "tuiDigitalInOut2.h"

#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Leds.h"
#include "vhwPphTbl_Mod1.h"

// **********************************************************
// -------- BOX define - start
// .......................... H   W  Yo  Xo
box_t tuiAppBoard_t::g_box = {25,  75,  5,  5};
// -------- BOX define - end

// **********************************************************
// -------- ZONE LIST define - start
void tuiAppBoard_t::zone_1_hndl    (void)  {
}

void tuiAppBoard_t::zone_2_hndl    (void)  {
}

tuiBaseUnit_t::zone_t tuiAppBoard_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_1_hndl}
    ,{{1, 2, 3, 4}, zone_2_hndl}
    ,{{1, 2, 3, 4}, nullptr}
};
// -------- ZONE LIST define - end

// **********************************************************
// -------- ELEMENT LIST define - start
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,BUTTON_AAA     ,1  ,  3 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,BUTTON_BBB     ,1  ,  4 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,BUTTON_CCC     ,1  ,  5 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,LED_XXX        ,1  ,  6 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,LED_YYY        ,1  ,  7 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,SWITCH_GGG     ,1  ,  8 )
TUI_DEF_CPP  (tuiDigitalInOut2_t    ,mcuPinPort2_t  ,ALARM_NNN      ,1  ,  9 )
TUI_DEF_CPP  (tuiDigitalInOut2_t    ,mcuPinPort2_t  ,LINK_TTT       ,1  , 10 )

tuiWin_t::element_t tuiAppBoard_t::g_elementList[] = {
     {&TUI_OBJ   (BUTTON_AAA)   ,  1 }
    ,{&TUI_OBJ   (BUTTON_BBB)   ,  0 }
    ,{&TUI_OBJ   (BUTTON_CCC)   ,  3 }
    ,{&TUI_OBJ   (LED_XXX)      ,  3 }
    ,{&TUI_OBJ   (LED_YYY)      ,  3 }
    ,{&TUI_OBJ   (SWITCH_GGG)   ,  6 }
    ,{&TUI_OBJ   (ALARM_NNN)    ,  3 }
    ,{&TUI_OBJ   (LINK_TTT)     , 19 }
    ,{nullptr                   ,  1 }
};
// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiWin_t tuiAppBoard_t::g_win ("Board Window", &g_box, g_zoneList, g_elementList);
// -------- MAIN WINDOW define - end
