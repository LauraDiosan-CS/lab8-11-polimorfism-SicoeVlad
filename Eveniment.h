#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Eveniment
{
protected:
	string data;
	string loc;
	int nrLocDisp;
	int nrLocVandut;
public:
	Eveniment();
	Eveniment(string d, string l, int nrLD, int nrLV);
	Eveniment(const Eveniment& e);
	string getData();
	string getLoc();
	int getNrLocDisp();
	int getNrLocVandut();
	void setData(string d);
	void setLoc(string l);
	void setNrLocDisp(int nrLD);
	void setNrLocVandut(int nrLV);
	Eveniment& operator=(const Eveniment& e);
	int operator==(const Eveniment& e);
	string toString(char delim);
	friend ostream& operator<<(ostream& os, Eveniment ev);
	~Eveniment();

};