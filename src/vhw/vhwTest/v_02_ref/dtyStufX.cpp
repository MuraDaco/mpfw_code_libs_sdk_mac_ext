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
 */
 

#include "dtyStufX.h"

// ****************************************************
// section start **** GENERAL *****

#define MARKER_START_POS        0   // 2-byte
#define DATA_LENGTH_POS         2   // 2-byte
#define DATA_BLOCK_INFO_POS     4   // 2-byte
#define DATA_BLOCK_END_POS      6   // 4-byte
#define DATA_START_POS          6
#define DATA_END___POS          DATA_LENGTH_POS + 1

#define HEADER_MARKER_POS           0
#define HEADER_DATA_LENGTH_POS      2
#define HEADER_INFO_POS             4
#define HEADER_DATA_BEGIN_POS       6
#define HEADER_SIZE                 10

#define DB_HEADER_UNDEFINED         0xFFFFFFFF

#define P_PO_FATHER static_cast<tuiBase_t*>(p_poFather)

dtyStufX_t::dtyStufX_t   (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize) :
     g_pBuf                         {p_pBuf             }
    ,g_bufSize                      {p_bufSize          }
    ,g_dBLoop                       {p_pBuf, p_bufSize  }
    ,g_writeIdHeaderCurrent         {0                  }
    ,g_writeIdDataCurrent           {p_bufSize          }
    ,g_selectIdHeader               {DB_HEADER_UNDEFINED}
    ,g_selectOldIdHeader            {DB_HEADER_UNDEFINED}
{
    uint8_t l_max = p_arrayBufInSize / sizeof(dtyBuffer_t);
    kMarker_t l_marker = kMarker_t::defaultX;
    for(uint8_t l_id=0; l_id < l_max; l_id++)   {
        switch (l_id)   {
            case 0:
                l_marker = kMarker_t::defaultX;
                break;
            case 1:
                l_marker = kMarker_t::deviceRx;
                break;
            case 2:
                l_marker = kMarker_t::deviceTx;
                break;
        };
        add(p_pArrayBufIn[l_id].pBuf, p_pArrayBufIn[l_id].size, l_marker, kDataType_t::binary);
    }
}



// ****************************************************
// section start **** GENERAL *****


void dtyStufX_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize)   {
    add(p_pBufIn, p_bufInSize, kMarker_t::defaultX, kDataType_t::binary);
}

void dtyStufX_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType)   {

    uint8_t* l_pBuf = g_pBuf + g_writeIdHeaderCurrent;
    uint16_t l_bufInSize = kDataType_t::ascii == p_dataType ? p_bufInSize : (p_bufInSize << 1);
    l_pBuf[HEADER_MARKER_POS]           = p_marker;
    l_pBuf[HEADER_MARKER_POS+1]         = p_marker;
    l_pBuf[HEADER_DATA_LENGTH_POS]      = l_bufInSize>>8;
    l_pBuf[HEADER_DATA_LENGTH_POS+1]    = static_cast<uint8_t> (l_bufInSize);
    l_pBuf[HEADER_INFO_POS]             = 0;
    l_pBuf[HEADER_INFO_POS+1]           = 0;
    g_writeIdDataCurrent                -= l_bufInSize;
    l_pBuf[HEADER_DATA_BEGIN_POS  ]     = g_writeIdDataCurrent>>24;
    l_pBuf[HEADER_DATA_BEGIN_POS+1]     = g_writeIdDataCurrent>>16;
    l_pBuf[HEADER_DATA_BEGIN_POS+2]     = g_writeIdDataCurrent>>8;
    l_pBuf[HEADER_DATA_BEGIN_POS+3]     = g_writeIdDataCurrent;

    uint8_t* l_pBufInfo = &l_pBuf[DATA_BLOCK_INFO_POS+1];

    // update header block id/pointer
    g_writeIdHeaderCurrent = getWriteIdHeaderNext(g_writeIdHeaderCurrent);

    // data block

    // set buffer pointer
    l_pBuf = g_pBuf + g_writeIdDataCurrent;
    uint16_t l_cnt = 0;
    bool l_binaryData = false;
    while(l_cnt < p_bufInSize)    {

        switch (p_dataType) {
            case kDataType_t::binary:
                l_pBuf[0] = (*p_pBufIn >> 4) & 0x0F; l_pBuf[0] += (l_pBuf[0] < 0x0A ? 0x30 : 0x37);
                l_pBuf[1] = (*p_pBufIn     ) & 0x0F; l_pBuf[1] += (l_pBuf[1] < 0x0A ? 0x30 : 0x37);
                if(!l_binaryData) {
                    l_binaryData = ((*p_pBufIn < 0x20) || (0x7e < *p_pBufIn));
                    *l_pBufInfo = 1;
                }
                l_pBuf += 2;
                break;
            case kDataType_t::ascii:
                *l_pBuf = *p_pBufIn;
                l_pBuf++;
                break;
        }

        l_cnt++;
        p_pBufIn++;
    }

}

