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
 * mcuUSART.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau

    Description:
    - the code flow is the following:
        1) create an instance at compile time in tbl.cpp file
            1.1) no parameter are available
                1.1.1) the uniq parameter is "g_msg_ptr" the pointer to shared memory
                    - this parameter is set after that the shared memory is created
        2) start device
        3) init procedure
            3.1) vhwManager module execute the init procedure
                3.1.1) create shared memory 
                3.1.2) call init function of mcuUSART module


 */



#include <iostream>


#include "mcuUSART.h"

#define MCU_USART_STATUS__RX_NO_DATA    0xfff0

void mcuUSART_t::vhwInit (void* p_ptrCh) {
    // //g_shm = static_cast<shmMcuUSART_t*> (p_shm);
    g_ch = *(static_cast<k_mcuUSART*> (p_ptrCh));
}

void mcuUSART_t::chEnable       (void)  {
    shmMcuUSART_t::chEnable (g_ch);
}

void mcuUSART_t::vhwLoop (void) {
    std::cout << "mcuUSART_t - loop function\n";
}

bool mcuUSART_t::check_read_write(void)	{
	bool l_result = false;
	g_rx_data = MCU_USART_STATUS__RX_NO_DATA;

//    if(g_shmFd != -1) {
//
//		// waiting for acquire the token
//		if(
//			(g_pid == g_msg_ptr->gActivePid) &&
//			g_start
//		)	{
			// check data buffer status
			if(shmMcuUSART_t::writeProcedureRun())	{
				// write/read procedure is on
				if(shmMcuUSART_t::pidMatches())	{
					// the current process is the process that write/add data to packet buffer
					// all processes have read the data
					// therefore ...
					
					if(tx_fifo_full())	{
						// write data
						shmMcuUSART_t::setData(g_tx_data);
						// empty the fifo
						tx_fifo_empty_out();
					} else {
						// release the channel
					 	shmMcuUSART_t::WriterPidClr();
					}

				} else {
					// the current process is not the process that add data to packet buffer
					// therefore ...

					// check if there is a line conflict
					// the line conflict happen when the current process want to send data but 
					// another process has already locked the channel
					if(tx_fifo_full())	{
						// there is a data to send
						// therefore there is a line conflict
						l_result = true;

						// empty the fifo
						tx_fifo_empty_out();
					} else {
						// there is a data to read
						g_rx_data = shmMcuUSART_t::getData();
					}

				}
			} else {
				// the channel is free
				// check if there is a data to send
				if(tx_fifo_full())	{
					// there is a data to send

					// get/lock the channel
					shmMcuUSART_t::WriterPidSet();
					// write data
					shmMcuUSART_t::setData(g_tx_data);
					// empty the fifo
					tx_fifo_empty_out();
				}
			}
//		}
//	}

	return l_result;
}

bool mcuUSART_t::tx_fifo_full   (void)	{
	return (g_tx_data_new);
}

void mcuUSART_t::tx_fifo_empty_out   (void)	{
	g_tx_data_new = false;
}

void mcuUSART_t::tx_fifo_write  (char c)	{
	g_tx_data = c;
	g_tx_data_new = true;
}

uint16_t mcuUSART_t::rx_fifo_read  (void)	{
	return g_rx_data;
}


uint16_t mcuUSART_t::read(void)	{
	return g_rx_data;
}

