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
 * dtyCntnrStreamOfFormattedString.h
 *
 *  Created on: Nov, 21st 2024 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef DTY_CNTNR_STREAM_OF_FORMATTED_STRING_H
#define DTY_CNTNR_STREAM_OF_FORMATTED_STRING_H

#include "dtyCntnrStreamList.h"

#include "tuiUnitFormattedStringCntnr.h"
#include "tuiGraphicUnitBase.h"

class dtyCntnrStreamOfFormattedString_t: public dtyCntnrStreamList_t {

    public:

    dtyCntnrStreamOfFormattedString_t   (uint8_t* p_pBuf, uint32_t p_bufSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize);

    private:
    tuiUnitFormattedStringCntnr_t    g_unit;
    tuiGraphicUnitBase_t             g_graphic;

};


#endif 	// DTY_CNTNR_STREAM_OF_FORMATTED_STRING_H
