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
 * tuiUnitSet.h
 *
 *  Created on: Oct, 24th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_SET_H
#define TUI_UNIT_SET_H

#include "tuiUnitAbstract.h"
#include "dtyUint8.h"

#include "tuiGraphicAbstract.h" // cross dependency - completed


class tuiUnitSet_t :    public tuiUnitAbstract_t
{

public:
    tuiUnitSet_t       (const char* p_strName  ,dtyUint8_t* p_pDtyStatus   );

protected:
   

    // --------------------- Display section - START
    void clear                  (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool select     	        (tuiGraphicAbstract_t* p_this) override;
    bool deSelect   	        (tuiGraphicAbstract_t* p_this) override;
    void eventOn    	        (tuiGraphicAbstract_t* p_this) override;
    bool selectByMouse 	        (tuiGraphicAbstract_t* p_this) override;
    bool selectTst              (tuiGraphicAbstract_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- Events handler section - START
	// ..................... Events handler: functions
    void vEventHndlKey_down	    (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_up	    (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_left	    (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_right	(tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_enter	(tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_home	    (tuiGraphicAbstract_t* p_this)  override;
    // --------------------- Events handler section - END

private:

    // --------------------- Generic  Data section - START
    const char* g_strName;
    // --------------------- Generic  Data section - END

    // --------------------- Specific Data section - START
    dtyUint8_t* g_pDtyStatus;
    // --------------------- Specific Data section - END

};


#endif 	// TUI_UNIT_DGT_IN_OUT_H
