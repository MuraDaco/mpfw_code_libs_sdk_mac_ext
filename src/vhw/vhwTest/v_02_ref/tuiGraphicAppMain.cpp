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

// **************************************************
// *** start section - STANDARD DEFINITIONS

    uint8_t tuiGraphicAppMain_t::g_initBufferIn1[] = {
    //  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
        '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11
    };

    uint8_t tuiGraphicAppMain_t::g_initBufferIn2[] = {
    //  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
        '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22
    };

    uint8_t tuiGraphicAppMain_t::g_initBufferIn3[] = {
    //  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
        '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33
    };

    //                                            01234567890    5    2    5    3    5    4    5    5    5    6    5    9    5    9    5    9
    char tuiGraphicAppMain_t::usartBuffer[1000] = "Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor";
    char tuiGraphicAppMain_t::g_fmtString[150] =  "Test about formatted string-this is a strin345678- this is the third row3456789(90)";

    uint8_t tuiGraphicAppMain_t::g_stringBuffer[1000000];

    // *** end   section - STANDARD DEFINITION
    // **************************************************
// -------------------------------------------------------
// **************************************************
// *** start section - BASE ELEMENTS DEFINITION

    dtyBuffer_t tuiGraphicAppMain_t::g_initUsartTextCntnr[] = {
         {g_initBufferIn1, sizeof(g_initBufferIn1)}
        ,{g_initBufferIn2, sizeof(g_initBufferIn2)}
        ,{g_initBufferIn3, sizeof(g_initBufferIn3)}
        };

    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_1      ("Unit Debug 111");
    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_2      ("Unit Debug 222");
    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_3      ("Unit Debug 333");
    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_4      ("Unit Debug 444");
    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_5      ("Unit Debug 555");
    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_6      ("Unit Debug 666");
    tuiUnitDebug_t  tuiGraphicAppMain_t::g_unitDebug_7      ("Unit Debug 777");

    tuiUnitEbox_t   tuiGraphicAppMain_t::g_unitEbox_1   ("Unit Ebox 1", usartString);
        dtyBaseArray_t  tuiGraphicAppMain_t::usartString    (usartBuffer, sizeof(usartBuffer));

    tuiUnitFormattedString_t    tuiGraphicAppMain_t::g_unitStringA      ("Unit Formatted string", &g_dtyStringA);
        dtyString_t     tuiGraphicAppMain_t::g_dtyStringA = {g_fmtString, sizeof(g_fmtString)};

    tuiUnitFormattedStringCntnr_t   tuiGraphicAppMain_t::g_unitStringZ      ("Unit Formatted string suitable inside a container", &g_dtyStringA);
        // dtyString_t                 tuiGraphicAppMain_t::g_dtyStringA = {g_fmtString, sizeof(g_fmtString)};

    // *** end   section - BASE ELEMENTS DEFINITION
    // **************************************************
// -------------------------------------------------------
// **************************************************
// *** start section - BASE CONTAINERS ELEMENTS DEFINITION
    tuiUnitCntnrList_t  tuiGraphicAppMain_t::g_unitTextUsart_1("Text Usart 1", &g_cntrString);
        dtyProtocolData_t tuiGraphicAppMain_t::g_cntrString (g_stringBuffer, sizeof(g_stringBuffer), g_initUsartTextCntnr, sizeof(g_initUsartTextCntnr));

    tuiUnitCntnrList_t  tuiGraphicAppMain_t::g_unitTextUsart_2("New Text Usart 2", &g_cntrStreamData_2);
        dtyCntnrStreamList_t tuiGraphicAppMain_t::g_cntrStreamData_2    (g_stringBuffer, sizeof(g_stringBuffer), g_initUsartTextCntnr, sizeof(g_initUsartTextCntnr), &g_cntnrStreamString, &g_cntnrStreamGraphicUnit);
            tuiGraphicUnitBase_t             tuiGraphicAppMain_t::g_cntnrStreamGraphicUnit  (&g_cntnrStreamString, box_t({8, 0, 0,  0}));
            tuiUnitFormattedStringCntnr_t    tuiGraphicAppMain_t::g_cntnrStreamString;

    tuiUnitCntnrList_t  tuiGraphicAppMain_t::g_unitTextUsart_3("New Text Usart 3", &g_cntrStreamData_3);
        dtyCntnrStreamOfFormattedString_t   tuiGraphicAppMain_t::g_cntrStreamData_3    (g_stringBuffer, sizeof(g_stringBuffer), g_initUsartTextCntnr, sizeof(g_initUsartTextCntnr));

    tuiUnitCntnrList_t  tuiGraphicAppMain_t::g_unitTextUsart_4("New Text Usart 4", &g_cntrStreamData_4);
        dtyCntnrStreamOfFormattedString_t   tuiGraphicAppMain_t::g_cntrStreamData_4    (g_stringBuffer, sizeof(g_stringBuffer), g_initUsartTextCntnr, sizeof(g_initUsartTextCntnr));


    // *** end   section - BASE CONTAINERS ELEMENTS DEFINITION
    // **************************************************
