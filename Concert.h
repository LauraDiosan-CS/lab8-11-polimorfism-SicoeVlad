#pragma once
#include "Eveniment.h"
using namespace std;

class Concert : public Eveniment {
private:
	string nume;
public:
	Concert();
	Concert(string n, string d, string l, int nrLD, int nrLV);
	Concert(string ags, char delim);
	Concert(const Concert& c);
	~Concert();
	void setNume(string n);
	string getNume();
	Concert& operator=(const Concert& c);
	int operator==(const Concert& c);
	string toString(char delim);
	friend ostream& operator<<(ostream& os, Concert c);
	
};