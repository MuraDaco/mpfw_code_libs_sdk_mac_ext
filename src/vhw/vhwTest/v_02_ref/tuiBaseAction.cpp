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
 * tuiBaseAction.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBaseAction.h"

event_t*            tuiBaseAction_t::g_eventArray = nullptr;
void_f_pVoid_t*     tuiBaseAction_t::g_eventMouseArray = nullptr;
tuiBaseAction_t*    tuiBaseAction_t::g_poSelected = nullptr;
tuiBaseAction_t*    tuiBaseAction_t::g_poEventOn  = nullptr;

uint8_t             tuiBaseAction_t::g_debugStatus = 0;
uint8_t             tuiBaseAction_t::g_debugStatusX = 0;


tuiBaseAction_t::tuiBaseAction_t    (void)  :
    g_poFather  {nullptr}
{}


bool tuiBaseAction_t::deselectBack(tuiBaseAction_t* p_poDeselectEnd, bool p_isSelecting) {
    bool l_result = true;
    if(this != p_poDeselectEnd) {
        deSelect();    
        if(g_poFather) {
            g_poFather->deselectBack(p_poDeselectEnd, p_isSelecting);
        } else {
            // the current function belong to rootWindow, therefore ...
            // no other deSelect functions have to be called
        }
        
    } else {
        // the elemet that is going to be selected is the element that the current function belong to, therefore ...
        // do nothing ...
        // 
        // p_poDeselectEnd = selecting element

    }
    return l_result;
}

void  tuiBaseAction_t::deselectBackNselect  (void) {
    if(g_poSelected)    {
        if(g_poSelected->deselectBack(this, true))  {
            g_poSelected = this;
            select();
        }
    } else {
        g_poSelected = this;
        select();
    }
}

void  tuiBaseAction_t::deselectBackNselect(tuiBaseAction_t* p_poFather) {
    if(g_poSelected)    {
        if(g_poSelected->deselectBack(p_poFather, false))   {
            g_poSelected = this;
            select();
        }
    } else {
        g_poSelected = this;
        select();
    }
}

void  tuiBaseAction_t::deselectBackNselect      ([[maybe_unused]] bool p_unused_1) {
    if(g_poSelected != this)    {
        tuiBaseAction_t* l_poCommonAncestor = searchCommonAncestor();
        if(g_poSelected->g_poFather == g_poFather)  {
            g_poSelected->deSelect();
        } else {
            // N.B.: the father of the current element is acquiring the event management or is already the event manager
            g_poSelected->deselectBack(searchCommonAncestor(), (g_poFather == l_poCommonAncestor), 0);
        }
        g_poSelected = this;
        selectBack();
        
    } else {
        // the current element is already selected, therefore ...
        // do nothing
    }
}


uint8_t tuiBaseAction_t::eventArraySizeGet     (void)    {
    return constEventArraySize;
}

tuiBaseAction_t* tuiBaseAction_t::searchCommonAncestor       (void)      {
    if(g_poFather)    {
        // the current element is not the root window
        // N.B.: root window cannot be deselected
        if(!selectTst())
            // the current element is not displayed as selected
            return g_poFather->searchCommonAncestor();
    }

    return this;
}

