#include<iostream>
#include"Aluno.h"

void exibirAluno(const Aluno& aluno) {
    std::cout << "Nome: " << aluno.getNome() << std::endl;
    std::cout << "Matrícula: " << aluno.getMatricula() << std::endl;
    std::cout << "Pasta: " << aluno.getPasta() << std::endl;
}

int main(int argc, char *argv[]) {

	Aluno aluno1("Pedro", "202310490021","61476");

	exibirAluno(aluno1);

return 0;
}
