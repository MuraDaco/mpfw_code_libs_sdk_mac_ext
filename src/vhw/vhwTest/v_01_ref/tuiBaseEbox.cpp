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
 * tuiBaseEbox.cpp
 *
 *  Created on: Sep, 2nd 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseEbox.h"


tuiBaseEbox_t*	tuiBaseEbox_t::g_po = nullptr;

tuiBaseEbox_t::tuiBaseEbox_t      (const char* p_strName    ,uint8_t p_height   ,dtyBaseArray_t* p_pDtyStr   )   :
     tuiBase_t          (p_strName, {p_height, 0, 0, 1})
    ,g_pDtyStr          {p_pDtyStr}
{}

tuiBaseEbox_t::tuiBaseEbox_t      (const char* p_strName    ,box_t p_box        ,dtyBaseArray_t* p_pDtyStr   )   :
     tuiBase_t          (p_strName, p_box)
    ,g_pDtyStr          {p_pDtyStr}
{
    g_pDtyStr->initDsplyBox(g_w-2);
}


void tuiBaseEbox_t::init       (void* p_poFather) 	{
    g_poFather      = static_cast<tuiBase_t*>(p_poFather);
    g_pNcursWin     = static_cast<tuiBase_t*>(p_poFather)->g_pNcursWin;
    g_x0Win         = static_cast<tuiBase_t*>(p_poFather)->g_x0Win  + g_x0r;
    g_y0Win         = static_cast<tuiBase_t*>(p_poFather)->g_y0Win  + g_y0r;
    g_x0a           = static_cast<tuiBase_t*>(p_poFather)->g_x0a    + g_x0r;
    g_y0a           = static_cast<tuiBase_t*>(p_poFather)->g_y0a    + g_y0r;
    if(!g_w) g_w    = static_cast<tuiBase_t*>(p_poFather)->g_w - 2;

    g_pDtyStr->initDsplyBox(g_w-2);
}

bool tuiBaseEbox_t::loop            (void)  {
    bool l_result = false;

    return l_result;
}


void tuiBaseEbox_t::select         (void)    {
    frameNname(tuiMode_t::select);
    //frameNameNcontent(tuiMode_t::select, g_pDtyStr->pDsplyStrBeginGet(), g_w-2);
    uint8_t l_position = g_pDtyStr->positionDsplyGet();
    positionCursor(false,l_position);
}

void tuiBaseEbox_t::selectByMouse       (void)    {
    deselectBackNselect(g_poFather);
    eventOn();
}

void tuiBaseEbox_t::display          (void)    {
    frameNname();
    uint8_t l_size = g_pDtyStr->sizeDsplyStrFromBeginGet();
    //uint8_t l_size = g_pDtyStr->sizeDsplyStrFromPositionGet();
    if(l_size)  {
        content(g_pDtyStr->pDsplyStrBeginGet(), l_size);
        //content(g_pDtyStr->pDsplyStrPositionGet(), l_size);
    }
}

void tuiBaseEbox_t::display         ([[maybe_unused]] bool p_recursively)  {
    display();
}  

void tuiBaseEbox_t::deSelect        (void)    {
    frameNname(tuiMode_t::deselect);
    //frameNameNcontent(tuiMode_t::deselect, g_pDtyStr->pDsplyStrBeginGet(), g_w-2);
    uint8_t l_position = g_pDtyStr->positionDsplyGet();
    positionCursor(false,l_position);
}

void tuiBaseEbox_t::setThis            (void)  {
    g_po = this;
}

void tuiBaseEbox_t::eventOn         (void)    {
    g_po = this;
    //tuiBaseAction_t::g_eventArray  = g_eventArray;
    tuiBaseAction_t::eventOn();

    frameNname(tuiMode_t::eventOn);
    // cursor management
    uint8_t l_position = g_pDtyStr->positionDsplyGet();
    positionCursor(true,l_position);

}

event_t* tuiBaseEbox_t::pEventArrayGet	(void)      {
    return g_eventArray;
}

uint8_t tuiBaseEbox_t::eventArraySizeGet   (void)   {
    return constEventArraySize;
}

void tuiBaseEbox_t::vEventHndlKey_down	(void)  {
    g_po->g_pDtyStr->positionEnd();
    g_po->display();
    // cursor management
    uint8_t l_position = g_po->g_pDtyStr->positionDsplyGet();
    g_po->positionCursor(true,l_position);
}

void tuiBaseEbox_t::vEventHndlKey_up	(void)  {
    g_po->g_pDtyStr->positionBegin();
    g_po->display();
    // cursor management
    uint8_t l_position = g_po->g_pDtyStr->positionDsplyGet();
    g_po->positionCursor(true,l_position);
}

void tuiBaseEbox_t::vEventHndlKey_left	(void)  {
    if(g_po->g_pDtyStr->dsplyPositionDec())
        g_po->display();
    // cursor management
    uint8_t l_position = g_po->g_pDtyStr->positionDsplyGet();
    g_po->positionCursor(true,l_position);
}

void tuiBaseEbox_t::vEventHndlKey_right	(void)  {
    if(g_po->g_pDtyStr->dsplyPositionInc())
        g_po->display();
    // cursor management
    uint8_t l_position = g_po->g_pDtyStr->positionDsplyGet();
    g_po->positionCursor(true,l_position);
}

void tuiBaseEbox_t::vEventHndlKey_enter	(void)  {
}

void tuiBaseEbox_t::vEventHndlKey_home	(void)  {
    g_po->deselectBackNselect();
    g_po->g_poFather->eventOn();

}

void tuiBaseEbox_t::vEventHndlKey_del	(void)  {
    g_po->g_pDtyStr->del();

    uint8_t l_size = g_po->g_pDtyStr->sizeDsplyStrFromPositionGet();
    uint8_t l_begin = g_po->g_pDtyStr->positionDsplyGet();
    if(l_size)
        g_po->content(g_po->g_pDtyStr->pDsplyStrPositionGet(), l_begin, l_size);
    else
        g_po->content(l_begin);

    g_po->positionCursor(true,l_begin);
}

void tuiBaseEbox_t::vEventHndlKey_backSpace	(void)  {
    if(g_po->g_pDtyStr->positionGet())     {
        if(g_po->g_pDtyStr->backSpace())
            g_po->display();

        uint8_t l_size = g_po->g_pDtyStr->sizeDsplyStrFromPositionGet();
        uint8_t l_begin = g_po->g_pDtyStr->positionDsplyGet();
        if(l_size)
            g_po->content(g_po->g_pDtyStr->pDsplyStrPositionGet(), l_begin, l_size);
        else
            g_po->content(l_begin);

        g_po->positionCursor(true,l_begin);

    }
}

void tuiBaseEbox_t::vEventHndlKey_typeChar	(void)  {
    if(g_po->g_pDtyStr->ins(g_po->uiEventKeyCode()))
         g_po->display();

    uint8_t l_size = g_po->g_pDtyStr->sizeDsplyStrFromPositionPrevGet();
    uint8_t l_begin = g_po->g_pDtyStr->positionDsplyGet();
    if(l_size)
        g_po->content(g_po->g_pDtyStr->pDsplyStrPositionPrevGet(), l_begin-1, l_size);
    else
        g_po->content(l_begin);

    g_po->positionCursor(true,l_begin);
}

uint8_t tuiBaseEbox_t::vEventHndlKeyArraySize	(void)  {
    return 0;
}

event_t tuiBaseEbox_t::g_eventArray[]  = {
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


