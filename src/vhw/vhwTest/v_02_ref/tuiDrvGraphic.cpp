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
 * tuiDrvGraphic.h
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 

#include "tuiDrvGraphic.h"

#define OFF     0
#define ON      1

// ************************************************************************************************************************************************
// ************************************************************************************************************************************************
// CONSTRUCTOR function section - START

tuiDrvGraphic_t::tuiDrvGraphic_t    (tuiUnitAbstract_t* p_pUnit     )      :
    tuiGraphicAbstract_t        (p_pUnit    )
{}

tuiDrvGraphic_t::tuiDrvGraphic_t    (tuiUnitAbstract_t* p_pUnit     ,box_t p_box    )      :
    tuiGraphicAbstract_t        (p_pUnit    ,p_box  )
{}

tuiDrvGraphic_t::tuiDrvGraphic_t    (tuiUnitAbstract_t* p_pUnit                     ,margins_t p_margin )      :
    tuiGraphicAbstract_t        (p_pUnit            ,p_margin   )
{}

tuiDrvGraphic_t::tuiDrvGraphic_t    (tuiUnitAbstract_t* p_pUnit     ,box_t p_box    ,margins_t p_margin )      :
    tuiGraphicAbstract_t        (p_pUnit    ,p_box  ,p_margin   )
{}

// CONSTRUCTOR function section - END
// ************************************************************************************************************************************************
// ************************************************************************************************************************************************


// ------------------------------------------------------------------------------------------------------------------------------------------------

// ************************************************************************************************************************************************
// ************************************************************************************************************************************************
// DEBUG section - START

void tuiDrvGraphic_t::dbgSetChildrenNumber    (uint8_t p_childrenNumber)     {
    g_childrenNumber     = p_childrenNumber;
}


// DEBUG section - END
// ************************************************************************************************************************************************
// ************************************************************************************************************************************************

// ------------------------------------------------------------------------------------------------------------------------------------------------

// ************************************************************************************************************************************************
// ************************************************************************************************************************************************
// GENERAL section - START



// GENERAL section - END
// ************************************************************************************************************************************************
// ************************************************************************************************************************************************

// ------------------------------------------------------------------------------------------------------------------------------------------------

// ************************************************************************************************************************************************
// ************************************************************************************************************************************************
// INIT function section - START


void tuiDrvGraphic_t::setNcursesWindow    (tuiDrvGraphic_t* p_pParent)     {
    g_pNcursWin     = p_pParent->g_pNcursWin;
}

