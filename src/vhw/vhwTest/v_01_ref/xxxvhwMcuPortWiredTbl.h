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
 * vhwMcuPortWiredTbl.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef VHW_MCU_PORT_WIRED_TBL_H
#define VHW_MCU_PORT_WIRED_TBL_H

#include <cstdint>
#include "vhwUnit.h"

#define DEVICE_WIRED_PIN(name)                                  vhwUnit_t*  pin_wired_##name[]                                              = { &mcu_##name             ,&pph_##name            ,nullptr };
#define DEVICE_WIRED_PIN_ID(name, id)                           vhwUnit_t*  pin_wired_##name##_device_##id[]                                = { &mcu_##id##_##name      ,&pph_##id##_##name     ,nullptr };
#define DEVICE_WIRED_PIN_MCU_MCU(name1, id1, name2, id2)        vhwUnit_t*  pin_wired_##name1##_device_##id1##__##name2##_device_##id2[]    = { &mcu_##id1##_##name1    ,&mcu_##id2##_##name2   ,nullptr };

class vhwMcuPortWiredTbl_t {

public:

	static vhwUnit_t**  vhwUnitPtrArray[];
    

};


#endif 	// VHW_MCU_PORT_WIRED_TBL_H
