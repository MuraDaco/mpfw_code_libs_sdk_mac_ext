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
 * dtyTuiGraphic.cpp
 *
 *  Created on: Nov, 4th 2024
 *      Author: Marco Dau
 */
 

#include "dtyTuiGraphic.h"

// ****************************************************
// section start **** GENERAL *****




dtyTuiGraphic_t::dtyTuiGraphic_t   (tuiGraphicUnit_t* p_array) :
     g_array        {p_array}
    ,g_y0r          {0}
{
    resetSelectElement();
}


void dtyTuiGraphic_t::resetSelectElement         (void)    {
    uint8_t l_id = 0;
    while (g_array[l_id].bNotNull())   {
        l_id++;
    }
    g_arraySize   = l_id;
    g_selectIdElement      = l_id;
}

bool dtyTuiGraphic_t::resetLoopElement         (void)    {
    bool l_result = false;  // "false" means empty list
    g_loopIdElement = 0;
    // check whether the list is empty
    if(g_array[g_loopIdElement].bNotNull()) l_result = true;
    return l_result;
}

bool dtyTuiGraphic_t::bLoopInitDisplay           ([[maybe_unused]] uint8_t p_id, [[maybe_unused]] void* p_pParent)    {
    // to be implemented - see below
    return true;
}
// bool dtyTuiGraphic_t::bLoopInitDisplay           (uint8_t p_id, void* p_pParent)    {
//     bool l_result = false;
//     if(g_array[p_id].bNotNull())   {
// 
//         // init "g_loopY0rElement" global parameter
//         g_loopY0rElement = (p_id) ? g_loopY0rElement : 0;
// 
//         // set data to element
//         g_array[p_id].tuiGraphicCoord_t::setParent(static_cast<tuiGraphicCoord_t*>(p_pParent));
//         g_array[p_id].setNcursesWindow(static_cast<tuiDrvGraphic_t*>(p_pParent));
// 
//         g_array[p_id].initRelCoordS(0, g_loopY0rElement);
// 
//         // determine the "g_loopY0rElement" (global parameter) for the next cycle
//         g_loopY0rElement += g_array[p_id].getDimH();
// 
//         l_result = true;
//     } else {
//         // Be carefull!! it seems wrong
//         g_h = g_loopY0rElement;
//     }
//     return l_result;
// }
// 

uint8_t dtyTuiGraphic_t::getLoopInitCycles       (void)    {
    return g_arraySize;
}

void dtyTuiGraphic_t::initDisplay                (uint8_t p_id, void* p_pParent)  {
    g_poParent = static_cast<tuiGraphicUnit_t*>(p_pParent);

    // init "g_loopY0rElement" global parameter
    g_loopY0rElement = (p_id) ? g_loopY0rElement : 0;

    // set data to element
    g_array[p_id].init(g_poParent);
    //g_array[p_id].tuiGraphicCoord_t::setParent(static_cast<tuiGraphicCoord_t*>(p_pParent));
    //g_array[p_id].setNcursesWindow(static_cast<tuiDrvGraphic_t*>(p_pParent));
    g_array[p_id].initRelCoordS(0, g_loopY0rElement);
    g_array[p_id].updParamsAfterParentMod();
    // determine the "g_loopY0rElement" (global parameter) for the next cycle
    g_loopY0rElement += g_array[p_id].getDimH();
    g_h = g_loopY0rElement;
}

