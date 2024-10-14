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
 * dtyStufX.h
 *
 *  Created on: Sep, 25th 2024
 *      Author: Marco Dau
 *

    Format description:
    
    01234567890 ....
    mmlliiddd....................dddllnn
          |__lenght of data block__|

    m = begin marker
    l = length of data block
    d = data (hex-ascii coded)
    i = info data block (i.e. text data block / binary data block )
    n = end marker
    m + n = 0
  
    LF = 0x0a
    CR = 0x0d
    '0'...'9''A'...'F'
    x30...x39x41...x46

 */
 
#ifndef DTY_STUF_X_H
#define DTY_STUF_X_H

#include <cstdint>
#include "tuiData.h"
#include "dtyBaseCntnrUnitX.h"
#include "dtyStufXTypesDefs.h"

class dtyStufX_t : public dtyBaseCntnrUnitX_t, public dtyStufXTypesDefs_t  {

public:
    // ****************************************************
    // section start **** GENERAL *****

    enum kPosition_t: int8_t  {
         top
        ,topButLastRowOnly
        ,bottom
        };


    dtyStufX_t  (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize);

    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             ;
    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) ;

    uint8_t getLoopInitCycles       (void)  override;
    bool bLoopInitDisplay           (uint8_t p_id, void* p_poFather)    override;
    void initDisplay                (uint8_t p_id, void* p_poFather)    override;
    void    initDisplay                     (void* p_poFather)  override;
    bool    resetLoopElement                (void)  override;
    bool    selectElementByMouse            (void)  override;
    void    shiftLoopElementBySelect        (void)  override;
    void    shiftLoopElementRollUp          (void)  override;
    void    shiftLoopElementRollDown        (void)  override;
    void    updElementCoordNbounds          (void)  override;
    void    dspElement                      ([[maybe_unused]] bool p_recursively)   override;
    bool    nextLoopElement                 (void)  override;


    uint8_t*    g_pBuf;
    uint32_t    g_bufSize;

    tuiData_t   g_dBLoop;           // it can be defined as static; it is a temporary variable BUT to make it static you MUST remember to update its g_pBuf & g_bufSize paramters every time you use it
    uint32_t    g_loopIdHeader;     // it can be defined as static; it is a temporary variable
    uint32_t    g_loopIdData;       // it can be defined as static; it is a temporary variable
    uint32_t    g_loopDataSize;     // it can be defined as static; it is a temporary variable
    int32_t     g_loopY0r;          // it can be defined as static; it is a temporary variable
    uint32_t    g_loopH;            // it can be defined as static; it is a temporary variable
    kMarker_t   g_loopMarker;       // it can be defined as static; it is a temporary variable
    bool        g_loopSelect;       // it can be defined as static; it is a temporary variable
    int32_t     g_loopRows;         // it can be defined as static; it is a temporary variable


    // section end   **** GENERAL ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****

    uint32_t g_writeIdHeaderCurrent;
    uint32_t g_writeIdDataCurrent;

    // section end   **** WRITE ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** DISPLAY *****

    uint8_t  g_displayBoxH;
    uint8_t  g_displayBoxW;

    uint32_t g_displayBeginIdHeader;
    uint32_t g_displayBeginIdData;
    uint32_t g_displayBeginDataSize;
    int32_t  g_displayBeginY0r;
    uint32_t g_displayBeginH;
    kMarker_t  g_displayBeginMarker;

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****

    bool setSelectPrev                  (void) override;
    bool setSelectNext                  (void) override;
    bool bSelectVisibleCompletely       (void) override;

    uint32_t g_selectIdHeader;
    uint32_t g_selectIdData;

    uint32_t g_selectOldIdHeader;
    uint32_t g_selectOldIdData;

    // section end   **** SELECT ***** 
    // ****************************************************

private:

    // ****************************************************
    // section start **** GENERAL *****

    
    uint32_t    getWriteIdHeaderNext            (uint32_t p_idHeader);
    uint32_t    getBlockDataIdHeaderPrev        (uint32_t p_idHeader);
    uint32_t    getBlockDataIdHeaderNext        (uint32_t p_idHeader);
    uint32_t    getBlockIdData                  (uint32_t p_idHeader);
    uint16_t    getBlockDataSize                (uint32_t p_idHeader);
    kMarker_t   getBlockDataMarker              (uint32_t p_idHeader);

    bool bDisplayLastRowVsLowerBound           (void);

    void        loopTuiParamSet                 (void);
    bool        loopInit                        (uint32_t p_idHeader, int32_t p_y0r);
    bool        loopDisplayBegin                (void);
    bool        loopDisplayEnd                  (void);


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

    bool        initDisplayBeginParams          (uint32_t p_idHeader);
    void        setDisplayBeginParams           (uint32_t p_idHeader, kPosition_t p_position);

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****


    // section end   **** SELECT ***** 
    // ****************************************************


};


#endif 	// DTY_STUF_X_H
