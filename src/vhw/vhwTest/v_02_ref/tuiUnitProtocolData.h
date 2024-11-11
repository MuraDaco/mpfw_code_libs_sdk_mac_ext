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
 * tuiUnitProtocolData.h
 *
 *  Created on: Nov, 10th 2024
 *      Author: Marco Dau
 */



#ifndef TUI_UNIT_PROTOCOL_DATA_H
#define TUI_UNIT_PROTOCOL_DATA_H


#include "tuiUnitAbstract.h"
#include "dtyProtocolDataTypesDefs.h"

#include "tuiGraphicUnit.h"     // cross dependency - top

class tuiUnitProtocolData_t : public tuiUnitAbstract_t,  dtyProtocolDataTypesDefs_t {

    public:
    tuiUnitProtocolData_t (uint8_t* p_pBuf, uint32_t p_bufSize);

    protected:
    // --------------------- Process section - START
    bool init   	            (tuiGraphicUnit_t* p_this) override;
    bool initChildren           (tuiGraphicUnit_t* p_this) override;
    bool loop   	            (tuiGraphicUnit_t* p_this) override;
    bool loopChildren           (tuiGraphicUnit_t* p_this) override;
    void end       	            (tuiGraphicUnit_t* p_this) override;
    void endChildren            (tuiGraphicUnit_t* p_this) override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    void clear                  (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    void displayChildren        (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    void refreshChildren        (tuiGraphicAbstract_t* p_this) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool select     	        (tuiGraphicAbstract_t* p_this) override;
    bool deSelect   	        (tuiGraphicAbstract_t* p_this) override;
    void eventOn    	        (tuiGraphicAbstract_t* p_this) override;
    bool selectByMouse 	        (tuiGraphicAbstract_t* p_this) override;
    bool clickingChild          (tuiGraphicAbstract_t* p_this) override;
    // --------------------- State management section - END

    // // --------------------- Events handler section - START
	// // ..................... Events handler: functions
    // void vEventHndlKey_down	    (tuiGraphicAbstract_t* p_this)  override;
    // void vEventHndlKey_up	    (tuiGraphicAbstract_t* p_this)  override;
    // void vEventHndlKey_left	    (tuiGraphicAbstract_t* p_this)  override;
    // void vEventHndlKey_right     (tuiGraphicAbstract_t* p_this)  override;
    // void vEventHndlKey_enter     (tuiGraphicAbstract_t* p_this)  override;
    // void vEventHndlKey_home	    (tuiGraphicAbstract_t* p_this)  override;
    // // --------------------- Events handler section - END

    // --------------------- Custom section - START
    public:
    void updParams          (uint32_t p_loopIData, uint32_t p_loopDataSize, bool p_loopSelect, kMarker_t p_loopMarker);

    private:
    uint8_t markerToColor     (kMarker_t p_marker);

    uint8_t*    g_pBuf;
    uint32_t    g_bufSize;
    uint32_t    g_idData;
    uint32_t    g_dataSize;
    bool        g_select;
    kMarker_t   g_marker;

    // --------------------- Custom section - END

    public:
    // --------------------- Custom debug section - START
    void displayDebug       (tuiGraphicAbstract_t* p_this, uint32_t p_dbgParam1, uint32_t p_dbgParam2);
    void displayDebugTest   (tuiGraphicAbstract_t* p_this);
    // --------------------- Custom debug section - END



};


#endif 	// TUI_UNIT_PROTOCOL_DATA_H