#define RECURSIVELY     true
bool dtyTuiGraphic_t::selectElementByMouse      (void)      {
    bool l_result = false;
    if(g_array[g_loopIdElement].bMouseClickInsideBounds()) {
        //if(g_pCurrentElement) g_pCurrentElement->element->deSelect();   // because of mouse event management
        g_selectIdElement = g_loopIdElement;
        if(!bSelectVisibleCompletely()) {
            // the element selected is not completely visible, therefore ...

            // it is necessary make it completely visibile

            // completely clear the display box 
            clearDisplayBox();

            // determine "delta" shift
            int32_t l_delta = getDeltaShiftBySelect();

            // update container relative coord
            updCntnrRelCoord(-l_delta);

            // update mouse absolute coord
            tuiGraphicCoord_t::updAbsMouseCoordY(l_delta);

            // update relative coordinates of every elements 
            // with "delta" shift previously determined
            for(uint8_t l_id = 0; l_id < g_arraySize; l_id++)   {
                if(l_delta) {
                    // update relative coord of element recursively
                    g_array[l_id].incRelCoordY(l_delta);
                    // refresh element content recursively
                    g_array[l_id].display(RECURSIVELY);
                }
            }

        }
        l_result = g_array[g_loopIdElement].selectByMouse();
    }
    return l_result;
}

int32_t dtyTuiGraphic_t::getDeltaShiftBySelect           (void)    {
    // determine the delta
    return g_array[g_selectIdElement].getDistanceFromBound();
}

void dtyTuiGraphic_t::shiftLoopElementBySelect       (int32_t p_delta)    {

    if(p_delta) g_array[g_loopIdElement].incRelCoordY(p_delta);
}

void dtyTuiGraphic_t::updSelectElement       (void)    {
    g_array[g_selectIdElement].deselectBackNselect();
}

void dtyTuiGraphic_t::clearDisplayBox       (void)    {
    g_poParent->clear();
}

bool dtyTuiGraphic_t::updCntnrRelCoord           (int32_t p_delta)    {
    bool l_result = true;
    g_y0r += p_delta;
    if(g_y0r < 0)   {
        g_y0r -= p_delta;
        l_result = false;
    } else {
        if((g_y0r + g_poParent->getDisplayMaxH()) > g_h)   {
            g_y0r -= p_delta;
            l_result = false;
        }
    }

    return l_result;
}

// shift the content up (to high) to see the content that is lower
// it is equivalent to shift the display box down (to the bottom) therefore ...
// increment the display box relative coords
void dtyTuiGraphic_t::shiftLoopElementRollUp       (void)    {
    g_array[g_loopIdElement].incRelCoordY(-1);    
}

// shift the content down (to the bottom) to see the content that is higher
// it is equivalent to shift the display box up (to high) therefore ...
// decrememt the display box relative coords
void dtyTuiGraphic_t::shiftLoopElementRollDown       (void)    {
    g_array[g_loopIdElement].incRelCoordY(1);
}

void dtyTuiGraphic_t::updElementCoordNbounds       (void)    {
    g_array[g_loopIdElement].updParamsAfterParentMod();
}

void dtyTuiGraphic_t::dspElement                 (bool p_recursively)  {
    g_array[g_loopIdElement].display(p_recursively);
}

bool dtyTuiGraphic_t::nextLoopElement          (void)    {
    bool l_result = false;
    g_loopIdElement++;
    if(g_loopIdElement < g_arraySize) {
        l_result = true;
    }
    return l_result;
}



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

void* dtyTuiGraphic_t::getSelectedItem               (void)      {
    return &g_array[g_selectIdElement];
}

bool dtyTuiGraphic_t::setSelectPrev                  (void)    {
    bool l_result = false;
    if(g_arraySize)   {

        if(g_selectIdElement == g_arraySize)  {
            g_selectIdElement = 0;
            l_result = true;
        } else {
            if(g_selectIdElement)  {
                g_selectIdElement--;
                l_result = true;
            }
        }
    }
    return l_result;
}

bool dtyTuiGraphic_t::setSelectNext                  (void)    {
    bool l_result = false;
    if(g_arraySize)   {

        if(g_selectIdElement == g_arraySize)  {
            g_selectIdElement = 0;
            l_result = true;
        } else {
            g_selectIdElement++;
            if(g_selectIdElement < g_arraySize) {
                l_result = true;
            } else {
                g_selectIdElement = g_arraySize-1;
            }
        }

    }
    return l_result;
}


bool dtyTuiGraphic_t::bSelectVisibleCompletely       (void)    {

    return g_array[g_selectIdElement].bVisibleCompletely();
}




// section end   **** SELECT ***** 
// ****************************************************