uint32_t dtyStufX_t::getBlockDataIdHeaderPrev    (uint32_t p_idHeader)  {                            
    return (HEADER_SIZE < p_idHeader) ? (p_idHeader - HEADER_SIZE) : 0;
}

uint32_t dtyStufX_t::getWriteIdHeaderNext    (uint32_t p_idHeader)  {         

    return ((p_idHeader + HEADER_SIZE) < g_bufSize) ? p_idHeader + HEADER_SIZE : p_idHeader;
}

uint32_t dtyStufX_t::getBlockDataIdHeaderNext    (uint32_t p_idHeader)  {         

    return ((p_idHeader + HEADER_SIZE) < g_writeIdHeaderCurrent) ? p_idHeader + HEADER_SIZE : p_idHeader;
    // return ((p_idHeader + HEADER_SIZE) < g_writeIdHeaderCurrent) ? p_idHeader + HEADER_SIZE : p_idHeader;
}

dtyStufX_t::kMarker_t dtyStufX_t::getBlockDataMarker  (uint32_t p_idHeader) {                 
    uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_MARKER_POS  ] <<  8) & 0xFF00;
    uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_MARKER_POS+1]      ) & 0x00FF;
    return static_cast<kMarker_t> (l_byteH + l_byteL);
}

uint32_t dtyStufX_t::getBlockIdData  (uint32_t p_idHeader) {                           
    uint32_t l_byteHH = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS  ] << 24) & 0xFF000000;
    uint32_t l_byteH_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+1] << 16) & 0x00FF0000;
    uint32_t l_byteL_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+2] <<  8) & 0x0000FF00;
    uint32_t l_byteLL = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+3]      ) & 0x000000FF;
    return (l_byteHH + l_byteH_ + l_byteL_ + l_byteLL);
}

uint16_t dtyStufX_t::getBlockDataSize   (uint32_t p_idHeader) {                              
    uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS  ] <<  8) & 0xFF00;
    uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS+1]      ) & 0x00FF;
    return (l_byteH + l_byteL);
}


void dtyStufX_t::loopTuiParamSet   (void) {
        // set all parameters to display element
        g_loopY0r       = g_loopRows;
        g_loopMarker    = getBlockDataMarker(g_loopIdHeader);
        g_loopIdData    = getBlockIdData    (g_loopIdHeader);
        g_loopDataSize  = getBlockDataSize  (g_loopIdHeader);
        g_loopH         =   (g_loopDataSize / g_displayBoxW);
        g_loopH         +=  (g_loopDataSize % g_displayBoxW) ? 1 : 0;
        g_loopRows      +=  g_loopH;
        g_loopSelect    = (g_loopIdHeader == g_selectIdHeader);
}

bool dtyStufX_t::loopInit   (uint32_t p_idHeader, int32_t p_y0r) {
    // check header position
    if(g_writeIdHeaderCurrent != p_idHeader) {
        // idHeader is OK
        g_loopIdHeader = p_idHeader;
        g_loopRows = p_y0r;
        loopTuiParamSet();
        return true;
    }

    // the container is empty
    return false;
}

