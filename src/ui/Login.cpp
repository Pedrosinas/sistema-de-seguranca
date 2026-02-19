#include "Login.h"

Login::Login() : wxDialog(nullptr, wxID_ANY, "Login", wxDefaultPosition, wxSize(500,350))
{
	wxPanel* panel = new wxPanel(this);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxButton* btnAluno    = new wxButton(panel, wxID_ANY, "Aluno");
	wxButton* btnAdministrador = new wxButton(panel, wxID_ANY, "Administrador");

	hbox->Add(btnAluno,    0, wxALL, 5);
	hbox->Add(btnAdministrador, 0, wxALL, 5);

	panel->SetSizer(hbox);
	this->Fit();
	Centre();

	btnAluno->Bind(wxEVT_BUTTON,    &Login::OnAluno,         this);
	btnAdministrador->Bind(wxEVT_BUTTON, &Login::OnAdministrador, this);
};

void Login::OnAluno(wxCommandEvent& event){
	Login::mode = "aluno";
	EndModal(wxID_OK);
}

void Login::OnAdministrador(wxCommandEvent& event){
	Login::mode = "administrador";
	EndModal(wxID_OK);
}
