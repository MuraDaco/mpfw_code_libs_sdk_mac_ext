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
 * tuiUnitCntnrList.h
 *
 *  Created on: Nov,  5th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_UNIT_CNTNR_LIST_H
#define TUI_UNIT_CNTNR_LIST_H

#include "tuiUnitCntnrAbstract.h"



class tuiUnitCntnrList_t :    public tuiUnitCntnrAbstract_t
{

public:
    tuiUnitCntnrList_t       (const char* p_strName  ,dtyBaseCntnrUnitX_t* p_pCntnr = nullptr  );

protected:
   
    // --------------------- Process section - START
    // bool init                    (tuiGraphicUnit_t* p_this) override; --> implemented in derived class tuiUnitListAbstract_t
    // bool initChildren            (tuiGraphicUnit_t* p_this) override; --> implemented in derived class tuiUnitListAbstract_t
    bool loop                    (tuiGraphicUnit_t* p_this) override;
    bool loopChildren            (tuiGraphicUnit_t* p_this) override;
    void end                     (tuiGraphicUnit_t* p_this) override;
    void endChildren             (tuiGraphicUnit_t* p_this) override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    void clear                  (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this) override;
    void display                (tuiGraphicAbstract_t* p_this, bool p_recursively) override;
    // void displayChildren        (tuiGraphicAbstract_t* p_this, bool p_recursively) override; --> implemented in derived class tuiUnitListAbstract_t
    // void refreshChildren        (tuiGraphicAbstract_t* p_this) override; --> implemented in derived class tuiUnitListAbstract_t
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool select                  (tuiGraphicAbstract_t* p_this) override;
    bool deSelect                (tuiGraphicAbstract_t* p_this) override;
    void eventOn                 (tuiGraphicAbstract_t* p_this) override;
    // bool selectByMouse           (tuiGraphicAbstract_t* p_this) override; --> implemented in derived class tuiUnitListAbstract_t
    // bool clickingChild           (tuiGraphicAbstract_t* p_this) override; --> implemented in derived class tuiUnitListAbstract_t
    // --------------------- State management section - END

    // --------------------- KEY Events handler section - START
	// ..................... KEY Events handler: functions
    // void vEventHndlKey_down      (tuiGraphicAbstract_t* p_this)  override; --> implemented in derived class tuiUnitListAbstract_t
    // void vEventHndlKey_up        (tuiGraphicAbstract_t* p_this)  override; --> implemented in derived class tuiUnitListAbstract_t
    void vEventHndlKey_left     (tuiGraphicAbstract_t* p_this)  override;
    void vEventHndlKey_right    (tuiGraphicAbstract_t* p_this)  override;
    // void vEventHndlKey_enter    (tuiGraphicAbstract_t* p_this)  override;  --> implemented in derived class tuiUnitListAbstract_t
    void vEventHndlKey_home     (tuiGraphicAbstract_t* p_this)  override;
    // --------------------- KEY Events handler section - END


private:

    // --------------------- Generic  Data section - START
    //const char* g_strName;
    // --------------------- Generic  Data section - END

};


#endif 	// TUI_UNIT_CNTNR_LIST_H
