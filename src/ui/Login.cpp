#include "Login.h"

Login::Login() : wxDialog(nullptr, wxID_ANY, "Sistema IFF",
                           wxDefaultPosition, wxSize(480, 320),
                           wxDEFAULT_DIALOG_STYLE)
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
    wxStaticText* titulo = new wxStaticText(panel, wxID_ANY, "Sistema de Seguranca - IFF",
                                             wxDefaultPosition, wxDefaultSize,
                                             wxALIGN_CENTER);
    titulo->SetForegroundColour(branco);
    wxFont fontTitulo(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    titulo->SetFont(fontTitulo);
    vbox->Add(titulo, 0, wxALIGN_CENTER | wxTOP, 35);

    // ===== Subtítulo =====
    wxStaticText* sub = new wxStaticText(panel, wxID_ANY, "Selecione o tipo de acesso",
                                          wxDefaultPosition, wxDefaultSize,
                                          wxALIGN_CENTER);
    sub->SetForegroundColour(cinzaTexto);
    wxFont fontSub(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    sub->SetFont(fontSub);
    vbox->Add(sub, 0, wxALIGN_CENTER | wxTOP, 8);

    // ===== Separador =====
    wxStaticLine* linha = new wxStaticLine(panel);
    linha->SetBackgroundColour(cinzaBorda);
    vbox->Add(linha, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 30);

    // ===== Botões =====
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    wxButton* btnAluno         = new wxButton(panel, wxID_ANY, "Aluno",
                                               wxDefaultPosition, wxSize(160, 60));
    wxButton* btnAdministrador = new wxButton(panel, wxID_ANY, "Administrador",
                                               wxDefaultPosition, wxSize(160, 60));

    // Estilo dos botões
    wxFont fontBtn(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    btnAluno->SetBackgroundColour(cinzaCard);
    btnAluno->SetForegroundColour(branco);
    btnAluno->SetFont(fontBtn);

    btnAdministrador->SetBackgroundColour(cinzaCard);
    btnAdministrador->SetForegroundColour(branco);
    btnAdministrador->SetFont(fontBtn);

    hbox->Add(btnAluno,         0, wxALL, 10);
    hbox->Add(btnAdministrador, 0, wxALL, 10);
    vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP, 25);

    // ===== Rodapé =====
    wxStaticText* rodape = new wxStaticText(panel, wxID_ANY, "IFF - Todos os direitos reservados",
                                             wxDefaultPosition, wxDefaultSize,
                                             wxALIGN_CENTER);
    rodape->SetForegroundColour(cinzaBorda);
    wxFont fontRodape(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    rodape->SetFont(fontRodape);
    vbox->Add(rodape, 0, wxALIGN_CENTER | wxTOP, 20);

    panel->SetSizer(vbox);
    this->Fit();
    Centre();

    btnAluno->Bind(wxEVT_BUTTON,         &Login::OnAluno,         this);
    btnAdministrador->Bind(wxEVT_BUTTON, &Login::OnAdministrador, this);
}

void Login::OnAluno(wxCommandEvent& event) {
    mode = "aluno";
    EndModal(wxID_OK);
}

void Login::OnAdministrador(wxCommandEvent& event) {
    mode = "administrador";
    EndModal(wxID_OK);
}
