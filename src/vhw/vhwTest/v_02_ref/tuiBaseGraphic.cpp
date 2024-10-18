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
 * tuiBaseGraphic.cpp
 *
 *  Created on: Oct, 8th 2024
 *      Author: Marco Dau
 */

#include "tuiBaseGraphic.h"

uint8_t tuiBaseGraphic_t::g_xMouse;
uint8_t tuiBaseGraphic_t::g_yMouse;
uint8_t tuiBaseGraphic_t::g_position;

#define OFF     0
#define ON      1

#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b


// *************

// element init procedure
void tuiBaseGraphic_t::init       (void* p_pParent) 	{
    g_pParent = static_cast<tuiBaseGraphic_t*>(p_pParent);

    updParams();

    if(0 == g_w) updDimW();
    if(0 == g_h) updDimH();
}


void tuiBaseGraphic_t::updCoordNboundX   (void)     {
    updAbsCoordX();
    updBoundX();
}

void tuiBaseGraphic_t::updCoordNboundY   (void)     {
    updAbsCoordY();
    updBoundY();
}

void tuiBaseGraphic_t::updCoordNboundS   (void)     {
    updAbsCoords();
    updBounds();
}


void tuiBaseGraphic_t::updParams   (void)     {
    updAbsCoords();
    updDspBoxDims();
    updBounds();
}

// element parameters
//  - coords

//      - relative

void tuiBaseGraphic_t::setRelCoordX                 (int32_t p_x)       {
    g_x0r = p_x;
    updCoordNboundX();
}

void tuiBaseGraphic_t::incRelCoordX                 (int32_t p_delta)       {
    g_x0r += p_delta;
    updCoordNboundX();
}

void tuiBaseGraphic_t::setRelCoordY                 (int32_t p_y)       {
    g_y0r = p_y;
    updCoordNboundY();
}

void tuiBaseGraphic_t::incRelCoordY                 (int32_t p_delta)       {
    g_y0r += p_delta;
    updCoordNboundY();
}

void tuiBaseGraphic_t::setRelCoords                 (int32_t p_x, int32_t p_y)      {
    g_x0r = p_x; 
    g_y0r = p_y;
    updCoordNboundS();
}

//  - dimensions

void tuiBaseGraphic_t::setDimW        (uint8_t p_w)     {
    g_w = p_w;
}

void tuiBaseGraphic_t::updDimW        (void)        {
    g_w = g_pParent->getDspBoxDimXw();
}

void tuiBaseGraphic_t::setDimH        (uint8_t p_h)     {
    g_h = p_h;
}

void tuiBaseGraphic_t::updDimH        (void)        {
    g_h = g_pParent->getDspBoxDimYh();
}

void tuiBaseGraphic_t::setDims        (uint8_t p_w, uint8_t p_h)        {
    g_w = p_w;
    g_h = p_h;
}

void tuiBaseGraphic_t::updDims        (void)        {
    g_w = g_pParent->getDspBoxDimXw();
    g_h = g_pParent->getDspBoxDimYh();
}


// - parent parameters

//  - coords

//      - horizontal coords

int32_t tuiBaseGraphic_t::getDspBoxAbsRefX      (void)      {
    return g_x0a + g_marginXleft;
}

int32_t tuiBaseGraphic_t::getMouseAbsRefX       (void)      {
    return g_mouseX0a + g_marginXleft;
}

void tuiBaseGraphic_t::updAbsCoordX                 (void)      {
    g_x0a          = g_pParent->getDspBoxAbsRefX() + g_x0r;
    g_mouseX0a     = g_pParent->getMouseAbsRefX()  + g_x0r;
}

//      - vertical coords

int32_t tuiBaseGraphic_t::getDspBoxAbsRefY      (void)      {
    return g_x0a + g_marginYtop;
}

int32_t tuiBaseGraphic_t::getMouseAbsRefY       (void)      {
    return g_mouseY0a + g_marginYtop;
}

void tuiBaseGraphic_t::updAbsCoordY                 (void)      {
    g_y0a          = g_pParent->getDspBoxAbsRefY() + g_y0r;
    g_mouseY0a     = g_pParent->getMouseAbsRefY()  + g_y0r;
}


//      - all coords

void tuiBaseGraphic_t::updAbsCoords                 (void)      {
    g_x0a          = g_pParent->getDspBoxAbsRefX() + g_x0r;
    g_y0a          = g_pParent->getDspBoxAbsRefY() + g_y0r;
    
    g_mouseX0a     = g_pParent->getMouseAbsRefX()  + g_x0r;
    g_mouseY0a     = g_pParent->getMouseAbsRefY()  + g_y0r;
}


//  - dimensions

