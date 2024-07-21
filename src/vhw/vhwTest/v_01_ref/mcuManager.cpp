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
 * mcuManager.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include "mcuManager.h"
#include "shmManager.h"
#include "pphManager.h"
#include "mcuPinPortConfig.h"


void mcuManager_t::init (void) {
    // vhwUnit_t*** l_ptrPtrUnitArray = mcuPinPortConfig_t::UnitPtrArray;
    // uint8_t l_pinPort = 0;
    // uint8_t* l_testPort;
    // uint8_t l_testPin;


    // 1. initialize/create shared memory about process management
    if(shmManager_t::init())    {

        // 2. add the current process to the list of process that may read/write the shared mameory without conflicts
        while(!shmManager_t::semaphore_init()){}

        // 3. initialize/create the shared memory about mcuPinPort/mcuPinPortConfig
        while(!shmManager_t::semaphore()){}
    }


    //mcuManger::init();
    // while(l_ptrPtrUnitArray) {
    //     vhwUnit_t** l_ptrUnitArray = *l_ptrPtrUnitArray;
    //     if(l_pinPort == 0) {
    //         shmMcuPinPort* ;
    //     }
    //     while(l_ptrUnitArray)    {
    //         vhwUnit_t* l_ptrUnit = *l_ptrUnitArray;
    //         l_ptrUnit->init(l_testPin, l_testPort, l_pinPort);
    //         l_ptrUnitArray++;
    //     }
    //     l_pinPort < 7 ? l_pinPort++ : l_pinPort=0;
    //     l_ptrPtrUnitArray++;
    // }
    
}


void mcuManager_t::loop (void) {
    if(shmManager_t::semaphore())   {
        if(shmManager_t::checkProcessesList()) pphManager_t::updateProcessesList();

        shmManager_t::next();
    }
}