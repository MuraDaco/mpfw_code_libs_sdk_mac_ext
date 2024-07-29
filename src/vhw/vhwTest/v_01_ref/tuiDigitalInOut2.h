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
 * tuiDigitalInOut2.h
 *
 *  Created on: Jul, 28th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_DIGITAL_IN_OUT_2_H
#define TUI_DIGITAL_IN_OUT_2_H

#include "tuiDigitalInOut.h"


class tuiDigitalInOut2_t : public tuiDigitalInOut_t  {

public:
    tuiDigitalInOut2_t       (const char* p_strName, point_t p_Origin,  dtyUint8_t* p_pDtyStatus,    dtyUint8_t* p_pDtyStatus2    );

    dtyUint8_t* g_pDtyStatus2;

private:

};


#endif 	// TUI_DIGITAL_IN_OUT_2_H
