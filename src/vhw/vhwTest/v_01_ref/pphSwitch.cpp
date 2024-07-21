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
 * pphSwitch.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "mcuDeviceConfig.h"
#include "pphSwitch.h"


pphSwitch_t::pphSwitch_t(void) :
     g_mcuId    {MCU_DEVICE_DEFAULT}
{}

pphSwitch_t::pphSwitch_t(uint8_t p_mcuId) :
     g_mcuId    {p_mcuId}
{}


void pphSwitch_t::vhwInit (uint8_t p_mcuId, uint8_t* p_ptrPort,   uint8_t p_pin) {
    if(MCU_DEVICE_DEFAULT == g_mcuId) g_mcuId     = p_mcuId;
    g_ptrPort   = p_ptrPort;
    g_pin       = p_pin;
}


void pphSwitch_t::vhwLoop (void) {
    std::cout << "pphButton_t - loop function\n";
}