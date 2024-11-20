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
 * tuiUnitFormattedStringCntnr.h
 *
 *  Created on: Nov, 15th 2024 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiUnitFormattedStringCntnr.h"

#include <stdio.h>

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiUnitFormattedStringCntnr_t::tuiUnitFormattedStringCntnr_t      (void)   :
        tuiUnitAbstract_t       ("-")
        ,g_pString              {nullptr}
    {}

    tuiUnitFormattedStringCntnr_t::tuiUnitFormattedStringCntnr_t      (const char* p_strName   ,dtyString_t* p_pString   )   :
        tuiUnitAbstract_t       (p_strName)
        ,g_pString              {p_pString}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

// --------------------- Process section - START

    // protected:
    bool tuiUnitFormattedStringCntnr_t::init   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
        if(g_pString)   {
            uint16_t l_h;
            
            l_h =   g_pString->getLength() / p_this->getDimW();
            l_h += (g_pString->getLength() % p_this->getDimW()) ? 1 : 0;
            p_this->setDimH(l_h);
            p_this->updBoundY();

            p_this->setEventStatus(false);
        }
        return true;
    }

    bool tuiUnitFormattedStringCntnr_t::initChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
        return true;
    }

    bool tuiUnitFormattedStringCntnr_t::loop   	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
        return true;
    }

    bool tuiUnitFormattedStringCntnr_t::loopChildren           ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {
        return true;
    }

    void tuiUnitFormattedStringCntnr_t::end       	            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

    }

    void tuiUnitFormattedStringCntnr_t::endChildren            ([[maybe_unused]] tuiGraphicUnit_t* p_this)  {

    }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    // protected:
    void tuiUnitFormattedStringCntnr_t::clear     	        (tuiGraphicAbstract_t* p_this)  {
        p_this->frameClear();
    }

    void tuiUnitFormattedStringCntnr_t::display     	    (tuiGraphicAbstract_t* p_this)  {
        if(g_pString)   {
            if(g_pStringInfo)   {
                p_this->stringPrint(markerToColor(g_pStringInfo->g_marker), g_pStringInfo->g_select, g_pString->getString(), g_pString->getLength());    
            } else {
                p_this->stringPrint2(markerToColor(kMarker_t::defaultX), false, g_pString->getString(), g_pString->getLength());
            }
        }
    }

    void tuiUnitFormattedStringCntnr_t::display     	    (tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
        display(p_this);
    }

    void tuiUnitFormattedStringCntnr_t::displayChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this, [[maybe_unused]] bool p_recursively)  {
    }

    void tuiUnitFormattedStringCntnr_t::refreshChildren    ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    }
    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    // protected:
    bool tuiUnitFormattedStringCntnr_t::select     	        (tuiGraphicAbstract_t* p_this)  {
        bool l_result = false;

        if(g_pString)   {
            if(g_pStringInfo)   {
                l_result = true;
                p_this->stringPrint( markerToColor( g_pStringInfo->g_marker), 
                                                    g_pStringInfo->g_select, 
                                                    g_pString->getString(), 
                                                    g_pString->getLength()
                                                );
            } else {
                l_result = p_this->stringPrint2(    tuiMode_t::select, 
                                                    markerToColor(kMarker_t::defaultX), 
                                                    true, 
                                                    g_pString->getString(), 
                                                    g_pString->getLength()
                                                );
            }
        }

        return l_result;
    }

    bool tuiUnitFormattedStringCntnr_t::deSelect   	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
        bool l_result = false;

        if(g_pString)   {
            if(g_pStringInfo)   {
                l_result = true;
                p_this->stringPrint( markerToColor( g_pStringInfo->g_marker), 
                                                    g_pStringInfo->g_select, 
                                                    g_pString->getString(), 
                                                    g_pString->getLength()
                                                );
            } else {
                l_result = p_this->stringPrint2(    tuiMode_t::deselect, 
                                                    markerToColor(kMarker_t::defaultX), 
                                                    false, 
                                                    g_pString->getString(), 
                                                    g_pString->getLength()
                                                );
            }
        }

        return l_result;
    }

    void tuiUnitFormattedStringCntnr_t::eventOn    	        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
    }

    bool tuiUnitFormattedStringCntnr_t::selectByMouse        ([[maybe_unused]] tuiGraphicAbstract_t* p_this)  {
        p_this->deselectBackNselect();
        p_this->parentDeselectBackNeventOn();
        return true;
    }

    bool tuiUnitFormattedStringCntnr_t::clickingChild        ([[maybe_unused]] tuiGraphicAbstract_t* p_this) {
        return false;
    }

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STREAM CONTAINER *****

    // public:
    void tuiUnitFormattedStringCntnr_t::cntnrInit          (dtyString_t* p_pString, dtyStringInfo_t* p_pStringInfo)  {
        g_pString       = p_pString;
        g_pStringInfo   = p_pStringInfo;
    }

    void tuiUnitFormattedStringCntnr_t::cntnrUpdParams          (tuiGraphicAbstract_t* p_this)  {
        uint16_t l_h;
        l_h =   g_pString->getLength() / p_this->getDimW();
        l_h += (g_pString->getLength() % p_this->getDimW()) ? 1 : 0;
        p_this->setDimH(l_h);
        p_this->updBoundY();
    }


    // section end   **** STREAM CONTAINER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DATA MANAGEMENT *****

    // private:
    uint8_t tuiUnitFormattedStringCntnr_t::markerToColor        (kMarker_t p_marker)        {
        uint8_t l_result = 0;

        switch (p_marker)   {
            case kMarker_t::defaultX:
                l_result = NCURS_COLOR_YELLOW;
                break;
            case kMarker_t::deviceRx:
                l_result = NCURS_COLOR_MAGENTA;
                break;
            case kMarker_t::deviceTx:
                l_result = NCURS_COLOR_CYAN;
                break;
            default:
                l_result = NCURS_COLOR_WHITE;
                break;
        }

        return l_result;
    }

    // section end   **** DATA MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG *****

    //public:
    void tuiUnitFormattedStringCntnr_t::displayDebug            (tuiGraphicAbstract_t* p_this, uint32_t p_dbgParam1, uint32_t p_dbgParam2)      {
        if(g_pString)   {
            p_this->debugPrint(p_dbgParam1, p_dbgParam2, g_pString->getString());
        }
    }

    // section end   **** DEBUG *****
    // ****************************************************
    // --------------------------
