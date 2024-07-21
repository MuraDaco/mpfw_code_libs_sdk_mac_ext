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
 * vhwUnit.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef VHW_UNIT_TEST_H
#define VHW_UNIT_TEST_H

#include "vhwUnit.h"

class vhwUnitTest1 : public vhwUnit {

public:
    vhwUnitTest1(uint8_t p_mcuId, uint8_t p_Port, uint8_t p_Pin);
    uint8_t g_mcuId;
    uint8_t g_Port;
    uint8_t g_Pin;
    void init (uint8_t*)    override;
    void loop (void)        override;
    uint8_t* g_port;
  
};


#endif 	// VHW_UNIT_TEST_H