void tuiDrvGraphic_t::initGraphEnv        (void)     {
    initscr();                          /* Start curses mode            */

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

void tuiDrvGraphic_t::initGraphEnvColor (void)    {
    start_color();    // BE CAREFUL!! - this instruction must be execute before init_pair function              /* Start color                  */

    // a) init color windows management
    NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_SELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_EVENT_ON;
    NCURS_COLOR_PAIR_INIT_WINDOW_YELLOW;
    NCURS_COLOR_PAIR_INIT_WINDOW_MAGENTA;
    NCURS_COLOR_PAIR_INIT_WINDOW_CYAN;
    NCURS_COLOR_PAIR_INIT_WINDOW_WHITE;

}
void tuiDrvGraphic_t::deinitGraphEnv    (void)    {
    NCURS_MOUSE_TRACKING_DISABLE
    mvwprintw(g_pNcursWin, 3, 5, "Exiting ... ");
}

void tuiDrvGraphic_t::initWinRootDims   (void) {
    getmaxyx(stdscr,g_h,g_w);
}


void tuiDrvGraphic_t::initWin           (void) {

    g_pNcursWin = newwin(g_h, g_w, g_mouseY0a, g_mouseX0a);
}

void tuiDrvGraphic_t::initWin           (uint16_t p_rootX0a, uint16_t p_rootY0a) {

    g_pNcursWin = newwin(g_h, g_w, p_rootY0a, p_rootX0a);

}

void tuiDrvGraphic_t::endGraphEnv       (void)  {
    nodelay(stdscr, false);
    getch();                            /* Print it on to the real screen */
    clrtoeol();
	refresh();
    endwin();                           /* Wait for user input */
}

// INIT function section - END
// ************************************************************************************************************************************************
// ************************************************************************************************************************************************

// ------------------------------------------------------------------------------------------------------------------------------------------------

// ************************************************************************************************************************************************
// ************************************************************************************************************************************************
// OUTPUT function section - START


// PUBLIC sub-section

void tuiDrvGraphic_t::refreshWin     (void)  {
    wrefresh(g_pNcursWin);
    refreshWinChildren();
}

void tuiDrvGraphic_t::frameClear (void)   {

    for(uint16_t l_row = g_boundYupper+1; l_row < g_boundYlower; l_row++)  {
        wattron  (g_pNcursWin,A_NORMAL);
        mvwhline    (g_pNcursWin, l_row          ,g_x0a + 1           ,' '    ,g_w - 2);
    }
    refreshWin();
}


void tuiDrvGraphic_t::frameNnameTest (const char* p_strName)   {
    frameNnameTest(g_status, p_strName);
    if(g_boundYupper <= g_boundYlower)  {

        g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

        if(g_boundYupper < g_boundYlower)  {
            if((g_boundYlower+1) == (g_y0a + g_h))   {
            	mvwvline(g_pNcursWin, g_boundYupper          ,g_x0a               ,0    ,g_boundYlower - g_boundYupper      );
            	mvwvline(g_pNcursWin, g_boundYupper          ,g_x0a + g_w - 1     ,0    ,g_boundYlower - g_boundYupper      );
            } else {
            	mvwvline(g_pNcursWin, g_boundYupper          ,g_x0a               ,0    ,g_boundYlower - g_boundYupper + 1      );
            	mvwvline(g_pNcursWin, g_boundYupper          ,g_x0a + g_w - 1     ,0    ,g_boundYlower - g_boundYupper + 1      );
            }
        }

        if(g_boundYupper == g_y0a)   {
        	mvwaddch    (g_pNcursWin, g_boundYupper     ,g_x0a               ,ACS_ULCORNER       );
        	mvwaddch    (g_pNcursWin, g_boundYupper     ,g_x0a + g_w - 1     ,ACS_URCORNER       );
        	mvwhline    (g_pNcursWin, g_boundYupper     ,g_x0a + 1           ,0    ,g_w - 2      );
            //mvwprintw   (g_pNcursWin, g_boundYupper     ,g_x0a + 4, " *~ %s ~*~ %04x - %04x | %04x - %04x ~* ", p_strName,  g_lvl1Y0a,  g_h, g_w, g_boundYlower);
            //mvwprintw   (g_pNcursWin, g_boundYupper     ,g_x0a + 4, " __ dsp - TEST __*~ %s ~*~ %04x - %04x - %04x - %04x ~* ", p_strName, g_boundYupper,  g_boundYlower, g_boundXleft,  g_boundXright);
            mvwprintw   (g_pNcursWin, g_boundYupper     ,g_x0a + 1, "~ %s ~", p_strName);
            if(((g_boundYupper+1) <= g_boundYlower))
                mvwprintw   (g_pNcursWin, g_boundYupper+1 ,g_x0a + 1, "~ %04x - %04x ~", g_boundYupper,  g_boundYlower);
        }

        if(
            (    
                    (g_boundYupper == (g_y0a+1))
                &&  ((g_boundYupper+1) <= g_boundYlower)
            )
        )
            mvwprintw   (g_pNcursWin, g_boundYupper   ,g_x0a + 1, "~ %04x - %04x ~", g_boundYupper,  g_boundYlower);

        if((g_boundYlower+1) == (g_y0a + g_h))   {
        	mvwaddch    (g_pNcursWin, g_boundYlower     ,g_x0a               ,ACS_LLCORNER       );
        	mvwaddch    (g_pNcursWin, g_boundYlower     ,g_x0a + g_w - 1     ,ACS_LRCORNER       );
        	mvwhline    (g_pNcursWin, g_boundYlower     ,g_x0a + 1           ,0    ,g_w - 2      );
            mvwprintw   (g_pNcursWin, g_boundYlower     ,g_x0a + 1, "~ %04x - %04x ~", g_boundXleft,   g_boundXright);
        }


        g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

        refreshWin();
    }
}

bool tuiDrvGraphic_t::frameNnameTest (tuiMode_t p_mode, const char* p_strName)   {
    if(g_status == p_mode) return false; 
    g_status = p_mode;

    frameNnameTest(p_strName);

    return false;
}

void tuiDrvGraphic_t::nameNstatus (const char* p_strName, uint8_t p_status)   {

    if(g_boundYupper <= g_boundYlower)    {
        g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, ON);
        mvwprintw(g_pNcursWin, g_y0a, g_x0a, "-- %s -- %02d", p_strName, p_status);
        g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, OFF);

        refreshWin();
    }
}

