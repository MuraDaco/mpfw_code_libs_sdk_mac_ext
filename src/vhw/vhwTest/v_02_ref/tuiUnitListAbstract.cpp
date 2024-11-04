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
 * tuiUnitListAbstract.cpp
 *
 *  Created on: Oct, 27th 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitListAbstract.h"


tuiUnitListAbstract_t::tuiUnitListAbstract_t      (tuiGraphicUnit_t* p_childrenSet) :
     g_childrenSet              {p_childrenSet}
    ,g_pChildCurrent            {p_childrenSet}
    ,g_pChildLast               {p_childrenSet}
    ,g_bChildrenSetEmpty        {true}
{}

bool tuiUnitListAbstract_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitListAbstract_t::initChildren       (tuiGraphicUnit_t* p_this) 	{
    uint8_t dbgCnt = 0;
    // check children set existence
    if(!g_childrenSet)
        // children set does not exist, therefore ...
        // do nothing & exit
        return false; 

    // initialize all elements of the its own element list that is
    tuiGraphicUnit_t* l_child = g_childrenSet;

    // run [init] function for each [child]
    // the loop end condition is when you meet a child (the last child of the set) with a null tuiUnit obiect (g_pUnit == nullptr)
    while(!l_child->bNull())    {
        l_child->init(p_this);
        l_child++;
        dbgCnt++;
    }
    p_this->dbgSetChildrenNumber(dbgCnt);
    
    // check the status of children set (weather it is empty or not); default status is empty (g_bChildrenSetEmpty = false, see constructor)
    if(l_child != g_childrenSet) {
        // childen set is NOT empty
        g_bChildrenSetEmpty = false;
        // initialize last child of the set
        g_pChildLast = l_child;
    }

    return true;
}


void tuiUnitListAbstract_t::displayChildren     ([[maybe_unused]] tuiGraphicAbstract_t* p_this, bool p_recursively)    {
    if(g_bChildrenSetEmpty) return;

    tuiGraphicUnit_t* l_child = g_childrenSet;

    while(l_child->bNotNull())    {
        l_child->display(p_recursively);
        l_child++;
    }
}

void tuiUnitListAbstract_t::refreshChildren     ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {
    if(g_bChildrenSetEmpty) return;

    tuiGraphicUnit_t* l_child = g_childrenSet;

    while(l_child->bNotNull())    {
        l_child->refreshWin();
        l_child++;
    }
}


bool tuiUnitListAbstract_t::selectByMouse     (tuiGraphicAbstract_t* p_this)    {

    if(!clickingChild(p_this)) {
        p_this->deselectBackNeventOn();
    }
    return true;
}

bool tuiUnitListAbstract_t::clickingChild     ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {
    if(g_bChildrenSetEmpty) return false;

    bool l_result = false;

    tuiGraphicUnit_t* l_child = g_childrenSet;
    while(l_child->bNotNull())    {
        if(l_child->bMouseClickInsideBounds()) {
            g_pChildCurrent = l_child;
            l_result = l_child->selectByMouse();
            break;
        }
        l_child++;
    }

    return l_result;
}

void tuiUnitListAbstract_t::vEventHndlKey_up     ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {
    if(g_bChildrenSetEmpty) return;

    if(g_pChildCurrent) {
        if(g_childrenSet == g_pChildCurrent)
            g_pChildCurrent = g_pChildLast;
        g_pChildCurrent--;
    } else {
        g_pChildCurrent = g_childrenSet;
    }
    g_pChildCurrent->deselectBackNselect();

}

void tuiUnitListAbstract_t::vEventHndlKey_down	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    if(g_bChildrenSetEmpty) return;

    if(g_pChildCurrent) {
        g_pChildCurrent++;
        if(g_pChildLast == g_pChildCurrent)
            g_pChildCurrent = g_childrenSet;
    } else {
        g_pChildCurrent = g_childrenSet;
    }
    g_pChildCurrent->deselectBackNselect();

}

void tuiUnitListAbstract_t::vEventHndlKey_enter	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    if(g_bChildrenSetEmpty) return;

    if(g_pChildCurrent->selectTst()) {
        g_pChildCurrent->deselectBackNeventOn();
    }

}

//void tuiUnitListAbstract_t::updCoordNboundsChilds    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)       {
//    tuiGraphicAbstract_t* l_child = g_childrenSet;
//
//    while(l_child->g_pUnit)    {
//        l_child->updCoordNboundsForNewFather();
//        l_child++;
//    }
//}

