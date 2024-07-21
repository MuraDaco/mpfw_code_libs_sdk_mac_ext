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
 * vhwUnitTest1.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "vhwUnitTest1.h"


vhwUnitTest1::vhwUnitTest1(uint8_t p_mcuId, uint8_t p_Port, uint8_t p_Pin) :
     g_mcuId    {p_mcuId}
    ,g_Port     {p_Port}
    ,g_Pin      {p_Pin}
{}


void vhwUnitTest1::init (uint8_t* p_port) {
    g_port = p_port;
}


void vhwUnitTest1::loop (void) {
    std::cout << "vhwUnitTest1 - loop function\n";
}