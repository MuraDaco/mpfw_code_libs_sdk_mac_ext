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
 * vhwPphTbl_Mod1.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#include <iostream>
#include "vhwPphTbl_Mod1.h"

// uint8_t g_test;
// mcuPinPort2_t mcuPP2Test ({1,&g_test,3,mcuPinPort_t::din});
// mcuPinPort_t::gpio_base_struct_t g_portConf =  {1,&g_test,3,mcuPinPort_t::din};
// mcuPinPort2_t mcuPP2Test2 ( {1,&g_test,3,mcuPinPort_t::din} ) ;
// mcuPinPort2_t mcuPP2Test3 ( g_portConf ) ;
// 
// DEF_MCU_PIN_PORT2_DEVICE_CONFIG (ALARM_A, 5, din, 2, dout)
// 
// pphWired_t pphWiredTest1 ( "Test1", {2, &g_test, 4}, {5, &g_test, 4} ) ;
// 
// //DEF_PPH_WIRED_NEW(ALARM_A, 2, 5)
// 
// void pippo  (void)  {
//     std::cout << "pippo - interrupt function\n";
// }


PPH_DEF_CPP         (pphSwitch_t ,SWITCH_XOR           )
PPH_DEF_CPP         (pphSwitch_t ,SWITCH_NOR           )

PPH_DEF_CPP         (pphSwitch_t ,SWITCH_AND           )
PPH_DEF_CPP         (pphSwitch_t ,SWITCH_NOT           )


PPH_DEF_CPP_LINK    (pphRely_t   ,ALARM_A     ,2 ,5     )
PPH_DEF_CPP         (pphSwitch_t ,SWITCH_TST1           )
PPH_DEF_CPP_LINK    (pphWired_t  ,LINK_A      ,3 ,1     )

PPH_DEF_CPP_LINK    (pphRely_t   ,ALARM_NNN   ,2 ,5     )
PPH_DEF_CPP         (pphSwitch_t ,SWITCH_GGG            )
PPH_DEF_CPP_LINK    (pphWired_t  ,LINK_TTT    ,3 ,1     )
