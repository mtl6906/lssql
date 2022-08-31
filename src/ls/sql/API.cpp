#include "ls/sql/API.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		API api;

		void API::update(const string &sql, vector<Item *> &&parameters)
		{
			Command command(pool, sql, parameters);
			command.update();
		}

		void API::query(const string &sql, vector<Item *> &&parameters, Table *table)
		{
			Command command(pool, sql, parameters);
			command.query(table);
		}
	}
}
