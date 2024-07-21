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
 * pphManager.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include <iostream>
#include <ncurses.h>

#include "pphManager.h"

#define SDK_USART_DISPLAY__START_CONSOLE	10

#define SDK_USART_SERVICE_MSG__HEADER					0
#define SDK_USART_SERVICE_MSG__RX_LINE_CONFLICT			1
#define SDK_USART_SERVICE_MSG__TX_LINE_CONFLICT			2
#define SDK_USART_SERVICE_MSG__PROCESS_LIST				3
#define SDK_USART_SERVICE_MSG__PACKET_END				4

#define SDK_USART_SERVICE_MSG__RX_RESET					6
#define SDK_USART_SERVICE_MSG__EMPTY_COMMAND			7

#define SDK_USART_SERVICE_MSG__EXIT_STEP_1				7
#define SDK_USART_SERVICE_MSG__EXIT_STEP_2				8
#define SDK_USART_SERVICE_MSG__EXIT_STEP_3				9

#define SDK_USART_SERVICE_MSG__COMMAND_RECEIVED 		5
#define SDK_USART_SERVICE_MSG__RX_STATUS_RUNNING		6
#define SDK_USART_SERVICE_MSG__RX_STATUS_COMPLETED		7
#define SDK_USART_SERVICE_MSG__TX_STATUS_RUNNING		8
#define SDK_USART_SERVICE_MSG__TX_STATUS_COMPLETED		9

#define SDK_USART_SERVICE_MSG__READER_COUNTER_CLR		6
#define SDK_USART_SERVICE_MSG__READER_COUNTER_1			7
#define SDK_USART_SERVICE_MSG__READER_COUNTER_2			8
#define SDK_USART_SERVICE_MSG__TX_ERROR					9

#define SDK_USART_SERVICE_MSG__DEBUG_TEST_0				5
#define SDK_USART_SERVICE_MSG__DEBUG_TEST_1				6
#define SDK_USART_SERVICE_MSG__DEBUG_TEST_2				7
#define SDK_USART_SERVICE_MSG__DEBUG_TEST_3				8
#define SDK_USART_SERVICE_MSG__DEBUG_TEST_4				9

// *******************

#define WIDTH 30
#define HEIGHT 10
int   pphManager_t::startx = 0;
int   pphManager_t::starty = 0;
const char* pphManager_t::choices[] = {
                    "Choice 1",
                    "Choice 2",
                    "Choice 3",
                    "Choice 4",
                    "Exit"
};

int pphManager_t::n_choices = sizeof(choices) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight);

// *******************

void pphManager_t::test_5   (void)  {
    WINDOW *menu_win;
    MEVENT event;

    int c, choice = 0;

    /* Initialize curses */
    clear();
    noecho();
    cbreak();       //Line buffering disabled. pass on everything

    /* Try to put the window in the middle of screen */
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;
    attron(A_REVERSE);
    mvprintw(23, 1, "Click on Exit to quit (Works best in a virtual console)");
    refresh();
    attroff(A_REVERSE);
    /* Print the menu for the first time */
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    print_menu(menu_win, 1);
    /* Get all the mouse events */
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    //printf("\033[?1003h\n"); // Makes the terminal report mouse movement events
    //mousemask(ALL_MOUSE_EVENTS, NULL);

    while(1)    {
        c = wgetch(menu_win);        
        int l_event = getmouse(&event);
        switch(c)   {
            case KEY_MOUSE:
                mvprintw(28, 0, "28 - Charcter pressed: %3d - event mouse code: %04d - status mouse: %04d - mouse.x: %04d - mouse.y: %04d", c, l_event, event.bstate, event.x, event.y);
                if(l_event == OK)  { /* When the user clicks left mouse button */
                    if(event.bstate & BUTTON1_PRESSED)  {
                        report_choice(event.x + 1, event.y + 1, &choice);
                        if(choice == -1) {
                            mvprintw(22, 1, "Exitting ...");
                            keypad(stdscr, TRUE);
                            getch();
                            clrtoeol();
                            refresh();

                            return;
                        }
                        mvprintw(22, 1, "Choice made is : %d - String chosen is \"%s\" ",choice-1, choices[choice-1]);
                    }
                    else    {
                        mvprintw(24, 1, "24 - !(event.bstate & BUTTON1_PRESSED)");
                        mvprintw(29, 0, "29 - Charcter pressed: %3d - event mouse code: %04d - status mouse: %04d - mouse.x: %04d - mouse.y: %04d", c, l_event, event.bstate, event.x, event.y);
                    }

                } else     mvprintw(25, 1, "25 - getmouse(&event) != OK");
                print_menu(menu_win, choice);
                break;
            default:
                mvprintw(26, 0, "Charcter pressed: %3d - event mouse code: %04d - mouse.x: %04d - mouse.y: %04d", c, l_event, event.x, event.y);
                break;

        }
        refresh();
    }

}

