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
 * tuiAppMain.h
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_APP_MAIN_H
#define TUI_APP_MAIN_H

#include "tuiGraphicTypes.h"
#include "uyTypesDefs.h"
#include "tuiWinRoot.h"

class tuiAppMain_t {

public:
    static tuiWinRoot_t                 g_win;

private:
    static void zone_1_hndl    (void);
    static void zone_2_hndl    (void);

    static box_t                    g_box;
    static tuiBaseUnit_t::zone_t    g_zoneList[];
    static tuiWin_t::element_t      g_elementList[];

};

#endif 	// TUI_APP_MAIN_H
