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
 * dtyCntnrArrayList.h
 *
 *  Created on: Nov, 20th 2024 (Wed)
 *      Author: Marco Dau
 *
 */
 
#ifndef DTY_CNTNR_ARRAY_LIST_H
#define DTY_CNTNR_ARRAY_LIST_H

#include <cstdint>
#include "dtyBaseCntnrUnitX.h"
//#include "tuiBase.h"
#include "tuiGraphicUnit.h"

class dtyCntnrArrayList_t : public dtyBaseCntnrUnitX_t  {

public:
    // ****************************************************
    // section start **** GENERAL *****

    dtyCntnrArrayList_t   (tuiGraphicUnit_t* p_array);

    // section end   **** GENERAL ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****


    // section end   **** WRITE ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** DISPLAY *****


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****

    // section end   **** SELECT ***** 
    // ****************************************************


protected:

    // ****************************************************
    // section start **** GENERAL *****

    bool    resetLoopElement            (void)  override;
    uint8_t getLoopInitCycles           (void)  override;
    // bool    bLoopInitDisplay            (uint8_t p_id, void* p_poFather)    override;
    void    initDisplay                 (uint8_t p_id, void* p_poFather)    override;
    bool    selectElementByMouse        (void)  override;
    int32_t getDeltaShiftBySelect       (void)  override;
    void    shiftLoopElementBySelect    (int32_t p_delta)  override;
    void    updSelectElement            (void)  override;
    void    clearDisplayBox             (void)  override;
    bool    updCntnrRelCoord            (int32_t p_delta)  override;
    void    shiftLoopElementRollUp      (void)  override;
    void    shiftLoopElementRollDown    (void)  override;
    void    updElementCoordNbounds      (void)  override;
    void    dspElement                  (bool p_recursively)  override;
    bool    nextLoopElement             (void)  override;


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****


    // section end   **** WRITE ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** DISPLAY *****


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****

    // section **** SELECT ****

    void*   getSelectedItem                 (void) override;
    bool    setSelectPrev                   (void) override;
    bool    setSelectNext                   (void) override;
    bool    bSelectVisibleCompletely        (void) override;

    // section end   **** SELECT ***** 
    // ****************************************************

private:

    void resetSelectElement         (void);

    tuiGraphicUnit_t* g_array;
    tuiGraphicUnit_t*  g_poParent;
    uint8_t     g_arraySize;
    uint8_t     g_selectIdElement;
    uint8_t     g_loopIdElement;
    uint16_t    g_loopY0rElement;

    //int32_t     g_x0r;
    int32_t     g_y0r;
    uint16_t    g_h;

};


#endif 	// DTY_CNTNR_ARRAY_LIST_H
