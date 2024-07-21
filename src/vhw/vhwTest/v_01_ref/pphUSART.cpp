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
 * pphUSART.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>


#include "pphUSART.h"


pphUSART_t::pphUSART_t(void) :
     g_mcuId    {0xff}
{}

pphUSART_t::pphUSART_t(uint8_t p_mcuId) :
     g_mcuId    {p_mcuId}
{}


void pphUSART_t::vhwInit (uint8_t* p_port) {
    g_port = p_port;
}


void pphUSART_t::vhwLoop (void) {
    std::cout << "pphLed - loop function\n";
}


void sdk_usart::start(std::string p_param)	{

	// PROCESS MANAGEMENT
	bool l_test = sdk_process::add_0(p_param);

	// DISPLAY MANAGEMENT
	initscr();
	clear();
	noecho();
	cbreak();						// raw();	// Line buffering disabled. pass on everything. It does not need to press "enter" key to submit previous pressed key
	nodelay(stdscr, true);			// non-blocking input (getch) -> the same of timeout(0)
	keypad(stdscr, true);
	if(l_test) mvprintw(SDK_USART_SERVICE_MSG__HEADER, 	0, "--- || ___ Ctrl-a, Ctrl-b or Ctrl-c to exit ___ || ---\n");
	else mvprintw(SDK_USART_SERVICE_MSG__HEADER, 		0, "No process added\n");
	processes_on_line();
	move(SDK_USART_DISPLAY__START_CONSOLE,0);
	curs_set(0);
	refresh();

}

void sdk_usart::end_0(void)	{
	ch_0 = 'X';
}

void sdk_usart::end(void)	{

	// DISPLAY MANAGEMENT
	clrtoeol();
	refresh();
	endwin();

	// PROCESS MANAGEMENT
	sdk_process::del_0();

}


