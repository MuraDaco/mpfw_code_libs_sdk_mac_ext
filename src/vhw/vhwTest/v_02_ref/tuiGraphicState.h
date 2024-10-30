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
 * tuiGraphicState.h
 *
 *  Created on: Oct, 21st 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_STATE_H
#define TUI_GRAPHIC_STATE_H

#include "tuiGraphicParent.h"
#include "tuiGraphicStateInterface.h"

class tuiGraphicState_t: public virtual tuiGraphicParent_t, public virtual tuiGraphicStateInterface_t {

public:


    // common functions
    void deselectBackNeventOn               (void);
    void deselectBackNselect                (void);


protected:
    tuiMode_t g_mode;
    tuiMode_t g_status;

private:
    void selectBack                            (void);
    tuiGraphicState_t* searchCommonAncestor    (void);
    tuiGraphicState_t* deselectBack            (tuiGraphicState_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON);

protected:
    void selectNeventOnInit                     (void);
    static tuiGraphicState_t* g_poSelected;
    static tuiGraphicState_t* g_poEventOn;



// **** --------------------- Events handler section - START

private:
	// // ..................... Events handler: array
    // static event_t*         g_eventKeyArray;
    // static void_f_pVoid_t*  g_eventMouseArray;

// **** --------------------- Events handler section - END


// **** --------------------- Debug section - START

public:
    // debug
    virtual void debug_01    	(void) = 0;

private:
    void debugDeselectBack (tuiGraphicState_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON);
    static uint8_t g_debugStatus;
    static uint8_t g_debugStatusX;

// **** --------------------- Debug section - END

};

#endif 	// TUI_GRAPHIC_STATE_H
