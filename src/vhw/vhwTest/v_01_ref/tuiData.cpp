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
 * tuiData.cpp
 *
 *  Created on: Sep, 25th 2024
 *      Author: Marco Dau
 */
 

#include "tuiData.h"


#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b

#define G_PO_FATHER static_cast<tuiBase_t*>(g_poFather)


tuiData_t::tuiData_t (uint8_t* p_pBuf, uint32_t p_bufSize) :
     tuiBase_t()
    ,g_pBuf         {p_pBuf         }
    ,g_bufSize      {p_bufSize      }
{}



void tuiData_t::displayUpdate      (uint32_t p_loopIdData, uint32_t p_loopDataSize, int32_t p_y0r, uint32_t p_h, bool p_loopSelect, kMarker_t p_loopMarker)   {
    g_idData        = p_loopIdData;
    g_dataSize      = p_loopDataSize;

    g_select        = p_loopSelect;
    g_marker        = p_loopMarker;

    g_y0Win = (g_y0Win - g_y0r) + p_y0r;    // N.B.: g_y0Win - g_y0r = G_PO_FATHER->g_y0Win;
    g_y0a   = (g_y0a   - g_y0r) + p_y0r;    // N.B.: g_y0a   - g_y0r = G_PO_FATHER->g_y0a;
    g_y0r   = p_y0r;
    g_h     = p_h;

    g_lvl1Y0r   = p_y0r;
    g_lvl1Y0a   = G_PO_FATHER->getRefY0() + g_lvl1Y0r;
    g_boundUpper = MAX(G_PO_FATHER->g_boundUpper+1, g_lvl1Y0a);
    g_boundLower = MIN(G_PO_FATHER->g_boundLower-1, g_lvl1Y0a + g_h - 1);


    // - g_relBoundUpper = g_y0Win - g_boundUpper;
    //     - N.B.: according to the g_boundUpper definition it is such that
    //             0 <= g_relBoundUpper
    //     - furthermore the element is visible if 
    //                  g_relBoundUpper <= g_h-1
    // - g_relBoundUpper = g_y0Win - g_boundUpper;
    //     - N.B.: according to the g_boundUpper definition it is such that
    //                  g_relBoundLower <= g_h-1
    //     - furthermore the element is visible if 
    //             0 <= g_relBoundLower
    //g_relBoundUpper = g_y0Win - g_boundUpper;
    //g_relBoundLower = g_y0Win - g_boundLower;

}


void tuiData_t::display                (void)   {
    rowPrintX(markerToColor(g_marker), g_select, reinterpret_cast<char*>(&g_pBuf[g_idData]), g_dataSize);

//    if(g_boundUpper <= g_boundLower)  {
//        if(
//                //(               g_boundUpper <= static_cast<uint16_t>(g_lvl1Y0a + g_h - 1)  )
//                (              (g_boundUpper+1) <= (g_lvl1Y0a + g_h)  )
//            ||  (g_lvl1Y0a <=   g_boundLower                            )
//        )   {
//            // element is visible
//
//            rowPrintX(markerToColor(g_marker), g_select, reinterpret_cast<char*>(&g_pBuf[g_idData]), g_dataSize);
//            //statusPrintX();
//            //statusPrintX(reinterpret_cast<char*>(&g_pBuf[g_idData]), g_dataSize);
//        } else {
//            statusPrintX();
//        }
//    } else statusPrintX();

}

void tuiData_t::displayDebug       (uint32_t p_dbgParam1, uint32_t p_dbgParam2)       {
    debugPrintX(p_dbgParam1, p_dbgParam2, reinterpret_cast<char*>(&g_pBuf[g_idData]));
}

void tuiData_t::displayDebugTest       (void)       {
    debugPrintXTest();
}


void       tuiData_t::display              ([[maybe_unused]] bool p_recursively)    {
}

bool       tuiData_t::select               (void)                  {
    return true;
}

bool       tuiData_t::deSelect             (void)                  {
    return true;
}

bool       tuiData_t::selectByMouse        (void)                  {
    return true;
}

void       tuiData_t::setThis              (void)                  {

}

void       tuiData_t::eventOn              (void)                  {

}

event_t*   tuiData_t::pEventArrayGet	   (void)                  {
    return nullptr;
}

uint8_t    tuiData_t::eventArraySizeGet    (void)                  {
    return 0;
}

uint8_t tuiData_t::markerToColor     (kMarker_t p_marker)    {
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


