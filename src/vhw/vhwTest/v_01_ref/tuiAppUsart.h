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
 * tuiAppUsart.h
 *
 *  Created on: Sep, 8th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_APP_USART_H
#define TUI_APP_USART_H

#include "tuiBaseEbox.h"
#include "tuiTextUsartX.h"
#include "tuiBaseButton.h"
#include "tuiBaseSubWin.h"

class tuiAppUsart_t: public tuiBaseSubWin_t {

public:
    tuiAppUsart_t   (box_t* p_pBox);


private:

    static uint8_t initBufferIn1[];
    static uint8_t initBufferIn2[];
    static uint8_t initBufferIn3[];
    static dtyBuffer_t initUsartTextCntnr[];
    uint8_t usartTextBuffer[1000000]; 
    dtyStufX_t       usartTextCntr;  //(usartTextBuffer, sizeof(usartTextBuffer), initUsartTextCntnr, sizeof(initUsartTextCntnr));
    tuiTextUsartX_t  g_text;

    char usartBuffer[1000]; //"Gennaro Pasquale Natale Nando Nunzio Nicandro Nicodemo Nabi alias Nabuccodonosor";
    dtyBaseArray_t      usartString;        //(usartBuffer, sizeof(usartBuffer));
    tuiBaseEbox_t       g_ebox;
    tuiBaseButton_t     g_button;
    element_t           g_eList[4];

    static void buttonFunction  (void);

};



#endif 	// TUI_APP_USART_H
