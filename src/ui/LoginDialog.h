#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <wx/wx.h>
#include "../db/Database.h"

class LoginDialog : public wxDialog {
private:
    wxTextCtrl* txtUsuario;
    wxTextCtrl* txtSenha;
    Database& db;

    void OnLogin(wxCommandEvent& event);
    void OnCancelar(wxCommandEvent& event);

public:
    LoginDialog(Database& db);
};

#endif
