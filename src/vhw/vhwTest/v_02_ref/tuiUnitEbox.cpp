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
 * tuiUnitEbox.h
 *
 *  Created on: Nov, 8th 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitEbox.h"


tuiUnitEbox_t::tuiUnitEbox_t      (const char* p_strName  ,dtyBaseArray_t& p_rDtyStr   )   :
    tuiUnitAbstract_t       (p_strName)
    ,g_rDtyStr              {p_rDtyStr}
{}

// --------------------- Process section - START

bool tuiUnitEbox_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    g_rDtyStr.initDsplyBox(p_this->getDspAreaDimXw());

    return true;
}

bool tuiUnitEbox_t::initChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitEbox_t::loop   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitEbox_t::loopChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

void tuiUnitEbox_t::end       	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

void tuiUnitEbox_t::endChildren            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiUnitEbox_t::clear     	        (tuiGraphicAbstract_t* p_this)  {
    p_this->frameClear();
}

void tuiUnitEbox_t::display     	    (tuiGraphicAbstract_t* p_this)  {
    p_this->frameNnameTest(g_strName);

    uint8_t l_size = g_rDtyStr.sizeDsplyStrFromBeginGet();
    if(l_size)  {
        p_this->content(g_rDtyStr.pDsplyStrBeginGet(), l_size);
    }
}

void tuiUnitEbox_t::display     	    (tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}

void tuiUnitEbox_t::displayChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
}

void tuiUnitEbox_t::refreshChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}


// --------------------- Display section - END


// --------------------- State management section - START
#define CURSOR_HIDE false
#define CURSOR_SHOW true

bool tuiUnitEbox_t::select     	        (tuiGraphicAbstract_t* p_this)  {
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(CURSOR_HIDE,l_position);
    return p_this->frameNnameTest(tuiMode_t::select, g_strName);    
}

bool tuiUnitEbox_t::deSelect   	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(CURSOR_HIDE,l_position);
    return p_this->frameNnameTest(tuiMode_t::deselect, g_strName);
}

void tuiUnitEbox_t::eventOn    	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    p_this->frameNnameTest(tuiMode_t::eventOn, g_strName);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(CURSOR_SHOW,l_position);
}

bool tuiUnitEbox_t::selectByMouse          ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    p_this->deselectBackNeventOn();
    return true;
}

bool tuiUnitEbox_t::clickingChild          ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
    return false;
}


// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiUnitEbox_t::vEventHndlKey_down	(tuiGraphicAbstract_t* p_this)  {
    g_rDtyStr.positionEnd();
    display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiUnitEbox_t::vEventHndlKey_up	(tuiGraphicAbstract_t* p_this)  {
    g_rDtyStr.positionBegin();
    display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiUnitEbox_t::vEventHndlKey_left	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    if(g_rDtyStr.dsplyPositionDec())
        display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiUnitEbox_t::vEventHndlKey_right	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    if(g_rDtyStr.dsplyPositionInc())
        display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiUnitEbox_t::vEventHndlKey_enter	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
}

void tuiUnitEbox_t::vEventHndlKey_home	(tuiGraphicAbstract_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

void tuiUnitEbox_t::vEventHndlKey_del	(tuiGraphicAbstract_t* p_this)  {
    g_rDtyStr.del();

    uint8_t l_size  = g_rDtyStr.sizeDsplyStrFromPositionGet();
    uint8_t l_begin = g_rDtyStr.positionDsplyGet();
    if(l_size)
        p_this->content(g_rDtyStr.pDsplyStrPositionGet(), l_begin, l_size);
    else
        p_this->content(l_begin);

    p_this->positionCursor(true,l_begin);
}

void tuiUnitEbox_t::vEventHndlKey_backSpace	(tuiGraphicAbstract_t* p_this)  {
    if(g_rDtyStr.positionGet())     {
        if(g_rDtyStr.backSpace())
            display(p_this);

        uint8_t l_size  = g_rDtyStr.sizeDsplyStrFromPositionGet();
        uint8_t l_begin = g_rDtyStr.positionDsplyGet();
        if(l_size)
            p_this->content(g_rDtyStr.pDsplyStrPositionGet(), l_begin, l_size);
        else
            p_this->content(l_begin);

        p_this->positionCursor(true,l_begin);

    }
}

void tuiUnitEbox_t::vEventHndlKey_typeChar	(tuiGraphicAbstract_t* p_this)  {
    if(g_rDtyStr.ins(p_this->uiEventKeyCode()))
         display(p_this);

    uint8_t l_size  = g_rDtyStr.sizeDsplyStrFromPositionPrevGet();
    uint8_t l_begin = g_rDtyStr.positionDsplyGet();
    if(l_size)
        p_this->content(g_rDtyStr.pDsplyStrPositionPrevGet(), l_begin-1, l_size);
    else
        p_this->content(l_begin);

    p_this->positionCursor(true,l_begin);
}


// --------------------- Events handler section - START
