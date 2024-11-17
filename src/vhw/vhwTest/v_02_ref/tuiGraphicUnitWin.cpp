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
 * tuiGraphicUnitWin.cpp
 *
 *  Created on: Oct, 28th 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicUnitWin.h"

#define MIN(a,b) (a < b) ? a : b
#define MAX(a,b) (a > b) ? a : b

tuiGraphicUnitWin_t::tuiGraphicUnitWin_t      (tuiUnitAbstract_t* p_pUnit )   :
     tuiGraphicUnit_t       (p_pUnit    )
{}

tuiGraphicUnitWin_t::tuiGraphicUnitWin_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    )   :
     tuiGraphicUnit_t       (p_pUnit    ,p_box)
{}

tuiGraphicUnitWin_t::tuiGraphicUnitWin_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    ,margins_t p_margin )   :
     tuiGraphicUnit_t       (p_pUnit    ,p_box  ,p_margin)
{}

bool tuiGraphicUnitWin_t::init       (void) 	{
    return true;
}

bool tuiGraphicUnitWin_t::initChildren       (void) 	{
    return true;
}

#define P_P_PARENT_STATE static_cast<tuiGraphicState_t*>(p_pParent)
#define P_P_PARENT_COORD static_cast<tuiGraphicCoord_t*>(p_pParent)

bool tuiGraphicUnitWin_t::init       (tuiGraphicUnit_t* p_pParent) 	{
    tuiGraphicState_t::setParent(P_P_PARENT_STATE);
    tuiGraphicCoord_t::setParent(P_P_PARENT_COORD);


    initCoordWin();

    initWin();

    g_status = tuiMode_t::undefined;

    g_pUnit->init(this);

    return true;
}

bool tuiGraphicUnitWin_t::loopChildren    (void)  {
    return true;
}

bool tuiGraphicUnitWin_t::loop            (void)  {
    return false;
}


void tuiGraphicUnitWin_t::end 	        (void)      {
}

void tuiGraphicUnitWin_t::endChildren  (void)      {
}


void tuiGraphicUnitWin_t::debug_01         (void)  {

}

