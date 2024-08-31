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
 * dtyArray.h
 *
 *  Created on: Aug, 29th 2024
 *      Author: Marco Dau
 *

    Use Case
        - 



 */
 
#ifndef UTY_ARRAY_H
#define UTY_ARRAY_H

#include <cstdint>
#include "dtyBaseCntnrUnit.h"

class dtyArray_t : public dtyBaseCntnrUnit_t  {

public:
    // ****************************************************
    // section start **** GENERAL *****

    dtyArray_t   (uint8_t* p_pBuf, uint32_t p_bufSize);
    dtyArray_t   (uint8_t* p_pBuf, uint32_t p_bufSize, uint8_t* p_pBufIn, uint16_t p_bufInSize);
    dtyArray_t   (dtyBuffer_t* p_cntnrIn, uint32_t p_sizeCntnrIn);

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

    kMarker_t   getBlockDataMarker     (uint32_t p_idHeader) override;                  
    uint32_t    getBlockDataRowBegin   (uint32_t p_idHeader) override;                  
    uint16_t    getBlockDataSize       (uint32_t p_idHeader) override;                  

    // section end   **** DISPLAY ***** 
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

    uint32_t    getBoxPrevHeader     (uint32_t p_pIdHeader) override;            
    uint32_t    getBoxNextHeader     (uint32_t p_pIdHeader) override;            

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
    // ****************************************************
    // section start **** SELECT *****

    // section end   **** SELECT ***** 
    // ****************************************************

private:

};


#endif 	// UTY_ARRAY_H
