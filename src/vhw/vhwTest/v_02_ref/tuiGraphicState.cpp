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
 * tuiGraphicState.cpp
 *
 *  Created on: Oct, 21st 2024
 *      Author: Marco Dau
 */
 

#include "tuiGraphicState.h"


tuiGraphicState_t*    tuiGraphicState_t::g_poSelected = nullptr;
tuiGraphicState_t*    tuiGraphicState_t::g_poEventOn  = nullptr;

//event_t*            tuiGraphicState_t::g_eventKeyArray = nullptr;
//void_f_pVoid_t*     tuiGraphicState_t::g_eventMouseArray = nullptr;

uint8_t             tuiGraphicState_t::g_debugStatus = 0;
uint8_t             tuiGraphicState_t::g_debugStatusX = 0;

tuiGraphicState_t::tuiGraphicState_t       (void)   :
    g_eventStatus   {true}
{}

void tuiGraphicState_t::selectNeventOnInit          (void)  {
    g_poSelected    = this;
    g_poEventOn     = this;
}

tuiGraphicState_t* tuiGraphicState_t::searchCommonAncestor       (void)      {
    if(g_pParent)    {
        // the current element is not the root window
        if(!selectTst())
            // the current element is not displayed as selected
            return g_pParent->searchCommonAncestor();
    }

    return this;
}

void  tuiGraphicState_t::deselectBackNselect        (void) {
    if(g_poSelected != this)    {
        if(g_poSelected->g_pParent == g_pParent)  {
            // the selected element is a brother of the selecting element
            g_poSelected->deSelect();
            dbgState_01();
        } else {
            tuiGraphicState_t* l_poCommonAncestor = searchCommonAncestor();
            g_poSelected->debugDeselectBack(l_poCommonAncestor, (l_poCommonAncestor == this));
            g_poSelected->deselectBack(l_poCommonAncestor, (g_pParent == l_poCommonAncestor));
            dbgState_01((l_poCommonAncestor == this));
        }
        g_poSelected = this;
        selectBack();
        
    } else {
        // the current element is already selected, therefore ...
        // do nothing
    }
}

