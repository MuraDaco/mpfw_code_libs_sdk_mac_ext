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
#include "tuiDgtInOut.h"
#include "tuiBaseDgtInOut.h"

#include "tuiLbox.h"
#include "tuiBaseLbox.h"

// **********************************************************
// -------- BOX define - start
// ............................ H   W  Yo  Xo
box_t tuiAppUSART_1_t::g_box = {25, 150, 33,  5};
// -------- BOX define - end

// **********************************************************
// -------- ZONE LIST define - start
void tuiAppUSART_1_t::zone_1_hndl    (void)  {
}

void tuiAppUSART_1_t::zone_2_hndl    (void)  {
}

tuiBaseUnit_t::zone_t tuiAppUSART_1_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_1_hndl}
    ,{{1, 2, 3, 4}, zone_2_hndl}
    ,{{1, 2, 3, 4}, nullptr}
};
// -------- ZONE LIST define - end

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

tuiDgtInOut_t testDgtInOut0A("DgtInOut 0A", {0 ,0 ,1 ,1}, &testPar0A);
tuiDgtInOut_t testDgtInOut0B("DgtInOut 0B", {0 ,0 ,2 ,1}, &testPar0B);
tuiDgtInOut_t testDgtInOut0C("DgtInOut 0C", {0 ,0 ,3 ,1}, &testPar0C);
tuiDgtInOut_t testDgtInOut0D("DgtInOut 0D", {0 ,0 ,4 ,1}, &testPar0D);
tuiDgtInOut_t testDgtInOut0E("DgtInOut 0E", {0 ,0 ,5 ,1}, &testPar0E);
tuiDgtInOut_t testDgtInOut0F("DgtInOut 0F", {0 ,0 ,6 ,1}, &testPar0F);
tuiDgtInOut_t testDgtInOut0G("DgtInOut 0G", {0 ,0 ,7 ,1}, &testPar0G);
tuiDgtInOut_t testDgtInOut0H("DgtInOut 0H", {0 ,0 ,8 ,1}, &testPar0H);


tuiBaseWlistUnit_t::element_t g_elementListLbox0[] = {
     {&testDgtInOut0A , 1 }
    ,{&testDgtInOut0B , 0 }
    ,{&testDgtInOut0C , 3 }
    ,{&testDgtInOut0D , 3 }
    ,{&testDgtInOut0E , 3 }
    ,{&testDgtInOut0F , 6 }
    ,{&testDgtInOut0G , 3 }
    ,{&testDgtInOut0H ,19 }
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
    ,{nullptr                   , 1 }
};


tuiDgtInOut_t testDgtInOut1A("DgtInOut 1A", {0 ,0 ,1 ,1}, &testPar0A);
tuiDgtInOut_t testDgtInOut1B("DgtInOut 1B", {0 ,0 ,2 ,1}, &testPar0B);
tuiDgtInOut_t testDgtInOut1C("DgtInOut 1C", {0 ,0 ,3 ,1}, &testPar0C);
tuiDgtInOut_t testDgtInOut1D("DgtInOut 1D", {0 ,0 ,4 ,1}, &testPar0D);
tuiDgtInOut_t testDgtInOut1E("DgtInOut 1E", {0 ,0 ,5 ,1}, &testPar0E);
tuiDgtInOut_t testDgtInOut1F("DgtInOut 1F", {0 ,0 ,6 ,1}, &testPar0F);
tuiDgtInOut_t testDgtInOut1G("DgtInOut 1G", {0 ,0 ,7 ,1}, &testPar0G);
tuiDgtInOut_t testDgtInOut1H("DgtInOut 1H", {0 ,0 ,8 ,1}, &testPar0H);


tuiBaseWlistUnit_t::element_t g_elementListLbox1[] = {
     {&testDgtInOut1A , 1 }
    ,{&testDgtInOut1B , 0 }
    ,{&testDgtInOut1C , 3 }
    ,{&testDgtInOut1D , 3 }
    ,{&testDgtInOut1E , 3 }
    ,{&testDgtInOut1F , 6 }
    ,{&testDgtInOut1G , 3 }
    ,{&testDgtInOut1H ,19 }
    ,{nullptr                   , 1 }
};

// ***** list 1 - end
// ******************

// ******************
// ***** list 2 *****

