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
 * tuiGraphicAppMain.cpp
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicAppMain.h"


tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_1    ("Unit Debug 111");
tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_2    ("Unit Debug 222");
tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_3    ("Unit Debug 333");
tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_4    ("Unit Debug 444");

tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setDebug[] = {
    {   &g_unitDebug_1, box_t({10, 30,  0,  0})                         },
    {   &g_unitDebug_2, box_t({10, 30, 10, 30}), margins_t({2,1,2,1})   },
    {   &g_unitDebug_3, box_t({10, 30, 10, 60}), margins_t({1,2,1,1})   },
    {   &g_unitDebug_2, box_t({10, 30,  0, 90}), margins_t({1,1,1,2})   },
    {   &g_unitDebug_4, box_t({10, 30, 20, 60}), margins_t({2,1,1,2})   },
    {}  // null element to mark the and of array; 
};

tuiUnitDebugList_t      tuiGraphicAppMain_t::g_unitDebugWin_1("Unit debug Window 1", g_setDebug);
tuiUnitDebugList_t      tuiGraphicAppMain_t::g_unitDebugWin_2("Unit debug Window 2");
tuiUnitDebugList_t      tuiGraphicAppMain_t::g_unitDebugWin_3("Unit debug Window 3");

tuiGraphicUnitWin_t    tuiGraphicAppMain_t::g_setWinDebug[] = {
    {   &g_unitDebugWin_1,  box_t({35, 130,   0,   0})                         },
    {   &g_unitDebugWin_2,  box_t({34,  80,  35,   0})                         },
    {   &g_unitDebugWin_3,  box_t({34,  80,  35,  80})                         },
    {}  // null element to mark the and of array; 
};

tuiUnitDebugList_t      tuiGraphicAppMain_t::g_unitDebugList("Unit debug List", g_setWinDebug);

tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug    ("Unit Debug");
tuiGraphicUnitRoot_t    tuiGraphicAppMain_t::g_boxRoot      (&g_unitDebugList   ,margins_t({5,2,1,1}));
