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
 * mcuPinPortDefineConfig.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef MCU_PIN_PORT_DEFINE_CONFIG_H
#define MCU_PIN_PORT_DEFINE_CONFIG_H

/*
    peripherals list
    - USART_RX
    - USART_TX
    - LED_TEST
    - LED_A
    - LED_B
    - LED_C
    - BUTTON_UP
    - SWITCH_TST1
    - ALARM_A_OUT
    - ALARM_A_IN

    for each (peripheral) create a #define of (PORT) and (PIN)
        #define MCU_[<device id>_]<peripheral name>_PORT_PTR  <sdk referiment port pointer>
        #define MCU_[<device id>_]<peripheral name>_PORT      <sdk referiment port ID>
        #define MCU_[<device id>_]<peripheral name>_PIN       <pin ID>

*/



#define MCU_USART_RX_PORT_PTR               SDK_MCU_PORT_A_PTR
#define MCU_USART_RX_PORT                   SDK_MCU_PORT_A
#define MCU_USART_RX_PIN                    3
#define MCU_USART_TX_PORT_PTR               SDK_MCU_PORT_A_PTR
#define MCU_USART_TX_PORT                   SDK_MCU_PORT_A
#define MCU_USART_TX_PIN                    4

#define MCU_LED_TEST_PORT_PTR               SDK_MCU_PORT_D_PTR
#define MCU_LED_TEST_PORT                   SDK_MCU_PORT_D
#define MCU_LED_TEST_PIN                    6

#define MCU_LED_A_PORT_PTR                  SDK_MCU_PORT_E_PTR
#define MCU_LED_A_PORT                      SDK_MCU_PORT_E
#define MCU_LED_A_PIN                       7

#define MCU_4_LED_B_dout_PORT_PTR                  SDK_MCU_PORT_F_PTR
#define MCU_4_LED_B_dout_PORT                      SDK_MCU_PORT_F
#define MCU_4_LED_B_dout_PIN                       2

#define MCU_LED_C_PORT_PTR                  SDK_MCU_PORT_D_PTR
#define MCU_LED_C_PORT                      SDK_MCU_PORT_D
#define MCU_LED_C_PIN                       3

#define MCU_BUTTON_UP_PORT_PTR              SDK_MCU_PORT_B_PTR
#define MCU_BUTTON_UP_PORT                  SDK_MCU_PORT_B
#define MCU_BUTTON_UP_PIN                   0

#define MCU_SWITCH_TST1_PORT_PTR            SDK_MCU_PORT_B_PTR
#define MCU_SWITCH_TST1_PORT                SDK_MCU_PORT_B
#define MCU_SWITCH_TST1_PIN                 1

//      MCU_<pin function>_port
#define MCU_2_ALARM_A_dout_PORT_PTR            SDK_MCU_PORT_C_PTR
#define MCU_2_ALARM_A_dout_PORT                SDK_MCU_PORT_C
#define MCU_2_ALARM_A_dout_PIN                 1
#define MCU_5_ALARM_A_din_PORT_PTR             SDK_MCU_PORT_H_PTR
#define MCU_5_ALARM_A_din_PORT                 SDK_MCU_PORT_H
#define MCU_5_ALARM_A_din_PIN                  4

// #define MCU_ALARM_A_PORT_PTR      SDK_MCU_PORT_C_PTR
// #define MCU_ALARM_A_PORT          SDK_MCU_PORT_C
// #define MCU_ALARM_A_PIN           1
// #define MCU_ALARM_A_PORT_PTR       SDK_MCU_PORT_H_PTR
// #define MCU_ALARM_A_PORT           SDK_MCU_PORT_H
// #define MCU_ALARM_A_PIN            4


#endif 	// MCU_PIN_PORT_DEFINE_CONFIG_H
