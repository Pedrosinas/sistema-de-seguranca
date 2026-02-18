#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include"Database.h"
#include"Aluno.h"

class Administrador{
	private:
		Database& db;
	public:
		Administrador(Database& database){
				bool cadastrarAluno(const Aluno& aluno);
		}
};
#endif
