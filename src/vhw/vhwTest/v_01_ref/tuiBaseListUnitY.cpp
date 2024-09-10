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


tuiBaseListUnitY_t::tuiBaseListUnitY_t      (const char* p_strName, box_t p_box, tuiBaseListElem_t* p_elementList) :
     tuiBase_t              (p_strName, p_box)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
    ,g_pLastElement         {p_elementList}
    ,g_bElementList         {false}
    ,g_originWin            {0}
{}

tuiBaseListUnitY_t::tuiBaseListUnitY_t      (const char* p_strName, box_t* p_pBox, tuiBaseListElem_t* p_elementList) :
     tuiBase_t              (p_strName, p_pBox)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
    ,g_pLastElement         {p_elementList}
    ,g_bElementList         {false}
    ,g_originWin            {0}
{}

void tuiBaseListUnitY_t::init       (void* p_poFather) 	{
    tuiBase_t::init(p_poFather);
    initElementsList();
}

void tuiBaseListUnitY_t::initElementsList       (void) 	{
    if(!g_elementList)   return;
    // c) initialize all elements of the its own element list that is
    tuiBaseListElem_t* l_element = g_elementList;

    // c.1) run [init] function for each [child] element
    uint16_t l_id = 0;
    while(l_element->g_pUnit)    {
        l_element->g_id = l_id;
        //g_pLastElement = l_element;
        if(g_pNcursWin)   {
            l_element->g_pUnit->init(this);
            l_element->g_pUnit->updateRelativeY(l_id);
        }
        l_element++;
        l_id++;
    }

    g_elementNum = l_id;

    // c.2) determine the existence of an elements list
    if(l_element == g_elementList) {
        g_bElementList = false;
    } else {
        g_bElementList = true;
        // initialize last Element of the list
        // last element of the list is the element that has the [tuiBase] element pointer (g_pUnit) = nullptr
        g_pLastElement = l_element;
    }

}

//void tuiBaseListUnitY_t::selectByMouse     (void)    {
//
//    if(selectElements()) {
//        select();
//    } else {
//        deselectBackNselect();
//        eventOn();
//    }
//
//}

void tuiBaseListUnitY_t::selectByMouse         (void)    {
    if(selectElements()) {
        // a sub-element has been selected
        select();
    } else {
        // none sub-element has been selected
        deselectBackNselect();
        //g_po = this;
        //setThis();
        eventOn();
    }
    display();
    
}

bool tuiBaseListUnitY_t::selectElements     (void)    {
    bool l_result = false;

    tuiBaseListElem_t* l_element = g_elementList + g_originWin;
    uint16_t l_id = 0;
    while((l_element->g_pUnit) && (l_id < (g_h-2)))  {
        if(l_element->g_pUnit->bMouseClickInsideBounds()) {
            
            g_pCurrentElement = l_element;
            l_element->g_pUnit->selectByMouse();
            l_result = true;
            break;
        } else {
            l_element->g_pUnit->display();
        }
        l_element++;
        l_id++;
    }

    return l_result;
}

void tuiBaseListUnitY_t::prevElement     (tuiBaseListUnitY_t* p_po)    {
    if(p_po->g_bElementList) {
        if(p_po->g_elementList == p_po->g_pCurrentElement) {
            // the current element is already the first element, therefore ...
            // do nothing
        } else {
            // 
            p_po->g_pCurrentElement--;
            //if(static_cast<int16_t>(p_po->g_pCurrentElement->g_id) >= p_po->g_originWin)   {
            if(p_po->g_pCurrentElement->g_id >= p_po->g_originWin)   {
                // repaint is NOT necessary
                p_po->g_pCurrentElement->g_pUnit->deselectBackNselect(p_po);
            } else {
                // re-paint is necessary

                // update origin
                p_po->g_originWin--;
                // update relative coordinates
                p_po->g_pCurrentElement->g_pUnit->updateRelativeY(0);
                g_poSelected = p_po->g_pCurrentElement->g_pUnit;
                p_po->g_pCurrentElement->g_pUnit->select();

                tuiBaseListElem_t* l_element = p_po->g_pCurrentElement + 1;
                for(uint8_t l_id = 1; l_id < (p_po->g_h-2); l_id++) {
                    if(l_element->g_pUnit) {
                        l_element->g_pUnit->updateRelativeY(l_id);
                        l_element->g_pUnit->deSelect();
                    } else break;
                    l_element++;
                }
            }
            p_po->display();
        }
    }
}

void tuiBaseListUnitY_t::nextElement	(tuiBaseListUnitY_t* p_po)  {
    if(p_po->g_bElementList) {
        p_po->g_pCurrentElement++;
        if(p_po->g_pLastElement == p_po->g_pCurrentElement) {
            // the bottom of the list has been reached, therefore ...

            // go back with the (current element)
            // N.B.: the last element of the list is the element that has the [tuiBase] element pointer (g_pUnit) = nullptr
            p_po->g_pCurrentElement--;

            // do not other things
        } else {
            if(static_cast<int16_t>(p_po->g_pCurrentElement->g_id - (p_po->g_h - 2)) < p_po->g_originWin)   {
                // repaint is NOT necessary
                p_po->g_pCurrentElement->g_pUnit->deselectBackNselect(p_po);
            } else {
                // re-paint is necessary

                // update origin
                p_po->g_originWin++;
                // update relative coordinates
                p_po->g_pCurrentElement->g_pUnit->updateRelativeY(p_po->g_h-3);
                g_poSelected = p_po->g_pCurrentElement->g_pUnit;
                p_po->g_pCurrentElement->g_pUnit->select();

                tuiBaseListElem_t* l_element = p_po->g_pCurrentElement - 1;
                for(int8_t l_id = (p_po->g_h-4); l_id >= 0; l_id--) {
                    if(l_element->g_pUnit) {
                        l_element->g_pUnit->updateRelativeY(l_id);
                        l_element->g_pUnit->deSelect();
                    } else break;
                    l_element--;
                }
            }
            p_po->display();
        }
    }
}

void tuiBaseListUnitY_t::refreshElements     (void)    {
    tuiBaseListElem_t* l_element = g_elementList + g_originWin;

    // c.1) run [init] function for each [child] element
    while(l_element->g_pUnit)    {
        if(l_element->g_id < (g_originWin + g_h - 2))    {
            l_element->g_pUnit->display();
        } else break;
        l_element++;
    }

}

void tuiBaseListUnitY_t::displayElements     (bool p_recursively)    {
    tuiBaseListElem_t* l_element = g_elementList + g_originWin;

    // c.1) run [init] function for each [child] element
    while(l_element->g_pUnit)    {
        if(l_element->g_id < (g_originWin + g_h - 2))    {
            l_element->g_pUnit->display(p_recursively);
        } else break;
        l_element++;
    }
}


