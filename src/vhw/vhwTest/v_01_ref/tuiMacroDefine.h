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
 * tuiMacroDefine.h
 *
 *  Created on: Jul, 28th 2024
 *      Author: Marco Dau
 */
 


#ifndef TUI_MACRO_DEFINE_H
#define TUI_MACRO_DEFINE_H

#include "pphMacroDefine.h"

#define TUI_DEF_CPP(tui_t, pph_t, name, x, y)          MCU_##name tui_t  tui_##name (#name, {x, y}, pph_t##_DATA_TYPE_PTRS(name));
#define TUI_OBJ(name)                       tui_##name

#endif 	// TUI_MACRO_DEFINE_H
