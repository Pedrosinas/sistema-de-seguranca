#ifndef ALUNO_H
#define ALUNO_H	

#include<string>

class Aluno {
	private:
    	std::string nome;
	    std::string matricula;
   		std::string pasta;

	public:
    	Aluno();
	    Aluno(const std::string& nome,
    	      const std::string& matricula,
        	  const std::string& pasta);

	    std::string getNome() const;
    	std::string getMatricula() const;
	    std::string getPasta() const;

	    void setNome(const std::string& nome);
    	void setMatricula(const std::string& matricula);
	    void setPasta(const std::string& pasta);
};
#endif
