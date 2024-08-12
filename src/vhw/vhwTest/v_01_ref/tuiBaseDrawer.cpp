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
 * tuiBaseDrawer.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */

#include "tuiBaseDrawer.h"

uint8_t tuiBaseDrawer_t::g_xMouse;
uint8_t tuiBaseDrawer_t::g_yMouse;
int      tuiBaseDrawer_t::g_ncursEventCode;
MEVENT   tuiBaseDrawer_t::g_mouseEvent;

#define OFF     0
#define ON      1


tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t *p_pBox) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_pBox->height}
    ,g_w            {p_pBox->width}
    ,g_y0r          {p_pBox->yStart}
    ,g_x0r          {p_pBox->xStart}
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_status       {tuiMode_t::deselect}
    ,g_strName      {p_strName}
    ,g_pDtyStatus   {nullptr}
{}

tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_box.height   }
    ,g_w            {p_box.width    }
    ,g_y0r          {p_box.yStart   }
    ,g_x0r          {p_box.xStart   }
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_status       {tuiMode_t::deselect}
    ,g_strName      {p_strName      }
    ,g_pDtyStatus   {p_pDtyStatus   }
{}

void tuiBaseDrawer_t::initGraphEnv        (void)     {

    // the current instance is the main window, therefore ...

    // 2. set the pointer of ncurses window to main window [stdsrc]
    g_pNcursWin = stdscr;
    // 3. complete ncurses initialization
    raw();                              /* Line buffering disabled        */
    nodelay(g_pNcursWin, true);
    keypad(g_pNcursWin, TRUE);           /* We get F1, F2 etc..            */
    noecho();                           /* Don't echo() while we do getch */
    curs_set(0);                        /* make cursor invisible */
    mousemask(  ALL_MOUSE_EVENTS |      \
                REPORT_MOUSE_POSITION,  \
                NULL);
    // 3.1. enable the continuously monitoring of mouse movement
    NCURS_MOUSE_TRACKING_ENABLE

}

void tuiBaseDrawer_t::initGraphEnvColor (void)    {
    start_color();    // BE CAREFUL!! - this instruction must be execute before init_pair function              /* Start color                  */

    // a) init color windows management
    NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_SELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_EVENT_ON;

}
void tuiBaseDrawer_t::deinitGraphEnv    (void)    {
    NCURS_MOUSE_TRACKING_DISABLE
    mvwprintw(g_pNcursWin, 3, 5, "Exiting ... ");
}

void tuiBaseDrawer_t::initWin           (void) {
    g_pNcursWin = newwin(g_h, g_w, g_y0r, g_x0r);
}

void tuiBaseDrawer_t::endGraphEnv       (void)  {
    nodelay(stdscr, false);
    getch();                            /* Print it on to the real screen */
    clrtoeol();
	refresh();
    endwin();                           /* Wait for user input */
}

void tuiBaseDrawer_t::frame (tuiMode_t p_mode)   {
    g_status = p_mode;
    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, ON);

	mvwaddch(g_pNcursWin, g_y0r              ,g_x0r               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0r              ,g_x0r + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0r + g_h - 1    ,g_x0r               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0r + g_h - 1    ,g_x0r + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0r              ,g_x0r + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0r + g_h - 1    ,g_x0r + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0r + 1          ,g_x0r               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0r + 1          ,g_x0r + g_w - 1     ,0    ,g_h - 2      );

    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);

}

void tuiBaseDrawer_t::frameNname (tuiMode_t p_mode)   {
    g_status = p_mode;
    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, ON);

	mvwaddch(g_pNcursWin, g_y0r              ,g_x0r               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0r              ,g_x0r + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0r + g_h - 1    ,g_x0r               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0r + g_h - 1    ,g_x0r + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0r              ,g_x0r + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0r + g_h - 1    ,g_x0r + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0r + 1          ,g_x0r               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0r + 1          ,g_x0r + g_w - 1     ,0    ,g_h - 2      );

    mvwprintw(g_pNcursWin, g_y0Win + 0, g_x0Win + 4, " *~ %s ~* ", g_strName);

    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);

}

void tuiBaseDrawer_t::frameBox (void)   {
    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

    box         (g_pNcursWin, 0, 0);                  // BE CAREFUL !! - if (g_ncursWin==stdscr) this instructions clear all sub-windows and you have to repaint the box and refresh subwindow
    mvwprintw   (g_pNcursWin, 0, 10, " *** window name: %s *** ", g_strName);

    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh    (g_pNcursWin);

}

void tuiBaseDrawer_t::frameBox (tuiMode_t p_mode)   {
    g_status = p_mode;
    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, ON);

    box(g_pNcursWin, 0, 0);                  // BE CAREFUL !! - if (g_ncursWin==stdscr) this instructions clear all sub-windows and you have to repaint the box and refresh subwindow
    mvwprintw   (g_pNcursWin, 0, 10, " *** window name: %s *** ", g_strName);

    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);

}


