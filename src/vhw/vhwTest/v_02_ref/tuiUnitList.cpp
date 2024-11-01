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
 * tuiUnitList.h
 *
 *  Created on: Oct, 22nd 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitList.h"


tuiUnitList_t::tuiUnitList_t      (const char* p_strName   ,dtyUint8_t* p_pDtyStatus   )   :
     g_strName          {p_strName}
    ,g_pDtyStatus       {p_pDtyStatus}
{}


void tuiUnitList_t::clear     	    (tuiGraphicAbstract_t* p_this)  {
    p_this->frameClear();
}

void tuiUnitList_t::display     	    (tuiGraphicAbstract_t* p_this)  {
    p_this->nameNstatus(g_strName, *g_pDtyStatus->g_pValue);
}

void tuiUnitList_t::display     	    (tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}

bool tuiUnitList_t::select     	    (tuiGraphicAbstract_t* p_this)  {
    return p_this->nameNstatus(tuiMode_t::select, g_strName, *g_pDtyStatus->g_pValue);
}

bool tuiUnitList_t::deSelect   	    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return true;
}

void tuiUnitList_t::eventOn    	    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {

}

bool tuiUnitList_t::selectByMouse   ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return true;
}

void tuiUnitList_t::vEventHndlKey_down	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitList_t::vEventHndlKey_up	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitList_t::vEventHndlKey_left	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitList_t::vEventHndlKey_right	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitList_t::vEventHndlKey_enter	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    g_pDtyStatus->vInc();
}

void tuiUnitList_t::vEventHndlKey_home	(tuiGraphicAbstract_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}
