#include "ls/sql/CommandFactory.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		CommandFactory *CommandFactory::instance = new CommandFactory();

		Command* CommandFactory::GetCommand(const string &sql, vector<Parameter *> &&parameters)
		{
			return new Command(pool, sql, parameters);
		}

		CommandFactory *CommandFactory::GetInstance()
		{
			return instance;
		}
	}
}
