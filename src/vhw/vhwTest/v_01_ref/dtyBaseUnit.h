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
 * dtyBaseUnit.h
 *
 *  Created on: Jul, 23rd 2024
 *      Author: Marco Dau
 */
 
#ifndef DTY_BASE_UNIT_H
#define DTY_BASE_UNIT_H

#include "uyTypesDefs.h"


class dtyBaseUnit_t   {

protected:
	dtyBaseUnit_t(																    );
	dtyBaseUnit_t(bool p_bApplyChangesImmediatly									);
	dtyBaseUnit_t(bool p_bApplyChangesImmediatly		,bool p_bTemporValueChanged	);

	virtual void	vSet		                (char*)	{} // = 0;
	virtual void	vGet		                (void*)	{} // = 0;
	virtual void*	xGet		                (void)	{return nullptr;} // = 0;
	virtual void	vInc		                (void)	{} // = 0;
	virtual void	vDec		                (void)	{} // = 0;
	virtual void	vConfirm	                (void)	{} // = 0;
	virtual void	vSelected	                (void)	{} // = 0;
	virtual void	vUpdateInit	                (void)	{} // = 0;
	virtual void	vSearchFirst                (void)	{} // = 0;
	virtual void	vSearchNext					(void)	{} // = 0;
	virtual void	vSearchPrev					(void)	{} // = 0;
	virtual bool	bSearchLast  				(void)	{return true;} // = 0;
	virtual bool	bDisplayable    			(void)	{return true;};

//	virtual void	vSet		                (char*)	{} // = 0;
//	virtual void	vGet		                (void*)	{} // = 0;
//	virtual void*	xGet		                (void)	{return nullptr;} // = 0;
//	virtual void	vInc		                ()		{} // = 0;
//	virtual void	vDec		                ()		{} // = 0;
//	virtual void	vConfirm	                ()		{} // = 0;
//	virtual void	vSelected	                ()		{} // = 0;
//	virtual void	vUpdateInit	                ()		{} // = 0;
//	virtual bool 	bDisplayable				(void);
//	virtual uint8_t	xGetIndex					(void);

//  static	bool	bUSBSettingNotToBeModified	(char* p_str);

//  static	bool	m_bParameterChanged;
	bool		m_bApplyChangesImmediatly	;
	bool		m_bTemporValueChanged		;


};


#endif 	// DTY_BASE_UNIT_H
