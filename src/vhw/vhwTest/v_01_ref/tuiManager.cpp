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
 * tuiManager.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */


#include "tuiManager.h"

#include <ncurses.h>

#include <thread>
#include <chrono>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.


uint8_t tuiManager_t::g_mcuId;
//tuiWin_t* tuiManager_t::g_mainWin;
//tuiWin_t* tuiManager_t::g_mainWin = nullptr;

void tuiManager_t::init(void)   {
    initscr();                          /* Start curses mode            */
    g_mainWin->init(nullptr);
    
}

void tuiManager_t::end(void)   {
    nodelay(stdscr, false);
    getch();                            /* Print it on to the real screen */
    clrtoeol();
	refresh();
    endwin();                           /* Wait for user input */
}

void tuiManager_t::loop(void)   {


    while(g_mainWin->eventManagement()) {
    	sleep_for(10*1ms);
    }

    // int l_ncursEventCode = getch();
    // if(ERR != l_ncursEventCode)   {
    //     // translate the [ncurses] event code in the [tui] eventcode
    //     int l_eventCode = eventCode(l_ncursEventCode);
    //     // check eventKey to move the winwdows focus or, that is the same thing, to change the acitve windows 
    //     if(1 == l_eventCode) {
    //         g_mainWin->eventManagement(l_eventCode);
    //     }
    // }
//
//        }  else {
//            for(i=0;i<10;i++)   {
//                // alla finestra viene dato il codice evento ottenuto da ncurses
//                // ci sono due controlli che deve compiere la finestra
//                //      1. se è un evento da mouse deve verificare che il click sia avvenuto entro i suoi "confini"
//                //          - in questo caso deve
//                //              1. impostare la finestra come attiva
//                //      2. se è un evento da tastiera deve verificare di essere attiva
//                //          - la proprietà di essere attiva dovrebbe essere una variabile globale e quindi statica della classe [tuiWin]
//                //            questa variabile potrebbe essere il codice identificativo [idWin] della finestra
//                if(windowsTbl[i].checkEvent(l_eventKeyCode)) {
//                    //if(MOUSE_EVENT == l_eventKeyCode)   {
//                    //} else {
//                    //    windowsTbl[i]->setActive();
//                    //    windowsTbl[i]->eventTable[l_eventKeyCode]();
//                    //}
//                    break;
//                }
//            }
//        }    
//    }

}

int tuiManager_t::eventCode  (int p_ncursesEventCode)  {
    return p_ncursesEventCode;
}


void tuiManager_t::test_1   (uint8_t p_mcuId)      {
    g_mcuId = p_mcuId;
}
