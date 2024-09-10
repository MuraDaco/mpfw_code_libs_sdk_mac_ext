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
 * tuiBase.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBase.h"

tuiBase_t::tuiBase_t (const char* p_strName, box_t *p_pBox) :
    tuiBaseDrawer_t(p_strName, p_pBox)
{}

tuiBase_t::tuiBase_t (const char* p_strName, box_t p_box) :
    tuiBaseDrawer_t(p_strName, p_box)
{}

tuiBase_t::tuiBase_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus) :
    tuiBaseDrawer_t(p_strName, p_box, p_pDtyStatus)
{}


void tuiBase_t::init       (void* p_poFather) 	{
    g_poFather      = static_cast<tuiBase_t*>(p_poFather);
    g_pNcursWin     = static_cast<tuiBase_t*>(p_poFather)->g_pNcursWin;
    g_x0Win         = static_cast<tuiBase_t*>(p_poFather)->g_x0Win  + g_x0r;
    g_y0Win         = static_cast<tuiBase_t*>(p_poFather)->g_y0Win  + g_y0r;
    g_x0a           = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a           = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;
    if(!g_w) g_w    = static_cast<tuiBase_t*>(p_poFather)->g_w - 2;

}


