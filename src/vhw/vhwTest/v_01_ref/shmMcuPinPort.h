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
 * shmMcuPinPort.h
 *
 *  Created on: Jul, 1st 2024
 *      Author: Marco Dau
 */


#ifndef SHM_MCU_PORT_H
#define SHM_MCU_PORT_H

#include <cstdint>
#include "mcuPortDef.h"

class shmMcuPinPort_t {

public:
    static void init            (void);
    static bool initStatus      (void);
    static uint8_t* getPtr      (uint8_t p_port);

private:
    typedef struct _shared_mem_struct
    {
        uint8_t portArray[SDK_MCU_PORT_NUM];
    } shared_mem_struct_t;

    static shared_mem_struct_t* g_ptrShm;
    static int g_shmFd;
};


#endif 	// SHM_MCU_PORT_H
