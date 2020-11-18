#include "ls/sql/Command.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		Command::Command(ConnectionPool &pool, 
				const std::string &sql, 
				vector<Parameter *> parameters) : 
					pool(pool),
					parameters(parameters.begin(), parameters.end()),
					connection(pool.Get()), 
					ps(connection -> prepareStatement(sql)),
					rs(nullptr)
		{
			SetParameters();
		}
			
		void Command::SetParameters()
		{
			for(int i=0;i<parameters.size();++i)
				parameters[i] -> AddTo(ps, i+1);
		}

		Command::~Command()
		{
			if(rs)
				rs -> close();
			if(ps)
				ps -> close();
			if(connection)
				pool.Put(connection);
		}
		void Command::Update()
		{
			ps -> executeUpdate();
		}

		void Command::Query(Table *table)
		{
			rs = ps -> executeQuery();
			table -> ParseFrom(rs);
		}
	}
}
