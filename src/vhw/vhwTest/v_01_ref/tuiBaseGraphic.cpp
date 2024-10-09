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
 * tuiBaseGraphic.cpp
 *
 *  Created on: Oct, 8th 2024
 *      Author: Marco Dau
 */

#include "tuiBaseGraphic.h"

uint8_t tuiBaseGraphic_t::g_xMouse;
uint8_t tuiBaseGraphic_t::g_yMouse;
uint8_t tuiBaseGraphic_t::g_position;

#define OFF     0
#define ON      1

void tuiBaseGraphic_t::updateRelativeX   (uint8_t p_x0r) {
    g_x0Win = (g_x0Win  - g_x0r) + p_x0r + 1;   // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_x0a   = (g_x0a    - g_x0r) + p_x0r + 1;   // N.B.: (g_x0a - g_x0r) = p_poFather->g_x0a
    g_x0r   = p_x0r + 1;
}

void tuiBaseGraphic_t::updateRelativeY   (uint8_t p_y0r) {
    g_y0Win = (g_y0Win - g_y0r) + p_y0r + 1;    // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_y0a   = (g_y0a   - g_y0r) + p_y0r + 1;    // N.B.: (g_y0a   - g_y0r) = p_poFather->g_x0a
    g_y0r   = p_y0r + 1;
}


int16_t tuiBaseGraphic_t::getRefX0            (void)  {
    return g_lvl1X0a + g_marginLeft;
}

int16_t tuiBaseGraphic_t::getRootRefX0            (void)  {
    return g_x0a + g_marginLeft;
}

int16_t tuiBaseGraphic_t::getDisplayMaxW      (void)  {
    return g_w - (g_marginLeft + g_marginRight);
}

int16_t tuiBaseGraphic_t::getRefY0            (void)  {
    return g_lvl1Y0a + g_marginTop;
}

int16_t tuiBaseGraphic_t::getRootRefY0            (void)  {
    return g_y0a + g_marginTop;
}

int16_t tuiBaseGraphic_t::getDisplayMaxH      (void)  {
    return g_h - (g_marginTop + g_marginBottom);
}




bool tuiBaseGraphic_t::bMouseClickInsideBounds (void)      {
    bool l_result = false;

    if(
        ((g_x0a <= g_xMouse) && (g_xMouse < (g_x0a + g_w ))) &&
        ((g_y0a <= g_yMouse) && (g_yMouse < (g_y0a + g_h )))
    ) {
        l_result = true;

    }
    return l_result;
}


bool tuiBaseGraphic_t::isSelectedOrEventOn             (void)  {
    return (
            (tuiMode_t::select == g_mode) ||
            (tuiMode_t::eventOn == g_mode)
    );
}

bool tuiBaseGraphic_t::isSelected             (void)  {
    return (tuiMode_t::select == g_mode);
}

