#pragma once
#include "Eveniment.h"
#include "Actor.h"
#include <vector>
using namespace std;

class Film : public Eveniment {
private:
	string titlu;
	vector<Actor> lista;
public:
	Film();
	Film(string t, vector<Actor> lst, string d, string l, int nrLD, int nrLV);
	Film(string ags, char delim);
	Film(const Film& f);
	~Film();
	void setTitlu(string t);
	string getTitlu();
	vector<Actor> getLista();
	void setLista(vector<Actor> act);
	Film& operator=(const Film& f);
	int operator==(const Film& f);
	string toString(char delim);
	friend ostream& operator<<(ostream& os, Film f);
	
};