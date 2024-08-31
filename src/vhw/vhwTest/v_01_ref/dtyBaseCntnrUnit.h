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
 * dtyBaseCntnrUnit.h
 *
 *  Created on: Aug, 15th 2024
 *      Author: Marco Dau
 */
 
#ifndef DTY_BASE_CNTR_UNIT_H
#define DTY_BASE_CNTR_UNIT_H

#include "uyTypesDefs.h"
#include "dtyTypesDefs.h"


class dtyBaseCntnrUnit_t   {

public:

    enum kMarker_t: int8_t  {
         defaultX = 0x18      // end marker = 0xe8
        ,deviceRx = 0x07      // end marker = 0xf9
        ,deviceTx = 0x06      // end marker = 0xfa
        ,testTx   = 0x15      // end marker = 0xeb
    };

    bool        bEmpty       (void);

    void        initDisplayBox          (uint8_t p_boxH, uint8_t p_boxW);
    void        resetDisplayBox         (void);
    bool        setDisplayBoxNextRow    (void);

    void        getDisplayBoxMoveUp     (void);
    void        getDisplayBoxMoveDown   (void);

    bool        bDisplayBoxRowEnd       (void);

    kMarker_t   getDisplayBlockDataRowMarker    (void);
    uint8_t*    getDisplayBlockDataRow          (void);
    uint8_t     getDisplayBlockDataRowLength    (void);
    bool        bDisplayBlockDataRowBegin       (void);
    bool        bDisplayBlockDataRowEnd         (void);

    uint8_t* g_pBuf;
    dtyBuffer_t* g_pAry;

    uint32_t g_idWriteHeaderCurrent;
    uint32_t g_idWriteDataCurrent;

    uint8_t  g_displayBoxH;
    uint8_t  g_displayBoxW;
    uint32_t g_idDisplayHeaderCurrent;
    uint32_t g_idDisplayHeaderBegin;
    uint32_t g_idDisplayHeaderEnd;
    uint32_t g_idDisplayDataCurrent;
    uint32_t g_idDisplayDataBegin;
    uint32_t g_idDisplayDataEnd;

    uint8_t  g_debugDisplayRow;
    uint16_t g_debugBlockDataSize;

protected:

    // section **** GENERAL ****


    enum kDataType_t: int8_t  {
         ascii
        ,binary
        };


    dtyBaseCntnrUnit_t  (uint8_t* p_pBuf, uint32_t p_bufSize);
    dtyBaseCntnrUnit_t  (dtyBuffer_t* p_pAry, uint32_t p_arySize);

    virtual kMarker_t   getBlockDataMarker      (uint32_t p_idHeader)   = 0;                
    virtual uint32_t    getBlockDataRowBegin    (uint32_t p_idHeader)   = 0;                
            uint32_t    getBlockDataRowEnd      (uint32_t p_idHeader);                      
    virtual uint16_t    getBlockDataSize        (uint32_t p_idHeader)   = 0;                

    virtual bool        bBlockDataHeaderBegin   (uint32_t p_idHeader)  = 0;
    virtual bool        bBlockDataHeaderEnd     (uint32_t p_idHeader)  = 0;
    virtual uint32_t    getBoxPrevHeader        (uint32_t p_pIdHeader) = 0;                 
    virtual uint32_t    getBoxNextHeader        (uint32_t p_pIdHeader) = 0;                 

    uint32_t g_bufSize;

    // section **** WRITE ****
    virtual void      add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             = 0;
    virtual void      add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker)                         = 0;
    virtual void      add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) = 0;

    // section **** DISPLAY *****

    // section **** SELECT ****
    uint32_t g_selectBlockCurrent;
    uint32_t g_selectDataCurrent;

};


#endif 	// DTY_BASE_CNTR_UNIT_H
