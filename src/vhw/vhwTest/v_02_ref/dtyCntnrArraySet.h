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
 * dtyCntnrArraySet.h
 *
 *  Created on: Nov, 20th 2024 (Wed)
 *      Author: Marco Dau
 *
 */
 
#ifndef DTY_CNTNR_ARRAY_SET_H
#define DTY_CNTNR_ARRAY_SET_H

#include <cstdint>
#include "dtyBaseCntnrUnitX.h"
//#include "tuiBase.h"
#include "tuiGraphicUnit.h"

class dtyCntnrArraySet_t : public dtyBaseCntnrUnitX_t  {

public:
// ****************************************************
// section start **** CONBSTRUCTOR *****

    dtyCntnrArraySet_t   (tuiGraphicUnit_t* p_array);

    // section end   **** CONBSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** ARRAY CONTAINER MANAGEMENT *****
    tuiGraphicUnit_t* g_array;
    tuiGraphicUnit_t*  g_poParent;
    uint8_t     g_arraySize;

    //int32_t     g_x0r;
    int32_t     g_y0r;
    uint16_t    g_h;
    // section end   **** ARRAY CONTAINER MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** LOOP MANAGEMENT *****
    private:
    // virtual override
    uint8_t getLoopInitCycles               (void)  override;
    bool    resetLoopElement                (void)  override;
    bool    nextLoopElement                 (void)  override;
    
    uint8_t     g_loopIdElement;
    int32_t     g_loopBoundYtop;
    int32_t     g_loopBoundYbottom;

    // section end   **** LOOP MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****
    private:

    bool    updCntnrRelCoord                (int32_t p_delta)  override;
    void    updElementCoordNbounds          (void)  override;

    // bool    bLoopInitDisplay                (uint8_t p_id, void* p_pParent)    override;
    void    initDisplay                     (uint8_t p_id, void* p_pParent)    override;
    void    clearDisplayBox                 (void)  override;
    void    dspElement                      (bool p_recursively)   override; // test

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INPUT EVENTS: SELECTION & MOUSE ROLL *****

    private:
    // roll
    void    shiftLoopElementRollUp          (void)  override;
    void    shiftLoopElementRollDown        (void)  override;
    // select
    bool    selectElementByMouse            (void) override;
    void    shiftLoopElementBySelect        (int32_t p_delta)  override;
    int32_t getDeltaShiftBySelect           (void) override;
    void    updSelectElement                (void) override;
    bool    setSelectPrev                   (void) override;
    bool    setSelectNext                   (void) override;
    bool    bSelectVisibleCompletely        (void) override;
    bool    bFindSelectedElement            (void);
    void*   getSelectedItem                 (void) override;

    void resetSelectElement         (void);

    uint8_t     g_selectIdElement;

    // section end   **** INPUT EVENTS: SELECTION & MOUSE ROLL ***** 
    // ****************************************************




};


#endif 	// DTY_CNTNR_ARRAY_SET_H
