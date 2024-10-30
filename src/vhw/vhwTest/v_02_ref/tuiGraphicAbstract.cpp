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
 * tuiGraphicAbstract.h
 *
 *  Created on: Oct, 22nd 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicAbstract.h"

#define G_P_PARENT  static_cast<tuiGraphicAbstract_t*>(g_pParent)

tuiGraphicAbstract_t::tuiGraphicAbstract_t    (tuiUnitAbstract_t* p_pUnit   )      :
     tuiGraphicCoord_t      ()
    ,g_pUnit                {p_pUnit}
{}

tuiGraphicAbstract_t::tuiGraphicAbstract_t    (tuiUnitAbstract_t* p_pUnit   ,box_t p_box    )      :
     tuiGraphicCoord_t      (p_box  )
    ,g_pUnit                {p_pUnit}
{}

tuiGraphicAbstract_t::tuiGraphicAbstract_t    (tuiUnitAbstract_t* p_pUnit                   ,margins_t p_margin )      :
     tuiGraphicCoord_t      (       p_margin)
    ,g_pUnit                {p_pUnit}
{}

tuiGraphicAbstract_t::tuiGraphicAbstract_t    (tuiUnitAbstract_t* p_pUnit   ,box_t p_box  ,margins_t p_margin )      :
     tuiGraphicCoord_t      (p_box, p_margin)
    ,g_pUnit                {p_pUnit}
{}

void tuiGraphicAbstract_t::parentDeselectBackNeventOn     	    (void)  {
    if(G_P_PARENT)
        G_P_PARENT->deselectBackNeventOn();
}

bool tuiGraphicAbstract_t::bNull       	    (void)  {
    return (nullptr == g_pUnit);
}

bool tuiGraphicAbstract_t::bNotNull       	    (void)  {
    return (nullptr != g_pUnit);
}

