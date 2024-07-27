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

//#include "vhwPphObjs.hpp"
//#include "vhwPphTbl.h"
#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Mod1.h"


// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppPinPort_t::g_box = {10, 45, 15, 20};
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
//tuiDigitalInOut_t tuiButtonTest2 (&OBJ_PPH_BUTTON(vhwPphObjs_t,BUTTON_TEST).g_dtyUint8_mcuPort);
//tuiDigitalInOut_t tuiButtonTest (&OBJ_PPH_BUTTON_STD(BUTTON_TEST).g_dtyUint8_mcuPort);

//DEF_TUI_DIGITAL_IN_OUT_OBJ  (BUTTON_TEST)
DEF_TUI_DIGITAL_IN_OUT_OBJ  (BUTTON_TEST, 0, 3)
DEF_TUI_DIGITAL_IN_OUT_OBJ  (BUTTON_XXX, 0, 5)
DEF_TUI_DIGITAL_IN_OUT_OBJ  (BUTTON_UP, 0, 7)
//DEF_TUI_DIGITAL_IN_OUT_OBJ  (0, 1, BUTTON_TEST)

tuiWin_t::element_t tuiAppPinPort_t::g_elementList[] = {
     {&OBJ_TUI_DIGITAL_IN_OUT   (BUTTON_TEST), 1}
    ,{&OBJ_TUI_DIGITAL_IN_OUT   (BUTTON_XXX), 0}
    ,{&OBJ_TUI_DIGITAL_IN_OUT   (BUTTON_UP), 3}
    ,{nullptr, 1}
};
// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiWin_t tuiAppPinPort_t::g_win ("PinPort Window", &g_box, g_zoneList, g_elementList);
// -------- MAIN WINDOW define - end
