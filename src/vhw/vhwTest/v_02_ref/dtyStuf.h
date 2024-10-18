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
 * dtyStuf.h
 *
 *  Created on: Aug, 20th 2024
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
 
#ifndef UTY_STUF_H
#define UTY_STUF_H

#include <cstdint>
#include "dtyBaseCntnrUnit.h"

class dtyStuf_t : public dtyBaseCntnrUnit_t  {

public:
    // ****************************************************
    // section start **** GENERAL *****

    dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize);
    dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize, uint8_t* p_pBufIn, uint16_t p_bufInSize);
    dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize);
    dtyStuf_t   (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBaseCntnrUnit_t* p_cntnr);

    // section end   **** GENERAL ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****

    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             override;
    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker)                         override;
    void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) override;


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


protected:

    // ****************************************************
    // section start **** GENERAL *****

    kMarker_t   getBlockDataMarker      (uint32_t p_idHeader) override;                  
    uint32_t    getBlockDataRowBegin    (uint32_t p_idHeader) override;                  
    uint16_t    getBlockDataSize        (uint32_t p_idHeader) override;                  

    bool        bBlockDataHeaderBegin   (uint32_t p_idHeader) override;
    bool        bBlockDataHeaderEnd     (uint32_t p_idHeader) override;

    uint32_t    getBoxPrevHeader     (uint32_t p_pIdHeader) override;            
    uint32_t    getBoxNextHeader     (uint32_t p_pIdHeader) override;            

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** WRITE *****


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

	// void	    format          (kMarker_t p_marker ,uint8_t*   p_pBuffIn   ,uint8_t* p_pBuffOut);
	// void	    formatStart     (kMarker_t p_marker ,uint8_t    p_data      ,uint8_t* p_buffOut);
	// kMarker_t	getMarker       (uint8_t* p_buffOut);
	// uint8_t*	getData         (uint8_t* p_buffOut);
	// uint8_t	    getDataLength   (uint8_t* p_buffOut);
    // void        search          (uint32_t p_pDataStart, uint16_t p_rowSize);
    // void        next            (void);
    // void        prev            (void);
    // kMarker_t   getRowMarker    (void);
    // uint8_t*    getRowData      (void);
    // uint16_t    getRowInfo      (void);

    // section end   **** SELECT ***** 
    // ****************************************************

private:

};


#endif 	// DTY_STUF_H
