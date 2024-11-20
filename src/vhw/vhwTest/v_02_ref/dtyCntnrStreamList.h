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
 * dtyCntnrStreamList.h
 *
 *  Created on: Nov, 10th 2024
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
 
#ifndef DTY_CNTNR_STREAM_LIST_H
#define DTY_CNTNR_STREAM_LIST_H

#include <cstdint>
#include "tuiUnitFormattedStringCntnr.h"
#include "tuiGraphicUnitBase.h"
#include "dtyBuffer.h"
#include "dtyString.h"
#include "dtyStringInfo.h"
#include "dtyBaseCntnrUnitX.h"
#include "dtyProtocolDataTypesDefs.h"

class dtyCntnrStreamList_t : public dtyBaseCntnrUnitX_t, public dtyProtocolDataTypesDefs_t  {

// ****************************************************
// section start **** CONBSTRUCTOR *****
    public:

    dtyCntnrStreamList_t  (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize);

    // section end   **** CONBSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DATA MANAGEMENT: READ/WRITE *****

    // sub-section ** READ **
    private:
    uint32_t    getBlockDataIdHeaderPrev        (uint32_t p_idHeader);
    uint32_t    getBlockDataIdHeaderNext        (uint32_t p_idHeader);
    uint32_t    getBlockDataId                  (uint32_t p_idHeader);
    uint16_t    getBlockDataSize                (uint32_t p_idHeader);
    kMarker_t   getBlockDataMarker              (uint32_t p_idHeader);

    // sub-section ** WRITE **
    public:
    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             ;
    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) ;

    private:
    uint32_t    getWriteHeaderIdNext            (uint32_t p_idHeader);

    uint8_t*    g_pBuf;
    uint32_t    g_bufSize;

    uint32_t g_writeHeaderIdCurrent;
    uint32_t g_writeDataIdCurrent;


    // section end   **** DATA MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** LOOP MANAGEMENT *****
    private:

    dtyString_t                     g_loopPString;
    dtyStringInfo_t                 g_loopPStringInfo;
    tuiGraphicUnitBase_t            g_loopTuiGraphic;           // it can be defined as static; it is a temporary variable BUT to make it static you MUST remember to call init procedure every time you start to use it
    tuiUnitFormattedStringCntnr_t   g_loopTuiUnit;              // it can be defined as static; it is a temporary variable BUT to make it static you MUST remember to update its g_pBuf & g_bufSize paramters every time you start to use it
    uint32_t    g_loopIdHeader;     // it can be defined as static; it is a temporary variable
    uint32_t    g_loopIdData;       // it can be defined as static; it is a temporary variable
    uint32_t    g_loopDataSize;     // it can be defined as static; it is a temporary variable
    int32_t     g_loopY0r;          // it can be defined as static; it is a temporary variable
    uint32_t    g_loopH;            // it can be defined as static; it is a temporary variable
    kMarker_t   g_loopMarker;       // it can be defined as static; it is a temporary variable
    bool        g_loopSelect;       // it can be defined as static; it is a temporary variable
    int32_t     g_loopRows;         // it can be defined as static; it is a temporary variable

    private:
    // virtual override
    uint8_t getLoopInitCycles               (void)  override;
    bool    resetLoopElement                (void)  override;
    bool    nextLoopElement                 (void)  override;
    
    void    loopTuiParamSet                 (void);
    bool    loopInit                        (uint32_t p_idHeader, int32_t p_y0r);
    bool    loopDisplayBegin                (void);
    bool    loopDisplayEnd                  (void);

    // section end   **** LOOP MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****
    private:

    enum kPosition_t: int8_t  {
         top
        ,topButLastRowOnly
        ,bottom
        };

    bool    updCntnrRelCoord                (int32_t p_delta)  override;
    void    updElementCoordNbounds          (void)  override;

    // bool    bLoopInitDisplay                (uint8_t p_id, void* p_pParent)    override;
    void    initDisplay                     (uint8_t p_id, void* p_pParent)    override;
    void    clearDisplayBox                 (void)  override;
    void    dspElement                      ([[maybe_unused]] bool p_recursively)   override; // test

    bool initDisplayBeginParams             (uint32_t p_idHeader);
    void setDisplayBeginParams              (uint32_t p_idHeader, kPosition_t p_position);
    bool bDisplayLastRowVsLowerBound        (void);

    uint8_t  g_displayBoxH;
    uint8_t  g_displayBoxW;

    uint32_t g_displayBeginIdHeader;
    uint32_t g_displayBeginIdData;
    uint32_t g_displayBeginDataSize;
    int32_t  g_displayBeginY0r;
    uint32_t g_displayBeginH;

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INPUT EVENTS: SELECTION & MOUSE ROLL *****

    private:
    // roll
    void    shiftLoopElementRollUp          (void)  override; // test
    void    shiftLoopElementRollDown        (void)  override; // test
    // select
    bool    selectElementByMouse            (void) override;
    void    shiftLoopElementBySelect        (int32_t p_delta)  override;
    int32_t getDeltaShiftBySelect           (void) override;
    void    updSelectElement                (void) override;
    bool    setSelectPrev                   (void) override;
    bool    setSelectNext                   (void) override;
    bool    bSelectVisibleCompletely        (void) override;

    uint32_t g_selectHeaderId;
    uint32_t g_selectHeaderIdOld;

    //tuiGraphicUnitBase_t    g_selectTuiGraphic;
    //tuiUnitProtocolData_t   g_selectTuiUnit;

    // section end   **** INPUT EVENTS: SELECTION & MOUSE ROLL ***** 
    // ****************************************************


};


#endif 	// DTY_PROTOCOL_DATA_H
