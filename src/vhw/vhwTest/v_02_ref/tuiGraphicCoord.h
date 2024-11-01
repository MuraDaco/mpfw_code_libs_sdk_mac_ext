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
 * tuiGraphicCoord.h
 *
 *  Created on: Oct, 18th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_COORD_H
#define TUI_GRAPHIC_COORD_H

#include "tuiGraphicTypes.h"
#include "uyTypesDefs.h"

class tuiGraphicCoord_t  {

public:

    tuiGraphicCoord_t ();
    tuiGraphicCoord_t (box_t p_box  );
    tuiGraphicCoord_t (              margins_t p_margin);
    tuiGraphicCoord_t (box_t p_box  ,margins_t p_margin);

private:
    tuiGraphicCoord_t* g_pParent;

public:
    // old use / to remove

    void    old_updAbsMouseCoordY      (int16_t p_deltaY);
    int16_t old_getRefX0               (void);
    int16_t old_getRootRefX0           (void);
    int16_t old_getDisplayMaxW         (void);
    int16_t old_getRefY0               (void);
    int16_t old_getRootRefY0           (void);
    int16_t old_getDisplayMaxH         (void);
    int16_t old_getBoundYupper         (void);
    int16_t old_getBoundYlower         (void);


    void old_updCoordNboundS        (void);
    void old_updDspBoxDimX          (void);
    void old_updDspBoxDimY          (void);
    void old_updDspBoxDimS          (void);

    void old_init               (void* p_poFather);
    void old_setParent          (void* p_poFather);
    void old_updateRelativeY    (uint8_t p_y0r);

    void old_updParams          (void);
    void old_updCoordNboundX        (void);
    void old_updCoordNboundY        (void);

    void old_updAbsParams                       (void);
    void old_updRelCoordY                       (int16_t p_delta);
    void old_updCoordNbounds                    (int16_t p_delta);
    void old_updCoordNboundsForNewFather        (void);

    int32_t g_lvl1X0r, g_lvl1Y0r, g_lvl1X0a, g_lvl1Y0a, g_x0Win, g_y0Win;
    uint16_t g_displayBoxW, g_displayBoxH;
    uint8_t g_marginLeft;
    uint8_t g_marginRight;
    uint8_t g_marginTop;
    uint8_t g_marginBottom;
    uint16_t g_boundLeft;
    uint16_t g_boundRight;
    uint16_t g_boundUpper;
    uint16_t g_boundLower;


    // to be add
    int32_t getDistanceFromUpperBound   (void);
    int32_t getDistanceFromLowerBound   (void);
    int32_t getDistanceFromBound        (void);
    bool bVisibleCompletely             (void);
    void updCoordNboundsAfterParentMod  (void);
    virtual void updCoordNboundsChilds  (void);

    // element init procedure
    void initCoord          (void);
    void setParent          (tuiGraphicCoord_t* p_pParent);
    tuiGraphicCoord_t* getParent            (void);
    void updParams          (void);
    void updCoordNboundX    (void);
    void updCoordNboundY    (void);
    void updCoordNboundS    (void);

    // element parameters
    //  - coords
    //      - relative
    int32_t g_x0r;  
    int32_t g_y0r;
    void initRelCoordX      (int32_t p_x);
    void setRelCoordX       (int32_t p_x);
    void incRelCoordX       (int32_t p_delta);
    void setRelCoordY       (int32_t p_y);
    void incRelCoordY       (int32_t p_delta);
    void initRelCoordY      (int32_t p_y);
    void initRelCoordS      (int32_t p_x, int32_t p_y);
    void setRelCoords       (int32_t p_x, int32_t p_y);

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
    void setDimW        (uint16_t p_w);
    void updDimW        (void);
    uint16_t getDimW    (void);

    void setDimH        (uint16_t p_h);
    void updDimH        (void);
    uint16_t getDimH    (void);

    void setDims        (uint16_t p_w, uint16_t p_h);
    void updDims        (void);

    //  - bounds (N.B.: to set these bounds you must use "updBound" functions)
    uint16_t g_boundXleft;
    uint16_t g_boundXright;
    uint16_t g_boundYupper;
    uint16_t g_boundYlower;


    // element

    // - parent parameters
    //  - coords
    //      - horizontal coords
    int32_t     getDspBoxAbsRefX    (void) ;
    int32_t     getMouseAbsRefX     (void) ;
    void        updAbsCoordX        (void) ;
    //      - vertical coords
    int32_t     getDspBoxAbsRefY    (void) ;
    int32_t     getMouseAbsRefY     (void) ;
    void        updAbsCoordY        (void) ;
    //      - all coords
    void        updAbsCoords        (void) ;

    // - display box dimensions
    uint16_t g_dspBoxW; 
    uint16_t g_dspBoxH;
    uint16_t    getDspBoxDimXw      (void) ;
    uint16_t    getDspBoxDimYh      (void) ;
    void        updDspBoxDims       (void) ;

    //  - bounds
    //      - horizontal coords
    int32_t     getBoundXleft       (void) ;
    int32_t     getBoundXright      (void) ;
    void        updBoundX           (void) ;
    //      - vertical coords
    int32_t     getBoundYupper      (void) ;
    int32_t     getBoundYlower      (void) ;
    void        updBoundY           (void) ;
    //      - all coords
    void        updBounds           (void) ;


    bool bMouseClickInsideBounds    (void);

protected:
    static uint16_t g_position;

    static uint16_t g_xMouse;
    static uint16_t g_yMouse;
    static uint16_t g_xCursor;
    static uint16_t g_yCursor;

};

#endif 	// TUI_GRAPHIC_COORD_H
