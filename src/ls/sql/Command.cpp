#include "ls/sql/Command.h"
#include "mysql/jdbc.h"
#include "ls/DefaultLogger.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		Command::Command(ConnectionPool &pool, 
				const std::string &sql, 
				vector<Item *> &parameters) : 
					pool(pool),
					connection(pool.get()),
					ps(connection -> prepareStatement(sql)),
					rs(nullptr)
		{
			setParameters(parameters);
		}
			
		void Command::setParameters(vector<Item *> &parameters)
		{
			for(int i=0;i<parameters.size();++i)
				parameters[i] -> addTo(ps, i+1);
			for(auto &it : parameters)
				delete it;
		}

		Command::~Command()
		{
			if(rs)
				rs -> close();
			if(ps)
				ps -> close();
			if(connection)
				pool.put(connection);
		}
		void Command::update()
		{
			ps -> executeUpdate();
		}

		void Command::query(Table *table)
		{
			rs = ps -> executeQuery();
			table -> parseFrom(rs);
		}
	}
}