void tuiBaseDrawer_t::name (tuiMode_t p_mode)   {
    g_status = p_mode;
    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, ON);

    mvwprintw(g_pNcursWin, g_y0Win + g_y0r, g_x0Win + g_x0r, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);

    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, OFF);


    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::nameNstatus (tuiMode_t p_mode)   {
    g_status = p_mode;
    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, ON);

    mvwprintw(g_pNcursWin, g_y0Win + g_y0r, g_x0Win + g_x0r, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);

    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::nameNstatus (void)   {

    g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, ON);
    mvwprintw(g_pNcursWin, g_y0Win + g_y0r, g_x0Win + g_x0r, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);
}

bool tuiBaseDrawer_t::bMouseClickInsideBounds (void)      {
    bool l_result = false;

    if(
        ((g_x0a <= g_xMouse) && (g_xMouse < (g_x0a + g_w ))) &&
        ((g_y0a <= g_yMouse) && (g_yMouse < (g_y0a + g_h )))
    ) {
        l_result = true;

    }
    return l_result;
}

bool tuiBaseDrawer_t::uiEventStatus                                 (void)  {
    bool l_result;
    g_ncursEventCode = wgetch(g_pNcursWin);
    l_result = (ERR != g_ncursEventCode);
    return l_result;
}

int tuiBaseDrawer_t::uiEventKeyCode                                 (void)  {
    return g_ncursEventCode;
}

tuiEventCode_t  tuiBaseDrawer_t::uiHandlerEventCode                 (void)  {
    tuiEventCode_t l_eventCode = tuiEventCode_t::noEvent;
    switch(g_ncursEventCode)    {
        case KEY_MOUSE:
            mvwprintw(g_pNcursWin, 2, 50, "MOUSE_EVENT");
            l_eventCode = tuiEventCode_t::mouse;
            break;
        case KEY_DOWN:
        case TUI_KEY_TAB:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_DOWN");
            l_eventCode = tuiEventCode_t::keyDown;
            break;
        case KEY_UP:
        case TUI_KEY_SHIFT_TAB:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_UP");
            l_eventCode = tuiEventCode_t::keyUp;
            break;
        case KEY_LEFT:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_LEFT");
            l_eventCode = tuiEventCode_t::keyLeft;
            break;
        case KEY_RIGHT:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_RIGHT");
            l_eventCode = tuiEventCode_t::keyRight;
            break;
        case KEY_ENTER:
        case TUI_KEY_RETURN:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_ENTER");
            l_eventCode = tuiEventCode_t::keyEnter;
            break;
        case KEY_HOME:
        case TUI_KEY_ESC:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_HOME");
            l_eventCode = tuiEventCode_t::keyHome;
            break;
        default:
            mvwprintw(g_pNcursWin, 2, 50, "UNKNOWN_EVENT - keyCode: %04x", g_ncursEventCode);
            break;
    }

    return l_eventCode;
}

bool tuiBaseDrawer_t::uiMouseEventStatus                            (void)  {
    bool l_result;
    
    l_result = (getmouse(&g_mouseEvent) == OK);
    g_xMouse = g_mouseEvent.x;
    g_yMouse = g_mouseEvent.y;

    return l_result;
}

bool tuiBaseDrawer_t::uiMouseEventCode_ButtonPressed             (void)  {
    bool l_result;
    l_result = ((g_mouseEvent.bstate & BUTTON1_PRESSED)  ||
                (g_mouseEvent.bstate & BUTTON1_CLICKED)     );
    return l_result;
}

bool tuiBaseDrawer_t::isSelected             (void)  {
    return (tuiMode_t::select == g_status);
}

void tuiBaseDrawer_t::attributeMode_frameDeselect (tuiBaseDrawer_t* p_this, uint8_t p_status)   {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
}

void tuiBaseDrawer_t::attributeMode_frameSelect (tuiBaseDrawer_t* p_this, uint8_t p_status)     {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
}

void tuiBaseDrawer_t::attributeMode_frameEventOn (tuiBaseDrawer_t* p_this, uint8_t p_status)    {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
}

void tuiBaseDrawer_t::attributeMode_lineDeselect ([[maybe_unused]]tuiBaseDrawer_t* p_this, [[maybe_unused]] uint8_t p_status)    {
    //if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    //if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
}

void tuiBaseDrawer_t::attributeMode_lineSelect (tuiBaseDrawer_t* p_this, uint8_t p_status)      {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,A_UNDERLINE);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,A_UNDERLINE);
}

void tuiBaseDrawer_t::attributeMode_lineEventOn (tuiBaseDrawer_t* p_this, uint8_t p_status)     {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
//    if(OFF == p_status) wattroff(p_this->g_pNcursWin,A_REVERSE);
//    if(ON  == p_status) wattron (p_this->g_pNcursWin,A_REVERSE);
}

tuiBaseDrawer_t::attributeFunc_t  tuiBaseDrawer_t::g_attributeMode_Frame[] = {
     attributeMode_frameDeselect
    ,attributeMode_frameSelect
    ,attributeMode_frameEventOn
};

tuiBaseDrawer_t::attributeFunc_t  tuiBaseDrawer_t::g_attributeMode_Line[] = {
     attributeMode_lineDeselect
    ,attributeMode_lineSelect
    ,attributeMode_lineEventOn
};

