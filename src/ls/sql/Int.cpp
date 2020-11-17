#include "ls/sql/Int.h"

namespace ls
{
	namespace sql
	{
		Int::Int(int value) : value(value)
		{
		
		}

		void Int::AddTo(::sql::PreparedStatement *ps, int pos)
		{
			ps -> setInt(pos, value);
		}
	}
}
