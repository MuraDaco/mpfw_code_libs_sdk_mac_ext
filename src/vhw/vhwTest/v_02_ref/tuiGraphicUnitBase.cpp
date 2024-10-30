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
 * tuiGraphicUnitBase.cpp
 *
 *  Created on: Oct, 28th 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicUnitBase.h"

#define MIN(a,b) (a < b) ? a : b
#define MAX(a,b) (a > b) ? a : b

tuiGraphicUnitBase_t::tuiGraphicUnitBase_t      (tuiUnitAbstract_t* p_pUnit )   :
     tuiGraphicUnit_t       (p_pUnit    )
{}

tuiGraphicUnitBase_t::tuiGraphicUnitBase_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    )   :
     tuiGraphicUnit_t       (p_pUnit    ,p_box)
{}

tuiGraphicUnitBase_t::tuiGraphicUnitBase_t      (tuiUnitAbstract_t* p_pUnit ,box_t p_box    ,margins_t p_margin )   :
     tuiGraphicUnit_t       (p_pUnit    ,p_box  ,p_margin)
{}

bool tuiGraphicUnitBase_t::init       (void) 	{
    return true;
}

bool tuiGraphicUnitBase_t::initChildren       (void) 	{
    return true;
}

bool tuiGraphicUnitBase_t::init       (tuiGraphicUnit_t* p_pParent) 	{
    initCoord(p_pParent);
    setNcursesWindow(p_pParent);
    g_status = tuiMode_t::undefined;

//    g_x0a           = p_pParent->getDspBoxAbsRefX() + g_x0r;
//    g_y0a           = p_pParent->getDspBoxAbsRefY() + g_y0r;
//
//    g_mouseX0a      = p_pParent->getMouseAbsRefX() + g_x0r;
//    g_mouseY0a      = p_pParent->getMouseAbsRefY() + g_y0r;
//
//    if(!g_w) g_w    = p_pParent->g_w - 2;
//
//    g_lvl1X0a       = p_pParent->getRefX0() + g_lvl1X0r;
//    g_displayBoxW   = p_pParent->getDisplayMaxW();
//    g_lvl1Y0a       = p_pParent->getRefY0() + g_lvl1Y0r;
//    g_displayBoxH   = p_pParent->getDisplayMaxH();
//    
//
//    // init bounds
//    g_boundUpper = MAX(p_pParent->getBoundYupper(), g_lvl1Y0a);
//    g_boundLower = MIN(p_pParent->getBoundYlower(), g_lvl1Y0a + g_h - 1);

    return true;
}

bool tuiGraphicUnitBase_t::loopChildren    (void)  {
    return true;
}

bool tuiGraphicUnitBase_t::loop            (void)  {
    return false;
}


void tuiGraphicUnitBase_t::end 	        (void)      {
}

void tuiGraphicUnitBase_t::endChildren  (void)      {
}


bool tuiGraphicUnitBase_t::eventOnTst       (void)  {
    return true;
}

void tuiGraphicUnitBase_t::debug_01         (void)  {

}

