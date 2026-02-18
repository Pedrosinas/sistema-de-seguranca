#include"Database.h"
#include<iostream>

Database::Database(){
	connection = mysql_init(nullptr);
}

Database::~Database(){
	desconectar();
}

bool Database::conectar(const std::string& host,
                        const std::string& user,
                        const std::string& password,
						const std::string& db) {
	
	if (!mysql_real_connect(connection,
							host.c_str(),
							user.c_str(),
                            password.c_str(),
                            db.c_str(),
							0, nullptr, 0)) {
		std::cout << "Erro de conexão: "
				  << mysql_error(connection) << std::endl;
		return false;
	}

	std::cout << "Conectado." << std::endl;
	return true;
}

void Database::desconectar(){
	if (connection){
		mysql_close(connection);
	}
}
