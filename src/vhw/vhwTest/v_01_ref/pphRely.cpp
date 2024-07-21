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
 * pphRely.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "mcuDeviceConfig.h"
#include "pphRely.h"


pphRely_t::pphRely_t(void) :
     g_mcuId    {MCU_DEVICE_DEFAULT}
{}

pphRely_t::pphRely_t(uint8_t p_mcuId) :
     g_mcuId    {p_mcuId}
{}

pphRely_t::pphRely_t(mcuPinPort_t* p_pinPortOut, mcuPinPort_t* p_pinPortIn) :
     g_pinPortOut     {p_pinPortOut }
    ,g_pinPortIn      {p_pinPortIn  }
{}

pphRely_t::pphRely_t(const char* p_strName, mcuPinPort_t* p_pinPortOut, mcuPinPort_t* p_pinPortIn)  :
     g_strName        {p_strName    }
    ,g_pinPortOut     {p_pinPortOut }
    ,g_pinPortIn      {p_pinPortIn  }
{}


void pphRely_t::vhwInit (void) {

    // inizializzazione 
    g_pinPortIn->vhwInit();

    /*
        inizializzazione della dashboard per la categoria degli oggetti pphRely
    */

}


void pphRely_t::vhwLoop (uint8_t p_mcuId) {
    std::cout << "pphRely_t - loop function\n";

    // 1. processo che analizza l'ingresso della dashboard per sapere se deve cambiare lo stato del oggetto
    // start dashboard read
        // ... after reading,
        // 1.1. set pinPort input to high
        if((nullptr == g_pinPortOut) && (g_pinPortIn)) g_pinPortIn->vhwSetHigh(p_mcuId);

        // ... after reading,
        // 1.1. set pinPort input to low
        if((nullptr == g_pinPortOut) && (g_pinPortIn)) g_pinPortIn->vhwSetLow(p_mcuId);

    // 2. processo che analizza l'input del relay per sapere se aggiornare l' stato di output del rely
    //    questo controllo deve essere eseguito solo se entrambe i puntatori non sono nulli
    if((g_pinPortOut) && (g_pinPortIn)) {
    // check config
        if(k_config_NormalOpen == g_config) {
            // rely is configured as NORMAL OPEN
            if(g_pinPortOut->getStatus())   {
                // mcuPinPort out (that is rely input) is high, therefore
                // set rely out (that is mcuPinPort in) close
                g_pinPortIn->vhwSetLow(p_mcuId);
            } else {
                // mcuPinPort out (that is rely input) is low, therefore
                // set rely out (that is mcuPinPort in) open
                g_pinPortIn->vhwSetHigh(p_mcuId);
            }
        } else {
            // rely is configured as NORMAL CLOSE
            if(g_pinPortOut->getStatus())   {
                // mcuPinPort out (that is rely input) is high, therefore
                // set rely out (that is mcuPinPort in) open
                g_pinPortIn->vhwSetHigh(p_mcuId);
            } else {
                // mcuPinPort out (that is rely input) is low, therefore
                // set rely out (that is mcuPinPort in) close
                g_pinPortIn->vhwSetLow(p_mcuId);
            }
        }
    }

    // 3. processo che analizza lo stato del oggetto per poi aggiornarlo sulla dashboard

}


void pphRely_t::setHigh (uint8_t p_mcuId) {
    if(nullptr == g_pinPortOut) g_pinPortOut->setHigh(p_mcuId);
}

void pphRely_t::setLow (uint8_t p_mcuId) {
    if(nullptr == g_pinPortOut) g_pinPortOut->setLow(p_mcuId);
}

bool pphRely_t::getStatus (void) {
    return g_pinPortIn->getStatus();
}


