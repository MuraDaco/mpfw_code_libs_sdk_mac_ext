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
    ,g_selectElement         {p_array}
    ,g_loopElement           {p_array}
{}


dtyTuiBase_t::dtyTuiBase_t   (dtyTuiBaseUnit_t* p_unitArray)   :
     g_unitArray                {p_unitArray}
    ,g_unitSelectElement        {p_unitArray}
    ,g_unitLoopElement          {p_unitArray}
{}


bool dtyTuiBase_t::resetLoopElement         (void)    {
    bool l_result = false;  // "false" means empty list
    g_loopElement = g_array;
    // check wether the list is empty
    if(*g_loopElement) l_result = true;
    return l_result;
}


void dtyTuiBase_t::initDisplay                (void* p_poFather)   {
    (*g_loopElement)->init(p_poFather);
}

bool dtyTuiBase_t::selectElementBySelect      (void)      {
    return false;
}

void dtyTuiBase_t::shiftLoopElementBySelect       (void)    {
    // determine the delta
    int32_t l_delta = (*g_selectElement)->getDistanceFromBound();

    if(l_delta) (*g_loopElement)->updCoordNbounds(l_delta);
}

void dtyTuiBase_t::shiftLoopElementRollUp       (void)    {
    (*g_loopElement)->updCoordNbounds(-1);
}

void dtyTuiBase_t::shiftLoopElementRollDown       (void)    {
    (*g_loopElement)->updCoordNbounds(1);
}

void dtyTuiBase_t::updElementCoordNbounds       (void)    {
    (*g_loopElement)->updCoordNboundsForNewFather();
}

void dtyTuiBase_t::dspElement                 (bool p_recursively)  {
    (*g_loopElement)->display(p_recursively);
}

bool dtyTuiBase_t::nextLoopElement          (void)    {
    bool l_result = true;
    g_loopElement++;
    if(!(*g_loopElement)) {
        l_result = false;
        g_loopElement = g_array;
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

bool dtyTuiBase_t::setSelectPrev                  (void)    {
    bool l_result = false;
    if(g_array != g_selectElement)  {
        g_selectElement--;
        l_result = true;
    }
    return l_result;
}

bool dtyTuiBase_t::setSelectNext                  (void)    {
    bool l_result = true;
    g_selectElement++;
    if(*g_selectElement) {
        l_result = false;
        // go back
        g_selectElement--;
    }
    return l_result;
}


bool dtyTuiBase_t::bSelectVisibleCompletely       (void)    {

    return (*g_selectElement)->bVisibleCompletely();
}




// section end   **** SELECT ***** 
// ****************************************************

