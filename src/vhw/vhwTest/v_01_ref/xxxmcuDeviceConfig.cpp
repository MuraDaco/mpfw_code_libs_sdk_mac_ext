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
 * mcuDeviceConfig.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>

#include "vhwMcuPortWiredTbl.h"
#include "mcuPort.h"
#include "pphLed.h"
#include "pphButton.h"
#include "pphSwitch.h"

void pippo  (void)  {
    std::cout << "pippo - interrupt function\n";
}


#define MCU_LED_A_PORT    4
#define MCU_LED_A_PIN     7
DEF_MCU_PORT_PIN                (LED_A)         // mcu_LED_A
DEF_PPH_LED                     (LED_A)         // pph_LED_A
#define MCU_LED_B_PORT    5
#define MCU_LED_B_PIN     2
DEF_MCU_PORT_PIN_DEVICE         (LED_B,4)       // mcu_4_LED_A
DEF_PPH_LED_DEVICE              (LED_B,4)       // pph_4_LED_A

#define MCU_BUTTON_UP_PORT    1
#define MCU_BUTTON_UP_PIN     0
DEF_MCU_PORT_PIN                (BUTTON_UP)       // mcu_BUTTON_UP
DEF_PPH_BUTTON                  (BUTTON_UP)       // pph_BUTTON_UP

#define MCU_SWITCH_TST1_PORT    1
#define MCU_SWITCH_TST1_PIN     1
DEF_MCU_PORT_PIN                (SWITCH_TST1)       // mcu_BUTTON_UP
DEF_PPH_BUTTON                  (SWITCH_TST1)       // pph_BUTTON_UP

//      MCU_<pin function>_port
#define MCU_ALARM_A_OUT_PORT    2
#define MCU_ALARM_A_OUT_PIN     1
#define MCU_ALARM_A_IN_PORT     7
#define MCU_ALARM_A_IN_PIN      4
DEF_MCU_PORT_PIN_DEVICE         (ALARM_A_OUT,2)       // mcu_2_OUT_ALARM_A
DEF_MCU_PORT_PIN_DEVICE         (ALARM_A_IN,5)       // mcu_5_IN_ALARM_A


DEVICE_WIRED_PIN            (LED_A)
DEVICE_WIRED_PIN            (BUTTON_UP)
DEVICE_WIRED_PIN            (SWITCH_TST1)
DEVICE_WIRED_PIN_ID         (LED_B, 4)
DEVICE_WIRED_PIN_MCU_MCU    (ALARM_A_OUT, 2, ALARM_A_IN, 5)


vhwUnit_t**  vhwMcuPortWiredTbl_t::vhwUnitPtrArray[]   = {
     pin_wired_LED_A
    ,pin_wired_BUTTON_UP
    ,pin_wired_SWITCH_TST1
    ,pin_wired_LED_B_device_4
    ,pin_wired_ALARM_A_OUT_device_2__ALARM_A_IN_device_5
    ,nullptr
};
