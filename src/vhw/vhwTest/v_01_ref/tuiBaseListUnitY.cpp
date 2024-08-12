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
 * tuiBaseListUnitY.cpp
 *
 *  Created on: Aug, 12th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseListUnitY.h"


tuiBaseListUnitY_t::tuiBaseListUnitY_t      (const char* p_strName, box_t p_box, element_t* p_elementList) :
     tuiBase_t              (p_strName, p_box)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
    ,g_pLastElement         {p_elementList}
    ,g_bElementList         {false}
{}

tuiBaseListUnitY_t::tuiBaseListUnitY_t      (const char* p_strName, box_t* p_pBox, element_t* p_elementList) :
     tuiBase_t              (p_strName, p_pBox)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
    ,g_pLastElement         {p_elementList}
    ,g_bElementList         {false}
{}

void tuiBaseListUnitY_t::initElementsList       (void) 	{
    if(!g_elementList)   return;
    // c) initialize all elements of the its own element list that is
    element_t* l_element = g_elementList;

    // c.1) run [init] function for each [child] element
    while(l_element->element)    {
        //g_pLastElement = l_element;
        if(this->g_pNcursWin) 
            l_element->element->init(this);
        l_element++;
    }

    // c.2) determine the existence of an elements list
    if(l_element == g_elementList) {
        g_bElementList = false;
    } else {
        g_bElementList = true;
        // initialize last Element of the list
        g_pLastElement = l_element;
    }

}

//void tuiBaseListUnitY_t::initElementsList       (point_t p_point0) 	{
//    if(!g_elementList)   return;
//    // c) initialize all elements of the its own element list that is
//    element_t* l_element = g_elementList;
//
//    // c.1) run [init] function for each [child] element
//    while(l_element->element)    {
//        //g_pLastElement = l_element;
//        l_element->element->init(this, p_point0);
//        l_element++;
//    }
//
//    // c.2) determine the existence of an elements list
//    if(l_element == g_elementList) {
//        g_bElementList = false;
//    } else {
//        g_bElementList = true;
//        // initialize last Element of the list
//        g_pLastElement = l_element;
//    }
//
//}

void tuiBaseListUnitY_t::selectByMouse     (void)    {

    if(selectElements()) {
        select();
    } else {
        deselectBackNselect();
        eventOn();
    }

}

bool tuiBaseListUnitY_t::selectElements     (void)    {
    bool l_result = false;

    element_t* l_element = g_elementList;
    while(l_element->element)    {
        if(l_element->element->bMouseClickInsideBounds()) {
            //if(g_pCurrentElement) g_pCurrentElement->element->deSelect();   // because of mouse event management
            g_pCurrentElement = l_element;
            l_element->element->selectByMouse();
            l_result = true;
            break;
        } else {
            l_element->element->display();
        }
        l_element++;
    }

    return l_result;
}

void tuiBaseListUnitY_t::prevElement     (tuiBaseListUnitY_t* p_po)    {
    if(p_po->g_bElementList) {
        if(p_po->g_pCurrentElement) {
            if(p_po->g_elementList == p_po->g_pCurrentElement)
                p_po->g_pCurrentElement = p_po->g_pLastElement;
            p_po->g_pCurrentElement--;
        } else {
            p_po->g_pCurrentElement = p_po->g_elementList;
        }
        p_po->g_pCurrentElement->element->deselectBackNselect(p_po);
    }
}

void tuiBaseListUnitY_t::nextElement	(tuiBaseListUnitY_t* p_po)  {
    if(p_po->g_bElementList) {
        if(p_po->g_pCurrentElement) {
            p_po->g_pCurrentElement++;
            if(p_po->g_pLastElement == p_po->g_pCurrentElement)
                p_po->g_pCurrentElement = p_po->g_elementList;
        } else {
            p_po->g_pCurrentElement = p_po->g_elementList;
        }
        p_po->g_pCurrentElement->element->deselectBackNselect(p_po);
    }
}

void tuiBaseListUnitY_t::refreshElements     (void)    {
    element_t* l_element = g_elementList;

    // c.1) run [init] function for each [child] element
    while(l_element->element)    {
        l_element->element->display();
        l_element++;
    }
}
