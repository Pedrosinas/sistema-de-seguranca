#include "Database.h"
#include <iostream>

Database::Database() {
    connection = mysql_init(nullptr);

    if (!connection) {
        ultimoErro = "Erro ao inicializar MySQL.";
        std::cout << ultimoErro << std::endl;
    }
}

Database::~Database() {
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
        ultimoErro = mysql_error(connection);
        std::cout << "Erro de conexão: " << ultimoErro << std::endl;
        return false;
    }

    ultimoErro = "";
    std::cout << "Conectado." << std::endl;
    return true;
}

void Database::desconectar() {
    if (connection) {
        mysql_close(connection);
        connection = nullptr;
    }
}

bool Database::executar(const std::string& sql) {
    if (mysql_query(connection, sql.c_str())) {
        ultimoErro = mysql_error(connection);
        std::cout << "Erro na query: " << ultimoErro << std::endl;
        return false;
    }

    ultimoErro = "";
    return true;
}
