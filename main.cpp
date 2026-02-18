#include"Database.h"
#include"Administrador.h"
#include"Aluno.h"

#include<iostream>

int main(int argc, char *argv[]) {

	Database db;

	if (!db.conectar("localhost", "iff_user", "1234", "sistema_de_seguranca")){
		return 1;
	}

	Administrador admin(db);
	
	std::string n, m, p;
	std::cout << "Insira o nome: ";
	std::cin >> n;
	std::cout << "\nInsira a matricula: ";
	std::cin >> m;
	std::cout << "\nInsira a pasta: ";
	std::cin >> p;

	if (admin.cadastrarAluno(n, m, p)) {
        std::cout << "Aluno cadastrado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao cadastrar aluno." << std::endl;
    }

return 0;
}
