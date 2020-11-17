#ifndef LS_SQL_STRING_H
#define LS_SQL_STRING_H

#include "ls/sql/Parameter.h"

namespace ls
{
	namespace sql
	{
		class String : public Parameter
		{
			public:
				String(std::string &value);
				void AddTo(::sql::PreparedStatement *ps, int pos) override;
			private:
				std::string &value;
		};
	}
}

#endif
