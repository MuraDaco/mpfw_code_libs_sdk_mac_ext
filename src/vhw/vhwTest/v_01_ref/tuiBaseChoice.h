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
 * tuiBaseChoice.h
 *
 *  Created on: Sep, 12th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_BUTTON_H
#define TUI_BASE_BUTTON_H

#include "tuiMacroDefine.h"
#include "tuiBase.h"
#include "dtyUint8.h"


class tuiBaseChoice_t : public tuiBase_t  {

public:
    tuiBaseChoice_t       (const char* p_strName  ,uint8_t p_sizeName   ,box_t p_box    ,func_t p_func);

    bool loop       	    (void)					override;
    void display            (void)                  override;
    void display            (bool p_recursively)    override;
    void select             (void)                  override;
    bool selectByMouse      (void)                  override;
    void deSelect           (void)                  override;
    void setThis            (void)                  override;
    void eventOn            (void)                  override;
    event_t* pEventArrayGet	(void)                  override;


private:

    // --------------------- Data section - START
    func_t g_func;
    // --------------------- Data section - END

};


#endif 	// TUI_BASE_BUTTON_H