/*
    remark abbreviation description
    - Cur:          the executor of this function
    - CA:           Common Anchestor 
    - eON next:     the element that will be the new event manager
    - eON:          the current event manager
    - selected:     the element currently selected and that is going to be substituted by selecting and that has started the deselect-back procedure calling deselectBack() function (that is this function)
    - selecting:    the element that will be the next selected element and that has started the deselect-back-and-select procedure calling deselectBackNselect() function

    N.B.: root window cannot be deselected
*/
tuiGraphicState_t* tuiGraphicState_t::deselectBack (tuiGraphicState_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON)   {
    
    tuiGraphicState_t* l_result = nullptr;
    if(p_poCommonAncestor == this) {
        // the current element is the common ancestor, therefore ...


        // check its status
        if(p_commonAncestorIsNextEventON)  {
            if(g_poEventOn == this) {
                if(g_poSelected == this) {
                    // N.B.: this is the first deselectBack function call
                    // STATUS 1
                    g_debugStatusX = 1;
                    // ... -> [Cur, CA, eON next, eON, selected]
                    // do nothing
                } else {
                    // STATUS 2
                    g_debugStatusX = 2;
                    // ... -> [Cur, CA, eON next, eON] -> [selected]
                    // do nothing
                }
            } else {
                if(g_poSelected == this) {
                    // N.B.: this is the first deselectBack function call
                    // STATUS 3
                    g_debugStatusX = 3;
                    // ... -> [eON] -> [Cur, CA, eON next, selected]

                    // the father of the current element is the current event management
                    // therefore ...
                    if(g_pParent) g_pParent->select();
                } else {
                    // STATUS 4
                    g_debugStatusX = 4;
                    // ... -> [Cur, CA, eON next] -> ... -> [eON] -> [selected & start deselectBack procedure]
                    // or
                    // ... -> [eON] -> [selected] -> ... -> [Cur, CA, eON next] -> this case does not exist because
                    // ... -> [eON] -> [selected] -> ... -> [CA, eON next] is NOT POSSIBLE,
                    // infact
                    // ... -> [eON] -> [selected] -> ... -> [eON next] implies
                    // ... -> [eON] -> [selected, CA] -> ... -> [eON next]
                    // see STATUS 7 <==> (p_poCommonAncestor == this) && (!p_commonAncestorIsNextEventON) && (g_poEventOn != this) && (g_poSelected == this)
                    // do nothing
                }
            }
        } else {
            if(g_poEventOn == this) {
                if(g_poSelected == this) {
                    // N.B.: this is the first deselectBack function call

                    // STATUS 5
                    g_debugStatusX = 5;
                    // ... -> [Cur, CA, eON, & selected] -> ... -> [eON next]
                    // or with a different view
                    // ... -> [Cur, CA, eON, & selected, start deselectBack procedure]
                    //          \-> ... -> [eON next] or
                    //          \-> ... -> [selecting]

                    // the current element is
                    // 1) the common ancestor
                    // 2) the current event management
                    // 3) currently selected 
                    // therefore ...
                    select();
                    // and ... stop deselectBack
                } else {
                    // STATUS 6
                    g_debugStatusX = 6;
                    // ... -> [Cur, CA, eventOn] -> [selected & start deselectBack procedure]
                    //          \-> ... -> [eON next] or
                    //          \-> ... -> [selecting]

                    // the current element is
                    // 1) the common ancestor
                    // 2) the current event management
                    // 3) not selected so its child is (selected)
                    // 4) the selected element is on a different branch than the element that is acquiring the event management or is being selected, therefore ...

                    // pass from eventOn() to select()
                    select();
                    // and ... stop deselectBack
                }
            } else {
                if(g_poSelected == this) {
                    // N.B.: this is the first deselectBack function call

                    // STATUS 7
                    g_debugStatusX = 7;
                    // ... -> [eventOn] -> [Cur, CA, selected & start deselectBack procedure] -> ... -> [eON next]
                    // or with a different view
                    // ... -> [eventOn] -> [Cur, CA, selected & start deselectBack procedure]
                    //                       \-> ... -> [eON next] or
                    //                       \-> ... -> [selecting]
                    // 1) the selected element is on a different branch than the element that is acquiring the event management or is being selected, therefore ...

                    // the father of the current element is the current event management
                    // therefore ...
                    if(g_pParent) g_pParent->select();
                    // and ... stop deselectBack
                } else {
                    // STATUS 8
                    g_debugStatusX = 8;
                    // ... -> [CA, Cur] -> ... -> [eventOn] -> [selected & start deselectBack procedure]
                    //          \-> ... -> [eON next] or
                    //          \-> ... -> [selecting]
                    // 1) the eventOn element is on a different branch than the element that is acquiring the event management or is being selected, therefore ...

                    // do nothing
                    // and ... stop deselectBack
                }
            }
        }
    } else  {
        // the current element is NOT the common ancestor, therefore ...

        // check the element status
        if(p_commonAncestorIsNextEventON) {

            // check its status
            // go to STATUS 4
            // remark -> if(g_poEventOn == this) {
            // remark ->     if(g_poSelected == this) {
            // remark ->         // N.B.: this is the first deselectBack function call
            // remark ->         // STATUS B.1
            // remark ->         // ... -> [CA, eON next] -> ... -> [Cur, eON, selected & start deselectBack procedure]
            // remark ->         // particular case where (p_poCommonAncestor == g_pParent)
            // remark ->         if(p_poCommonAncestor == g_pParent)    {
            // remark ->              // ... -> [CA, eON next] -> [Cur, eON, selected & start deselectBack procedure]
            // remark ->             select();
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     } else {
            // remark ->         // STATUS B.2
            // remark ->         // ... -> [CA, eON next] -> ... -> [Cur, eON] -> [selected & start deselectBack procedure]
            // remark ->         // particular case where (p_poCommonAncestor == g_pParent)
            // remark ->         if(p_poCommonAncestor == g_pParent)    {
            // remark ->             // ... -> [CA, eON next] -> [Cur, eON] -> [selected & start deselectBack procedure]
            // remark ->             select();
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     }
            // remark -> } else {
            // remark ->     if(g_poSelected == this) {
            // remark ->         // N.B.: this is the first deselectBack function call
            // remark ->         // STATUS B.3 
            // remark ->         // ... -> [CA, eON next] -> ... -> [eON] -> [Cur, selected & start deselectBack procedure]
            // remark ->         // particular case where (p_poCommonAncestor == g_pParent) -> got to STATUS 2
            // remark ->         if(p_poCommonAncestor == g_pParent)    {
            // remark ->             // ... -> [CA, eON next, eON] -> [Cur, selected & start deselectBack procedure]
            // remark ->             // do nothing
            // remark ->             // leave all unchanged
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     } else {
            // remark ->         // STATUS B.4
            // remark ->         // ... -> [CA, eON next] -> ... -> [Cur] -> ... -> [eON] -> [selected & start deselectBack procedure]
            // remark ->         // particular case where (p_poCommonAncestor == g_pParent)
            // remark ->         if(p_poCommonAncestor == g_pParent)    {
            // remark ->             // ... -> [CA, eON next] -> [Cur] -> ... -> [eON] -> [selected & start deselectBack procedure]
            // remark ->             // it is not necessary select the element
            // remark ->             // select();
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     }
            // remark -> }

            // particular case where (p_poCommonAncestor == g_pParent)
            if(p_poCommonAncestor == g_pParent)    {
                g_debugStatusX = 99;
                select();
                l_result = this;
                // and ... stop deselectBack
            } else {
                // element is a nephew of eventOn next element
                // and
                // common anchestor is eventOn next
                g_debugStatusX = 91;
                if(g_pParent) {
                    deSelect();
                    l_result = g_pParent->deselectBack(p_poCommonAncestor, p_commonAncestorIsNextEventON);
                }
            }

        } else {
            // go to STATUS 8
            
            // remark -> if(g_poEventOn == this) {
            // remark ->     if(g_poSelected == this) {
            // remark ->         // N.B.: this is the first deselectBack function call
            // remark ->         // STATUS B.5
            // remark ->         // ... -> [CA] -> ... -> [Cur, eON, & selected, start deselectBack procedure]
            // remark ->         //          \-> ... -> [eON next] or
            // remark ->         //          \-> ... -> [selecting]
            // remark ->     } else {
            // remark ->         // STATUS B.6
            // remark ->         // ... -> [CA] -> ... -> [Cur, eventOn] -> [selected & start deselectBack procedure]
            // remark ->         //          \-> ... -> [eON next] or
            // remark ->         //          \-> ... -> [selecting]
            // remark ->     }
            // remark -> } else {
            // remark ->     if(g_poSelected == this) {
            // remark ->         // N.B.: this is the first deselectBack function call
            // remark ->         // STATUS B.7
            // remark ->         // ... -> [CA] -> ... -> [eventOn] -> [Cur, selected & start deselectBack procedure]
            // remark ->         //          \-> ... -> [eON next] or
            // remark ->         //          \-> ... -> [selecting]
            // remark ->     } else {
            // remark ->         // STATUS B.8
            // remark ->         // ... -> [CA] -> ... -> [Cur] -> ... -> [eventOn] -> [selected & start deselectBack procedure]
            // remark ->         //          \-> ... -> [eON next] or
            // remark ->         //          \-> ... -> [selecting]
            // remark ->     }
            // remark -> }
            
            if(g_pParent) {
                g_debugStatusX = 11;
                deSelect();
                l_result = g_pParent->deselectBack(p_poCommonAncestor, p_commonAncestorIsNextEventON);
            } else {
                g_debugStatusX = 19;
            }
        }
    }

    return l_result;
}

