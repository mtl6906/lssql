#include "ls/sql/LongLong.h"

namespace ls
{
	namespace sql
	{
		LongLong::LongLong(long long value) : value(value)
		{
			
		}

		void LongLong::addTo(::sql::PreparedStatement *ps, int pos)
		{
			ps -> setInt64(pos, value);
		}
	}
}
