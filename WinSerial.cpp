/***************************************************************
 * Name:      WinSerial.cpp
 * Purpose:   Code for Win32 RS232 Serial communications
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

#include <windows.h>

#include "Serial.h"

/*!
 * Serial constructors
 */

Serial::Serial()
{
    sPort=_T("");
    pIndex=0;
}

/*!
 * Serial destructor
 */

Serial::~Serial()
{
}

/*!
 * Member initialisation
 */

int Serial::ReadData(char* data, int length)
{
    DWORD dwBytesRead = 0;

    if(!ReadFile(hSerial, data, (DWORD)length, &dwBytesRead, NULL))
        dwBytesRead=0;

    return ((int)dwBytesRead);
}

int Serial::WriteData(char* data, int length)
{
    DWORD dwBytesRead = 0;

    if(!WriteFile(hSerial, data, (DWORD)length, &dwBytesRead, NULL))
        dwBytesRead=0;

    return ((int)dwBytesRead);
}

int Serial::BytesAvailable(void)
{
    int bytes=0;

    struct _COMSTAT status;
    unsigned long   etat;

    ClearCommError(hSerial, &etat, &status);
    bytes = status.cbInQue;

    return(bytes);
}

int Serial::OpenPort(wxString port)
{
    hSerial = CreateFile(port,
                         GENERIC_READ | GENERIC_WRITE,
                         0,
                         0,
                         OPEN_EXISTING,
                         FILE_ATTRIBUTE_NORMAL,
                         0);

    if(hSerial==INVALID_HANDLE_VALUE)
        return(-1);

    DCB config;

    // Get current configuration of serial communication port.
    if (GetCommState(hSerial,&config) == 0)
        return(-1);

    // Assign user parameter.
    config.ByteSize = 8;            // Byte of the Data.
    config.StopBits = ONESTOPBIT;   // Use one bit for stopbit.
    config.Parity = NOPARITY;       // No parity bit
    config.BaudRate = CBR_2400;     // Buadrate 38400 bit/sec

    // Set current configuration of serial communication port.
    if (SetCommState(hSerial,&config) == 0)
        return(-1);

    COMMTIMEOUTS timeouts={0};

    timeouts.ReadIntervalTimeout=50;
    timeouts.ReadTotalTimeoutConstant=2000;
    timeouts.ReadTotalTimeoutMultiplier=10;

    timeouts.WriteTotalTimeoutConstant=2000;
    timeouts.WriteTotalTimeoutMultiplier=10;
    if(!SetCommTimeouts(hSerial, &timeouts))
        return(-1);

    return(0);
}

void Serial::ClosePort(void)
{
    CloseHandle(hSerial);
    sPort=_T("");
}

wxString Serial::GetNextPort(void)
{
    wxString port;

    switch(pIndex)
    {
        case(0): port=_T(COM1); break;
        case(1): port=_T(COM2); break;
        case(2): port=_T(COM3); break;
        case(3): port=_T(COM4); break;
        case(4): port=_T(COM5); break;
        case(5): port=_T(COM6); break;
        case(6): port=_T(COM7); break;
        case(7): port=_T(COM8);
    }

    pIndex++;
    if (pIndex==NUMPORTS) pIndex=0;

    return(port);
}
