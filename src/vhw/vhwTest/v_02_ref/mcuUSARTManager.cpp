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
 * mcuUSARTManager.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */



#include <iostream>


#include "mcuUSARTManager.h"
#include "mcuUSARTConfig.h"


shmMcuUSART_t::shared_mem_struct_t* mcuUSARTManager_t::g_ptrShm;

void mcuUSARTManager_t::init (void)        {
    //k_mcuUSART l_ch = k_mcuUSART_ch1;
    //g_ptrShm = shmMcuUSART_t::init(k_mcuUSART_ch1);
    //for(k_mcuUSART t_ch: k_mcuUSART_Num) {
    //    mcuUSARTTbl_t::unitArray2[t_ch].init(t_ch);
    //}

    for (uint8_t t_ch = k_mcuUSART_ch1; t_ch < k_mcuUSART_Num; t_ch++ )
    {
        k_mcuUSART l_ch =  static_cast<k_mcuUSART>(t_ch);        
        mcuUSARTTbl_t::unitArray2[t_ch].vhwInit(&l_ch);
    }    
}

void mcuUSARTManager_t::loop (void)               {

}

void mcuUSARTManager_t::channelSet ([[maybe_unused]] uint8_t p_channel)    {

}

