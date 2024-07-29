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
 * pphRely.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef PPH_RELY_H
#define PPH_RELY_H

#include "mcuPinPort2.h"
#include "pphMacroDefine.h"


class pphRely_t : public mcuPinPort2_t {

public:

    enum k_config_t   {
         k_config_NormalOpen    // rely input is low => rely output is high/open
        ,k_config_NormalClose   // rely input is low => rely output is low/close
    };

    pphRely_t(const char* p_strName, gpio_config3_struct_t p_ConfPinPortOut, gpio_config3_struct_t p_ConfPinPortIn);
    void vhwInit (void)    override;
    void vhwInit    (uint8_t p_mcuId,     uint8_t  p_port,   uint8_t p_pin, uint8_t p_pin2) override;
    void vhwLoop (void)    override;
    void vhwLoop (uint8_t p_mcuId)    override;
    void setHigh        (uint8_t p_mcuId) override;
    void setLow         (uint8_t p_mcuId) override;
    bool getStatus      (void);

    const char* g_strName;
    k_config_t  g_config;
  
};


#endif 	// PPH_RELY_H
