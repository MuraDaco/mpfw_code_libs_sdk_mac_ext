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
 * pphManager.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef PPH_MANAGER_H
#define PPH_MANAGER_H

#include <cstdint>
#include <ncurses.h>

class pphManager_t {

public:
    static void init                        (uint8_t p_mcuId);
    static void updateProcessesList         (void);
    static void processes_on_line	        (void);
    static void end                         (void);


    static void test_1  (uint8_t p_mcuId);
    static void test_2  (void);
    static void test_3  (void);
    static void test_4  (void);
    static void test_5  (void);

    static void print_in_middle     (WINDOW *win, int starty, int startx, int width, const char *string);
    static void print_menu          (WINDOW *menu_win, int highlight);
    static void report_choice       (int mouse_x, int mouse_y, int *p_choice);

    // *******
    static int startx;
    static int starty;
    static const char *choices[];
    static int n_choices;

    // *******

};


#endif 	// PPH_MANAGER_H
