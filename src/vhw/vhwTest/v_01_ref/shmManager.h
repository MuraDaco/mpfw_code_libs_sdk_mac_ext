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
 * shmManager.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef SHM_MANAGER_H
#define SHM_MANAGER_H

#include <string>
#include <atomic>
#include <cstdint>

#define PROCESS_MAX_NUMBER	    4

class shmManager_t {

public:
    static bool init   (void);
    static bool checkProcessesList   (void);
    static void next   (void);
    static bool semaphore_init   (void);
    static bool semaphore   (void);

private:

    static void     add_2   (void);
    static bool     del_0   (void);
    static void     del_2   (void);

    typedef struct _process_struct
    {
        uint16_t pid;
        uint8_t  status;
    } process_struct_t;

    typedef struct _shared_mem_struct
    {
        int gNew;
        int gDel;
        int pid;
        int gActivePid;
        uint8_t gActiveProcessNum;
        uint8_t reader_counter;
    	process_struct_t process_buffer[PROCESS_MAX_NUMBER];
        std::atomic_flag gLockProcess;
        int gProcessWriterPid;
    } shared_mem_struct_t;

    static int g_shmFd;
    static shared_mem_struct_t* g_msg_ptr;
    static uint16_t g_pid;
    static uint16_t g_process_buff[];




};


#endif 	// SHM_MANAGER_H
