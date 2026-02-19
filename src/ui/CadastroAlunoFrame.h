#ifndef CADASTROALUNOFRAME_H
#define CADASTROALUNOFRAME_H

#include <wx/wx.h>
#include "../db/Database.h"
#include "../models/Administrador.h"

class CadastroAlunoFrame : public wxFrame {
private:
    wxTextCtrl* txtNome;
    wxTextCtrl* txtMatricula;
    wxTextCtrl* txtPasta;

    Administrador* admin;

    void OnCadastrar(wxCommandEvent& event);

public:
    CadastroAlunoFrame(Database& db);
    ~CadastroAlunoFrame();
};

#endif
