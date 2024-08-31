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
 * tuiAppUSART_1.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiAppUSART_1.h"
#include "tuiAppPinPort.h"
#include "tuiBaseDgtInOut.h"
#include "tuiBaseLbox.h"
#include "tuiBaseLboxY.h"

#include "tuiTextUsart.h"

#include "dtyArray.h"

// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppUSART_1_t::g_box = {25, 150, 33,  5};
// -------- BOX define - end

// **********************************************************
// -------- ELEMENT LIST define - start
uint8_t par0A;
dtyUint8_t testPar0A(&par0A);
uint8_t par0B;
dtyUint8_t testPar0B(&par0B);
uint8_t par0C;
dtyUint8_t testPar0C(&par0C);
uint8_t par0D;
dtyUint8_t testPar0D(&par0D);
uint8_t par0E;
dtyUint8_t testPar0E(&par0E);
uint8_t par0F;
dtyUint8_t testPar0F(&par0F);
uint8_t par0G;
dtyUint8_t testPar0G(&par0G);
uint8_t par0H;
dtyUint8_t testPar0H(&par0H);

// ******************
// ***** list 0 *****

tuiBaseDgtInOut_t testBaseDgtInOut0A("BaseDgtInOut 0A", {1 ,40 ,1 ,1}, &testPar0A);
tuiBaseDgtInOut_t testBaseDgtInOut0B("BaseDgtInOut 0B", {1 ,40 ,2 ,1}, &testPar0B);
tuiBaseDgtInOut_t testBaseDgtInOut0C("BaseDgtInOut 0C", {1 ,40 ,3 ,1}, &testPar0C);
tuiBaseDgtInOut_t testBaseDgtInOut0D("BaseDgtInOut 0D", {1 ,40 ,4 ,1}, &testPar0D);
tuiBaseDgtInOut_t testBaseDgtInOut0E("BaseDgtInOut 0E", {1 ,40 ,5 ,1}, &testPar0E);
tuiBaseDgtInOut_t testBaseDgtInOut0F("BaseDgtInOut 0F", {1 ,40 ,6 ,1}, &testPar0F);
tuiBaseDgtInOut_t testBaseDgtInOut0G("BaseDgtInOut 0G", {1 ,40 ,7 ,1}, &testPar0G);
tuiBaseDgtInOut_t testBaseDgtInOut0H("BaseDgtInOut 0H", {1 ,40 ,8 ,1}, &testPar0H);

tuiBaseListUnit_t::element_t g_elementBaseListLbox0[] = {
     {&testBaseDgtInOut0A , 1 }
    ,{&testBaseDgtInOut0B , 0 }
    ,{&testBaseDgtInOut0C , 3 }
    ,{&testBaseDgtInOut0D , 3 }
    ,{&testBaseDgtInOut0E , 3 }
    ,{&testBaseDgtInOut0F , 6 }
    ,{&testBaseDgtInOut0G , 3 }
    ,{&testBaseDgtInOut0H ,19 }
    ,{nullptr                   , 1 }
};


// ***** list 0 - end
// ******************

// ******************
// ***** list 1 *****

tuiBaseDgtInOut_t testBaseDgtInOut1A("BaseDgtInOut 1A", {1 ,40 ,1 ,1}, &testPar0A);
tuiBaseDgtInOut_t testBaseDgtInOut1B("BaseDgtInOut 1B", {1 ,40 ,2 ,1}, &testPar0B);
tuiBaseDgtInOut_t testBaseDgtInOut1C("BaseDgtInOut 1C", {1 ,40 ,3 ,1}, &testPar0C);
tuiBaseDgtInOut_t testBaseDgtInOut1D("BaseDgtInOut 1D", {1 ,40 ,4 ,1}, &testPar0D);
tuiBaseDgtInOut_t testBaseDgtInOut1E("BaseDgtInOut 1E", {1 ,40 ,5 ,1}, &testPar0E);
tuiBaseDgtInOut_t testBaseDgtInOut1F("BaseDgtInOut 1F", {1 ,40 ,6 ,1}, &testPar0F);
tuiBaseDgtInOut_t testBaseDgtInOut1G("BaseDgtInOut 1G", {1 ,40 ,7 ,1}, &testPar0G);
tuiBaseDgtInOut_t testBaseDgtInOut1H("BaseDgtInOut 1H", {1 ,40 ,8 ,1}, &testPar0H);

tuiBaseListUnit_t::element_t g_elementBaseListLbox1[] = {
     {&testBaseDgtInOut1A , 1 }
    ,{&testBaseDgtInOut1B , 0 }
    ,{&testBaseDgtInOut1C , 3 }
    ,{&testBaseDgtInOut1D , 3 }
    ,{&testBaseDgtInOut1E , 3 }
    ,{&testBaseDgtInOut1F , 6 }
    ,{&testBaseDgtInOut1G , 3 }
    ,{&testBaseDgtInOut1H ,19 }
    ,{nullptr, 1 }
};

// ***** list 1 - end
// ******************

// ******************
// ***** list 2 *****

