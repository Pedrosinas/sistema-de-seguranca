#include"Administrador.h"

Administrador::Administrador(Database& database) : db(database)
{}

bool Administrador::cadastrarAluno(const std::string& nome,
								   const std::string& matricula,
								   const std::string& pasta){

	Aluno aluno(nome, matricula, pasta);
	
	std::string sql =
        "INSERT INTO alunos (nome, matricula, pasta) VALUES ('" +
        aluno.getNome() + "', '" +
        aluno.getMatricula() + "', '" +
        aluno.getPasta() + "');";

	return db.executar(sql);
}
