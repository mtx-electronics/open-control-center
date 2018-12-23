/***************************************************************
 * Name:      OpenCCApp.h
 * Purpose:   Defines Application Class
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

#ifndef OPENCCAPP_H
#define OPENCCAPP_H

#include <wx/app.h>

class OpenCCApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // OPENCCAPP_H
