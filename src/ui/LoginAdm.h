#ifndef LOGINADM_H
#define LOGINADM_H

#include <wx/wx.h>
#include <wx/statline.h>
#include "../db/Database.h"

class LoginAdm : public wxDialog {
private:
    wxTextCtrl* txtUsuario;
    wxTextCtrl* txtSenha;
    Database& db;

    void OnLogin(wxCommandEvent& event);
    void OnCancelar(wxCommandEvent& event);

public:
    LoginAdm(Database& db);
};

#endif
