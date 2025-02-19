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
 * tuiBase.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */
 

#include "tuiBase.h"


#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b

#define G_PO_FATHER static_cast<tuiBase_t*>(g_poFather)
#define P_PO_FATHER static_cast<tuiBase_t*>(p_poFather)


tuiBase_t::tuiBase_t (void)    :
    tuiBaseDrawer_t()
{}

tuiBase_t::tuiBase_t (const char* p_strName, box_t *p_pBox) :
    tuiBaseDrawer_t(p_strName, p_pBox)
{}

tuiBase_t::tuiBase_t (const char* p_strName, box_t p_box) :
    tuiBaseDrawer_t(p_strName, p_box)
{}

tuiBase_t::tuiBase_t (const char* p_strName, box_t *p_pBox,    margins_t p_margins ) :
    tuiBaseDrawer_t(p_strName, p_pBox, p_margins)
{}

tuiBase_t::tuiBase_t (const char* p_strName, box_t p_box,      margins_t p_margins ) :
    tuiBaseDrawer_t(p_strName, p_box,  p_margins)
{}


tuiBase_t::tuiBase_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus) :
    tuiBaseDrawer_t(p_strName, p_box, p_pDtyStatus)
{}


void tuiBase_t::init       (void* p_poFather) 	{
    g_poFather      = P_PO_FATHER;
    g_pNcursWin     = P_PO_FATHER->g_pNcursWin;
    g_x0Win         = P_PO_FATHER->getRefX0() + g_x0r;
    g_y0Win         = P_PO_FATHER->getRefY0() + g_y0r;
    g_x0a           = P_PO_FATHER->getRootRefX0() + g_lvl1X0r;    // g_x0r;
    g_y0a           = P_PO_FATHER->getRootRefY0() + g_lvl1Y0r;    // g_y0r;
    g_x0Win         = P_PO_FATHER->getRefX0() + g_lvl1X0r;
    g_y0Win         = P_PO_FATHER->getRefY0() + g_lvl1Y0r;
    //g_x0a           = P_PO_FATHER->getRefX0() + g_lvl1X0r;
    //g_y0a           = P_PO_FATHER->getRefY0() + g_lvl1Y0r;
    if(!g_w) g_w    = P_PO_FATHER->g_w - 2;

    g_lvl1X0a       = P_PO_FATHER->getRefX0() + g_lvl1X0r;
    g_displayBoxW   = P_PO_FATHER->getDisplayMaxW();
    g_lvl1Y0a       = P_PO_FATHER->getRefY0() + g_lvl1Y0r;
    g_displayBoxH   = P_PO_FATHER->getDisplayMaxH();
    

    // init bounds
    g_boundUpper = MAX(G_PO_FATHER->getBoundYupper(), g_lvl1Y0a);
    g_boundLower = MIN(G_PO_FATHER->getBoundYlower(), g_lvl1Y0a + g_h - 1);

}

void tuiBase_t::setParent       (void* p_poFather) 	{
    g_poFather      = P_PO_FATHER;
    g_pNcursWin     = P_PO_FATHER->g_pNcursWin;
}

void tuiBase_t::updateRelativeX   (uint8_t p_x0r) {
    g_x0Win = (g_x0Win  - g_x0r) + p_x0r + 0;   // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_x0a   = (g_x0a    - g_x0r) + p_x0r + 0;   // N.B.: (g_x0a - g_x0r) = p_poFather->g_x0a
    g_x0r   = p_x0r + 0;
}

void tuiBase_t::updateRelativeY   (uint8_t p_y0r) {
//    g_y0Win = (g_y0Win - g_y0r) + p_y0r + 0;    // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
//    g_y0a   = (g_y0a   - g_y0r) + p_y0r + 0;    // N.B.: (g_y0a   - g_y0r) = p_poFather->g_x0a
    g_y0r       = p_y0r;
    g_lvl1Y0r   = p_y0r;
    updCoordNboundY();
}



