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


#include "mcuPinPortDefineConfig.h"
#include "pphLed.h"

DEF_MCU_PIN_PORT                (LED_A, dout)           // mcu_LED_A
DEF_PPH_LED_2                   (LED_A)                 // pph_LED_A

DEF_MCU_PIN_PORT_DEVICE         (LED_B,4, dout)         // mcu_4_LED_A
DEF_PPH_LED_DEVICE              (LED_B,4)               // pph_4_LED_A

DEF_MCU_PIN_PORT_PTR            (LED_C, dout)           // mcu_LED_C
DEF_PPH_LED                     (LED_C)                 // pph_LED_C