bool tuiDrvGraphic_t::nameNstatus (tuiMode_t p_mode, const char* p_strName, uint8_t p_status)   {
    if(g_status == p_mode) return false; 
    g_status = p_mode;

    if(g_boundYupper <= g_boundYlower)    {
        g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, ON);

        mvwprintw(g_pNcursWin, g_y0a, g_x0a, "-- %s -- %02d", p_strName, p_status);

        g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, OFF);

        refreshWin();
    }
    return true;
}

bool tuiDrvGraphic_t::nameNstatus (tuiMode_t p_mode, const char* p_strName, uint8_t p_status, bool p_repaint)   {
    if(
            (g_status == p_mode)
        &&  (!p_repaint)
    )   return false; 
    g_status = p_mode;

    if(g_boundYupper <= g_boundYlower)    {
        g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, ON);

        mvwprintw(g_pNcursWin, g_y0a, g_x0a, "-- %s -- %02d", p_strName, p_status);

        g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, OFF);

        refreshWin();
    }
    return true;
}

void tuiDrvGraphic_t::content (char* p_str, uint8_t p_size)   {
    int16_t l_row = getBoundYupper();
    if(
            (g_boundYupper <= l_row)  
        &&  (                 l_row <= g_boundYlower)
    )    {

        uint16_t l_dspBoxW = getDspBoxDimXw();
        mvwaddnstr  (g_pNcursWin, l_row          ,g_x0a + 1        ,p_str  ,p_size);
        if(p_size < l_dspBoxW)
            mvwhline    (g_pNcursWin, l_row          ,g_x0a + 1 + p_size           ,' '    ,l_dspBoxW - p_size      );

        refreshWin();
    }
}

void tuiDrvGraphic_t::content (char* p_str, uint8_t p_begin, uint8_t p_size)   {
    int16_t l_row = getBoundYupper();
    if(
            (g_boundYupper <= l_row)  
        &&  (                 l_row <= g_boundYlower)  
    )    {
        uint16_t l_dspBoxW = getDspBoxDimXw();
        mvwaddnstr  (g_pNcursWin, l_row          ,g_x0a + 1 + p_begin       ,p_str  ,p_size);
        if(p_size < l_dspBoxW)
            mvwhline    (g_pNcursWin, l_row          ,g_x0a + 1 + p_begin + p_size           ,' '    ,l_dspBoxW - (p_begin + p_size)      );

        refreshWin();
    }
}

void tuiDrvGraphic_t::content (uint8_t p_begin)   {
    int16_t l_row = getBoundYupper();
    if(
            (g_boundYupper <= l_row)  
        &&  (                 l_row <= g_boundYlower)  
    )    {
        uint16_t l_dspBoxW = getDspBoxDimXw();
        mvwhline    (g_pNcursWin, l_row          ,g_x0a + 1 + p_begin           ,' '    ,l_dspBoxW - p_begin      );

        refreshWin();
    }
}


