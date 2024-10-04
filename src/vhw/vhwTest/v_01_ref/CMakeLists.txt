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
    pphButton.cpp         
    pphLed.cpp            
    pphRely.cpp         
    pphSwitch.cpp         
    pphWired.cpp         
    ###--- pphUSART.cpp          
    shmMcuPinPort.cpp     
    shmMcuUSART.cpp       
    ###--- mcuPortManager.cpp        
    mcuUSARTManager.cpp          
    pphManager.cpp        
    shmManager.cpp        

    vhwPphTbl_Leds.cpp
    vhwPphTbl_Buttons.cpp
    vhwPphTbl_Mod1.cpp
    vhwPphTbl.cpp

    ##-- utyFrmtUsart.cpp

    ##-- dtyArray.cpp
    dtyBaseArray.cpp
    dtyBaseUnit.cpp
    dtyUint8.cpp
    dtyBaseCntnrUnit.cpp
    dtyBaseCntnrUnitX.cpp
    dtyStuf.cpp
    dtyTuiBase.cpp
    dtyStufX.cpp
    ##-- dtyStringList.cpp

    ##-- tuiGraphicBox.cpp
    
    tuiBaseCntnr.cpp
    tuiBaseCntnrX.cpp
    tuiTextUsart.cpp
    tuiTextUsartX.cpp
    tuiData.cpp

    tuiBaseAction.cpp
    tuiBaseDrawer.cpp

    tuiBaseButton.cpp

    tuiBase.cpp
    tuiBaseListUnit.cpp
    tuiBaseListElem.cpp
    tuiBaseListUnitY.cpp
    tuiBaseDgtInOut.cpp
    tuiBaseEbox.cpp
    tuiBaseLbox.cpp
    tuiBaseLboxY.cpp
    tuiBaseSubWin.cpp
    tuiBaseWin.cpp
    tuiBaseWinRoot.cpp
    
    tuiDrawerBase.cpp
    tuiBaseUnit.cpp
    ##-- tuiBaseWlistUnit.cpp
    ##-- tuiDgtInOut.cpp
    tuiDigitalInOut.cpp
    tuiDigitalInOut2.cpp
    ##-- tuiLbox.cpp
    ##-- tuiWin.cpp
    ##-- tuiWinRoot.cpp

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

################ ----------------

## mcuPinPort.cpp          -> mcuPinPort.h          -> 
## vhwPphMcuPinPortWiredTbl_t.cpp    -> vhwPphMcuPinPortWiredTbl_t.h    -> 
## mcuPortDef.cpp          -> mcuPortDef.h          -> 
## pphLed.cpp              -> pphLed.h              -> 
## pphButton.cpp           -> pphButton.h           -> 
## pphSwitch.cpp           -> pphSwitch.h           -> 
## shmMcuPinPort.cpp       -> shmMcuPinPort.h       -> 
## mcuUSART.cpp            -> mcuUSART.h            -> 
## pphUSART.cpp            -> pphUSART.h            xxxxx
## shmMcuUSART.cpp         -> shmMcuUSART.h         -> 
## vhwManager.cpp          -> vhwManager.h          xxxxx
## mcuManager.cpp          -> mcuManager.h          -> 
## pphManager.cpp          -> pphManager.h          -> 
## shmManager.cpp          -> shmManager.h          -> 
## vhwMain.cpp             -> vhwMain.h             -> 
## 
## 
## 
## 
## 
## Unit         -> vhwUnit.h                
## PinPort      -> mcuDeciveConfig.h        
##                 mcuPortDef.cpp           x
##                 mcuPortDef.h             
##                 vhwPphMcuPinPortWiredTbl_t.cpp     x   
##                 vhwPphMcuPinPortWiredTbl_t.h       
##                 mcuPinPort.cpp,          x
##                 mcuPinPort.h,            
##                 pphButton.cpp            x
##                 pphButton.h              
##                 pphLed.cpp               x
##                 pphLed.h                 
##                 pphSwitch.cpp            x
##                 pphSwitch.h              
##                 shmMcuPinPort.cpp,          x
##                 shmMcuPinPort.h             
## USART        -> mcuUSART.cpp,            x
##                 mcuUSART.h,              
##                 pphUSART.cpp,            x
##                 pphUSART.h               
##                 shmMcuUSART.cpp,            x
##                 shmMcuUSART.h               
## Manager      -> vhwManager.cpp           x
##                 vhwManager.h             
##                 mcuManager.cpp           x
##                 mcuManager.h             
##                 pphManager.cpp           x
##                 pphManager.h             
##                 shmManager.cpp           x
##                 shmManager.h             
## Main         -> vhwmain.cpp              x
##                 
## 
## 