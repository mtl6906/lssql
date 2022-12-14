#include "ls/sql/ConnectionPool.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		ConnectionPool::ConnectionPool() : driver(get_driver_instance())
		{
			for(int i=0;i<config.size;++i)
			{
				auto connection = driver -> connect(config.url, config.username, config.password);
				pool.push(connection);
			}
		}

		ConnectionPool::~ConnectionPool()
		{
			while(!pool.empty())
			{
				delete pool.front();
				pool.pop();
			}
		}

		void ConnectionPool::put(::sql::Connection *connection)
		{
			lock_guard<mutex> poolLock(poolMutex);
			pool.push(connection);
		}

		::sql::Connection *ConnectionPool::get()
		{
			lock_guard<mutex> poolLock(poolMutex);
			auto it = pool.front();
			pool.pop();
			return it;
		}
	}
}
