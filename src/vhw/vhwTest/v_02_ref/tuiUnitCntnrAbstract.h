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
 * tuiUnitCntnrAbstract.h
 *
 *  Created on: Nov, 4th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_CNTNR_ABSTRACT_H
#define TUI_UNIT_CNTNR_ABSTRACT_H

#include "tuiUnitAbstract.h"
#include "dtyBaseCntnrUnitX.h"

#include "tuiGraphicUnit.h"     // cross dependency - top

class tuiUnitCntnrAbstract_t :    public tuiUnitAbstract_t 
{

protected:
    tuiUnitCntnrAbstract_t      (const char* p_strName, dtyBaseCntnrUnitX_t* p_pCntnr     );

    // --------------------- Process section - START
    bool init                   (tuiGraphicUnit_t* p_this) override;
    bool initChildren           (tuiGraphicUnit_t* p_this) override;
    // bool loop                    (tuiGraphicUnit_t* p_this) override;
    // bool loopChildren            (tuiGraphicUnit_t* p_this) override;
    // void end                     (tuiGraphicUnit_t* p_this) override;
    // void endChildren             (tuiGraphicUnit_t* p_this) override;
    // --------------------- Process section - END

    // --------------------- Container section - START
    void updCoordNboundsChilds      (void) override;

    dtyBaseCntnrUnitX_t* g_pCntnr;
    // --------------------- Container section - END

    // --------------------- Display section - START
    // void clear                  (tuiGraphicAbstract_t* p_this) override;
    // void display                (tuiGraphicAbstract_t* p_this) override;
    // void display                (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    void displayChildren        (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    void refreshChildren        (tuiGraphicAbstract_t* p_this) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    // bool select                  (tuiGraphicAbstract_t* p_this) override;
    // bool deSelect                (tuiGraphicAbstract_t* p_this) override;
    // void eventOn                 (tuiGraphicAbstract_t* p_this) override;
    bool selectByMouse 	        (tuiGraphicAbstract_t* p_this) override;
    bool clickingChild          (tuiGraphicAbstract_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- KEY Events handler section - START
	// ..................... KEY Events handler: functions
    void vEventHndlKey_down         (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_up           (tuiGraphicAbstract_t* p_this)  override;
    //void vEventHndlKey_left       (tuiGraphicAbstract_t* p_this)  override;
    //void vEventHndlKey_right      (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_enter        (tuiGraphicAbstract_t* p_this)  override;
    //void vEventHndlKey_home       (tuiGraphicAbstract_t* p_this)  override;
    // --------------------- KEY Events handler section - END

    // --------------------- MOUSE Events handler section - START
	// ..................... MOUSE Events handler: functions
    void vEventHndlMouse_rollUp         (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlMouse_rollDown       (tuiGraphicAbstract_t* p_this)  override;
    // --------------------- MOUSE Events handler section - END

};


#endif 	// TUI_UNIT_CNTNR_ABSTRACT_H
