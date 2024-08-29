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
 * dtyBaseCntnrUnit.cpp
 *
 *  Created on: Aug, 15th 2024
 *      Author: Marco Dau
 */
 

#include "dtyBaseCntnrUnit.h"

// ****************************************************
// section start **** GENERAL *****


dtyBaseCntnrUnit_t::dtyBaseCntnrUnit_t		(uint8_t* p_pBuf, uint32_t p_bufSize)	:
     g_pBuf                         {p_pBuf         }
    ,g_bufSize                      {p_bufSize      }
    ,g_idWriteHeaderCurrent         {0              }
    ,g_idWriteDataCurrent           {p_bufSize      }
    ,g_idDisplayHeaderCurrent       {0              }
    ,g_idDisplayHeaderBegin         {0              }
    ,g_idDisplayHeaderEnd           {0              }
    ,g_idDisplayDataCurrent         {p_bufSize      }
    ,g_idDisplayDataBegin           {p_bufSize      }
    ,g_idDisplayDataEnd             {p_bufSize      }
{}

uint32_t dtyBaseCntnrUnit_t::getBlockDataRowEnd    (uint32_t p_idHeader)   {                        
    uint8_t  l_dataRowsNum  = getBlockDataSize    (p_idHeader) / g_displayBoxW;
    uint32_t l_dataRowEnd   = getBlockDataRowBegin(p_idHeader) + g_displayBoxW*l_dataRowsNum;
    return l_dataRowEnd;
}

// section end   **** GENERAL ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** WRITE *****

// section end   **** WRITE ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** DISPLAY *****

dtyBaseCntnrUnit_t::kMarker_t   dtyBaseCntnrUnit_t::getDisplayBlockDataRowMarker        (void)  {   
    return getBlockDataMarker(g_idDisplayHeaderCurrent);
}

uint8_t* dtyBaseCntnrUnit_t::getDisplayBlockDataRow     (void)      {                               
    return &g_pBuf[g_idDisplayDataCurrent];
}

uint8_t dtyBaseCntnrUnit_t::getDisplayBlockDataRowLength    (void)      {                           
    uint8_t l_rowLength = getBlockDataRowBegin(g_idDisplayHeaderCurrent) + getBlockDataSize(g_idDisplayHeaderCurrent) - g_idDisplayDataCurrent;
    if(l_rowLength > g_displayBoxW) {
        l_rowLength = g_displayBoxW;
    }
    return l_rowLength;
}

void dtyBaseCntnrUnit_t::resetDisplayBox      (void)      {                                         
    g_idDisplayDataCurrent      = g_idDisplayDataBegin;
    g_idDisplayHeaderCurrent    = g_idDisplayHeaderBegin;
}

bool dtyBaseCntnrUnit_t::bDisplayBoxRowEnd      (void)   {                                          
    return (g_idDisplayDataCurrent == g_idDisplayDataEnd);
}

bool dtyBaseCntnrUnit_t::bDisplayBlockDataRowBegin          (void)   {                              
    return (g_idDisplayDataCurrent == getBlockDataRowBegin(g_idDisplayHeaderCurrent));
}

bool dtyBaseCntnrUnit_t::bDisplayBlockDataRowEnd            (void)   {                              
    return (g_idDisplayDataCurrent == getBlockDataRowEnd(g_idDisplayHeaderCurrent));
}

/*
DisplayBoxRowBegin
DisplayBoxRowEnd
DisplayBlockDataRowBegin    -> BlockDataRowBegin
DisplayBlockDataRowEnd      -> BlockDataRowEnd      -> depends on g_displayBoxW

setBlockDataRowEnd  (p_idHeader)    -> non esiste e forse non ha neppure motivo di esserlo
getBlockDataRowEnd  (p_idHeader)    -> fornisce l ultima riga (avendo come riferimento g_displayBoxW)
bBlockDataRowEnd    (p_idHeader)    -> al momento non esiste

getDisplayBoxRowBegin   -> = g_idDisplayDataBegin


*/

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

//    void vInBoxPrev         ();
//

//dtyBaseCntnrUnit_t::kMarker_t  dtyBaseCntnrUnit_t::getInBlockMarker       (void)      {
//    return; g_pBuf[g_idInBoxHeaderCurr];
//}
//
//uint8_t* dtyBaseCntnrUnit_t::getInBlockStrBuf       ()      {
//
//}

//    bool     bInBlockFirstRow               ();
//    bool     bInBlockSelected               ();
