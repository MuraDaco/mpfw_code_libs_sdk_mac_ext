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
 * tuiAppBoard.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiAppBoard.h"

#include "tuiAppPinPort.h"
#include "tuiBaseDgtInOut.h"
#include "tuiBaseLboxX.h"
#include "tuiAppUsart.h"

#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Leds.h"
#include "vhwPphTbl_Mod1.h"

// **********************************************************
// -------- BOX define - start
// .......................... H   W  Yo  Xo
box_t tuiAppBoard_t::g_box = {25,  75,  0,  0};
// -------- BOX define - end



// **********************************************************
// -------- ELEMENT LIST define - start
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_VIA    ,1 ,40 , 0 ,0  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_BIO    ,1 ,40 , 1 ,0  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_VAI    ,1 ,40 , 2 ,0  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_PER       ,1 ,40 , 3 ,0  )

TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_PUR       ,1 ,40 , 4 ,0  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_MAI       ,1 ,40 , 5 ,0  )

TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_AND    ,1 ,40 , 6 ,0  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_NOT    ,1 ,40 , 7 ,0  )


box_t boxAppUsarttest = {13,  71,  2, 0};
tuiAppUsart_t appUsartTest1(&boxAppUsarttest);

box_t boxAppUsarttest2 = {13,  71,  5, 0};
tuiAppUsart_t appUsartTest2(&boxAppUsarttest2);
// ******************
// ***** list 3 *****

tuiBase_t*   elementListCntnrX2[] = {
     &appUsartTest1
    ,&appUsartTest2
    ,&TUI_OBJ   (LED_PUR)
    ,&TUI_OBJ   (LED_MAI)     
    ,&TUI_OBJ   (SWITCH_AND)  
    ,&TUI_OBJ   (SWITCH_NOT)  
    ,nullptr  
};

dtyTuiBase_t testCntrX2 (elementListCntnrX2);
box_t boxTestLboxX2 = {17,  73,  4, 0};
tuiBaseLboxX_t testLboxX2 ("testLboxX 2", &boxTestLboxX2 ,&testCntrX2);

// ***** list 2 - end
// ******************



tuiBaseListUnit_t::element_t tuiAppBoard_t::g_baseElementList[] = {
    //{nullptr                   , 1 }
     {&TUI_OBJ   (BUTTON_VIA)   , 1 }
    ,{&TUI_OBJ   (BUTTON_BIO)   , 0 }
    ,{&TUI_OBJ   (BUTTON_VAI)   , 3 }
    ,{&TUI_OBJ   (LED_PER)      , 3 }
    ,{&testLboxX2               , 1 }
    ,{nullptr                   , 1 }
};


// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiBaseWin_t    tuiAppBoard_t::g_baseWin   ("Board Window", &g_box,     {3,1,1,1},      g_baseElementList   );
// -------- MAIN WINDOW define - end
