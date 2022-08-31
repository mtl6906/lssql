#ifndef LS_SQL_ITEM_H
#define LS_SQL_ITEM_H

#include "mysql/jdbc.h"

namespace ls
{
	namespace sql
	{
		class Item
		{
			public:
				virtual void addTo(::sql::PreparedStatement *ps, int pos) = 0;
				virtual ~Item() = default;
		};
	}
}

#endif
