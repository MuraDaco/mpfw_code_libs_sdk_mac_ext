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
 * tuiGraphicAppMain.h
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_APP_MAIN_H
#define TUI_GRAPHIC_APP_MAIN_H

#include "tuiUnitDebug.h"
#include "tuiUnitListDebug.h"
#include "dtyTuiGraphic.h"
#include "tuiUnitCntnrList.h"

#include "tuiGraphicUnitBase.h"
#include "tuiGraphicUnitWin.h"
#include "tuiGraphicUnitRoot.h"

class tuiGraphicAppMain_t {

public:
    static tuiUnitDebug_t           g_unitDebug_1;
    static tuiUnitDebug_t           g_unitDebug_2;
    static tuiUnitDebug_t           g_unitDebug_3;
    static tuiUnitDebug_t           g_unitDebug_4;
    static tuiUnitDebug_t           g_unitDebug_5;
    static tuiUnitDebug_t           g_unitDebug_6;
    static tuiUnitDebug_t           g_unitDebug_7;
    static tuiUnitDebug_t           g_unitDebug;
    static tuiUnitDebug_t           g_unitDebugA;

    static tuiGraphicUnitBase_t     g_setDebug[];
    static tuiGraphicUnitBase_t     g_arrayCntnrDebug[];
    static tuiGraphicUnitWin_t      g_setWinDebug[];

    static dtyTuiGraphic_t          g_CntnrDebug;

    static tuiUnitListDebug_t       g_unitDebugWin_1;
    static tuiUnitListDebug_t       g_unitDebugWin_2;
    static tuiUnitListDebug_t       g_unitDebugWin_3;
    static tuiUnitCntnrList_t        g_unitCntnrWin_A;
    static tuiUnitListDebug_t       g_unitDebugList;

    static tuiGraphicUnitRoot_t     g_boxRoot;

};

#endif 	// TUI_GRAPHIC_APP_MAIN_H
