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
 * tuiBaseGraphic.h
 *
 *  Created on: Oct, 8th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_GRAPHIC_H
#define TUI_BASE_GRAPHIC_H

#include "tuiGraphicTypes.h"

class tuiBaseGraphic_t   {

public:


    int16_t getRefX0            (void);
    int16_t getRootRefX0        (void);
    int16_t getDisplayMaxW      (void);
    int16_t getRefY0            (void);
    int16_t getRootRefY0        (void);
    int16_t getDisplayMaxH      (void);


    bool bMouseClickInsideBounds            (void);

    bool isSelected                         (void);
    bool isSelectedOrEventOn                (void);

    int16_t g_h;
    int16_t g_w;
    int16_t g_y0r;      // it is used to determine the "g_y0Win" & "g_y0a" coordinates and it is defined because it is easier to manage by the programmer user
    int16_t g_x0r;      // it is used to determine the "g_x0Win" & "g_x0a" coordinates and it is defined because it is easier to manage by the programmer user
    int16_t g_y0a;      // the origin/referiment is the ncurses "main" window, that is "stdscr"; it is used in mouse management
    int16_t g_x0a;      // the origin/referiment is the ncurses "main" window, that is "stdscr"; it is used in mouse management
    int16_t g_y0Win;    // the origin/referiment is the ncurses "secondary" windows, the windows that are created by "newwin" function; it is used in "print" functions
    int16_t g_x0Win;    // the origin/referiment is the ncurses "secondary" windows, the windows that are created by "newwin" function; it is used in "print" functions

    uint8_t g_marginTop;
    uint8_t g_marginBottom;
    uint8_t g_marginLeft;
    uint8_t g_marginRight;

    int16_t g_lvl1X0a;
    int16_t g_lvl1X0r;
    int16_t g_displayBoxW;
    int16_t g_lvl1Y0a;
    int16_t g_lvl1Y0r;
    int16_t g_displayBoxH;
    

    // init bound
    int16_t g_boundUpper;
    int16_t g_boundLower;

    tuiMode_t g_mode;

    void updateRelativeX    (uint8_t p_x0r);
    void updateRelativeY    (uint8_t p_y0r);

private:


    static uint8_t g_xMouse;
    static uint8_t g_yMouse;
    static uint8_t g_position;

};

#endif 	// TUI_BASE_GRAPHIC_H