bool dtyStufX_t::loopDisplayBegin   (void) {
    // the loop-DISPLAY reached the begin/top when
    // 1. the first data block of container is seeked; the first data block is the one that idHeader = 0
    // OR
    // 2. the amount of rows of all data block analyzed before (that is g_loopRows) is greater or equal than the dispaly-BOX rows (that is g_displayBoxH)
    return  (
            (0 == g_loopIdHeader)
        ||  (g_loopRows >= g_displayBoxH)
    );
}

bool dtyStufX_t::loopDisplayEnd   (void) {
    // the loop-DISPLAY reached the end/bottom when
    // 1. the next header is equal to the first header to write (that is g_writeIdHeaderCurrent)
    // OR
    // 2. the amount of rows of all data block analyzed before (that is g_loopRows) is greater or equal than the dispaly-BOX rows (that is g_displayBoxH)
    return  (
            (g_loopIdHeader == getBlockDataIdHeaderNext(g_loopIdHeader))
        ||  (g_loopRows >= g_displayBoxH)
    );
}


bool dtyStufX_t::initDisplayBeginParams     (uint32_t p_idHeader)      {

    // check the position of header
    if(loopInit(p_idHeader,0))   {
        // the container is NOT empty, 
        // the display-BEGIN parameters are already set to <p_idHeader> header, therefore ...

        // start the procedure/loop to determine the "dispaly-begin" data block
        // N.B. the "dispaly-BEGIN" data block must be such that 
        //      1. the header of dispaly-END data block is equal to p_idHeader
        //      and
        //      2. the last row of display-BOX contains the last data trunk of dispaly-END data block

        // run loop to determine the display-begin data block
        while (!loopDisplayBegin()){
            g_loopIdHeader    = getBlockDataIdHeaderPrev(g_loopIdHeader);
            loopTuiParamSet();            
        };

        // determine the relative coord to associate to the current loop data block (that is the dispaly-begin data block) that respects the second condition reported above
        //      that is: "2. the last row of display-box contains the last data trunk of dispaly-end data block"
        if(g_displayBoxH > g_loopRows)  {
            // g_loopIdHeader (and so also g_displayBeginIdHeader) is equal to zero, therefore ...
            g_loopY0r = 0;
        } else {
            // N.B.: g_displayBoxH <= g_loopRows so g_loopY0r <= 0
            //       but (g_loopY0r + g_displayBeginH) > 0 because 
            //       (g_loopY0r + g_displayBeginH) = (g_displayBoxH - (g_loopRows - g_displayBeginH)) = (g_displayBoxH - g_loopRows[minus one step]) > 0 
            //       so the display-Begin element will be partially displayed
            g_loopY0r = static_cast<int32_t>(g_displayBoxH - g_loopRows);
        }

        // 1. update the display-BEGIN parameters
        g_displayBeginIdHeader      = g_loopIdHeader;
        g_displayBeginIdData        = g_loopIdData;
        g_displayBeginDataSize      = g_loopDataSize;
        g_displayBeginH             = g_loopH;
        g_displayBeginY0r           = g_loopY0r;

        return true;
    }

    // the container is empty
    return false;
}

void dtyStufX_t::setDisplayBeginParams                (uint32_t p_idHeader, kPosition_t p_position)    {
        if(kPosition_t::bottom == p_position)   {
            initDisplayBeginParams(p_idHeader);
        } else {
            g_loopIdHeader = p_idHeader;
            loopTuiParamSet();

            g_displayBeginIdHeader      = g_loopIdHeader;
            g_displayBeginIdData        = g_loopIdData;
            g_displayBeginDataSize      = g_loopDataSize;
            g_displayBeginH             = g_loopH;
            if(kPosition_t::top                  == p_position)  g_displayBeginY0r = 0;
            if(kPosition_t::topButLastRowOnly    == p_position)  g_displayBeginY0r = 1 - g_loopH;
        }
}

