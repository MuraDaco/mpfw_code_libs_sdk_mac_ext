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
 * tuiUnitFormattedStringCntnr.h
 *
 *  Created on: Nov, 15th 2024 (Fri) 
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_FORMATTED_STRING_CNTNR_H
#define TUI_UNIT_FORMATTED_STRING_CNTNR_H

#include "tuiUnitAbstract.h"
#include "dtyString.h"
#include "dtyStringInfo.h"
#include "dtyProtocolDataTypesDefs.h"

//#include "tuiGraphicAbstract.h" // cross dependency - top
#include "tuiGraphicUnit.h"     // cross dependency - top


class tuiUnitFormattedStringCntnr_t :    public tuiUnitAbstract_t, dtyProtocolDataTypesDefs_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiUnitFormattedStringCntnr_t       (void);
    tuiUnitFormattedStringCntnr_t       (const char* p_strName  ,dtyString_t* p_pString = nullptr   );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    protected:
    bool init   	            (tuiGraphicUnit_t* p_this) override;
    bool initChildren           (tuiGraphicUnit_t* p_this) override;
    bool loop   	            (tuiGraphicUnit_t* p_this) override;
    bool loopChildren           (tuiGraphicUnit_t* p_this) override;
    void end       	            (tuiGraphicUnit_t* p_this) override;
    void endChildren            (tuiGraphicUnit_t* p_this) override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    protected:
    void clear                  (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    void displayChildren        (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    void refreshChildren        (tuiGraphicAbstract_t* p_this) override;

    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    protected:
    bool select     	        (tuiGraphicAbstract_t* p_this) override;
    bool deSelect   	        (tuiGraphicAbstract_t* p_this) override;
    void eventOn    	        (tuiGraphicAbstract_t* p_this) override;
    bool selectByMouse 	        (tuiGraphicAbstract_t* p_this) override;
    bool clickingChild          (tuiGraphicAbstract_t* p_this) override;

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER *****

    public:
    void cntnrInit           (dtyString_t* p_pString, dtyStringInfo_t* p_pStringInfo);
    void cntnrUpdParams      (tuiGraphicAbstract_t* p_this);

    // section end   **** CONTAINER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DATA MANAGEMENT *****

    private:

    dtyString_t*        g_pString;
    dtyStringInfo_t*    g_pStringInfo;

    uint8_t markerToColor     (kMarker_t p_marker);

    // section end   **** DATA MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG *****

    public:
    void displayDebug       (tuiGraphicAbstract_t* p_this, uint32_t p_dbgParam1, uint32_t p_dbgParam2);

    // section end   **** DEBUG *****
    // ****************************************************
    // --------------------------

};


#endif 	// TUI_UNIT_FORMATTED_STRING_H
