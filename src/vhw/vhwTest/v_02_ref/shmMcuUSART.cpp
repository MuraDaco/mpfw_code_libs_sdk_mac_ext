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
 * shmMcuUSART.cpp
 *
 *  Created on: Jul, 1st 2024
 *      Author: Marco Dau
 */

#include "shmMcuUSART.h"


#include <cstdint>
#include <string>
#include <atomic>
#include <iostream>

#include <unistd.h>             // for getpid(), ftruncate()

#include <sys/mman.h>           // for shared memory created
#include <fcntl.h>              // for O_* constant: S_IRUSR, S_IWUSR



#define SHARED_MCU_USART_OBJ_NAME         		"/shmMcuUSART"		// "/mpfw_sdk_process"

int     shmMcuUSART_t::g_shmFd;
int16_t shmMcuUSART_t::g_pid;
shmMcuUSART_t::shared_mem_struct_t* shmMcuUSART_t::g_ptrShmInit;
shmMcuUSART_t::shared_mem_struct_t* shmMcuUSART_t::g_ptrShmActive;

void shmMcuUSART_t::init    (void)  {


    g_shmFd = shm_open(SHARED_MCU_USART_OBJ_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if(g_shmFd == -1) {
        printf("ERROR - opening shared memory\n");
    } else {
        ftruncate(g_shmFd, MCU_USART_CHANNEL_NUM*sizeof(shared_mem_struct_t));
        g_ptrShmInit = (shared_mem_struct_t *) mmap(NULL, MCU_USART_CHANNEL_NUM*sizeof(shared_mem_struct_t), PROT_READ | PROT_WRITE, MAP_SHARED, g_shmFd, 0);
    }

}

void shmMcuUSART_t::chEnable       (k_mcuUSART p_ch)     {
    g_ptrShmActive = &g_ptrShmInit[p_ch];
}


bool shmMcuUSART_t::writeProcedureRun (void)    {
    return (g_ptrShmActive->gDataWriterPid);
}

bool shmMcuUSART_t::pidMatches (void)   {
    return (g_pid == g_ptrShmActive->gDataWriterPid);
}

uint8_t shmMcuUSART_t::getData         (void)  {
    return  g_ptrShmActive->buffer[0];
}

void    shmMcuUSART_t::setData         (uint8_t p_data)    {
    g_ptrShmActive->buffer[0] = p_data;
}


void shmMcuUSART_t::WriterPidClr       (void)  {
    g_ptrShmActive->gDataWriterPid = 0;
}

void shmMcuUSART_t::WriterPidSet       (void)  {
    g_ptrShmActive->gDataWriterPid = g_pid;
}

void shmMcuUSART_t::pidSet       (int16_t p_pid)  {
    g_pid = p_pid;
}