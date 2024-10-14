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
 * dtyTuiBase.cpp
 *
 *  Created on: Sep, 21st 2024
 *      Author: Marco Dau
 */
 

#include "dtyTuiBase.h"

// ****************************************************
// section start **** GENERAL *****




dtyTuiBase_t::dtyTuiBase_t   (tuiBase_t** p_array) :
     g_array                 {p_array}
{
    resetSelectElement();
}


dtyTuiBase_t::dtyTuiBase_t   (dtyTuiBaseUnit_t* p_unitArray)   :
     g_unitArray                {p_unitArray}
{
    resetSelectElement();
}


void dtyTuiBase_t::resetSelectElement         (void)    {
    uint8_t l_id = 0;
    while(g_array[l_id])    {
        l_id++;
    }
    g_idSelectItem      = l_id;
    g_idArrayItemLast   = l_id;

}

bool dtyTuiBase_t::resetLoopElement         (void)    {
    bool l_result = false;  // "false" means empty list
    g_idLoopItem = 0;
    // check wether the list is empty
    if(g_array[g_idLoopItem]) l_result = true;
    return l_result;
}

bool dtyTuiBase_t::bLoopInitDisplay           (uint8_t p_id, void* p_poFather)    {
    bool l_result = false;
    if(p_id)    {
        // check the null-terminator array
        if(g_array[p_id])   {
            g_array[p_id]->init(p_poFather);
            //g_array[p_id]->
            l_result = true;
        } else {
            // end of loop, therefore ...
            // do nothing
        }
    } else {
        // first step of the loop

        // 
        g_array[p_id]->init(p_poFather);
        l_result = true;
    }
    return l_result;
}


uint8_t dtyTuiBase_t::getLoopInitCycles       (void)    {
    return 0;
}

void dtyTuiBase_t::initDisplay                (uint8_t p_id, void* p_poFather)  {
     g_array[p_id]->init(p_poFather);
}

void dtyTuiBase_t::initDisplay                (void* p_poFather)   {
    g_array[g_idLoopItem]->init(p_poFather);
}

bool dtyTuiBase_t::selectElementByMouse      (void)      {
    return false;
}

void dtyTuiBase_t::shiftLoopElementBySelect       (void)    {
    // determine the delta
    int32_t l_delta = g_array[g_idSelectItem]->getDistanceFromBound();

    if(l_delta) g_array[g_idLoopItem]->updCoordNbounds(l_delta);
}

void dtyTuiBase_t::shiftLoopElementRollUp       (void)    {
    g_array[g_idLoopItem]->updCoordNbounds(-1);
}

void dtyTuiBase_t::shiftLoopElementRollDown       (void)    {
    g_array[g_idLoopItem]->updCoordNbounds(1);
}

void dtyTuiBase_t::updElementCoordNbounds       (void)    {
    g_array[g_idLoopItem]->updCoordNboundsForNewFather();
}

void dtyTuiBase_t::dspElement                 (bool p_recursively)  {
    g_array[g_idLoopItem]->display(p_recursively);
}

bool dtyTuiBase_t::nextLoopElement          (void)    {
    bool l_result = true;
    g_idLoopItem++;
    if((g_idLoopItem+1) < g_idArrayItemLast) {
        l_result = false;
        g_idLoopItem = 0;
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

void* dtyTuiBase_t::getSelectedItem               (void)      {
    return g_array[g_idSelectItem];
}

bool dtyTuiBase_t::setSelectPrev                  (void)    {
    bool l_result = false;
    if(g_idSelectItem)  {
        g_idSelectItem--;
        l_result = true;
    }
    return l_result;
}

bool dtyTuiBase_t::setSelectNext                  (void)    {
    bool l_result = true;
    if((g_idSelectItem+1) < g_idArrayItemLast) {
        g_idSelectItem++;
        l_result = false;
    }
    return l_result;
}


bool dtyTuiBase_t::bSelectVisibleCompletely       (void)    {

    return g_array[g_idSelectItem]->bVisibleCompletely();
}




// section end   **** SELECT ***** 
// ****************************************************

