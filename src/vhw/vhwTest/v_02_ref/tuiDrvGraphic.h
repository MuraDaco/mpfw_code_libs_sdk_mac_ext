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
 
#ifndef TUI_DRV_GRAPHIC_H
#define TUI_DRV_GRAPHIC_H

#include <ncurses.h>

#include "tuiGraphicTypes.h"
#include "uyTypesDefs.h"
#include "tuiBaseDrawerColor.h"

#include "tuiGraphicAbstract.h"


#define TUI_KEY_CTRL_Q              0x0011
#define TUI_KEY_CTRL_X              0x0018
#define TUI_KEY_BACKSPACE           0x007f
#define TUI_KEY_DEL                 0x014a
#define TUI_KEY_TAB                 0x0009
#define TUI_KEY_SHIFT_TAB           0x0161
#define TUI_KEY_RETURN              0x000A
#define TUI_KEY_ESC                 0x001b

#define TUI_MOUSE_ROLL_UP           0x08000000
#define TUI_MOUSE_ROLL_DOWN         0x00080000

#define NCURS_MOUSE_TRACKING_ENABLE     // printf("\033[?1003h");            // Makes the terminal report mouse movement events           
#define NCURS_MOUSE_TRACKING_DISABLE    // printf("\033[?1003l");            // Disable mouse movement events, as l = low

#define tuiBaseDrawer__mvprintw(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__mvwprintw_string(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__mvwprintw_keyCode(y, x, strFrmt, strName)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, strFrmt, strName);     wrefresh(g_pNcursWin)

#define tuiBaseDrawer__name(y, x)       \
        mvwprintw(g_pNcursWin, g_y0r + y, g_x0r + x, " *~ %s ~* ", tuiBaseDrawer_t::g_strName);     wrefresh(g_pNcursWin)


class  tuiDrvGraphic_t : public tuiGraphicAbstract_t {

public:

    // ************************************************************************
    // CONSTRUCTOR function section - START

    protected:
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit     );
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit     ,box_t p_box    );
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit                     ,margins_t p_margin );
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit     ,box_t p_box    ,margins_t p_margin );

    // CONSTRUCTOR function section - START
    // ************************************************************************

    // ************************************************************************
    // DEBUG section - START

    public:
    void    dbgSetChildrenNumber    (uint8_t p_childrenNumber);

    uint8_t g_childrenNumber;
    // DEBUG section - END
    // ************************************************************************

    // ************************************************************************
    // GENERAL section - START

    public:
    void    setNcursesWindow    (tuiDrvGraphic_t* p_pParent);

    private:
    WINDOW* g_pNcursWin;

    // GENERAL section - END
    // ************************************************************************

    // ************************************************************************
    // INIT function section - START
    protected:

    void initWin                            (void)                                                                                          override;
    void initWin                            (uint16_t p_rootX0a, uint16_t p_rootY0a)                                                        override;
    void initGraphEnv                       (void)                                                                                          override;
    void initDimsNbounds                    (void)                                                                                          ;
    void initGraphEnvColor                  (void)                                                                                          override;
    void deinitGraphEnv                     (void)                                                                                          override;
    void endGraphEnv                        (void)                                                                                          override;
    // INIT function section - END
    // ************************************************************************

    // ************************************************************************
    // OUTPUT function section - START

    public:

    void content                            (char* p_str, uint8_t p_size)                                                                   override;
    void content                            (uint8_t p_begin)                                                                               override;
    void content                            (char* p_str, uint8_t p_begin, uint8_t p_size)                                                  override;

    void frameBox                           (const char* g_strName)                                                                         override;
    bool frameBox                           (tuiMode_t p_mode, const char* g_strName)                                                       override;
    void frameClear                         (void)                                                                                          override;
    void frameNname                         (const char* g_strName)                                                                         override;
    bool frameNname                         (tuiMode_t p_mode, const char* g_strName)                                                       override;
    void frameNameNstatus                   (const char* g_strName, char* p_str)                                                            override;
    bool frameNameNstatus                   (tuiMode_t p_mode, const char* g_strName, char* p_str)                                          override;
    void frameNnameTest                     (const char* g_strName)                                                                         override;
    bool frameNnameTest                     (tuiMode_t p_mode, const char* g_strName)                                                       override;
    void nameNstatus                        (const char* p_strName, uint8_t p_status)                                                       override;
    bool nameNstatus                        (tuiMode_t p_mode, const char* p_strName, uint8_t p_status)                                     override;
    bool nameNstatus                        (tuiMode_t p_mode, const char* p_strName, uint8_t p_status, bool p_repaint)                     override;
    void nameOnly                           (const char* g_strName)                                                                         override;
    void nameOnly                           (tuiMode_t p_mode, const char* g_strName)                                                       override;

    void rowPrint                           (uint8_t b_row, bool p_bRowBegin, uint8_t p_rowMarker, char* p_pRowStr, uint8_t p_rowLength)    override;
    void rowPrintX                          (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize)                          override;
    void statusPrintX                       (void)                                                                                          override;
    void statusPrintX                       (char* p_pStr, uint32_t p_strSize)                                                              override;
    void positionCursor                     (bool p_status, uint8_t p_position)                                                             override;

    bool isSelected                         (void) override;
    bool isSelectedOrEventOn                (void) override;

    private:

    typedef void (* attributeFunc_t)    (tuiDrvGraphic_t*, uint8_t);
    static attributeFunc_t  g_attributeMode_Frame[static_cast<uint8_t>(tuiMode_t::num)];
    static void attributeMode_frameDeselect     (tuiDrvGraphic_t* p_this, uint8_t p_status);
    static void attributeMode_frameSelect       (tuiDrvGraphic_t* p_this, uint8_t p_status);
    static void attributeMode_frameEventOn      (tuiDrvGraphic_t* p_this, uint8_t p_status);
    static attributeFunc_t  g_attributeMode_Line[static_cast<uint8_t>(tuiMode_t::num)];
    static void attributeMode_lineDeselect      (tuiDrvGraphic_t* p_this, uint8_t p_status);
    static void attributeMode_lineSelect        (tuiDrvGraphic_t* p_this, uint8_t p_status);
    static void attributeMode_lineEventOn       (tuiDrvGraphic_t* p_this, uint8_t p_status);

    // OUTPUT function section - END
    // ************************************************************************

    // ************************************************************************
    // INPUT function section - START

    protected:

    bool uiEventStatus                      (void) override;
    int uiEventKeyCode                      (void) override;
    tuiEventCode_t  uiHandlerEventCode      (void) override;
    bool uiMouseEventStatus                 (void) override;
    bool uiMouseEventCode_ButtonPressed     (void) override;

    private:

    static int g_ncursEventCode;
    static MEVENT g_mouseEvent;

    // INPUT function section - END
    // ************************************************************************


};


#endif  // TUI_DRV_GRAPHIC_H
