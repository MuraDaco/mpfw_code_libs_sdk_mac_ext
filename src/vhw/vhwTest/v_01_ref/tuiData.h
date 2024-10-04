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
 * tuiData.h
 *
 *  Created on: Sep, 25th 2024
 *      Author: Marco Dau
 */



#ifndef TUI_DATA_H
#define TUI_DATA_H


#include "tuiBase.h"

class tuiData_t : public tuiBase_t {

public:

    tuiData_t (uint8_t* p_pBuf, uint32_t p_bufSize);


    void display            (void)                  override;
    void display            (bool p_recursively)    override;
    bool select             (void)                  override;
    bool deSelect           (void)                  override;
    bool selectByMouse      (void)                  override;
    void setThis            (void)                  override;
    void eventOn            (void)                  override;
    event_t* pEventArrayGet	(void)                  override;
    uint8_t eventArraySizeGet   (void)              override;


    void displayUpdate      (uint32_t p_loopIData, uint32_t p_loopDataSize, int32_t p_loopY0r, uint32_t p_loopH, bool p_loopSelect, uint8_t p_loopMarker);



    uint8_t* g_pBuf;
    uint32_t g_bufSize;
    uint32_t g_idData;
    uint32_t g_dataSize;
    bool     g_select;
    uint8_t  g_marker;

    uint32_t g_relBoundUpper;
    uint32_t g_relBoundLower;

};


#endif 	// TUI_DATA_H
