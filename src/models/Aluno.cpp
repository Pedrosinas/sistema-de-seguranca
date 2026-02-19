#include"Aluno.h"
#include<iostream>

Aluno::Aluno() {}

Aluno::Aluno(const std::string& nome,
             const std::string& matricula,
             const std::string& pasta)
			: nome(nome), matricula(matricula), pasta(pasta)
{}

std::string Aluno::getNome() const{
	return nome;
}

std::string Aluno::getMatricula() const{
	return matricula;
}

std::string Aluno::getPasta() const{
	return pasta;
}

void Aluno::setNome(const std::string& nome){
	this->nome = nome;
}

void Aluno::setMatricula(const std::string& matricula){
	this->matricula = matricula;
}

void Aluno::setPasta(const std::string& pasta){
	this->pasta = pasta;
}
