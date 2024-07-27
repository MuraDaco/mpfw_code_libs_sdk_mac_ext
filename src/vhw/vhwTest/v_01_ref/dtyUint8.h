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
 * dtyUint8.h
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
#ifndef DTY_UINT8_H
#define DTY_UINT8_H

#include "dtyBaseUnit.h"

class dtyUint8_t : public dtyBaseUnit_t  {

public:
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ***************************************************************************** CONSTRUCTOR **************
	dtyUint8_t(uint8_t* p_pValue);
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ************* END CONSTRUCTOR **********************

    // ************************************************************ CONSTANTS
	enum kDigit {
		kDigitNum = 3
	};

    // ************************************************************ ATTRIBUTE
	// +++++++++++++++++++++ Instance (non Static) attribute
	uint8_t*    g_pValue					;
	uint8_t	    g_tmpValue					;

	// +++++++++++++++++++++ Class (Static) attribute

	static const char*		m_pStringValue;
protected:
	static char				m_StringValue[kDigitNum+1];

    // ************************************************************** METHODS

	// --------------------- Interfaces from uySettingsIfField
public:
	void	vUpdate				(void);

	virtual void	vSet		                (char* p_str)	override;
	//virtual void	vGet		                (void*)	{} // = 0;
	//virtual void*	xGet		                (void)	{return nullptr;} // = 0;
	virtual void	vInc		                (void)	        override;
	virtual void	vDec		                (void)	        override;
	virtual void	vConfirm	                (void)	        override;
	virtual void	vSelected	                (void)	        override;
	virtual void	vUpdateInit	                (void)	        override;
	// virtual void	vSearchFirst                (void)	{} // = 0;
	// virtual void	vSearchNext					(void)	{} // = 0;
	// virtual void	vSearchPrev					(void)	{} // = 0;
	// virtual bool	bSearchLast  				(void)	{return true;} // = 0;
	// virtual bool	bDisplayable    			(void)	{return true;};

	// --------------------- Subroutine
	__attribute__((const)) bool	bStringToValue			(char* p_str );
	void	vValueToString			(void);


};


#endif 	// DTY_UINT8_H
