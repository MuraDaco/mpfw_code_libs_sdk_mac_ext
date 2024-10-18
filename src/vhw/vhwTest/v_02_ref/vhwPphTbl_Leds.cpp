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
 * vhwPphTbl_Leds.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#include "mcuPinPortDefineConfig.h"
#include "pphLed.h"


PPH_DEF_CPP   (pphLed_t, LED_RAI)
PPH_DEF_CPP   (pphLed_t, LED_REO)
PPH_DEF_CPP   (pphLed_t, LED_REI)

PPH_DEF_CPP   (pphLed_t, LED_PER)
PPH_DEF_CPP   (pphLed_t, LED_PUR)
PPH_DEF_CPP   (pphLed_t, LED_MAI)


PPH_DEF_CPP                     (pphLed_t, LED_A)                 // pph_LED_A
PPH_DEF_CPP                     (pphLed_t, LED_C)                 // pph_LED_C

PPH_DEF_CPP                     (pphLed_t, LED_XXX)                 // pph_LED_A
PPH_DEF_CPP                     (pphLed_t, LED_YYY)                 // pph_LED_C

