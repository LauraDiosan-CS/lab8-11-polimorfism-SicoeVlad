#pragma once
#include <iostream>
#include <string>
using namespace std;

class Actor
{
private:
	string numeActor;
public:
	Actor();
	Actor(string n);
	Actor(const Actor& a);
	string getNume();
	void setNume(string n);
	Actor& operator=(const Actor& a);
	int operator==(const Actor& a);
	~Actor();

};
