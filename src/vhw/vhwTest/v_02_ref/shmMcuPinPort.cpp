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
 * shmMcuPinPort.cpp
 *
 *  Created on: Jul, 1st 2024
 *      Author: Marco Dau
 */

#include "shmMcuPinPort.h"

#include <cstdint>
#include <string>
#include <atomic>
#include <iostream>

#include <unistd.h>             // for getpid()

#include <sys/mman.h>           // for shared memory created
#include <fcntl.h>              // for O_* constant: S_IRUSR, S_IWUSR

#define SHARED_MCU_PORT_OBJ_NAME         		"/shmMcuPort"		// "/mpfw_sdk_process"

int     shmMcuPinPort_t::g_shmFd = -1;
shmMcuPinPort_t::shared_mem_struct_t* shmMcuPinPort_t::g_ptrShm = nullptr;

void shmMcuPinPort_t::init    (void)  {


    g_shmFd = shm_open(SHARED_MCU_PORT_OBJ_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if(g_shmFd == -1) {
        printf("ERROR - opening shared memory\n");
    } else {
        ftruncate(g_shmFd, sizeof(shared_mem_struct_t));
        g_ptrShm = (shared_mem_struct_t *) mmap(NULL, sizeof(shared_mem_struct_t), PROT_READ | PROT_WRITE, MAP_SHARED, g_shmFd, 0);
    }

}

uint8_t* shmMcuPinPort_t::getPtr(uint8_t p_port)  {
    return g_ptrShm ? &g_ptrShm->portArray[p_port] : nullptr;
}

bool shmMcuPinPort_t::initStatus(void)  {
    return (g_shmFd != -1);
}
