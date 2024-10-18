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
 * mcuUSART.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef MCU_USART_H
#define MCU_USART_H

#include "vhwUnit.h"
#include "shmMcuUSART.h"
#include "mcuUSARTConfig.h"

class mcuUSART_t : public vhwUnit_t {

public:
    void vhwInit (void* p_ptrCh)     override;
    void vhwLoop (void)            override;

    bool tx_fifo_full           (void);
    void tx_fifo_empty_out      (void);
    void tx_fifo_write          (char c);
    uint16_t rx_fifo_read       (void);
    bool rx_fifo_full           (void);
    bool check_read_write       (void);
    uint16_t read               (void);
    void chEnable               (void);

private:

    k_mcuUSART      g_ch;
    bool            g_tx_data_new;
    uint16_t        g_tx_data;
    uint16_t        g_rx_data;

};


#endif 	// MCU_USART_H