uint16_t tuiBaseGraphic_t::getDspBoxDimXw      (void)  {
    return g_w - (g_marginXleft + g_marginXright);
}

uint16_t tuiBaseGraphic_t::getDspBoxDimYh      (void)  {
    return g_h - (g_marginYtop + g_marginYbottom);
}

void tuiBaseGraphic_t::updDspBoxDims       (void)   {
    g_dspBoxW = g_pParent->getDspBoxDimXw();
    g_dspBoxH = g_pParent->getDspBoxDimYh();
}


//  - bounds

//      - horizontal coords

int16_t tuiBaseGraphic_t::getBoundXleft             (void)      {
    return (g_boundXleft  == g_x0a)                  ? g_boundXleft + 1 : g_boundXleft;
}

int16_t tuiBaseGraphic_t::getBoundXright            (void)      {
    return ((g_boundXright + 1)  == (g_x0a + g_w))   ? g_boundXright - 1 : g_boundXright;
}

void tuiBaseGraphic_t::updBoundX                    (void)      {
    g_boundXleft  = MAX(g_pParent->getBoundXleft(),  g_x0a           );
    g_boundXright = MIN(g_pParent->getBoundXright(), g_x0a + g_w - 1 );
}

//      - vertical coords

int16_t tuiBaseGraphic_t::getBoundYupper            (void)      {
    return (g_boundYupper == g_y0a)                  ? g_boundYupper + 1 : g_boundYupper;
}

int16_t tuiBaseGraphic_t::getBoundYlower            (void)      {
    return ((g_boundYlower + 1)  == (g_y0a + g_h))   ? g_boundYlower - 1 : g_boundYlower;
}

void tuiBaseGraphic_t::updBoundY                    (void)      {
    g_boundYupper = MAX(g_pParent->getBoundYupper(), g_y0a           );
    g_boundYlower = MIN(g_pParent->getBoundYlower(), g_y0a + g_h - 1 );
}

//      - all coords

void tuiBaseGraphic_t::updBounds                    (void)        {
    g_boundXleft  = MAX(g_pParent->getBoundXleft(),  g_x0a           );
    g_boundXright = MIN(g_pParent->getBoundXright(), g_x0a + g_w - 1 );

    g_boundYupper = MAX(g_pParent->getBoundYupper(), g_y0a           );
    g_boundYlower = MIN(g_pParent->getBoundYlower(), g_y0a + g_h - 1 );
}

// old

void tuiBaseGraphic_t::updateRelativeX   (uint8_t p_x0r) {
    g_x0Win = (g_x0Win  - g_x0r) + p_x0r + 1;   // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_x0a   = (g_x0a    - g_x0r) + p_x0r + 1;   // N.B.: (g_x0a - g_x0r) = p_poFather->g_x0a
    g_x0r   = p_x0r + 1;
}

void tuiBaseGraphic_t::updateRelativeY   (uint8_t p_y0r) {
    g_y0Win = (g_y0Win - g_y0r) + p_y0r + 1;    // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_y0a   = (g_y0a   - g_y0r) + p_y0r + 1;    // N.B.: (g_y0a   - g_y0r) = p_poFather->g_x0a
    g_y0r   = p_y0r + 1;
}


int16_t tuiBaseGraphic_t::getRefX0            (void)  {
    return g_lvl1X0a + g_marginXleft;
}

int16_t tuiBaseGraphic_t::getRootRefX0            (void)  {
    return g_x0a + g_marginXleft;
}

int16_t tuiBaseGraphic_t::getDisplayMaxW      (void)  {
    return g_w - (g_marginXleft + g_marginXright);
}

int16_t tuiBaseGraphic_t::getRefY0            (void)  {
    return g_lvl1Y0a + g_marginYtop;
}

int16_t tuiBaseGraphic_t::getRootRefY0            (void)  {
    return g_y0a + g_marginYtop;
}

int16_t tuiBaseGraphic_t::getDisplayMaxH      (void)  {
    return g_h - (g_marginYtop + g_marginYbottom);
}




bool tuiBaseGraphic_t::bMouseClickInsideBounds (void)      {
    bool l_result = false;

    if(
        ((g_x0a <= g_xMouse) && (g_xMouse < (g_x0a + g_w ))) &&
        ((g_y0a <= g_yMouse) && (g_yMouse < (g_y0a + g_h )))
    ) {
        l_result = true;

    }
    return l_result;
}


bool tuiBaseGraphic_t::isSelectedOrEventOn             (void)  {
    return (
            (tuiMode_t::select == g_mode) ||
            (tuiMode_t::eventOn == g_mode)
    );
}

bool tuiBaseGraphic_t::isSelected             (void)  {
    return (tuiMode_t::select == g_mode);
}

