#include "ls/sql/Parameter.h"

namespace ls
{
	namespace sql
	{
		class Int : public Parameter
		{
			public:
				Int(int value);
				void AddTo(::sql::PreparedStatement *ps, int pos) override;
			private:
				int value;
		};
	}
}
