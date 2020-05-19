#include "Film.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

Film::Film() :Eveniment()
{
	this->titlu = " ";
	this->lista = { };
}

Film::Film(string t, vector<Actor> lst, string d, string l, int nrLD, int nrLV) :Eveniment(d, l, nrLD, nrLV)
{
	this->titlu = t;
	this->lista = lst;
}

Film::Film(string ags, char sep)
{
	vector<string> result;
	stringstream ss(ags);
	string item;
	while (getline(ss, item, sep))
	{
		result.push_back(item);
	}

	vector<string> v = result;
	this->titlu = v[0];
	int nr;
	stringstream nf(v[1]);
	nf >> nr;
	int k = 1;
	vector<Actor> actori;
	for (int i = 0; i < nr; i++)
	{
		k++;
		string nume = v[k];
		Actor aux;
		aux.setNume(nume);
		actori.push_back(aux);
	}
	
	this->lista = actori;
	this->data = v[k + 1];
	this->loc = v[k + 2];
	this->nrLocDisp = stoi(v[k + 3]);
	this->nrLocVandut = stoi(v[k + 4]);

}

Film::Film(const Film& f) : Eveniment(f)
{
	this->titlu = f.titlu;
	this->lista = f.lista;
}

Film::~Film()
{
	
}

void Film::setTitlu(string t)
{
	this->titlu = t;
}

string Film::getTitlu()
{
	return this->titlu;
}

vector<Actor> Film::getLista()
{
	return this->lista;
}

void Film::setLista(vector<Actor> act)
{
	this->lista = act;
}

Film& Film::operator=(const Film& f)
{
	if (this != &f)
	{
		this->titlu = f.titlu;
		this->lista = f.lista;
	}
	return *this;
}

int Film::operator==(const Film& f)
{
	return (this->titlu == f.titlu);
}

string Film::toString(char delim)
{
	string actori;
	int nr = this->lista.size();
	string num;
	num = to_string(nr);


	for (int i = 0; i < this->lista.size(); i++)
	{
		actori = actori + this->lista[i].getNume() + delim;
	}
	return this->titlu + delim + num + delim + actori + this->data + delim + this->loc + delim + to_string(this->nrLocDisp) + delim + to_string(this->nrLocVandut);
}


ostream& operator<<(ostream& os, Film f)
{
	os << f.titlu << " " << f.data << " " << f.loc << " " << f.nrLocDisp << " " << f.nrLocVandut;
	return os;
}

