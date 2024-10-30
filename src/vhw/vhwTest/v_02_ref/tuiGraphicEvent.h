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
 * tuiGraphicEvent.h
 *
 *  Created on: Oct, 22nd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_EVENT_H
#define TUI_GRAPHIC_EVENT_H

#include "tuiGraphicAbstract.h"

class tuiGraphicEvent_t {

    virtual event_t*        pEventKeyArrayGet	(void) = 0;
    virtual void_f_pVoid_t* pEventMouseArrayGet	(void) = 0;

    // --------------------- Events handler section - START
	// ..................... Events handler: functions
    virtual static void vEventHndlKey_down	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) = 0;
    virtual void vEventHndlKey_up	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlKey_left	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlKey_right	    ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlKey_enter	    ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlKey_home	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};

    virtual void vEventHndlKey_del	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlKey_backSpace	([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlKey_typeChar	    ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};

    virtual void vEventHndlMouse_rollUp	    ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};
    virtual void vEventHndlMouse_rollDown	([[maybe_unused]] tuiGraphicAbstract_t* p_this) {};

    // --------------------- Events handler section - END
};

#endif 	// TUI_GRAPHIC_EVENT_H
