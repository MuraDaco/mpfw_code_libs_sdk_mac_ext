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

#include "vhwUnit.h"
#include "mcuPinPort.h"

#define DEF_PPH_RELY(name)                          pphRely_t pph_##name;
#define DEF_PPH_RELY_DEVICE(name, id)               pphRely_t pph_##id##_##name (id);
#define DEF_PPH_RELY_IN(name)                       pphRely_t pph_##name        (&mcu_##name##_dout             ,nullptr);
#define DEF_PPH_RELY_DEVICE_IN(name, id)            pphRely_t pph_##id##_##name (&mcu_##name##_dout             ,nullptr);
#define DEF_PPH_RELY_OUT(name)                      pphRely_t pph_##name        (nullpptr                       ,&mcu_##name##_din);
#define DEF_PPH_RELY_DEVICE_OUT(name, id)           pphRely_t pph_##id##_##name (nullpptr                       ,&mcu_##name##_din);
#define DEF_PPH_RELY_IN_OUT(name, idout, idin)      pphRely_t pph_##name        (&mcu_##idout##_##name##_dout   ,&mcu_##idin##_##name##_din);
#define DEF_PPH_RELY_IN_OUT_NAME(name, idout, idin)      pphRely_t pph_##name        (#name, &mcu_##idout##_##name##_dout   ,&mcu_##idin##_##name##_din);

class pphRely_t : public vhwUnit_t {

public:

    enum k_config_t   {
         k_config_NormalOpen    // rely input is low => rely output is high/open
        ,k_config_NormalClose   // rely input is low => rely output is low/close
    };

    //static constexpr gpio_config_struct_t din       = {mcuPinPort_t::k_typePort_digital ,mcuPinPort_t::k_modePort_input  };

    pphRely_t();
    pphRely_t(uint8_t p_mcuId);
    pphRely_t(mcuPinPort_t* p_pinPortOut, mcuPinPort_t* p_pinPortIn);
    pphRely_t(const char* p_strName, mcuPinPort_t* p_pinPortOut, mcuPinPort_t* p_pinPortIn);
    void vhwInit (void)    override;
    void vhwLoop (uint8_t p_mcuId)    override;
    void setHigh        (uint8_t p_mcuId);
    void setLow         (uint8_t p_mcuId);
    bool getStatus      (void);

    uint8_t  g_mcuId;
    const char* g_strName;
    mcuPinPort_t* g_pinPortOut;
    mcuPinPort_t* g_pinPortIn;
    k_config_t  g_config;
  
};


#endif 	// PPH_RELY_H
