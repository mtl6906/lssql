#ifndef LS_SQL_COMMANDFACTORY_H
#define LS_SQL_COMMANDFACTORY_H

#include "ls/sql/Command.h"

namespace ls
{
	namespace sql
	{
		class CommandFactory
		{
			public:
				Command *GetCommand(const std::string &sql, std::vector<Parameter *> &&parameter);
				static CommandFactory* GetInstance();
			private:
				CommandFactory() = default;
				ConnectionPool pool;
				static CommandFactory* instance;
		};
	}
}

#endif
