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

#define KEY_RETURN  0x0A


tuiWin_t*	tuiWin_t::g_po = nullptr;

// tuiWin_t::tuiWin_t      (void)    :
//     tuiBaseUnit_t(g_zoneList)
// {}
// 
tuiWin_t::tuiWin_t      (box_t* p_box)    :
    tuiBaseUnit_t           (p_box, g_zoneList)
{}

tuiWin_t::tuiWin_t      (box_t* p_box, element_t* p_elementList)    :
     tuiBaseUnit_t          (p_box, g_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
{}

tuiWin_t::tuiWin_t      (box_t* p_box, zone_t* p_zoneList)    :
    tuiBaseUnit_t           (p_box, p_zoneList)
{}

tuiWin_t::tuiWin_t      (box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseUnit_t          (p_box, p_zoneList)
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
{}

tuiWin_t::tuiWin_t      (const char* p_strName, box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiBaseUnit_t          (p_box, p_zoneList)
    ,g_strName              {p_strName}
    ,g_elementList          {p_elementList}
    ,g_pCurrentElement      {p_elementList}
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
    if(p_poFather) {
        g_ncursWin = newwin(g_pBox->height, g_pBox->width, g_pBox->yStart, g_pBox->xStart);
        box(g_ncursWin, 0, 0);
    }
    else
    {   // the current instance is the main window, therefore ...
        // 2. set the pointer of ncurses window to main window [stdsrc]
        g_ncursWin = stdscr;
        g_poSelected = this;
        // 4. complete ncurses initialization
        raw();                              /* Line buffering disabled        */
        nodelay(g_ncursWin, true);
        keypad(g_ncursWin, TRUE);           /* We get F1, F2 etc..            */
        noecho();                           /* Don't echo() while we do getch */
        mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
        printf("\033[?1003h\n"); // Makes the terminal report mouse movement events                
    }

    //if(has_colors() == FALSE)
    //{       
    //    printf("Your terminal does not support color\n");
    //}
    start_color();                  /* Start color                  */
    init_pair(1, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(2, COLOR_RED,     COLOR_BLUE);

    wattron(g_ncursWin, COLOR_PAIR(2));
    mvwprintw(g_ncursWin, 2, 2, "window name: %s \n", g_strName);
    wrefresh(g_ncursWin);
    wattroff(g_ncursWin, COLOR_PAIR(2));

    // // 3. run [init] function for each my [child] elements
    element_t* l_element = g_elementList;
    //uint8_t l_cnt = 3;
    while(l_element->element)    {
        l_element->element->init(this);
        l_element++;
    }
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
                printf("\033[?1003l\n"); // Disable mouse movement events, as l = low
                mvwprintw(g_ncursWin, 9, 2, "Exiting ... \n");
            } else {
                switch(l_ncursEventCode)    {
                    case KEY_MOUSE:
                        mvwprintw(g_ncursWin, 8, 1, "MOUSE_EVENT");
                        l_eventCode = tuiEventCode_t::mouse;
                        break;
                    case KEY_DOWN:
                        mvwprintw(g_ncursWin, 8, 1, "KEY_DOWN");
                        l_eventCode = tuiEventCode_t::keyDown;
                        break;
                    case KEY_UP:
                        mvwprintw(g_ncursWin, 8, 1, "KEY_UP");
                        l_eventCode = tuiEventCode_t::keyUp;
                        break;
                    case KEY_LEFT:
                        mvwprintw(g_ncursWin, 8, 1, "KEY_LEFT");
                        l_eventCode = tuiEventCode_t::keyLeft;
                        break;
                    case KEY_RIGHT:
                        mvwprintw(g_ncursWin, 8, 1, "KEY_RIGHT");
                        l_eventCode = tuiEventCode_t::keyRight;
                        break;
                    case KEY_ENTER:
                    case KEY_RETURN:
                        mvwprintw(g_ncursWin, 8, 1, "KEY_ENTER");
                        l_eventCode = tuiEventCode_t::keyEnter;
                        break;
                    case KEY_HOME:
                        mvwprintw(g_ncursWin, 8, 1, "KEY_HOME");
                        l_eventCode = tuiEventCode_t::keyHome;
                        break;
                    default:
                        mvwprintw(g_ncursWin, 8, 1, "UNKNOWN_EVENT");
                        break;
                }
            }
        }
    }

    //if(tuiEventCode_t::noEvent != l_eventCode) tuiBaseUnit_t::g_eventArray[static_cast<uint8_t>(l_eventCode)]();
    if(tuiEventCode_t::mouse == l_eventCode) {
        g_eventArray[tuiEventCodeNum(l_eventCode)]();
    } else {
        if(tuiEventCode_t::noEvent != l_eventCode) tuiBaseUnit_t::g_eventArray[tuiEventCodeNum(l_eventCode)]();
    }

    return l_result;
}


//void EventOn    (uiBase* p_pFather) override;

