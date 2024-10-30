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
 * tuiGraphicUnit.h
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_UNIT_H
#define TUI_GRAPHIC_UNIT_H

#include "tuiMacroDefine.h"
#include "tuiDrvGraphic.h"

#include "tuiUnitAbstract.h"    // cross dependency - top


class tuiGraphicUnit_t :     public tuiDrvGraphic_t
{
    typedef void    (* eventHandler_t)      (tuiGraphicAbstract_t*);

public:
    tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit  );
    tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit  ,box_t p_box    );
    tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit                  ,margins_t p_margin );
    tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit  ,box_t p_box    ,margins_t p_margin );

    //// --------------------- Process section - START
    //bool loop       	    (void)					override;
    //// --------------------- Process section - START

    // --------------------- Display section - START
    void clear              (void)                  override;
    void display            (void)                  override;
    void display            (bool p_recursively)    override;
    // --------------------- Display section - START

    // --------------------- State management section - START
    bool select             (void)                  override;
    bool deSelect           (void)                  override;
    void eventOn            (void)                  override;
    bool selectByMouse      (void)                  override;
    bool selectTst          (void)                  override;
    // --------------------- State management section - END

    // --------------------- Events handler section - START
    //protected:
    //void_f_pVoid_t* pEventKeyArrayGet	(void);
    private:
	// ..................... Events KEY handler: functions
    // the "event" & the "event array" is equal for all the instanticies of the current class therefore ...
    // the event handler function & the event array must to be defined as static
    static void vEventHndlKey_down	        (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_up	        (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_left	        (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_right	        (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_enter	        (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_home	        (tuiGraphicAbstract_t* p_this);

    static void vEventHndlKey_del	        (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_backSpace	    (tuiGraphicAbstract_t* p_this);
    static void vEventHndlKey_typeChar	    (tuiGraphicAbstract_t* p_this);

	// ..................... Events KEY handler: array
    protected:
    static eventHandler_t g_eventKeyArray[];

    //protected:
    //void_f_pVoid_t* pEventMouseArrayGet	(void)      override;
    private:
	// ..................... Events MOUSE handler: functions
    static void vEventHndlMouse_rollUp	    (tuiGraphicAbstract_t* p_this);
    static void vEventHndlMouse_rollDown	(tuiGraphicAbstract_t* p_this);

	// ..................... Events KEY handler: array
    protected:
    static eventHandler_t g_eventMouseArray[];

    // --------------------- Events handler section - END


};


#endif 	// TUI_GRAPHIC_UNIT_H
