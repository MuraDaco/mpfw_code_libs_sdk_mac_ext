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
 * dtyString.cpp
 *
 *  Created on: Nov, 15h 2024 (Fri)
 *      Author: Marco Dau
 */
 
#include "dtyString.h"


dtyString_t::dtyString_t (void) :
     g_pChar    {nullptr}
    ,g_size     {0}
{}

dtyString_t::dtyString_t (char* p_pChar, size_t p_size) :
     g_pChar    {p_pChar}
    ,g_size     {p_size}
{}

uint16_t dtyString_t::getLength(void)   {
    uint16_t l_length = 0;
    if(g_pChar)
        for(uint16_t i = 0; (g_pChar[i] != 0) && (i < g_size); i++) 
            {l_length = (i < g_size) ? ++i : i;}
        
    return l_length;
}

void dtyString_t::setLength(uint16_t p_length)   {
    g_size   = p_length;
}

char* dtyString_t::getString(void)   {
    return g_pChar;
}

void dtyString_t::setString(char* p_pChar)   {
    g_pChar = p_pChar;
}
