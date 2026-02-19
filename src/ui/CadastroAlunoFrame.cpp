#include "CadastroAlunoFrame.h"

CadastroAlunoFrame::CadastroAlunoFrame(Database& db)
    : wxFrame(nullptr, wxID_ANY, "Cadastro de Alunos - IFF",
              wxDefaultPosition, wxSize(400, 350))
{
    admin = new Administrador(db);

    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Nome:"), 0, wxLEFT | wxTOP, 10);
    txtNome = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(txtNome, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Matricula:"), 0, wxLEFT | wxTOP, 10);
    txtMatricula = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(txtMatricula, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Pasta:"), 0, wxLEFT | wxTOP, 10);
    txtPasta = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(txtPasta, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    wxButton* btnCadastrar = new wxButton(panel, wxID_ANY, "Cadastrar");
    vbox->Add(btnCadastrar, 0, wxALIGN_CENTER | wxALL, 15);

    panel->SetSizer(vbox);
    this->Fit();
    SetMinSize(wxSize(400, 350));
    Centre();

    btnCadastrar->Bind(wxEVT_BUTTON, &CadastroAlunoFrame::OnCadastrar, this);
}

CadastroAlunoFrame::~CadastroAlunoFrame() {
    delete admin;
}

void CadastroAlunoFrame::OnCadastrar(wxCommandEvent& event) {
    wxString nomeWx      = txtNome->GetValue();
    wxString matriculaWx = txtMatricula->GetValue();
    wxString pastaWx     = txtPasta->GetValue();

    if (nomeWx.IsEmpty() || matriculaWx.IsEmpty() || pastaWx.IsEmpty()) {
        wxMessageBox("Preencha todos os campos!", "Atencao", wxICON_WARNING);
        return;
    }

    std::string nome      = nomeWx.ToStdString();
    std::string matricula = matriculaWx.ToStdString();
    std::string pasta     = pastaWx.ToStdString();

    if (admin->cadastrarAluno(nome, matricula, pasta)) {
        wxMessageBox("Aluno cadastrado com sucesso!", "Sucesso", wxICON_INFORMATION);
        txtNome->Clear();
        txtMatricula->Clear();
        txtPasta->Clear();
    } else {
        wxMessageBox("Erro ao cadastrar aluno.", "Erro", wxICON_ERROR);
    }
}
