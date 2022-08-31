#include "ls/sql/Item.h"

namespace ls
{
	namespace sql
	{
		class Int : public Item
		{
			public:
				Int(int value);
				void addTo(::sql::PreparedStatement *ps, int pos) override;
			private:
				int value;
		};
	}
}
