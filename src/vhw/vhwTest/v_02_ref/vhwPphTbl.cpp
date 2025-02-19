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
 * vhwPphTbl.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau

    see the mcuPinPort.h to know how to compose the PORT and PIN #define name
    MCU_<port function name>_PORT
    MCU_<port function name>_PIN

 */

// export module vhwPphTbl;

#include "vhwPphTbl.h"

#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Leds.h"
#include "vhwPphTbl_Mod1.h"

vhwUnit_t*  vhwPphTbl_t::UnitPtrArray[]   = {
     &PPH_OBJ   (BUTTON_UP)
    ,&PPH_OBJ   (BUTTON_TEST)
    ,&PPH_OBJ   (BUTTON_XXX)
    ,&PPH_OBJ   (LED_A)
    ,&PPH_OBJ   (LED_C)
    ,&PPH_OBJ   (SWITCH_TST1)
    ,&PPH_OBJ   (ALARM_A)

    ,&PPH_OBJ   (BUTTON_AAA)
    ,&PPH_OBJ   (BUTTON_BBB)
    ,&PPH_OBJ   (BUTTON_CCC)
    ,&PPH_OBJ   (LED_XXX)
    ,&PPH_OBJ   (LED_YYY)
    ,&PPH_OBJ   (ALARM_NNN)
    ,&PPH_OBJ   (SWITCH_GGG)
    ,&PPH_OBJ   (LINK_TTT)
    ,nullptr
};

// (BUTTON_AAA)
// (BUTTON_BBB)
// (BUTTON_CCC)
// (LED_XXX)
// (LED_YYY)
// (SWITCH_GGG)
// (ALARM_NNN)
// (LINK_TTT)