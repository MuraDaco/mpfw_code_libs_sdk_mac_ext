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
 * tuiBase.h
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_H
#define TUI_BASE_H


#include "tuiBaseAction.h"
#include "tuiBaseDrawer.h"

class tuiBase_t : public tuiBaseAction_t, public tuiBaseDrawer_t {

public:

    tuiBase_t (void);
    tuiBase_t (const char* p_strName, box_t *p_pBox);
    tuiBase_t (const char* p_strName, box_t p_box);
    tuiBase_t (const char* p_strName, box_t *p_pBox,    margins_t p_margins );
    tuiBase_t (const char* p_strName, box_t p_box,      margins_t p_margins );
    tuiBase_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus);

    void init               (void* p_poFather) 		override;
    bool selectTst   	    (void)                  override;
    void debug_01   	    (void)                  override;

    void updCoordNbounds                (int16_t p_delta);
    void updCoordNboundsForNewFather    (void);

    virtual void updCoordNboundsChilds  (void);



    bool bVisibleCompletely       (void);
    int32_t getDistanceFromUpperBound   (void);
    int32_t getDistanceFromLowerBound   (void);
    int32_t getDistanceFromBound        (void);


    //int16_t g_boundUpper;
    //int16_t g_boundLower;

};


#endif  // TUI_BASE_H
