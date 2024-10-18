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
 * tuiBaseListElem.h
 *
 *  Created on: Aug, 13th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_LIST_ELEM_H
#define TUI_BASE_LIST_ELEM_H

#include "tuiBase.h"

class tuiBaseListElem_t {

public:

    tuiBaseListElem_t      (tuiBase_t*	p_pUnit,   uint8_t p_flag);

    tuiBase_t*	g_pUnit;
    uint16_t g_id;
    uint8_t  g_flag;


};


#endif 	// TUI_BASE_LIST_ELEM_H
