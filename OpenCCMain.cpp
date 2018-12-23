/***************************************************************
 * Name:      OpenCCMain.cpp
 * Purpose:   Code for Application Frame
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
#include "OpenCCMain.h"
#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include "AboutBoxDialog.h"

//(*InternalHeaders(OpenCCFrame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(OpenCCFrame)
const long OpenCCFrame::ID_STATICBITMAP1 = wxNewId();
const long OpenCCFrame::idStaticTextThreshold = wxNewId();
const long OpenCCFrame::idStaticPower = wxNewId();
const long OpenCCFrame::idStaticTextSlopeThreshold = wxNewId();
const long OpenCCFrame::idStaticTextSLope = wxNewId();
const long OpenCCFrame::idStaticTextRamp = wxNewId();
const long OpenCCFrame::idSliderThreshold = wxNewId();
const long OpenCCFrame::idSliderPower = wxNewId();
const long OpenCCFrame::idSLiderSlopeThreshold = wxNewId();
const long OpenCCFrame::idSLiderSlope = wxNewId();
const long OpenCCFrame::idSliderRamp = wxNewId();
const long OpenCCFrame::idStaticTextThresholdVolt = wxNewId();
const long OpenCCFrame::idStaticTextPowerPerc = wxNewId();
const long OpenCCFrame::idStaticTextSlopeThresholdVolt = wxNewId();
const long OpenCCFrame::idStaticTextSlopePerc = wxNewId();
const long OpenCCFrame::idStaticTextRampVolt = wxNewId();
const long OpenCCFrame::idGaugeRailIn = wxNewId();
const long OpenCCFrame::idStaticTextRailIn = wxNewId();
const long OpenCCFrame::idGaugeRailOut = wxNewId();
const long OpenCCFrame::idStaticTextRailOut = wxNewId();
const long OpenCCFrame::ID_PANEL1 = wxNewId();
const long OpenCCFrame::idMenuItemOpen = wxNewId();
const long OpenCCFrame::idMenuItemSave = wxNewId();
const long OpenCCFrame::idMenuItemConnect = wxNewId();
const long OpenCCFrame::idMenuItemDisconnect = wxNewId();
const long OpenCCFrame::idMenuItemTransmit = wxNewId();
const long OpenCCFrame::idMenuItemReceive = wxNewId();
const long OpenCCFrame::idMenuItemExit = wxNewId();
const long OpenCCFrame::idMenuItemNormalMap = wxNewId();
const long OpenCCFrame::idMenuItemFAPMap = wxNewId();
const long OpenCCFrame::idMenuItemEnMonitor = wxNewId();
const long OpenCCFrame::idMenuItemEnTrimmer = wxNewId();
const long OpenCCFrame::idMenuItemEnBox = wxNewId();
const long OpenCCFrame::idMenuItemReset = wxNewId();
const long OpenCCFrame::idMenuItemAbout = wxNewId();
const long OpenCCFrame::idMenuItemRelease = wxNewId();
const long OpenCCFrame::idStatusBar = wxNewId();
const long OpenCCFrame::idToolBarItemReceive = wxNewId();
const long OpenCCFrame::idToolBarItemTransmit = wxNewId();
const long OpenCCFrame::idToolBarItemLoad = wxNewId();
const long OpenCCFrame::idToolBarItemSave = wxNewId();
const long OpenCCFrame::idToolBarItemNormalMap = wxNewId();
const long OpenCCFrame::idToolBarItemFAPMap = wxNewId();
const long OpenCCFrame::idToolBarAbout = wxNewId();
const long OpenCCFrame::idToolBar = wxNewId();
const long OpenCCFrame::idTimerMonitor = wxNewId();
//*)

BEGIN_EVENT_TABLE(OpenCCFrame,wxFrame)
    //(*EventTable(OpenCCFrame)
    //*)
END_EVENT_TABLE()

OpenCCFrame::OpenCCFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(OpenCCFrame)
    wxMenuItem* MenuItemAbout;
    wxMenuItem* MenuItemConnect;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxMenuItem* MenuItemExit;
    wxMenu* MenuInfo;
    wxMenu* MenuFile;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenuBar* MenuBar;

    Create(parent, wxID_ANY, _("Open Control Center"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(567,344));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("Images/icon.png"))));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(561,344), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("Images/header.jpg"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer1 = new wxFlexGridSizer(3, 5, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer1->AddGrowableCol(2);
    FlexGridSizer1->AddGrowableCol(3);
    FlexGridSizer1->AddGrowableCol(4);
    FlexGridSizer1->AddGrowableRow(1);
    StaticTextThreshold = new wxStaticText(Panel1, idStaticTextThreshold, _("Threshold"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextThreshold"));
    FlexGridSizer1->Add(StaticTextThreshold, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextPower = new wxStaticText(Panel1, idStaticPower, _("Power"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticPower"));
    FlexGridSizer1->Add(StaticTextPower, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextSlopeThreshold = new wxStaticText(Panel1, idStaticTextSlopeThreshold, _("Slope\nThreshold"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextSlopeThreshold"));
    FlexGridSizer1->Add(StaticTextSlopeThreshold, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextSlope = new wxStaticText(Panel1, idStaticTextSLope, _("Slope"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextSLope"));
    FlexGridSizer1->Add(StaticTextSlope, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextRamp = new wxStaticText(Panel1, idStaticTextRamp, _("Ramp"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextRamp"));
    FlexGridSizer1->Add(StaticTextRamp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SliderThreshold = new wxSlider(Panel1, idSliderThreshold, 0, 0, 4095, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("idSliderThreshold"));
    SliderThreshold->SetToolTip(_("Set activation point"));
    SliderThreshold->SetHelpText(_("Set activation point"));
    FlexGridSizer1->Add(SliderThreshold, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SliderPower = new wxSlider(Panel1, idSliderPower, 0, 0, 1228, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("idSliderPower"));
    SliderPower->SetToolTip(_("Set max power to increment"));
    SliderPower->SetHelpText(_("Set max power to increment"));
    FlexGridSizer1->Add(SliderPower, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SliderSlopeThreshold = new wxSlider(Panel1, idSLiderSlopeThreshold, 0, 0, 4095, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("idSLiderSlopeThreshold"));
    SliderSlopeThreshold->SetToolTip(_("Set power reduction start point"));
    SliderSlopeThreshold->SetHelpText(_("Set power reduction start point"));
    FlexGridSizer1->Add(SliderSlopeThreshold, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SliderSlope = new wxSlider(Panel1, idSLiderSlope, 0, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("idSLiderSlope"));
    SliderSlope->SetToolTip(_("Set max power reduction percentage"));
    SliderSlope->SetHelpText(_("Set max power reduction percentage"));
    FlexGridSizer1->Add(SliderSlope, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SliderRamp = new wxSlider(Panel1, idSliderRamp, 0, 0, 2048, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("idSliderRamp"));
    SliderRamp->SetToolTip(_("Set power increase speed"));
    SliderRamp->SetHelpText(_("Set power increase speed"));
    FlexGridSizer1->Add(SliderRamp, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextThresholdVolt = new wxStaticText(Panel1, idStaticTextThresholdVolt, _("0V"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextThresholdVolt"));
    FlexGridSizer1->Add(StaticTextThresholdVolt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextPowerPerc = new wxStaticText(Panel1, idStaticTextPowerPerc, _("0%"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextPowerPerc"));
    FlexGridSizer1->Add(StaticTextPowerPerc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextSlopeThresholdVolt = new wxStaticText(Panel1, idStaticTextSlopeThresholdVolt, _("0V"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextSlopeThresholdVolt"));
    FlexGridSizer1->Add(StaticTextSlopeThresholdVolt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextSlopePerc = new wxStaticText(Panel1, idStaticTextSlopePerc, _("0%"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextSlopePerc"));
    FlexGridSizer1->Add(StaticTextSlopePerc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextRampVolt = new wxStaticText(Panel1, idStaticTextRampVolt, _("0V"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextRampVolt"));
    FlexGridSizer1->Add(StaticTextRampVolt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Monitor"));
    FlexGridSizer2 = new wxFlexGridSizer(4, 1, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    GaugeRailIn = new wxGauge(Panel1, idGaugeRailIn, 4095, wxDefaultPosition, wxSize(295,28), wxGA_SMOOTH, wxDefaultValidator, _T("idGaugeRailIn"));
    FlexGridSizer2->Add(GaugeRailIn, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextRailIn = new wxStaticText(Panel1, idStaticTextRailIn, _("Rail In: 0V"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextRailIn"));
    FlexGridSizer2->Add(StaticTextRailIn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GaugeRailOut = new wxGauge(Panel1, idGaugeRailOut, 4095, wxDefaultPosition, wxDefaultSize, wxGA_SMOOTH, wxDefaultValidator, _T("idGaugeRailOut"));
    FlexGridSizer2->Add(GaugeRailOut, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextRailOut = new wxStaticText(Panel1, idStaticTextRailOut, _("Rail Out: 0V"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("idStaticTextRailOut"));
    FlexGridSizer2->Add(StaticTextRailOut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer3->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar = new wxMenuBar();
    MenuFile = new wxMenu();
    MenuItemOpen = new wxMenuItem(MenuFile, idMenuItemOpen, _("Open"), _("Load map from file"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemOpen);
    MenuItemSave = new wxMenuItem(MenuFile, idMenuItemSave, _("Save"), _("Save map to file"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemSave);
    MenuFile->AppendSeparator();
    MenuItemConnect = new wxMenuItem(MenuFile, idMenuItemConnect, _("Connect"), _("Connect to tuning box"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemConnect);
    MenuItemDisconnect = new wxMenuItem(MenuFile, idMenuItemDisconnect, _("Disconnect"), _("Disconnect tuning box"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemDisconnect);
    MenuItemTransmit = new wxMenuItem(MenuFile, idMenuItemTransmit, _("Transmit"), _("Transmit map to tuning box"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemTransmit);
    MenuItemReceive = new wxMenuItem(MenuFile, idMenuItemReceive, _("Receive"), _("Receive map from tuning box"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemReceive);
    MenuFile->AppendSeparator();
    MenuItemExit = new wxMenuItem(MenuFile, idMenuItemExit, _("Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    MenuFile->Append(MenuItemExit);
    MenuBar->Append(MenuFile, _("&File"));
    MenuMaps = new wxMenu();
    MenuItemNormalMap = new wxMenuItem(MenuMaps, idMenuItemNormalMap, _("Normal (Map 1)"), _("Select Normal (Map 1)"), wxITEM_RADIO);
    MenuMaps->Append(MenuItemNormalMap);
    MenuItemFAPMap = new wxMenuItem(MenuMaps, idMenuItemFAPMap, _("FAP (Map 2)"), _("Select FAP (Map 2)"), wxITEM_RADIO);
    MenuMaps->Append(MenuItemFAPMap);
    MenuBar->Append(MenuMaps, _("&Maps"));
    MenuOptions = new wxMenu();
    MenuItemMonitor = new wxMenuItem(MenuOptions, idMenuItemEnMonitor, _("Enable Monitor"), _("Enable/Disable rail monitor"), wxITEM_CHECK);
    MenuOptions->Append(MenuItemMonitor);
    MenuItemEnTrimmer = new wxMenuItem(MenuOptions, idMenuItemEnTrimmer, _("Enable Trimmer"), _("Enable/Disable tuning box trimmer"), wxITEM_CHECK);
    MenuOptions->Append(MenuItemEnTrimmer);
    MenuItemEnBox = new wxMenuItem(MenuOptions, idMenuItemEnBox, _("Enable Tuning Box"), _("Enable/Disable tuning box"), wxITEM_CHECK);
    MenuOptions->Append(MenuItemEnBox);
    MenuItemReset = new wxMenuItem(MenuOptions, idMenuItemReset, _("Reset Tuning Box"), _("Reset tuning box to defaults"), wxITEM_NORMAL);
    MenuOptions->Append(MenuItemReset);
    MenuBar->Append(MenuOptions, _("&Options"));
    MenuInfo = new wxMenu();
    MenuItemAbout = new wxMenuItem(MenuInfo, idMenuItemAbout, _("About...\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuInfo->Append(MenuItemAbout);
    MenuItemRelease = new wxMenuItem(MenuInfo, idMenuItemRelease, _("Release History"), _("Show release information"), wxITEM_NORMAL);
    MenuInfo->Append(MenuItemRelease);
    MenuItemRelease->Enable(false);
    MenuBar->Append(MenuInfo, _("&Information"));
    SetMenuBar(MenuBar);
    StatusBar = new wxStatusBar(this, idStatusBar, 0, _T("idStatusBar"));
    int __wxStatusBarWidths_1[5] = { 250, 100, 100, -10, 110 };
    int __wxStatusBarStyles_1[5] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    StatusBar->SetFieldsCount(5,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(5,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    ToolBar = new wxToolBar(this, idToolBar, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("idToolBar"));
    ToolBarItemReceive = ToolBar->AddTool(idToolBarItemReceive, _("Receive"), wxBitmap(wxImage(_T("Images/receive.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Receive map from tuning box"));
    ToolBarItemTransmit = ToolBar->AddTool(idToolBarItemTransmit, _("Transmit"), wxBitmap(wxImage(_T("Images/transmit.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Transmit map to tuning box"));
    ToolBarItemLoad = ToolBar->AddTool(idToolBarItemLoad, _("Load"), wxBitmap(wxImage(_T("Images/load.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Load map from file"));
    ToolBarItemSave = ToolBar->AddTool(idToolBarItemSave, _("Save"), wxBitmap(wxImage(_T("Images/save.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Save map to file"));
    ToolBarItemNormalMap = ToolBar->AddTool(idToolBarItemNormalMap, _("Normal Map"), wxBitmap(wxImage(_T("Images/map1.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Select Normal (Map 1)"));
    ToolBarItemFAPMap = ToolBar->AddTool(idToolBarItemFAPMap, _("FAP Map"), wxBitmap(wxImage(_T("Images/map2.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Select FAP (Map 2)"));
    ToolBarAbout = ToolBar->AddTool(idToolBarAbout, _("About"), wxBitmap(wxImage(_T("Images/about.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("About..."));
    ToolBar->Realize();
    SetToolBar(ToolBar);
    TimerMonitor.SetOwner(this, idTimerMonitor);
    TimerMonitor.Start(1000, false);
    BoxSizer1->SetSizeHints(this);

    Connect(idSliderThreshold,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&OpenCCFrame::OnSliderThresholdCmdScrollThumbTrack);
    Connect(idSliderPower,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&OpenCCFrame::OnSliderPowerCmdScrollThumbTrack);
    Connect(idSLiderSlopeThreshold,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&OpenCCFrame::OnSliderSlopeThresholdCmdScrollThumbTrack);
    Connect(idSLiderSlope,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&OpenCCFrame::OnSliderSlopeCmdScrollThumbTrack);
    Connect(idSliderRamp,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&OpenCCFrame::OnSliderRampCmdScrollThumbTrack);
    Connect(idMenuItemOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemOpenSelected);
    Connect(idMenuItemSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemSaveSelected);
    Connect(idMenuItemConnect,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemConnectSelected);
    Connect(idMenuItemDisconnect,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemDisconnectSelected);
    Connect(idMenuItemTransmit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemTransmitSelected);
    Connect(idMenuItemReceive,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemReceiveSelected);
    Connect(idMenuItemExit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemExitSelected);
    Connect(idMenuItemNormalMap,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemNormalMapSelected);
    Connect(idMenuItemFAPMap,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemFAPMapSelected);
    Connect(idMenuItemEnMonitor,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemMonitorSelected);
    Connect(idMenuItemEnTrimmer,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemEnTrimmerSelected);
    Connect(idMenuItemEnBox,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemEnBoxSelected);
    Connect(idMenuItemReset,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemResetSelected);
    Connect(idMenuItemAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OpenCCFrame::OnMenuItemAboutSelected);
    Connect(idToolBarItemReceive,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarItemReceiveClicked);
    Connect(idToolBarItemTransmit,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarItemTransmitClicked);
    Connect(idToolBarItemLoad,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarItemLoadClicked);
    Connect(idToolBarItemSave,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarItemSaveClicked);
    Connect(idToolBarItemNormalMap,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarItemNormalMapClicked);
    Connect(idToolBarItemFAPMap,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarItemFAPMapClicked);
    Connect(idToolBarAbout,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&OpenCCFrame::OnToolBarAboutClicked);
    Connect(idTimerMonitor,wxEVT_TIMER,(wxObjectEventFunction)&OpenCCFrame::OnTimerMonitorTrigger);
    //*)

    connectionStatus=false;

    StatusBar->SetStatusText(_("No Interface"),1);
    StatusBar->SetStatusText(_T(""),2);
    StatusBar->SetStatusText(_("Ready."),3);
    StatusBar->SetStatusText(_T(""),4);
}

OpenCCFrame::~OpenCCFrame()
{
    //(*Destroy(OpenCCFrame)
    //*)
}

// Custom functions -----------------------------------------------------------

void OpenCCFrame::UpdateThresholdValue(void)
{
    float fThreshold=(float)SliderThreshold->GetValue() * 0.00122;

    wxString strNumDigits = wxString::Format(_T("%%0.%df"),2);
    StaticTextThresholdVolt->SetLabel(wxString::Format (strNumDigits, fThreshold) + _T("V"));
}

void OpenCCFrame::UpdatePowerValue(void)
{
    float fPower=(float)SliderPower->GetValue() / 4095 * 100;

    wxString strNumDigits = wxString::Format(_T("%%0.%df"),1);
    StaticTextPowerPerc->SetLabel(wxString::Format (strNumDigits, fPower) + _T("%"));
}

void OpenCCFrame::UpdateSlopeThresholdValue(void)
{
    float fSlopeThreshold=(float)SliderSlopeThreshold->GetValue() * 0.00122;

    wxString strNumDigits = wxString::Format(_T("%%0.%df"),2);
    StaticTextSlopeThresholdVolt->SetLabel(wxString::Format (strNumDigits, fSlopeThreshold) + _T("V"));
}

void OpenCCFrame::UpdateSlopePowerValue(void)
{
    float fSlopePower=(float)SliderSlope->GetValue() / 4095 * 100;

    wxString strNumDigits = wxString::Format(_T("%%0.%df"),1);
    StaticTextSlopePerc->SetLabel(wxString::Format (strNumDigits, fSlopePower) + _T("%"));
}

void OpenCCFrame::UpdateRampValue(void)
{
    float fRamp=(float)SliderRamp->GetValue() * 0.00122;

    wxString strNumDigits = wxString::Format(_T("%%0.%df"),2);
    StaticTextRampVolt->SetLabel(wxString::Format (strNumDigits, fRamp) + _T("V"));
}

// Menubar events -------------------------------------------------------------

void OpenCCFrame::OnMenuItemOpenSelected(wxCommandEvent& event)
{
    wxString sValue;

    wxFileDialog *FileDialog = new wxFileDialog(this, _("Select MAP to Load"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    if (FileDialog->ShowModal() == wxID_CANCEL)
    {
        delete FileDialog;
        return;
    }

	wxTextFile txt(FileDialog->GetFilename());

    delete FileDialog;

	if (!txt.Exists ())
    {
        StatusBar->SetStatusText(_("File does not exist."),3);
        return;
    }

	if (txt.Open ())
	{
        sValue = txt.GetFirstLine();
        threshold1 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        power1 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        slopeThreshold1 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        slopePower1 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        ramp1 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        threshold2 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        power2 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        slopeThreshold2 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        slopePower2 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        ramp2 = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        mapMode = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        trimmerEnabled = wxAtoi(sValue);

        sValue = txt.GetNextLine();
        boxEnabled = wxAtoi(sValue);

        if (!txt.Close())
        {
            StatusBar->SetStatusText(_("Error closing file."),3);
            return;
        }

        if (trimmerEnabled)
        {
            MenuItemEnTrimmer->Check(true);
            StaticTextPower->SetLabel(_("Maximum\nPower"));
        }
        else
        {
            MenuItemEnTrimmer->Check(false);
            StaticTextPower->SetLabel(_("Power"));
        }

        if (boxEnabled)
            MenuItemEnBox->Check(true);
        else
            MenuItemEnBox->Check(false);

        if (mapMode==1)
        {
            SliderThreshold->SetValue(threshold1);
            SliderPower->SetValue(power1);
            SliderSlopeThreshold->SetValue(slopeThreshold1);
            SliderSlope->SetValue(slopePower1);
            SliderRamp->SetValue(ramp1);

            StatusBar->SetStatusText(_("Map 1 (Normal)"),4);
            MenuItemNormalMap->Check(true);
        }
        else
        {
            SliderThreshold->SetValue(threshold2);
            SliderPower->SetValue(power2);
            SliderSlopeThreshold->SetValue(slopeThreshold2);
            SliderSlope->SetValue(slopePower2);
            SliderRamp->SetValue(ramp2);

            StatusBar->SetStatusText(_("Map 2 (FAP)"),4);
            MenuItemFAPMap->Check(true);
        }

        UpdateThresholdValue();
        UpdatePowerValue();
        UpdateSlopeThresholdValue();
        UpdateSlopePowerValue();
        UpdateRampValue();

        StatusBar->SetStatusText(_("Ready."),3);
	}
    else
        StatusBar->SetStatusText(_("Error opening file."),3);

}

void OpenCCFrame::OnMenuItemSaveSelected(wxCommandEvent& event)
{
    wxFileDialog *FileDialog = new wxFileDialog(this, _("Select Filename of MAP to Save"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    if (FileDialog->ShowModal() == wxID_CANCEL)
    {
        delete FileDialog;
        return;
    }

	wxTextFile txt(FileDialog->GetFilename());

    delete FileDialog;

    if (!txt.Create())
    {
        StatusBar->SetStatusText(_("Error creating file."),3);
        return;
    }

	txt.AddLine (wxString::Format (_T("%d"), threshold1));
	txt.AddLine (wxString::Format (_T("%d"), power1));
	txt.AddLine (wxString::Format (_T("%d"), slopeThreshold1));
	txt.AddLine (wxString::Format (_T("%d"), slopePower1));
	txt.AddLine (wxString::Format (_T("%d"), ramp1));
	txt.AddLine (wxString::Format (_T("%d"), threshold2));
	txt.AddLine (wxString::Format (_T("%d"), power2));
	txt.AddLine (wxString::Format (_T("%d"), slopeThreshold2));
	txt.AddLine (wxString::Format (_T("%d"), slopePower2));
	txt.AddLine (wxString::Format (_T("%d"), ramp2));
	txt.AddLine (wxString::Format (_T("%d"), mapMode));
	txt.AddLine (wxString::Format (_T("%d"), trimmerEnabled));
	txt.AddLine (wxString::Format (_T("%d"), boxEnabled));

	if (!txt.Write())
    {
        StatusBar->SetStatusText(_("Error writing file."),3);
        return;
    }

	if (!txt.Close())
    {
        StatusBar->SetStatusText(_("Error closing file."),3);
        return;
    }

    StatusBar->SetStatusText(_("File saved."),3);
}

void OpenCCFrame::OnMenuItemConnectSelected(wxCommandEvent& event)
{
    if (connectionStatus)
    {
        StatusBar->SetStatusText(_("Already connected, command aborted."),3);
        return;
    }

    xBusCon = new XBus();

    StatusBar->SetStatusText(_("Searching for interface..."),3);

    if (xBusCon->FindDevice())
    {
        // Get device serial number
        xBusCon->WritePacket(5,0x01,0);
        if (!xBusCon->ReadPacket())
        {
            xBusCon->packetData[8]=0;
            wxString string((char*)xBusCon->packetData, wxConvUTF8);

            StatusBar->SetStatusText(string,2);
        }
        else
            StatusBar->SetStatusText(_("No S/N"),2);

        // Update statusbar
        StatusBar->SetStatusText(_("Connected"),1);
        StatusBar->SetStatusText(_("Interface found."),3);

        // Update connection status
        connectionStatus=true;
    }
    else
    {
        StatusBar->SetStatusText(_("Error: Interface not found."),3);
        delete xBusCon;
    }
}

void OpenCCFrame::OnMenuItemDisconnectSelected(wxCommandEvent& event)
{
    if (connectionStatus)
    {
        connectionStatus=false;
        StatusBar->SetStatusText(_("Disconnected"),1);
        StatusBar->SetStatusText(_T(""),2);
        StatusBar->SetStatusText(_("Ready."),3);
        delete xBusCon;
    }
    else
    {
        StatusBar->SetStatusText(_("Already disconnected, command aborted."),3);
    }

}

void OpenCCFrame::OnMenuItemTransmitSelected(wxCommandEvent& event)
{
    int msb, lsb;

    if (!connectionStatus)
    {
        StatusBar->SetStatusText(_("Please connect to tuning box first, command aborted."),3);
        return;
    }

    if (MenuItemMonitor->IsChecked())
    {
        StatusBar->SetStatusText(_("Monitor function must be disabled, command aborted."),3);
        return;
    }

    StatusBar->SetStatusText(_("Writing map to tuning box..."),3);

    // MAP 1 (Normal)

    // TX threshold
    msb=threshold1 / 256;
    lsb=threshold1 - (msb * 256);
    xBusCon->packetData[0]=(unsigned char)msb;
    xBusCon->packetData[1]=(unsigned char)lsb;

    // TX power
    msb=power1 / 256;
    lsb=power1 - (msb * 256);
    xBusCon->packetData[2]=(unsigned char)msb;
    xBusCon->packetData[3]=(unsigned char)lsb;

    // TX SogliaSlop
    msb=slopeThreshold1 / 256;
    lsb=slopeThreshold1 - (msb * 256);
    xBusCon->packetData[4]=(unsigned char)msb;
    xBusCon->packetData[5]=(unsigned char)lsb;

    // TX Slop Pot
    msb=slopePower1 / 256;
    lsb=slopePower1 - (msb * 256);
    xBusCon->packetData[6]=(unsigned char)msb;
    xBusCon->packetData[7]=(unsigned char)lsb;

    // TX Ramp
    msb=ramp1 / 256;
    lsb=ramp1 - (msb * 256);
    xBusCon->packetData[8]=(unsigned char)msb;
    xBusCon->packetData[9]=(unsigned char)lsb;

    // Map 2 (FAP)

    // TX threshold
    msb=threshold2 / 256;
    lsb=threshold2 - (msb * 256);
    xBusCon->packetData[10]=(unsigned char)msb;
    xBusCon->packetData[11]=(unsigned char)lsb;

    // TX power
    msb=power2 / 256;
    lsb=power2 - (msb * 256);
    xBusCon->packetData[12]=(unsigned char)msb;
    xBusCon->packetData[13]=(unsigned char)lsb;

    // TX SogliaSlop
    msb=slopeThreshold2 / 256;
    lsb=slopeThreshold2 - (msb * 256);
    xBusCon->packetData[14]=(unsigned char)msb;
    xBusCon->packetData[15]=(unsigned char)lsb;

    // TX Slop Pot
    msb=slopePower2 / 256;
    lsb=slopePower2 - (msb * 256);
    xBusCon->packetData[16]=(unsigned char)msb;
    xBusCon->packetData[17]=(unsigned char)lsb;

    // TX Ramp
    msb=ramp2 / 256;
    lsb=ramp2 - (msb * 256);
    xBusCon->packetData[18]=(unsigned char)msb;
    xBusCon->packetData[19]=(unsigned char)lsb;

    // Function Mode
    xBusCon->packetData[20]=mapMode;

    // Trimmer Mode
    xBusCon->packetData[21]=trimmerEnabled;

    // Enable Box
    xBusCon->packetData[22]=boxEnabled;

    // Send write data packet
    xBusCon->WritePacket(128,0x11,23);

    if (!xBusCon->ReadPacket())
    {
        StatusBar->SetStatusText(_("Ready."),3);
    }
    else
        StatusBar->SetStatusText(_("Error writing map, please retry!"),3);
}

void OpenCCFrame::OnMenuItemReceiveSelected(wxCommandEvent& event)
{
    if (!connectionStatus)
    {
        StatusBar->SetStatusText(_("Please connect to tuning box first, command aborted."),3);
        return;
    }

    if (MenuItemMonitor->IsChecked())
    {
        StatusBar->SetStatusText(_("Monitor function must be disabled, command aborted."),3);
        return;
    }

    StatusBar->SetStatusText(_("Reading map from tuning box..."),3);

    xBusCon->WritePacket(128,0x01,0);
    if (!xBusCon->ReadPacket())
    {
        threshold1=xBusCon->packetData[0] * 256 + xBusCon->packetData[1];
        power1=xBusCon->packetData[2] * 256 + xBusCon->packetData[3];
        slopeThreshold1=xBusCon->packetData[4] * 256 + xBusCon->packetData[5];
        slopePower1=xBusCon->packetData[6] * 256 + xBusCon->packetData[7];
        ramp1=xBusCon->packetData[8] * 256 + xBusCon->packetData[9];

        threshold2=xBusCon->packetData[10] * 256 + xBusCon->packetData[11];
        power2=xBusCon->packetData[12] * 256 + xBusCon->packetData[13];
        slopeThreshold2=xBusCon->packetData[14] * 256 + xBusCon->packetData[15];
        slopePower2=xBusCon->packetData[16] * 256 + xBusCon->packetData[17];
        ramp2=xBusCon->packetData[18] * 256 + xBusCon->packetData[19];

        mapMode=xBusCon->packetData[20];
        trimmerEnabled=xBusCon->packetData[21];
        boxEnabled=xBusCon->packetData[22];

        if (trimmerEnabled)
        {
            MenuItemEnTrimmer->Check(true);
            StaticTextPower->SetLabel(_("Maximum\nPower"));
        }
        else
        {
            MenuItemEnTrimmer->Check(false);
            StaticTextPower->SetLabel(_("Power"));
        }

        if (boxEnabled)
            MenuItemEnBox->Check(true);
        else
            MenuItemEnBox->Check(false);

        if (mapMode==1)
        {
            SliderThreshold->SetValue(threshold1);
            SliderPower->SetValue(power1);
            SliderSlopeThreshold->SetValue(slopeThreshold1);
            SliderSlope->SetValue(slopePower1);
            SliderRamp->SetValue(ramp1);

            StatusBar->SetStatusText(_("Map 1 (Normal)"),4);
            MenuItemNormalMap->Check(true);
        }
        else
        {
            SliderThreshold->SetValue(threshold2);
            SliderPower->SetValue(power2);
            SliderSlopeThreshold->SetValue(slopeThreshold2);
            SliderSlope->SetValue(slopePower2);
            SliderRamp->SetValue(ramp2);

            StatusBar->SetStatusText(_("Map 2 (FAP)"),4);
            MenuItemFAPMap->Check(true);
        }

        UpdateThresholdValue();
        UpdatePowerValue();
        UpdateSlopeThresholdValue();
        UpdateSlopePowerValue();
        UpdateRampValue();

        StatusBar->SetStatusText(_("Ready."),3);
    }
    else
        StatusBar->SetStatusText(_("Error reading map, please retry!"),3);
}

void OpenCCFrame::OnMenuItemNormalMapSelected(wxCommandEvent& event)
{
    SliderThreshold->SetValue(threshold1);
    SliderPower->SetValue(power1);
    SliderSlopeThreshold->SetValue(slopeThreshold1);
    SliderSlope->SetValue(slopePower1);
    SliderRamp->SetValue(ramp1);

    UpdateThresholdValue();
    UpdatePowerValue();
    UpdateSlopeThresholdValue();
    UpdateSlopePowerValue();
    UpdateRampValue();

    mapMode=1;
    StatusBar->SetStatusText(_("Map 1 (Normal)"),4);
}

void OpenCCFrame::OnMenuItemFAPMapSelected(wxCommandEvent& event)
{
    SliderThreshold->SetValue(threshold2);
    SliderPower->SetValue(power2);
    SliderSlopeThreshold->SetValue(slopeThreshold2);
    SliderSlope->SetValue(slopePower2);
    SliderRamp->SetValue(ramp2);

    UpdateThresholdValue();
    UpdatePowerValue();
    UpdateSlopeThresholdValue();
    UpdateSlopePowerValue();
    UpdateRampValue();

    mapMode=2;
    StatusBar->SetStatusText(_("Map 2 (FAP)"),4);
}

void OpenCCFrame::OnMenuItemMonitorSelected(wxCommandEvent& event)
{
    if (MenuItemMonitor->IsChecked())
    {
        TimerMonitor.Start(1000, false);
        StatusBar->SetStatusText(_("Monitor enabled..."),3);
    }
    else
    {
        TimerMonitor.Stop();

        GaugeRailIn->SetValue(0);
        GaugeRailOut->SetValue(0);

        StaticTextRailIn->SetLabel(_T("0V"));
        StaticTextRailOut->SetLabel(_T("0V"));
        StatusBar->SetStatusText(_("Ready."),3);
    }
}

void OpenCCFrame::OnMenuItemEnTrimmerSelected(wxCommandEvent& event)
{
    if (MenuItemEnTrimmer->IsChecked())
    {
        trimmerEnabled=1;
        StaticTextPower->SetLabel(_("Maximum\nPower"));
    }
    else
    {
        trimmerEnabled=0;
        StaticTextPower->SetLabel(_("Power"));
    }
}

void OpenCCFrame::OnMenuItemEnBoxSelected(wxCommandEvent& event)
{
    if (MenuItemEnBox->IsChecked())
        boxEnabled=1;
    else
        boxEnabled=0;
}

void OpenCCFrame::OnMenuItemResetSelected(wxCommandEvent& event)
{
    if (!connectionStatus)
    {
        StatusBar->SetStatusText(_("Please connect to tuning box first, command aborted."),3);
        return;
    }

    StatusBar->SetStatusText(_("Resetting tuning box..."),3);

    threshold1=0;
    power1=0;
    slopeThreshold1=0;
    slopePower1=0;
    ramp1=0;

    threshold2=0;
    power2=0;
    slopeThreshold2=0;
    slopePower2=0;
    ramp2=0;

    mapMode=1;
    trimmerEnabled=0;
    boxEnabled=0;

    UpdateThresholdValue();
    UpdatePowerValue();
    UpdateSlopeThresholdValue();
    UpdateSlopePowerValue();
    UpdateRampValue();

    StatusBar->SetStatusText(_("Map 1 (Normal)"),4);
    MenuItemEnTrimmer->Check(false);
    MenuItemEnBox->Check(false);

    OnMenuItemTransmitSelected(event);
}

void OpenCCFrame::OnMenuItemExitSelected(wxCommandEvent& event)
{
    Close();
}

void OpenCCFrame::OnMenuItemAboutSelected(wxCommandEvent& event)
{
	// Create about box instance
	AboutBoxDialog * dlg = new AboutBoxDialog(this);

	// Set application data
	dlg->SetAppName(_T("Open Control Center"));
	dlg->SetVersion(_T("0.1.0 [Alfa]"));
	dlg->SetCopyright(_T("Copyright (c) MTX Electronics, 2009.\nAll rights reserved.\n\nReleased under GNU GPL license."));
	dlg->SetCustomBuildInfo(AboutBoxDialog::GetBuildInfo(AboutBoxDialog::wxBUILDINFO_LONG).GetData());

	// Apply data changes
	dlg->ApplyInfo();
	// Show dialog
	dlg->ShowModal();
	// Destroy dialog
	dlg->Destroy();
}

// Toolbar events -------------------------------------------------------------

void OpenCCFrame::OnToolBarItemLoadClicked(wxCommandEvent& event)
{
    OnMenuItemOpenSelected(event);
}

void OpenCCFrame::OnToolBarItemSaveClicked(wxCommandEvent& event)
{
    OnMenuItemSaveSelected(event);
}

void OpenCCFrame::OnToolBarItemReceiveClicked(wxCommandEvent& event)
{
    OnMenuItemReceiveSelected(event);
}

void OpenCCFrame::OnToolBarItemTransmitClicked(wxCommandEvent& event)
{
    OnMenuItemTransmitSelected(event);
}

void OpenCCFrame::OnToolBarItemNormalMapClicked(wxCommandEvent& event)
{
    OnMenuItemNormalMapSelected(event);
}

void OpenCCFrame::OnToolBarItemFAPMapClicked(wxCommandEvent& event)
{
    OnMenuItemFAPMapSelected(event);
}

void OpenCCFrame::OnToolBarAboutClicked(wxCommandEvent& event)
{
    OnMenuItemAboutSelected(event);
}

// Scrollbar events -----------------------------------------------------------

void OpenCCFrame::OnSliderThresholdCmdScrollThumbTrack(wxScrollEvent& event)
{
    if (mapMode==1)
        threshold1=SliderThreshold->GetValue();
    else
        threshold2=SliderThreshold->GetValue();

    UpdateThresholdValue();
}

void OpenCCFrame::OnSliderPowerCmdScrollThumbTrack(wxScrollEvent& event)
{
    if (mapMode==1)
        power1=SliderPower->GetValue();
    else
        power2=SliderPower->GetValue();

    UpdatePowerValue();
}

void OpenCCFrame::OnSliderSlopeThresholdCmdScrollThumbTrack(wxScrollEvent& event)
{
    if (mapMode==1)
        slopeThreshold1=SliderSlopeThreshold->GetValue();
    else
        slopeThreshold2=SliderSlopeThreshold->GetValue();

    UpdateSlopeThresholdValue();
}

void OpenCCFrame::OnSliderSlopeCmdScrollThumbTrack(wxScrollEvent& event)
{
    if (mapMode==1)
        slopePower1=SliderSlope->GetValue();
    else
        slopePower2=SliderSlope->GetValue();

    UpdateSlopePowerValue();
}

void OpenCCFrame::OnSliderRampCmdScrollThumbTrack(wxScrollEvent& event)
{
    if (mapMode==1)
        ramp1=SliderRamp->GetValue();
    else
        ramp2=SliderRamp->GetValue();

    UpdateRampValue();
}

// Timer events ---------------------------------------------------------------

void OpenCCFrame::OnTimerMonitorTrigger(wxTimerEvent& event)
{
    float fValue;
    wxString strNumDigits = wxString::Format(_T("%%0.%df"),2);

    if (!connectionStatus)
    {
        MenuItemMonitor->Check(false);
        TimerMonitor.Stop();
        return;
    }

    xBusCon->WritePacket(129,0x01,0);
    if (!xBusCon->ReadPacket())
    {
        GaugeRailIn->SetValue(xBusCon->packetData[0] * 256 + xBusCon->packetData[1]);
        GaugeRailOut->SetValue(xBusCon->packetData[2] * 256 + xBusCon->packetData[3]);

        fValue=(float)GaugeRailIn->GetValue() * 0.00122;
        StaticTextRailIn->SetLabel(_("Rail In: ") + wxString::Format (strNumDigits, fValue) + _T("V"));

        fValue=(float)GaugeRailOut->GetValue() * 0.00122;
        StaticTextRailOut->SetLabel(_("Rail Out: ") + wxString::Format (strNumDigits, fValue) + _T("V"));
    }
    else
        StatusBar->SetStatusText(_("Error reading monitor, retrying..."),3);
}
