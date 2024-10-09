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
 * tuiBaseDrawer.cpp
 *
 *  Created on: Aug, 7th 2024
 *      Author: Marco Dau
 */

#include "tuiBaseDrawer.h"

uint8_t tuiBaseDrawer_t::g_xMouse;
uint8_t tuiBaseDrawer_t::g_yMouse;
uint8_t tuiBaseDrawer_t::g_position;

int      tuiBaseDrawer_t::g_ncursEventCode;
MEVENT   tuiBaseDrawer_t::g_mouseEvent;

#define OFF     0
#define ON      1


tuiBaseDrawer_t::tuiBaseDrawer_t (void) :
     g_pNcursWin    {nullptr}
    ,g_h            {0}
    ,g_w            {0}
    ,g_y0r          {0}
    ,g_x0r          {0}
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {nullptr}
    ,g_pDtyStatus   {nullptr}
{}

tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t *p_pBox) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_pBox->height}
    ,g_w            {p_pBox->width}
    ,g_y0r          {p_pBox->yStart}
    ,g_x0r          {p_pBox->xStart}
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_marginTop    {1}
    ,g_marginBottom {1}
    ,g_marginLeft   {1}
    ,g_marginRight  {1}
    ,g_lvl1X0r      {p_pBox->xStart}
    ,g_lvl1Y0r      {p_pBox->yStart}
//    ,g_boundUpper   {}
//    ,g_boundLower   {}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {p_strName}
    ,g_pDtyStatus   {nullptr}
{}

tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t p_box) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_box.height}
    ,g_w            {p_box.width}
    ,g_y0r          {p_box.yStart}
    ,g_x0r          {p_box.xStart}
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_marginTop    {1}
    ,g_marginBottom {1}
    ,g_marginLeft   {1}
    ,g_marginRight  {1}
    ,g_lvl1X0r      {p_box.xStart}
    ,g_lvl1Y0r      {p_box.yStart}
//    ,g_boundUpper   {}
//    ,g_boundLower   {}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {p_strName}
    ,g_pDtyStatus   {nullptr}
{}

tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t p_box, dtyUint8_t* p_pDtyStatus) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_box.height   }
    ,g_w            {p_box.width    }
    ,g_y0r          {p_box.yStart   }
    ,g_x0r          {p_box.xStart   }
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_marginTop    {1}
    ,g_marginBottom {1}
    ,g_marginLeft   {1}
    ,g_marginRight  {1}
    ,g_lvl1X0r      {p_box.xStart}
    ,g_lvl1Y0r      {p_box.yStart}
//    ,g_boundUpper   {}
//    ,g_boundLower   {}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {p_strName      }
    ,g_pDtyStatus   {p_pDtyStatus   }
{}


tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t *p_pBox, margins_t p_margins) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_pBox->height}
    ,g_w            {p_pBox->width}
    ,g_y0r          {p_pBox->yStart}
    ,g_x0r          {p_pBox->xStart}
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_marginTop    {p_margins.Top}
    ,g_marginBottom {p_margins.Bottom}
    ,g_marginLeft   {p_margins.Left}
    ,g_marginRight  {p_margins.Right}
    ,g_lvl1X0r      {p_pBox->xStart}
    ,g_lvl1Y0r      {p_pBox->yStart}
//    ,g_boundUpper   {}
//    ,g_boundLower   {}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {p_strName}
    ,g_pDtyStatus   {nullptr}
{}

tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t p_box, margins_t p_margins) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_box.height}
    ,g_w            {p_box.width}
    ,g_y0r          {p_box.yStart}
    ,g_x0r          {p_box.xStart}
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_marginTop    {p_margins.Top}
    ,g_marginBottom {p_margins.Bottom}
    ,g_marginLeft   {p_margins.Left}
    ,g_marginRight  {p_margins.Right}
    ,g_lvl1X0r      {p_box.xStart}
    ,g_lvl1Y0r      {p_box.yStart}
//    ,g_boundUpper   {}
//    ,g_boundLower   {}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {p_strName}
    ,g_pDtyStatus   {nullptr}
{}

