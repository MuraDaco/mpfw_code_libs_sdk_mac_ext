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

    // ---------------------  CONSTRUCTOR section - START
    protected:
    tuiGraphicCoord_t ();
    tuiGraphicCoord_t (box_t p_box  );
    tuiGraphicCoord_t (              margins_t p_margin);
    tuiGraphicCoord_t (box_t p_box  ,margins_t p_margin);
    // ---------------------  CONSTRUCTOR section - END

    // ---------------------  INTERFACE section - START
    public:
    virtual void updParamsAfterParentMod            (void);    
    // ---------------------  INTERFACE section - END

private:
    tuiGraphicCoord_t* g_pParent;

public:


    // element init procedure
    void setParent          (tuiGraphicCoord_t* p_pParent);
    tuiGraphicCoord_t* getParent            (void);

    void initCoordBase      (void);
    void initCoordWin       (void);
    void initCoordNdspBox   (void);
    void initBoundsBase     (void);
    void initBoundsWin      (void);
    void initBoundsWinRoot  (void);
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



    // - cursor management
    protected:
    static uint16_t g_position;
    static uint16_t g_xCursor;
    static uint16_t g_yCursor;

    // - mouse management

    public:
    bool bMouseClickInsideBounds    (void);
    static void updAbsMouseCoordX          (int16_t p_deltaY);
    static void updAbsMouseCoordY          (int16_t p_deltaY);

    protected:
    static uint16_t g_xMouse;
    static uint16_t g_yMouse;

    // functions called by container
    public:
    int32_t getDistanceFromBound                (void);
    int16_t getDisplayMaxH                      (void);
    bool    bVisibleCompletely                  (void);
    virtual void updCoordNboundsChilds          (void);
    virtual void updCoordNboundsForNewFather    (void);

};

#endif 	// TUI_GRAPHIC_COORD_H
