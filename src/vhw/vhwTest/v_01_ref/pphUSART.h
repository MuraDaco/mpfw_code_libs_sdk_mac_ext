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
 * pphUSART.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef PPH_USART_H
#define PPH_USART_H

#include "vhwUnitGen.h"


//#define DEF_PPH_LED(name)            pphLed_t pph_##name;
//#define DEF_PPH_LED_DEVICE(name, id) pphLed_t pph_##id##_##name(id);

class pphUSART_t : public vhwUnitGen_t {

public:
    pphUSART_t(void);
    pphUSART_t(uint8_t p_mcuId);
    uint8_t g_mcuId;
    void vhwInit (uint8_t*)    override;
    void vhwLoop (void)        override;
    uint8_t* g_port;

void     start                    (std::string p_param)
bool     loop                     (void)
void     end_0                    (void)
void     end                      (void)
bool     check_loop_end           (void)
void     rx_stop                  (void)


};


#endif 	// PPH_USART_H
