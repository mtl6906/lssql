#ifndef LS_SQL_TABLE_H
#define LS_SQL_TABLE_H

#include "mysql/jdbc.h"

namespace ls
{
	namespace sql
	{
		class Table
		{
			public:
				virtual void parseFrom(::sql::ResultSet *rs) = 0;
				virtual ~Table() = default;
		};
	}
}

#endif
