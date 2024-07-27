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
 * dtyBaseUnit.cpp
 *
 *  Created on: Jul, 16th 2024
 *      Author: Marco Dau
 */
 
#include <cstdint>

#include "dtyUint8.h"


// ************************************************************ ATTRIBUTE
// +++++++++++++++++++++ Class (Static) attribute
const char*			dtyUint8_t::m_pStringValue				{m_StringValue};
char				dtyUint8_t::m_StringValue[kDigitNum+1];

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ***************************************************************************** CONSTRUCTOR **************
dtyUint8_t::dtyUint8_t(uint8_t* p_pValue) :
         dtyBaseUnit_t   {}
		,g_pValue        {p_pValue   }
{}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ************* END CONSTRUCTOR **********************



// ************************************************************** METHODS
/*
 * This function must be call only after calling
 * vLoadDataStructure()
 */
void	dtyUint8_t::vUpdateInit	(void) {
	*g_pValue = g_tmpValue;
}

/*
 * This function makes parameter modification operative
 */
void	dtyUint8_t::vUpdate			(void) {
	if(m_bTemporValueChanged) {
		*g_pValue = g_tmpValue;
	}
}

// --------------------- Interfaces from uySettingsIfField
void	dtyUint8_t::vInc				(void) {
	(g_tmpValue)++;
	vValueToString();
}

void	dtyUint8_t::vDec				(void) {
	(g_tmpValue)--;
	vValueToString();
}

void	dtyUint8_t::vSelected			(void) {
	if(!m_bTemporValueChanged) {
		g_tmpValue = *g_pValue;
	}
	vValueToString();
}

void	dtyUint8_t::vConfirm			(void) {
	if(!m_bTemporValueChanged) {
		m_bTemporValueChanged = true;

		if(m_bApplyChangesImmediatly) {
			vUpdate();
		}

	}
}

void	dtyUint8_t::vSet			(char* p_str)	{
	p_str += 2;

	if(bStringToValue(p_str)) {
		vConfirm();
	}
}



// --------------------- Subroutine
bool	dtyUint8_t::bStringToValue	(__attribute__((unused)) char* p_str ) {
	return false;
}

void	dtyUint8_t::vValueToString	(void) {
	uint8_t l_value		{g_tmpValue};
	char remandier;

	m_pStringValue = m_StringValue;

	// set null string terminator
	m_StringValue[kDigitNum]	= 0;
	for(uint8_t i=1; i<=kDigitNum; i++) {
		remandier	= static_cast<char>(l_value % 10);
		l_value		= l_value / 10;
		m_StringValue[kDigitNum - i] = static_cast<char>('0' + remandier);
	}
}
