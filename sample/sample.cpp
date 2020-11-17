#include "iostream"
#include "memory"
#include "ls/sql/CommandFactory.h"
#include "ls/sql/String.h"
#include "ls/sql/Int.h"


using namespace std;
using namespace ls::sql;

void PrintContent(vector<vector<string>> &table)
{
	cout << "username\tpassword\temail" << endl;
	for(auto &row : table)
	{
		for(auto &col : row)
			cout << col << "\t";
		cout << endl;
	}
}

int main()
{	
	int number;
	const string createUser = "create table user(username varchar(255) not null, password varchar(255) not null, emall varchar(255) not null, primary key(username));";
	const string insertUser = "insert into user(username, password, email) values(?, ?, ?);";
	const string selectUser = "select username, password, email from user;";
	const string deleteUser = "delete from user where username = ?;";
	for(;;)
	{
		cout << "1. createUser" << endl;
		cout << "2. insertUser" << endl;
	       	cout << "3. selectAllUser" << endl;
		cout << "4. deleteUser"	<< endl;
		cout << "5. exit";
		cin >> number;
		if(number == 1)
		{
			unique_ptr<Command> command(CommandFactory::GetInstance() -> GetCommand(createUser, {}));
			command -> Update();
		}
		else if(number == 2)
		{
			string username, password, email;
			cout << "input username, password, email:" << endl;
			cin >> username >> password >> email;
			unique_ptr<Command> command(CommandFactory::GetInstance() -> GetCommand(insertUser, {
				new String(username), 
				new String(password), 
				new String(email)
			}));
			command -> Update();
		}
		else if(number == 3)
		{
			unique_ptr<Command> command(CommandFactory::GetInstance() -> GetCommand(selectUser, {}));
			auto table = command -> Query();
			PrintContent(table);
		}
		else if(number == 4)
		{
			string username;
			cout << "input username:" << endl;
			cin >> username;
			unique_ptr<Command> command(CommandFactory::GetInstance() -> GetCommand(deleteUser, {new String(username)}));
			command -> Update();
		}
		else if(number == 5)
			break;
	}
	return 0;
}
