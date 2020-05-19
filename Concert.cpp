#include "Concert.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

Concert::Concert():Eveniment()
{
	
	this->nume = " ";
}

Concert::Concert(string n, string d, string l, int nrLD, int nrLV):Eveniment(d, l, nrLD, nrLV)
{
	
	this->nume = n;
}

Concert::Concert(string ags, char sep)
{

	vector<string> result;
	stringstream ss(ags);
	string item;
	while (getline(ss, item, sep))
	{
		result.push_back(item);
	}
	
	vector<string> v = result;
	this->nume = v[0];
	this->data = v[1];
	this->loc = v[2];
	this->nrLocDisp = stoi(v[3]);
	this->nrLocVandut = stoi(v[4]);
}


Concert::Concert(const Concert& c) : Eveniment(c)
{
	
	this->nume = c.nume;
}

Concert::~Concert()
{
	
}

void Concert::setNume(string n)
{
	this->nume = n;
}

string Concert::getNume()
{
	return this->nume;
}

Concert& Concert::operator=(const Concert& c)
{
	if (this != &c)
	{
		this->nume = c.nume;
	}
	return *this;
}

int Concert::operator==(const Concert& c)
{
	return (this->nume == c.nume);
}

string Concert::toString(char delim)
{
	return this->nume + delim + this->data + delim + this->loc + delim + to_string(this->nrLocDisp) + delim + to_string(this->nrLocVandut);
}

ostream& operator<<(ostream & os, Concert c)
{
	os << c.nume << " " << c.data << " " << c.loc << " " << c.nrLocDisp << " " << c.nrLocVandut << endl;
	return os;
}
