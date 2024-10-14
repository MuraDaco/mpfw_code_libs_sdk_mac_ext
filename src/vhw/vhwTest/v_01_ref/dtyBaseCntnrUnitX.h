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
 * dtyBaseCntnrUnitX.h
 *
 *  Created on: Sep, 20th 2024
 *      Author: Marco Dau
 */
 
#ifndef DTY_BASE_CNTR_UNIT_X_H
#define DTY_BASE_CNTR_UNIT_X_H

#include "uyTypesDefs.h"
#include "dtyTypesDefs.h"


class dtyBaseCntnrUnitX_t   {

public:
    void        initDisplayBox          (void* p_poFather);
    void*       getSelect               (void);
    void        selectSubBoxUp          (void);
    void        selectSubBoxDown        (void);
    bool        selectElementsByMouse   (void);
    void        displayBoxRollUp        (void);
    void        displayBoxRollDown      (void);
    void        updCoordNboundsChilds   (void);
    void        displayChilds           (bool p_recursively);

private:
    void        selectDisplayBoxMoveTo  (void);
    

protected:

    // section **** GENERAL ****
    virtual uint8_t getLoopInitCycles       (void) = 0;
    virtual bool bLoopInitDisplay           (uint8_t p_id, void* p_poFather) = 0;
    virtual void initDisplay                (uint8_t p_id, void* p_poFather) = 0;
    virtual void initDisplay                (void* p_poFather) = 0;
    virtual bool resetLoopElement           (void) = 0;
    virtual bool selectElementByMouse       (void) = 0;
    virtual void shiftLoopElementBySelect   (void) = 0;
    virtual void shiftLoopElementRollUp     (void) = 0;
    virtual void shiftLoopElementRollDown   (void) = 0;
    virtual void updElementCoordNbounds     (void) = 0;
    virtual void dspElement                 (bool p_recursively) = 0;
    virtual bool nextLoopElement            (void) = 0;


    // section **** WRITE ****

    // section **** DISPLAY *****

    // section **** SELECT ****

    virtual void*   getSelectedItem                 (void)  {return nullptr;};
    virtual bool    setSelectPrev                  (void) = 0;
    virtual bool    setSelectNext                  (void) = 0;
    virtual bool    bSelectVisibleCompletely       (void) = 0;
};


#endif 	// DTY_BASE_CNTR_UNIT_X_H
