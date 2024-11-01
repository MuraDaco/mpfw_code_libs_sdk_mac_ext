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
 * tuiGraphicAbstract.h
 *
 *  Created on: Oct, 22nd 2024
 *      Author: Marco Dau
 
    - genealogical & dependence tree
        - [dr] tuiGraphicCoord_t
            - [dr-virtual] tuiGraphicParent_t
        - [dr] tuiGraphicState_t
            - [dr-virtual] tuiGraphicParent_t
            - [dr] tuiGraphicStateInterface_t
        - [dr] tuiGraphicDriverInOutInterface_t

*/
 
#ifndef TUI_GRAPHIC_ABSTRACT_H
#define TUI_GRAPHIC_ABSTRACT_H


#include "tuiGraphicCoord.h"
#include "tuiGraphicState.h"
#include "tuiGraphicDisplayInterface.h"
#include "tuiGraphicDriverInOutInterface.h"
#include "tuiGraphicProcessInterface.h"

class tuiUnitAbstract_t; // cross dependency -> #include "tuiUnitAbstract.h"

class tuiGraphicAbstract_t :     public tuiGraphicCoord_t
                                ,public tuiGraphicState_t
                                ,public tuiGraphicDisplayInterface_t
                                ,public tuiGraphicDriverInOutInterface_t
                                ,public tuiGraphicProcessInterface_t
{

public:
    tuiGraphicAbstract_t (tuiUnitAbstract_t* p_pUnit     );
    tuiGraphicAbstract_t (tuiUnitAbstract_t* p_pUnit     ,box_t p_box   );
    tuiGraphicAbstract_t (tuiUnitAbstract_t* p_pUnit                    ,margins_t p_margin );
    tuiGraphicAbstract_t (tuiUnitAbstract_t* p_pUnit     ,box_t p_box   ,margins_t p_margin );

public:
    //// --------------------- General section - START
    bool bNull              (void);
    bool bNotNull           (void);
    tuiUnitAbstract_t* g_pUnit;
    //// --------------------- General section - START




};


#endif  // TUI_GRAPHIC_VIRTUAL_H
