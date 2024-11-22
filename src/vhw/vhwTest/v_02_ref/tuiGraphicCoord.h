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

// ****************************************************
// section start **** CONSTRUCTOR *****
    protected:
    tuiGraphicCoord_t ();
    tuiGraphicCoord_t (box_t p_box  );
    tuiGraphicCoord_t (              margins_t p_margin);
    tuiGraphicCoord_t (box_t p_box  ,margins_t p_margin);
    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INIT *****

    public:
    void initCoordBase      (void);
    void initCoordWin       (void);
    void initCoordNdspBox   (void);
    void initBoundsBase     (void);
    void initBoundsWin      (void);
    void initBoundsWinRoot  (void);

    void                setParent   (tuiGraphicCoord_t* p_pParent);
    tuiGraphicCoord_t*  getParent   (void);

    private:
    tuiGraphicCoord_t* g_pParent;

    // section end   **** INIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** AVAILABLE DISPLAY/MOUSE AREA *****

    // - parent available display area dimensions
    public:
    int32_t     getDspAreaAbsRefX       (void);
    int32_t     getDspAreaAbsRefY       (void);
    int32_t     getMouseAreaAbsRefX     (void);
    int32_t     getMouseAreaAbsRefY     (void);
    uint16_t    getDspAreaDimXw         (void);
    uint16_t    getDspAreaDimYh         (void);
    void        updDspAreaDims          (void);

    protected:
    uint16_t g_dspAreaW; 
    uint16_t g_dspAreaH;
    // section end   **** AVAILABLE DISPLAY/MOUSE AREA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PARAMETERS *****

    void updParams          (void);
    void updCoordNboundX    (void);
    void updCoordNboundY    (void);
    void updCoordNboundS    (void);

    // sub-section ** VIRTUAL **
    public:
    virtual void updParamsAfterParentMod            (void);    

    // section end   **** PARAMETERS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** COORDINATES *****

    public:    
    void initRelCoordX      (int32_t p_x);
    int32_t getRelCoordX       (void);
    void setRelCoordX       (int32_t p_x);
    void incRelCoordX       (int32_t p_delta);
    void initRelCoordY      (int32_t p_y);
    int32_t getRelCoordY       (void);
    void setRelCoordY       (int32_t p_y);
    void incRelCoordY       (int32_t p_delta);
    void initRelCoordS      (int32_t p_x, int32_t p_y);
    void setRelCoords       (int32_t p_x, int32_t p_y);

    void updAbsCoordX       (void);
    void updAbsCoordY       (void);
    void updAbsCoords       (void);

    protected:
    //      - relative respect parent window (N.B.: parent window can be different than root window)
    int32_t g_x0r;  
    int32_t g_y0r;

    //      - absolute respect parent window (N.B.: to set these coords you must use "updAbsCoord" functions)
    int32_t g_x0a;  
    int32_t g_y0a;
    //      - absolute respect root window (N.B.: to set these coords you must use "updAbsCoord" functions)
    //          - the mouse coords are given, by platform driver functions (i.e. ncurses library), respect root window
    int32_t g_mouseX0a;
    int32_t g_mouseY0a;

    // section end   **** COORDINATES *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** MARGINS *****

    //  - margins (N.B. these parameters are set by the class constructor)
    uint8_t g_marginXleft;
    uint8_t g_marginXright;
    uint8_t g_marginYtop;
    uint8_t g_marginYbottom;
    // section end   **** MARGINS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DIMENSIONS *****
    public:    
    void setDimW        (uint16_t p_w);
    void updDimW        (void);
    uint16_t getDimW    (void);

    void setDimH        (uint16_t p_h);
    void updDimH        (void);
    uint16_t getDimH    (void);

    void setDims        (uint16_t p_w, uint16_t p_h);
    void updDims        (void);

    protected:
    uint16_t g_w; 
    uint16_t g_h;
    // section end   **** DIMENSIONS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** BOUNDS *****
    public:
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

    protected:
    //  - bounds (N.B.: to set these bounds you must use "updBound" functions)
    int16_t g_boundXleft;
    int16_t g_boundXright;
    int16_t g_boundYupper;
    int16_t g_boundYlower;
    // section end   **** BOUNDS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** MOUSE CLICK MANAGEMENT *****
    public:
    bool bMouseClickInsideBounds    (void);
    static void updAbsMouseCoordX          (int16_t p_deltaY);
    static void updAbsMouseCoordY          (int16_t p_deltaY);

    protected:
    static uint16_t g_xMouse;
    static uint16_t g_yMouse;
    // section end   **** MOUSE CLICK MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CURSOR MANAGEMENT *****

    protected:
    static uint16_t g_position;
    static uint16_t g_xCursor;
    static uint16_t g_yCursor;
    // section end   **** CURSOR MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER FUNCTION INTERFACE *****

    // functions called by container
    public:
    int32_t getDistanceFromBound                (void);
    int16_t getDisplayMaxH                      (void);
    bool    bVisibleCompletely                  (void);

    // sub-section ** VIRTUAL **
    virtual void updCoordNboundsChilds              (void);

    // section end   **** CONTAINER FUNCTION INTERFACE *****
    // ****************************************************
    // --------------------------



};

#endif 	// TUI_GRAPHIC_COORD_H
