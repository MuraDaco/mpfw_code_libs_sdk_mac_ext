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
 * tuiGraphicBox.h
 *
 *  Created on: Aug, 3rd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_BOX_H
#define TUI_GRAPHIC_BOX_H

#include <cstdint>
#include "tuiGraphicTypes.h"
#include <ncurses.h>


#define tuiGraphicBox__draw(ncursWin, y0, x0, strFrmt, strName)       \
        mvwprintw(ncursWin, y0, x0, strFrmt, strName)

class tuiGraphicBox_t   {

public:
    tuiGraphicBox_t (box_t *p_pBox);
    tuiGraphicBox_t (uint8_t p_h, uint8_t p_w, uint8_t p_y0, uint8_t p_x0);

    // void plotBox     (void);
    // void frame       (void);
    void draw        (WINDOW* p_pNcursWin);

    uint8_t g_h;
    uint8_t g_w;
    uint8_t g_y0;
    uint8_t g_x0;

private:


};

#endif 	// TUI_GRAPHIC_TYPES_H
