#include "ls/sql/Config.h"
#include "ls/DefaultLogger.h"
#include "ls/json/API.h"
#include "iostream"
#include "exception"
using namespace std;

namespace ls
{
    using namespace json;
    namespace sql
    {
		Config::Config()
		{
			load();
		}

		string Config::getConfigPath() 
		{
			char *configPath = getenv("LS_SQLCONFIG");
			if(configPath == NULL)
				configPath = (char *)"sql.json";
			return configPath;
		}

		void Config::init()
		{
			json::api.get(root, "url", url);
			json::api.get(root, "username", username);
			json::api.get(root, "password", password);
			json::api.get(root, "size", size);

			LOGGER(ls::INFO) << "url: " << url << ls::endl;
			LOGGER(ls::INFO) << "username: " << username << ls::endl;
			LOGGER(ls::INFO) << "password: " << password << ls::endl;
			LOGGER(ls::INFO) << "size: " << size << ls::endl;
		}
    }
}
