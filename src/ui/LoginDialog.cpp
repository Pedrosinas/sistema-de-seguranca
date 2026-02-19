#include "LoginDialog.h"

LoginDialog::LoginDialog(Database& db)
	: wxDialog(nullptr, wxID_ANY, "Login - Sistema IFF",
               wxDefaultPosition, wxSize(300, 200)),
      db(db)
{
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Usuario:"), 0, wxLEFT | wxTOP, 10);
    txtUsuario = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(txtUsuario, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Senha:"), 0, wxLEFT | wxTOP, 10);
    txtSenha = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
                               wxDefaultSize, wxTE_PASSWORD);
    vbox->Add(txtSenha, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    wxButton* btnLogin    = new wxButton(panel, wxID_ANY, "Entrar");
    wxButton* btnCancelar = new wxButton(panel, wxID_ANY, "Cancelar");
    hbox->Add(btnLogin,    0, wxALL, 5);
    hbox->Add(btnCancelar, 0, wxALL, 5);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP, 10);

    panel->SetSizer(vbox);
    this->Fit();
    Centre();

    btnLogin->Bind(wxEVT_BUTTON,    &LoginDialog::OnLogin,    this);
    btnCancelar->Bind(wxEVT_BUTTON, &LoginDialog::OnCancelar, this);
}

void LoginDialog::OnLogin(wxCommandEvent& event) {
    wxString usuario = txtUsuario->GetValue();
    wxString senha   = txtSenha->GetValue();

    if (usuario.IsEmpty() || senha.IsEmpty()) {
        wxMessageBox("Preencha todos os campos!", "Atencao", wxICON_WARNING);
        return;
    }

    if (usuario == "admin" && senha == "1234") {
        EndModal(wxID_OK);
    } else {
        wxMessageBox("Usuario ou senha incorretos.", "Erro", wxICON_ERROR);
        txtSenha->Clear();
        txtUsuario->SetFocus();
    }
}

void LoginDialog::OnCancelar(wxCommandEvent& event) {
    EndModal(wxID_CANCEL);
}
