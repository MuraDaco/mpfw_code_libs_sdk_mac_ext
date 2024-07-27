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
 * pphWired.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "mcuDeviceConfig.h"
#include "pphWired.h"


pphWired_t::pphWired_t(const char* p_strName, gpio_config3_struct_t p_ConfPinPortOut, gpio_config3_struct_t p_ConfPinPortIn)  :
     mcuPinPort2_t  (
                        {p_ConfPinPortOut.mcuId,    p_ConfPinPortOut.ptrPort, p_ConfPinPortOut.pin, mcuPinPort_t::dout},
                        {p_ConfPinPortIn.mcuId,     p_ConfPinPortIn.ptrPort , p_ConfPinPortIn.pin , mcuPinPort_t::din}
     )
    ,g_strName          {p_strName    }
{}


void pphWired_t::vhwInit (void) {
}


void pphWired_t::vhwLoop () {
}

void pphWired_t::setHigh ([[maybe_unused]] uint8_t p_mcuId) {
}

void pphWired_t::setLow ([[maybe_unused]] uint8_t p_mcuId) {
}

bool pphWired_t::getStatus (void) {
    return true;
}


