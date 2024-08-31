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
 * dtyArray.cpp
 *
 *  Created on: Aug, 29th 2024
 *      Author: Marco Dau
 */
 

#include "dtyArray.h"

// ****************************************************
// section start **** GENERAL *****

dtyArray_t::kMarker_t   dtyArray_t::getBlockDataMarker     ([[maybe_unused]] uint32_t p_idHeader)    {return kMarker_t::defaultX;}
uint32_t    dtyArray_t::getBlockDataRowBegin   ([[maybe_unused]] uint32_t p_idHeader)    {return 0;}
uint16_t    dtyArray_t::getBlockDataSize       ([[maybe_unused]] uint32_t p_idHeader)    {return 0;}

// section end   **** DISPLAY ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** WRITE *****

void        dtyArray_t::add             ([[maybe_unused]] uint8_t* p_pBufIn, [[maybe_unused]] uint16_t p_bufInSize)   {}
void        dtyArray_t::add             ([[maybe_unused]] uint8_t* p_pBufIn, [[maybe_unused]] uint16_t p_bufInSize, [[maybe_unused]] kMarker_t p_marker)   {}
void        dtyArray_t::add             ([[maybe_unused]] uint8_t* p_pBufIn, [[maybe_unused]] uint16_t p_bufInSize, [[maybe_unused]] kMarker_t p_marker, [[maybe_unused]] kDataType_t p_dataType)   {}

// section end   **** WRITE ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** DISPLAY *****

uint32_t    dtyArray_t::getBoxPrevHeader     ([[maybe_unused]] uint32_t p_pIdHeader) {return 0;}
uint32_t    dtyArray_t::getBoxNextHeader     ([[maybe_unused]] uint32_t p_pIdHeader) {return 0;}

// section end   **** DISPLAY ***** 
// ****************************************************