bool dtyStufX_t::bLoopInitDisplay           (uint8_t p_id, void* p_poFather)    {
    bool l_result = false;
    if(p_id)    {
        // run body loop step

        // the container is NOT empty, 
        // the display-BEGIN parameters are already set to <p_idHeader> header, therefore ...

        // start the procedure/loop to determine the "dispaly-begin" data block
        // N.B. the "dispaly-BEGIN" data block must be such that 
        //      1. the header of dispaly-END data block is equal to p_idHeader
        //      and
        //      2. the last row of display-BOX contains the last data trunk of dispaly-END data block

        // run loop to determine the display-begin data block
        if(!loopDisplayBegin()){
            g_loopIdHeader    = getBlockDataIdHeaderPrev(g_loopIdHeader);
            loopTuiParamSet();

            l_result = true;
        } else {
            // determine the relative coord to associate to the current loop data block (that is the dispaly-begin data block) that respects the second condition reported above
            //      that is: "2. the last row of display-box contains the last data trunk of dispaly-end data block"
            if(g_displayBoxH > g_loopRows)  {
                // g_loopIdHeader (and so also g_displayBeginIdHeader) is equal to zero, therefore ...
                g_loopY0r = 0;
            } else {
                // N.B.: g_displayBoxH <= g_loopRows so g_loopY0r <= 0
                //       but (g_loopY0r + g_displayBeginH) > 0 because 
                //       (g_loopY0r + g_displayBeginH) = (g_displayBoxH - (g_loopRows - g_displayBeginH)) = (g_displayBoxH - g_loopRows[minus one step]) > 0 
                //       so the display-Begin element will be partially displayed
                g_loopY0r = static_cast<int32_t>(g_displayBoxH - g_loopRows);
            }

            // 1. update the display-BEGIN parameters
            g_displayBeginIdHeader      = g_loopIdHeader;
            g_displayBeginIdData        = g_loopIdData;
            g_displayBeginDataSize      = g_loopDataSize;
            g_displayBeginH             = g_loopH;
            g_displayBeginY0r           = g_loopY0r;

            // it can be omitted
            l_result = false;
        }

        
    }   else {
        // run the frist loop step (that is init step)
        g_dBLoop.init(p_poFather);

        g_displayBoxH = P_PO_FATHER->getDisplayMaxH();
        g_displayBoxW = P_PO_FATHER->getDisplayMaxW();
        g_selectIdHeader = getBlockDataIdHeaderPrev(g_writeIdHeaderCurrent);

        loopInit(g_selectIdHeader,0);

        l_result = true;
    }
    return l_result;
}

uint8_t dtyStufX_t::getLoopInitCycles       (void)    {
    return 1;
}

void dtyStufX_t::initDisplay                ([[maybe_unused]]uint8_t p_id, void* p_poFather)  {
    g_dBLoop.init(p_poFather);

    g_displayBoxH = P_PO_FATHER->getDisplayMaxH();
    g_displayBoxW = P_PO_FATHER->getDisplayMaxW();

    initDisplayBeginParams(getBlockDataIdHeaderPrev(g_writeIdHeaderCurrent));    
    g_selectIdHeader = getBlockDataIdHeaderPrev(g_writeIdHeaderCurrent);
}


bool dtyStufX_t::resetLoopElement           (void)    {
    return true;
}

bool dtyStufX_t::selectElementByMouse      (void)      {
    if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
        // container is NOT empty, therefore ...

        // start the procedure/loop to display elments of the container
        for(;;) {

            g_dBLoop.displayUpdate(g_loopIdData, g_loopDataSize, g_loopY0r, g_loopH, g_loopSelect, g_loopMarker);

            if(g_dBLoop.bMouseClickInsideBounds()) {
                g_selectIdHeader = g_loopIdHeader;

                // be carefull !!! "bSelectVisibleCompletely" function resets "loop" parameters
                if(bSelectVisibleCompletely())    {
                    // element shift is not necessary
                } else {
                    // be carefull !!! "bSelectVisibleCompletely" function resets "loop" parameters
                    shiftLoopElementBySelect(0);
                }

                dspElement(false);
                // important !!! here you must break the loop because "loop" parameters have been modified by prevoius functions
                return true;
            }

            // check status of the loop
            if(loopDisplayEnd()) break;

            // go to the next element to display
            g_loopIdHeader      = getBlockDataIdHeaderNext(g_loopIdHeader);
            // update tui element parameter
            loopTuiParamSet();
        }

    }

    return false;
}


