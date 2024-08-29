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


class dtyBaseCntnrUnit_t   {

public:

    enum kMarker_t: int8_t  {
         defaultX = 0x18      // end marker = 0xe8
        ,deviceRx = 0x07      // end marker = 0xf9
        ,deviceTx = 0x06      // end marker = 0xfa
        ,testTx   = 0x15      // end marker = 0xeb
    };

    virtual void        initDisplayBox          (uint8_t p_boxH, uint8_t p_boxW)  = 0;      
    void        resetDisplayBox                (void);                                      
    bool        bDisplayBoxRowEnd              (void);                                      
    virtual bool        setDisplayBoxNextRow    (void)  = 0;                                       

    kMarker_t   getDisplayBlockDataRowMarker    (void);                                     
    uint8_t*    getDisplayBlockDataRow          (void);                                     
    uint8_t     getDisplayBlockDataRowLength    (void);                                     
    bool        bDisplayBlockDataRowBegin       (void);                                     
    bool        bDisplayBlockDataRowEnd         (void);                                     

    uint8_t* g_pBuf;

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

    virtual kMarker_t   getBlockDataMarker      (uint32_t p_idHeader)   = 0;                
    virtual uint32_t    getBlockDataRowBegin    (uint32_t p_idHeader)   = 0;                
            uint32_t    getBlockDataRowEnd      (uint32_t p_idHeader);                      
    virtual uint16_t    getBlockDataSize        (uint32_t p_idHeader)   = 0;                

    //uint8_t* g_pBuf;
    uint32_t g_bufSize;

    // section **** WRITE ****
    virtual void      add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             = 0;
    virtual void      add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker)                         = 0;
    virtual void      add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) = 0;
    //uint32_t g_idWriteHeaderCurrent;
    //uint32_t g_idWriteDataCurrent;

    // section **** DISPLAY *****
    virtual uint32_t    getDisplayBoxPrevHeader (uint32_t p_pIdHeader) = 0;                 
    virtual uint32_t    getDisplayBoxNextHeader (uint32_t p_pIdHeader) = 0;                 




//    uint8_t  g_displayBoxH;
//    uint8_t  g_displayBoxW;
//    uint32_t g_idDisplayHeaderCurrent;
//    uint32_t g_idDisplayHeaderBegin;
//    uint32_t g_idDisplayHeaderEnd;
//    uint32_t g_idDisplayDataCurrent;
//    uint32_t g_idDisplayDataBegin;
//    uint32_t g_idDisplayDataEnd;

    //virtual uint8_t*    getDisplayStrBuf        (void)  = 0;
    //virtual bool        bDisplayStrBufBegin     (void)  = 0;
    //virtual bool        bDisplaySelected        (void)  = 0;
    //virtual void        setDisplayNext          (void)  = 0;
    //virtual void        setDisplayNextHeader    (void)  = 0;
    //virtual void        setDisplayPrev          (void)  = 0;




    // section **** SELECT ****
    uint32_t g_selectBlockCurrent;
    uint32_t g_selectDataCurrent;


    // old 

//	virtual void	  vDel		                (char*)	{}
//	virtual void	  vUp                       (void)	{}
//	virtual void	  vDown		                (void)	{}
//	virtual void	  vRight		            (void)	{}
//	virtual void	  vLeft		                (void)	{}
//	virtual void	  vConfirm	                (void)	{}
//	virtual void	  vSelected	                (void)	{}
//	virtual void	  vUpdateInit	            (void)	{}
//	virtual void	  vSearchFirst              (void)	{}
//	virtual void	  vSearchNext		        (void)	{}
//	virtual void	  vSearchPrev		        (void)	{}
//	virtual bool	  bSearchLast  		        (void)	{return true;}
//	virtual bool	  bDisplayable    	        (void)	{return true;}
//
//    uint32_t g_idDisplayHeaderCurr;   // absolute id buffer element currently displyed  -- g_pDisplayOrigin <= g_pDisplayCurr <= (g_pDisplayOrigin + g_inBoxSizeInRow*g_inBoxRowSize)
//    uint32_t g_idDisplayCurr;         // absolute id buffer element currently displyed  -- g_pDisplayOrigin <= g_pDisplayCurr <= (g_pDisplayOrigin + g_inBoxSizeInRow*g_inBoxRowSize)
//    uint32_t g_idDisplayOrigin;       // absolute id buffer element at the begin of box 
//    uint8_t  g_inBoxSizeByRow;      // (rows number)
//    uint8_t  g_inBoxRowSize;        // (row size)
//    uint8_t  g_idRowSelected;  
//
//    uint32_t g_idDisplayBlockBeginCurr;
//    uint32_t g_idDisplayBlockSizeCurr;
//    uint32_t g_idDisplayHeaderBlockCurr;
//    uint8_t  g_headerSize;
//
//    uint8_t* g_pBufCur;
//
//    uint8_t* g_pBufOrigin;
//    uint8_t* g_pBufHeaderCur;
//    uint8_t* g_pBufBlockDataCur;
//    uint8_t* g_pBufSearch;
//    uint8_t g_rowSize;


};


#endif 	// DTY_BASE_CNTR_UNIT_H
