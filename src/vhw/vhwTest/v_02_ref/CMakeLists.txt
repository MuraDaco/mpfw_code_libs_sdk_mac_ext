#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the "main" entry point and, 
#       eventualy, application code that is platform dependent
#   Copyright (C) (2023) Marco Dau
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published
#   by the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#   
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#   
#   You can contact me by the following email address
#   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
#   
#   *******************************************************************************

## cmake -S . -B build -G "Unix Makefiles"
## cmake --build build -j 1
## cmake --build build --clean-first -j 1

## executing
## v_01_ref % ./build/vhwTest.out -id 1  (160x60 terminal dimensions)


message(STATUS "Start super-project CMAkeLists.txt")

cmake_minimum_required(VERSION 3.16)

# set the project name and version
set(MAIN_NAME vhwTest)
project(${MAIN_NAME} VERSION 1.0)

set(EXECUTABLE ${PROJECT_NAME}.out )

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)





#enable_language(C ASM)
#set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_STANDARD_REQUIRED ON)
#set(CMAKE_C_EXTENSIONS OFF)

message(STATUS "TOOLCHAIN - ASM:                  ${CMAKE_ASM_COMPILER}")
message(STATUS "TOOLCHAIN - C:                    ${CMAKE_C_COMPILER}"  )
message(STATUS "TOOLCHAIN - C++:                  ${CMAKE_CXX_COMPILER}")


## ******************************************************************
## __________________________________________________________________
## TST/APP CPP FILES Definitions

set(SOURCE_FILES_CPP
    mcuPinPort.cpp        
    mcuPinPort2.cpp        
    mcuPortDef.cpp        
    mcuUSART.cpp          
    mcuUSARTTbl.cpp          
    mcuUSARTManager.cpp

    pphButton.cpp         
    pphLed.cpp            
    pphRely.cpp         
    pphSwitch.cpp         
    pphWired.cpp         
    pphManager.cpp        

    shmMcuPinPort.cpp     
    shmMcuUSART.cpp       
    shmManager.cpp        

    vhwPphTbl_Leds.cpp
    vhwPphTbl_Buttons.cpp
    vhwPphTbl_Mod1.cpp
    vhwPphTbl.cpp

    dtyBaseArray.cpp
    dtyBaseCntnrUnit.cpp
    dtyBaseCntnrUnitX.cpp
    dtyBaseUnit.cpp
    dtyStuf.cpp
    dtyStufX.cpp
    dtyTuiBase.cpp
    dtyTuiGraphic.cpp
    dtyProtocolData.cpp
    dtyUint8.cpp

    tuiGraphicCoord.cpp
    tuiGraphicState.cpp
    tuiGraphicAbstract.cpp
    tuiDrvGraphic.cpp
    tuiGraphicUnit.cpp
    tuiGraphicUnitRoot.cpp
    tuiGraphicUnitWin.cpp
    tuiGraphicUnitBase.cpp
    tuiGraphicAppMain.cpp
    
    tuiUnitAbstract.cpp
    #--- tuiUnitDgtInOut.cpp
    #--- tuiUnitList.cpp
    tuiUnitEbox.cpp
    tuiUnitSet.cpp
    tuiUnitDebug.cpp
    tuiUnitProtocolData.cpp
    tuiUnitCntnrAbstract.cpp
    tuiUnitCntnrList.cpp
    tuiUnitListAbstract.cpp
    tuiUnitListDebug.cpp

    tuiBase.cpp
    tuiBaseAction.cpp
    tuiBaseButton.cpp
    tuiBaseCntnr.cpp
    tuiBaseCntnrX.cpp
    tuiBaseDgtInOut.cpp
    tuiBaseDrawer.cpp
    tuiBaseEbox.cpp
    tuiBaseGraphic.cpp
    tuiBaseLbox.cpp
    tuiBaseLboxX.cpp
    tuiBaseLboxY.cpp
    tuiBaseListElem.cpp
    tuiBaseListUnit.cpp
    tuiBaseListUnitY.cpp
    tuiBaseSubWin.cpp
    tuiBaseWin.cpp
    tuiBaseWinRoot.cpp
    tuiData.cpp
    tuiTextUsart.cpp
    tuiTextUsartX.cpp

    tuiAppUsart.cpp
    tuiAppUSART_1.cpp
    tuiAppPinPort.cpp
    tuiAppBoard.cpp
    tuiAppMain.cpp
    tuiManager.cpp
    tuiManagerApp.cpp

    vhwManager.cpp        
    vhwMain.cpp               
)

add_executable(${EXECUTABLE} 
    ${SOURCE_FILES_CPP}
)

include(wsp/toolchain_compile_option.cmake )
include(wsp/toolchain_link_option.cmake )