tuiBaseDrawer_t::tuiBaseDrawer_t (const char* p_strName, box_t p_box,  margins_t p_margins, dtyUint8_t* p_pDtyStatus) :
     g_pNcursWin    {nullptr}
    ,g_h            {p_box.height   }
    ,g_w            {p_box.width    }
    ,g_y0r          {p_box.yStart   }
    ,g_x0r          {p_box.xStart   }
    ,g_y0a          {0}
    ,g_x0a          {0}
    ,g_y0Win        {0}
    ,g_x0Win        {0}
    ,g_marginTop    {p_margins.Top}
    ,g_marginBottom {p_margins.Bottom}
    ,g_marginLeft   {p_margins.Left}
    ,g_marginRight  {p_margins.Right}
    ,g_lvl1X0r      {p_box.xStart}
    ,g_lvl1Y0r      {p_box.yStart}
//    ,g_boundUpper   {}
//    ,g_boundLower   {}
    ,g_status       {tuiMode_t::undefined}
    ,g_strName      {p_strName      }
    ,g_pDtyStatus   {p_pDtyStatus   }
{}

void tuiBaseDrawer_t::initGraphEnv        (void)     {
    initscr();                          /* Start curses mode            */

    // the current instance is the main window, therefore ...

    // 2. set the pointer of ncurses window to main window [stdsrc]
    g_pNcursWin = stdscr;
    // 3. complete ncurses initialization
    raw();                              /* Line buffering disabled        */
    nodelay(g_pNcursWin, true);
    keypad(g_pNcursWin, TRUE);           /* We get F1, F2 etc..            */
    noecho();                           /* Don't echo() while we do getch */
    curs_set(0);                        /* make cursor invisible */
    mousemask(  ALL_MOUSE_EVENTS |      \
                REPORT_MOUSE_POSITION,  \
                NULL);
    // 3.1. enable the continuously monitoring of mouse movement
    NCURS_MOUSE_TRACKING_ENABLE

}

void tuiBaseDrawer_t::initGraphEnvColor (void)    {
    start_color();    // BE CAREFUL!! - this instruction must be execute before init_pair function              /* Start color                  */

    // a) init color windows management
    NCURS_COLOR_PAIR_INIT_WINDOW_DESELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_SELECT;
    NCURS_COLOR_PAIR_INIT_WINDOW_EVENT_ON;
    NCURS_COLOR_PAIR_INIT_WINDOW_YELLOW;
    NCURS_COLOR_PAIR_INIT_WINDOW_MAGENTA;
    NCURS_COLOR_PAIR_INIT_WINDOW_CYAN;
    NCURS_COLOR_PAIR_INIT_WINDOW_WHITE;

}
void tuiBaseDrawer_t::deinitGraphEnv    (void)    {
    NCURS_MOUSE_TRACKING_DISABLE
    mvwprintw(g_pNcursWin, 3, 5, "Exiting ... ");
}

void tuiBaseDrawer_t::initWin           (void) {

    g_pNcursWin = newwin(g_h, g_w, g_y0a, g_x0a);
}

void tuiBaseDrawer_t::initWin           (uint16_t p_rootX0a, uint16_t p_rootY0a) {

    g_pNcursWin = newwin(g_h, g_w, p_rootY0a, p_rootX0a);

}


void tuiBaseDrawer_t::updateRelativeX   (uint8_t p_x0r) {
    g_x0Win = (g_x0Win  - g_x0r) + p_x0r + 1;   // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_x0a   = (g_x0a    - g_x0r) + p_x0r + 1;   // N.B.: (g_x0a - g_x0r) = p_poFather->g_x0a
    g_x0r   = p_x0r + 1;
}

void tuiBaseDrawer_t::updateRelativeY   (uint8_t p_y0r) {
    g_y0Win = (g_y0Win - g_y0r) + p_y0r + 1;    // N.B.: (g_y0Win - g_y0r) = p_poFather->g_y0Win
    g_y0a   = (g_y0a   - g_y0r) + p_y0r + 1;    // N.B.: (g_y0a   - g_y0r) = p_poFather->g_x0a
    g_y0r   = p_y0r + 1;
}

void tuiBaseDrawer_t::endGraphEnv       (void)  {
    nodelay(stdscr, false);
    getch();                            /* Print it on to the real screen */
    clrtoeol();
	refresh();
    endwin();                           /* Wait for user input */
}


int16_t tuiBaseDrawer_t::getRefX0            (void)  {
    return g_lvl1X0a + g_marginLeft;
}

