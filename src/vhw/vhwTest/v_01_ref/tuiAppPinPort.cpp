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
 * tuiAppPinPort.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
#include "tuiAppPinPort.h"
#include "tuiBaseDgtInOut.h"
#include "tuiDigitalInOut.h"
//#include "tuiDigitalInOut2.h"

#include "tuiBaseLboxX.h"
#include "tuiBaseEbox.h"
#include "tuiTextUsartX.h"
#include "tuiBaseSubWin.h"

#include "vhwPphTbl_Buttons.h"
#include "vhwPphTbl_Leds.h"
#include "vhwPphTbl_Mod1.h"


// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppPinPort_t::g_box = {25,  75,  0, 75};
// -------- BOX define - end



// ******************
// ***** list 3 *****

uint8_t par3A;  dtyUint8_t testPar3A(&par3A);
uint8_t par3B;  dtyUint8_t testPar3B(&par3B);
uint8_t par3C;  dtyUint8_t testPar3C(&par3C);
uint8_t par3D;  dtyUint8_t testPar3D(&par3D);
uint8_t par3E;  dtyUint8_t testPar3E(&par3E);
uint8_t par3F;  dtyUint8_t testPar3F(&par3F);
uint8_t par3G;  dtyUint8_t testPar3G(&par3G);
uint8_t par3H;  dtyUint8_t testPar3H(&par3H);


tuiBaseDgtInOut_t testBaseDgtInOut3A("BaseDgtInOut 3A", 1, &testPar3A);
tuiBaseDgtInOut_t testBaseDgtInOut3B("BaseDgtInOut 3B", 1, &testPar3B);
tuiBaseDgtInOut_t testBaseDgtInOut3C("BaseDgtInOut 3C", 1, &testPar3C);
tuiBaseDgtInOut_t testBaseDgtInOut3D("BaseDgtInOut 3D", 1, &testPar3D);
tuiBaseDgtInOut_t testBaseDgtInOut3E("BaseDgtInOut 3E", 1, &testPar3E);
tuiBaseDgtInOut_t testBaseDgtInOut3F("BaseDgtInOut 3F", 1, &testPar3F);
tuiBaseDgtInOut_t testBaseDgtInOut3G("BaseDgtInOut 3G", 1, &testPar3G);
tuiBaseDgtInOut_t testBaseDgtInOut3H("BaseDgtInOut 3H", 1, &testPar3H);

tuiBase_t*   elementListCntnrX1[] = {
     &testBaseDgtInOut3A
    ,&testBaseDgtInOut3B
    ,&testBaseDgtInOut3C
    ,&testBaseDgtInOut3D
    ,&testBaseDgtInOut3E
    ,&testBaseDgtInOut3F
    ,&testBaseDgtInOut3G
    ,&testBaseDgtInOut3H
    ,nullptr  
};

dtyTuiBase_t testCntrX1 (elementListCntnrX1);
box_t boxTestLboxX1 = {5,  30,  0, 30};
tuiBaseLboxX_t testLboxX1 ("testLboxX 1", &boxTestLboxX1 ,&testCntrX1);

// ***** list 2 - end
// ******************

// **********************************************************
// -------- ELEMENT LIST define - start
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_NEO    ,1 ,25 , 0 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_MAO    ,1 ,25 , 1 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_LEO    ,1 ,25 , 2 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_RAI       ,1 ,25 , 3 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_REO       ,1 ,25 , 4 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_REI       ,1 ,25 , 5 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_XOR    ,1 ,25 , 6 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_NOR    ,1 ,25 , 7 ,1  )


uint8_t initBufferIn1[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11
};

uint8_t initBufferIn2[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22
};

uint8_t initBufferIn3[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33
};

dtyBuffer_t initUsartTextCntnr[] = {
     {initBufferIn1, sizeof(initBufferIn1)}
    ,{initBufferIn2, sizeof(initBufferIn2)}
    ,{initBufferIn3, sizeof(initBufferIn3)}
};
/*
uint8_t usartTextBuffer[1000000]; dtyStuf_t       usartTextCntr(usartTextBuffer, sizeof(usartTextBuffer), initUsartTextCntnr, sizeof(initUsartTextCntnr));
tuiTextUsart_t  usartText("USART Text", {8, 71, 1,   1}, &usartTextCntr);
*/
uint8_t usartTextBuffer[1000000]; dtyStufX_t       usartTextCntrX(usartTextBuffer, sizeof(usartTextBuffer), initUsartTextCntnr, sizeof(initUsartTextCntnr));
tuiTextUsartX_t  usartTextX("USART Text-X", {7, 71, 0,   0}, &usartTextCntrX);

char usartBuffer[1000] = "Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor";
dtyBaseArray_t usartString(usartBuffer, sizeof(usartBuffer));
tuiBaseEbox_t   usartSendEbox("USART send Ebox", {3,  71, 8, 0}, &usartString);

box_t boxUsartSubWin = {16,  73,  5, 0};
tuiBaseListUnit_t::element_t eListUsartSubWin[] = {
    //{nullptr                   , 1 }
     {&usartTextX               , 1 }
    ,{&usartSendEbox            , 1 }
    ,{nullptr                   , 1 }
};
tuiBaseSubWin_t    usartSubWin  ("USART Sub Window", &boxUsartSubWin,  {2,1,1,1}, eListUsartSubWin   );

tuiBaseListUnit_t::element_t tuiAppPinPort_t::g_baseElementList[] = {
    //{nullptr                   , 1 }
     {&TUI_OBJ   (BUTTON_NEO)   , 1 }
    ,{&TUI_OBJ   (BUTTON_MAO)   , 0 }
    ,{&TUI_OBJ   (BUTTON_LEO)   , 3 }
    ,{&TUI_OBJ   (LED_RAI)      , 3 }
    ,{&TUI_OBJ   (LED_REO)      , 3 }
    ,{&testLboxX1               , 6 }
    //,{&TUI_OBJ   (LED_REI)      , 3 }
    //,{&TUI_OBJ   (SWITCH_XOR)   , 6 }
    //,{&TUI_OBJ   (SWITCH_NOR)   , 6 }
    ,{&usartSubWin              , 8 }
    ,{nullptr                   , 1 }
};

// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiBaseWin_t    tuiAppPinPort_t::g_baseWin  ("PinPort Window", &g_box, {3,1,1,1},              g_baseElementList   );
// -------- MAIN WINDOW define - end
