#include "iostream"
#include "memory"
#include "ls/sql/API.h"
#include "ls/sql/String.h"
#include "ls/sql/Int.h"
#include "ls/sql/API.h"


using namespace std;
using namespace ls::sql;

class User
{
	public:
		string username;
		string password;
		string email;
};

class UserTable : public ls::sql::Table
{
	public:
		UserTable()
		{
			
		}
		void parseFrom(::sql::ResultSet *rs) override
		{
			while(rs -> next())
			{
				User *user = new User();
				user -> username = rs -> getString("username");
				user -> password = rs -> getString("password");
				user -> email = rs -> getString("email");
				data.push_back(user);
			}
		}
		vector<User *> &getData()
		{
			return data;
		}
	private:
		vector<User *> data;
};

void PrintContent(UserTable &userTable)
{
	cout << "username\tpassword\temail" << endl;
	auto &data = userTable.getData();
	for(auto user : data)
	{
		cout << user -> username << "\t";
		cout << user -> password << "\t";
		cout << user -> email << "\t";
		cout << endl;
	}
}

int main()
{	
	int number;
	const string createUser = "create table user(username varchar(255) not null, password varchar(255) not null, email varchar(255) not null, primary key(username));";
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
			api.update(createUser, {});
		}
		else if(number == 2)
		{
			string username, password, email;
			cout << "input username, password, email:" << endl;
			cin >> username >> password >> email;
			api.update(insertUser, {
				new String(username),
				new String(password), 
				new String(email)
			});
		}
		else if(number == 3)
		{
			UserTable userTable;
			api.query(selectUser, {}, &userTable);
			PrintContent(userTable);
		}
		else if(number == 4)
		{
			string username;
			cout << "input username:" << endl;
			cin >> username;
			api.update(deleteUser, {new String(username)});
		}
		else if(number == 5)
			break;
	}
	return 0;
}
