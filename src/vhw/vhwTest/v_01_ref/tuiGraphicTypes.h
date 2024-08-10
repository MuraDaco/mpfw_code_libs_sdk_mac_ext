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
 * tuiGraphicTypes.h
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_TYPES_H
#define TUI_GRAPHIC_TYPES_H

#include <cstdint>

enum class tuiEventCode_t: uint8_t {
     keyDown
    ,keyUp
    ,keyLeft
    ,keyRight
    ,keyEnter
    ,keyHome
    ,mouse
    ,noEvent = 0xff
};

enum class tuiMode_t: uint8_t {
     deselect
    ,select
};

#define tuiEventCodeNum(a) static_cast<uint8_t>(a)

typedef struct __point__ {
    uint8_t x;
    uint8_t y;
} point_t;

typedef struct __dimension__ {
    uint8_t width;
    uint8_t height;
} dimension_t;

typedef struct __box__ {
    // height & width
    uint8_t height;
    uint8_t width;
    // start point
    uint8_t yStart;
    uint8_t xStart;
} box_t;


#endif 	// TUI_GRAPHIC_TYPES_H