void tuiBaseAction_t::debugDeselectBack (tuiBaseAction_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON)   {
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


tuiBaseAction_t* tuiBaseAction_t::deselectBack (tuiBaseAction_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON, [[maybe_unused]] uint8_t p_unused)   {
    tuiBaseAction_t* l_result = nullptr;
    if(p_poCommonAncestor == this) {
        // the current element is the common ancestor, therefore ...
        //return l_result;

        // check its status
        if(p_commonAncestorIsNextEventON)  {
            if(g_poEventOn == this) {
                if(g_poSelected == this) {
                    // N.B.: this is the first deselectBack function call
                    // STATUS 1
                    g_debugStatusX = 1;
                    // ... -> [Cur, CA, eON next, eON, selected & start deselectBack procedure]
                    // do nothing
                } else {
                    // STATUS 2
                    g_debugStatusX = 2;
                    // ... -> [Cur, CA, eON next, eON] -> [selected & start deselectBack procedure]
                    // do nothing
                }
            } else {
                if(g_poSelected == this) {
                    // N.B.: this is the first deselectBack function call
                    // STATUS 3
                    g_debugStatusX = 3;
                    // ... -> [eON] -> [Cur, CA, eON next, selected & start deselectBack procedure]

                    // the father of the current element is the current event management
                    // therefore ...
                    if(g_poFather) g_poFather->select();
                } else {
                    // STATUS 4
                    g_debugStatusX = 4;
                    // ... -> [Cur, CA, eON next] -> ... -> [eON] -> [selected & start deselectBack procedure]
                    // or
                    // ... -> [eON] -> [selected & start deselectBack procedure] -> ... -> [Cur, CA, eON next] -> this case does not exist because
                    // ... -> [eON] -> [selected & start deselectBack procedure] -> ... -> [CA, eON next] is NOT POSSIBLE,
                    // infact
                    // ... -> [eON] -> [selected & start deselectBack procedure] -> ... -> [eON next] implies
                    // ... -> [eON] -> [selected & start deselectBack procedure, CA] -> ... -> [eON next]
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
                    // ... -> [Cur, CA, eON, & selected, start deselectBack procedure] -> ... -> [eON next]
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
                    if(g_poFather) g_poFather->select();
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
            // remark ->         // particular case where (p_poCommonAncestor == g_poFather)
            // remark ->         if(p_poCommonAncestor == g_poFather)    {
            // remark ->              // ... -> [CA, eON next] -> [Cur, eON, selected & start deselectBack procedure]
            // remark ->             select();
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     } else {
            // remark ->         // STATUS B.2
            // remark ->         // ... -> [CA, eON next] -> ... -> [Cur, eON] -> [selected & start deselectBack procedure]
            // remark ->         // particular case where (p_poCommonAncestor == g_poFather)
            // remark ->         if(p_poCommonAncestor == g_poFather)    {
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
            // remark ->         // particular case where (p_poCommonAncestor == g_poFather) -> got to STATUS 2
            // remark ->         if(p_poCommonAncestor == g_poFather)    {
            // remark ->             // ... -> [CA, eON next, eON] -> [Cur, selected & start deselectBack procedure]
            // remark ->             // do nothing
            // remark ->             // leave all unchanged
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     } else {
            // remark ->         // STATUS B.4
            // remark ->         // ... -> [CA, eON next] -> ... -> [Cur] -> ... -> [eON] -> [selected & start deselectBack procedure]
            // remark ->         // particular case where (p_poCommonAncestor == g_poFather)
            // remark ->         if(p_poCommonAncestor == g_poFather)    {
            // remark ->             // ... -> [CA, eON next] -> [Cur] -> ... -> [eON] -> [selected & start deselectBack procedure]
            // remark ->             // it is not necessary select the element
            // remark ->             // select();
            // remark ->             l_result = this;
            // remark ->         }
            // remark ->     }
            // remark -> }

            // particular case where (p_poCommonAncestor == g_poFather)
            if(p_poCommonAncestor == g_poFather)    {
                g_debugStatusX = 99;
                select();
                l_result = this;
                // and ... stop deselectBack
            } else {
                // element is a nephew of eventOn next element
                // and
                // common ancestor is eventOn next
                g_debugStatusX = 91;
                if(g_poFather) {
                    deSelect();
                    l_result = g_poFather->deselectBack(p_poCommonAncestor, p_commonAncestorIsNextEventON, 0);
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
            
            if(g_poFather) {
                g_debugStatusX = 11;
                deSelect();
                l_result = g_poFather->deselectBack(p_poCommonAncestor, p_commonAncestorIsNextEventON, 0);
            } else {
                g_debugStatusX = 19;
            }
        }
    }

    return l_result;
}


void tuiBaseAction_t::selectBack (void)     {
    if(this != g_poEventOn) {
        if(g_poFather) {
            // the current element is NOT the root window, therefore ...
            if(select()) g_poFather->selectBack();
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

bool tuiBaseAction_t::deselectBackNeventOn ([[maybe_unused]] bool p_unused)   {
    bool l_result = false;
    // check the current elmenet status
    if(this != g_poEventOn) {
        // the current element is different than eventON element, therefore ...

        tuiBaseAction_t* l_poCommonAncestor = searchCommonAncestor();
        tuiBaseAction_t* l_poSelected = g_poSelected->deselectBack(l_poCommonAncestor, (l_poCommonAncestor == this), 0);

        g_poSelected = l_poSelected ? l_poSelected : this;
        //if(l_poSelected)    {
        //    g_poSelected = l_poSelected;
        //} else {
        //    g_poSelected = this;
        //}
        g_poEventOn = this;
        eventOn();
        tuiBaseAction_t::g_eventArray  = pEventArrayGet();
        if(g_poFather) g_poFather->selectBack();
    } else {
        // the current element is already eventON, therefore ...
        // do nothing, but ...
        l_result = true;
    }
    return l_result;
}

void tuiBaseAction_t::deselectBackNeventOn      (void)    {
    g_poEventOn = this;
    tuiBaseAction_t::g_eventArray       = pEventArrayGet();
    tuiBaseAction_t::g_eventMouseArray  = pEventMouseArrayGet();
}


void tuiBaseAction_t::deselectBackNeventOn     ([[maybe_unused]] bool p_unused_1, [[maybe_unused]] bool p_unused_2)    {
    if(pEventArrayGet())    {
        // the current element has a plenty event array
        tuiBaseAction_t* l_poCommonAncestor = searchCommonAncestor();
        if(g_poSelected)    {
            g_poSelected->debugDeselectBack(l_poCommonAncestor, (l_poCommonAncestor == this));
            tuiBaseAction_t* l_poSelected = g_poSelected->deselectBack(l_poCommonAncestor, (l_poCommonAncestor == this), 0);
            g_poSelected = l_poSelected ? l_poSelected : this;
        }
        l_poCommonAncestor->debug_01();

        g_poEventOn = this;
        eventOn();
        tuiBaseAction_t::g_eventArray  = pEventArrayGet();
        tuiBaseAction_t::g_eventMouseArray  = pEventMouseArrayGet();
        if(g_poFather) g_poFather->selectBack();
    } else {
        // the current element has an empty event array as a tuiBaseButton component, therefore ...
        // call only its eventOn() function
        eventOn();
    }

}

