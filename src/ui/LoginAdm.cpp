#include "LoginAdm.h"

LoginAdm::LoginAdm(Database& db)
    : wxDialog(nullptr, wxID_ANY, "Login - Administrador",
               wxDefaultPosition, wxSize(720, 480)),
      db(db)
{
    // Cores
    wxColour bgEscuro(18, 18, 18);
    wxColour cinzaCard(35, 35, 35);
    wxColour cinzaBorda(60, 60, 60);
    wxColour branco(240, 240, 240);
    wxColour cinzaTexto(160, 160, 160);

    SetBackgroundColour(bgEscuro);

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(bgEscuro);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // ===== Título =====
    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Acesso ao Sistema",
                                             wxDefaultPosition, wxDefaultSize,
                                             wxALIGN_CENTER);
    titulo->SetForegroundColour(branco);
    titulo->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(titulo, 0, wxALIGN_CENTER | wxTOP, 25);

    // ===== Subtítulo =====
    wxStaticText* sub = new wxStaticText(panel, wxID_ANY, "Digite suas credenciais para continuar",
                                          wxDefaultPosition, wxDefaultSize,
                                          wxALIGN_CENTER);
    sub->SetForegroundColour(cinzaTexto);
    sub->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    vbox->Add(sub, 0, wxALIGN_CENTER | wxTOP, 6);

    // ===== Separador =====
    wxStaticLine* linha = new wxStaticLine(panel);
    linha->SetBackgroundColour(cinzaBorda);
    vbox->Add(linha, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    // ===== Campo Usuário =====
    wxStaticText* lblUsuario = new wxStaticText(panel, wxID_ANY, "Usuario:");
    lblUsuario->SetForegroundColour(cinzaTexto);
    lblUsuario->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(lblUsuario, 0, wxLEFT | wxTOP, 20);

    txtUsuario = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 35));
    txtUsuario->SetBackgroundColour(cinzaCard);
    txtUsuario->SetForegroundColour(branco);
    vbox->Add(txtUsuario, 0, wxEXPAND | wxLEFT | wxRIGHT, 20);

    // ===== Campo Senha =====
    wxStaticText* lblSenha = new wxStaticText(panel, wxID_ANY, "Senha:");
    lblSenha->SetForegroundColour(cinzaTexto);
    lblSenha->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(lblSenha, 0, wxLEFT | wxTOP, 10);

    txtSenha = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition,
                               wxSize(-1, 35), wxTE_PASSWORD);
    txtSenha->SetBackgroundColour(cinzaCard);
    txtSenha->SetForegroundColour(branco);
    vbox->Add(txtSenha, 0, wxEXPAND | wxLEFT | wxRIGHT, 20);

    // ===== Botões =====
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    wxButton* btnLogin    = new wxButton(panel, wxID_ANY, "Entrar",
                                          wxDefaultPosition, wxSize(180, 55));
    wxButton* btnCancelar = new wxButton(panel, wxID_ANY, "Cancelar",
                                          wxDefaultPosition, wxSize(180, 55));

    wxFont fontBtn(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    btnLogin->SetBackgroundColour(cinzaCard);
    btnLogin->SetForegroundColour(branco);
    btnLogin->SetFont(fontBtn);

    btnCancelar->SetBackgroundColour(cinzaCard);
    btnCancelar->SetForegroundColour(cinzaTexto);
    btnCancelar->SetFont(fontBtn);

    hbox->Add(btnLogin,    0, wxALL, 8);
    hbox->Add(btnCancelar, 0, wxALL, 8);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP, 15);

    // ===== Rodapé =====
    wxStaticText* rodape = new wxStaticText(panel, wxID_ANY, "IFF - Todos os direitos reservados",
                                             wxDefaultPosition, wxDefaultSize,
                                             wxALIGN_CENTER);
    rodape->SetForegroundColour(cinzaBorda);
    rodape->SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    vbox->Add(rodape, 0, wxALIGN_CENTER | wxTOP, 10);

    panel->SetSizer(vbox);
    Centre();

    btnLogin->Bind(wxEVT_BUTTON,    &LoginAdm::OnLogin,    this);
    btnCancelar->Bind(wxEVT_BUTTON, &LoginAdm::OnCancelar, this);
}

void LoginAdm::OnLogin(wxCommandEvent& event) {
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

void LoginAdm::OnCancelar(wxCommandEvent& event) {
    EndModal(wxID_CANCEL);
}