// -------------------------------------------------------
// **************************************************
// *** start section - WINDOW ELEMENTS ARRAYS DEFINITION
    tuiGraphicUnitWin_t    tuiGraphicAppMain_t::g_elementSetOfRootWin[] = {
        {   &g_unitDebugWin_1,      box_t({69,  95,   0,   0}), margins_t({2,1,2,2})                          },
        {   &g_unitSubCntnrWin_T,   box_t({35,  35,   0,  95})                          },
        {   &g_unitDebugWin_3,      box_t({34,  75,  35,  95})                          },
        {}  // null element to mark the and of array; 
        };

        tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setDebug[] = {
            {   &g_unitTextUsart_1,     box_t({10, 30, 20,  0})                         },
            {   &g_unitTextUsart_2,     box_t({10, 30,  0, 30})                         },
            {   &g_unitStringA,         box_t({10, 30, 20, 30})                         },
            //    {   &g_unitSubCntnrWin_T,   box_t({20, 30, 10, 90})                         },
            {   &g_unitDebug_1,         box_t({10, 30,  0,  0})                         },
            {   &g_unitDebug_2,         box_t({10, 30, 10, 30}), margins_t({2,1,2,1})   },
            {   &g_unitDebug_3,         box_t({10, 30, 10, 60}), margins_t({1,2,1,1})   },
            {   &g_unitDebug_2,         box_t({10, 30,  0, 60}), margins_t({1,1,1,2})   },
            {   &g_unitEbox_1,          box_t({10, 30, 20, 60}), margins_t({2,1,1,3})   },
            {   &g_unitCntnrWin_A,      box_t({30,  92,  31,   0}),  margins_t({2,1,2,2})                          },
            {   &g_unitDebugWin_2,      box_t({14,  92,  61,   0}),  margins_t({2,1,2,2})                          },
            {}  // null element to mark the and of array; 
            };

                tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_arrayCntnrDebug[] = {
                    {   &g_unitDebug_1, box_t({ 8, 24,  0,  0})                         },
                    {   &g_unitDebug_2, box_t({10, 22,  0,  0}), margins_t({2,1,2,1})   },
                    {   &g_unitDebug_3, box_t({ 5, 20,  0,  0}), margins_t({1,2,1,1})   },
                    {   &g_unitDebug_2, box_t({ 5, 20,  0,  0}), margins_t({1,1,1,2})   },
                    {   &g_unitDebug_4, box_t({ 5, 20,  0,  0}), margins_t({2,1,1,2})   },
                    {   &g_unitDebug_5, box_t({ 6, 20,  0,  0}), margins_t({1,2,1,1})   },
                    {   &g_unitDebug_6, box_t({11, 20,  0,  0}), margins_t({1,1,1,2})   },
                    {   &g_unitDebug_7, box_t({ 8, 20,  0,  0})                         },
                    {   &g_unitDebug_5, box_t({ 6, 20,  0,  0}), margins_t({1,2,1,1})   },
                    {}  // null element to mark the and of array; 
                    };

                    tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setSubDebug2[] = {
                        {   &g_unitDebug_1,         box_t({10, 30,  0,  0})     },
                        {   &g_unitDebug_2,         box_t({10, 30, 10, 30})     },
                        {   &g_unitStringZ,         box_t({10, 30, 20, 30})     },
                        {}  // null element to mark the and of array; 
                    };

        tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_arraySubCntnrDebug[] = {
            {   &g_unitStringA, box_t({10, 20, 0,  0})                         },
            {   &g_unitStringA, box_t({10, 20, 0,  0})                         },
            {   &g_unitStringA, box_t({10, 20, 0,  0})                         },
            //    {   &g_unitCntnrWin_A,      box_t({35,  32,   0, 0})                          },
            {   &g_unitStringA, box_t({10, 20, 0,  0})                         },
            {   &g_unitStringA, box_t({10, 20, 0,  0})                         },
            {}  // null element to mark the and of array; 
            };

        tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setWindow_3[] = {
            {   &g_unitTextUsart_3,     box_t({ 10, 25,  0,  0})                         },
            {   &g_unitTextUsart_4,     box_t({ 15, 20, 10,  0})                         },
            {   &g_unitStringA,         box_t({  6, 30, 25,  0})                         },
            {   &g_unitDebug_1,         box_t({  8, 24,  0, 26})                         },
            {   &g_unitDebug_2,         box_t({  5, 18, 10, 31}), margins_t({2,1,2,1})   },
            {   &g_unitDebug_3,         box_t({  4, 15, 15, 31}), margins_t({1,2,1,1})   },
            {   &g_unitDebug_2,         box_t({  8, 40, 32, 10}), margins_t({2,1,2,1})   },
            // {   &g_unitDebug_2,         box_t({ 0, 30,  0, 60}), margins_t({1,1,1,2})   },
            // {   &g_unitEbox_1,          box_t({ 0, 30, 20, 60}), margins_t({2,1,1,3})   },
            // {   &g_unitDebugWin_2,      box_t({ 4,  92,  31,   0}),  margins_t({2,1,2,2})                          },
            {}  // null element to mark the and of array; 
            };

    // *** end   section - WINDOW ELEMENTS ARRAY DEFINITION
    // **************************************************
