#ifndef LS_SQL_COMMAND_H
#define LS_SQL_COMMAND_H

#include "ls/sql/ConnectionPool.h"
#include "ls/sql/Item.h"
#include "ls/sql/Table.h"
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
					std::vector<Item *> &parameters);
				~Command();
				void update();
				void query(Table *table);
			protected:
				void setParameters(std::vector<Item *> &paramters);
				ConnectionPool &pool;
				std::vector<Item *> parameters;
				::sql::Connection *connection;
				::sql::PreparedStatement *ps;
				::sql::ResultSet *rs;
		};
	}
}

#endif
