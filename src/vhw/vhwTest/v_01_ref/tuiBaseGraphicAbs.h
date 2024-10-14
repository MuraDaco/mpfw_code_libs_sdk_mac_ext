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
 * tuiBaseGraphicAbs.h
 *
 *  Created on: Oct, 11th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_GRAPHIC_ABS_H
#define TUI_BASE_GRAPHIC_ABS_H

#include "tuiGraphicTypes.h"

class tuiBaseGraphicAbs_t   {

public:

    // element
    // - bounds
    virtual int16_t     getBoundXleft           (void) = 0;
    virtual int16_t     getBoundXRight          (void) = 0;
    virtual int16_t     getBoundYUpper          (void) = 0;
    virtual int16_t     getBoundYLower          (void) = 0;


    // display box
    // - display box dimensions
    virtual uint16_t    getDspBoxDimW           (void) = 0;
    virtual uint16_t    getDspBoxDimH           (void) = 0;

    // - display box absolute coordinates
    virtual uint16_t    getDspBoxAbsolutRefX    (void) = 0;
    virtual uint16_t    getDspBoxAbsolutRefY    (void) = 0;

    // mouse
    virtual uint16_t    getMouseAbsolutRefX     (void) = 0;
    virtual uint16_t    getMouseAbsolutRefY     (void) = 0;

};

#endif 	// TUI_BASE_GRAPHIC_ABS_H
