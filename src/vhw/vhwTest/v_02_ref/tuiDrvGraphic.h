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
#include "tuiDrvGraphicColor.h"

#include "tuiGraphicAbstract.h"


class  tuiDrvGraphic_t : public tuiGraphicAbstract_t {

public:


// ****************************************************
// section start **** DEFINES *****
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
    // section end   **** DEFINES *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONSTRUCTOR *****

    protected:
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit     );
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit     ,box_t p_box    );
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit                     ,margins_t p_margin );
    tuiDrvGraphic_t (tuiUnitAbstract_t* p_pUnit     ,box_t p_box    ,margins_t p_margin );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INIT *****
    public:
    void    setNcursesWindow    (tuiDrvGraphic_t* p_pParent);

    protected:
    void initWin                            (void)                                                                                          override;
    void initWin                            (uint16_t p_rootX0a, uint16_t p_rootY0a)                                                        override;
    void initWinRootDims                    (void);
    void initGraphEnv                       (void)                                                                                          override;
    void initGraphEnvColor                  (void)                                                                                          override;
    void deinitGraphEnv                     (void)                                                                                          override;
    void endGraphEnv                        (void)                                                                                          override;

    private:
    WINDOW* g_pNcursWin;

    // section end   **** INIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY STATUS *****
    public:
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

    // section end   **** DISPLAY STATUS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** OUTPUT/DISPLAY functions *****

    public:

    void refreshWin                         (void)                                                                                          override;
    void frameClear                         (void)                                                                                          override;

    void frameNnameTest                     (const char* g_strName)                                                                         override;
    bool frameNnameTest                     (tuiMode_t p_mode, const char* g_strName)                                                       override;

    void nameNstatus                        (const char* p_strName, uint8_t p_status)                                                       override;
    bool nameNstatus                        (tuiMode_t p_mode, const char* p_strName, uint8_t p_status)                                     override;
    bool nameNstatus                        (tuiMode_t p_mode, const char* p_strName, uint8_t p_status, bool p_repaint)                     override;

    void content                            (uint8_t p_begin)                                                                               override;
    void content                            (char* p_str, uint8_t p_size)                                                                   override;
    bool content                            (tuiMode_t p_mode, char* p_str, uint8_t p_size)                                                 override;
    void content                            (char* p_str, uint8_t p_begin, uint8_t p_size)                                                  override;

    void positionCursor                     (bool p_status, uint8_t p_position)                                                             override;

    void stringPrint                        (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize)                          override;
    bool stringPrint                        (tuiMode_t p_mode, uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize)        override;
    void stringPrint2                       (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize)                          override;
    bool stringPrint2                       (tuiMode_t p_mode, uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize)        override;

    // section end   **** OUTPUT/DISPLAY functions *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG OUTPUT/DISPLAY functions *****
    public:
    void debugPrint                         (uint32_t p_dbgParam1, uint32_t p_dbgParam2, char* p_pStr)                                      override;
    void dbgPrint                           (char* p_str) override;
    void dbgPrint                           (uint16_t p_x, uint16_t p_y, char* p_str) override;
    // section end   **** DEBUG OUTPUT/DISPLAY functions *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INPUT/(KEYBOARD-MOUSE) functions *****

    protected:

    bool    uiEventStatus                       (void) override;
    int     uiEventKeyCode                      (void) override;
    tuiEventCode_t  uiHandlerEventCode          (void) override;
    bool    uiMouseEventStatus                  (void) override;
    bool    uiMouseEventCode_ButtonPressed      (void) override;

    private:

    static int g_ncursEventCode;
    static MEVENT g_mouseEvent;

    // section end   **** INPUT/(KEYBOARD-MOUSE) functions *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG *****

    public:
    void    dbgSetChildrenNumber    (uint8_t p_childrenNumber);

    uint8_t g_childrenNumber;
    // section end   **** DEBUG *****
    // ****************************************************
    // --------------------------



};


#endif  // TUI_DRV_GRAPHIC_H
