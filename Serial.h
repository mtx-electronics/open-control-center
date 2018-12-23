/***************************************************************
 * Name:      Serial.h
 * Purpose:   Code for RS232 Serial interface handling
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

#ifndef _Serial_H_
#define _Serial_H_

/*!
 * Includes
 */

/*!
 * Declarations
 */

#if defined (WIN32)
    #define COM1    "COM0"
    #define COM2    "COM1"
    #define COM3    "COM2"
    #define COM4    "COM3"
    #define COM5    "COM4"
    #define COM6    "COM5"
    #define COM7    "COM6"
    #define COM8    "COM7"

    #define NUMPORTS    8
#else
    #define USB1    "/dev/ttyUSB0"
    #define USB2    "/dev/ttyUSB1"
    #define USB3    "/dev/ttyUSB2"
    #define USB4    "/dev/ttyUSB3"
    #define USB5    "/dev/ttyUSB4"
    #define USB6    "/dev/ttyUSB5"
    #define USB7    "/dev/ttyUSB6"
    #define USB8    "/dev/ttyUSB7"

    #define COM1    "/dev/ttyS0"
    #define COM2    "/dev/ttyS1"
    #define COM3    "/dev/ttyS2"
    #define COM4    "/dev/ttyS3"
    #define COM5    "/dev/ttyS4"
    #define COM6    "/dev/ttyS5"
    #define COM7    "/dev/ttyS6"
    #define COM8    "/dev/ttyS7"

    #define NUMPORTS    16
#endif

/*!
 * Serial class declaration
 */

class Serial
{
public:
    /// Constructors
    Serial();

    /// Destructor
    ~Serial();

    int ReadData(char* data, int length);
    int WriteData(char* data, int length);
    int BytesAvailable(void);
    int OpenPort(wxString port);
    void ClosePort(void);

    wxString GetPort() const { return sPort; }
    int GetNumPorts() const { return NUMPORTS; }
    wxString GetNextPort(void);

private:
#if defined (WIN32)
    HANDLE hSerial;
#else
    int fd;
#endif

    int pIndex;
    wxString sPort;
};

#endif
