#ifndef LS_SQL_LONGLONG_H
#define LS_SQL_LONGLONG_H

#include "ls/sql/Item.h"

namespace ls
{
	namespace sql
	{
		class LongLong : public Item
		{
			public:
				LongLong(long long value);
				void addTo(::sql::PreparedStatement *ps, int pos) override;
			private:
				long long value;
		};
	}
}

#endif
