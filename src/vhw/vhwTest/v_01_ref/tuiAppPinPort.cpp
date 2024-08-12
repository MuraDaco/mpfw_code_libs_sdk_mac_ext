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
 
#include "tuiAppPinPort.h"
#include "tuiBaseDgtInOut.h"
#include "tuiDigitalInOut.h"
#include "tuiDigitalInOut2.h"

#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Leds.h"
#include "vhwPphTbl_Mod1.h"


// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppPinPort_t::g_box = {25,  75,  8, 80};
// -------- BOX define - end


// **********************************************************
// -------- ELEMENT LIST define - start
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_NEO    ,1 ,40 , 3 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_MAO    ,1 ,40 , 4 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_LEO    ,1 ,40 , 5 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_RAI       ,1 ,40 , 6 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_REO       ,1 ,40 , 7 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_REI       ,1 ,40 , 8 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_XOR    ,1 ,40 , 9 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_NOR    ,1 ,40 ,10 ,1  )


tuiBaseListUnit_t::element_t tuiAppPinPort_t::g_baseElementList[] = {
    //{nullptr                   , 1 }
     {&TUI_OBJ   (BUTTON_NEO)   , 1 }
    ,{&TUI_OBJ   (BUTTON_MAO)   , 0 }
    ,{&TUI_OBJ   (BUTTON_LEO)   , 3 }
    ,{&TUI_OBJ   (LED_RAI)      , 3 }
    ,{&TUI_OBJ   (LED_REO)      , 3 }
    ,{&TUI_OBJ   (LED_REI)      , 3 }
    ,{&TUI_OBJ   (SWITCH_XOR)   , 6 }
    ,{&TUI_OBJ   (SWITCH_NOR)   , 6 }
    ,{nullptr                   , 1 }
};

// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiBaseWin_t    tuiAppPinPort_t::g_baseWin  ("PinPort Window", &g_box,              g_baseElementList   );
// -------- MAIN WINDOW define - end