void pphManager_t::test_4   (void)  {
        WINDOW *menu_win;

        int highlight = 1;
        int choice = 0;
        int c;

        clear();
        noecho();
        cbreak();
        startx = (80 - WIDTH) / 2;
        starty = (24 - HEIGHT) / 2;
        menu_win = newwin(HEIGHT, WIDTH, starty, startx);
        keypad(menu_win, TRUE);
        mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
        refresh();
        print_menu(menu_win, highlight);
        while(1)
        {       
            c = wgetch(menu_win);
            switch(c)
            {       
                case KEY_UP:
                    if(highlight == 1) highlight = n_choices; /* Line buffering disabled. pass on everything */
                    else --highlight;
                    break;
                case KEY_DOWN:
                    if(highlight == n_choices) highlight = 1;
                    else ++highlight;
                    break;
                case 10:
                    choice = highlight;
                    break;
                default:
                    mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be pr", c);
                    refresh();
                    break;
            }
            print_menu(menu_win, highlight);
            if(choice != 0) /* User did a choice come out of the infinite loop */
                break;
        }
        mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
        clrtoeol();
        refresh();
}

void pphManager_t::test_3   (void)  {
        if(has_colors() == FALSE)
            {       
                endwin();
                printf("Your terminal does not support color\n");
                exit(1);
            }
        start_color();                  /* Start color                  */
        init_pair(1, COLOR_YELLOW, COLOR_BLUE);
        attron(COLOR_PAIR(1));
        print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
        attroff(COLOR_PAIR(1));
        refresh();            
}

void pphManager_t::test_2   (void)  {
        start_color();                  /* Start color functionality    */
        init_pair(1, COLOR_CYAN, COLOR_BLACK);

        printw("A Big string which i didn't care to type fully ");
        mvchgat(0,0,-1, A_BLINK, 1, NULL);
        /*
         * First two parameters specify the position at which to start
         * Third parameter number of characters to update. −1 means till
         * end of line
         * Forth parameter is the normal attribute you wanted to give
         * to the charcter
         * Fifth is the color index. It is the index given during init_pair()
         * use 0 if you didn't want color
         * Sixth one is always NULL
         */
        refresh();
}

void pphManager_t::test_1   (uint8_t p_mcuId)  {
        int ch;
        raw();                              /* Line buffering disabled      */
        keypad(stdscr, TRUE);               /* We get F1, F2 etc..          */
        noecho();                           /* Don't echo() while we do getch */

        printw("id: %02d - Type any character to see it in bold\n", p_mcuId);
        ch = getch();                       /* If raw() hadn't been called
                                             * we have to press enter before it
                                             * gets to the program          */
        if(ch == KEY_F(1))                  /* Without keypad enabled this will */
            printw("F1 Key pressed");       /*  not get to us either       */
                                            /* Without noecho() some ugly escape
                                             * charachters might have been printed
                                             * on screen                    */
        else
        {       
            printw("The pressed key is ");
            attron(A_BOLD);
            printw("%c", ch);
            attroff(A_BOLD);
        }

}