void tuiDrvGraphic_t::positionCursor     (bool p_status, uint8_t p_position)    {
    int16_t l_row = getBoundYupper();
    if(
            (g_boundYupper <= l_row)  
        &&  (                l_row <= g_boundYlower)
    )    {
        if(p_status)    {
            if(g_position != p_position)    {
                mvwchgat(g_pNcursWin, l_row          ,g_x0a + 1 + g_position,1, A_NORMAL, 0, NULL);
                g_position = p_position;
            }
            mvwchgat(g_pNcursWin, l_row          ,g_x0a + 1 + g_position,1, A_BLINK | A_UNDERLINE, 0, NULL);
        } else {
            g_position = p_position;
            mvwchgat(g_pNcursWin, l_row          ,g_x0a + 1 + p_position,1, A_NORMAL, 0, NULL);    
        }
        refreshWin();
    }
}


bool tuiDrvGraphic_t::isSelectedOrEventOn             (void)  {
    return (
            (tuiMode_t::select == g_status) ||
            (tuiMode_t::eventOn == g_status)
    );
}

bool tuiDrvGraphic_t::isSelected             (void)  {
    return (tuiMode_t::select == g_status);
}

void tuiDrvGraphic_t::dbgPrint             (char* p_str)       {
    [[maybe_unused]] uint16_t l_h;
    uint16_t l_w;
    getmaxyx(stdscr, l_h, l_w);
    if(80 < l_w)    {
        mvwhline    (stdscr, 2, 80, ' '         , l_w - 80);
        mvwprintw   (stdscr, 2, 80, "*** %s ***", p_str);
        refreshWin();
    }
}



// PRIVATE sub-section

void tuiDrvGraphic_t::attributeMode_frameDeselect (tuiDrvGraphic_t* p_this, uint8_t p_status)   {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
}

void tuiDrvGraphic_t::attributeMode_frameSelect (tuiDrvGraphic_t* p_this, uint8_t p_status)     {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
}

void tuiDrvGraphic_t::attributeMode_frameEventOn (tuiDrvGraphic_t* p_this, uint8_t p_status)    {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
}

void tuiDrvGraphic_t::attributeMode_lineDeselect ([[maybe_unused]]tuiDrvGraphic_t* p_this, [[maybe_unused]] uint8_t p_status)    {
    //if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    //if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
}

void tuiDrvGraphic_t::attributeMode_lineSelect (tuiDrvGraphic_t* p_this, uint8_t p_status)      {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,A_UNDERLINE);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,A_UNDERLINE);
}

void tuiDrvGraphic_t::attributeMode_lineEventOn (tuiDrvGraphic_t* p_this, uint8_t p_status)     {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
//    if(OFF == p_status) wattroff(p_this->g_pNcursWin,A_REVERSE);
//    if(ON  == p_status) wattron (p_this->g_pNcursWin,A_REVERSE);
}

tuiDrvGraphic_t::attributeFunc_t  tuiDrvGraphic_t::g_attributeMode_Frame[] = {
     attributeMode_frameDeselect
    ,attributeMode_frameDeselect
    ,attributeMode_frameSelect
    ,attributeMode_frameEventOn
};

tuiDrvGraphic_t::attributeFunc_t  tuiDrvGraphic_t::g_attributeMode_Line[] = {
     attributeMode_lineDeselect
    ,attributeMode_lineDeselect
    ,attributeMode_lineSelect
    ,attributeMode_lineEventOn
};

// OUTPUT function section - END
// ************************************************************************************************************************************************
// ************************************************************************************************************************************************

// ------------------------------------------------------------------------------------------------------------------------------------------------

// ************************************************************************************************************************************************
// ************************************************************************************************************************************************
// OUTPUT function section - START


int      tuiDrvGraphic_t::g_ncursEventCode;
MEVENT   tuiDrvGraphic_t::g_mouseEvent;

bool tuiDrvGraphic_t::uiEventStatus                                 (void)  {
    bool l_result;
    g_ncursEventCode = wgetch(g_pNcursWin);
    l_result = (ERR != g_ncursEventCode);
    return l_result;
}

