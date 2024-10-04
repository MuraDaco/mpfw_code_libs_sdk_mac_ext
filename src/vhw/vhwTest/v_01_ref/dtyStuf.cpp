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
 * dtyStuf.cpp
 *
 *  Created on: Aug, 20th 2024
 *      Author: Marco Dau
 */
 

#include "dtyStuf.h"

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

dtyStuf_t::dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize) :
    dtyBaseCntnrUnit_t  (p_pBuf, p_bufSize)
{}

dtyStuf_t::dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize, uint8_t* p_pBufIn, uint16_t p_bufInSize) :
    dtyBaseCntnrUnit_t  (p_pBuf, p_bufSize)
{
    add(p_pBufIn, p_bufInSize);
}

dtyStuf_t::dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize) :
    dtyBaseCntnrUnit_t  (p_pBuf, p_bufSize)
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



dtyStuf_t::kMarker_t dtyStuf_t::getBlockDataMarker  (uint32_t p_idHeader) {                 
    uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_MARKER_POS  ] <<  8) & 0xFF00;
    uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_MARKER_POS+1]      ) & 0x00FF;
    return static_cast<kMarker_t> (l_byteH + l_byteL);
}

uint32_t dtyStuf_t::getBlockDataRowBegin  (uint32_t p_idHeader) {                           
    uint32_t l_byteHH = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS  ] << 24) & 0xFF000000;
    uint32_t l_byteH_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+1] << 16) & 0x00FF0000;
    uint32_t l_byteL_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+2] <<  8) & 0x0000FF00;
    uint32_t l_byteLL = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+3]      ) & 0x000000FF;
    return (l_byteHH + l_byteH_ + l_byteL_ + l_byteLL);
}

uint16_t dtyStuf_t::getBlockDataSize   (uint32_t p_idHeader) {                              
    uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS  ] <<  8) & 0xFF00;
    uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS+1]      ) & 0x00FF;
    return (l_byteH + l_byteL);
}


bool     dtyStuf_t::bBlockDataHeaderBegin   (uint32_t p_idHeader)   {
    return (p_idHeader == 0);
}

bool     dtyStuf_t::bBlockDataHeaderEnd   (uint32_t p_idHeader)   {
    return (p_idHeader + HEADER_SIZE == g_idWriteHeaderCurrent);
}

uint32_t dtyStuf_t::getBoxPrevHeader    (uint32_t p_pIdHeader)  {                            
    return (p_pIdHeader >= HEADER_SIZE) ? (p_pIdHeader - HEADER_SIZE) : 0;
}

uint32_t dtyStuf_t::getBoxNextHeader    (uint32_t p_pIdHeader)  {                            
    return p_pIdHeader + HEADER_SIZE;
}


// section end   **** GENERAL ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** WRITE *****

void dtyStuf_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize)   {
    add(p_pBufIn, p_bufInSize, kMarker_t::defaultX, kDataType_t::binary);
}

void dtyStuf_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker)   {
    uint8_t* l_pBuf = g_pBuf + g_idWriteDataCurrent;

    l_pBuf[MARKER_START_POS]         = p_marker;
    l_pBuf[MARKER_START_POS+1]       = p_marker;
    l_pBuf[DATA_LENGTH_POS]          = p_bufInSize>>8;
    l_pBuf[DATA_LENGTH_POS+1]        = static_cast<uint8_t> (p_bufInSize);
    l_pBuf[DATA_BLOCK_INFO_POS]      = 0;
    l_pBuf[DATA_BLOCK_INFO_POS+1]    = 0;
    uint8_t* l_pBufInfo = &l_pBuf[DATA_BLOCK_INFO_POS+1];
    l_pBuf += DATA_START_POS;
    uint16_t l_cnt = 0;
    bool l_binaryData = false;
    while(l_cnt < p_bufInSize)    {
        // l_pBuf[0] = *p_pBufIn;
        l_pBuf[0] = (*p_pBufIn >> 4) & 0x0F; l_pBuf[0] += ( l_pBuf[0] < 0x0A ? 0x30 : 0x37);
        // l_pBuf[1] = *p_pBufIn;
        l_pBuf[1] = (*p_pBufIn     ) & 0x0F; l_pBuf[1] += ( l_pBuf[1] < 0x0A ? 0x30 : 0x37);
        if(!l_binaryData) {
            l_binaryData = ((*p_pBufIn < 0x20) || (*p_pBufIn > 0x7e));
            *l_pBufInfo = 1;
        }
        l_pBuf += 2;
        l_cnt++;
        p_pBufIn++;
    }
    l_pBuf[DATA_END___POS - (DATA_LENGTH_POS+1)      ]   = p_bufInSize>>8;
    l_pBuf[DATA_END___POS -  DATA_LENGTH_POS         ]   = static_cast<uint8_t> (p_bufInSize);
    l_pBuf[DATA_END___POS - (MARKER_START_POS+1)     ]   = -p_marker;
    l_pBuf[DATA_END___POS -  MARKER_START_POS        ]   = -p_marker;

    // to-do
    // update g_idWriteDataCurrent
    //g_idWriteDataCurrent;
}

