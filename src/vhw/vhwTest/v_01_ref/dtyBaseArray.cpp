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
 * dtyBaseArray.cpp
 *
 *  Created on: Sep, 1st 2024
 *      Author: Marco Dau
 */
 

#include "dtyBaseArray.h"


dtyBaseArray_t::dtyBaseArray_t		(char* p_pAry, uint16_t p_sizeAry)	:
     g_pAry                 {p_pAry}
    ,g_sizeAry              {p_sizeAry}
    ,g_position             {0}
    ,g_idDsplyBoxBegin           {0}
    ,g_idDsplyBoxWidth            {0}
    ,g_idDsplyPositionCursor    {0}
    ,g_idDsplyLength     {0}

{
    // determine the length
    uint16_t l_pos = 0;
    while(*p_pAry)  {
        l_pos++;
        p_pAry++;
    }
    g_length = l_pos;
}

bool	dtyBaseArray_t::ins		                (char p_char)   {
    shiftAhead();
    g_pAry[g_position] = p_char;
    bool l_result = positionInc();

    // display section
    dsplyCurrentUpd(g_position);

    return l_result;
}

void	dtyBaseArray_t::del		                (void)      {
    shiftBack();

    // display section
    dsplyCurrentUpd(g_position);
}

bool	dtyBaseArray_t::backSpace               (void)      {
    bool l_result = false;
    if(g_position)  {
        l_result = positionDec();
        shiftBack();

        // display section
        dsplyCurrentUpd(g_position);
    }

    return l_result;
}

void    dtyBaseArray_t::shiftAhead              (void)      {
    if(g_length < g_sizeAry)    {

        for(int16_t i=g_length-1; i>=g_position; i--)  {
            g_pAry[i+1] = g_pAry[i];
        }
        g_length++;
        g_pAry[g_length] = 0;

    }
}

void    dtyBaseArray_t::shiftBack               (void)      {
    if(g_position < g_length)   {
        for(uint16_t i=g_position; i<g_length-1; i++)  {
            g_pAry[i] = g_pAry[i+1];
        }
        g_length--;
        g_pAry[g_length] = 0;
    }
}

void    dtyBaseArray_t::positionBegin           (void)      {
    if(g_position > 0)  {
        g_position = 0;

        // display section
        dsplyBeginSet(0);
        dsplyCurrentUpd(g_position);
    }
}

void    dtyBaseArray_t::positionEnd             (void)      {
    if(g_position != g_length)  {
        g_position = g_length;

        // display section
        dsplyBeginSet(((g_length+1) > g_idDsplyBoxWidth) ? (g_length + 1 - g_idDsplyBoxWidth) : 0);
        dsplyCurrentUpd(g_position);
    }
}

bool    dtyBaseArray_t::positionInc             (void)      {
    bool l_result = false;
    if(g_position < g_sizeAry) {
        g_position++;

        // display section
        if(g_position == (g_idDsplyBoxBegin + g_idDsplyBoxWidth))    {
            dsplyBeginInc();
            l_result = true;
        }
        dsplyCurrentUpd(g_position);
    }
    return l_result;
}

bool    dtyBaseArray_t::positionDec             (void)      {
    bool l_result = false;
    if(g_position) {
        g_position--;

        // display section
        if(g_position < g_idDsplyBoxBegin)    {
            dsplyBeginDec();
            l_result = true;
        }
        dsplyCurrentUpd(g_position);
    }
    return l_result;
}

uint16_t dtyBaseArray_t::positionGet            (void)      {
    return g_position;
}

char* dtyBaseArray_t::pArrayGet                 (void)      {
    return g_pAry;
}

uint16_t dtyBaseArray_t::lengthGet              (void)      {
    return g_length;
}

// display section

// display section: public 
void    dtyBaseArray_t::initDsplyBox            (uint8_t p_boxW)    {
    g_idDsplyBoxWidth = p_boxW;
    g_idDsplyPositionCursor = g_idDsplyBoxBegin;
    g_idDsplyLength  = (g_idDsplyBoxWidth < g_length) ? g_idDsplyBoxWidth : g_length;
}

bool    dtyBaseArray_t::dsplyPositionInc             (void)      {
    bool l_result = false;
    if(g_position < g_length) {
        g_position++;

        // display section
        if(g_position == (g_idDsplyBoxBegin + g_idDsplyBoxWidth))    {
            l_result = true;
            dsplyBeginInc();
        }
        dsplyCurrentUpd(g_position);
    }
    return l_result;
}

bool    dtyBaseArray_t::dsplyPositionDec             (void)     {
    return positionDec();
}

char* dtyBaseArray_t::pDsplyStrBeginGet         (void)      {
    return &g_pAry[g_idDsplyBoxBegin];
}

char* dtyBaseArray_t::pDsplyStrPositionGet              (void)      {
    return &g_pAry[g_idDsplyPositionCursor];
}

char* dtyBaseArray_t::pDsplyStrPositionPrevGet              (void)      {
    return &g_pAry[g_idDsplyPositionCursor-1];
}

uint8_t dtyBaseArray_t::sizeDsplyStrFromBeginGet         (void)     {
    return (g_idDsplyBoxBegin + g_idDsplyBoxWidth < g_length) ? g_idDsplyBoxWidth : (g_length - g_idDsplyBoxBegin);
}

uint8_t dtyBaseArray_t::sizeDsplyStrFromPositionGet     (void)      {
    uint8_t l_return = g_idDsplyLength;
    g_idDsplyLength = 0;
    return l_return;
}

uint8_t dtyBaseArray_t::sizeDsplyStrFromPositionPrevGet     (void)      {
    uint8_t l_return = g_idDsplyLength+1;
    g_idDsplyLength = 0;
    return l_return;
}

uint8_t dtyBaseArray_t::beginDsplyStrGet         (void)      {
    return g_idDsplyBoxBegin;
}

uint8_t dtyBaseArray_t::positionDsplyGet         (void)      {
    return g_idDsplyPositionCursor - g_idDsplyBoxBegin;
}


// display section: private
void dtyBaseArray_t::dsplyBeginSet              (uint16_t p_begin)        {
    g_idDsplyBoxBegin = p_begin;
}

void dtyBaseArray_t::dsplyBeginInc              (void)        {
    g_idDsplyBoxBegin++;
}

void dtyBaseArray_t::dsplyBeginDec              (void)        {
    g_idDsplyBoxBegin--;
}


void dtyBaseArray_t::dsplyCurrentUpd            (uint16_t p_position)      {
    g_idDsplyPositionCursor = p_position;
    if(g_idDsplyBoxBegin + g_idDsplyBoxWidth < g_length)
        g_idDsplyLength         = g_idDsplyBoxBegin + g_idDsplyBoxWidth - g_idDsplyPositionCursor;
    else
        g_idDsplyLength         = g_length - g_idDsplyPositionCursor;
}