void tuiGraphicState_t::debugDeselectBack (tuiGraphicState_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON)   {
    // STATUS 1
    if(
            (p_poCommonAncestor == g_poSelected)    
        &&  (p_poCommonAncestor == g_poEventOn)
        &&  (p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 1;
    }

    // STATUS 2
    if(
            (p_poCommonAncestor != g_poSelected)
        &&  (p_poCommonAncestor == g_poEventOn)
        &&  (p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 2;
    }

    // STATUS 3
    if(
            (p_poCommonAncestor == g_poSelected)
        &&  (p_poCommonAncestor != g_poEventOn)
        &&  (p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 3;
    }

    // STATUS 4
    if(
            (p_poCommonAncestor != g_poSelected)
        &&  (p_poCommonAncestor != g_poEventOn)
        &&  (p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 4;
    }

    // STATUS 5
    if(
            (p_poCommonAncestor == g_poSelected)
        &&  (p_poCommonAncestor == g_poEventOn)
        &&  (!p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 5;
    }

    // STATUS 6
    if(
            (p_poCommonAncestor != g_poSelected)
        &&  (p_poCommonAncestor == g_poEventOn)
        &&  (!p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 6;
    }

    // STATUS 7
    if(
            (p_poCommonAncestor == g_poSelected)
        &&  (p_poCommonAncestor != g_poEventOn)
        &&  (!p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 7;
    }

    // STATUS 8
    if(
            (p_poCommonAncestor != g_poSelected)
        &&  (p_poCommonAncestor != g_poEventOn)
        &&  (!p_commonAncestorIsNextEventON)
    )   {
        g_debugStatus = 8;
    }

}


void tuiGraphicState_t::selectBack (void)     {
    if(this != g_poEventOn) {
        if(g_pParent) {
            // the current element is NOT the root window, therefore ...
            if(select()) g_pParent->selectBack();
            // N.B.: if the current element is already in select state then do nothing and stop the recusive procedure
        } else {
            // the current element is the root window, therefore ...
            // do not show select() mode
            // and stop to select back
        }
    } else {
        // the current element is in [eventOn] state, therefore ...
        // do not show select() mode
        // and stop to select back
    }
}


void tuiGraphicState_t::deselectBackNeventOn     (void)    {
    // check status of the current eventOn element to avoid unuseful operations
    if(this == g_poEventOn) 
        return; // the current eventOn element is equal to the next eventOn element, therefore ... do nothing!!! exit

    
    if(getEventStatus())    {
        // the current element has a plenty event array
        if(g_poSelected)    {
            tuiGraphicState_t* l_poCommonAncestor = searchCommonAncestor();
            g_poSelected->debugDeselectBack(l_poCommonAncestor, (l_poCommonAncestor == this));
            tuiGraphicState_t* l_poSelected = g_poSelected->deselectBack(l_poCommonAncestor, (l_poCommonAncestor == this));
            
            // (l_poSelected != nullptr) occurs 
            //      1) when a child gives back the event management to its parent and so goes back into select state
            //dbgState_01((this == g_poSelected->g_pParent));
            g_poSelected = l_poSelected ? l_poSelected : this;
            dbgState_01((this == g_poSelected));

            g_poEventOn = this;
            eventOn();

            // select all anchestor of the current element
            if(g_pParent) g_pParent->selectBack();
        }

    } else {
        // the current element has an empty event array as a tuiBaseButton component, therefore ...
        // call only its eventOn() function and do not change the current eventOn element
        eventOn();
   }

}


void tuiGraphicState_t::setParent       (tuiGraphicState_t* p_pParent) {
    g_pParent = p_pParent;
}

tuiGraphicState_t* tuiGraphicState_t::getParent       (void)   {
    return g_pParent;
}

void tuiGraphicState_t::parentDeselectBackNeventOn     	    (void)  {
    if(g_pParent)
        g_pParent->deselectBackNeventOn();
}

bool tuiGraphicState_t::getEventStatus                     (void)   {
    return g_eventStatus;
}

void tuiGraphicState_t::setEventStatus                     (bool p_eventStatus) {
    g_eventStatus = p_eventStatus;
}

