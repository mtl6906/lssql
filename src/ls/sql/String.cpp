#include "ls/sql/String.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		String::String(const string& value) : value(value)
		{
			
		}

		void String::addTo(::sql::PreparedStatement *ps, int pos)
		{
			ps -> setString(pos, value);
		}
	}
}
