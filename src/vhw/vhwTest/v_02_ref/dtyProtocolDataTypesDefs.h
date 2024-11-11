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
 * dtyProtocolDataTypesDefs.h
 *
 *  Created on: Nov, 10th 2024
 *      Author: Marco Dau
 */
 
#ifndef DTY_PPROTOCOL_DATA_TYPES_DEFS_H
#define DTY_PPROTOCOL_DATA_TYPES_DEFS_H

#include <stddef.h>
#include <cstdint>

class dtyProtocolDataTypesDefs_t  {

public:
    enum kMarker_t: int8_t  {
         defaultX = 0x18      // end marker = 0xe8
        ,deviceRx = 0x07      // end marker = 0xf9
        ,deviceTx = 0x06      // end marker = 0xfa
        ,testTx   = 0x15      // end marker = 0xeb
    };

    enum kDataType_t: int8_t  {
         ascii
        ,binary
    };
};


#endif 	// DTY_PPROTOCOL_DATA_TYPES_DEFS_H
