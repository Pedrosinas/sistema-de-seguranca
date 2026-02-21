#ifndef LOGIN_H
#define LOGIN_H

#include <wx/wx.h>
#include <wx/statline.h>
#include "../db/Database.h"

class Login : public wxDialog {
private:
    void OnAluno(wxCommandEvent& event);
    void OnAdministrador(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);

public:
    std::string mode;
    Login();
};

#endif
