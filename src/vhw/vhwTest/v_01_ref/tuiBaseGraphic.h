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
#include "tuiBaseGraphicAbs.h"

class tuiBaseGraphic_t: public tuiBaseGraphicAbs_t  {

public:


    // element init procedure
    tuiBaseGraphic_t* g_pParent;
    void init   (void* p_pParent);
    void updParams          (void);
    void updCoordNboundX    (void);
    void updCoordNboundY    (void);
    void updCoordNboundS    (void);

    // element parameters
    //  - coords
    //      - relative
    int32_t g_x0r;  
    int32_t g_y0r;
    void setRelCoordX   (int32_t p_x);
    void incRelCoordX   (int32_t p_delta);
    void setRelCoordY   (int32_t p_y);
    void incRelCoordY   (int32_t p_delta);
    void setRelCoords   (int32_t p_x, int32_t p_y);
    //      - absolute respect parent window (N.B.: to set these coords you must use "updAbsCoord" functions)
    int32_t g_x0a;  
    int32_t g_y0a;
    //      - absolute respect root window (N.B.: to set these coords you must use "updAbsCoord" functions)
    //          - the mouse coords are given, by platform driver functions (i.e. ncurses library), respect root window
    int32_t g_mouseX0a;
    int32_t g_mouseY0a;

    //  - margins (N.B. these parameters are set by the class constructor)
    uint8_t g_marginXleft;
    uint8_t g_marginXright;
    uint8_t g_marginYtop;
    uint8_t g_marginYbottom;

    //  - dimensions
    uint16_t g_w; 
    uint16_t g_h;
    void setDimW        (uint8_t p_w);
    void updDimW        (void);
    void setDimH        (uint8_t p_h);
    void updDimH        (void);
    void setDims        (uint8_t p_w, uint8_t p_h);
    void updDims        (void);

    //  - bounds (N.B.: to set these bounds you must use "updBound" functions)
    uint16_t g_boundXleft;
    uint16_t g_boundXright;
    uint16_t g_boundYupper;
    uint16_t g_boundYlower;



    // - parent parameters
    //  - coords
    //      - horizontal coords
    int32_t     getDspBoxAbsRefX    (void);
    int32_t     getMouseAbsRefX     (void);
    void        updAbsCoordX        (void);
    //      - vertical coords
    int32_t     getDspBoxAbsRefY    (void);
    int32_t     getMouseAbsRefY     (void);
    void        updAbsCoordY        (void);
    //      - all coords
    void        updAbsCoords        (void);

    //  - dimensions
    uint16_t g_dspBoxW; 
    uint16_t g_dspBoxH;
    uint16_t    getDspBoxDimXw      (void);
    uint16_t    getDspBoxDimYh      (void);
    void        updDspBoxDims       (void);

    //  - bounds
    //      - horizontal coords
    int16_t     getBoundXleft       (void);
    int16_t     getBoundXright      (void);
    void        updBoundX           (void);
    //      - vertical coords
    int16_t     getBoundYupper      (void);
    int16_t     getBoundYlower      (void);
    void        updBoundY           (void);
    //      - all coords
    void        updBounds           (void);



    // old

    int16_t getRefX0            (void);
    int16_t getRootRefX0        (void);
    int16_t getDisplayMaxW      (void);
    int16_t getRefY0            (void);
    int16_t getRootRefY0        (void);
    int16_t getDisplayMaxH      (void);


    bool bMouseClickInsideBounds            (void);
    bool isSelected                         (void);
    bool isSelectedOrEventOn                (void);

    // int16_t g_h;
    // int16_t g_w;
    // int16_t g_y0r;      // it is used to determine the "g_y0Win" & "g_y0a" coordinates and it is defined because it is easier to manage by the programmer user
    // int16_t g_x0r;      // it is used to determine the "g_x0Win" & "g_x0a" coordinates and it is defined because it is easier to manage by the programmer user
    // int16_t g_y0a;      // the origin/referiment is the ncurses "main" window, that is "stdscr"; it is used in mouse management
    // int16_t g_x0a;      // the origin/referiment is the ncurses "main" window, that is "stdscr"; it is used in mouse management
    int16_t g_y0Win;    // the origin/referiment is the ncurses "secondary" windows, the windows that are created by "newwin" function; it is used in "print" functions
    int16_t g_x0Win;    // the origin/referiment is the ncurses "secondary" windows, the windows that are created by "newwin" function; it is used in "print" functions

    int16_t g_lvl1X0a;
    int16_t g_lvl1X0r;
    int16_t g_displayBoxW;
    int16_t g_lvl1Y0a;
    int16_t g_lvl1Y0r;
    int16_t g_displayBoxH;
    

    // init bound
    //int16_t g_boundUpper;
    //int16_t g_boundLower;

    tuiMode_t g_mode;

    void updateRelativeX    (uint8_t p_x0r);
    void updateRelativeY    (uint8_t p_y0r);

private:


    static uint8_t g_xMouse;
    static uint8_t g_yMouse;
    static uint8_t g_position;

};

#endif 	// TUI_BASE_GRAPHIC_H