int tuiDrvGraphic_t::uiEventKeyCode                                 (void)  {
    return g_ncursEventCode;
}

tuiEventCode_t  tuiDrvGraphic_t::uiHandlerEventCode                 (void)  {
    tuiEventCode_t l_eventCode = tuiEventCode_t::noEvent;
    switch(g_ncursEventCode)    {
        case KEY_MOUSE:
            mvwprintw(g_pNcursWin, 2, 50, "MOUSE_EVENT");
            l_eventCode = tuiEventCode_t::mouse;
            getmouse(&g_mouseEvent);
            char l_str[30];
            snprintf(l_str, sizeof l_str,"%03d / %03d", g_mouseEvent.x, g_mouseEvent.y);
            mvwprintw(g_pNcursWin, 3, 50, "MOUSE_coordinates: %s",l_str);
            snprintf(l_str, sizeof l_str,"%08lx", g_mouseEvent.bstate);
            mvwprintw(g_pNcursWin, 4, 50, "MOUSE_status: %s",l_str);
            if(TUI_MOUSE_ROLL_UP    == g_mouseEvent.bstate) l_eventCode = tuiEventCode_t::mouseRollUp;
            if(TUI_MOUSE_ROLL_DOWN  == g_mouseEvent.bstate) l_eventCode = tuiEventCode_t::mouseRollDown;            
            break;
        case KEY_DOWN:
        case TUI_KEY_TAB:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_DOWN                            ");
            l_eventCode = tuiEventCode_t::keyDown;
            break;
        case KEY_UP:
        case TUI_KEY_SHIFT_TAB:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_UP                              ");
            l_eventCode = tuiEventCode_t::keyUp;
            break;
        case KEY_LEFT:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_LEFT                            ");
            l_eventCode = tuiEventCode_t::keyLeft;
            break;
        case KEY_RIGHT:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_RIGHT                           ");
            l_eventCode = tuiEventCode_t::keyRight;
            break;
        case KEY_ENTER:
        case TUI_KEY_RETURN:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_ENTER                           ");
            l_eventCode = tuiEventCode_t::keyEnter;
            break;
        case KEY_HOME:
        case TUI_KEY_ESC:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_HOME                            ");
            l_eventCode = tuiEventCode_t::keyHome;
            break;
        case TUI_KEY_DEL:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_DEL                             ");
            l_eventCode = tuiEventCode_t::keyDel;
            break;
        case TUI_KEY_BACKSPACE:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_BACKSPACE                       ");
            l_eventCode = tuiEventCode_t::keyBackspace;
            break;
        default:
            if((0x20 <= g_ncursEventCode) && (g_ncursEventCode < 0x7f)) {
                mvwprintw(g_pNcursWin, 2, 50, "type character - keyCode: %04x", g_ncursEventCode);
                l_eventCode = tuiEventCode_t::keyTypeChar;
            } else {
                mvwprintw(g_pNcursWin, 2, 50, "UNKNOWN_EVENT - keyCode: %04x", g_ncursEventCode);
            }
            break;
    }

    return l_eventCode;
}

bool tuiDrvGraphic_t::uiMouseEventStatus                            (void)  {
    bool l_result;
    
    //l_result = (getmouse(&g_mouseEvent) == OK);
    l_result = true;
    g_xMouse = g_mouseEvent.x;
    g_yMouse = g_mouseEvent.y;

    return l_result;
}

bool tuiDrvGraphic_t::uiMouseEventCode_ButtonPressed             (void)  {
    bool l_result;
    l_result = (
                    (g_mouseEvent.bstate & BUTTON1_PRESSED  )
                ||  (g_mouseEvent.bstate & BUTTON1_CLICKED  )     
                //||  (g_mouseEvent.bstate & BUTTON1_RELEASED )     
            );
    return l_result;
}

// INPUT function section - END
// ************************************************************************************************************************************************
// ************************************************************************************************************************************************