void tuiBase_t::updParams              (void)       {

    updCoordNboundS();
    updDspBoxDimS();
}

void tuiBase_t::updCoordNboundX        (void)       {
    g_x0Win     = G_PO_FATHER->getRefX0()       + g_lvl1X0r;
    g_x0a       = G_PO_FATHER->getRootRefX0()   + g_lvl1X0r;
    g_lvl1X0a   = G_PO_FATHER->getRefX0()       + g_lvl1X0r;

    if(!g_w) g_w    = G_PO_FATHER->g_w - 2;

}

void tuiBase_t::updCoordNboundY        (void)       {
    g_y0Win     = G_PO_FATHER->getRefY0()       + g_lvl1Y0r;
    g_y0a       = G_PO_FATHER->getRootRefY0()   + g_lvl1Y0r;
    g_lvl1Y0a   = G_PO_FATHER->getRefY0()       + g_lvl1Y0r;


    g_boundUpper = MAX(G_PO_FATHER->getBoundYupper(), g_lvl1Y0a);
    g_boundLower = MIN(G_PO_FATHER->getBoundYlower(), g_lvl1Y0a + g_h - 1);
}

/*

//  parent bounds  ------U------------------L-------------------------------------
//  element box    ---------u-----------l-----------------------------------------
//  element bounds ---------u-----------l-----------------------------------------

//  parent bounds  ---------------U---------L-------------------------------------
//  element box    ---------u-----------l-----------------------------------------
//  element bounds ---------------U-----l----------------------------------------- 

//  parent bounds  ------U--------L-----------------------------------------------
//  element box    ---------u-----------l-----------------------------------------
//  element bounds ---------u-----L----------------------------------------------- 

//  parent bounds  ---------------------------U--------L--------------------------
//  element box    ---------u-----------l-----------------------------------------
//  element bounds ---------------------l-----U----------------------------------- 

N.B.: the bounds definitions imply that
    if
        (g_boundUpper <= g_boundLower)
    then
            (              (g_boundUpper+1) <= (g_lvl1Y0a + g_h)  )
        ||  (g_lvl1Y0a <=   g_boundLower                          )
        
 */


void tuiBase_t::updCoordNboundS        (void)       {
    updCoordNboundX();
    updCoordNboundY();
}

void tuiBase_t::updDspBoxDimX                (void)       {
    g_displayBoxW   = G_PO_FATHER->getDisplayMaxW();
}

void tuiBase_t::updDspBoxDimY                (void)       {
    g_displayBoxH   = G_PO_FATHER->getDisplayMaxH();
}

void tuiBase_t::updDspBoxDimS                (void)       {
    updDspBoxDimX();
    updDspBoxDimY();
}


void tuiBase_t::setRelCoordX           (int16_t p_x)        {
    g_x0r       = p_x;
    g_lvl1X0r   = p_x;
    updCoordNboundX();
}

void tuiBase_t::incRelCoordX           (int16_t p_deltaX)        {
    g_x0r       += p_deltaX;
    g_lvl1X0r    = g_x0r;
    updCoordNboundX();
}

void tuiBase_t::setRelCoordY           (int16_t p_y)        {
    g_y0r       = p_y;
    g_lvl1Y0r   = p_y;
    updCoordNboundY();
}

void tuiBase_t::incRelCoordY           (int16_t p_deltaY)        {
    g_y0r       += p_deltaY;
    g_lvl1Y0r    = g_y0r;
    updCoordNboundY();
}

void tuiBase_t::initRelCoordX      (int16_t p_x)        {
    g_x0r       = p_x;
    g_lvl1X0r   = p_x;
}

void tuiBase_t::initRelCoordY      (int16_t p_y)        {
    g_y0r       = p_y;
    g_lvl1Y0r   = p_y;
}

void tuiBase_t::initRelCoordS      (int16_t p_x, int16_t p_y)       {
    initRelCoordX(p_x);
    initRelCoordY(p_y);
}


uint16_t tuiBase_t::getDimH         (void)   {
    return g_h;
}

