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
 * pphMacroDefine.h
 *
 *  Created on: Jul, 28 2024
 *      Author: Marco Dau
 */


#ifndef PPH_MACRO_DEFINE_H
#define PPH_MACRO_DEFINE_H


// use to export the [pph] module/class instances
#define PPH_DEF_H__(type_t, name)            MCU_##name type_t                 pph_##name;
// use to define the [pph] module/class instances in [app] module
#define PPH_DEF_CPP(type_t, name)                               \
            type_t pph_##name  (                                \
                {MCU_##name##_PORT_PTR, MCU_##name##_PIN }      \
            );
// use to define the [pph] module/class instances in [app] module
#define PPH_DEF_CPP_LINK(type_t, name, id1, id2)                                            \
            type_t pph_##name    (                                                          \
                #name,                                                                      \
                {id1, MCU_##id1##_##name##_dout_PORT_PTR, MCU_##id1##_##name##_dout_PIN },  \
                {id2, MCU_##id2##_##name##_din_PORT_PTR,  MCU_##id2##_##name##_din_PIN  }   \
            );
// used by [pph] module [manager]
#define PPH_OBJ(name)                                                        pph_##name

// used by [tui] component module
//#define PPH_DATA_TYPE_PTR(name)  &pph_##name.g_dtyStatus
//#define PPH_DATA_TYPE_PTR(name) &pph_##name.g_dtyStatus, &pph_##name.g_pinPort2.g_dtyStatus


#endif 	// PPH_MACRO_DEFINE_H
