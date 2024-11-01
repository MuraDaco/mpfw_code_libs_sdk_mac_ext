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
 * tuiGraphicCoord.cpp
 *
 *  Created on: Oct, 18th 2024
 *      Author: Marco Dau
 */

#include "tuiGraphicCoord.h"

uint16_t tuiGraphicCoord_t::g_xMouse;
uint16_t tuiGraphicCoord_t::g_yMouse;
uint16_t tuiGraphicCoord_t::g_xCursor;
uint16_t tuiGraphicCoord_t::g_yCursor;
uint16_t tuiGraphicCoord_t::g_position;

#define OFF     0
#define ON      1

#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b



// **** OLD SECTION - START *************
#define G_PO_FATHER static_cast<tuiGraphicCoord_t*>(g_pParent)
#define P_PO_FATHER static_cast<tuiGraphicCoord_t*>(p_pParent)


tuiGraphicCoord_t::tuiGraphicCoord_t    (void)      :
     g_x0r              {0}
    ,g_y0r              {0}
    ,g_x0a              {0}
    ,g_y0a              {0}
    ,g_mouseX0a         {0}
    ,g_mouseY0a         {0}
    ,g_marginXleft      {0}
    ,g_marginXright     {0}
    ,g_marginYtop       {0}
    ,g_marginYbottom    {0}
{}


tuiGraphicCoord_t::tuiGraphicCoord_t    (box_t p_box    )      :
     g_x0r              {p_box.xStart}
    ,g_y0r              {p_box.yStart}
    ,g_x0a              {0}
    ,g_y0a              {0}
    ,g_mouseX0a         {0}
    ,g_mouseY0a         {0}
    ,g_marginXleft      {1} // default margin = 1
    ,g_marginXright     {1} // default margin = 1
    ,g_marginYtop       {1} // default margin = 1
    ,g_marginYbottom    {1} // default margin = 1
    ,g_w                {p_box.width}
    ,g_h                {p_box.height}
{}

tuiGraphicCoord_t::tuiGraphicCoord_t    (                margins_t p_margin)      :
     g_x0r              {0}
    ,g_y0r              {0}
    ,g_x0a              {0}
    ,g_y0a              {0}
    ,g_mouseX0a         {0}
    ,g_mouseY0a         {0}
    ,g_marginXleft      {p_margin.Left}
    ,g_marginXright     {p_margin.Right}
    ,g_marginYtop       {p_margin.Top}
    ,g_marginYbottom    {p_margin.Bottom}
{}

tuiGraphicCoord_t::tuiGraphicCoord_t    (box_t p_box    ,margins_t p_margin)      :
     g_x0r              {p_box.xStart}
    ,g_y0r              {p_box.yStart}
    ,g_x0a              {0}
    ,g_y0a              {0}
    ,g_mouseX0a         {0}
    ,g_mouseY0a         {0}
    ,g_marginXleft      {p_margin.Left}
    ,g_marginXright     {p_margin.Right}
    ,g_marginYtop       {p_margin.Top}
    ,g_marginYbottom    {p_margin.Bottom}
    ,g_w                {p_box.width}
    ,g_h                {p_box.height}
{}


#define G_P_PARENT  static_cast<tuiGraphicCoord_t*>(g_pParent)


// *************

// element init procedure
void tuiGraphicCoord_t::initCoord       () 	{
// - // -    updParams();

// -     updAbsCoords();
    g_x0a           = G_P_PARENT->getDspBoxAbsRefX() + g_x0r;
    g_y0a           = G_P_PARENT->getDspBoxAbsRefY() + g_y0r;
    
    g_mouseX0a      = G_P_PARENT->getMouseAbsRefX()  + g_x0r;
    g_mouseY0a      = G_P_PARENT->getMouseAbsRefY()  + g_y0r;

// -     updDspBoxDims();
    g_dspBoxW       = G_P_PARENT->getDspBoxDimXw();
    g_dspBoxH       = G_P_PARENT->getDspBoxDimYh();

// -     updBounds();
    g_boundXleft    = MAX(G_P_PARENT->getBoundXleft(),  g_x0a           );
    g_boundXright   = MIN(G_P_PARENT->getBoundXright(), g_x0a + g_w - 1 );

    g_boundYupper   = MAX(G_P_PARENT->getBoundYupper(), g_y0a           );
    g_boundYlower   = MIN(G_P_PARENT->getBoundYlower(), g_y0a + g_h - 1 );

//    if(0 == g_w) updDimW();
//    if(0 == g_h) updDimH();
}