void tuiWin_t::select     (void)    {
    start_color();                  /* Start color                  */

    deSelectSelected         (this);
    wattron(g_ncursWin,COLOR_PAIR(2));
    // refresh current window and ...
    //mvwprintw(g_ncursWin, 0, 0, " 1st row - window name: %s \n", g_strName);
    mvwprintw(g_ncursWin, 1, 1, " 2nd row - window name: %s \n", g_strName);
    mvwprintw(g_ncursWin, 2, 1, " 3rd row - window name: %s \n", g_strName);

    box(g_ncursWin, 0, 0);
    wrefresh(g_ncursWin);
    wattroff(g_ncursWin,COLOR_PAIR(2));

    //mvwprintw(g_ncursWin, 3, 0, " 4th row - window name: %s \n", g_strName);
    // ... its elements

}

void tuiWin_t::deSelect     (void)    {
    start_color();                  /* Start color                  */

    // refresh current window and ...
    wclear(g_ncursWin);
    wattron(g_ncursWin,COLOR_PAIR(1));
    box(g_ncursWin, 0, 0);
    wrefresh(g_ncursWin);
    wattroff(g_ncursWin,COLOR_PAIR(1));

    // ... its elements

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
    //,nullptr
};


void tuiWin_t::vEventHndlKey_down	(void)  {
    mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key down");
    g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_up	(void)  {
    mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key up");
    if(g_po->g_bElementList) {
        //g_po->g_pCurrentElement->element->deSelect();
        g_po->g_pCurrentElement++;
        if(g_po->g_pLastElement == g_po->g_pCurrentElement)
            g_po->g_pCurrentElement = g_po->g_elementList;
        g_po->g_pCurrentElement->element->select();
    } else {
        mvwprintw(g_po->g_ncursWin, 0, 30, "No elements!!!");
    }
}

void tuiWin_t::vEventHndlKey_left	(void)  {
    mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key left");
    g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_right	(void)  {
    mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key right");
    g_po->g_pCurrentElement = g_po->g_elementList;
}

void tuiWin_t::vEventHndlKey_enter	(void)  {
    mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key enter");
    //g_po->g_pCurrentElement->element->eventOn();
}

void tuiWin_t::vEventHndlKey_home	(void)  {
    mvwprintw(g_po->g_ncursWin, 0, 30, "event hndl - key home");
    // go back to parent window
    // g_po->g_poFather->eventOn();
    // //g_po->g_pCurrentElement->element->eventOn();
}

// it can be run only by [main_window] therefore ...
// its elements are all & only windows
void tuiWin_t::vEventHndlMouse	(void)  {
    MEVENT l_mouseEvent;
    int l_mouseEventStatus = getmouse(&l_mouseEvent);
    //mvwprintw(g_po->g_ncursWin, 5, 0, "getch: %04x - getmouse: %08x - mouseEvent .state %08x - .x: %04d - .y: %04d", l_ncursEventCode, l_mouseEventStatus, l_mouseEvent.bstate, l_mouseEvent.x, l_mouseEvent.y);
    mvwprintw(g_po->g_ncursWin, 5, 0, "getmouse: %08x - mouseEvent .state %08x - .x: %04d - .y: %04d", l_mouseEventStatus, l_mouseEvent.bstate, l_mouseEvent.x, l_mouseEvent.y);
    if(l_mouseEventStatus == OK)  { /* When the user clicks left mouse button */
        if(l_mouseEvent.bstate & BUTTON1_PRESSED)  {
            mvwprintw(g_po->g_ncursWin, 6, 1, "Left button of mouse was pressed");
        }
        else {
            mvwprintw(g_po->g_ncursWin, 7, 1, "Another button of mouse was pressed instead of the left one");
        }
    } else mvwprintw(g_po->g_ncursWin, 8, 2, "getmouse() function failed! Its return value is different from \"OK\" - %08x", l_mouseEventStatus);

    element_t* l_element = g_po->g_elementList;
    element_t* l_elementSelected = nullptr;
    while(l_element->element)    {
        if(l_element->element->bMouseClickInsideBounds({static_cast<uint8_t>(l_mouseEvent.x), static_cast<uint8_t>(l_mouseEvent.y)})) {
            //g_po->g_pCurrentElement->element->deSelect();

            if(l_elementSelected) {
                mvwprintw(g_po->g_ncursWin, 2, 1, "p_selCnt1: %02x - p_selCnt2: %02x", static_cast<tuiWin_t*>(l_elementSelected->element)->g_selCnt, static_cast<tuiWin_t*>(l_element->element)->g_selCnt);
                if(bTstSelCnts(static_cast<tuiWin_t*>(l_elementSelected->element)->g_selCnt, static_cast<tuiWin_t*>(l_element->element)->g_selCnt)) {
                    l_elementSelected = l_element;
                }
            } else {
                l_elementSelected = l_element;
            }
            // static_cast<tuiWin_t*>(l_element->element)->select();
            // g_po->g_pCurrentElement = l_element;
            // mvwprintw(g_po->g_ncursWin, 8, 2, "window \"%s\" selcted by mouse", static_cast<tuiWin_t*>(l_element->element)->g_strName);
            // break;
        }
        l_element++;
    }
    if(l_elementSelected) {
        static_cast<tuiWin_t*>(l_elementSelected->element)->select();
        g_po->g_pCurrentElement = l_elementSelected;
        mvwprintw(g_po->g_ncursWin, 8, 2, "window \"%s\" selcted by mouse", static_cast<tuiWin_t*>(l_elementSelected->element)->g_strName);
    }

}

event_t tuiWin_t::g_eventArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
    ,vEventHndlMouse
};


