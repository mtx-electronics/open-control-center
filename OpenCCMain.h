/***************************************************************
 * Name:      OpenCCMain.h
 * Purpose:   Defines Application Frame
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

#ifndef OPENCCMAIN_H
#define OPENCCMAIN_H

//(*Headers(OpenCCFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/statusbr.h>
//*)

#include "XBus.h"

class OpenCCFrame: public wxFrame
{
    public:

        OpenCCFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~OpenCCFrame();

    private:

        //(*Handlers(OpenCCFrame)
        void OnMenuItemExitSelected(wxCommandEvent& event);
        void OnMenuItemAboutSelected(wxCommandEvent& event);
        void OnToolBarAboutClicked(wxCommandEvent& event);
        void OnMenuItemConnectSelected(wxCommandEvent& event);
        void OnMenuItemDisconnectSelected(wxCommandEvent& event);
        void OnSliderThresholdCmdScrollThumbTrack(wxScrollEvent& event);
        void OnSliderPowerCmdScrollThumbTrack(wxScrollEvent& event);
        void OnSliderSlopeThresholdCmdScrollThumbTrack(wxScrollEvent& event);
        void OnSliderSlopeCmdScrollThumbTrack(wxScrollEvent& event);
        void OnSliderRampCmdScrollThumbTrack(wxScrollEvent& event);
        void OnMenuItemReceiveSelected(wxCommandEvent& event);
        void OnMenuItemTransmitSelected(wxCommandEvent& event);
        void OnMenuItemEnTrimmerSelected(wxCommandEvent& event);
        void OnMenuItemEnBoxSelected(wxCommandEvent& event);
        void OnMenuItemResetSelected(wxCommandEvent& event);
        void OnToolBarItemReceiveClicked(wxCommandEvent& event);
        void OnToolBarItemTransmitClicked(wxCommandEvent& event);
        void OnTimerMonitorTrigger(wxTimerEvent& event);
        void OnMenuItemNormalMapSelected(wxCommandEvent& event);
        void OnMenuItemFAPMapSelected(wxCommandEvent& event);
        void OnToolBarItemNormalMapClicked(wxCommandEvent& event);
        void OnToolBarItemFAPMapClicked(wxCommandEvent& event);
        void OnMenuItemMonitorSelected(wxCommandEvent& event);
        void OnMenuItemSaveSelected(wxCommandEvent& event);
        void OnMenuItemOpenSelected(wxCommandEvent& event);
        void OnToolBarItemLoadClicked(wxCommandEvent& event);
        void OnToolBarItemSaveClicked(wxCommandEvent& event);
        //*)

        //(*Identifiers(OpenCCFrame)
        static const long ID_STATICBITMAP1;
        static const long idStaticTextThreshold;
        static const long idStaticPower;
        static const long idStaticTextSlopeThreshold;
        static const long idStaticTextSLope;
        static const long idStaticTextRamp;
        static const long idSliderThreshold;
        static const long idSliderPower;
        static const long idSLiderSlopeThreshold;
        static const long idSLiderSlope;
        static const long idSliderRamp;
        static const long idStaticTextThresholdVolt;
        static const long idStaticTextPowerPerc;
        static const long idStaticTextSlopeThresholdVolt;
        static const long idStaticTextSlopePerc;
        static const long idStaticTextRampVolt;
        static const long idGaugeRailIn;
        static const long idStaticTextRailIn;
        static const long idGaugeRailOut;
        static const long idStaticTextRailOut;
        static const long ID_PANEL1;
        static const long idMenuItemOpen;
        static const long idMenuItemSave;
        static const long idMenuItemConnect;
        static const long idMenuItemDisconnect;
        static const long idMenuItemTransmit;
        static const long idMenuItemReceive;
        static const long idMenuItemExit;
        static const long idMenuItemNormalMap;
        static const long idMenuItemFAPMap;
        static const long idMenuItemEnMonitor;
        static const long idMenuItemEnTrimmer;
        static const long idMenuItemEnBox;
        static const long idMenuItemReset;
        static const long idMenuItemAbout;
        static const long idMenuItemRelease;
        static const long idStatusBar;
        static const long idToolBarItemReceive;
        static const long idToolBarItemTransmit;
        static const long idToolBarItemLoad;
        static const long idToolBarItemSave;
        static const long idToolBarItemNormalMap;
        static const long idToolBarItemFAPMap;
        static const long idToolBarAbout;
        static const long idToolBar;
        static const long idTimerMonitor;
        //*)

        //(*Declarations(OpenCCFrame)
        wxMenuItem* MenuItemTransmit;
        wxStaticText* StaticTextThreshold;
        wxTimer TimerMonitor;
        wxStaticText* StaticTextRailOut;
        wxMenuItem* MenuItemMonitor;
        wxMenuItem* MenuItemSave;
        wxSlider* SliderSlope;
        wxMenuItem* MenuItemEnTrimmer;
        wxSlider* SliderPower;
        wxStaticText* StaticTextSlopeThreshold;
        wxToolBarToolBase* ToolBarItemTransmit;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticTextPower;
        wxMenuItem* MenuItemReceive;
        wxStaticText* StaticTextSlopePerc;
        wxToolBarToolBase* ToolBarItemSave;
        wxPanel* Panel1;
        wxSlider* SliderSlopeThreshold;
        wxMenuItem* MenuItemRelease;
        wxToolBarToolBase* ToolBarItemFAPMap;
        wxMenuItem* MenuItemFAPMap;
        wxMenuItem* MenuItemOpen;
        wxToolBarToolBase* ToolBarItemReceive;
        wxMenuItem* MenuItemNormalMap;
        wxStaticText* StaticTextRailIn;
        wxMenuItem* MenuItemEnBox;
        wxStaticText* StaticTextSlopeThresholdVolt;
        wxMenu* MenuMaps;
        wxMenuItem* MenuItemDisconnect;
        wxToolBarToolBase* ToolBarAbout;
        wxStaticText* StaticTextRampVolt;
        wxMenuItem* MenuItemReset;
        wxStaticText* StaticTextPowerPerc;
        wxGauge* GaugeRailOut;
        wxStaticText* StaticTextSlope;
        wxToolBarToolBase* ToolBarItemNormalMap;
        wxToolBarToolBase* ToolBarItemLoad;
        wxGauge* GaugeRailIn;
        wxSlider* SliderThreshold;
        wxStaticText* StaticTextThresholdVolt;
        wxToolBar* ToolBar;
        wxStatusBar* StatusBar;
        wxStaticText* StaticTextRamp;
        wxMenu* MenuOptions;
        wxSlider* SliderRamp;
        //*)

        void UpdateThresholdValue(void);
        void UpdatePowerValue(void);
        void UpdateSlopeThresholdValue(void);
        void UpdateSlopePowerValue(void);
        void UpdateRampValue(void);

        XBus *xBusCon;
        bool connectionStatus;

        int threshold1,power1,slopeThreshold1,slopePower1,ramp1,
            threshold2,power2,slopeThreshold2,slopePower2,ramp2;

        unsigned char mapMode,trimmerEnabled,boxEnabled;

        DECLARE_EVENT_TABLE()
};

#endif // OPENCCMAIN_H
