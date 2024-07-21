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
 * mcuUSARTTbl.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef MCU_USART_TBL_H
#define MCU_USART_TBL_H

#include "mcuUSART.h"
#include "vhwTbl.h"

class mcuUSARTTbl_t {

public:

    static mcuUSART_t  unitArray2[];
    static vhwTbl_t::manager_struct_t test3;
};


#endif 	// MCU_USART_TBL_H
