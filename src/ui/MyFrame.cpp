#include "MyFrame.h"
#include <wx/treectrl.h>

MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1200, 800)) {

    m_mgr.SetManagedWindow(this);

    wxTreeCtrl* palette = new wxTreeCtrl(this, wxID_ANY);
    palette->AddRoot("Derivative");

    wxPanel* canvas = new wxPanel(this, wxID_ANY);
    canvas->SetBackgroundColour(*wxBLACK);

    m_mgr.AddPane(palette, wxAuiPaneInfo().Left().Caption("Palette").BestSize(250, -1));
    m_mgr.AddPane(canvas, wxAuiPaneInfo().CenterPane());

    m_mgr.Update();
}

MyFrame::~MyFrame() {
    m_mgr.UnInit();
}