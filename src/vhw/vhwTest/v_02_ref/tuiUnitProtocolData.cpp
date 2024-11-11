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
 * tuiUnitProtocolData.cpp
 *
 *  Created on: Nov, 10th 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitProtocolData.h"


#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b

tuiUnitProtocolData_t::tuiUnitProtocolData_t (uint8_t* p_pBuf, uint32_t p_bufSize) :
    tuiUnitAbstract_t       (nullptr)    
    ,g_pBuf         {p_pBuf         }
    ,g_bufSize      {p_bufSize      }
{}


// --------------------- Process section - START

bool tuiUnitProtocolData_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitProtocolData_t::initChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitProtocolData_t::loop   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitProtocolData_t::loopChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

void tuiUnitProtocolData_t::end       	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

void tuiUnitProtocolData_t::endChildren            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiUnitProtocolData_t::clear     	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitProtocolData_t::display     	    (tuiGraphicAbstract_t* p_this)  {
    p_this->stringPrint(markerToColor(g_marker), g_select, reinterpret_cast<char*>(&g_pBuf[g_idData]), g_dataSize);    
}

void tuiUnitProtocolData_t::display     	    (tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}

void tuiUnitProtocolData_t::displayChildren     ([[maybe_unused]] tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
}

void tuiUnitProtocolData_t::refreshChildren     ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}


// --------------------- Display section - END


// --------------------- State management section - START

bool tuiUnitProtocolData_t::select     	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return false;
}

bool tuiUnitProtocolData_t::deSelect   	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return false;
}

void tuiUnitProtocolData_t::eventOn    	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

bool tuiUnitProtocolData_t::selectByMouse       ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return false;
}

bool tuiUnitProtocolData_t::clickingChild          ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
    return false;
}


void tuiUnitProtocolData_t::updParams      (uint32_t p_loopIdData, uint32_t p_loopDataSize, bool p_loopSelect, kMarker_t p_loopMarker)   {
    g_idData        = p_loopIdData;
    g_dataSize      = p_loopDataSize;

    g_select        = p_loopSelect;
    g_marker        = p_loopMarker;
}


void tuiUnitProtocolData_t::displayDebug            (tuiGraphicAbstract_t* p_this, uint32_t p_dbgParam1, uint32_t p_dbgParam2)      {
    p_this->debugPrint(p_dbgParam1, p_dbgParam2, reinterpret_cast<char*>(&g_pBuf[g_idData]));
}

uint8_t tuiUnitProtocolData_t::markerToColor        (kMarker_t p_marker)        {
    uint8_t l_result = 0;

    switch (p_marker)   {
        case kMarker_t::defaultX:
            l_result = NCURS_COLOR_YELLOW;
            break;
        case kMarker_t::deviceRx:
            l_result = NCURS_COLOR_MAGENTA;
            break;
        case kMarker_t::deviceTx:
            l_result = NCURS_COLOR_CYAN;
            break;
        default:
            l_result = NCURS_COLOR_WHITE;
            break;
    }

    return l_result;
}