tuiBaseDgtInOut_t testBaseDgtInOut2A("BaseDgtInOut 2A", {1 ,40 ,1 ,1}, &testPar0A);
tuiBaseDgtInOut_t testBaseDgtInOut2B("BaseDgtInOut 2B", {1 ,40 ,2 ,1}, &testPar0B);
tuiBaseDgtInOut_t testBaseDgtInOut2C("BaseDgtInOut 2C", {1 ,40 ,3 ,1}, &testPar0C);
tuiBaseDgtInOut_t testBaseDgtInOut2D("BaseDgtInOut 2D", {1 ,40 ,4 ,1}, &testPar0D);
tuiBaseDgtInOut_t testBaseDgtInOut2E("BaseDgtInOut 2E", {1 ,40 ,5 ,1}, &testPar0E);
tuiBaseDgtInOut_t testBaseDgtInOut2F("BaseDgtInOut 2F", {1 ,40 ,6 ,1}, &testPar0F);
tuiBaseDgtInOut_t testBaseDgtInOut2G("BaseDgtInOut 2G", {1 ,40 ,7 ,1}, &testPar0G);
tuiBaseDgtInOut_t testBaseDgtInOut2H("BaseDgtInOut 2H", {1 ,40 ,8 ,1}, &testPar0H);

tuiBaseListUnit_t::element_t g_elementBaseListLbox2[] = {
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


tuiDgtInOut_t testDgtInOut2A("DgtInOut 2A", {0 ,0 ,1 ,1}, &testPar0A);
tuiDgtInOut_t testDgtInOut2B("DgtInOut 2B", {0 ,0 ,2 ,1}, &testPar0B);
tuiDgtInOut_t testDgtInOut2C("DgtInOut 2C", {0 ,0 ,3 ,1}, &testPar0C);
tuiDgtInOut_t testDgtInOut2D("DgtInOut 2D", {0 ,0 ,4 ,1}, &testPar0D);
tuiDgtInOut_t testDgtInOut2E("DgtInOut 2E", {0 ,0 ,5 ,1}, &testPar0E);
tuiDgtInOut_t testDgtInOut2F("DgtInOut 2F", {0 ,0 ,6 ,1}, &testPar0F);
tuiDgtInOut_t testDgtInOut2G("DgtInOut 2G", {0 ,0 ,7 ,1}, &testPar0G);
tuiDgtInOut_t testDgtInOut2H("DgtInOut 2H", {0 ,0 ,8 ,1}, &testPar0H);


tuiBaseWlistUnit_t::element_t g_elementListLbox2[] = {
     {&testDgtInOut2A , 1 }
    ,{&testDgtInOut2B , 0 }
    ,{&testDgtInOut2C , 3 }
    ,{&testDgtInOut2D , 3 }
    ,{&testDgtInOut2E , 3 }
    ,{&testDgtInOut2F , 6 }
    ,{&testDgtInOut2G , 3 }
    ,{&testDgtInOut2H ,19 }
    ,{nullptr                   , 1 }
};

// ***** list 2 - end
// ******************


box_t testLboxBox0 = {14,30,2,5};
tuiLbox_t testLbox0("testLbox 0", &testLboxBox0, nullptr, g_elementListLbox0);
tuiBaseLbox_t testBaseLbox0("testBaseLbox 0", &testLboxBox0, g_elementBaseListLbox0);

box_t testLboxBox1 = {14,30,2,45};
tuiLbox_t testLbox1("testLbox 1", &testLboxBox1, nullptr, g_elementListLbox1);
tuiBaseLbox_t testBaseLbox1("testBaseLbox 1", &testLboxBox1, g_elementBaseListLbox1);

box_t testLboxBox2 = {14,30,2,85};
tuiLbox_t testLbox2("testLbox 2", &testLboxBox2, nullptr, g_elementListLbox2);
tuiBaseLbox_t testBaseLbox2("testBaseLbox 2", &testLboxBox2, g_elementBaseListLbox2);

tuiWin_t::element_t tuiAppUSART_1_t::g_elementList[] = {
     {&testLbox0, 1}
    ,{&testLbox1, 1}
    ,{&testLbox2, 1}
    ,{nullptr, 1}
};

tuiBaseWin_t::element_t tuiAppUSART_1_t::g_elementBaseList[] = {
     {&testBaseLbox0, 1}
    ,{&testBaseLbox1, 1}
    ,{&testBaseLbox2, 1}
    ,{nullptr, 1}
};

// -------- ELEMENT LIST define - end


// **********************************************************
// -------- MAIN WINDOW define - start
tuiWin_t        tuiAppUSART_1_t::g_win      ("USART_1 window"        ,&g_box ,g_zoneList     ,g_elementList);
tuiBaseWin_t    tuiAppUSART_1_t::g_baseWin  ("USART_1 base window"   ,&g_box                 ,g_elementBaseList);
// -------- MAIN WINDOW define - end
