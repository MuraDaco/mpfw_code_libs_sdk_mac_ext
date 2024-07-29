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
 * tuiObjs.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiObjs.h"
#include "tuiManager.h"
#include "tuiWin.h"


//tuiWin_t tuiWinMain;
box_t WinBoard_box = {1, 2, 3, 4};

void WinBoard_zoneHndl_1    (void)  {

}

tuiBaseUnit_t::zone_t WinBoard_zoneList[] = {
     {{1, 2, 3, 4}, WinBoard_zoneHndl_1}
    ,{{1, 2, 3, 4}, WinBoard_zoneHndl_1}
    ,{{1, 4, 3, 4}, WinBoard_zoneHndl_1}
    ,{{1, 2, 3, 4}, nullptr}
    //,nullptr
};

tuiWin_t tuiWinBoard (&WinBoard_box, WinBoard_zoneList);


tuiWin_t::element_t tuiWinBoard2_ElementList[] = {
     {&tuiWinBoard, 2}
    ,{&tuiWinBoard, 1}
    ,{nullptr, 1}
};

tuiWin_t tuiWinBoard2 (&WinBoard_box, tuiWinBoard2_ElementList);

tuiWin_t* tuiManager_t::g_mainWin = &tuiWinBoard2;
