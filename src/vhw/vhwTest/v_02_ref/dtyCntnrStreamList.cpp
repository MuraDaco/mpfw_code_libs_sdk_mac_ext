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
 * dtyCntnrStreamList.cpp
 *
 *  Created on: Nov, 10th 2024
 *      Author: Marco Dau
 */

// debug 
#include <iostream>
#include <stdexcept>

#include "dtyCntnrStreamList.h"


// ****************************************************
// section start **** CONSTRUCTOR *****

    #define DB_HEADER_UNDEFINED         0xFFFFFFFF

    dtyCntnrStreamList_t::dtyCntnrStreamList_t   (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize, tuiUnitAbstract_t*  p_loopPTuiUnit, tuiGraphicAbstract_t*  p_loopPTuiGraphic) :
    // section - DATA MANAGEMENT
         g_pBuf                         {p_pBuf             }
        ,g_bufSize                      {p_bufSize          }
        ,g_writeHeaderIdCurrent         {0                  }
        ,g_writeDataIdCurrent           {p_bufSize          }
    // section - LOOP MANAGEMENT
        ,g_loopPTuiUnit                 {p_loopPTuiUnit}
        ,g_loopPTuiGraphic               {p_loopPTuiGraphic}
    // section - SELECT
        ,g_selectHeaderId               {DB_HEADER_UNDEFINED}
        ,g_selectHeaderIdOld            {DB_HEADER_UNDEFINED}
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

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

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


    // READ section
    // private:
    // uint32_t    getBlockDataIdHeaderPrev        (uint32_t p_idHeader);
    uint32_t dtyCntnrStreamList_t::getBlockDataIdHeaderPrev    (uint32_t p_idHeader)  {                            
        return (HEADER_SIZE < p_idHeader) ? (p_idHeader - HEADER_SIZE) : 0;
    }

    // uint32_t    getBlockDataIdHeaderNext        (uint32_t p_idHeader);
    uint32_t dtyCntnrStreamList_t::getBlockDataIdHeaderNext    (uint32_t p_idHeader)  {         

        return ((p_idHeader + HEADER_SIZE) < g_writeHeaderIdCurrent) ? p_idHeader + HEADER_SIZE : p_idHeader;
        // return ((p_idHeader + HEADER_SIZE) < g_writeHeaderIdCurrent) ? p_idHeader + HEADER_SIZE : p_idHeader;
    }

    // uint32_t    getBlockDataId                  (uint32_t p_idHeader);
    uint32_t dtyCntnrStreamList_t::getBlockDataId  (uint32_t p_idHeader) {                           
        uint32_t l_byteHH = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS  ] << 24) & 0xFF000000;
        uint32_t l_byteH_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+1] << 16) & 0x00FF0000;
        uint32_t l_byteL_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+2] <<  8) & 0x0000FF00;
        uint32_t l_byteLL = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+3]      ) & 0x000000FF;
        return (l_byteHH + l_byteH_ + l_byteL_ + l_byteLL);
    }


    // uint16_t    getBlockDataSize                (uint32_t p_idHeader);
    uint16_t dtyCntnrStreamList_t::getBlockDataSize   (uint32_t p_idHeader) {                              
        uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS  ] <<  8) & 0xFF00;
        uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS+1]      ) & 0x00FF;
        return (l_byteH + l_byteL);
    }

    // kMarker_t   getBlockDataMarker              (uint32_t p_idHeader);
    dtyCntnrStreamList_t::kMarker_t dtyCntnrStreamList_t::getBlockDataMarker  (uint32_t p_idHeader) {                 
        uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_MARKER_POS  ] <<  8) & 0xFF00;
        uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_MARKER_POS+1]      ) & 0x00FF;
        return static_cast<kMarker_t> (l_byteH + l_byteL);
    }


    // WRITE section

    // public:
    // void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             ;
    void dtyCntnrStreamList_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize)   {
        add(p_pBufIn, p_bufInSize, kMarker_t::defaultX, kDataType_t::binary);
    }

    // void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) ;
    void dtyCntnrStreamList_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType)   {

        uint8_t* l_pBuf = g_pBuf + g_writeHeaderIdCurrent;
        uint16_t l_bufInSize = kDataType_t::ascii == p_dataType ? p_bufInSize : (p_bufInSize << 1);
        l_pBuf[HEADER_MARKER_POS]           = p_marker;
        l_pBuf[HEADER_MARKER_POS+1]         = p_marker;
        l_pBuf[HEADER_DATA_LENGTH_POS]      = l_bufInSize>>8;
        l_pBuf[HEADER_DATA_LENGTH_POS+1]    = static_cast<uint8_t> (l_bufInSize);
        l_pBuf[HEADER_INFO_POS]             = 0;
        l_pBuf[HEADER_INFO_POS+1]           = 0;
        g_writeDataIdCurrent                -= l_bufInSize;
        l_pBuf[HEADER_DATA_BEGIN_POS  ]     = g_writeDataIdCurrent>>24;
        l_pBuf[HEADER_DATA_BEGIN_POS+1]     = g_writeDataIdCurrent>>16;
        l_pBuf[HEADER_DATA_BEGIN_POS+2]     = g_writeDataIdCurrent>>8;
        l_pBuf[HEADER_DATA_BEGIN_POS+3]     = g_writeDataIdCurrent;

        uint8_t* l_pBufInfo = &l_pBuf[DATA_BLOCK_INFO_POS+1];

        // update header block id/pointer
        g_writeHeaderIdCurrent = getWriteHeaderIdNext(g_writeHeaderIdCurrent);

        // data block

        // set buffer pointer
        l_pBuf = g_pBuf + g_writeDataIdCurrent;
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

    //private:
    // uint32_t    getWriteHeaderIdNext            (uint32_t p_idHeader);
    uint32_t dtyCntnrStreamList_t::getWriteHeaderIdNext    (uint32_t p_idHeader)  {         

        return ((p_idHeader + HEADER_SIZE) < g_bufSize) ? p_idHeader + HEADER_SIZE : p_idHeader;
    }



    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** LOOP MANAGEMENT *****
    // private:

    // uint8_t getLoopInitCycles               (void)  override;
    uint8_t dtyCntnrStreamList_t::getLoopInitCycles       (void)    {
        return 1;
    }

    //bool    resetLoopElement                (void)  override;
    bool dtyCntnrStreamList_t::resetLoopElement           (void)    {
        return true;
    }

    // bool    nextLoopElement                 (void)  override;
    bool dtyCntnrStreamList_t::nextLoopElement              (void)    {
        return false;
    }

    // void        loopTuiParamSet                 (void);
    void dtyCntnrStreamList_t::loopTuiParamSet   (void) {

            // set all parameters to display element
            g_loopY0r       = g_loopRows;
            g_loopSelect    = (g_loopIdHeader == g_selectHeaderId);
            g_loopMarker    = getBlockDataMarker(g_loopIdHeader);
            g_loopPStringInfo.g_select  = g_loopSelect;
            g_loopPStringInfo.g_marker  = g_loopMarker;
            g_loopPString.setString(reinterpret_cast<char*>(&g_pBuf[getBlockDataId    (g_loopIdHeader)]));
            g_loopPString.setLength(getBlockDataSize  (g_loopIdHeader));

            g_loopPTuiUnit->cntnrUpdParams(g_loopPTuiGraphic);
            g_loopPTuiGraphic->setRelCoordY(g_loopY0r);
            g_loopH = g_loopPTuiGraphic->getDimH();

            g_loopRows      +=  g_loopH;

    }

    // bool        loopInit                        (uint32_t p_idHeader, int32_t p_y0r);
    bool dtyCntnrStreamList_t::loopInit   (uint32_t p_idHeader, int32_t p_y0r) {
        // check header position
        if(g_writeHeaderIdCurrent != p_idHeader) {
            // idHeader is OK
            g_loopIdHeader = p_idHeader;
            g_loopRows = p_y0r;
            loopTuiParamSet();
            return true;
        }

        // the container is empty
        return false;
    }

    // bool        loopDisplayBegin                (void);
    bool dtyCntnrStreamList_t::loopDisplayBegin   (void) {
        // the loop-DISPLAY reached the begin/top when
        // 1. the first data block of container is seeked; the first data block is the one that idHeader = 0
        // OR
        // 2. the amount of rows of all data block analyzed before (that is g_loopRows) is greater or equal than the dispaly-BOX rows (that is g_displayBoxH)
        return  (
                (0 == g_loopIdHeader)
            ||  (g_loopRows >= g_displayBoxH)
        );
    }

    // bool        loopDisplayEnd                  (void);
    bool dtyCntnrStreamList_t::loopDisplayEnd   (void) {
        // the loop-DISPLAY reached the end/bottom when
        // 1. the next header is equal to the first header to write (that is g_writeHeaderIdCurrent)
        // OR
        // 2. the amount of rows of all data block analyzed before (that is g_loopRows) is greater or equal than the dispaly-BOX rows (that is g_displayBoxH)
        return  (
                (g_loopIdHeader == getBlockDataIdHeaderNext(g_loopIdHeader))
            ||  (g_loopRows >= g_displayBoxH)
        );
    }


    // section end   **** LOOP MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    #define P_P_PARENT static_cast<tuiGraphicUnit_t*>(p_pParent)

    // private:

    // bool    updCntnrRelCoord                (int32_t p_delta)  override;
    bool dtyCntnrStreamList_t::updCntnrRelCoord           ([[maybe_unused]]int32_t p_delta)    {
        return true;
    }

    // void    updElementCoordNbounds          (void)  override;
    void dtyCntnrStreamList_t::updElementCoordNbounds       (void)    {
        // the display-BOX (that is the display-BOX of the owner of the current container) has been modified, so
        // the initialization params of tui element associate to container data block must be done
        g_loopPTuiGraphic->updParamsAfterParentMod();

        // N.B.: the relative coords of display-BEGIN element (that is, the data block begin) remain the same, therefore ...
        // do not other things

    }


    /* / bool    bLoopInitDisplay                (uint8_t p_id, void* p_pParent)    override;
    bool dtyCntnrStreamList_t::bLoopInitDisplay           (uint8_t p_id, void* p_pParent)    {
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
            g_loopPTuiGraphic->init(P_P_PARENT);
            g_displayBoxW = P_P_PARENT->getDspAreaDimXw();
            g_displayBoxH = P_P_PARENT->getDspAreaDimYh();
    
            g_selectHeaderId = getBlockDataIdHeaderPrev(g_writeHeaderIdCurrent);
    
            loopInit(g_selectHeaderId,0);
    
            l_result = true;
        }
        return l_result;
    }
    */

    //void    initDisplay                     (uint8_t p_id, void* p_pParent)    override;
    void dtyCntnrStreamList_t::initDisplay                ([[maybe_unused]] uint8_t p_id, void* p_pParent)  {
        // N.B.: this function is run inside a loop of only one cycle
        g_loopPTuiGraphic->init(P_P_PARENT);
        g_loopPTuiUnit->cntnrInit(&g_loopPString, &g_loopPStringInfo);

        g_displayBoxW = static_cast<tuiGraphicAbstract_t*>(p_pParent)->getDspAreaDimXw();
        g_displayBoxH = static_cast<tuiGraphicAbstract_t*>(p_pParent)->getDspAreaDimYh();

        initDisplayBeginParams(getBlockDataIdHeaderPrev(g_writeHeaderIdCurrent));    
        g_selectHeaderId = getBlockDataIdHeaderPrev(g_writeHeaderIdCurrent);

    }

    // void    clearDisplayBox                 (void)  override;
    void dtyCntnrStreamList_t::clearDisplayBox       (void)    {
    }

    // void    dspElement                      ([[maybe_unused]] bool p_recursively)   override;
    void dtyCntnrStreamList_t::dspElement                   ([[maybe_unused]] bool p_recursively)  {
        if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
            // container is NOT empty, therefore ...

            // start the procedure/loop to display elments of the container
            for(;;) {

                // display tui element
                g_loopPTuiGraphic->display();

                // check status of the loop
                if(loopDisplayEnd()) break;

                // go to the next element to display
                g_loopIdHeader      = getBlockDataIdHeaderNext(g_loopIdHeader);
                // update tui element parameter
                loopTuiParamSet();
            }
        } else {
            // display tui element
            //g_loopPTuiUnit->displayDebug(&g_loopTuiGraphic, g_writeHeaderIdCurrent, g_displayBeginIdHeader);
        }
    }


    // bool initDisplayBeginParams             (uint32_t p_idHeader);
    bool dtyCntnrStreamList_t::initDisplayBeginParams     (uint32_t p_idHeader)      {

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

    // void setDisplayBeginParams              (uint32_t p_idHeader, kPosition_t p_position);
    void dtyCntnrStreamList_t::setDisplayBeginParams                (uint32_t p_idHeader, kPosition_t p_position)    {
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

    // bool bDisplayLastRowVsLowerBound        (void);
    bool dtyCntnrStreamList_t::bDisplayLastRowVsLowerBound           (void)    {
        // 
        if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
            // container is NOT empty, therefore ...

            // start the procedure/loop to display elments of the container
            for(;;) {

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


    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INPUT EVENTS: SELECTION & MOUSE ROLL *****

    // void    shiftLoopElementRollUp          (void)  override;
    void dtyCntnrStreamList_t::shiftLoopElementRollUp           (void)    {
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


    // void    shiftLoopElementRollDown        (void)  override;
    void dtyCntnrStreamList_t::shiftLoopElementRollDown           (void)    {

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

    bool dtyCntnrStreamList_t::bFindSelectedElement     (void)  {
        bool l_result = false;
        if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
            // container is NOT empty, therefore ...

            // start the procedure/loop to display elments of the container
            for(;;) {

                g_loopPTuiGraphic->updParamsAfterParentMod();
                if(g_loopPTuiGraphic->bMouseClickInsideBounds()) {
                    g_selectHeaderId = g_loopIdHeader;
                    l_result = true;
                    break;
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

    // new version; this version seems OK but it must be tested deeply
    bool dtyCntnrStreamList_t::selectElementByMouse      (void)      {
        bool l_result = bFindSelectedElement();
        if(l_result)    {
            // check the visibility status of element
            if(bSelectVisibleCompletely())   {
                // element is completely visible, therefore ...
                // element shift is not necessary,
                // do nothing
            } else {
                // element is NOT completely visible, therefore ...

                // shift element to the suitable position
                shiftLoopElementBySelect(0);
            }

            dspElement(false);
        }

        // N.B.: if "selectyByMouse" function of the selected item is not called then return value is false
        return false;
    }


    // int32_t getDeltaShiftBySelect           (void)  override;
    int32_t dtyCntnrStreamList_t::getDeltaShiftBySelect                ()    {
        return 0;
    }

    // void    shiftLoopElementBySelect        (int32_t p_delta)  override;
    void dtyCntnrStreamList_t::shiftLoopElementBySelect                ([[maybe_unused]] int32_t p_delta)    {
        // set display-Element parameters to select-Element parameters
        // and 
        // determine the postion inside the display-BOX of the display-Element
        if(g_selectHeaderId <= g_displayBeginIdHeader)   {
            // select-Element is located higher than display-BOX
            // shift it to Upper of the display-BOX, therefore ...
            // select-Element is equal to displayBegin-element
            setDisplayBeginParams(g_selectHeaderId, kPosition_t::top);
        } else {
            // N.B.: when the current function is called it means that the selected element is not completely visible (see bSelectVisibleCompletely() function) and
            //      therefore here the select-Element is ncessarily located under the display-BOX
            // shift it to Bottom of the display-BOX, therefore ...
            // select-Element is different than displayBegin-element
            setDisplayBeginParams(g_selectHeaderId, kPosition_t::bottom);
        }
    }

    // void    updSelectElement                (void)  override;
    void dtyCntnrStreamList_t::updSelectElement                (void)    {
    }


    // bool setSelectPrev                  (void) override;
    bool dtyCntnrStreamList_t::setSelectPrev                  (void)    {

        uint32_t l_idHeader = getBlockDataIdHeaderPrev(g_selectHeaderId);    
        // N.B.:  (l_idHeader == g_selectHeaderId) means that the select element is the first one
        bool l_result = (l_idHeader != g_selectHeaderId);
        if(l_result)    {
            g_selectHeaderIdOld = g_selectHeaderId;
            g_selectHeaderId    = l_idHeader;
        }
        return true;
    }

    // bool setSelectNext                  (void) override;
    bool dtyCntnrStreamList_t::setSelectNext                  (void)    {

        uint32_t l_idHeader = getBlockDataIdHeaderNext(g_selectHeaderId);
        // N.B.:  (l_idHeader == g_selectHeaderId) means that the select element is the last one
        bool l_result = (l_idHeader != g_selectHeaderId);
        if(l_result)    {
            g_selectHeaderIdOld = g_selectHeaderId;
            g_selectHeaderId    = l_idHeader;
        }
        return true;
    }

    // bool bSelectVisibleCompletely       (void) override;
    bool dtyCntnrStreamList_t::bSelectVisibleCompletely     (void)      {
        bool l_result = false;
        if(loopInit(g_displayBeginIdHeader, g_displayBeginY0r))    {
            for(;;) {
                if(g_loopSelect) {
                    l_result = g_loopPTuiGraphic->bVisibleCompletely();
                    break;
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




    // section end   **** INPUT EVENTS: SELECTION & MOUSE ROLL ***** 
    // ****************************************************
