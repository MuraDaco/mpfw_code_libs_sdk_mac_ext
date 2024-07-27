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
 * pphButton.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "mcuDeviceConfig.h"
#include "pphButton.h"


pphButton_t::pphButton_t(void) :
     mcuPinPort_t  ({0,    nullptr, 0, mcuPinPort_t::din})
    ,g_dtyStatus     {nullptr}
{}

pphButton_t::pphButton_t(uint8_t p_mcuId) :
     mcuPinPort_t  ({p_mcuId,    nullptr, 0, mcuPinPort_t::din})
    ,g_dtyStatus     {nullptr}
{}

pphButton_t::pphButton_t(gpio_config2_struct_t p_ConfPinPort   )  :
     mcuPinPort_t  ({                        p_ConfPinPort.ptrPort, p_ConfPinPort.pin, mcuPinPort_t::din})
    ,g_dtyStatus     {nullptr}
{}

pphButton_t::pphButton_t(gpio_config3_struct_t p_ConfPinPort   )  :
     mcuPinPort_t  ({p_ConfPinPort.mcuId,    p_ConfPinPort.ptrPort, p_ConfPinPort.pin, mcuPinPort_t::din})
    ,g_dtyStatus     {nullptr}
{}


void pphButton_t::vhwInit (uint8_t p_mcuId, uint8_t p_port,   uint8_t p_pin) {
    if(MCU_DEVICE_DEFAULT == g_mcuId) g_mcuId     = p_mcuId;
    g_port   = p_port;
    g_pin       = p_pin;
}


void pphButton_t::vhwLoop (void) {
    std::cout << "pphButton_t - loop function\n";
}