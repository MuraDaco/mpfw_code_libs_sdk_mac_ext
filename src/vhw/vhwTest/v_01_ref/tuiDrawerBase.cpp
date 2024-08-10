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
 * tuiDrawerBase.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */

#include "tuiDrawerBase.h"

uint8_t tuiDrawerBase_t::g_xMouse;
uint8_t tuiDrawerBase_t::g_yMouse;

tuiDrawerBase_t::tuiDrawerBase_t (box_t* p_pBox) :
     g_h        {p_pBox->height}
    ,g_w        {p_pBox->width}
    ,g_y0       {p_pBox->yStart}
    ,g_x0       {p_pBox->xStart}
    ,g_y0Win    {0}
    ,g_x0Win    {0}
{}


tuiDrawerBase_t::tuiDrawerBase_t (const char* p_strName, box_t *p_pBox) :
     g_h        {p_pBox->height}
    ,g_w        {p_pBox->width}
    ,g_y0       {p_pBox->yStart}
    ,g_x0       {p_pBox->xStart}
    ,g_y0Win    {0}
    ,g_x0Win    {0}
    ,g_strName  {p_strName}
{}

tuiDrawerBase_t::tuiDrawerBase_t (WINDOW* p_pNcursWin, box_t* p_pBox) :
     g_pNcursWin    {p_pNcursWin}
    ,g_h            {p_pBox->height}
    ,g_w            {p_pBox->width}
    ,g_y0           {p_pBox->yStart}
    ,g_x0           {p_pBox->xStart}
    ,g_y0Win    {0}
    ,g_x0Win    {0}
{}

tuiDrawerBase_t::tuiDrawerBase_t (uint8_t p_h, uint8_t p_w, uint8_t p_y0, uint8_t p_x0)     :
     g_h        {p_h}
    ,g_w        {p_w}
    ,g_y0       {p_y0}
    ,g_x0       {p_x0}
    ,g_y0Win    {0}
    ,g_x0Win    {0}
{}

tuiDrawerBase_t::tuiDrawerBase_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus) :
     g_h            {p_box.height   }
    ,g_w            {p_box.width    }
    ,g_y0           {p_box.yStart   }
    ,g_x0           {p_box.xStart   }
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_strName      {p_strName      }
    ,g_pDtyStatus   {p_pDtyStatus   }
{}



void tuiDrawerBase_t::frame (WINDOW* p_pNcursWin)   {
	mvwaddch(p_pNcursWin, g_y0        ,g_x0       ,ACS_ULCORNER                   );
	mvwaddch(p_pNcursWin, g_y0        ,g_x0 + g_w ,ACS_URCORNER               );
	mvwaddch(p_pNcursWin, g_y0 + g_h  ,g_x0       ,ACS_LLCORNER               );
	mvwaddch(p_pNcursWin, g_y0 + g_h  ,g_x0 + g_w ,ACS_LRCORNER               );
	mvwhline(p_pNcursWin, g_y0        ,g_x0 + 1   ,0   ,g_w - 1    );
	mvwhline(p_pNcursWin, g_y0 + g_h  ,g_x0 + 1   ,0   ,g_w - 1    );
	mvwvline(p_pNcursWin, g_y0 + 1    ,g_x0       ,0   ,g_h - 1    );
	mvwvline(p_pNcursWin, g_y0 + 1    ,g_x0 + g_w ,0   ,g_h - 1    );
}

void tuiDrawerBase_t::frame (void)   {
	mvwaddch(g_pNcursWin, g_y0        ,g_x0       ,ACS_ULCORNER                   );
	mvwaddch(g_pNcursWin, g_y0        ,g_x0 + g_w ,ACS_URCORNER               );
	mvwaddch(g_pNcursWin, g_y0 + g_h  ,g_x0       ,ACS_LLCORNER               );
	mvwaddch(g_pNcursWin, g_y0 + g_h  ,g_x0 + g_w ,ACS_LRCORNER               );
	mvwhline(g_pNcursWin, g_y0        ,g_x0 + 1   ,0   ,g_w - 1    );
	mvwhline(g_pNcursWin, g_y0 + g_h  ,g_x0 + 1   ,0   ,g_w - 1    );
	mvwvline(g_pNcursWin, g_y0 + 1    ,g_x0       ,0   ,g_h - 1    );
	mvwvline(g_pNcursWin, g_y0 + 1    ,g_x0 + g_w ,0   ,g_h - 1    );
}

void tuiDrawerBase_t::frame (tuiMode_t p_mode)   {
    if(tuiMode_t::deselect == p_mode) {
        wattron(g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    } else {
        wattron(g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    }

	mvwaddch(g_pNcursWin, g_y0              ,g_x0               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0              ,g_x0 + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0 + g_h - 1    ,g_x0               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0 + g_h - 1    ,g_x0 + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0              ,g_x0 + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0 + g_h - 1    ,g_x0 + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0 + 1          ,g_x0               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0 + 1          ,g_x0 + g_w - 1     ,0    ,g_h - 2      );

    if(tuiMode_t::deselect == p_mode) {
        wattroff(g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    } else {
        wattroff(g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    }

    wrefresh(g_pNcursWin);

}


void tuiDrawerBase_t::name (tuiMode_t p_mode)   {
    if(tuiMode_t::deselect == p_mode) {
        wattron(g_pNcursWin,A_UNDERLINE);
    }

    mvwprintw(g_pNcursWin, g_y0Win + g_y0, g_x0Win + g_x0, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);

    if(tuiMode_t::deselect == p_mode) {
        wattroff(g_pNcursWin,A_UNDERLINE);
    }

    wrefresh(g_pNcursWin);
}

void tuiDrawerBase_t::nameNstatus (tuiMode_t p_mode)   {
    if(tuiMode_t::select == p_mode) {
        wattron(g_pNcursWin,A_UNDERLINE);
    }

    mvwprintw(g_pNcursWin, g_y0Win + g_y0, g_x0Win + g_x0, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);

    if(tuiMode_t::select == p_mode) {
        wattroff(g_pNcursWin,A_UNDERLINE);
    }

    wrefresh(g_pNcursWin);
}

void tuiDrawerBase_t::nameNstatus (tuiMode_t p_mode, point_t p_point0)   {
    if(tuiMode_t::select == p_mode) {
        wattron(g_pNcursWin,A_UNDERLINE);
    }

    mvwprintw(g_pNcursWin, p_point0.y + g_y0, p_point0.x + g_x0, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);

    if(tuiMode_t::select == p_mode) {
        wattroff(g_pNcursWin,A_UNDERLINE);
    }

    wrefresh(g_pNcursWin);
}

bool tuiDrawerBase_t::bMouseClickInsideBounds (void)      {
    bool l_result = false;

    if(
        ((g_x0 <= g_xMouse) && (g_xMouse < (g_x0+g_w ))) &&
        ((g_y0 <= g_yMouse) && (g_yMouse < (g_y0+g_h )))
    ) {
        l_result = true;

    }
    return l_result;

//    return  ((g_pBox->xStart <= g_mouseXY.x) && (g_mouseXY.x < (g_pBox->xStart+g_pBox->width ))) &&
//            ((g_pBox->yStart <= g_mouseXY.y) && (g_mouseXY.y < (g_pBox->yStart+g_pBox->height)));
}
