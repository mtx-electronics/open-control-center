/***************************************************************
 * Name:      XBus.cpp
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

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "XBus.h"

/*!
 * XBus constructors
 */

XBus::XBus()
{
	sCon = new Serial();
}

/*!
 * XBus destructor
 */

XBus::~XBus()
{
    sCon->ClosePort();
    delete sCon;
}

/*!
 * Member initialisation
 */

bool XBus::FindDevice(void)
{
    bool found=false;

    for (int loop=0; loop < sCon->GetNumPorts(); loop++)
    {
        if (sCon->OpenPort(sCon->GetNextPort()) != -1)
        {
            WritePacket(0,0x01,0);  //ALive
            if (!ReadPacket())
            {
                found=true;
                break;
            }
            sCon->ClosePort();
        }
    }

    return(found);
}

int XBus::ReadPacket(void)
{
    unsigned char crc=0;
    int loop;

    //TODO: Add timeout
    while (sCon->BytesAvailable() < 4);

    if(sCon->ReadData((char*)headerData,4) != 4)
        return(2);

    for (loop=0; loop < 3; loop++)
        crc+=headerData[loop];

    if (crc != headerData[3])
        return(1);

    if (headerData[2])
    {
        // TODO: Add timeout
        while (sCon->BytesAvailable() != ((int)headerData[2]+1));

        if (sCon->ReadData((char*)packetData,(int)headerData[2]+1) != ((int)headerData[2]+1))
            return(2);

        crc=0;
        for (loop=0; loop < (int)headerData[2]; loop++)
          crc+=packetData[loop];

        // Check possible packet CRC Error
        if (crc != packetData[loop])
          return(1);
    }

    return(0);
}

void XBus::WritePacket(unsigned char type, unsigned char flags, unsigned char dataLength)
{
    unsigned char crc;

    crc=type+flags+dataLength;
    headerData[0]=type;
    headerData[1]=flags;
    headerData[2]=dataLength;
    headerData[3]=crc;
    sCon->WriteData((char*)headerData,4);

    if (dataLength)
    {
        crc=0;
        for (int x=0; x < dataLength; x++)
          crc+=packetData[x];

        packetData[dataLength]=crc;
        sCon->WriteData((char*)packetData,dataLength+1);
    }
}
