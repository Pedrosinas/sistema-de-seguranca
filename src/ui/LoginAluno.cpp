#include "LoginAluno.h"

LoginAluno::LoginAluno(Database& db)
    : wxDialog(nullptr, wxID_ANY, "Login - Aluno",
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
    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Acesso do Aluno",
                                             wxDefaultPosition, wxDefaultSize,
                                             wxALIGN_CENTER);
    titulo->SetForegroundColour(branco);
    titulo->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(titulo, 0, wxALIGN_CENTER | wxTOP, 25);

    // ===== Subtítulo =====
    wxStaticText* sub = new wxStaticText(panel, wxID_ANY, "Digite sua matricula e senha para continuar",
                                          wxDefaultPosition, wxDefaultSize,
                                          wxALIGN_CENTER);
    sub->SetForegroundColour(cinzaTexto);
    sub->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    vbox->Add(sub, 0, wxALIGN_CENTER | wxTOP, 6);

    // ===== Separador =====
    wxStaticLine* linha = new wxStaticLine(panel);
    linha->SetBackgroundColour(cinzaBorda);
    vbox->Add(linha, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    // ===== Campo Matrícula =====
    wxStaticText* lblMatricula = new wxStaticText(panel, wxID_ANY, "Matricula:");
    lblMatricula->SetForegroundColour(cinzaTexto);
    lblMatricula->SetFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(lblMatricula, 0, wxLEFT | wxTOP, 20);

    txtMatricula = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 35));
    txtMatricula->SetBackgroundColour(cinzaCard);
    txtMatricula->SetForegroundColour(branco);
    vbox->Add(txtMatricula, 0, wxEXPAND | wxLEFT | wxRIGHT, 20);

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

    btnLogin->Bind(wxEVT_BUTTON,    &LoginAluno::OnLogin,    this);
    btnCancelar->Bind(wxEVT_BUTTON, &LoginAluno::OnCancelar, this);
}

void LoginAluno::OnLogin(wxCommandEvent& event) {
    wxString matricula = txtMatricula->GetValue();
    wxString senha     = txtSenha->GetValue();

    if (matricula.IsEmpty() || senha.IsEmpty()) {
        wxMessageBox("Preencha todos os campos!", "Atencao", wxICON_WARNING);
        return;
    }

    // TODO: validar matrícula e senha no banco de dados
    wxMessageBox("Login do aluno ainda nao implementado.", "Info", wxICON_INFORMATION);
}

void LoginAluno::OnCancelar(wxCommandEvent& event) {
    EndModal(wxID_CANCEL);
}