int16_t tuiBaseDrawer_t::getRootRefX0            (void)  {
    return g_x0a + g_marginLeft;
}

int16_t tuiBaseDrawer_t::getDisplayMaxW      (void)  {
    return g_w - (g_marginLeft + g_marginRight);
}

int16_t tuiBaseDrawer_t::getRefY0            (void)  {
    return g_lvl1Y0a + g_marginTop;
}

int16_t tuiBaseDrawer_t::getRootRefY0            (void)  {
    return g_y0a + g_marginTop;
}

int16_t tuiBaseDrawer_t::getDisplayMaxH      (void)  {
    return g_h - (g_marginTop + g_marginBottom);
}



void tuiBaseDrawer_t::positionCursor     (bool p_status, uint8_t p_position)    {
    //wmove(g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + p_position);
    //curs_set(1);
    if(p_status)    {
        if(g_position != p_position)    {
            mvwchgat(g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + g_position,1, A_NORMAL, 0, NULL);
            g_position = p_position;
        }
        mvwchgat(g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + g_position,1, A_BLINK | A_UNDERLINE, 0, NULL);
    } else {
        g_position = p_position;
        mvwchgat(g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + p_position,1, A_NORMAL, 0, NULL);    
    }
    wrefresh(g_pNcursWin);
}


