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
 * tuiUnitCntnrAbstract.cpp
 *
 *  Created on: Nov,  5th 2024
 *      Author: Marco Dau
 */
 

#include "tuiUnitCntnrAbstract.h"

#define RECURSIVELY         true
#define NOT_RECURSIVELY     false

tuiUnitCntnrAbstract_t::tuiUnitCntnrAbstract_t      (const char* p_strName, dtyBaseCntnrUnitX_t* p_pCntnr     )   :
    tuiUnitAbstract_t           (p_strName)
    ,g_pCntnr                   {p_pCntnr}
{}

bool tuiUnitCntnrAbstract_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
    return true;
}

bool tuiUnitCntnrAbstract_t::initChildren       (tuiGraphicUnit_t* p_this) 	{
    g_pCntnr->initDisplayBox(p_this);

    return true;
}

// --------------------- Container section - START

void tuiUnitCntnrAbstract_t::updCoordNboundsChilds      (void)  {
    g_pCntnr->updCoordNboundsChilds();
}

// --------------------- Container section - END

void tuiUnitCntnrAbstract_t::displayChildren     ([[maybe_unused]] tuiGraphicAbstract_t* p_this, bool p_recursively)    {
    g_pCntnr->displayChilds(p_recursively);
}

void tuiUnitCntnrAbstract_t::refreshChildren     ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {
    g_pCntnr->displayChilds(NOT_RECURSIVELY);
}


bool tuiUnitCntnrAbstract_t::selectByMouse     (tuiGraphicAbstract_t* p_this)    {

    if(!g_pCntnr->selectElementsByMouse()) {
        p_this->deselectBackNeventOn();
    }
    return true;
}

bool tuiUnitCntnrAbstract_t::clickingChild               ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {

    return g_pCntnr->selectElementsByMouse();
}

void tuiUnitCntnrAbstract_t::vEventHndlKey_up            ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {
    g_pCntnr->selectSubBoxUp();
    g_pCntnr->displayChilds(RECURSIVELY);
}

void tuiUnitCntnrAbstract_t::vEventHndlKey_down	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    g_pCntnr->selectSubBoxDown();
    g_pCntnr->displayChilds(RECURSIVELY);
}

void tuiUnitCntnrAbstract_t::vEventHndlKey_enter	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    tuiGraphicUnit_t* l_element = static_cast<tuiGraphicUnit_t*>(g_pCntnr->getSelect());
    if(l_element->isSelected())  {
       l_element->deselectBackNeventOn();
    }

}

void tuiUnitCntnrAbstract_t::vEventHndlMouse_rollUp      ([[maybe_unused]] tuiGraphicAbstract_t* p_this)    {
    g_pCntnr->displayBoxRollUp();
    g_pCntnr->displayChilds(RECURSIVELY);

}

void tuiUnitCntnrAbstract_t::vEventHndlMouse_rollDown	([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    g_pCntnr->displayBoxRollDown();
    g_pCntnr->displayChilds(RECURSIVELY);

}



