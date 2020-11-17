#include "ls/sql/String.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		String::String(string& value) : value(value)
		{
			
		}

		void String::AddTo(::sql::PreparedStatement *ps, int pos)
		{
			ps -> setString(pos, value);
		}
	}
}
