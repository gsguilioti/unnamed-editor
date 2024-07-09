#include <wx/wx.h>

class Window : public wxFrame
{
public:
    Window();
 
private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};