/***************************************************************
 * Name:      XBus.h
 * Purpose:   Code for xBus protocol handling
 * Author:    Faro Salvatore (info@mtx-electronics.com)
 * Created:   2009-09-14
 * Copyright: MTX Electronics (www.mtx-electronics.com)
 * License:   GNU General Public License (GPL version 2)
 *            http://www.fsf.org/licenses/gpl.html
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 **************************************************************/

#ifndef _XBus_H_
#define _XBus_H_

/*!
 * Includes
 */
#include "Serial.h"

/*!
 * Declarations
 */


/*!
 * XBus class declaration
 */

class XBus
{
public:
    /// Constructors
    XBus();

    /// Destructor
    ~XBus();

    bool FindDevice(void);
    int ReadPacket(void);
    void WritePacket(unsigned char type, unsigned char flags, unsigned char dataLength);

    unsigned char packetData[256];

private:
    unsigned char headerData[4];
    Serial *sCon;
};

#endif
