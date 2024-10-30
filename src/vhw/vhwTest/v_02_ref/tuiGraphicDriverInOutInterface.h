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
 * tuiGraphicDriverInOutInterface.h
 *
 *  Created on: Oct, 22nd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRAPHIC_DRIVER_IN_OUT_INTERFACE_H
#define TUI_GRAPHIC_DRIVER_IN_OUT_INTERFACE_H


class tuiGraphicDriverInOutInterface_t {

public:

    // INIT

    virtual void initWin                            (void) = 0;
    virtual void initWin                            (uint16_t p_rootX0a, uint16_t p_rootY0a) = 0;
    virtual void initGraphEnv                       (void) = 0;
    virtual void initGraphEnvColor                  (void) = 0;
    virtual void deinitGraphEnv                     (void) = 0;
    virtual void endGraphEnv                        (void) = 0;


    // OUTPUT

    virtual void content                            (char* p_str, uint8_t p_size) = 0;
    virtual void content                            (uint8_t p_begin) = 0;
    virtual void content                            (char* p_str, uint8_t p_begin, uint8_t p_size) = 0;

    virtual void frameBox                           (const char* g_strName) = 0;
    virtual bool frameBox                           (tuiMode_t p_mode, const char* g_strName) = 0;
    virtual void frameClear                         (void) = 0;

    virtual void frameNname                         (const char* g_strName) = 0;
    virtual bool frameNname                         (tuiMode_t p_mode, const char* g_strName) = 0;
    virtual void frameNameNstatus                   (const char* g_strName, char* p_str) = 0;
    virtual bool frameNameNstatus                   (tuiMode_t p_mode, const char* g_strName, char* p_str) = 0;
    virtual void frameNnameTest                     (const char* g_strName) = 0;
    virtual bool frameNnameTest                     (tuiMode_t p_mode, const char* g_strName) = 0;

    virtual void nameNstatus                        (const char* p_strName, uint8_t p_status) = 0;
    virtual bool nameNstatus                        (tuiMode_t p_mode, const char* p_strName, uint8_t p_status) = 0;
    virtual bool nameNstatus                        (tuiMode_t p_mode, const char* p_strName, uint8_t p_status, bool p_repaint) = 0;

    virtual void nameOnly                           (const char* g_strName) = 0;
    virtual void nameOnly                           (tuiMode_t p_mode, const char* g_strName) = 0;

    virtual void positionCursor                     (bool p_status, uint8_t p_position) = 0;
    virtual void rowPrint                           (uint8_t b_row, bool p_bRowBegin, uint8_t p_rowMarker, char* p_pRowStr, uint8_t p_rowLength) = 0;
    virtual void rowPrintX                          (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) = 0;
    virtual void statusPrintX                       (void) = 0;
    virtual void statusPrintX                       (char* p_pStr, uint32_t p_strSize) = 0;

    virtual bool isSelected                         (void) = 0;
    virtual bool isSelectedOrEventOn                (void) = 0;

    // INPUT
    virtual bool uiEventStatus                      (void) = 0;
    virtual int uiEventKeyCode                      (void) = 0;
    virtual tuiEventCode_t  uiHandlerEventCode      (void) = 0;
    virtual bool uiMouseEventStatus                 (void) = 0;
    virtual bool uiMouseEventCode_ButtonPressed     (void) = 0;

};

#endif 	// TUI_GRAPHIC_DRIVER_IN_OUT_INTERFACE_H
