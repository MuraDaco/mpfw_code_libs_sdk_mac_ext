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
 * tuiTextUsartX.cpp
 *
 *  Created on: Sep, 25th 2024
 *      Author: Marco Dau
 */
 

#include "tuiTextUsartX.h"


tuiTextUsartX_t*	tuiTextUsartX_t::g_po = nullptr;


tuiTextUsartX_t::tuiTextUsartX_t      (const char* p_strName, box_t  p_box, dtyStufX_t* p_pCntnr) :
     tuiBaseCntnrX_t         (p_strName, p_box, p_pCntnr)
{}

//tuiTextUsartX_t::tuiTextUsartX_t      (const char* p_strName, box_t* p_pBox, dtyStufX_t* p_pCntnr) :
//     tuiBaseCntnrX_t         (p_strName, p_pBox, p_pCntnr)
//{}


void tuiTextUsartX_t::init       (void* p_poFather) 	{
    tuiBase_t::init(p_poFather);
    initElementsList();

}


bool tuiTextUsartX_t::select         (void)    {
    return frameNname(tuiMode_t::select);
}

bool tuiTextUsartX_t::deSelect        (void)    {
    return frameNname(tuiMode_t::deselect);
}

bool tuiTextUsartX_t::selectByMouse     (void)    {

    g_pCntnr->selectElementsByMouse();
    deselectBackNeventOn(true, true);

    return true;
}

#define SIZE_OF_STATUS_STR  200

void tuiTextUsartX_t::getStrStatus               (char* p_str)    {
    snprintf(p_str, 30," NOTHING - %04x - %04x", g_y0Win, g_lvl1Y0a );
}

void tuiTextUsartX_t::display               (void)    {
    //frameNname();
    char l_str[SIZE_OF_STATUS_STR];
    getStrStatus(l_str);
    frameNameNstatus(l_str);
}

void tuiTextUsartX_t::display               (bool p_recursively)    {
    display();
    if(p_recursively) displayElements(p_recursively);
}

void tuiTextUsartX_t::setThis            (void)  {
    g_po = this;
}


void tuiTextUsartX_t::eventOn     (void)    {
    g_po = this;
    //tuiBaseAction_t::g_eventArray  = g_eventArray;
    //deselectBackNeventOn();
    frameNname(tuiMode_t::eventOn);
}

event_t* tuiTextUsartX_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

void tuiTextUsartX_t::vEventHndlKey_up	(void)  {
    selectPrev(g_po);
}

void tuiTextUsartX_t::vEventHndlKey_down	(void)  {
    selectNext(g_po);
}

void tuiTextUsartX_t::vEventHndlKey_left	(void)  {
    rollUp(g_po);
}

void tuiTextUsartX_t::vEventHndlKey_right	(void)  {
    rollDown(g_po);
}

void tuiTextUsartX_t::vEventHndlKey_enter	(void)  {
}

void tuiTextUsartX_t::vEventHndlKey_home	(void)  {
    if(g_po->g_poFather) g_po->g_poFather->deselectBackNeventOn(true, true);

}


event_t tuiTextUsartX_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};
