#ifndef LS_SQL_CONNECTIONPOOL_H
#define LS_SQL_CONNECTIONPOOL_H

#include "ls/sql/Config.h"
#include "mysql/jdbc.h"
#include "queue"
#include "mutex"

namespace ls
{
	namespace sql
	{
		class ConnectionPool
		{
			public:
				ConnectionPool();
				~ConnectionPool();
				::sql::Connection *get();
				void put(::sql::Connection *Connection);
			private:
				sql::Config config;
				::sql::Driver *driver;
				std::queue<::sql::Connection *> pool;
				std::mutex poolMutex;
		};
	}
}

#endif
