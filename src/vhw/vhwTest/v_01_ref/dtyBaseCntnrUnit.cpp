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

dtyBaseCntnrUnit_t::dtyBaseCntnrUnit_t		(dtyBuffer_t* p_pAry, uint32_t p_arySize)	:
     g_pAry                         {p_pAry         }
    ,g_bufSize                      {static_cast<uint32_t>(p_arySize/sizeof(dtyBuffer_t))  }
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

void dtyBaseCntnrUnit_t::initDisplayBox        (uint8_t p_boxH, uint8_t p_boxW)      {              

    // init display box parametrs
    g_displayBoxH = p_boxH;
    g_displayBoxW = p_boxW;

    // determine the data block that contains the data to display begin
    g_idDisplayHeaderEnd = getBoxPrevHeader(g_idWriteHeaderCurrent);
    g_idDisplayDataEnd   = getBlockDataRowEnd(g_idDisplayHeaderEnd);
    g_idDisplayHeaderBegin = g_idDisplayHeaderEnd;
    g_idDisplayDataBegin  = getBlockDataRowBegin(g_idDisplayHeaderBegin);

    g_debugBlockDataSize = getBlockDataSize(g_idDisplayHeaderBegin);
    uint8_t l_displayRow = 0;
    bool l_continue = true;
    do {
        if(!g_idDisplayHeaderBegin)  {
            l_continue = false;
        }
        l_displayRow +=  getBlockDataSize(g_idDisplayHeaderBegin)/p_boxW;
        l_displayRow += (getBlockDataSize(g_idDisplayHeaderBegin)%p_boxW) ? 1 : 0;
        if(l_displayRow >= p_boxH)  {
            g_idDisplayDataBegin  = getBlockDataRowBegin(g_idDisplayHeaderBegin) + (l_displayRow-p_boxH)*p_boxW;
            break;
        }
        g_idDisplayHeaderBegin = getBoxPrevHeader(g_idDisplayHeaderBegin);     // g_idDisplayHeaderBegin -= HEADER_SIZE;  // setDisplayPrevHeader
    } while(l_continue);
    // all situations must be analyzed
    // 1) g_idDisplayHeaderBegin = 0 && (l_displayRow < p_boxH)
    //      -> it means that box contains all data blocks and has some rows free yet, therefore ...
    //          -> g_idDisplayDataBegin = l_idBlockDataBegin
    // 2) g_idDisplayHeaderBegin = 0 && (l_displayRow = p_boxH)
    //      -> it means that the data to display perfectly matches the data the box can contain
    //          -> g_idDisplayDataBegin = l_idBlockDataBegin
    // 3) g_idDisplayHeaderBegin = 0 && (l_displayRow > p_boxH)
    //      -> it means that the data to display are more than how much the box can contain
    //          -> g_idDisplayDataBegin = l_idBlockDataBegin - (l_displayRow-p_boxH)*p_boxW
    
    // now the data block headers pointers/ids (begin:g_idDisplayHeaderBegin & end:g_idDisplayHeaderEnd) is determined 
    // but it misses to determine the data block pointers/ids (begin:g_idDisplayDataBegin & end:g_idDisplayDataEnd), therefore ...
    //g_idDisplayDataBegin = getBlockDataRowBegin(g_idDisplayHeaderBegin);
    //if(l_displayRow > p_boxH)  {
    //    g_idDisplayDataBegin  = getBlockDataRowBegin(g_idDisplayHeaderBegin) + (l_displayRow-p_boxH)*p_boxW;
    //}
    g_debugDisplayRow = l_displayRow;

}

bool dtyBaseCntnrUnit_t::setDisplayBoxNextRow          (void)      {                                         
    bool l_result = false;
    // check the box end
    if(!bDisplayBoxRowEnd())    {
        l_result = true;
        // check the current data block end
        if(bDisplayBlockDataRowEnd())    {
            // the current pointer/id seeks the last data row of the data block, therefore ...

            // the current header/block data must be updated/incremented before to determine the next data block pointer/id
            g_idDisplayHeaderCurrent    = getBoxNextHeader(g_idDisplayHeaderCurrent);     // g_idDisplayHeaderCurrent    += HEADER_SIZE;
            g_idDisplayDataCurrent      = getBlockDataRowBegin(g_idDisplayHeaderCurrent);
        } else {
            // stay on the current header/block data
            // update only current data pointer/id
            g_idDisplayDataCurrent += g_displayBoxW;
        }
    }
    return l_result;
}

void dtyBaseCntnrUnit_t::getDisplayBoxMoveUp(void) {

    // move "g_idDisplayDataBegin" to high
    if(getBlockDataRowBegin(g_idDisplayHeaderBegin) != g_idDisplayDataBegin)    {

        // stay on the current header/block data
        // update only current data pointer/id
        g_idDisplayDataBegin -= g_displayBoxW;

    } else {
        // the first row of the box is also the first row of the block data, therefore ...

        //  check the block data header position
        if(bBlockDataHeaderBegin(g_idDisplayHeaderBegin)) return;

        // update header and data pointer/id
        g_idDisplayHeaderBegin = getBoxPrevHeader(g_idDisplayHeaderBegin);
        g_idDisplayDataBegin = getBlockDataRowEnd(g_idDisplayHeaderBegin);

    }

    // move "g_idDisplayDataEnd" to high
    if(getBlockDataRowBegin(g_idDisplayHeaderEnd) != g_idDisplayDataEnd)    {

        // stay on the current header/block data
        // update only current data pointer/id
        g_idDisplayDataEnd -= g_displayBoxW;

    } else {
        // the last row of the box is also the first row of the block data, therefore ...

        // update header and data pointer/id
        g_idDisplayHeaderEnd    = getBoxPrevHeader(g_idDisplayHeaderEnd);
        g_idDisplayDataEnd      = getBlockDataRowEnd(g_idDisplayHeaderEnd);
    }

}

void dtyBaseCntnrUnit_t::getDisplayBoxMoveDown(void) {

    // move "g_idDisplayDataEnd" to low
    if(getBlockDataRowEnd(g_idDisplayHeaderEnd) != g_idDisplayDataEnd)    {

        // stay on the current header/block data
        // update only current data pointer/id
        g_idDisplayDataEnd += g_displayBoxW;

    } else {
        // the last row of the box is also the first row of the block data, therefore ...

        //  check the block data header position
        if(bBlockDataHeaderEnd(g_idDisplayHeaderEnd)) return;

        // update header and data pointer/id
        g_idDisplayHeaderEnd    = getBoxNextHeader(g_idDisplayHeaderEnd);
        g_idDisplayDataEnd      = getBlockDataRowBegin(g_idDisplayHeaderEnd);
    }

    // move "g_idDisplayDataBegin" to low
    if(getBlockDataRowEnd(g_idDisplayHeaderBegin) != g_idDisplayDataBegin)    {

        // stay on the current header/block data
        // update only current data pointer/id
        g_idDisplayDataBegin += g_displayBoxW;

    } else {
        // the first row of the box is also the first row of the block data, therefore ...


        // update header and data pointer/id
        g_idDisplayHeaderBegin  = getBoxNextHeader(g_idDisplayHeaderBegin);
        g_idDisplayDataBegin    = getBlockDataRowBegin(g_idDisplayHeaderBegin);

    }


}




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