// -------------------------------------------------------
// **************************************************
// *** start section - WINDOW SET/LIST CONTAINERS DEFINITION
    tuiGraphicUnitRoot_t    tuiGraphicAppMain_t::g_boxRoot      (&g_unitRootWin   ,margins_t({5,2,5,5}));
        tuiUnitSet_t            tuiGraphicAppMain_t::g_unitRootWin  ("Unit Root Window", g_elementSetOfRootWin);
            // tuiGraphicUnitWin_t    tuiGraphicAppMain_t::g_elementSetOfRootWin[] = {
                tuiUnitCntnrList_t      tuiGraphicAppMain_t::g_unitDebugWin_1       ("Cntnr debug Window 1", &g_cntnrSetDebug);
                    dtyCntnrArraySet_t      tuiGraphicAppMain_t::g_cntnrSetDebug(g_setDebug);
                        // tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setDebug[] = {
                            tuiUnitCntnrList_t      tuiGraphicAppMain_t::g_unitCntnrWin_A       ("Cntnr debug Window A", &g_CntnrDebug);
                                dtyTuiGraphic_t    tuiGraphicAppMain_t::g_CntnrDebug(g_arrayCntnrDebug);
                                    // tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_arrayCntnrDebug[] = {
                            tuiUnitCntnrList_t      tuiGraphicAppMain_t::g_unitDebugWin_2       ("Unit debug Window 2", &g_cntnrSetDebugWin2);
                                dtyCntnrArraySet_t    tuiGraphicAppMain_t::g_cntnrSetDebugWin2(g_setSubDebug2);
                                    // tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_setSubDebug2[] = {

                tuiUnitCntnrList_t      tuiGraphicAppMain_t::g_unitSubCntnrWin_T    ("Cntnr Sub-Cntr T", &g_SubCntnrDebug);
                    dtyTuiGraphic_t         tuiGraphicAppMain_t::g_SubCntnrDebug(g_arraySubCntnrDebug);
                        // tuiGraphicUnitBase_t    tuiGraphicAppMain_t::g_arraySubCntnrDebug[] = {

                tuiUnitCntnrList_t      tuiGraphicAppMain_t::g_unitDebugWin_3       ("Cntnr debug Window 3", &g_cntnrSetWindow_3);
                    dtyCntnrArraySet_t      tuiGraphicAppMain_t::g_cntnrSetWindow_3(g_setWindow_3);


    // *** end   section - WINDOW SET/LIST CONTAINERS DEFINITION
    // **************************************************
// -------------------------------------------------------
