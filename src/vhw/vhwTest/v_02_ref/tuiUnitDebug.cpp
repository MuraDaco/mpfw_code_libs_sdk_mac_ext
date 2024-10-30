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
 * tuiUnitDebug.h
 *
 *  Created on: Oct, 25th 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitDebug.h"


tuiUnitDebug_t::tuiUnitDebug_t      (const char* p_strName   ,dtyUint8_t* p_pDtyStatus   )   :
     g_strName          {p_strName}
    ,g_pDtyStatus       {p_pDtyStatus}
{}

// --------------------- Process section - START

bool tuiUnitDebug_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitDebug_t::initChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitDebug_t::loop   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitDebug_t::loopChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

void tuiUnitDebug_t::end       	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

void tuiUnitDebug_t::endChildren            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiUnitDebug_t::clear     	        (tuiGraphicAbstract_t* p_this)  {
    p_this->frameClear();
}

void tuiUnitDebug_t::display     	    (tuiGraphicAbstract_t* p_this)  {
    //p_this->frameBox(g_strName);
    p_this->frameNnameTest(g_strName);
}

void tuiUnitDebug_t::display     	    (tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}

void tuiUnitDebug_t::displayChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
}

void tuiUnitDebug_t::refreshChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}


// --------------------- Display section - END


// --------------------- State management section - START

bool tuiUnitDebug_t::select     	        (tuiGraphicAbstract_t* p_this)  {
    return p_this->frameNnameTest(tuiMode_t::select, g_strName);
}

bool tuiUnitDebug_t::deSelect   	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return true;
}

void tuiUnitDebug_t::eventOn    	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    //p_this->frameBox(tuiMode_t::eventOn, g_strName);
    p_this->frameNnameTest(tuiMode_t::eventOn, g_strName);
}

bool tuiUnitDebug_t::selectByMouse          ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return true;
}

bool tuiUnitDebug_t::clickingChild          ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
    return false;
}

bool tuiUnitDebug_t::selectTst              ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
    return true;
}

bool tuiUnitDebug_t::eventOnTst             ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
    return true;
}


// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiUnitDebug_t::vEventHndlKey_down	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitDebug_t::vEventHndlKey_up	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitDebug_t::vEventHndlKey_left	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitDebug_t::vEventHndlKey_right	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitDebug_t::vEventHndlKey_enter	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitDebug_t::vEventHndlKey_home	(tuiGraphicAbstract_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
