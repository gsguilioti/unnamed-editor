#include "window.h"

Window::Window()
        : wxFrame(nullptr, wxID_ANY, "Unnamed Editor")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar(menuBar);
 
    CreateStatusBar();
    SetStatusText("Unnamed Editor v0.0.0");

    Bind(wxEVT_MENU, &Window::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Window::OnExit, this, wxID_EXIT);
}

void Window::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Window::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("github.com/gsguilioti/unnamed-editor",
                 "unnamed editor", wxOK | wxICON_INFORMATION);
}