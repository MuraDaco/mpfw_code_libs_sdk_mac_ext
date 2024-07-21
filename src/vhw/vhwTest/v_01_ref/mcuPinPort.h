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
 * mcuPinPort.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef MCU_PIN_PORT_H
#define MCU_PIN_PORT_H

#include "vhwUnit.h"
#include "mcuPortDef.h"

#define DEF_MCU_PIN_PORT_DEVICE_CONFIG(name, id, config)                mcuPinPort_t mcu_##id##_##name       (id, MCU_##name##_PORT,        MCU_##name##_PIN,       mcuPinPort_t::config);
#define DEF_MCU_PIN_PORT_PTR(name, config)                              mcuPinPort_t mcu_##name              (    MCU_##name##_PORT_PTR,    MCU_##name##_PIN,       mcuPinPort_t::config);
#define DEF_MCU_PIN_PORT(name, config)                                  mcuPinPort_t mcu_##name              (    MCU_##name##_PORT_PTR,    MCU_##name##_PIN,       mcuPinPort_t::config);
#define DEF_MCU_PIN_PORT_INTERRUPT(name, hndl, config)                  mcuPinPort_t mcu_##name              (    MCU_##name##_PORT_PTR,    MCU_##name##_PIN, hndl, mcuPinPort_t::config);
#define DEF_MCU_PIN_PORT_DEVICE(name, id, config)                       mcuPinPort_t mcu_##id##_##name##_##config       (id, MCU_##id##_##name##_##config##_PORT_PTR,    MCU_##id##_##name##_##config##_PIN,       mcuPinPort_t::config);
#define DEF_MCU_PIN_PORT_INTERRUPT_DEVICE(name, hndl, id, config)       mcuPinPort_t mcu_##id##_##name       (id, MCU_##name##_PORT_PTR,    MCU_##name##_PIN, hndl, mcuPinPort_t::config);

#define pinSet          *g_ptrPort = *g_ptrPort | (1 << g_pin)
#define pinClr          *g_ptrPort = *g_ptrPort & ~(1 << g_pin)
#define pinTst          *g_ptrPort & (1 << g_pin)

class mcuPinPort_t : public vhwUnit_t {


public:

    enum k_typePort_t   {
         k_typePort_digital
        ,k_typePort_analog
        ,k_typePort_usart
        ,k_typePort_spi
        ,k_typePort_i2c
    };

    enum k_modePort_t   {
         k_modePort_input
        ,k_modePort_output
        ,k_modePort_data
        ,k_modePort_clck
    };

    typedef struct gpio_config_struct
    {
        k_typePort_t type;
        k_modePort_t mode;
    } gpio_config_struct_t;

    static constexpr gpio_config_struct_t din       = {mcuPinPort_t::k_typePort_digital ,mcuPinPort_t::k_modePort_input  };
    static constexpr gpio_config_struct_t dout      = {mcuPinPort_t::k_typePort_digital ,mcuPinPort_t::k_modePort_output };
    static constexpr gpio_config_struct_t ain       = {mcuPinPort_t::k_typePort_analog  ,mcuPinPort_t::k_modePort_input  };
    static constexpr gpio_config_struct_t aout      = {mcuPinPort_t::k_typePort_analog  ,mcuPinPort_t::k_modePort_output };

    static constexpr gpio_config_struct_t usart_rx  = {mcuPinPort_t::k_typePort_usart   ,mcuPinPort_t::k_modePort_input  };
    static constexpr gpio_config_struct_t usart_tx  = {mcuPinPort_t::k_typePort_usart   ,mcuPinPort_t::k_modePort_output };

    static constexpr gpio_config_struct_t spi_data  = {mcuPinPort_t::k_typePort_spi     ,mcuPinPort_t::k_modePort_data };
    static constexpr gpio_config_struct_t spi_clck  = {mcuPinPort_t::k_typePort_spi     ,mcuPinPort_t::k_modePort_clck };

    static constexpr gpio_config_struct_t i2c_data  = {mcuPinPort_t::k_typePort_i2c     ,mcuPinPort_t::k_modePort_data };
    static constexpr gpio_config_struct_t i2c_clck  = {mcuPinPort_t::k_typePort_i2c     ,mcuPinPort_t::k_modePort_clck };

    mcuPinPort_t(uint8_t p_mcuId,   uint8_t  p_port,      uint8_t p_pin, const gpio_config_struct_t& p_config);

    mcuPinPort_t(                   uint8_t* p_ptrPort,   uint8_t p_pin,                        const gpio_config_struct_t& p_config);
    mcuPinPort_t(uint8_t p_mcuId,   uint8_t* p_ptrPort,   uint8_t p_pin,                        const gpio_config_struct_t& p_config);
    mcuPinPort_t(                   uint8_t* p_ptrPort,   uint8_t p_pin, void (*p_func)(void),  const gpio_config_struct_t& p_config );
    mcuPinPort_t(uint8_t p_mcuId,   uint8_t* p_ptrPort,   uint8_t p_pin, void (*p_func)(void),  const gpio_config_struct_t& p_config );
    void vhwInit (uint8_t p_mcuId,     uint8_t  p_Port,   uint8_t p_pin)    override;
    void vhwInit (void)    override;
    void vhwLoop (void)        override;

    // 
    uint8_t  g_mcuId;
    uint8_t* g_ptrPort;
    uint8_t  g_port;
    uint8_t  g_pin;
    void (*g_Func)(void);
    gpio_config_struct_t g_config;

    uint16_t pinRead    (uint8_t  p_port,      uint8_t p_pin);
    void pinWrite       (uint8_t  p_Port,      uint8_t p_pin, uint16_t p_status);
    void pinConfig      (uint8_t  p_Port,      uint8_t p_pin, gpio_config_struct_t& p_config);
    void setHigh        (uint8_t p_mcuId);
    void setLow         (uint8_t p_mcuId);
    void vhwSetHigh     (uint8_t p_mcuId);
    void vhwSetLow      (uint8_t p_mcuId);
    bool getStatus      (void);

};


#endif 	// MCU_PIN_PORT_H