void tuiGraphicCoord_t::setParent                       (tuiGraphicCoord_t* p_pParent) {
    g_pParent = p_pParent;
}

tuiGraphicCoord_t* tuiGraphicCoord_t::getParent         (void)  {
    return g_pParent;
}

void tuiGraphicCoord_t::updCoordNboundX   (void)     {
    updAbsCoordX();
    updBoundX();
}

void tuiGraphicCoord_t::updCoordNboundY   (void)     {
    updAbsCoordY();
    updBoundY();
}

void tuiGraphicCoord_t::updCoordNboundS   (void)     {
    updAbsCoords();
    updBounds();
}


void tuiGraphicCoord_t::updParams   (void)     {
    updAbsCoords();
    updDspBoxDims();
    updBounds();
}

// element parameters
//  - coords

//      - relative

void tuiGraphicCoord_t::initRelCoordX               (int32_t p_x)       {
    g_x0r       = p_x;
}

void tuiGraphicCoord_t::setRelCoordX                (int32_t p_x)       {
    g_x0r = p_x;
    updCoordNboundX();
}

void tuiGraphicCoord_t::incRelCoordX                (int32_t p_delta)       {
    g_x0r += p_delta;
    updCoordNboundX();
}

void tuiGraphicCoord_t::initRelCoordY               (int32_t p_y)       {
    g_y0r       = p_y;
}

void tuiGraphicCoord_t::setRelCoordY                (int32_t p_y)       {
    g_y0r = p_y;
    updCoordNboundY();
}

void tuiGraphicCoord_t::incRelCoordY                (int32_t p_delta)       {
    g_y0r += p_delta;
    updCoordNboundY();
}

void tuiGraphicCoord_t::initRelCoordS               (int32_t p_x, int32_t p_y)      {
    initRelCoordX(p_x);
    initRelCoordY(p_y);
}

void tuiGraphicCoord_t::setRelCoords                (int32_t p_x, int32_t p_y)      {
    g_x0r = p_x; 
    g_y0r = p_y;
    updCoordNboundS();
}


//  - dimensions

void tuiGraphicCoord_t::setDimW         (uint16_t p_w)     {
    g_w = p_w;
}

void tuiGraphicCoord_t::updDimW         (void)        {
    g_w = G_P_PARENT->getDspBoxDimXw();
}

uint16_t tuiGraphicCoord_t::getDimW     (void)     {
    return g_w;
}

void tuiGraphicCoord_t::setDimH         (uint16_t p_h)     {
    g_h = p_h;
}

void tuiGraphicCoord_t::updDimH         (void)        {
    g_h = G_P_PARENT->getDspBoxDimYh();
}

uint16_t tuiGraphicCoord_t::getDimH     (void)     {
    return g_h;
}

void tuiGraphicCoord_t::setDims         (uint16_t p_w, uint16_t p_h)        {
    g_w = p_w;
    g_h = p_h;
}

void tuiGraphicCoord_t::updDims         (void)        {
    g_w = G_P_PARENT->getDspBoxDimXw();
    g_h = G_P_PARENT->getDspBoxDimYh();
}


// - parent parameters

//  - coords

//      - horizontal coords

int32_t tuiGraphicCoord_t::getDspBoxAbsRefX      (void)      {
    return g_x0a + g_marginXleft;
}

int32_t tuiGraphicCoord_t::getMouseAbsRefX       (void)      {
    return g_mouseX0a + g_marginXleft;
}

void tuiGraphicCoord_t::updAbsCoordX                 (void)      {
    g_x0a          = G_P_PARENT->getDspBoxAbsRefX() + g_x0r;
    g_mouseX0a     = G_P_PARENT->getMouseAbsRefX()  + g_x0r;
}

//      - vertical coords

int32_t tuiGraphicCoord_t::getDspBoxAbsRefY      (void)      {
    return g_x0a + g_marginYtop;
}

