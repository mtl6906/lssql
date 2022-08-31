#ifndef LS_SQL_API_H
#define LS_SQL_API_H

#include "ls/sql/Command.h"
#include "memory"

namespace ls
{
	namespace sql
	{
		class API
		{
			public:
				void update(const std::string &sql, std::vector<Item *> &&parameters);
				void query(const std::string &sql, std::vector<Item *> &&parameter, Table *table);
			private:
				ConnectionPool pool;
		};
		extern API api;
	}
}

#endif