int32_t dtyStufX_t::getDeltaShiftBySelect                ()    {
    return 0;
}

void dtyStufX_t::shiftLoopElementBySelect                ([[maybe_unused]] int32_t p_delta)    {
    // set display-Element parameters to select-Element parameters
    // and 
    // determine the postion inside the display-BOX of the display-Element
    if(g_selectIdHeader <= g_displayBeginIdHeader)   {
        // select-Element is located higher than display-BOX
        // shift it to Upper of the display-BOX, therefore ...
        // select-Element is equal to displayBegin-element
        setDisplayBeginParams(g_selectIdHeader, kPosition_t::top);
    } else {
        // N.B.: when the current function is called it means that the selected element is not completely visible (see bSelectVisibleCompletely() function) and
        //      therefore here the select-Element is ncessarily located under the display-BOX
        // shift it to Bottom of the display-BOX, therefore ...
        // select-Element is different than displayBegin-element
        setDisplayBeginParams(g_selectIdHeader, kPosition_t::bottom);
    }

}

void dtyStufX_t::updSelectElement                (void)    {
}

void dtyStufX_t::clearDisplayBox       (void)    {
}

bool dtyStufX_t::bDisplayLastRowVsLowerBound           (void)    {
    // 
    if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
        // container is NOT empty, therefore ...

        // start the procedure/loop to display elments of the container
        for(;;) {

            g_dBLoop.displayUpdate(g_loopIdData, g_loopDataSize, g_loopY0r, g_loopH, g_loopSelect, g_loopMarker);

            // check status of the loop
            if(loopDisplayEnd()) break;

            // go to the next element to display
            g_loopIdHeader      = getBlockDataIdHeaderNext(g_loopIdHeader);
            // update tui element parameter
            loopTuiParamSet();
        }

        return ((g_loopIdHeader == getBlockDataIdHeaderNext(g_loopIdHeader)) && (g_loopRows <= g_displayBoxH));

    }
    return false;
}


bool dtyStufX_t::updCntnrRelCoord           ([[maybe_unused]]int32_t p_delta)    {
    return true;
}

void dtyStufX_t::shiftLoopElementRollUp           (void)    {

    if(!bDisplayLastRowVsLowerBound())   {
        // shift up the current display-begin element
        g_displayBeginY0r--;
        // check the status of the current display-begin element
        if(0 < static_cast<int32_t>(g_displayBeginY0r+g_displayBeginH))   {
            // at least one row of the current display-begin element is visible, therefore ...
            // dispaly-begin data block remains the same
        } else {
            // no rows of the current display-begin element is visible, they are all higher than the display-box, therefore ...
            // dispaly-begin data block must be updated to the next element/data block
            uint32_t l_idHeader = getBlockDataIdHeaderNext(g_displayBeginIdHeader);
            if(l_idHeader != g_displayBeginIdHeader)    {
                g_displayBeginIdHeader    = l_idHeader;

                // the new data block  (that is display-begin element) is located at the top of display-box
                setDisplayBeginParams(g_displayBeginIdHeader, kPosition_t::top);
            } else {
                g_displayBeginY0r++;
            }
        }

    }

}

