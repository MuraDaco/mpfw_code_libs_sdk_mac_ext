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
 * tuiWin.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 

#include "tuiWin.h"

#define TUI_KEY_TAB             0x0009
#define TUI_KEY_SHIFT_TAB       0x0161
#define TUI_KEY_RETURN          0x000A
#define TUI_KEY_ESC             0x001b

#define NCURS_MOUSE_TRACKING_ENABLE     // printf("\033[?1003h");            // Makes the terminal report mouse movement events           
#define NCURS_MOUSE_TRACKING_DISABLE    // printf("\033[?1003l");            // Disable mouse movement events, as l = low

#define NCURS_COLOR_PAIR_WINDOW_SELECT              COLOR_PAIR  (1)
#define NCURS_COLOR_PAIR_INIT_WINDOW_SELECT         init_pair   (1, COLOR_YELLOW,  COLOR_BLUE)

#define NCURS_COLOR_PAIR_WINDOW_DESELECT            COLOR_PAIR  (2)
#define NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT       init_pair   (2, COLOR_RED,     COLOR_BLACK)


//#define NCURS_COLOR_PAIR_INIT(name)    NCURS_COLOR_PAIR_##name
//#define NCURS_COLOR_PAIR_SET(WINDOW_SELECT)

tuiWin_t*	tuiWin_t::g_po = nullptr;

