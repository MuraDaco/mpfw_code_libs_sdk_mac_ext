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
 * vhwUnitManagerTbl.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>

#include "vhwUnitManagerTbl.h"
#include "mcuPort.h"
#include "pphLed.h"
//#include "mcuPortInst.h"

void pippo  (void)  {
    std::cout << "pippo - interrupt function\n";
}

//#define DEF_MCU_PORT_PIN_TEST(a, name) mcuPort_t mcu_##a##_func_##name(a,##name##_PORT,##name##_PIN);

#define LED_PORT    4
#define LED_PIN     7

mcuPort_t a_1_2_3(1, 2, 3);
DEF_MCU_PORT_PIN            (1, 2 ,3)
DEF_MCU_PORT_PIN            (6, 5 ,1)
DEF_MCU_PORT_PIN            (3, 1 ,5)
DEF_MCU_PORT_PIN            (6, 2 ,0)
DEF_MCU_PORT_PIN_FUNC       (3, 2, 0, pippo)

DEF_MCU_PORT_PIN_TEST       (1, LED)    // mcu_1_func_LED

DEF_PPH_LED                 (LED_1)
DEF_PPH_LED_DEVICE          (LED_2, 3)

vhwUnitManager  vhwUnitManagerTbl::vhwUnitManagerPtrArray[] = {
     {1, 2, a_1_2_3}
    ,{1, 1, mcu_1_port_2_pin_3}
    ,{0, 4, mcu_3_port_1_pin_5}
    ,{3, 7, mcu_6_port_5_pin_1}
    ,{2, 1, mcu_6_port_2_pin_0}
    ,{1, 2, mcu_3_port_2_pin_0}
    // ---------------------------
};

#define VHW_LED_PORT    4
#define VHW_LED_PIN     7

#define MCU_LED_A_PORT    4
#define MCU_LED_A_PIN     7
DEF_MCU_PORT_PIN_X              (LED_A)         // mcu_LED_A
DEF_PPH_LED                     (LED_A)         // pph_LED_A
#define MCU_LED_B_PORT    5
#define MCU_LED_B_PIN     2
DEF_MCU_PORT_PIN_DEVICE_X       (LED_B,4)       // mcu_4_LED_A
DEF_PPH_LED_DEVICE              (LED_B,4)       // pph_4_LED_A

#define MCU_ALARM_OUT_A_PORT    2
#define MCU_ALARM_OUT_A_PIN     1
DEF_MCU_PORT_PIN_DEVICE_X       (ALARM_OUT_A,2)       // mcu_2_OUT_ALALRM_A

#define MCU_ALARM_IN_A_PORT     7
#define MCU_ALARM_IN_A_PIN      4
DEF_MCU_PORT_PIN_DEVICE_X       (ALARM_IN_A,5)       // mcu_5_IN_ALARM_A

DEF_MCU_PORT_PIN_TST2(3, LED)

//#define DEF_MCU_PORT_PIN_TEST(a, name)       mcuPort_t mcu_##a##_func_##name       (a, name##_PORT, name##_PIN);
#define DEF_WIRED(id, end1, end2)       vhwUnit_t*  wired_##id[] = { &end1 ,&end2 ,nullptr };
#define DEVICE_WIRED_PIN(name)                                  vhwUnit_t*  pin_wired_##name[]                              = { &mcu_##name             ,&pph_##name            ,nullptr };
#define DEVICE_WIRED_PIN_ID(name, id)                           vhwUnit_t*  pin_wired_##name##_device_##id[]                = { &mcu_##id##_##name      ,&pph_##id##_##name     ,nullptr };
#define DEVICE_WIRED_PIN_MCU_MCU(name1, id1, name2, id2)        vhwUnit_t*  pin_wired_##name1##_##id1##__##name2##_##id2[]  = { &mcu_##id1##_##name1    ,&mcu_##id2##_##name2   ,nullptr };
//#define DEF_WIRED_MCU_MCU(id, end1, end2)       vhwUnit_t*  wired_##id[] = { &end1 ,&end2 ,nullptr };
//#define DEF_WIRED_MCU_PPH(id, end1, end2)       vhwUnit_t*  wired_##id[] = { &end1 ,&end2 ,nullptr };

vhwUnit_t*  wired_1[] = { &mcu_1_port_2_pin_3 ,&mcu_3_port_1_pin_5 ,nullptr };
vhwUnit_t*  wired_2[] = { &mcu_6_port_5_pin_1 ,&mcu_6_port_2_pin_0 ,nullptr };
vhwUnit_t*  wired_3[] = { &mcu_3_port_2_pin_0 ,&mcu_3_port_1_pin_5 ,&mcu_3_port_2_pin_0 ,nullptr };
vhwUnit_t*  wired_4[] = { &mcu_1_func_LED ,&mcu_3_port_1_pin_5 ,&mcu_3_port_2_pin_0 ,nullptr };



DEF_WIRED(5,mcu_6_port_5_pin_1,mcu_6_port_2_pin_0)
DEF_WIRED(6,mcu_6_port_5_pin_1,pph_LED_1)
DEF_WIRED(7,pph_3_LED_2,mcu_6_port_2_pin_0)
DEVICE_WIRED_PIN            (LED_A)
DEVICE_WIRED_PIN_ID         (LED_B, 4)
DEVICE_WIRED_PIN_MCU_MCU    (ALARM_OUT_A, 2, ALARM_IN_A, 5)

vhwUnit_t*  wired_8[] = { &mcu_6_port_5_pin_1 ,&pph_LED_1          ,nullptr };
vhwUnit_t*  wired_9[] = { &pph_3_LED_2        ,&mcu_6_port_2_pin_0 ,nullptr };

// #define LED_PORT    4
// #define LED_PIN     7
// DEF_MCU_PORT_PIN(LED)           // mcu_1_func_LED
// DEF_VHW_WIRED(LED)              // wired_LED

vhwUnit_t**  vhwUnitManagerTbl::vhwUnitPtrArray[]   = {
     wired_1
    ,wired_2
    ,wired_3
    ,wired_4
    ,wired_5
    ,wired_6
    ,wired_7
    ,wired_8
    ,wired_9
    ,pin_wired_LED_A
    ,pin_wired_LED_B_device_4
    ,pin_wired_ALARM_OUT_A_2__ALARM_IN_A_5
    ,nullptr
};



/*
vhwUnitTest1 test(1,2,3);
vhwPphButton pph_1_Btn_1(1,2);
vhwMcuPort mcu_1_Pin_2_3(1,2,3);
vhwUnitNull NULL_Unit();
//vhwUnitManager test_manager(1,2,test);
//vhwUnitWired test_manager(1,2,test);
//vhwUnitManager test_manager(1,2,&vhwUnitTest1(1,2,3));

vhwUnitManager  vhwUnitManagerPtrArray[] = {
    // nullptr
    //,&vhwUnitManager(1, 2, test)
    //,&vhwUnitManager{1, 2, test}
    //,&{1, 2, test}
    //,test_manager
    test_manager
    ,{1, 2, test}
    // ---------------------------
    ,{1, 2, pph_1_Btn_1}
    ,{1, 2, mcu_1_Pin_2_3}
    // ---------------------------
    ,{1, 3, pph_1_Led_1}
    ,{1, 3, mcu_1_Pin_1_4}
    // ---------------------------
    ,{0, 0, mcuPortInst_t::arrayUnit[vhwPortPin_1_4]}
    ,{0, 0, mcuPortInst_t::arrayUnit[vhwPortPin_1_4]}
    // ---------------------------
    ,{NULL_PORT, NULL_PIN, NULL_Unit}
    //,nullptr
};
*/
