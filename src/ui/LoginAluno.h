#ifndef LOGINALUNO_H
#define LOGINALUNO_H

#include <wx/wx.h>
#include <wx/statline.h>
#include "../db/Database.h"

class LoginAluno : public wxDialog {
private:
    wxTextCtrl* txtMatricula;
    wxTextCtrl* txtSenha;
    Database& db;

    void OnLogin(wxCommandEvent& event);
    void OnCancelar(wxCommandEvent& event);

public:
    LoginAluno(Database& db);
};

#endif
