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

		vector<vector<string>> Command::Query()
		{
			rs = ps -> executeQuery();
			return ParseResultSetToTable();
		}
	
		vector<vector<string>> Command::ParseResultSetToTable()
		{
			vector<vector<string>> table;
			int n = ps -> getMetaData() -> getColumnCount();
			while(rs -> next())
			{
				vector<string> row;
				for(int i=1;i<=n;++i)
					row.push_back(rs -> getString(i));
				table.push_back(std::move(row));
			}
			return table;
		}
	}
}
