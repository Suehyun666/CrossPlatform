#include <wx/aui/aui.h>
#include <wx/menu.h>
#include <wx/treectrl.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    virtual ~MainFrame();

private:
    wxAuiManager m_mgr;
    wxMenuBar* m_menuBar;
    wxPanel* m_canvas;
    wxTreeCtrl* m_palette;

    void SetupMenuBar();
    void SetupLayout();

    void OnFileOpen(wxCommandEvent& evt);
    void OnFileExit(wxCommandEvent& evt);

    wxDECLARE_EVENT_TABLE();
};
