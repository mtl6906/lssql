#ifndef LS_SQL_SQLCONFIG_H
#define LS_SQL_SQLCONFIG_H

#include "ls/Config.h"

namespace ls
{
    namespace sql
    {
        class Config : public ls::Config
        {
            public:  
		Config();
		std::string getConfigPath() override;
		void init() override;
                std::string url;
                std::string username;
                std::string password;
                int size;
	};
    }
}

#endif
