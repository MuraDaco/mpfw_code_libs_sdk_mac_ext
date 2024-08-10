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
 

#include "tuiWinRoot.h"



tuiWinRoot_t::tuiWinRoot_t      (const char* p_strName, box_t* p_box, zone_t*    p_zoneList, element_t* p_elementList) :
     tuiWin_t      (p_strName, p_box, p_zoneList, p_elementList)
{}


void tuiWinRoot_t::init       (void* p_poFather) 	{
    g_poFather = static_cast<tuiWin_t*>(p_poFather);

    initTuiNcursesEnv();
    initTuiNcursesColoPair();
    initTuiNcursesBox();
    initElementsList();

    eventOn();
}

void tuiWinRoot_t::initTuiNcursesEnv        (void)    {
    // the current instance is the main window, therefore ...
    // 1. initialize the g_poSelected (the pointer of the instance that is currently selected)
    g_poSelected = this;
    // 2. set the pointer of ncurses window to main window [stdsrc]
    g_ncursWin = stdscr;
    // 3. complete ncurses initialization
    raw();                              /* Line buffering disabled        */
    nodelay(g_ncursWin, true);
    keypad(g_ncursWin, TRUE);           /* We get F1, F2 etc..            */
    noecho();                           /* Don't echo() while we do getch */
    curs_set(0);                        /* make cursor invisible */
    mousemask(  ALL_MOUSE_EVENTS |      \
                REPORT_MOUSE_POSITION,  \
                NULL);
    // 3.1. enable the continuously monitoring of mouse movement
    NCURS_MOUSE_TRACKING_ENABLE
}

void tuiWinRoot_t::initTuiNcursesColoPair      (void)    {
    start_color();    // BE CAREFUL!! - this instruction must be execute before init_pair function              /* Start color                  */

    // a) init color windows management
    NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_SELECT;

}


bool tuiWinRoot_t::loop            (void)  {
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
void tuiWinRoot_t::eventHndlMouse	(void)  {
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
                //static_cast<tuiWin_t*>(l_elementSelected->element)->eventOn();
            } else {
                selectX();

                // ... its elements
                refreshElements();

                eventOn();
            }
            g_pCurrentElement = l_elementSelected;
        }
    }

}


void tuiWinRoot_t::deSelect     (void)    {

    tuiWin_t::deSelect();

    // ... its elements
    refreshElements();

}

void tuiWinRoot_t::refreshElements     (void)    {
    element_t* l_element = g_elementList;

    // c.1) run [init] function for each [child] element
    while(l_element->element)    {
        l_element->element->deSelect();
        l_element++;
    }
}
