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
 * tuiGraphicUnit.cpp
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicUnit.h"

#include <stdio.h>

tuiGraphicUnit_t::tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit    )    :
     tuiDrvGraphic_t    (p_pUnit)
{}

tuiGraphicUnit_t::tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit    ,box_t p_box    )    :
     tuiDrvGraphic_t    (p_pUnit, p_box)
{}

tuiGraphicUnit_t::tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit                    ,margins_t p_margin )    :
     tuiDrvGraphic_t    (p_pUnit,        p_margin)
{}

tuiGraphicUnit_t::tuiGraphicUnit_t       (tuiUnitAbstract_t* p_pUnit    ,box_t p_box    ,margins_t p_margin )    :
     tuiDrvGraphic_t    (p_pUnit, p_box, p_margin)
{}

void tuiGraphicUnit_t::clear            (void)  {
    g_pUnit->clear(this);
}

void tuiGraphicUnit_t::display          (void)  {
    g_pUnit->display(this);
}

void tuiGraphicUnit_t::display          (bool p_recursively)  {
    g_pUnit->display(this, p_recursively);
}

// --------------------- Container section - START
void tuiGraphicUnit_t::updCoordNboundsChilds    (void)       {
    
    g_pUnit->updCoordNboundsChilds();
}
// --------------------- Container section - END


bool tuiGraphicUnit_t::select           (void)  {
    return g_pUnit->select(this);
}

bool tuiGraphicUnit_t::deSelect         (void)  {
    return g_pUnit->deSelect(this);
}

void tuiGraphicUnit_t::eventOn          (void)  {
    g_pUnit->eventOn(this);
}

bool tuiGraphicUnit_t::selectByMouse    (void)  {
    return g_pUnit->selectByMouse(this);
}

bool tuiGraphicUnit_t::selectTst        (void)  {
    return (g_status == tuiMode_t::select) || (g_status == tuiMode_t::eventOn);
}

void tuiGraphicUnit_t::dbgState_01          (void)  {
    char l_str[100];
    snprintf(l_str, sizeof(l_str),"sts %02d - stsX %02d - %s", g_debugStatus, g_debugStatusX, g_pUnit->getName());
    //mvwprintw   (stdscr, 2, 100, "*** deselect status debug: sts %02d - stsX %02d ***", g_debugStatus, g_debugStatusX);
    dbgPrint    (l_str);
}

void tuiGraphicUnit_t::dbgState_01          (bool p_test)  {
    char l_str[100];
    if(p_test)
        // mvwprintw   (stdscr, 2, 80, "*** deselect status debug: sts %02d - stsX %02d - parent match---", g_debugStatus, g_debugStatusX);
        snprintf(l_str, sizeof(l_str),"sts %02d - stsX %02d - %s -  true", g_debugStatus, g_debugStatusX, g_pUnit->getName());
    else
        // mvwprintw   (stdscr, 2, 80, "*** deselect status debug: sts %02d - stsX %02d - parent NO match", g_debugStatus, g_debugStatusX);
        snprintf(l_str, sizeof(l_str),"sts %02d - stsX %02d - %s - false", g_debugStatus, g_debugStatusX, g_pUnit->getName());

    dbgPrint    (l_str);
}

void tuiGraphicUnit_t::vEventHndlKey_down	        (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_down(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_up	            (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_up(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_left	        (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_left(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_right	        (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_right(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_enter	        (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_enter(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_home	        (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_home(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_del            (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_del(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_backSpace      (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_backSpace(p_this);
}

void tuiGraphicUnit_t::vEventHndlKey_typeChar       (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_typeChar(p_this);
}

tuiGraphicUnit_t::eventHandler_t tuiGraphicUnit_t::g_eventKeyArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
    ,vEventHndlKey_del
    ,vEventHndlKey_backSpace
    ,vEventHndlKey_typeChar
};


void tuiGraphicUnit_t::vEventHndlMouse_rollUp       (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlMouse_rollUp(p_this);
}

void tuiGraphicUnit_t::vEventHndlMouse_rollDown     (tuiGraphicAbstract_t* p_this)  {
    p_this->g_pUnit->vEventHndlMouse_rollDown(p_this);
}

tuiGraphicUnit_t::eventHandler_t tuiGraphicUnit_t::g_eventMouseArray[]  = {
     vEventHndlMouse_rollUp
    ,vEventHndlMouse_rollDown
};
