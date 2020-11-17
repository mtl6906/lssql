#include "ls/sql/SqlConfig.h"
#include "ls/util.h"

#define SQLCONFIG_LOG "SQLCONFIG_LOG"

namespace ls
{
    using namespace json;
    namespace sql
    {
		SqlConfig::SqlConfig()
		{
			char *configPath = getenv("LS_SQL_SQLCONFIG");
			if(configPath == NULL)
				configPath = (char *)"sql.json";
			Load(configPath);
			GET_STRING(root, "url", url);
			GET_STRING(root, "username", username);
			GET_STRING(root, "password", password);
			GET_INT(root, "size", size);

			ls_log_tag(SQLCONFIG_LOG, "url: %s", url.c_str());
			ls_log_tag(SQLCONFIG_LOG, "username: %s", username.c_str());
			ls_log_tag(SQLCONFIG_LOG, "password: %s", password.c_str());
			ls_log_tag(SQLCONFIG_LOG, "size: %d", size);
		}
    }
}