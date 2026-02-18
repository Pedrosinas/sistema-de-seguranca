#include<iostream>
#include"Aluno.h"
#include"Database.h"

void exibirAluno(const Aluno& aluno) {
    std::cout << "Nome: " << aluno.getNome() << std::endl;
    std::cout << "Matrícula: " << aluno.getMatricula() << std::endl;
    std::cout << "Pasta: " << aluno.getPasta() << std::endl;
}

int main(int argc, char *argv[]) {

	Aluno aluno1("Pedro", "202310490021","61476");

	exibirAluno(aluno1);

    Database db;

	db.conectar("localhost", "iff_user", "1234", "sistema_de_seguranca");

return 0;
}
