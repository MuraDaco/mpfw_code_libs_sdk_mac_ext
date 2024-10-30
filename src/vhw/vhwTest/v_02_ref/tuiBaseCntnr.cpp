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
 * tuiBaseCntnr.cpp
 *
 *  Created on: Aug, 12th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseCntnr.h"


tuiBaseCntnr_t::tuiBaseCntnr_t      (const char* p_strName, box_t p_box, dtyBaseCntnrUnit_t* p_pCntr) :
     tuiBase_t              (p_strName, p_box)
    ,g_pCntnr                {p_pCntr}
{}

void tuiBaseCntnr_t::initElementsList       (void) 	{
    // 1. init Box parameter & pointers
    g_pCntnr->initDisplayBox(g_h-2, g_w-2);
    g_pCntnr->resetDisplayBox();
    // 2. init selected
}

uint8_t tuiBaseCntnr_t::markerToColor     (dtyBaseCntnrUnit_t::kMarker_t p_marker)    {
    uint8_t l_result = 0;

    switch (p_marker)   {
        case dtyBaseCntnrUnit_t::kMarker_t::defaultX:
            l_result = NCURS_COLOR_YELLOW;
            break;
        case dtyBaseCntnrUnit_t::kMarker_t::deviceRx:
            l_result = NCURS_COLOR_MAGENTA;
            break;
        case dtyBaseCntnrUnit_t::kMarker_t::deviceTx:
            l_result = NCURS_COLOR_CYAN;
            break;
        default:
            l_result = NCURS_COLOR_WHITE;
            break;
    }

    return l_result;
}

void tuiBaseCntnr_t::displayElements     ([[maybe_unused]] bool p_recursively)    {
    // 1. resetting displayCurrent pointer
    g_pCntnr->resetDisplayBox();

    // 2. loop to display the clock data contents
    uint8_t l_row = 0;
    do {
        dtyBaseCntnrUnit_t::kMarker_t  l_rowMarker = g_pCntnr->getDisplayBlockDataRowMarker();
        char*               l_pRowStr   = reinterpret_cast<char*>(g_pCntnr->getDisplayBlockDataRow());
        uint8_t             l_rowLength = g_pCntnr->getDisplayBlockDataRowLength();
        bool                l_bRowBegin = g_pCntnr->bDisplayBlockDataRowBegin();

        rowPrint(l_row, l_bRowBegin, markerToColor(l_rowMarker), l_pRowStr, l_rowLength);
        l_row++;
    } while(g_pCntnr->setDisplayBoxNextRow());
}

bool tuiBaseCntnr_t::selectByMouse     (void)    {

    deselectBackNeventOn();
    return true;
}

bool tuiBaseCntnr_t::selectElements     (void)    {

    return true;
}

void tuiBaseCntnr_t::prevElement     (tuiBaseCntnr_t* p_po)    {
    p_po->g_pCntnr->getDisplayBoxMoveUp();
    p_po->displayElements(false);

}

void tuiBaseCntnr_t::nextElement	([[maybe_unused]] tuiBaseCntnr_t* p_po)  {
    p_po->g_pCntnr->getDisplayBoxMoveDown();
    p_po->displayElements(false);


}

void tuiBaseCntnr_t::refreshElements     (void)    {

}