tuiBaseDgtInOut_t testBaseDgtInOut2A("BaseDgtInOut 2A", 1, &testPar0A);
tuiBaseDgtInOut_t testBaseDgtInOut2B("BaseDgtInOut 2B", 1, &testPar0B);
tuiBaseDgtInOut_t testBaseDgtInOut2C("BaseDgtInOut 2C", 1, &testPar0C);
tuiBaseDgtInOut_t testBaseDgtInOut2D("BaseDgtInOut 2D", 1, &testPar0D);
tuiBaseDgtInOut_t testBaseDgtInOut2E("BaseDgtInOut 2E", 1, &testPar0E);
tuiBaseDgtInOut_t testBaseDgtInOut2F("BaseDgtInOut 2F", 1, &testPar0F);
tuiBaseDgtInOut_t testBaseDgtInOut2G("BaseDgtInOut 2G", 1, &testPar0G);
tuiBaseDgtInOut_t testBaseDgtInOut2H("BaseDgtInOut 2H", 1, &testPar0H);

tuiBaseListElem_t   g_elementBaseListLboxY2[] = {
     {&testBaseDgtInOut2A , 1 }
    ,{&testBaseDgtInOut2B , 0 }
    ,{&testBaseDgtInOut2C , 3 }
    ,{&testBaseDgtInOut2D , 3 }
    ,{&testBaseDgtInOut2E , 3 }
    ,{&testBaseDgtInOut2F , 6 }
    ,{&testBaseDgtInOut2G , 3 }
    ,{&testBaseDgtInOut2H ,19 }
    ,{nullptr                   , 1 }
};


// ***** list 2 - end
// ******************


box_t testLboxBox0 = {14,30,2,5};
tuiBaseLbox_t testBaseLbox0("testBaseLbox 0", &testLboxBox0, g_elementBaseListLbox0);

box_t testLboxBox1 = {14,30,2,45};
tuiBaseLbox_t testBaseLbox1("testBaseLbox 1", &testLboxBox1, g_elementBaseListLbox1);

box_t testLboxBoxY2 = {5,30,2,85};
tuiBaseLboxY_t testBaseLboxY2("testBaseLbox 2", &testLboxBoxY2, g_elementBaseListLboxY2);

uint8_t appBufferLog[1000000];
uint8_t appBufferIn1[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11
};

uint8_t appBufferIn2[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22
};

uint8_t appBufferIn3[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33
};

uint8_t appBufferInnn[] = {
//  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x00,0x00,0x00,0x00
};


dtyBuffer_t appArrayCntnr[] = {
     {appBufferIn1, sizeof(appBufferIn1)}
    ,{appBufferIn2, sizeof(appBufferIn2)}
    ,{appBufferIn3, sizeof(appBufferIn3)}
};
//dtyArray_t      testArrayBufferIn(appArrayCntnr,sizeof(appArrayCntnr));
//dtyStuf_t       testBuffer0(appBufferLog, sizeof(appBufferLog), testArrayBufferIn);
uint8_t appBufferLog1[1000000]; dtyStuf_t       testBuffer1(appBufferLog1, sizeof(appBufferLog1), appArrayCntnr, sizeof(appArrayCntnr));
uint8_t appBufferLog2[1000000]; dtyStuf_t       testBuffer2(appBufferLog2, sizeof(appBufferLog2), appArrayCntnr, sizeof(appArrayCntnr));
dtyStuf_t       testBuffer3(appBufferLog, sizeof(appBufferLog), appBufferInnn, sizeof(appBufferInnn));
uint8_t appBufferLog4[1000000]; dtyStuf_t       testBuffer4(appBufferLog4, sizeof(appBufferLog4), appArrayCntnr, sizeof(appArrayCntnr));

//dtyStuf_t       testBuffer1(appBufferLog, sizeof(appBufferLog), appBufferIn, sizeof(appBufferIn));
//dtyStuf_t       testBuffer2(appBufferLog, sizeof(appBufferLog), appBufferInnn, sizeof(appBufferInnn));
//dtyStuf_t       testBuffer3(appBufferLog, sizeof(appBufferLog), appBufferInnn, sizeof(appBufferInnn));
//dtyStuf_t       testBuffer4(appBufferLog, sizeof(appBufferLog), appBufferIn, sizeof(appBufferIn));

tuiTextUsart_t  testTextUsart1("testTextUsart1", {5,  60,  2,  85}, &testBuffer1);
tuiTextUsart_t  testTextUsart2("testTextUsart2", {9,  35,  7,  75}, &testBuffer2);
tuiTextUsart_t  testTextUsart3("testTextUsart3", {5,  35,  7, 110}, &testBuffer3);
tuiTextUsart_t  testTextUsart4("testTextUsart4", {7, 140, 16,   5}, &testBuffer4);


tuiBaseWin_t::element_t tuiAppUSART_1_t::g_elementBaseList[] = {
     {&testBaseLbox0, 1}
    ,{&testBaseLbox1, 1}
    //,{&testBaseLboxY2, 1}
    ,{&testTextUsart1, 1}
    ,{&testTextUsart2, 1}
    ,{&testTextUsart3, 1}
    ,{&testTextUsart4, 1}
    ,{nullptr, 1}
};

// -------- ELEMENT LIST define - end


// **********************************************************
// -------- MAIN WINDOW define - start
tuiBaseWin_t    tuiAppUSART_1_t::g_baseWin  ("USART_1 base window"   ,&g_box                 ,g_elementBaseList);
// -------- MAIN WINDOW define - end
