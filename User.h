#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User();
	User(string, string);
	User(string args, char delim);
	string getUserName();
	string getPassword();
	void setUserName(string);
	void setPassword(string);
	bool operator==(const User& u);
	friend ostream& operator<<(ostream& os, const User u);
	string toString(char delim);
	vector<string> split(const string&, char);
	~User();
};