void dtyStufX_t::shiftLoopElementRollDown           (void)    {

    // shift down the current display-begin element
    g_displayBeginY0r++;
    // check the status of the current display-begin element
    if(g_displayBeginY0r <= 0)   {
        // the first row of the current display-begin element is still negative so 
        // the first row of the display-BOX belongs to the current display-begin element, therefore ...
        // dispaly-begin data block remains the same
    } else {
        // the first row of the current display-begin element is equal to 1 or greater so
        // the first row of the display-BOX does not belong to the current display-begin element, therefore ...
        // dispaly-begin data block must be updated to the previous one
        uint32_t l_idHeader = getBlockDataIdHeaderPrev(g_displayBeginIdHeader);
        if(l_idHeader != g_displayBeginIdHeader)    {
            g_displayBeginIdHeader    = l_idHeader;

            // the new data block  (that is display-begin element) is located at the top of display-box but only the its last row can be displayed
            setDisplayBeginParams(g_displayBeginIdHeader, kPosition_t::topButLastRowOnly);
        } else {
            g_displayBeginY0r--;
        }

    }

}

void dtyStufX_t::updElementCoordNbounds       (void)    {
    // the display-BOX (that is the display-BOX of the owner of the current container) has been modified, so
    // the initialization params of tui element associate to container data block must be done
    g_dBLoop.updCoordNboundsForNewFather();

    // N.B.: the relative coords of display-BEGIN element (that is, the data block begin) remain the same, therefore ...
    // do not other things

    // N.B.: in this class the g_dBLoop.updCoordNbounds() function is not used because 
}

void dtyStufX_t::dspElement                   ([[maybe_unused]] bool p_recursively)  {

    if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
        // container is NOT empty, therefore ...

        // start the procedure/loop to display elments of the container
        for(;;) {
            // init tui element
            g_dBLoop.displayUpdate(g_loopIdData, g_loopDataSize, g_loopY0r, g_loopH, g_loopSelect, g_loopMarker);
            // display tui element
            g_dBLoop.display();

            // display tui element
            //g_dBLoop.displayDebug(g_loopDataSize, g_loopRows);

            // check status of the loop
            if(loopDisplayEnd()) break;

            // go to the next element to display
            g_loopIdHeader      = getBlockDataIdHeaderNext(g_loopIdHeader);
            // update tui element parameter
            loopTuiParamSet();
        }
    } else {
        // display tui element
        g_dBLoop.displayDebug(g_writeIdHeaderCurrent, g_displayBeginIdHeader);
    }

}

bool dtyStufX_t::nextLoopElement              (void)    {
    return false;
}



// section end   **** GENERAL ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** SELECT *****

bool dtyStufX_t::setSelectPrev                  (void)    {
    
    uint32_t l_idHeader = getBlockDataIdHeaderPrev(g_selectIdHeader);    
    // N.B.:  (l_idHeader == g_selectIdHeader) means that the select element is the first one
    bool l_result = (l_idHeader != g_selectIdHeader);
    if(l_result)    {
        g_selectOldIdHeader = g_selectIdHeader;
        g_selectIdHeader    = l_idHeader;
    }
    return true;
}

bool dtyStufX_t::setSelectNext                  (void)    {

    uint32_t l_idHeader = getBlockDataIdHeaderNext(g_selectIdHeader);
    // N.B.:  (l_idHeader == g_selectIdHeader) means that the select element is the last one
    bool l_result = (l_idHeader != g_selectIdHeader);
    if(l_result)    {
        g_selectOldIdHeader = g_selectIdHeader;
        g_selectIdHeader    = l_idHeader;
    }
    return true;
}


bool dtyStufX_t::bSelectVisibleCompletely     (void)      {
    bool l_result = false;
    if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
        for(;;) {
            // init tui element
            if(g_loopSelect) {
                if(
                        (0 <= g_loopY0r)
                    &&  (     g_loopY0r + g_loopH <= g_displayBoxH)
                )
                {
                    l_result = true;
                    // exit from loop
                    break;
                }
            }

            // check status of the loop
            if(loopDisplayEnd()) break;

            // go to the next element to display
            g_loopIdHeader      = getBlockDataIdHeaderNext(g_loopIdHeader);
            // update tui element parameter
            loopTuiParamSet();
        }
    }

    return l_result;
}



// section end   **** SELECT ***** 
// ****************************************************
