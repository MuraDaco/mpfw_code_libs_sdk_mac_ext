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
 * tuiAppPinPort.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
//import vhwPphTbl;

#include "tuiAppPinPort.h"
#include "tuiDigitalInOut.h"
#include "tuiDigitalInOut2.h"

//#include "vhwPphObjs.hpp"
//#include "vhwPphTbl.h"
#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Leds.h"
#include "vhwPphTbl_Mod1.h"


// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppPinPort_t::g_box = {12, 45, 15, 20};
// -------- BOX define - end

// **********************************************************
// -------- ZONE LIST define - start
void tuiAppPinPort_t::zone_1_hndl    (void)  {
}

void tuiAppPinPort_t::zone_2_hndl    (void)  {
}

tuiBaseUnit_t::zone_t tuiAppPinPort_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_1_hndl}
    ,{{1, 2, 3, 4}, zone_2_hndl}
    ,{{1, 2, 3, 4}, nullptr}
};
// -------- ZONE LIST define - end

// **********************************************************
// -------- ELEMENT LIST define - start
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,BUTTON_TEST    ,0  , 3 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,BUTTON_XXX     ,0  , 4 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,BUTTON_UP      ,0  , 5 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,LED_A          ,0  , 6 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,LED_C          ,0  , 7 )
TUI_DEF_CPP  (tuiDigitalInOut_t     ,mcuPinPort_t   ,SWITCH_TST1    ,0  , 8 )
TUI_DEF_CPP  (tuiDigitalInOut2_t    ,mcuPinPort2_t  ,ALARM_A        ,0  , 9 )
TUI_DEF_CPP  (tuiDigitalInOut2_t    ,mcuPinPort2_t  ,LINK_A         ,0  ,10 )

tuiWin_t::element_t tuiAppPinPort_t::g_elementList[] = {
     {&TUI_OBJ   (BUTTON_TEST)  , 1 }
    ,{&TUI_OBJ   (BUTTON_XXX)   , 0 }
    ,{&TUI_OBJ   (BUTTON_UP)    , 3 }
    ,{&TUI_OBJ   (LED_A)        , 3 }
    ,{&TUI_OBJ   (LED_C)        , 3 }
    ,{&TUI_OBJ   (SWITCH_TST1)  , 6 }
    ,{&TUI_OBJ   (ALARM_A)      , 3 }
    ,{&TUI_OBJ   (LINK_A)       ,19 }
    ,{nullptr                   , 1 }
};
// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiWin_t tuiAppPinPort_t::g_win ("PinPort Window", &g_box, g_zoneList, g_elementList);
// -------- MAIN WINDOW define - end
