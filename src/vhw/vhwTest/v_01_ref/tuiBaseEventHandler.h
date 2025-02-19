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
 * tuiBaseEventHandler.h
 *
 *  Created on: Aug, 8th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_EVENT_HANDLER_H
#define TUI_BASE_EVENT_HANDLER_H

#include <cstdint>
#include "tuiGraphicTypes.h"
#include <ncurses.h>
#include "dtyUint8.h"


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

#define tuiDrawer__mvprintw(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0 + y, g_x0 + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiDrawer__mvwprintw_string(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0 + y, g_x0 + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiDrawer__mvwprintw_keyCode(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0 + y, g_x0 + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__name(y, x)       \
        mvwprintw(g_pNcursWin, g_y0 + y, g_x0 + x, " *~ %s ~* ", tuiBaseDrawer_t::g_strName);     wrefresh(g_pNcursWin)

class tuiBaseDrawer_t   {

public:

    typedef struct __zone__ {
        box_t box;
        func_t hndl;
    } zone_t;

    tuiBaseDrawer_t (box_t *p_pBox);
    tuiBaseDrawer_t (const char* p_strName, box_t *p_pBox);
    tuiBaseDrawer_t (WINDOW* p_pNcursWin, box_t *p_pBox);
    tuiBaseDrawer_t (uint8_t p_h, uint8_t p_w, uint8_t p_y0, uint8_t p_x0);
    tuiBaseDrawer_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus);

    //void init           (WINDOW* p_pNcursWin, point_t );
    void initWin                (void);
    void initGraphEnv           (void);
    void initGraphEnvColor      (void);
    void deinitGraphEnv         (void);
    void frame          (WINDOW* p_pNcursWin);
    void frame          (void);
    void frame          (tuiMode_t p_mode);
    void name           (tuiMode_t p_mode);
    void nameNstatus    (tuiMode_t p_mode);
    void nameNstatus    (tuiMode_t p_mode, point_t p_point0);
    bool bMouseClickInsideBounds            (void);
    int_t uiEventKeyCode                    (void);
    bool uiEventStatus                      (void);
    bool uiMouseEventStatus                 (void);
    bool uiMouseEventCode_ButtonPressed     (void);

    WINDOW* g_pNcursWin;
    uint8_t g_h;
    uint8_t g_w;
    uint8_t g_y0;
    uint8_t g_x0;
    uint8_t g_y0Win;
    uint8_t g_x0Win;

    const char* g_strName;
    // --------------------- Data section - START
    dtyUint8_t* g_pDtyStatus;
    // --------------------- Data section - END

private:

    static uint8_t g_xMouse;
    static uint8_t g_yMouse;

};

#endif 	// TUI_BASE_EVENT_HANDLER_H