void tuiBaseDrawer_t::content (char* p_str, uint8_t p_size)   {

    mvwaddnstr  (g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1        ,p_str  ,p_size);
    if(p_size < g_w-2)
        mvwhline    (g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + p_size           ,' '    ,g_w - 2 - p_size      );

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::content (char* p_str, uint8_t p_begin, uint8_t p_size)   {

    mvwaddnstr  (g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + p_begin       ,p_str  ,p_size);
    if(p_size < g_w-2)
        mvwhline    (g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + p_begin + p_size           ,' '    ,g_w - 2 - (p_begin + p_size)      );

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::content (uint8_t p_begin)   {

    mvwhline    (g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1 + p_begin           ,' '    ,g_w - 2 - p_begin      );

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::frameNameNstatus (char* p_str)   {
    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0Win              ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win + g_w - 1     ,0    ,g_h - 2      );

    mvwprintw(g_pNcursWin, g_y0Win + 0          ,g_x0Win + 4        ," *~ %s ~*~ %04x - %04x | %04x - %04x ~* ", g_strName, g_lvl1Y0a, g_h, g_boundUpper, g_boundLower);
    mvwprintw(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + 1        ,"~ %s ~", p_str);

    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);

}

//void tuiBaseDrawer_t::rowPrint  ([[maybe_unused]] uint8_t b_row, [[maybe_unused]] bool p_bRowBegin, [[maybe_unused]] uint8_t p_rowMarker, [[maybe_unused]] uint8_t* p_pRowStr, [[maybe_unused]] uint8_t p_rowLength)     {
void tuiBaseDrawer_t::rowPrint  (uint8_t p_row, bool p_bRowBegin, uint8_t p_rowMarker, char* p_pRowStr, uint8_t p_rowLength)     {
    wattron (g_pNcursWin,COLOR_PAIR(p_rowMarker));

    //mvwaddchnstr(g_pNcursWin, g_y0Win + 1 + p_row          ,g_x0Win + 1        ,p_pRowStr  ,p_rowLength);
    if(p_bRowBegin) 
        //mvwaddnstr(g_pNcursWin, g_y0Win + 1 + p_row          ,g_x0Win        ,"1"  ,1);
        mvwaddch(g_pNcursWin,   g_y0Win + 1 + p_row          ,g_x0Win    ,'1'       );
    else
        //mvwaddnstr(g_pNcursWin, g_y0Win + 1 + p_row          ,g_x0Win        ," "  ,1);
        mvwaddch(g_pNcursWin,   g_y0Win + 1 + p_row          ,g_x0Win    ,' '       );

    if(*p_pRowStr)  {
        mvwaddnstr  (g_pNcursWin, g_y0Win + 1 + p_row          ,g_x0Win + 1        ,p_pRowStr  ,p_rowLength);
        if(p_rowLength < g_w-2)
    	    mvwhline    (g_pNcursWin, g_y0Win + 1 + p_row          ,g_x0Win + 1 + p_rowLength           ,' '    ,g_w - p_rowLength - 2      );
    } else
        mvwaddnstr(g_pNcursWin, g_y0Win + 1 + p_row          ,g_x0Win + 1        ,"0123456789"  ,10);

    wattroff(g_pNcursWin,COLOR_PAIR(p_rowMarker));
    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::statusPrintX  (void)  {
    //mvwprintw(g_pNcursWin, g_y0Win + 1          ,g_x0Win + 1        ,"~ %04x - %04x - %04x - %04x | %04x - %04x - %04x - %04x ~", g_y0Win, g_lvl1Y0a, g_displayBoxW, g_displayBoxH, g_relBoundUpper, g_relBoundLower, g_boundUpper, g_boundLower);
    mvwprintw   (g_pNcursWin, g_lvl1Y0a     ,g_lvl1Y0a        ,"~ %04x - %04x - %04x - %04x | %04x - %04x ~", g_y0Win, g_lvl1Y0a, g_displayBoxW, g_displayBoxH, g_boundUpper, g_boundLower);
}

void tuiBaseDrawer_t::statusPrintX  (char* p_pStr, uint32_t p_strSize)  {
    uint16_t l_strSize = p_strSize;
    uint16_t l_lenghtStrMax = g_displayBoxW - 1; // the first column is reserved for info about string (if it is the first row or not)
    // synchronization between row and string id to display
    uint16_t l_row0     = (g_lvl1Y0r < 0) ? (0 + (-g_lvl1Y0r)) : 0;
    uint16_t l_strId    = (g_lvl1Y0r < 0) ? (l_lenghtStrMax*(-g_lvl1Y0r)) : 0;
    l_strSize          -= (g_lvl1Y0r < 0) ?  l_strId         : 0;
    uint16_t l_strSizeRow  = (l_strSize < l_lenghtStrMax) ? l_strSize : l_lenghtStrMax;

        if(0 == l_strId) 
            mvwaddch(g_pNcursWin,   g_lvl1Y0a + l_row0          ,g_lvl1X0a    ,'1'       );
        else
            mvwaddch(g_pNcursWin,   g_lvl1Y0a + l_row0          ,g_lvl1X0a    ,' '       );

        // mvwprintw   (g_pNcursWin, g_lvl1Y0a + l_row0     ,g_lvl1X0a      ,"~ %08x - %08x ~", p_dbgParam1, p_dbgParam2);
        // mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row0     ,g_lvl1X0a + 24 , &p_pStr[l_strId]  ,5);
        mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row0     ,g_lvl1X0a + 1     ,&p_pStr[l_strId]  ,l_strSizeRow);
        if(l_strSizeRow < l_lenghtStrMax)    {
      	    mvwhline    (g_pNcursWin, g_lvl1Y0a + l_row0          ,g_lvl1X0a + 1 + l_strSizeRow           ,' '    ,l_lenghtStrMax - l_strSizeRow);
            // the last row is displayed, therefore ...
        }
        if(g_boundLower == (g_lvl1Y0a + l_row0)) return;

        l_row0++;
        l_strId         += l_lenghtStrMax;
        l_strSize       -= (l_strSize < l_lenghtStrMax) ? 0         : l_lenghtStrMax;
        l_strSizeRow     = (l_strSize < l_lenghtStrMax) ? l_strSize : l_lenghtStrMax;
        // mvwprintw   (g_pNcursWin, g_lvl1Y0a + l_row1   ,g_lvl1X0a      ,"~ %04x - %04x - %04x - %04x | %04x - %04x ~", g_y0Win, g_lvl1Y0a, g_displayBoxW, g_displayBoxH, g_boundUpper, g_boundLower);
        // mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row1   ,g_lvl1X0a + 44 ,&p_pStr[l_strId]  ,5);
        mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row0     ,g_lvl1X0a + 1     ,&p_pStr[l_strId]  ,l_strSizeRow);
        if(l_strSizeRow < l_lenghtStrMax)    {
      	    mvwhline    (g_pNcursWin, g_lvl1Y0a + l_row0          ,g_lvl1X0a + 1 + l_strSizeRow           ,' '    ,l_lenghtStrMax - l_strSizeRow);
            // the last row is displayed, therefore ...
        }
        if(g_boundLower == (g_lvl1Y0a + l_row0)) return;

        l_row0++;
        l_strId         += l_lenghtStrMax;
        l_strSize       -= (l_strSize < l_lenghtStrMax) ? 0         : l_lenghtStrMax;
        l_strSizeRow     = (l_strSize < l_lenghtStrMax) ? l_strSize : l_lenghtStrMax;
        // mvwprintw   (g_pNcursWin, g_lvl1Y0a + l_row1   ,g_lvl1X0a      ,"~ %04x - %04x - %04x - %04x | %04x - %04x ~", g_y0Win, g_lvl1Y0a, g_displayBoxW, g_displayBoxH, g_boundUpper, g_boundLower);
        // mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row1   ,g_lvl1X0a + 44 ,&p_pStr[l_strId]  ,5);
        mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row0     ,g_lvl1X0a + 1     ,&p_pStr[l_strId]  ,l_strSizeRow);
        if(l_strSizeRow < l_lenghtStrMax)    {
      	    mvwhline    (g_pNcursWin, g_lvl1Y0a + l_row0          ,g_lvl1Y0a + 1 + l_strSizeRow           ,' '    ,l_lenghtStrMax - l_strSizeRow);
            // the last row is displayed, therefore ...
        }
}