bool tuiBase_t::selectTst   (void)  {
    return (g_status == tuiMode_t::select) || (g_status == tuiMode_t::eventOn);
}

void tuiBase_t::debug_01    (void)  {
    mvwprintw   (stdscr, 6, 10, "*** deselect status: %02d - %02d *** commmon ancestor: %s *** selected %s ***", g_debugStatus, g_debugStatusX, g_strName, static_cast<tuiBase_t*>(g_poSelected)->g_strName);
}


// ----/\--/\--/\--/\--/\--/\--/\--/\--/\--/\--/-|-\--/\--/\--/\--/\--/\--/\--/\--/\--/\--/\----
// ___/--\/--\/--\/--\/--\/--\/--\/--\/--\/--\/--|--\/--\/--\/--\/--\/--\/--\/--\/--\/--\/--\___
// to use when my own father shift my own position by a mouse or key event
// so this function will be called inside some event handler function of my own father like
// - selectByMouse
// - key up/down
// - mouse wheel roll up/down
// the call to this function is located in a derived dtyBaseCntnrUnitX class (that is in the class container) 
// so this call regards a child (it is the childs function that is called)
// --------------------
// an example about when/how this function is called:
// tui<Father>::rollUpEvent (mouse event handler) ==> (base/interface class of the container) (<dtyBaseCntnrUnitX_t*>)->displayBoxRollUp ==> 
// ==> (derived class of dtyBaseCntnrUnitX_t) dtyTuiBase_t::shiftLoopElementRollUp ==> tuiBase_t::updCoordNbounds (this function)
// by this example you can understand where to call this function
// that is, inside of all functions of the container class that are associated to the evnt key/mouse
void tuiBase_t::updCoordNbounds    (int16_t p_delta)       {
//    // update coordinates
//    g_y0Win += p_delta;
//    g_y0a   += p_delta;
//    g_y0r   += p_delta;
//    g_lvl1Y0a   += p_delta;
//
//    g_boundUpper = MAX(g_boundUpper, g_lvl1Y0a);
//    g_boundLower = MIN(g_boundLower, g_lvl1Y0a + g_h - 1);
    updRelCoordY(p_delta);

    updCoordNboundsChilds();
}

void tuiBase_t::updRelCoordY(int16_t p_delta)   {

    g_y0r       += p_delta;
    g_lvl1Y0r    = g_y0r;
//    g_y0a           = P_PO_FATHER->getRootRefY0()   + g_lvl1Y0r;    // g_y0r;
//    g_y0Win         = P_PO_FATHER->getRefY0()       + g_lvl1Y0r;
//    g_lvl1Y0a       = P_PO_FATHER->getRefY0()       + g_lvl1Y0r;

    updAbsParams();
}

