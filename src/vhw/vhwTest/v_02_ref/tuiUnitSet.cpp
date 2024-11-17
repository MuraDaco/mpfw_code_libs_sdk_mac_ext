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
 * tuiUnitSet.cpp
 *
 *  Created on: Nov, 8th 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitSet.h"


tuiUnitSet_t::tuiUnitSet_t      (const char* p_strName   ,tuiGraphicUnit_t* p_childrenSet     )   :
     tuiUnitListAbstract_t      (p_strName, p_childrenSet)
{}

// --------------------- Process section - START

bool tuiUnitSet_t::loop   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitSet_t::loopChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

void tuiUnitSet_t::end       	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

void tuiUnitSet_t::endChildren            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiUnitSet_t::clear     	        (tuiGraphicAbstract_t* p_this)  {
    p_this->frameClear();
}

// void tuiUnitSet_t::display     	    (tuiGraphicAbstract_t* p_this)  {
//     p_this->frameNnameTest(g_strName);
// }
// 
// void tuiUnitSet_t::display     	    (tuiGraphicAbstract_t* p_this, bool p_recursively)  {
//     display(p_this);
//     if(p_recursively) displayChildren(p_this, p_recursively);
// }



// --------------------- Display section - END


// --------------------- State management section - START

bool tuiUnitSet_t::select     	        (tuiGraphicAbstract_t* p_this)  {
    return p_this->frameNnameTest(tuiMode_t::select, g_strName);
}

bool tuiUnitSet_t::deSelect   	        (tuiGraphicAbstract_t* p_this)  {
    return p_this->frameNnameTest(tuiMode_t::deselect, g_strName);
}

void tuiUnitSet_t::eventOn    	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    p_this->frameNnameTest(tuiMode_t::eventOn, g_strName);
}



// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiUnitSet_t::vEventHndlKey_left	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitSet_t::vEventHndlKey_right	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitSet_t::vEventHndlKey_home	(tuiGraphicAbstract_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
