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
 * tuiBaseCntnrX.cpp
 *
 *  Created on: Sep, 21st 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseCntnrX.h"


tuiBaseCntnrX_t::tuiBaseCntnrX_t      (const char* p_strName, box_t p_box, dtyBaseCntnrUnitX_t* p_pCntr) :
     tuiBase_t              (p_strName, p_box)
    ,g_pCntnr               {p_pCntr}
{}

tuiBaseCntnrX_t::tuiBaseCntnrX_t      (const char* p_strName, box_t* p_pBox, dtyBaseCntnrUnitX_t* p_pCntr) :
     tuiBase_t              (p_strName, p_pBox)
    ,g_pCntnr               {p_pCntr}
{}

void tuiBaseCntnrX_t::initElementsList       (void) 	{
    // 1. init Box parameter & pointers
    g_pCntnr->initDisplayBox(this);
}

void tuiBaseCntnrX_t::displayElements     (bool p_recursively)    {
    g_pCntnr->displayChilds(p_recursively);

}

void tuiBaseCntnrX_t::updCoordNboundsChilds    (void)       {
    g_pCntnr->updCoordNboundsChilds();
}


bool tuiBaseCntnrX_t::selectByMouse     (void)    {

    if(g_pCntnr->selectElementsByMouse()) {
        //select();   // to remove
    } else {
        deselectBackNeventOn();
    }
    return true;
}

void tuiBaseCntnrX_t::rollUp     (tuiBaseCntnrX_t* p_po)    {
    p_po->g_pCntnr->displayBoxRollUp();
    p_po->g_pCntnr->displayChilds(true);

}

void tuiBaseCntnrX_t::rollDown	(tuiBaseCntnrX_t* p_po)  {
    p_po->g_pCntnr->displayBoxRollDown();
    p_po->g_pCntnr->displayChilds(true);

}

void tuiBaseCntnrX_t::selectPrev     (tuiBaseCntnrX_t* p_po)    {
    p_po->g_pCntnr->selectSubBoxUp();
    p_po->g_pCntnr->displayChilds(true);

}

// to use when arrow up key event occur
void tuiBaseCntnrX_t::selectNext	(tuiBaseCntnrX_t* p_po)  {
    p_po->g_pCntnr->selectSubBoxDown();
    p_po->g_pCntnr->displayChilds(true);
}

void tuiBaseCntnrX_t::refreshElements     (void)    {

}

