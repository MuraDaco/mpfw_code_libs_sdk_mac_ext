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
 * tuiUnitStateInterface.h
 *
 *  Created on: Oct, 22nd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_STATE_INTERFACE_H
#define TUI_UNIT_STATE_INTERFACE_H


class tuiGraphicAbstract_t; // cross dependency -> #include "tuiGraphicAbstract.h"

class tuiUnitStateInterface_t {

public:


    virtual bool select     	    (tuiGraphicAbstract_t* p_this) = 0;
    virtual bool deSelect   	    (tuiGraphicAbstract_t* p_this) = 0;
    virtual void eventOn    	    (tuiGraphicAbstract_t* p_this) = 0;
    virtual bool selectByMouse 	    (tuiGraphicAbstract_t* p_this) = 0;
    virtual bool clickingChild      (tuiGraphicAbstract_t* p_this) = 0;

};

#endif 	// TUI_UNIT_STATE_INTERFACE_H
