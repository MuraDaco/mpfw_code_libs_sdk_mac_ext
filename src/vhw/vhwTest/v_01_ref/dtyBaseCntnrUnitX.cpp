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
 * dtyBaseCntnrUnitX.cpp
 *
 *  Created on: Sep, 20th 2024
 *      Author: Marco Dau
 */
 

#include "dtyBaseCntnrUnitX.h"

// ****************************************************
// section start **** GENERAL *****


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

void dtyBaseCntnrUnitX_t::initDisplayBox                (void* p_poFather)  {
    
    uint8_t l_loopCycles = getLoopInitCycles();
    for(uint8_t l_id = 0; l_id < l_loopCycles; l_id++ ) initDisplay(l_id, p_poFather);
    //for(uint8_t l_id = 0; l_id < getLoopInitCycles(); l_id++ ) initDisplay(l_id, p_poFather);
    //for(uint8_t l_id = 0; bLoopInitDisplay(l_id, p_poFather); l_id++ ) {}

    // determine the container height

}

void* dtyBaseCntnrUnitX_t::getSelect                (void) {

    return getSelectedItem();

}

// to use when arrow key up event occur
void dtyBaseCntnrUnitX_t::selectSubBoxUp                (void) {

    if(setSelectPrev()) selectDisplayBoxMoveTo();

}

// to use when arrow key up event occur
void dtyBaseCntnrUnitX_t::selectSubBoxDown              (void) {

    if(setSelectNext()) selectDisplayBoxMoveTo();
}

void dtyBaseCntnrUnitX_t::selectDisplayBoxMoveTo        (void) {

    if(bSelectVisibleCompletely())    {
        // it is not necessary shift any elements

        // update select display status
        updSelectElement();
    } else {
        // completely clear the display box 
        clearDisplayBox();

        // determine "delta" shift
        int32_t l_delta = getDeltaShiftBySelect();

        // update relative coord of container
        updCntnrRelCoord(-l_delta);

        // update relative coordinates of every elements 
        // with "delta" shift previously determined
        if(resetLoopElement())  {
            do {
                shiftLoopElementBySelect(l_delta);
            } while (nextLoopElement());
        }
        
        // update select display status
        updSelectElement();
    }

}

bool dtyBaseCntnrUnitX_t::selectElementsByMouse        (void) {
    bool l_result = false;
    if(resetLoopElement())  {
        do {
            l_result = selectElementByMouse();
        } while (nextLoopElement() && !l_result);
    }

    return l_result;
}

// °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// to use when mouse roll-up event occur
// N.B.: roll-up means shift the content of the displayed list data up that is decrement the y-coord 
//      it is equivalent to shift display-BOX down
// this function update the coordinates coordinates of all elements
void dtyBaseCntnrUnitX_t::displayBoxRollUp(void) {

    // update relative coord of container
    if(updCntnrRelCoord(+1))  {
        // update relative coordinates of every elements
        if(resetLoopElement())  {
            do {
                shiftLoopElementRollUp();
            } while (nextLoopElement());
        }
    }


}

// to use when mouse roll-down event occur
// N.B.: roll-down means shift the content of the displayed list data down that is increment the y-coord 
//      it is equivalent to shift display-BOX up
// this function update the coordinates coordinates of all elements
void dtyBaseCntnrUnitX_t::displayBoxRollDown(void) {

    // update relative coord of container
    if(updCntnrRelCoord(-1))  {
        // update relative coordinates of every elements
        if(resetLoopElement())  {
            do {
                shiftLoopElementRollDown();
            } while (nextLoopElement());
        }
    }

}

// °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

void dtyBaseCntnrUnitX_t::updCoordNboundsChilds    (void)       {

    // update relative coordinates of every elements
    if(resetLoopElement())  {
        do {
            updElementCoordNbounds();
        } while (nextLoopElement());
    }

}

void dtyBaseCntnrUnitX_t::displayChilds    (bool p_recursively)       {

    // update relative coordinates of every elements
    if(resetLoopElement())  {
        do {
            dspElement(p_recursively);
        } while (nextLoopElement());
    }

}


// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