// ----/\--/\--/\--/\--/\--/\--/\--/\--/\--/\--/-|-\--/\--/\--/\--/\--/\--/\--/\--/\--/\--/\----
// ___/--\/--\/--\/--\/--\/--\/--\/--\/--\/--\/--|--\/--\/--\/--\/--\/--\/--\/--\/--\/--\/--\___
// to use when bounds father has been modified
// N.B.: the relative coords do not change but the absolute one only do
// this function is called indirectly by the updCoordNbounds function of its father by means container function via updCoordNboundsChilds function
// tui<Father>::updCoordNbounds ==> dty<Container>::updCoordNboundsChilds ==> tui<Child>::updCoordNboundsForNewFather ==> dty<Container>::updCoordNboundsChilds ==> ... ==> tui<Child>::updCoordNboundsForNewFather
// how you can see, the updCoordNbounds() function is called at the first step of the recursive calling inside links tree of the tui elements
// while this function is called in all other steps
// N.B.: only at the first step the relative coords are modified, in the other step only absolute coords change the relative one remain the same
// the call to this function is located in a derived dtyBaseCntnrUnitX class (that is in the class container) 
// so this call regards a child (it is the childs function that is called)
// --------------------
// an example on how this function is called:
// tuiBase_t::updCoordNbounds (the above function) ==> tuiBase_t::updCoordNboundsChilds ==> (if the tuiBase_t derived class has a container) dtyBaseCntnrUnitX_t::updCoordNboundsChilds ==> 
// ==> (derived class of dtyBaseCntnrUnitX_t) dtyStufX_t::updElementCoordNbounds::(<tuiBase_t*>)->updCoordNboundsForNewFather() (this function)
// by this example you can understand where to call this function
// that is, inside the updElementCoordNbounds function of the container class 
void tuiBase_t::updCoordNboundsForNewFather   (void) {
//    g_y0Win = G_PO_FATHER->g_y0Win + g_y0r;
//    g_y0a   = G_PO_FATHER->g_y0a   + g_y0r;
//
//    g_lvl1Y0a   = G_PO_FATHER->getRefY0() + g_y0r;
//
//
//    g_boundUpper = MAX(G_PO_FATHER->g_boundUpper, g_lvl1Y0a);
//    g_boundLower = MIN(G_PO_FATHER->g_boundLower, g_lvl1Y0a + g_h - 1);

    updAbsParams();
    updCoordNboundsChilds();
}

void tuiBase_t::updAbsParams   (void)     {

    g_y0Win     = G_PO_FATHER->getRefY0()       + g_lvl1Y0r;
    g_y0a       = G_PO_FATHER->getRootRefY0()   + g_lvl1Y0r;
    g_lvl1Y0a   = G_PO_FATHER->getRefY0()       + g_lvl1Y0r;


    g_boundUpper = MAX(G_PO_FATHER->getBoundYupper(), g_lvl1Y0a);
    g_boundLower = MIN(G_PO_FATHER->getBoundYlower(), g_lvl1Y0a + g_h - 1);

    // updAbsCoords();
    // updDspBoxDims();
    // updBounds();
}

void tuiBase_t::updCoordNboundsChilds    (void)       {
    // g_cntr->updCoordNboundsChilds();
}


bool tuiBase_t::bVisibleCompletely   (void)  {
    return (g_boundUpper == g_lvl1Y0a) && (g_boundLower == (g_lvl1Y0a + g_h - 1));
}


int32_t tuiBase_t::getDistanceFromUpperBound   (void)   {
    return g_boundUpper - g_lvl1Y0a;
}

int32_t tuiBase_t::getDistanceFromLowerBound   (void)   {
    return g_boundLower - (g_lvl1Y0a + g_h);
}

int32_t tuiBase_t::getDistanceFromBound   (void)   {
    if(g_lvl1Y0a < g_boundUpper)
        return g_boundUpper - g_lvl1Y0a;

    //  parent bounds         ----U-L---------
    //  select element box    -------o--------  o = u & l (element with g_h=1)
    //  select element bounds ------Lu--------
    if(g_boundLower < (g_lvl1Y0a + g_h - 1))
        return g_boundLower - (g_lvl1Y0a + g_h - 1);
        
    return 0;
}

//  g_y0Win = g_y0Win + g_boundUpper - (g_y0Win + g_h) = g_boundUpper - g_h

//void initBounds (void)  {
//    // get father bounds
//    g_boundUpper = MAX(l_fatherBoundUpper, y0rWin);
//    g_boundLower = MIN(l_fatherBoundLower, y0rWin + g_h);
//}
//
//bool bVisible   (void)  {
//    return (g_boundUpper <= g_boundLower);
//}
//
//void updateBoundsAfterFatherCoordUpd     (void)  {
//    g_boundUpper = MAX(l_fatherBoundUpper, y0rWin);
//    g_boundLower = MIN(l_fatherBoundLower, y0rWin + g_h);
//}
//
//void updateBoundsAfterCoordUpd     (void)  {
//    g_boundUpper = MAX(g_boundUpper, y0rWin);
//    g_boundLower = MIN(g_boundLower, y0rWin + g_h);
//}

