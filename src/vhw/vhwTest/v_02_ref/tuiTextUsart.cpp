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
 * tuiTextUsart.cpp
 *
 *  Created on: Aug, 26th 2024
 *      Author: Marco Dau
 */
 

#include "tuiTextUsart.h"


tuiTextUsart_t*	tuiTextUsart_t::g_po = nullptr;


tuiTextUsart_t::tuiTextUsart_t      (const char* p_strName, box_t  p_box, dtyStuf_t* p_pCntnr) :
     tuiBaseCntnr_t         (p_strName, p_box, p_pCntnr)
{}

//tuiTextUsart_t::tuiTextUsart_t      (const char* p_strName, box_t* p_pBox, dtyStuf_t* p_pCntnr) :
//     tuiBaseCntnr_t         (p_strName, p_pBox, p_pCntnr)
//{}


void tuiTextUsart_t::init       (void* p_poFather) 	{
    tuiBase_t::init(p_poFather);
    initElementsList();

}


bool tuiTextUsart_t::select         (void)    {
    return frameNname(tuiMode_t::select);
}

bool tuiTextUsart_t::deSelect        (void)    {
    return frameNname(tuiMode_t::deselect);
}

bool tuiTextUsart_t::selectByMouse         (void)    {
    deselectBackNeventOn(true, true);
    return true;
}

#define SIZE_OF_STATUS_STR  200

uint8_t tuiTextUsart_t::minOf               (uint8_t p_num1, uint8_t p_num2)    {
    return (p_num1 < p_num2) ? p_num1 : p_num2;
}

void tuiTextUsart_t::getStrStatus               (char* p_str)    {
    snprintf(p_str, minOf(SIZE_OF_STATUS_STR, g_w-5),"> %02x : %02x : %02x : %02x : %02x : %02x : %02x : %02x : %02x : %02x <", 
                g_pCntnr->g_pBuf[0], g_pCntnr->g_pBuf[1],
                g_pCntnr->g_pBuf[2], g_pCntnr->g_pBuf[3],
                g_pCntnr->g_pBuf[4], g_pCntnr->g_pBuf[5],
                g_pCntnr->g_pBuf[6], g_pCntnr->g_pBuf[7],
                g_pCntnr->g_pBuf[8], g_pCntnr->g_pBuf[9]
    );
}

void tuiTextUsart_t::getStrStatus                (uint8_t p_row, char* p_str)    {
    switch (p_row)  {
        case 1:
            snprintf(p_str, minOf(SIZE_OF_STATUS_STR, g_w-5),"> %02x : %02x : %06x : %06x : %06x <", 
                        g_pCntnr->g_displayBoxH,            g_pCntnr->g_displayBoxW,
                        g_pCntnr->g_idDisplayDataBegin,     g_pCntnr->g_idDisplayDataEnd,   g_pCntnr->g_idDisplayDataCurrent
            );
            break;
        case 2:
            snprintf(p_str, minOf(SIZE_OF_STATUS_STR, g_w-5),"> %02x : %06x : %06x : %06x <", 
                        g_pCntnr->g_debugDisplayRow,        
                        g_pCntnr->g_idDisplayHeaderBegin,     g_pCntnr->g_idDisplayHeaderEnd,   g_pCntnr->g_idDisplayHeaderCurrent
            );
            break;
        case 3:
            snprintf(p_str, minOf(SIZE_OF_STATUS_STR, g_w-5),"> %04x : %06x : %06x <",
                        g_pCntnr->g_debugBlockDataSize,
                        g_pCntnr->g_idWriteHeaderCurrent,        g_pCntnr->g_idWriteDataCurrent
            );
            break;
        default:
            break;
    }
}


void tuiTextUsart_t::display               (void)    {
    //frameNname();
    char l_str[SIZE_OF_STATUS_STR];
    getStrStatus(l_str);
    frameNameNstatus(l_str);
    //getStrStatus(1, l_str);
    //frameDebug(1, l_str);
    //getStrStatus(2, l_str);
    //frameDebug(2, l_str);
    //getStrStatus(3, l_str);
    //frameDebug(3, l_str);
}

void tuiTextUsart_t::display               (bool p_recursively)    {
    display();
    if(p_recursively) displayElements(p_recursively);
}

void tuiTextUsart_t::setThis            (void)  {
    g_po = this;
}


void tuiTextUsart_t::eventOn     (void)    {
    g_po = this;
    //tuiBaseAction_t::g_eventArray  = g_eventArray;
    //deselectBackNeventOn();
    frameNname(tuiMode_t::eventOn);
}

event_t* tuiTextUsart_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

void tuiTextUsart_t::vEventHndlKey_up	(void)  {
    prevElement(g_po);
}

void tuiTextUsart_t::vEventHndlKey_down	(void)  {
    nextElement(g_po);
}

void tuiTextUsart_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiTextUsart_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiTextUsart_t::vEventHndlKey_enter	(void)  {
//    if(g_po->g_pCurrentElement->element->isSelected())  {
//        g_po->frameNname(tuiMode_t::select);
//        g_po->g_pCurrentElement->element->eventOn();
//    }
}

void tuiTextUsart_t::vEventHndlKey_home	(void)  {
    if(g_po->g_poFather) g_po->g_poFather->deselectBackNeventOn(true, true);

}


event_t tuiTextUsart_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};
