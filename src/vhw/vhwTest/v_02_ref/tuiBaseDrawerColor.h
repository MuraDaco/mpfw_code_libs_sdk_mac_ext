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
 * tuiBaseDrawerColor.h
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_DRAWER_COLOR_H
#define TUI_BASE_DRAWER_COLOR_H

#define NCURS_COLOR_PAIR_WINDOW_SELECT              COLOR_PAIR  (1)
#define NCURS_COLOR_PAIR_INIT_WINDOW_SELECT         init_pair   (1, COLOR_YELLOW,  COLOR_BLUE)

#define NCURS_COLOR_PAIR_WINDOW_DESELECT            COLOR_PAIR  (2)
#define NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT       init_pair   (2, COLOR_RED,     COLOR_BLACK)

#define NCURS_COLOR_PAIR_WINDOW_EVENT_ON            COLOR_PAIR  (3)
#define NCURS_COLOR_PAIR_INIT_WINDOW_EVENT_ON       init_pair   (3, COLOR_RED,   COLOR_YELLOW)

#define NCURS_COLOR_YELLOW                          4
#define NCURS_COLOR_PAIR_WINDOW_YELLOW              COLOR_PAIR  (4)
#define NCURS_COLOR_PAIR_INIT_WINDOW_YELLOW         init_pair   (4, COLOR_YELLOW,   COLOR_BLACK)

#define NCURS_COLOR_MAGENTA                         5
#define NCURS_COLOR_PAIR_WINDOW_MAGENTA             COLOR_PAIR  (5)
#define NCURS_COLOR_PAIR_INIT_WINDOW_MAGENTA        init_pair   (5, COLOR_MAGENTA,   COLOR_BLACK)

#define NCURS_COLOR_CYAN                            6
#define NCURS_COLOR_PAIR_WINDOW_CYAN                COLOR_PAIR  (6)
#define NCURS_COLOR_PAIR_INIT_WINDOW_CYAN           init_pair   (6, COLOR_CYAN,   COLOR_BLACK)

#define NCURS_COLOR_WHITE                           7
#define NCURS_COLOR_PAIR_WINDOW_WHITE               COLOR_PAIR  (7)
#define NCURS_COLOR_PAIR_INIT_WINDOW_WHITE          init_pair   (7, COLOR_WHITE,   COLOR_BLACK)

#endif 	// TUI_BASE_DRAWER_COLOR_H
