#include <wx/aui/aui.h>

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);
    virtual ~MyFrame();

private:
    wxAuiManager m_mgr;
    void SetupLayout();
};