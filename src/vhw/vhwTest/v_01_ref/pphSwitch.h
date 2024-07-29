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
 * pphSwitch.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef PPH_SWITCH_H
#define PPH_SWITCH_H

#include "pphMacroDefine.h"
#include "mcuPinPort.h"

class pphSwitch_t : public mcuPinPort_t {

public:
    pphSwitch_t();
    pphSwitch_t(uint8_t p_mcuId);
    pphSwitch_t(gpio_config2_struct_t p_ConfPinPort  );
    pphSwitch_t(gpio_config3_struct_t p_ConfPinPort  );
    void vhwInit (uint8_t p_mcuId, uint8_t p_port,   uint8_t p_pin)    override;
    void vhwLoop (void)        override;
  
};


#endif 	// PPH_SWITCH_H
