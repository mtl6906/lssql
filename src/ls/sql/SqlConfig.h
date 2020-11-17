#ifndef LS_SQL_SQLCONFIG_H
#define LS_SQL_SQLCONFIG_H

#include "ls/Config.h"

namespace ls
{
    namespace sql
    {
        class SqlConfig : public ls::Config
        {
            public:  
                std::string url;
                std::string username;
                std::string password;
                int size;
                SqlConfig();
        };
    }
}

#endif