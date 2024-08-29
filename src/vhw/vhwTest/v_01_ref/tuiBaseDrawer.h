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
 * tuiBaseDrawer.h
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_DRAWER_H
#define TUI_BASE_DRAWER_H

#include <functional>
#include <cstdint>
#include "tuiGraphicTypes.h"
#include <ncurses.h>
#include "dtyUint8.h"
#include "uyTypesDefs.h"
#include "tuiBaseDrawerColor.h"


#define TUI_KEY_TAB             0x0009
#define TUI_KEY_SHIFT_TAB       0x0161
#define TUI_KEY_RETURN          0x000A
#define TUI_KEY_ESC             0x001b

#define NCURS_MOUSE_TRACKING_ENABLE     // printf("\033[?1003h");            // Makes the terminal report mouse movement events           
#define NCURS_MOUSE_TRACKING_DISABLE    // printf("\033[?1003l");            // Disable mouse movement events, as l = low

// #define NCURS_COLOR_PAIR_WINDOW_SELECT              COLOR_PAIR  (1)
// #define NCURS_COLOR_PAIR_INIT_WINDOW_SELECT         init_pair   (1, COLOR_YELLOW,  COLOR_BLUE)
// 
// #define NCURS_COLOR_PAIR_WINDOW_DESELECT            COLOR_PAIR  (2)
// #define NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT       init_pair   (2, COLOR_RED,     COLOR_BLACK)
// 
// #define NCURS_COLOR_PAIR_WINDOW_EVENT_ON            COLOR_PAIR  (3)
// #define NCURS_COLOR_PAIR_INIT_WINDOW_EVENT_ON       init_pair   (3, COLOR_RED,   COLOR_YELLOW)

#define tuiBaseDrawer__mvprintw(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__mvwprintw_string(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__mvwprintw_keyCode(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__name(y, x)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, " *~ %s ~* ", tuiBaseDrawer_t::g_strName);     wrefresh(g_pNcursWin)

class tuiBaseDrawer_t   {

public:

    typedef struct __zone__ {
        box_t box;
        func_t hndl;
    } zone_t;

    tuiBaseDrawer_t (const char* p_strName, box_t *p_pBox);
    tuiBaseDrawer_t (const char* p_strName, box_t p_box);
    tuiBaseDrawer_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus);

    void initWin                (void);
    void initGraphEnv           (void);
    void initGraphEnvColor      (void);
    void deinitGraphEnv         (void);
    void endGraphEnv            (void);

    void rowPrint(uint8_t b_row, bool p_bRowBegin, uint8_t p_rowMarker, char* p_pRowStr, uint8_t p_rowLength);

    void frame              (tuiMode_t p_mode);
    void frameNname         (void);
    void frameNameNstatus   (char* p_str);
    void frameDebug         (char* p_str);
    void frameDebug         (uint8_t p_row, char* p_str);
    void frameNname         (tuiMode_t p_mode);
    void frameNameNstatus   (tuiMode_t p_mode, char* p_str);
    void frameBox       (tuiMode_t p_mode);
    void frameBox       (void);
    void name           (tuiMode_t p_mode);
    void nameNstatus    (void);
    void nameNstatus    (tuiMode_t p_mode);
    bool bMouseClickInsideBounds            (void);

    bool uiEventStatus                      (void);
    int uiEventKeyCode                      (void);
    tuiEventCode_t  uiHandlerEventCode      (void);
    bool uiMouseEventStatus                 (void);
    bool uiMouseEventCode_ButtonPressed     (void);
    bool isSelected                         (void);
    bool isSelectedOrEventOn                (void);

    WINDOW* g_pNcursWin;
    uint8_t g_h;
    uint8_t g_w;
    uint8_t g_y0r;
    uint8_t g_x0r;
    uint8_t g_y0a;
    uint8_t g_x0a;
    uint8_t g_y0Win;
    uint8_t g_x0Win;
    tuiMode_t g_status;

    const char* g_strName;
    // --------------------- Data section - START
    dtyUint8_t* g_pDtyStatus;
    // --------------------- Data section - END

    void updateRelativeX    (uint8_t p_x0r);
    void updateRelativeY    (uint8_t p_y0r);

private:


    //bool g_visible;
    static uint8_t g_xMouse;
    static uint8_t g_yMouse;

    static int g_ncursEventCode;
    static MEVENT g_mouseEvent;

    typedef void (* attributeFunc_t)    (tuiBaseDrawer_t*, uint8_t);
    std::function<void(int)>  g_attributeModeX[2];
    static attributeFunc_t  g_attributeMode_Frame[static_cast<uint8_t>(tuiMode_t::num)];
    static void attributeMode_frameDeselect     (tuiBaseDrawer_t* p_this, uint8_t p_status);
    static void attributeMode_frameSelect       (tuiBaseDrawer_t* p_this, uint8_t p_status);
    static void attributeMode_frameEventOn      (tuiBaseDrawer_t* p_this, uint8_t p_status);
    static attributeFunc_t  g_attributeMode_Line[static_cast<uint8_t>(tuiMode_t::num)];
    static void attributeMode_lineDeselect      (tuiBaseDrawer_t* p_this, uint8_t p_status);
    static void attributeMode_lineSelect        (tuiBaseDrawer_t* p_this, uint8_t p_status);
    static void attributeMode_lineEventOn       (tuiBaseDrawer_t* p_this, uint8_t p_status);
};

#endif 	// TUI_DRAWER_BASE_H