void dtyStuf_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType)   {

    uint8_t* l_pBuf = g_pBuf + g_idWriteHeaderCurrent;
    uint16_t l_bufInSize = kDataType_t::ascii == p_dataType ? p_bufInSize : (p_bufInSize << 1);
    l_pBuf[HEADER_MARKER_POS]           = p_marker;
    l_pBuf[HEADER_MARKER_POS+1]         = p_marker;
    l_pBuf[HEADER_DATA_LENGTH_POS]      = l_bufInSize>>8;
    l_pBuf[HEADER_DATA_LENGTH_POS+1]    = static_cast<uint8_t> (l_bufInSize);
    l_pBuf[HEADER_INFO_POS]             = 0;
    l_pBuf[HEADER_INFO_POS+1]           = 0;
    g_idWriteDataCurrent                -= l_bufInSize;
    l_pBuf[HEADER_DATA_BEGIN_POS  ]     = g_idWriteDataCurrent>>24;
    l_pBuf[HEADER_DATA_BEGIN_POS+1]     = g_idWriteDataCurrent>>16;
    l_pBuf[HEADER_DATA_BEGIN_POS+2]     = g_idWriteDataCurrent>>8;
    l_pBuf[HEADER_DATA_BEGIN_POS+3]     = g_idWriteDataCurrent;

    uint8_t* l_pBufInfo = &l_pBuf[DATA_BLOCK_INFO_POS+1];

    // update header block id/pointer
    g_idWriteHeaderCurrent = getBoxNextHeader(g_idWriteHeaderCurrent);

    // data block

    // set buffer pointer
    l_pBuf = g_pBuf + g_idWriteDataCurrent;
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

// section end   **** WRITE ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** DISPLAY *****


// section end   **** DISPLAY ***** 
// ****************************************************
// --------------------------
// ****************************************************
// section start **** SELECT *****

// section end   **** SELECT ***** 
// ****************************************************


/*
void        dtyStuf_t::search          (uint32_t p_pDataStart, uint16_t p_rowSize) {

    // find the data block to which p_pDataStart seeks
    g_pBufSearch = g_pBufOrigin + p_pDataStart;
    g_rowSize = p_rowSize;

}

void        dtyStuf_t::next            (void)   {

}

void        dtyStuf_t::prev            (void)   {

}

dtyStuf_t::kMarker_t   dtyStuf_t::getRowMarker    (void)   {

    return kMarker_t::defaultX;
}

uint8_t*    dtyStuf_t::getRowData      (void)   {

    return g_pBufBlockDataCur;
}

uint16_t    dtyStuf_t::getRowInfo      (void)   {
    uint16_t l_result = g_pBufSearch[0];
    return l_result;
}



void dtyStuf_t::format      (kMarker_t p_marker, uint8_t* p_buffIn, uint8_t* p_buffOut) {
    *p_buffOut = p_marker;
    p_buffOut++;
    while(*p_buffIn)    {
        *p_buffOut = *p_buffIn;
        p_buffIn++;
    }
}

dtyStuf_t::kMarker_t	dtyStuf_t::getMarker             (uint8_t* p_buffOut)  {
    return static_cast<kMarker_t>(p_buffOut[0]);
}

uint8_t*    dtyStuf_t::getData         (uint8_t* p_buffOut)    {
    return p_buffOut + 10;
}


uint8_t	    dtyStuf_t::getDataLength   (uint8_t* p_buffOut)    {
    return p_buffOut[10];
}

*/
