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
 * dtyBaseArray.h
 *
 *  Created on: Sep, 1st 2024
 *      Author: Marco Dau
 *

        - the events are
            - type a character
                - (g_position == (g_length-1))
                    - update g_str[g_position]; <goForW> (increment [g_position]); increment [g_length]; 
                - (g_position <  (g_length-1))
                    - <shiftAhead> the string at the right of the [g_position]; update g_str[g_position]; <goForW> (increment [g_position]); increment [g_length]; 
            - type a comand key
                - up
                    - goToBegin
                - down
                    - goToEnd
                - left
                    - goBackW
                - right
                    - goForW
                - del
                    - (g_position <  (g_length-1))
                        - (<shiftBack> the string at the right of the position (N.B.: [g_position] does not change); decrement [g_length];)
                - backspace
                    - (g_position == (g_length-1))
                        - (<goBackW> (increment [g_position]); decrement [g_length];)
                    - (g_position <  (g_length-1))
                        - (decrement [g_position] & <shiftBack> the string at the right of the [g_position]; decrement [g_length];)
            - mouse events/actions
                - select
                    - start select
                    - end select
                - click on component
        - the parameters are
            - [g_length]:   lunghezza della stringa
            - [g_position]: posizione corrente

 *
 */
 
#ifndef DTY_BASE_ARRAY_H
#define DTY_BASE_ARRAY_H

#include "uyTypesDefs.h"
#include "dtyBuffer.h"


class dtyBaseArray_t   {

public:

    dtyBaseArray_t		(char* p_pAry, uint16_t p_sizeAry);

    bool	ins		                (char p_char);
    void	del		                (void);
    bool	backSpace               (void);
    void    positionBegin           (void);
    void    positionEnd             (void);
    void    shiftAhead              (void);
    void    shiftBack               (void);
    uint16_t positionGet            (void);
    char*   pArrayGet               (void);
    uint16_t lengthGet              (void);


    // display section
    void     initDsplyBox           (uint8_t p_boxW);
    bool     dsplyPositionInc       (void);
    bool     dsplyPositionDec       (void);

    char*    pDsplyStrBeginGet                      (void);
    char*    pDsplyStrPositionGet                   (void);
    char*    pDsplyStrPositionPrevGet               (void);

    uint8_t  sizeDsplyStrFromBeginGet               (void);
    uint8_t  sizeDsplyStrFromPositionGet            (void);
    uint8_t  sizeDsplyStrFromPositionPrevGet        (void);

    uint8_t  beginDsplyStrGet       (void);
    uint8_t  positionDsplyGet       (void);

protected:

	char*    g_pAry ;
    uint16_t g_sizeAry;
    uint16_t g_length;
    uint16_t g_position;                    // 0 <= g_position <= g_length


private:

    bool    positionInc             (void);
    bool    positionDec             (void);

    // display section

    uint16_t g_idDsplyBoxBegin;             // window begin
    uint8_t  g_idDsplyBoxWidth;             // window length = box width
    uint16_t g_idDsplyPositionCursor;       // cursor position 
    uint8_t  g_idDsplyLength;               // string length to display from position to 1) the end of array or 2) to the end of box

    void     dsplyBeginSet          (uint16_t p_begin);
    void     dsplyBeginInc          (void);
    void     dsplyBeginDec          (void);

    void     dsplyCurrentUpd        (uint16_t p_position);


};


#endif 	// DTY_BASE_ARRAY_H
