#include <wx/wx.h>
#include <string>

#include "Database.h"
#include "Administrador.h"
#include "Aluno.h"

class MyFrame : public wxFrame {
private:
    wxTextCtrl* txtNome;
    wxTextCtrl* txtMatricula;
    wxTextCtrl* txtPasta;

    Database db;
    Administrador* admin;

    void OnCadastrar(wxCommandEvent& event);

public:
    MyFrame();
    ~MyFrame();
};

// ===== Construtor =====
MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Sistema de Segurança - IFF",
              wxDefaultPosition, wxSize(400, 350))
{
    admin = nullptr;

    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Nome:"), 0, wxLEFT | wxTOP, 10);
    txtNome = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(txtNome, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    vbox->Add(new wxStaticText(panel, wxID_ANY, "Matrícula:"), 0, wxLEFT | wxTOP, 10);
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

    btnCadastrar->Bind(wxEVT_BUTTON, &MyFrame::OnCadastrar, this);

    if (db.conectar("localhost", "iff_user", "1234", "sistema_de_seguranca")) {
        admin = new Administrador(db);
    } else {
        wxMessageBox("Erro ao conectar no banco:\n" + db.getErro(),
                     "Erro de Conexão", wxICON_ERROR | wxOK);
        btnCadastrar->Disable();
    }
}

MyFrame::~MyFrame() {
    delete admin;
}

void MyFrame::OnCadastrar(wxCommandEvent& event) {

    if (!admin) {
        wxMessageBox("Sem conexão com o banco de dados.", "Erro", wxICON_ERROR);
        return;
    }

    wxString nomeWx      = txtNome->GetValue();
    wxString matriculaWx = txtMatricula->GetValue();
    wxString pastaWx     = txtPasta->GetValue();

    if (nomeWx.IsEmpty() || matriculaWx.IsEmpty() || pastaWx.IsEmpty()) {
        wxMessageBox("Preencha todos os campos!", "Atenção", wxICON_WARNING);
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

class MyApp : public wxApp {
public:
	bool OnInit() override {
    wxInitAllImageHandlers();
    // garante encoding correto
    if (!wxSetlocale(LC_ALL, ""))
        wxSetlocale(LC_ALL, "pt_BR.UTF-8");

    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
	}
};	
wxIMPLEMENT_APP(MyApp);
