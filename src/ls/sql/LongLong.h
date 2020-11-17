#ifndef LS_SQL_LONGLONG_H
#define LS_SQL_LONGLONG_H

#include "ls/sql/Parameter.h"

namespace ls
{
	namespace sql
	{
		class LongLong : public Parameter
		{
			public:
				LongLong(long long value);
				void AddTo(::sql::PreparedStatement *ps, int pos) override;
			private:
				long long value;
		};
	}
}

#endif
