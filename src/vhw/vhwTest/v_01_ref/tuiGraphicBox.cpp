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
 * tuiGraphicBox.cpp
 *
 *  Created on: Aug, 3rd 2024
 *      Author: Marco Dau
 */

#include "tuiGraphicBox.h"


tuiGraphicBox_t::tuiGraphicBox_t (box_t* p_pBox) :
     g_h        {p_pBox->height}
    ,g_w        {p_pBox->width}
    ,g_y0       {p_pBox->yStart}
    ,g_x0       {p_pBox->xStart}
{}

tuiGraphicBox_t::tuiGraphicBox_t (uint8_t p_h, uint8_t p_w, uint8_t p_y0, uint8_t p_x0)     :
     g_h        {p_h}
    ,g_w        {p_w}
    ,g_y0       {p_y0}
    ,g_x0       {p_x0}
{}


void tuiGraphicBox_t::draw (WINDOW* p_pNcursWin)   {
	mvwaddch(p_pNcursWin, g_y0        ,g_x0       ,ACS_ULCORNER                   );
	mvwaddch(p_pNcursWin, g_y0        ,g_x0 + g_w ,ACS_URCORNER               );
	mvwaddch(p_pNcursWin, g_y0 + g_h  ,g_x0       ,ACS_LLCORNER               );
	mvwaddch(p_pNcursWin, g_y0 + g_h  ,g_x0 + g_w ,ACS_LRCORNER               );
	mvwhline(p_pNcursWin, g_y0        ,g_x0 + 1   ,0   ,g_w - 1    );
	mvwhline(p_pNcursWin, g_y0 + g_h  ,g_x0 + 1   ,0   ,g_w - 1    );
	mvwvline(p_pNcursWin, g_y0 + 1    ,g_x0       ,0   ,g_h - 1    );
	mvwvline(p_pNcursWin, g_y0 + 1    ,g_x0 + g_w ,0   ,g_h - 1    );
}