void tuiBaseDrawer_t::debugPrintX    (uint32_t p_dbgParam1, uint32_t p_dbgParam2, char* p_pStr)       {
    uint16_t l_lenghtStrMax = g_displayBoxW - 1; // the first column is reserved for info about string (if it is the first row or not)
    uint16_t l_strId    = (g_lvl1Y0r < 0) ? (l_lenghtStrMax*(-g_lvl1Y0r)) : 0;
    //uint16_t l_strSizeRow  = (p_strSize < l_lenghtStrMax) ? (p_strSize - (l_strId * l_lenghtStrMax)) : l_lenghtStrMax;
    uint16_t l_rowUp    = (g_lvl1Y0r < 0) ? (0 + (-g_lvl1Y0r)) : 0;
    //uint16_t l_rowDw = (g_lvl1Y0r < 0) ? (1 + (-g_lvl1Y0r)) : 1;

    mvwprintw   (g_pNcursWin, g_lvl1Y0a + l_rowUp     ,g_lvl1X0a      ,"~ %08x - %08x - %04x ~", p_dbgParam1, p_dbgParam2, l_lenghtStrMax);
    mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_rowUp     ,g_lvl1X0a + 8 , &p_pStr[l_strId]  ,5);

}
void tuiBaseDrawer_t::debugPrintXTest    (void)       {

    mvwprintw   (g_pNcursWin, 1     ,1  ,"~ test ~");
    wrefresh(g_pNcursWin);

}

void tuiBaseDrawer_t::rowPrintX  (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) {
    wattron (g_pNcursWin,COLOR_PAIR(p_rowMarker));
    if(p_select) wattron (g_pNcursWin,A_UNDERLINE);


    uint16_t l_strSize = p_strSize;
    uint16_t l_lenghtStrMax = g_displayBoxW - 1; // the first column is reserved for info about string (if it is the first row or not)

    // synchronization between row and string id to display
    uint16_t l_row0     = (g_lvl1Y0r < 0) ? (0 + (-g_lvl1Y0r)) : 0;
    uint16_t l_strId    = (g_lvl1Y0r < 0) ? (l_lenghtStrMax*(-g_lvl1Y0r)) : 0;
    l_strSize          -= (g_lvl1Y0r < 0) ?  l_strId         : 0;
    uint16_t l_strSizeRow  = (l_strSize < l_lenghtStrMax) ? l_strSize : l_lenghtStrMax;

    for(;;)    {

        if(0 == l_strId) 
            mvwaddch(g_pNcursWin,   g_lvl1Y0a + l_row0          ,g_lvl1X0a    ,'1'       );
        else
            mvwaddch(g_pNcursWin,   g_lvl1Y0a + l_row0          ,g_lvl1X0a    ,' '       );

        // ---------------------

        mvwaddnstr  (g_pNcursWin, g_lvl1Y0a + l_row0     ,g_lvl1X0a + 1     ,&p_pStr[l_strId]  ,l_strSizeRow);
        if(l_strSizeRow < l_lenghtStrMax)    {
            if(p_select) wattroff (g_pNcursWin,A_UNDERLINE);
            wattron (g_pNcursWin,A_NORMAL);
      	    mvwhline    (g_pNcursWin, g_lvl1Y0a + l_row0          ,g_lvl1X0a + 1 + l_strSizeRow           ,' '    ,l_lenghtStrMax - l_strSizeRow);
            // the last row is displayed, therefore ...
        }
        if(g_boundLower == (g_lvl1Y0a + l_row0)) break;

        l_row0++;
        l_strId         += l_lenghtStrMax;
        l_strSize       -= (l_strSize < l_lenghtStrMax) ? 0         : l_lenghtStrMax;
        l_strSizeRow     = (l_strSize < l_lenghtStrMax) ? l_strSize : l_lenghtStrMax;

    }

    if(p_select) wattroff (g_pNcursWin,A_UNDERLINE);
    wattron (g_pNcursWin,A_NORMAL);
    wattroff(g_pNcursWin,COLOR_PAIR(p_rowMarker));

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::frameDebug (char* p_str)   {
    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

    mvwprintw(g_pNcursWin, g_y0Win + 2          ,g_x0Win + 4        ,"~ %s ~", p_str);

    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);

}

