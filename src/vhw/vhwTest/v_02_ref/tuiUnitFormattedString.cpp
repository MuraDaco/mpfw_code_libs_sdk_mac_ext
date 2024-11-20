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
 * tuiUnitFormattedString.h
 *
 *  Created on: Nov, 15th 2024 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiUnitFormattedString.h"

#include <stdio.h>

tuiUnitFormattedString_t::tuiUnitFormattedString_t      (const char* p_strName   ,dtyString_t* p_pString   )   :
    tuiUnitAbstract_t       (p_strName)
    ,g_pString              {p_pString}
{}

// --------------------- Process section - START

bool tuiUnitFormattedString_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    uint16_t l_h;
    l_h =   g_pString->getLength() / p_this->getDimW();
    l_h += (g_pString->getLength() % p_this->getDimW()) ? 1 : 0;
    p_this->setDimH(l_h);
    p_this->updBoundY();

    p_this->setEventStatus(false);
    return true;
}

bool tuiUnitFormattedString_t::initChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitFormattedString_t::loop   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitFormattedString_t::loopChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

void tuiUnitFormattedString_t::end       	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

void tuiUnitFormattedString_t::endChildren            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiUnitFormattedString_t::clear     	        (tuiGraphicAbstract_t* p_this)  {
    p_this->frameClear();
}

void tuiUnitFormattedString_t::display     	    (tuiGraphicAbstract_t* p_this)  {
    // char l_str[100];
    // uint16_t l_h;
    // l_h =   g_pString->getLength() / p_this->getDimW();
    // l_h += (g_pString->getLength() % p_this->getDimW()) ? 1 : 0;
    // snprintf(l_str, sizeof(l_str),"** p1: %02d - p2 %02d - p3 %02d **", g_pString->getLength() / p_this->getDimW(), (g_pString->getLength() % p_this->getDimW()) ? 1 : 0, l_h);
    // p_this->dbgPrint(80,3,l_str);
    p_this->stringPrint2(0, false, g_pString->getString(), g_pString->getLength());

}

void tuiUnitFormattedString_t::display     	    (tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}

void tuiUnitFormattedString_t::displayChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
}

void tuiUnitFormattedString_t::refreshChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}


// --------------------- Display section - END


// --------------------- State management section - START

bool tuiUnitFormattedString_t::select     	        (tuiGraphicAbstract_t* p_this)  {
    return p_this->stringPrint2(tuiMode_t::select, 0, true, g_pString->getString(), g_pString->getLength());
}

bool tuiUnitFormattedString_t::deSelect   	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    return p_this->stringPrint2(tuiMode_t::deselect, 0, false, g_pString->getString(), g_pString->getLength());
}

void tuiUnitFormattedString_t::eventOn    	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    // p_this->stringPrint(tuiMode_t::eventOn, 0, true, g_pString->getString(), g_pString->getLength());
}

bool tuiUnitFormattedString_t::selectByMouse        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
        p_this->deselectBackNselect();
        p_this->parentDeselectBackNeventOn();
    return true;
}

bool tuiUnitFormattedString_t::clickingChild        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
    return false;
}


// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiUnitFormattedString_t::vEventHndlKey_down	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitFormattedString_t::vEventHndlKey_up	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitFormattedString_t::vEventHndlKey_left	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitFormattedString_t::vEventHndlKey_right	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitFormattedString_t::vEventHndlKey_enter	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitFormattedString_t::vEventHndlKey_home	(tuiGraphicAbstract_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
