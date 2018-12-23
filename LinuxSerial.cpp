/***************************************************************
 * Name:      linuxSerial.cpp
 * Purpose:   Code for linux RS232 Serial communications
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

#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

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
    int rep;

    rep = read(fd, data, length);

    return (rep);
}

int Serial::WriteData(char* data, int length)
{
    int rep;

    rep = write(fd, data, length);

    return(rep);
}

int Serial::BytesAvailable(void)
{
    int bytes;

    ioctl(fd, FIONREAD, &bytes);

    return(bytes);
}

int Serial::OpenPort(wxString port)
{
    struct termios sOptions;

    fd = open(port.mb_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd != -1)
    {
        sPort=port;

        tcgetattr(fd, &sOptions);                               // Read current port options

        sOptions.c_cflag = B2400;                               // Set baud rate to 38400
        sOptions.c_cflag |= CS8;                                // Set 8bit data
        sOptions.c_cflag |= CREAD;                              // Enable RXD
        sOptions.c_iflag = IGNPAR | IGNBRK;                     // Ignore parrity errors & break condition
        sOptions.c_cflag |= CLOCAL;

        sOptions.c_oflag = 0;                                   // Set output to RAW mode
        sOptions.c_lflag = 0;                                   // Set input to RAW mode

        sOptions.c_cc[VMIN] = 0;                                // Min. num. of characters to read
        sOptions.c_cc[VTIME] = 1;                               // Time to wait for data (Tenths of second)

        tcsetattr(fd, TCSANOW, &sOptions);                      // Write new port settings
        tcflush(fd, TCOFLUSH);                                  // Flush TXD buffer
        tcflush(fd, TCIFLUSH);                                  // Flush RXD buffer
    }

    return(fd);
}

void Serial::ClosePort(void)
{
    close(fd);
    sPort=_T("");
}

wxString Serial::GetNextPort(void)
{
    wxString port;

    switch(pIndex)
    {
        case(0): port=_T(USB1); break;
        case(1): port=_T(USB2); break;
        case(2): port=_T(USB3); break;
        case(3): port=_T(USB4); break;
        case(4): port=_T(USB5); break;
        case(5): port=_T(USB6); break;
        case(6): port=_T(USB7); break;
        case(7): port=_T(USB8); break;
        case(8): port=_T(COM1); break;
        case(9): port=_T(COM2); break;
        case(10): port=_T(COM3); break;
        case(11): port=_T(COM4); break;
        case(12): port=_T(COM5); break;
        case(13): port=_T(COM6); break;
        case(14): port=_T(COM7); break;
        case(15): port=_T(COM8);
    }

    pIndex++;
    if (pIndex==NUMPORTS) pIndex=0;

    return(port);
}
