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
 * tuiAppUsart.cpp
 *
 *  Created on: Sep, 8th 2024
 *      Author: Marco Dau
 */
 
#include "tuiAppUsart.h"


/*

// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppUsart::g_box = {25,  75,  8, 80};
// -------- BOX define - end


// **********************************************************
// -------- ELEMENT LIST define - start
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_NEO    ,1 ,40 , 3 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_MAO    ,1 ,40 , 4 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,BUTTON_LEO    ,1 ,40 , 5 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_RAI       ,1 ,40 , 6 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_REO       ,1 ,40 , 7 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,LED_REI       ,1 ,40 , 8 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_XOR    ,1 ,40 , 9 ,1  )
TUI_DEF_CPP_BOX (tuiBaseDgtInOut_t     ,mcuPinPort_t   ,SWITCH_NOR    ,1 ,40 ,10 ,1  )


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

uint8_t usartTextBuffer[1000000]; dtyStuf_t       usartTextCntr(usartTextBuffer, sizeof(usartTextBuffer), initUsartTextCntnr, sizeof(initUsartTextCntnr));
tuiTextUsart_t  usartText("USART Text", {8, 71, 1,   1}, &usartTextCntr);

char usartBuffer[1000] = "Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor";
dtyBaseArray_t usartString(usartBuffer, sizeof(usartBuffer));
tuiBaseEbox_t   usartSendEbox("USART send Ebox", {3,  71, 9, 1}, &usartString);

box_t boxUsartSubWin = {13,  73,  11, 1};
tuiBaseListUnit_t::element_t eListUsartSubWin[] = {
    //{nullptr                   , 1 }
     {&usartText                , 1 }
    ,{&usartSendEbox            , 1 }
    ,{nullptr                   , 1 }
};
tuiBaseSubWin_t    usartSubWin  ("USART Sub Window", &boxUsartSubWin,  eListUsartSubWin   );

tuiBaseListUnit_t::element_t tuiAppUsart::g_baseElementList[] = {
    //{nullptr                   , 1 }
     {&TUI_OBJ   (BUTTON_NEO)   , 1 }
    ,{&TUI_OBJ   (BUTTON_MAO)   , 0 }
    ,{&TUI_OBJ   (BUTTON_LEO)   , 3 }
    ,{&TUI_OBJ   (LED_RAI)      , 3 }
    ,{&TUI_OBJ   (LED_REO)      , 3 }
    ,{&TUI_OBJ   (LED_REI)      , 3 }
    ,{&TUI_OBJ   (SWITCH_XOR)   , 6 }
    ,{&TUI_OBJ   (SWITCH_NOR)   , 6 }
    ,{&usartSubWin              , 8 }
    ,{nullptr                   , 1 }
};

// -------- ELEMENT LIST define - end

// **********************************************************
// -------- MAIN WINDOW define - start
tuiBaseWin_t    tuiAppUsart::g_baseWin  ("PinPort Window", &g_box,              g_baseElementList   );
// -------- MAIN WINDOW define - end

*/

uint8_t tuiAppUsart_t::initBufferIn1[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11
};

uint8_t tuiAppUsart_t::initBufferIn2[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22
};

uint8_t tuiAppUsart_t::initBufferIn3[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33
};

dtyBuffer_t tuiAppUsart_t::initUsartTextCntnr[] = {
     {initBufferIn1, sizeof(initBufferIn1)}
    ,{initBufferIn2, sizeof(initBufferIn2)}
    ,{initBufferIn3, sizeof(initBufferIn3)}
};

tuiAppUsart_t::tuiAppUsart_t   (void)   :
    // tuiBaseSubWin_t    usartSubWin   ("USART Sub Window", &boxUsartSubWin,  eListUsartSubWin   );
    tuiBaseSubWin_t                     ("USART Sub Window", nullptr,  g_eList  )

    ,usartTextCntr                      (usartTextBuffer, sizeof(usartTextBuffer), initUsartTextCntnr, sizeof(initUsartTextCntnr))
    // tuiTextUsart_t  usartText        ("USART Text", {8, 71, 1,   1}, &usartTextCntr);
    ,g_text                              {"USART Text", {7, 71, 1,   1}, nullptr}

    ,usartBuffer            {"Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor"}
    ,usartString            {usartBuffer, sizeof(usartBuffer)}
    // tuiBaseEbox_t   usartSendEbox    ("USART send Ebox", {3,  71, 9, 1}, &usartString);
    ,g_ebox                              {"USART send Ebox", {3,  71, 9, 1}, &usartString}
    ,g_button                           {"send", 4, {1,4,8,71-4}, buttonFunction}
    ,g_eList     {
                     {&g_text,      1}
                    ,{&g_button,    1}
                    ,{&g_ebox,      1}
                    ,{nullptr,      1}
                    }
{}

    
tuiAppUsart_t::tuiAppUsart_t   (box_t* p_pBox)   :
    // tuiBaseSubWin_t    usartSubWin   ("USART Sub Window", &boxUsartSubWin,  eListUsartSubWin   );
    tuiBaseSubWin_t                     ("USART Sub Window", p_pBox,  g_eList  )

    ,usartTextCntr                      (usartTextBuffer, sizeof(usartTextBuffer), initUsartTextCntnr, sizeof(initUsartTextCntnr))
    // tuiTextUsart_t  usartText        ("USART Text", {8, 71, 1,   1}, &usartTextCntr);
    ,g_text                              {"USART Text", {7, 71, 1,   1}, &usartTextCntr}

    ,usartBuffer            {"Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor"}
    ,usartString            {usartBuffer, sizeof(usartBuffer)}
    // tuiBaseEbox_t   usartSendEbox    ("USART send Ebox", {3,  71, 9, 1}, &usartString);
    ,g_ebox                             {"USART send Ebox", {3,  71, 9, 1}, &usartString}
    ,g_button                           {"send", 4, {1,4,8,71-4}, buttonFunction}
    ,g_eList     {
                     {&g_text,      1}
                    ,{&g_button,    1}
                    ,{&g_ebox,      1}
                    ,{nullptr,      1}
                    }
{}

void tuiAppUsart_t::buttonFunction  (void)      {
    if(g_po)    {
        tuiAppUsart_t* l_this = static_cast<tuiAppUsart_t*>(g_po);

        // read  from g_ebox/usartString
        // write to   g_text/usartTextCntr
        l_this->usartTextCntr.add(   
            reinterpret_cast<uint8_t*>(l_this->usartString.pArrayGet()),
            l_this->usartString.lengthGet(),
            dtyStuf_t::kMarker_t::testTx,
            dtyStuf_t::kDataType_t::ascii
            );

        //l_this->eventOn();      // frameNname(tuiMode_t::eventOn);
    }
}
