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
 * pphLed.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef PPH_LED_H
#define PPH_LED_H

#include "vhwUnit.h"
#include "mcuPinPort.h"

#define DEF_PPH_LED(name)             pphLed_t pph_##name(&mcu_##name);
#define DEF_PPH_LED_DEVICE(name, id)    pphLed_t pph_##id##_##name(id);

#define DEF_PPH_LED_2(name)                pphLed_t pph_##name;
//#define DEF_PPH_LED_DEVICE(name, id)     pphLed_t pph_##id##_##name(id);

#define DEF_H___PPH_LED(name)           MCU_##name  pphLed_t                 pph_##name;
#define DEF_CPP_PPH_LED(name)           MCU_##name  pphLed_t PPH_CLASS_DEF:: pph_##name;
#define OBJ_PPH_LED(name)                                    PPH_CLASS_DEF:: pph_##name


class pphLed_t : public vhwUnit_t {

public:
    pphLed_t(void);
    pphLed_t(                   mcuPinPort_t* p_pinPort);
    pphLed_t(uint8_t p_mcuId);
    pphLed_t(uint8_t p_mcuId,   mcuPinPort_t* p_pinPort);
    void vhwInit (uint8_t p_mcuId, uint8_t* p_ptrPort,   uint8_t p_pin)    override;
    void vhwLoop (void)        override;

    uint8_t g_mcuId;
    uint8_t g_pin;
    uint8_t* g_ptrPort;
    mcuPinPort_t* g_pinPort;
  
};


#endif 	// PPH_LED_H
