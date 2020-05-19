#include "User.h"
#include <vector>
#include<cstring>
#include<sstream>


User::User()
{
}

User::User(string u, string p) :userName(u), password(p)
{
}

string User::getUserName()
{
	return userName;
}

string User::getPassword()
{
	return password;
}

void User::setUserName(string u)
{
	userName = u;
}

void User::setPassword(string p)
{
	password = p;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

string User::toString(char delim)
{
	return this->userName + delim + this->password;
}

ostream& operator<<(ostream& os, const User u)
{
	os << u.userName << " " << u.password << endl;
	return os;
}


User::~User()
{
}


User::User(string args, char delim)
{
	vector<string> v = split(args, delim);
	this->userName = v[0];
	this->password = v[1];
}

vector<string> User::split(const string& s, char delim)
{
	vector<string>result;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
	{
		result.push_back(item);
	}
	return result;
}