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
 * dtyTuiBase.h
 *
 *  Created on: Sep, 21st 2024
 *      Author: Marco Dau
 *
 */
 
#ifndef DTY_TUI_BASE_H
#define DTY_TUI_BASE_H

#include <cstdint>
#include "dtyBaseCntnrUnitX.h"
#include "dtyTuiBaseUnit.h"

class dtyTuiBase_t : public dtyBaseCntnrUnitX_t  {

public:
    // ****************************************************
    // section start **** GENERAL *****

    dtyTuiBase_t   (tuiBase_t** p_array);
    dtyTuiBase_t   (dtyTuiBaseUnit_t* p_unitArray);

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

    bool resetLoopElement           (void)  override;
    void initDisplay                (void* p_poFather)  override;
    bool selectElementBySelect      (void)  override;
    void shiftLoopElementBySelect   (void)  override;
    void shiftLoopElementRollUp     (void)  override;
    void shiftLoopElementRollDown   (void)  override;
    void updElementCoordNbounds     (void)  override;
    void dspElement                 (bool p_recursively)  override;
    bool nextLoopElement            (void)  override;


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

    bool setSelectPrev                  (void) override;
    bool setSelectNext                  (void) override;
    bool bSelectVisibleCompletely       (void) override;

    // section end   **** SELECT ***** 
    // ****************************************************

private:

    tuiBase_t**     g_array;
    tuiBase_t**     g_selectElement;
    tuiBase_t**     g_loopElement;

    [[maybe_unused]] dtyTuiBaseUnit_t* g_unitArray;
    [[maybe_unused]] dtyTuiBaseUnit_t* g_unitSelectElement;
    [[maybe_unused]] dtyTuiBaseUnit_t* g_unitLoopElement;

};


#endif 	// DTY_TUI_BASE_H
