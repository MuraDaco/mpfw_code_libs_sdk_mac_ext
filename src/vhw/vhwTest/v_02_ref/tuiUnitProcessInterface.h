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
 * tuiUnitProcessInterface.h
 *
 *  Created on: Oct, 24th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_PROCESS_INTERFACE_H
#define TUI_UNIT_PROCESS_INTERFACE_H

class tuiGraphicUnit_t; // cross or derived element dependency

class tuiUnitProcessInterface_t {

public:


    virtual bool init   	    (tuiGraphicUnit_t* p_pParent) = 0;
    virtual bool initChildren   (tuiGraphicUnit_t* p_pParent) = 0;
    virtual bool loop   	    (tuiGraphicUnit_t* p_pParent) = 0;
    virtual bool loopChildren   (tuiGraphicUnit_t* p_pParent) = 0;
    virtual void end       	    (tuiGraphicUnit_t* p_pParent) = 0;
    virtual void endChildren    (tuiGraphicUnit_t* p_pParent) = 0;

};

#endif 	// TUI_UNIT_PROCESS_INTERFACE_H
