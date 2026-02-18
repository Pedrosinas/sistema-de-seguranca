#ifndef DATABASE_H
#define DATABASE_H

#include<mariadb/mysql.h>
#include<string>

class Database {
	private:
		MYSQL* connection;

	public:
		Database();
		~Database();		

		bool conectar(const std::string& host,
	                  const std::string& user,
    	              const std::string& password,
        	          const std::string& db);

		void desconectar();
};
#endif
