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
 * tuiBaseWinRoot.h
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_BASE_WIN_ROOT_H
#define TUI_BASE_WIN_ROOT_H

#include "tuiBaseWin.h"

class tuiBaseWinRoot_t : public tuiBaseWin_t  {

public:

    tuiBaseWinRoot_t        (const char* p_strName, box_t* p_box, element_t* p_elementList);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"
    void init                   (void)      override;
#pragma clang diagnostic pop

    bool loop       	        (void)      override;
    void end          	        (void)      override;
    void deSelect               (void)      override;



};


#endif 	// TUI_BASE_WIN_ROOT_H
