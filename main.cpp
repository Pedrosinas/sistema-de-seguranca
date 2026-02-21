#include <wx/wx.h>
#include "src/db/Database.h"
#include "src/ui/Login.h"
#include "src/ui/LoginAdm.h"
#include "src/ui/LoginAluno.h"
#include "src/ui/CadastroAlunoFrame.h"

class MyApp : public wxApp {
public:
    bool OnInit() override {
        if (!wxSetlocale(LC_ALL, ""))
            wxSetlocale(LC_ALL, "pt_BR.UTF-8");

        Database* db = new Database();

        if (!db->conectar("localhost", "iff_user", "1234", "sistema_de_seguranca")) {
            wxMessageBox("Erro ao conectar no banco:\n" + db->getErro(),
                         "Erro", wxICON_ERROR);
            delete db;
            return false;
        }

        Login* log = new Login();

        if (log->ShowModal() == wxID_OK) {
            std::string modo = log->mode;
            log->Destroy();

            if (modo == "administrador") {
                LoginAdm* login = new LoginAdm(*db);

                if (login->ShowModal() == wxID_OK) {
                    CadastroAlunoFrame* frame = new CadastroAlunoFrame(*db);
                    frame->Show(true);
                    SetTopWindow(frame);
                }
                login->Destroy();

            } else if (modo == "aluno") {
                LoginAluno* login = new LoginAluno(*db);

                if (login->ShowModal() == wxID_OK) {
                    // TODO: tela do aluno quando estiver pronta
                }
                login->Destroy();
            }
        } else {
            log->Destroy();
        }

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
