#ifndef LS_SQL_STRING_H
#define LS_SQL_STRING_H

#include "ls/sql/Item.h"
#include "mysql/jdbc.h"

using namespace std;

namespace ls
{
	namespace sql
	{
		class String : public Item
		{
			public:
				String(const std::string &value);
				void addTo(::sql::PreparedStatement *ps, int pos) override;
			private:
				const std::string &value;
		};
	}
}

#endif