int32_t tuiGraphicCoord_t::getMouseAbsRefY       (void)      {
    return g_mouseY0a + g_marginYtop;
}

void tuiGraphicCoord_t::updAbsCoordY                 (void)      {
    g_y0a          = G_P_PARENT->getDspBoxAbsRefY() + g_y0r;
    g_mouseY0a     = G_P_PARENT->getMouseAbsRefY()  + g_y0r;
}


//      - all coords

void tuiGraphicCoord_t::updAbsCoords                 (void)      {
    g_x0a          = G_P_PARENT->getDspBoxAbsRefX() + g_x0r;
    g_y0a          = G_P_PARENT->getDspBoxAbsRefY() + g_y0r;
    
    g_mouseX0a     = G_P_PARENT->getMouseAbsRefX()  + g_x0r;
    g_mouseY0a     = G_P_PARENT->getMouseAbsRefY()  + g_y0r;
}


//  - dimensions

uint16_t tuiGraphicCoord_t::getDspBoxDimXw      (void)  {
    return g_w - (g_marginXleft + g_marginXright);
}

uint16_t tuiGraphicCoord_t::getDspBoxDimYh      (void)  {
    return g_h - (g_marginYtop + g_marginYbottom);
}

void tuiGraphicCoord_t::updDspBoxDims       (void)   {
    g_dspBoxW = G_P_PARENT->getDspBoxDimXw();
    g_dspBoxH = G_P_PARENT->getDspBoxDimYh();
}


//  - bounds

//      - horizontal coords

int32_t tuiGraphicCoord_t::getBoundXleft             (void)      {
    return (g_boundXleft  == g_x0a)                  ? g_boundXleft + 1 : g_boundXleft;
}

int32_t tuiGraphicCoord_t::getBoundXright            (void)      {
    return ((g_boundXright + 1)  == (g_x0a + g_w))   ? g_boundXright - 1 : g_boundXright;
}

void tuiGraphicCoord_t::updBoundX                    (void)      {
    g_boundXleft  = MAX(G_P_PARENT->getBoundXleft(),  g_x0a           );
    g_boundXright = MIN(G_P_PARENT->getBoundXright(), g_x0a + g_w - 1 );
}

//      - vertical coords

int32_t tuiGraphicCoord_t::getBoundYupper            (void)      {
    return (g_boundYupper == g_y0a)                  ? g_boundYupper + 1 : g_boundYupper;
}

int32_t tuiGraphicCoord_t::getBoundYlower            (void)      {
    return ((g_boundYlower + 1)  == (g_y0a + g_h))   ? g_boundYlower - 1 : g_boundYlower;
}

void tuiGraphicCoord_t::updBoundY                    (void)      {
    g_boundYupper = MAX(G_P_PARENT->getBoundYupper(), g_y0a           );
    g_boundYlower = MIN(G_P_PARENT->getBoundYlower(), g_y0a + g_h - 1 );
}

//      - all coords

void tuiGraphicCoord_t::updBounds                    (void)        {
    g_boundXleft  = MAX(G_P_PARENT->getBoundXleft(),  g_x0a           );
    g_boundXright = MIN(G_P_PARENT->getBoundXright(), g_x0a + g_w - 1 );

    g_boundYupper = MAX(G_P_PARENT->getBoundYupper(), g_y0a           );
    g_boundYlower = MIN(G_P_PARENT->getBoundYlower(), g_y0a + g_h - 1 );
}


void tuiGraphicCoord_t::updCoordNboundsChilds    (void)       {
    // g_cntr->updCoordNboundsChilds();
}

bool tuiGraphicCoord_t::bMouseClickInsideBounds (void)      {
    bool l_result = false;

    if(g_boundYupper <= g_boundYlower)    {
        uint16_t l_boundUpper = g_boundYupper + (g_mouseY0a - g_y0a);
        uint16_t l_boundLower = g_boundYlower + (g_mouseY0a - g_y0a);
        if(
                ( (g_mouseX0a   <= g_xMouse) && (g_xMouse <   (g_mouseX0a + g_w )) )
            &&  ( (l_boundUpper <= g_yMouse) && (g_yMouse <=  l_boundLower)  )
        ) {
            l_result = true;
        }
    }
    return l_result;
}
