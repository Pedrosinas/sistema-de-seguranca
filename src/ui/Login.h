#ifndef LOGIN_H
#define LOGIN_H

#include <wx/wx.h>
#include "../db/Database.h"

class Login : public wxDialog {
	private:
		void OnAluno(wxCommandEvent& event);
		void OnAdministrador(wxCommandEvent& event);
	public:
		std::string mode;
		Login();
};

#endif
