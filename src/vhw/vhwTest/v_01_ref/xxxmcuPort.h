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
 * mcuPort.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef MCU_PORT_H
#define MCU_PORT_H

#include "vhwUnit.h"

#define DEF_MCU_PIN_PORT_PTR(name)                              mcuPort_t mcu_##name              (    &mcuPortDef_t::Port[MCU_##name##_PORT], MCU_##name##_PIN);
#define DEF_MCU_PORT_PIN(name)                                  mcuPort_t mcu_##name              (    MCU_##name##_PORT, MCU_##name##_PIN);
#define DEF_MCU_PORT_PIN_INTERRUPT(name, hndl)                  mcuPort_t mcu_##name              (    MCU_##name##_PORT, MCU_##name##_PIN, hndl);
#define DEF_MCU_PORT_PIN_DEVICE(name, id)                       mcuPort_t mcu_##id##_##name       (id, MCU_##name##_PORT, MCU_##name##_PIN);
#define DEF_MCU_PORT_PIN_INTERRUPT_DEVICE(name, hndl, id)       mcuPort_t mcu_##id##_##name       (id, MCU_##name##_PORT, MCU_##name##_PIN, hndl);

class mcuPort_t : public vhwUnit_t {

public:
    mcuPort_t(                 uint8_t* p_ptrPort,   uint8_t p_Pin);
    mcuPort_t(                 uint8_t  p_Port,      uint8_t p_Pin);
    mcuPort_t(                 uint8_t  p_Port,      uint8_t p_Pin, void (*p_func)(void) );
    mcuPort_t(uint8_t p_mcuId, uint8_t  p_Port,      uint8_t p_Pin);
    mcuPort_t(uint8_t p_mcuId, uint8_t  p_Port,      uint8_t p_Pin, void (*p_func)(void) );
//    mcuPort_t(uint8_t p_Port, uint8_t p_Pin);
//    mcuPort_t(uint8_t p_mcuId, uint8_t p_Port, uint8_t p_Pin);
//    mcuPort_t(uint8_t p_mcuId, uint8_t p_Port, uint8_t p_Pin, void (*p_func)(void) );
    uint8_t g_mcuId;
    uint8_t g_Port;
    uint8_t g_Pin;
    void (*g_Func)(void);
    void init (uint8_t*)    override;
    void loop (void)        override;
    uint8_t* g_ptrPort;

};


#endif 	// MCU_PORT_H
