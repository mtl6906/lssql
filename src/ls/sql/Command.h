#ifndef LS_SQL_COMMAND_H
#define LS_SQL_COMMAND_H

#include "ls/sql/ConnectionPool.h"
#include "ls/sql/Parameter.h"
#include "memory"

namespace ls
{
	namespace sql
	{
		class Command
		{
			public:
				Command(ConnectionPool &pool, 
					const std::string &sql, 
					std::vector<Parameter *> parameters);
				~Command();
				void Update();
				std::vector<std::vector<std::string>> Query();
			protected:
				void SetParameters();
				std::vector<std::vector<std::string>> ParseResultSetToTable();
				ConnectionPool &pool;
				std::vector<std::unique_ptr<Parameter>> parameters;
				::sql::Connection *connection;
				::sql::PreparedStatement *ps;
				::sql::ResultSet *rs;
		};
	}
}

#endif