void tuiBaseDrawer_t::frameDebug (uint8_t p_row, char* p_str)   {
    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

    mvwprintw(g_pNcursWin, g_y0Win + p_row          ,g_x0Win + 4        ,"~ %s ~", p_str);

    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);

}

bool tuiBaseDrawer_t::frameNname (tuiMode_t p_mode)   {
    if(g_status == p_mode) return false; 
    g_status = p_mode;
    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, ON);

	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0Win              ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win + g_w - 1     ,0    ,g_h - 2      );

    // mvwprintw   (g_pNcursWin, g_y0Win + 0, g_x0Win + 4, " *~ %s ~* ", g_strName);
    mvwprintw   (g_pNcursWin, g_y0Win + 0, g_x0Win + 4, " *~ %s ~*~ %04x - %04x ~* ", g_strName, g_y0Win, g_lvl1Y0a);

    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);

    return true;
}

void tuiBaseDrawer_t::frameNname (void)   {
    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0Win              ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win + g_w - 1     ,0    ,g_h - 2      );

    //mvwprintw   (g_pNcursWin, g_y0Win + 0, g_x0Win + 4, " *~ %s ~* ", g_strName);
    mvwprintw   (g_pNcursWin, g_y0Win + 0, g_x0Win + 4, " *~ %s ~*~ %04x - %04x ~* ", g_strName, g_y0Win, g_lvl1Y0a);

    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);
}

bool tuiBaseDrawer_t::frameNameNstatus (tuiMode_t p_mode, char* p_str)   {
    if(g_status == p_mode) return false; 
    g_status = p_mode;
    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, ON);

	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win               ,ACS_ULCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win              ,g_x0Win + g_w - 1     ,ACS_URCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win               ,ACS_LLCORNER       );
	mvwaddch(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + g_w - 1     ,ACS_LRCORNER       );
	mvwhline(g_pNcursWin, g_y0Win              ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwhline(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + 1           ,0    ,g_w - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win               ,0    ,g_h - 2      );
	mvwvline(g_pNcursWin, g_y0Win + 1          ,g_x0Win + g_w - 1     ,0    ,g_h - 2      );

    //mvwprintw(g_pNcursWin, g_y0Win + 0          ,g_x0Win + 4        ," *~ %s ~* ", g_strName);
    mvwprintw(g_pNcursWin, g_y0Win + 0          ,g_x0Win + 4        ," *~ %s ~*~ %04x - %04x | %04x - %04x ~* ", g_strName, g_lvl1Y0a, g_h, g_boundUpper, g_boundLower);
    mvwprintw(g_pNcursWin, g_y0Win + g_h - 1    ,g_x0Win + g_w - 21 ," >> %s << ", p_str);

    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);
    return true;
}

void tuiBaseDrawer_t::frameBox (void)   {
    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, ON);

    box         (g_pNcursWin, 0, 0);                  // BE CAREFUL !! - if (g_ncursWin==stdscr) this instructions clear all sub-windows and you have to repaint the box and refresh subwindow
    mvwprintw   (g_pNcursWin, 0, 10, " *** window name: %s *** %04x - %04x ***", g_strName, g_y0Win, g_lvl1Y0a);

    g_attributeMode_Frame[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh    (g_pNcursWin);

}

