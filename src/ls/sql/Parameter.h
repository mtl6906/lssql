#ifndef LS_SQL_PARAMETER_H
#define LS_SQL_PARAMETER_H

#include "mysql/jdbc.h"

namespace ls
{
	namespace sql
	{
		class Parameter
		{
			public:
				virtual void AddTo(::sql::PreparedStatement *ps, int pos) = 0;
				virtual ~Parameter() = default;
		};
	}
}

#endif
