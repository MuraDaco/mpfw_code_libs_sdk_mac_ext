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
 * vhwUnit.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#include <iomanip>      // std::quoted()
#include <iostream>
#include <string>
#include <stdexcept>

//#include "mcuPinPort.h"
//#include "vhwPphTbl.h"
#include "vhwManager.h"


int main(int argc, char *argv[])      {
    //uint8_t g_portTest;
    uint8_t g_mcuId = 0;

    std::cout << "argc == " << argc << '\n';
 
    for(int ndx{}; ndx != argc; ++ndx) {
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
        std::string l_string (argv[ndx]);
        if( "-id" == l_string)   {
            try
            {
                g_mcuId = std::stoi(argv[++ndx]); // Throws: no conversion
                std::cout << "-id parametr == " << static_cast<int> (g_mcuId) << '\n';
            }
            catch (std::invalid_argument const& ex)
            {
                std::cout << "#2: " << ex.what() << '\n';
            }
        }
    }
    std::cout << "argv[" << argc << "] == "
              << static_cast<void*>(argv[argc]) << '\n';

    vhwManager_t::init(g_mcuId);

//    mcuPinPort_t a(1,&g_portTest,3, mcuPinPort_t::ain);
//
//    a.vhwLoop();
//
//    vhwUnit_t& ra = a;
//    vhwUnit_t* pa = &a;
//
//    ra.vhwLoop();
//    pa->vhwLoop();
//    
//    //((static_cast<mcuPort_t&> (vhwUnitManagerTbl::vhwUnitManagerPtrArray[5].g_ptrUnit)).g_Func)();

}