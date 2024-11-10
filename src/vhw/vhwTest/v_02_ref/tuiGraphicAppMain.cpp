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
tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_5    ("Unit Debug 555");
tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_6    ("Unit Debug 666");
tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug_7    ("Unit Debug 777");


char tuiGraphicAppMain_t::usartBuffer[1000] = "Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor";
dtyBaseArray_t  tuiGraphicAppMain_t::usartString    (usartBuffer, sizeof(usartBuffer));
tuiUnitEbox_t   tuiGraphicAppMain_t::g_unitEbox_1   ("Unit Ebox 1", usartString);

tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setDebug[] = {
    {   &g_unitDebug_1, box_t({10, 30,  0,  0})                         },
    {   &g_unitDebug_2, box_t({10, 30, 10, 30}), margins_t({2,1,2,1})   },
    {   &g_unitDebug_3, box_t({10, 30, 10, 60}), margins_t({1,2,1,1})   },
    {   &g_unitDebug_2, box_t({10, 30,  0, 90}), margins_t({1,1,1,2})   },
    {   &g_unitEbox_1,  box_t({10, 30, 20, 60}), margins_t({2,1,1,2})   },
    {}  // null element to mark the and of array; 
};

tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_arrayCntnrDebug[] = {
    {   &g_unitDebug_1, box_t({ 8, 34,  0,  0})                         },
    {   &g_unitDebug_2, box_t({10, 32,  0,  0}), margins_t({2,1,2,1})   },
    {   &g_unitDebug_3, box_t({ 5, 30,  0,  0}), margins_t({1,2,1,1})   },
    {   &g_unitDebug_2, box_t({ 5, 30,  0,  0}), margins_t({1,1,1,2})   },
    {   &g_unitDebug_4, box_t({ 5, 30,  0,  0}), margins_t({2,1,1,2})   },
    {   &g_unitDebug_5, box_t({ 6, 30,  0,  0}), margins_t({1,2,1,1})   },
    {   &g_unitDebug_6, box_t({11, 30,  0,  0}), margins_t({1,1,1,2})   },
    {   &g_unitDebug_7, box_t({ 8, 30,  0,  0})                         },
    {   &g_unitDebug_5, box_t({ 6, 30,  0,  0}), margins_t({1,2,1,1})   },
    {}  // null element to mark the and of array; 
};

dtyTuiGraphic_t    tuiGraphicAppMain_t::g_CntnrDebug(g_arrayCntnrDebug);

tuiUnitListDebug_t      tuiGraphicAppMain_t::g_unitDebugWin_1   ("Unit debug Window 1", g_setDebug);
tuiUnitCntnrList_t      tuiGraphicAppMain_t::g_unitCntnrWin_A   ("Unit debug Window A", &g_CntnrDebug);
tuiUnitListDebug_t      tuiGraphicAppMain_t::g_unitDebugWin_2   ("Unit debug Window 2");
tuiUnitListDebug_t      tuiGraphicAppMain_t::g_unitDebugWin_3   ("Unit debug Window 3");

tuiGraphicUnitWin_t    tuiGraphicAppMain_t::g_setWinDebug[] = {
    {   &g_unitDebugWin_1,  box_t({35, 130,   0,   0})                         },
    {   &g_unitCntnrWin_A,  box_t({35,  40,   0, 130})                         },
    {   &g_unitDebugWin_2,  box_t({34,  80,  35,   0})                         },
    {   &g_unitDebugWin_3,  box_t({34,  80,  35,  80})                         },
    {}  // null element to mark the and of array; 
};

tuiUnitSet_t      tuiGraphicAppMain_t::g_unitDebugList("Unit debug List", g_setWinDebug);

tuiUnitDebug_t          tuiGraphicAppMain_t::g_unitDebug    ("Unit Debug");
tuiGraphicUnitRoot_t    tuiGraphicAppMain_t::g_boxRoot      (&g_unitDebugList   ,margins_t({5,2,5,5}));
