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
 * tuiGraphicUnitBase.h
 *
 *  Created on: Oct, 28th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_UNIT_BASE_H
#define TUI_GRAPHIC_UNIT_BASE_H

#include "tuiGraphicUnit.h"

class tuiGraphicUnitBase_t : public tuiGraphicUnit_t  {

public:

    tuiGraphicUnitBase_t        (tuiUnitAbstract_t* p_pUnit = nullptr);
    tuiGraphicUnitBase_t        (tuiUnitAbstract_t* p_pUnit ,box_t p_box    );
    tuiGraphicUnitBase_t        (tuiUnitAbstract_t* p_pUnit ,box_t p_box    ,margins_t p_margin);


    // --------------------- Process section - START
    bool init                   (void)      override;
    bool initChildren           (void)      override;
    bool init                   (tuiGraphicUnit_t* p_pParent)       override;
    bool loop                   (void)      override;
    bool loopChildren           (void)      override;
    void end                    (void)      override;
    void endChildren            (void)      override;
    // --------------------- Process section - START

    // --------------------- State management section - START
    bool eventOnTst    	        (void) override;
    void debug_01               (void) override;
    // --------------------- State management section - END


};


#endif 	// TUI_GRAPHIC_UNIT_BASE_H