// tuiWin_t::tuiWin_t      (void)    :
//     tuiBaseUnit_t(g_zoneList)
// {}
// 
tuiWin_t::tuiWin_t      (box_t* p_box)    :
    tuiBaseUnit_t           (p_box, g_zoneList)
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, element_t* p_elementList)    :
     tuiBaseUnit_t          (p_box, g_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, zone_t* p_zoneList)    :
    tuiBaseUnit_t           (p_box, p_zoneList)
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseUnit_t          (p_box, p_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {nullptr}
{}

tuiWin_t::tuiWin_t      (const char* p_strName, box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseUnit_t          (p_box, p_zoneList)
    ,g_strName              {p_strName}
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {nullptr}
{}


void tuiWin_t::init       (void* p_poFather) 	{
    // 1. set pointer to my own [father]
    //      - it will be usefull for move between tui elements
    g_poFather = static_cast<tuiWin_t*>(p_poFather);

    // 2. initialize the active [event array]
    if(!p_poFather) {
        // the current instance is the main window, therefore ...
        // 1. set the event array and the g_po variable with its own pointer
        eventOn();
    }

    // 4. instantiate a new window
    //      - only if the current window has a [father]
    //      - otherwise the current windows is the [main] and it is associated to [ncurses stdscr]
    if(p_poFather)
    {   // the current instance is NOT the main window, therefore ...

        // crete new ncurses window
        g_ncursWin = newwin(g_pBox->height, g_pBox->width, g_pBox->yStart, g_pBox->xStart);
    }
    else
    {   // the current instance is the main window, therefore ...
        // 1. initialize the g_poSelected (the pointer of the instance that is currently selected)
        g_poSelected = this;
        // 2. set the pointer of ncurses window to main window [stdsrc]
        g_ncursWin = stdscr;
        // 3. complete ncurses initialization
        raw();                              /* Line buffering disabled        */
        nodelay(g_ncursWin, true);
        keypad(g_ncursWin, TRUE);           /* We get F1, F2 etc..            */
        noecho();                           /* Don't echo() while we do getch */
        mousemask(  ALL_MOUSE_EVENTS |      \
                    REPORT_MOUSE_POSITION,  \
                    NULL);
        // 3.1. enable the continuously monitoring of mouse movement
        NCURS_MOUSE_TRACKING_ENABLE


    }

    setNcursWindow(g_ncursWin);

    start_color();    // BECAREFUL!! - this instruction must be execute before init_pair function              /* Start color                  */

    // a) init color windows management
    if(p_poFather)  NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT;
    else            NCURS_COLOR_PAIR_INIT_WINDOW_SELECT;

    if(p_poFather)  wattron(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_DESELECT);
    else            wattron(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_SELECT);

    // b) enable color windows management
    mvwprintw(g_ncursWin, 2, 2, "window name: %s", g_strName);
    box(g_ncursWin, 0, 0);                  // BECAREFUL !! - if (g_ncursWin==stdscr) this instructions clear all sub-windows and you have to repaint the box and refresh subwindow
    if(p_poFather)  wattroff(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_DESELECT);
    else            wattroff(g_ncursWin, NCURS_COLOR_PAIR_WINDOW_SELECT);
    wrefresh(g_ncursWin);

    // c) initialize all elements of the its own element list that is
    element_t* l_element = g_elementList;

    // c.1) run [init] function for each [child] element
    while(l_element->element)    {
        //g_pLastElement = l_element;
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

bool tuiWin_t::loop            (void)  {
    bool l_result = true;
    tuiEventCode_t l_eventCode = tuiEventCode_t::noEvent;

    if(!g_poFather) {
       
        int l_ncursEventCode = wgetch(g_ncursWin);
        if(ERR != l_ncursEventCode)   {
            if(('x' == l_ncursEventCode) || ('q' == l_ncursEventCode) ){
                l_result = false;
                NCURS_MOUSE_TRACKING_DISABLE
                mvwprintw(g_ncursWin, 3, 5, "Exiting ... ");
            } else {
                switch(l_ncursEventCode)    {
                    case KEY_MOUSE:
                        mvwprintw(g_ncursWin, 2, 50, "MOUSE_EVENT");
                        l_eventCode = tuiEventCode_t::mouse;
                        break;
                    case KEY_DOWN:
                    case TUI_KEY_TAB:
                        mvwprintw(g_ncursWin, 2, 50, "KEY_DOWN");
                        l_eventCode = tuiEventCode_t::keyDown;
                        break;
                    case KEY_UP:
                    case TUI_KEY_SHIFT_TAB:
                        mvwprintw(g_ncursWin, 2, 50, "KEY_UP");
                        l_eventCode = tuiEventCode_t::keyUp;
                        break;
                    case KEY_LEFT:
                        mvwprintw(g_ncursWin, 2, 50, "KEY_LEFT");
                        l_eventCode = tuiEventCode_t::keyLeft;
                        break;
                    case KEY_RIGHT:
                        mvwprintw(g_ncursWin, 2, 50, "KEY_RIGHT");
                        l_eventCode = tuiEventCode_t::keyRight;
                        break;
                    case KEY_ENTER:
                    case TUI_KEY_RETURN:
                        mvwprintw(g_ncursWin, 2, 50, "KEY_ENTER");
                        l_eventCode = tuiEventCode_t::keyEnter;
                        break;
                    case KEY_HOME:
                    case TUI_KEY_ESC:
                        mvwprintw(g_ncursWin, 2, 50, "KEY_HOME");
                        l_eventCode = tuiEventCode_t::keyHome;
                        break;
                    default:
                        mvwprintw(g_ncursWin, 2, 50, "UNKNOWN_EVENT - keyCode: %04x", l_ncursEventCode);
                        break;
                }
            }
        }
    }

    //if(tuiEventCode_t::noEvent != l_eventCode) tuiBaseUnit_t::g_eventArray[static_cast<uint8_t>(l_eventCode)]();
    if(tuiEventCode_t::mouse == l_eventCode) {
        eventHndlMouse();
    } else {
        if(tuiEventCode_t::noEvent != l_eventCode) tuiBaseUnit_t::g_eventArray[tuiEventCodeNum(l_eventCode)]();
    }

    return l_result;
}

// it can be run only by [main_window] therefore ...
// its elements are all & only windows
void tuiWin_t::eventHndlMouse	(void)  {
    MEVENT l_mouseEvent;
    int l_mouseEventStatus = getmouse(&l_mouseEvent);

    if(l_mouseEventStatus == OK)  
    { /* When the user clicks left mouse button */

        if( (l_mouseEvent.bstate & BUTTON1_PRESSED)  ||
            (l_mouseEvent.bstate & BUTTON1_CLICKED)     )
        {
            element_t* l_element = g_elementList;
            element_t* l_elementSelected = nullptr;
            while(l_element->element)    {
                if(l_element->element->bMouseClickInsideBounds({static_cast<uint8_t>(l_mouseEvent.x), static_cast<uint8_t>(l_mouseEvent.y)})) {

                    if(l_elementSelected) {
                        if(bTstSelCnts(static_cast<tuiWin_t*>(l_elementSelected->element)->g_selCnt, static_cast<tuiWin_t*>(l_element->element)->g_selCnt)) {
                            l_elementSelected = l_element;
                        }
                    } else {
                        l_elementSelected = l_element;
                    }
                }
                l_element++;
            }
            if(l_elementSelected) {
                tuiWin_t* l_winSelected = static_cast<tuiWin_t*> (l_elementSelected->element);
                setMouseXY({static_cast<uint8_t>(l_mouseEvent.x - l_winSelected->g_pBox->xStart), static_cast<uint8_t>(l_mouseEvent.y - l_winSelected->g_pBox->yStart)});
                static_cast<tuiWin_t*>(l_elementSelected->element)->selectByMouse();
                static_cast<tuiWin_t*>(l_elementSelected->element)->eventOn();
            } else {
                //deSelectSelected         (this);
                g_poSelected = this;
                eventOn();
                setNcursWindow(g_ncursWin);
                wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
                // refresh current window and ...
                //mvwprintw(g_ncursWin, 0, 0, " 1st row - window name: %s ", g_strName);
                mvwprintw(g_ncursWin, 1, 1, " 2nd row - window name: %s ", g_strName);
                mvwprintw(g_ncursWin, 2, 1, " 3rd row - window name: %s ", g_strName);

                box(g_ncursWin, 0, 0);
                wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
                wrefresh(g_ncursWin);

                // c) initialize all elements of the its own element list that is
                element_t* l_element = g_elementList;

                // c.1) run [init] function for each [child] element
                while(l_element->element)    {
                    wattron     (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
                    box         (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin, 0, 0);
                    wattroff    (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
                    wrefresh    (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin);
                    l_element++;
                }

                //mvwchgat(g_ncursWin, 2, 0, 3, A_NORMAL, 2, NULL);
                wrefresh(g_ncursWin);

            }
            g_pCurrentElement = l_elementSelected;
        }
    }

}


//void EventOn    (uiBase* p_pFather) override;

void tuiWin_t::display     (void)    {
}

void tuiWin_t::selectByMouse     (void)    {
    //start_color();                  /* Start color                  */
    if(g_poSelected) g_poSelected->deSelect();
    g_poSelected = this;
//    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
//    // refresh current window and ...
//    //mvwprintw(g_ncursWin, 0, 0, " 1st row - window name: %s ", g_strName);
//    mvwprintw(g_ncursWin, 1, 1, " 2nd row - window name: %s ", g_strName);
//    mvwprintw(g_ncursWin, 2, 1, " 3rd row - window name: %s ", g_strName);
//
//    box(g_ncursWin, 0, 0);
//    wrefresh(g_ncursWin);
//    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    setNcursWindow(g_ncursWin);

    element_t* l_element = g_elementList;
    while(l_element->element)    {
        if(l_element->element->bMouseClickInsideBounds()) {
            if(g_pCurrentElement) g_pCurrentElement->element->deSelect();   // because of mouse event management
            g_pCurrentElement = l_element;
            l_element->element->selectByMouse();
        } else {
            l_element->element->display();
        }
        l_element++;
    }

    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    // refresh current window and ...
    //mvwprintw(g_ncursWin, 0, 0, " 1st row - window name: %s ", g_strName);
    mvwprintw(g_ncursWin, 1, 1, " 2nd row - window name: %s ", g_strName);
    mvwprintw(g_ncursWin, 2, 1, " 3rd row - window name: %s ", g_strName);

    box(g_ncursWin, 0, 0);
    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    wrefresh(g_ncursWin);


}

void tuiWin_t::selectByKey     (void)    {
    //start_color();                  /* Start color                  */
    if(g_poSelected) g_poSelected->deSelect();
    g_poSelected = this;
//    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
//    // refresh current window and ...
//    //mvwprintw(g_ncursWin, 0, 0, " 1st row - window name: %s ", g_strName);
//    mvwprintw(g_ncursWin, 1, 1, " 2nd row - window name: %s ", g_strName);
//    mvwprintw(g_ncursWin, 2, 1, " 3rd row - window name: %s ", g_strName);
//
//    box(g_ncursWin, 0, 0);
//    wrefresh(g_ncursWin);
//    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    setNcursWindow(g_ncursWin);

//    element_t* l_element = g_elementList;
//    while(l_element->element)    {
//        if(l_element->element->bMouseClickInsideBounds()) {
//            if(g_pCurrentElement) g_pCurrentElement->element->deSelect();   // because of mouse event management
//            g_pCurrentElement = l_element;
//            l_element->element->select();
//        } else {
//            l_element->element->display();
//        }
//        l_element++;
//    }

    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    // refresh current window and ...
    //mvwprintw(g_ncursWin, 0, 0, " 1st row - window name: %s ", g_strName);
    mvwprintw(g_ncursWin, 1, 1, " 2nd row - window name: %s ", g_strName);
    mvwprintw(g_ncursWin, 2, 1, " 3rd row - window name: %s ", g_strName);

    box(g_ncursWin, 0, 0);
    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    wrefresh(g_ncursWin);


}

void tuiWin_t::deSelect     (void)    {
    //start_color();                  /* Start color                  */

    // refresh current window and ...
    //wclear(g_ncursWin);

    //deSelectSelected         (this);
    wattron(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    box(g_ncursWin, 0, 0);
    wattroff(g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    wrefresh(g_ncursWin);


    // ... its elements
    if(!g_poFather) {
                element_t* l_element = g_elementList;

                // c.1) run [init] function for each [child] element
                while(l_element->element)    {
                    wattron     (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
                    box         (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin, 0, 0);
                    wattroff    (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
                    wrefresh    (static_cast<tuiWin_t*>(l_element->element)->g_ncursWin);
                    l_element++;
                }

                //mvwchgat(g_ncursWin, 2, 0, 3, A_NORMAL, 2, NULL);
                wrefresh(g_ncursWin);

    }

}

void tuiWin_t::eventOn     (void)    {
    g_po = this;
    tuiBaseUnit_t::g_eventArray  = g_eventArray;
}

void tuiWin_t::zone_hndl_1  (void)  {

}

void tuiWin_t::zone_hndl_2  (void)  {

}

tuiBaseUnit_t::zone_t tuiWin_t::g_zoneList[] = {
     {{1, 2, 3, 4}, zone_hndl_1}
    ,{{1, 2, 3, 4}, zone_hndl_2}
    ,{{1, 4, 3, 4}, zone_hndl_2}
    ,{{1, 2, 3, 4}, nullptr}
};


void tuiWin_t::vEventHndlKey_up	(void)  {
    if(g_po->g_bElementList) {
        if(g_po->g_pCurrentElement) {
            g_po->g_pCurrentElement->element->deSelect();
            if(g_po->g_elementList == g_po->g_pCurrentElement)
                g_po->g_pCurrentElement = g_po->g_pLastElement;
            g_po->g_pCurrentElement--;
        } else {
            g_po->g_pCurrentElement = g_po->g_elementList;
        }
        g_po->g_pCurrentElement->element->selectByKey();
    } else
        mvwprintw(g_po->g_ncursWin, 4, 5, "NO ELEMENTS");
}

void tuiWin_t::vEventHndlKey_down	(void)  {
    if(g_po->g_bElementList) {
        if(g_po->g_pCurrentElement) {
            g_po->g_pCurrentElement->element->deSelect();
            g_po->g_pCurrentElement++;
            if(g_po->g_pLastElement == g_po->g_pCurrentElement)
                g_po->g_pCurrentElement = g_po->g_elementList;
        } else {
            g_po->g_pCurrentElement = g_po->g_elementList;
        }
        g_po->g_pCurrentElement->element->selectByKey();
    }
}

void tuiWin_t::vEventHndlKey_left	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_right	(void)  {
    //mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    //g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_enter	(void)  {
    g_po->g_pCurrentElement->element->eventOn();
}

void tuiWin_t::vEventHndlKey_home	(void)  {
    // mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key home");
    // go back to parent window
    if(g_po->g_poFather) g_po->g_poFather->eventOn();

}


event_t tuiWin_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
};