bool tuiBaseDrawer_t::frameBox (tuiMode_t p_mode)   {
    if(g_status == p_mode) return false; 
    g_status = p_mode;
    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, ON);

    box(g_pNcursWin, 0, 0);                  // BE CAREFUL !! - if (g_ncursWin==stdscr) this instructions clear all sub-windows and you have to repaint the box and refresh subwindow
    //mvwprintw   (g_pNcursWin, 0, 10, " *** window name: %s *** ", g_strName);
    mvwprintw   (g_pNcursWin, 0, 10, " *** window name: %s *** %04x - %04x ***", g_strName, g_y0Win, g_lvl1Y0a);

    g_attributeMode_Frame[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);
    return true;
}



void tuiBaseDrawer_t::nameOnly (void)   {

    g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, ON);
    mvwprintw(g_pNcursWin, g_y0Win, g_x0Win, "%s", g_strName);
    g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::nameOnly (tuiMode_t p_mode)   {
    g_status = p_mode;
    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, ON);

    mvwprintw(g_pNcursWin, g_y0Win, g_x0Win, "%s", g_strName);

    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);
}

void tuiBaseDrawer_t::nameNstatus (void)   {

    g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, ON);
    mvwprintw(g_pNcursWin, g_y0Win, g_x0Win, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);
    g_attributeMode_Line[static_cast<uint8_t>(g_status)](this, OFF);

    wrefresh(g_pNcursWin);
}

bool tuiBaseDrawer_t::nameNstatus (tuiMode_t p_mode)   {
    if(g_status == p_mode) return false; 
    g_status = p_mode;
    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, ON);

    mvwprintw(g_pNcursWin, g_y0Win, g_x0Win, "-- %s -- %02d", g_strName, *g_pDtyStatus->g_pValue);

    g_attributeMode_Line[static_cast<uint8_t>(p_mode)](this, OFF);

    wrefresh(g_pNcursWin);
    return true;
}

bool tuiBaseDrawer_t::bMouseClickInsideBounds (void)      {
    bool l_result = false;

    if(
        ((g_x0a <= g_xMouse) && (g_xMouse < (g_x0a + g_w ))) &&
        ((g_y0a <= g_yMouse) && (g_yMouse < (g_y0a + g_h )))
    ) {
        l_result = true;

    }
    return l_result;
}

bool tuiBaseDrawer_t::uiEventStatus                                 (void)  {
    bool l_result;
    g_ncursEventCode = wgetch(g_pNcursWin);
    l_result = (ERR != g_ncursEventCode);
    return l_result;
}

int tuiBaseDrawer_t::uiEventKeyCode                                 (void)  {
    return g_ncursEventCode;
}

tuiEventCode_t  tuiBaseDrawer_t::uiHandlerEventCode                 (void)  {
    tuiEventCode_t l_eventCode = tuiEventCode_t::noEvent;
    switch(g_ncursEventCode)    {
        case KEY_MOUSE:
            mvwprintw(g_pNcursWin, 2, 50, "MOUSE_EVENT");
            l_eventCode = tuiEventCode_t::mouse;
            getmouse(&g_mouseEvent);
            char l_str[30];
            snprintf(l_str, sizeof l_str,"%03d / %03d", g_mouseEvent.x, g_mouseEvent.y);
            mvwprintw(g_pNcursWin, 3, 50, "MOUSE_coordinates: %s",l_str);
            snprintf(l_str, sizeof l_str,"%08lx", g_mouseEvent.bstate);
            mvwprintw(g_pNcursWin, 4, 50, "MOUSE_status: %s",l_str);
            if(0x00080000 == g_mouseEvent.bstate) l_eventCode = tuiEventCode_t::keyUp;
            if(0x08000000 == g_mouseEvent.bstate) l_eventCode = tuiEventCode_t::keyDown;            
            break;
        case KEY_DOWN:
        case TUI_KEY_TAB:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_DOWN                            ");
            l_eventCode = tuiEventCode_t::keyDown;
            break;
        case KEY_UP:
        case TUI_KEY_SHIFT_TAB:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_UP                              ");
            l_eventCode = tuiEventCode_t::keyUp;
            break;
        case KEY_LEFT:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_LEFT                            ");
            l_eventCode = tuiEventCode_t::keyLeft;
            break;
        case KEY_RIGHT:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_RIGHT                           ");
            l_eventCode = tuiEventCode_t::keyRight;
            break;
        case KEY_ENTER:
        case TUI_KEY_RETURN:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_ENTER                           ");
            l_eventCode = tuiEventCode_t::keyEnter;
            break;
        case KEY_HOME:
        case TUI_KEY_ESC:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_HOME                            ");
            l_eventCode = tuiEventCode_t::keyHome;
            break;
        case TUI_KEY_DEL:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_DEL                             ");
            l_eventCode = tuiEventCode_t::keyDel;
            break;
        case TUI_KEY_BACKSPACE:
            mvwprintw(g_pNcursWin, 2, 50, "KEY_BACKSPACE                       ");
            l_eventCode = tuiEventCode_t::keyBackspace;
            break;
        default:
            if((0x20 <= g_ncursEventCode) && (g_ncursEventCode < 0x7f)) {
                mvwprintw(g_pNcursWin, 2, 50, "type character - keyCode: %04x", g_ncursEventCode);
                l_eventCode = tuiEventCode_t::keyTypeChar;
            } else {
                mvwprintw(g_pNcursWin, 2, 50, "UNKNOWN_EVENT - keyCode: %04x", g_ncursEventCode);
            }
            break;
    }

    return l_eventCode;
}

