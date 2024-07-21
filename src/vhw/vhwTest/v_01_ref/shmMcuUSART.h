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
 * shmMcuUSART.h
 *
 *  Created on: Jul, 1st 2024
 *      Author: Marco Dau
 */


#ifndef SHM_MCU_USART_H
#define SHM_MCU_USART_H

#include <cstdint>

#include "mcuUSARTConfig.h"

#define MESSAGE_BUFFER_SIZE 1

class shmMcuUSART_t {


public:
    typedef struct _shared_mem_struct
    {
        char buffer[MESSAGE_BUFFER_SIZE];
        int gDataWriterPid;
    } shared_mem_struct_t;

    static void init                (void);
    static bool writeProcedureRun   (void);
    static bool pidMatches          (void);
    static uint8_t getData          (void);
    static void    setData          (uint8_t p_data);
	static void WriterPidClr        (void);
	static void WriterPidSet        (void);
    static void pidSet              (int16_t p_pid);
    static void chEnable            (k_mcuUSART p_ch);


private:
    static shared_mem_struct_t* g_ptrShmInit;
    static shared_mem_struct_t* g_ptrShmActive;
    static int g_shmFd;
    static int16_t g_pid;

};


#endif 	// SHM_MCU_UASRT_H
