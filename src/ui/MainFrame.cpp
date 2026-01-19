#include "MainFrame.h"
#include <wx/filedlg.h>
#include "../../include/FileManager.h"

enum {
    ID_FILE_OPEN = wxID_HIGHEST + 1
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_FILE_OPEN, MainFrame::OnFileOpen)
    EVT_MENU(wxID_EXIT, MainFrame::OnFileExit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1200, 800)),
      m_menuBar(nullptr),
      m_canvas(nullptr),
      m_palette(nullptr) {

    SetupMenuBar();
    SetupLayout();
}

MainFrame::~MainFrame() {
    m_mgr.UnInit();
}

void MainFrame::SetupMenuBar() {
    m_menuBar = new wxMenuBar();

    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(ID_FILE_OPEN, "&Open\tCtrl+O");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt+F4");

    m_menuBar->Append(fileMenu, "&File");
    SetMenuBar(m_menuBar);
}

void MainFrame::SetupLayout() {
    m_mgr.SetManagedWindow(this);

    m_palette = new wxTreeCtrl(this, wxID_ANY);
    m_palette->AddRoot("Sources");

    m_canvas = new wxPanel(this, wxID_ANY);
    m_canvas->SetBackgroundColour(*wxBLACK);

    m_mgr.AddPane(m_palette, wxAuiPaneInfo()
        .Left()
        .Caption(wxT("Palette"))
        .BestSize(250, -1)
        .CloseButton(false));

    m_mgr.AddPane(m_canvas, wxAuiPaneInfo()
        .CenterPane()
        .Name(wxT("Canvas")));

    m_mgr.Update();
}

void MainFrame::OnFileOpen(wxCommandEvent& evt) {
    wxFileDialog dlg(this, "Open File", "", "",
        "All supported files|*.jpg;*.png;*.bmp;*.mp4;*.avi|"
        "All files (*.*)|*.*",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (dlg.ShowModal() == wxID_OK) {
        FileManager::GetInstance()->OpenFile(dlg.GetPath().mb_str());
    }
}

void MainFrame::OnFileExit(wxCommandEvent& evt) {
    Close(true);
}