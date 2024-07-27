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
 * pphWired.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef PPH_WIRED_H
#define PPH_WIRED_H

#include "mcuPinPort2.h"

//pphWired_t pphWiredTest1 ( "Test1", {2, &g_test, 4}, {5, &g_test, 4} ) ;

#define DEF_PPH_WIRED_NEW(name, id1, id2)           \
            pphWired_t pph_wired_##name##_##id1##_##id2                            (   \
                #name,  \
                {id1, MCU_##id1##_##name##_dout_PORT_PTR, MCU_##id1##_##name##_dout_PIN },  \
                {id2, MCU_##id2##_##name##_din_PORT_PTR,  MCU_##id2##_##name##_din_PIN  }   \
            );

#define DEF_PPH_WIRED(name)                                 pphWired_t pph_##name;
#define DEF_PPH_WIRED_DEVICE(name, id)                      pphWired_t pph_##id##_##name (id);
#define DEF_PPH_WIRED_IN(name)                              pphWired_t pph_##name        (&mcu_##name##_dout             ,nullptr);
#define DEF_PPH_WIRED_DEVICE_IN(name, id)                   pphWired_t pph_##id##_##name (&mcu_##name##_dout             ,nullptr);
#define DEF_PPH_WIRED_OUT(name)                             pphWired_t pph_##name        (nullpptr                       ,&mcu_##name##_din);
#define DEF_PPH_WIRED_DEVICE_OUT(name, id)                  pphWired_t pph_##id##_##name (nullpptr                       ,&mcu_##name##_din);
#define DEF_PPH_WIRED_IN_OUT(name, idout, idin)             pphWired_t pph_##name        (&mcu_##idout##_##name##_dout   ,&mcu_##idin##_##name##_din);
#define DEF_PPH_WIRED_IN_OUT_NAME(name, idout, idin)        pphWired_t pph_##name        (#name, &mcu_##idout##_##name##_dout   ,&mcu_##idin##_##name##_din);

class pphWired_t : public mcuPinPort2_t {

public:

    //static constexpr gpio_config_struct_t din       = {mcuPinPort_t::k_typePort_digital ,mcuPinPort_t::k_modePort_input  };

    pphWired_t(const char* p_strName, gpio_config3_struct_t p_ConfPinPortOut, gpio_config3_struct_t p_ConfPinPortIn);
    void vhwInit (void)    override;
    void vhwLoop (void)    override;
    void setHigh        (uint8_t p_mcuId);
    void setLow         (uint8_t p_mcuId);
    bool getStatus      (void);

    const char* g_strName;
  
};


#endif 	// PPH_WIRED_H
