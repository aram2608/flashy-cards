#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class FlashyCards : public wxApp {
  public:
    bool OnInit() override;
};

// We declare the App so that get can retrieve a refernce to it instead of
// a wxAPP
wxDECLARE_APP(FlashyCards);

class FlashyFrame : public wxFrame {
  public:
    FlashyFrame();

  private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};

// In order to react to events, an identifier needs to be created
// variable are fine but enums are easier
enum { ID_Hello = 1 };

// We need to implement our app for it to work
wxIMPLEMENT_APP(FlashyCards);

// This is our entry to the program, similar to main
bool FlashyCards::OnInit() {
    FlashyFrame *frame = new FlashyFrame();
    frame->Show(true);
    return true;
}

FlashyFrame::FlashyFrame() : wxFrame(NULL, wxID_ANY, "Hello World") {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &FlashyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &FlashyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &FlashyFrame::OnExit, this, wxID_EXIT);
}

void FlashyFrame::OnExit(wxCommandEvent &event) { Close(true); }

void FlashyFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
                 wxOK | wxICON_INFORMATION);
}

void FlashyFrame::OnHello(wxCommandEvent &event) {
    wxLogMessage("Hello world from wxWidgets!");
}