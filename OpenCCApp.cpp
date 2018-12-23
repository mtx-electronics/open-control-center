/***************************************************************
 * Name:      OpenCCApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Salvatore Faro (info@mtx-electronics.com)
 * Created:   2009-09-17
 * Copyright: MTX Electronics (www.mtx-electronics.com)
 * License:   GNU General Public License (GPL version 2)
 *            http://www.fsf.org/licenses/gpl.html
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 **************************************************************/

#include "wx_pch.h"
#include "OpenCCApp.h"

//(*AppHeaders
#include "OpenCCMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(OpenCCApp);

bool OpenCCApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	OpenCCFrame* Frame = new OpenCCFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
