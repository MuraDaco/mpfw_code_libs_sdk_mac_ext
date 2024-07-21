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
 * vhwPphMcuPinPortWiredTbl.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau

    see the mcuPinPort.h to know how to compose the PORT and PIN #define name
    MCU_<port function name>_PORT
    MCU_<port function name>_PIN

 */

#include <iostream>

#include "mcuPortDef.h"

#include "vhwPphMcuPinPortWiredTbl.h"
#include "mcuPinPort.h"
#include "pphLed.h"
#include "pphButton.h"
#include "pphSwitch.h"

#include "mcuPinPortDefineConfig.h"

void pippo  (void)  {
    std::cout << "pippo - interrupt function\n";
}


//#define MCU_LED_TEST_PORT          SDK_MCU_PORT_D
//#define MCU_LED_TEST_PIN           6
DEF_MCU_PIN_PORT_DEVICE_CONFIG (LED_TEST, 3, dout)

//DEF_MCU_PIN_PORT_INOUT_DEVICE_CONFIG (LED_TEST, 3, dout)
//DEF_MCU_PIN_PORT_USART_DEVICE_CONFIG (LED_TEST, 3, dout)
//DEF_MCU_PIN_PORT_I2C_DEVICE_CONFIG (LED_TEST, 3, dout)
//DEF_MCU_PIN_PORT_SPI_DEVICE_CONFIG (LED_TEST, 3, dout)


//#define MCU_LED_A_PORT          SDK_MCU_PORT_E
//#define MCU_LED_A_PIN           7
DEF_MCU_PIN_PORT                (LED_A, dout)                 // mcu_LED_A
//DEF_PPH_LED                     (LED_A)                 // pph_LED_A
DEF_PPH_LED_2                     (LED_A)                 // pph_LED_A
DEVICE_WIRED_PIN                (LED_A)                 // pin_wired_LED_A

//#define MCU_LED_B_PORT          SDK_MCU_PORT_F
//#define MCU_LED_B_PIN           2
DEF_MCU_PIN_PORT_DEVICE         (LED_B,4, dout)               // mcu_4_LED_A
DEF_PPH_LED_DEVICE              (LED_B,4)               // pph_4_LED_A
DEVICE_WIRED_PIN_ID             (LED_B,4)               // pin_wired_LED_B_device_4

//#define MCU_LED_C_PORT          SDK_MCU_PORT_D
//#define MCU_LED_C_PIN           3
DEF_MCU_PIN_PORT_PTR            (LED_C, dout)                 // mcu_LED_C
DEF_PPH_LED                     (LED_C)                 // pph_LED_C
DEVICE_WIRED_PIN                (LED_C)                 // pin_wired_LED_C

//#define MCU_BUTTON_UP_PORT      SDK_MCU_PORT_B
//#define MCU_BUTTON_UP_PIN       0
DEF_MCU_PIN_PORT                (BUTTON_UP, din)       // mcu_BUTTON_UP
DEF_PPH_BUTTON                  (BUTTON_UP)       // pph_BUTTON_UP
DEVICE_WIRED_PIN                (BUTTON_UP)

//#define MCU_SWITCH_TST1_PORT    SDK_MCU_PORT_B
//#define MCU_SWITCH_TST1_PIN     1
DEF_MCU_PIN_PORT                (SWITCH_TST1, din)       // mcu_BUTTON_UP
DEF_PPH_BUTTON                  (SWITCH_TST1)       // pph_BUTTON_UP
DEVICE_WIRED_PIN                (SWITCH_TST1)

//      MCU_<pin function>_port
//#define MCU_ALARM_A_OUT_PORT    SDK_MCU_PORT_C
//#define MCU_ALARM_A_OUT_PIN     1
//#define MCU_ALARM_A_IN_PORT     SDK_MCU_PORT_H
//#define MCU_ALARM_A_IN_PIN      4
DEF_MCU_PIN_PORT_DEVICE         (ALARM_A_OUT    ,2, dout)       // mcu_2_OUT_ALARM_A
DEF_MCU_PIN_PORT_DEVICE         (ALARM_A_IN     ,5, din)       // mcu_5_IN_ALARM_A
DEVICE_WIRED_PIN_MCU_MCU        (ALARM_A_OUT, 2, ALARM_A_IN, 5)


vhwUnit_t**  vhwPphMcuPinPortWiredTbl_t::UnitPtrArray[]   = {
     pin_wired_LED_A
    ,pin_wired_LED_C
    ,pin_wired_BUTTON_UP
    ,pin_wired_SWITCH_TST1
    ,pin_wired_LED_B_device_4
    ,pin_wired_ALARM_A_OUT_device_2__ALARM_A_IN_device_5
    ,nullptr
};

//vhwUnit_t*  vhwPphTbl_t::UnitPtrArray[]   = {
//     pin_wired_LED_A
//    ,pin_wired_LED_C
//    ,pin_wired_BUTTON_UP
//    ,pin_wired_SWITCH_TST1
//    ,pin_wired_LED_B_device_4
//    ,pin_wired_ALARM_A_OUT_device_2__ALARM_A_IN_device_5
//    ,nullptr
//};
