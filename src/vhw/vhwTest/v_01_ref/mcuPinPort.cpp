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
 * mcuPinPort.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "mcuDeviceConfig.h"
#include "shmMcuPinPort.h"
#include "mcuPinPort.h"


mcuPinPort_t::mcuPinPort_t(uint8_t p_mcuId, uint8_t  p_port,      uint8_t p_pin, const gpio_config_struct_t& p_config) :
     g_mcuId        {p_mcuId}
    ,g_port         {p_port}
    ,g_pin          {p_pin}
    ,g_config       {p_config}
    
{}

mcuPinPort_t::mcuPinPort_t(                 uint8_t* p_ptrPort, uint8_t p_Pin,  const gpio_config_struct_t& p_config) :
     g_mcuId        {MCU_DEVICE_DEFAULT}
    ,g_ptrPort      {p_ptrPort}
    ,g_pin          {p_Pin}
    ,g_config       {p_config}
{}

mcuPinPort_t::mcuPinPort_t(uint8_t p_mcuId, uint8_t* p_ptrPort, uint8_t p_Pin,  const gpio_config_struct_t& p_config) :
     g_mcuId        {p_mcuId}
    ,g_ptrPort      {p_ptrPort}
    ,g_pin          {p_Pin}
    ,g_config       {p_config}
{}

mcuPinPort_t::mcuPinPort_t(                 uint8_t* p_ptrPort, uint8_t p_Pin, void (*p_Func)(void),    const gpio_config_struct_t& p_config ) :
     g_mcuId        {MCU_DEVICE_DEFAULT}
    ,g_ptrPort      {p_ptrPort}
    ,g_pin          {p_Pin}
    ,g_Func         {p_Func}
    ,g_config       {p_config}
{}

mcuPinPort_t::mcuPinPort_t(uint8_t p_mcuId, uint8_t* p_ptrPort, uint8_t p_Pin, void (*p_Func)(void),    const gpio_config_struct_t& p_config ) :
     g_mcuId        {p_mcuId}
    ,g_ptrPort      {p_ptrPort}
    ,g_pin          {p_Pin}
    ,g_Func         {p_Func}
    ,g_config       {p_config}
{}


void mcuPinPort_t::vhwInit (void) {
    if(shmMcuPinPort_t::initStatus()) {
        g_ptrPort = shmMcuPinPort_t::getPtr(g_port);
    }
}

void mcuPinPort_t::vhwInit (uint8_t p_mcuId, uint8_t p_port,   uint8_t p_pin) {
    //if(MCU_DEVICE_DEFAULT == g_mcuId) g_mcuId     = p_mcuId;
    MCU_DEVICE_DEFAULT == g_mcuId ? g_mcuId = p_mcuId : false;
    g_port   = p_port;
    g_ptrPort = shmMcuPinPort_t::getPtr(p_port);
    g_pin    = p_pin;
}


void mcuPinPort_t::vhwLoop (void) {
    std::cout << "vhwUnitTest1 - loop function\n";
}

uint16_t mcuPinPort_t::pinRead   ([[maybe_unused]] uint8_t p_port,      [[maybe_unused]] uint8_t p_pin)    {
    return true;
}

void mcuPinPort_t::pinWrite  ([[maybe_unused]] uint8_t  p_Port,      [[maybe_unused]] uint8_t p_pin, [[maybe_unused]] uint16_t p_status) {
    
}

void mcuPinPort_t::pinConfig ([[maybe_unused]] uint8_t  p_Port,      [[maybe_unused]] uint8_t p_pin, gpio_config_struct_t& p_config)    {
    g_config.type = p_config.type;
    g_config.mode = p_config.mode;
}

void mcuPinPort_t::setHigh        (uint8_t p_mcuId)    {
    if(
        (
            (MCU_DEVICE_DEFAULT == g_mcuId) ||
            (p_mcuId            == g_mcuId)
        ) &&
        (k_modePort_output == g_config.mode)
    ) pinSet;
}

void mcuPinPort_t::setLow         (uint8_t p_mcuId)    {
    if(
        (
            (MCU_DEVICE_DEFAULT == g_mcuId) ||
            (p_mcuId            == g_mcuId)
        ) &&
        (k_modePort_output == g_config.mode)
    ) pinClr;
}

void mcuPinPort_t::vhwSetHigh        ([[maybe_unused]]uint8_t p_mcuId)    {
    if(k_modePort_input == g_config.mode) pinSet;
}

void mcuPinPort_t::vhwSetLow         ([[maybe_unused]]uint8_t p_mcuId)    {
    if(k_modePort_input == g_config.mode) pinClr;
}

bool mcuPinPort_t::getStatus      (void)    {
    return pinTst;
}