bool tuiBaseDrawer_t::uiMouseEventStatus                            (void)  {
    bool l_result;
    
    //l_result = (getmouse(&g_mouseEvent) == OK);
    l_result = true;
    g_xMouse = g_mouseEvent.x;
    g_yMouse = g_mouseEvent.y;

    return l_result;
}

bool tuiBaseDrawer_t::uiMouseEventCode_ButtonPressed             (void)  {
    bool l_result;
    l_result = ((g_mouseEvent.bstate & BUTTON1_PRESSED)  ||
                (g_mouseEvent.bstate & BUTTON1_CLICKED)     );
    return l_result;
}

bool tuiBaseDrawer_t::isSelectedOrEventOn             (void)  {
    return (
            (tuiMode_t::select == g_status) ||
            (tuiMode_t::eventOn == g_status)
    );
}

bool tuiBaseDrawer_t::isSelected             (void)  {
    return (tuiMode_t::select == g_status);
}

void tuiBaseDrawer_t::attributeMode_frameDeselect (tuiBaseDrawer_t* p_this, uint8_t p_status)   {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
}

void tuiBaseDrawer_t::attributeMode_frameSelect (tuiBaseDrawer_t* p_this, uint8_t p_status)     {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_SELECT);
}

void tuiBaseDrawer_t::attributeMode_frameEventOn (tuiBaseDrawer_t* p_this, uint8_t p_status)    {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
}

void tuiBaseDrawer_t::attributeMode_lineDeselect ([[maybe_unused]]tuiBaseDrawer_t* p_this, [[maybe_unused]] uint8_t p_status)    {
    //if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
    //if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_DESELECT);
}

void tuiBaseDrawer_t::attributeMode_lineSelect (tuiBaseDrawer_t* p_this, uint8_t p_status)      {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,A_UNDERLINE);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,A_UNDERLINE);
}

void tuiBaseDrawer_t::attributeMode_lineEventOn (tuiBaseDrawer_t* p_this, uint8_t p_status)     {
    if(OFF == p_status) wattroff(p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
    if(ON  == p_status) wattron (p_this->g_pNcursWin,NCURS_COLOR_PAIR_WINDOW_EVENT_ON);
//    if(OFF == p_status) wattroff(p_this->g_pNcursWin,A_REVERSE);
//    if(ON  == p_status) wattron (p_this->g_pNcursWin,A_REVERSE);
}

tuiBaseDrawer_t::attributeFunc_t  tuiBaseDrawer_t::g_attributeMode_Frame[] = {
     attributeMode_frameDeselect
    ,attributeMode_frameDeselect
    ,attributeMode_frameSelect
    ,attributeMode_frameEventOn
};

tuiBaseDrawer_t::attributeFunc_t  tuiBaseDrawer_t::g_attributeMode_Line[] = {
     attributeMode_lineDeselect
    ,attributeMode_lineDeselect
    ,attributeMode_lineSelect
    ,attributeMode_lineEventOn
};

