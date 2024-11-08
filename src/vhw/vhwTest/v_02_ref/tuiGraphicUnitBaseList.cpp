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
 * tuiGraphicUnitBaseList.cpp
 *
 *  Created on: Nov, 4th 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicUnitBaseList.h"

#define MIN(a,b) (a < b) ? a : b
#define MAX(a,b) (a > b) ? a : b

tuiGraphicUnitBaseList_t::tuiGraphicUnitBaseList_t      (tuiUnitAbstract_t* p_pUnit )   :
     tuiGraphicUnit_t       (p_pUnit    )
{}

tuiGraphicUnitBaseList_t::tuiGraphicUnitBaseList_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    )   :
     tuiGraphicUnit_t       (p_pUnit    ,p_box)
{}

tuiGraphicUnitBaseList_t::tuiGraphicUnitBaseList_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    ,margins_t p_margin )   :
     tuiGraphicUnit_t       (p_pUnit    ,p_box  ,p_margin)
{}

bool tuiGraphicUnitBaseList_t::init       (void) 	{
    return true;
}

bool tuiGraphicUnitBaseList_t::initChildren       (void) 	{
    return true;
}

bool tuiGraphicUnitBaseList_t::init       (tuiGraphicUnit_t* p_pParent) 	{
    tuiGraphicState_t::setParent(static_cast<tuiGraphicState_t*>(p_pParent));
    tuiGraphicCoord_t::setParent(static_cast<tuiGraphicCoord_t*>(p_pParent));

    initCoordBase();
    setNcursesWindow(p_pParent);
    g_status = tuiMode_t::undefined;

    return true;
}

bool tuiGraphicUnitBaseList_t::loopChildren    (void)  {
    return true;
}

bool tuiGraphicUnitBaseList_t::loop            (void)  {
    return false;
}


void tuiGraphicUnitBaseList_t::end 	        (void)      {
}

void tuiGraphicUnitBaseList_t::endChildren  (void)      {
}

// --------------------- Container section - START

void tuiGraphicUnitBaseList_t::updCoordNboundsChilds    (void)       {
    
    g_pUnit->updCoordNboundsChilds();
}

void tuiGraphicUnitBaseList_t::updParamsAfterParentMod    (void)       {
    updAbsCoords();
    tuiGraphicCoord_t::updParamsAfterParentMod();
}


// --------------------- Container section - END



bool tuiGraphicUnitBaseList_t::eventOnTst       (void)  {
    return true;
}

void tuiGraphicUnitBaseList_t::debug_01         (void)  {

}