void pphManager_t::init (uint8_t p_mcuId) {
//	// PROCESS MANAGEMENT
//	//bool l_test = sdk_process::add_0(p_param);
//    bool l_test = false;
//    // 1. init 
//
//	// DISPLAY MANAGEMENT
//	initscr();
//	clear();
//	noecho();
//	cbreak();						// raw();	// Line buffering disabled. pass on everything. It does not need to press "enter" key to submit previous pressed key
//	nodelay(stdscr, true);			// non-blocking input (getch) -> the same of timeout(0)
//	keypad(stdscr, true);
//	if(l_test) mvprintw(0, 	0, "--- || ___ Ctrl-a, Ctrl-b or Ctrl-c to exit ___ || ---\n");
//	else mvprintw(0, 		0, "No process added\n");
//	processes_on_line();
//	move(10,0);
//	curs_set(0);
//	refresh();
//
    initscr();                          /* Start curses mode            */

    if(1 == p_mcuId) test_1(p_mcuId);

    if(2 == p_mcuId) test_2();

    if(3 == p_mcuId) test_3();

    if(4 == p_mcuId) test_4();

    if(5 == p_mcuId) test_5();



    getch();                            /* Print it on to the real screen */
    clrtoeol();
	refresh();
    endwin();                           /* Wait for user input */

    std::cout << "char \"ACS_VLINE\": " << ACS_VLINE << std::endl;
    char l_test[] = "│";
    uint32_t* l_pTest = reinterpret_cast<uint32_t*> (l_test);
    char l_test1[] = "─";
    uint32_t* l_pTest1 = reinterpret_cast<uint32_t*> (l_test1);
    char l_test2[] = "┌";
    uint32_t* l_pTest2 = reinterpret_cast<uint32_t*> (l_test2);
    char l_test3[] = "└";
    uint32_t* l_pTest3 = reinterpret_cast<uint32_t*> (l_test3);
    char l_test4[] = "┐";
    uint32_t* l_pTest4 = reinterpret_cast<uint32_t*> (l_test4);
    char l_test5[] = "┘";
    uint32_t* l_pTest5 = reinterpret_cast<uint32_t*> (l_test5);
    // std::cout << "char \"ACS_VLINE\": " << ACS_VLINE << " - " << "│ x \U00000078 x \U00008294" << *l_pTest  << std::endl;         // 0x400078 - 0x8294E2
    std::cout << "char \"ACS_VLINE\": " << ACS_VLINE << " - " << "│" << *l_pTest  << std::endl;         // 0x400078 - 0x8294E2
    std::cout << "char \"ACS_HLINE\": " << ACS_HLINE << " - " << "─" << *l_pTest1 << std::endl;         // 0x400071 - 0x8094E2
    std::cout << "char \"ACS_HLINE\": " << ACS_ULCORNER << " - " << "┌" << *l_pTest2 << std::endl;      // 0x40006C - 0x8C94E2
    std::cout << "char \"ACS_HLINE\": " << ACS_LLCORNER << " - " << "└" << *l_pTest3 << std::endl;      // 0x40006D - 0x9494E2
    std::cout << "char \"ACS_HLINE\": " << ACS_URCORNER << " - " << "┐" << *l_pTest4 << std::endl;      // 0x40006B - 0x9094E2
    std::cout << "char \"ACS_HLINE\": " << ACS_LRCORNER << " - " << "┘" << *l_pTest5 << std::endl;      // 0x40006A - 0x9894E2
    //std::cout << "char \"ACS_VLINE\": " << ACS_VLINE << " - " << L"\x40" << std::endl;
     // │ Choice 1                   │
     // ┌┐
     // ││──────────________
     // └┘

}

void pphManager_t::processes_on_line	(void)	{
	int x = getcurx(stdscr);
	int y = getcury(stdscr);

	//  move(SDK_USART_SERVICE_MSG__PROCESS_LIST,0);
	//  for(uint8_t i=0;i<PROCESS_MAX_NUMBER;i++){
	//  	uint16_t l_pid;
	//  	l_pid = sdk_process::get_pid(i);
	//  	printw("Pid %1d: %05d --- ", i, l_pid);
	//  }

	refresh();
	move(y,x);
}

void pphManager_t::end(void)	{

	// DISPLAY MANAGEMENT
	clrtoeol();
	refresh();
	endwin();

	// PROCESS MANAGEMENT
    //	sdk_process::del_0();

}


void pphManager_t::updateProcessesList (void) {
}

void pphManager_t::print_in_middle(WINDOW *win, int starty, int startx, int width, const char *string)
{   
    int length, x, y;
    float temp;
    if(win == NULL)
            win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
            x = startx;
    if(starty != 0)
            y = starty;
    if(width == 0)
    width = 80;
    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    mvwprintw(win, y, x, "%s", string);
    refresh();
}

void pphManager_t::print_menu   (WINDOW *menu_win, int highlight)
{
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for(i = 0; i < n_choices; ++i)
    {       
        if(highlight == i + 1) /* High light the present choice */
        {       
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);    
}

//{
//    int x, y, i;
//    x = 2;
//    y = 2;
//    box(menu_win, 0, 0);
//    for(i = 0; i < n_choices; ++i)
//    {       
//        if(highlight == i + 1)  {
//            wattron(menu_win, A_REVERSE);
//            mvwprintw(menu_win, y, x, "%s", choices[i]);
//            wattroff(menu_win, A_REVERSE);
//        } else
//            mvwprintw(menu_win, y, x, "%s", choices[i]);
//        ++y;
//    }
//    wrefresh(menu_win);
//
//}

void pphManager_t::report_choice       (int mouse_x, int mouse_y, int *p_choice)    {
    /* Report the choice according to mouse position */
    int i,j, choice;
    i = startx + 2;
    j = starty + 3;
    for(choice = 0; choice < n_choices; ++choice)
        if(
            (mouse_y == j + choice) && 
            (mouse_x >= i && mouse_x <= i + static_cast<int> (strlen(choices[choice])) )
        )
        {       
            if(choice == n_choices - 1) 
                *p_choice = -1;
            else 
                *p_choice = choice + 1;

            // exit from loop
            break;
        }
}
