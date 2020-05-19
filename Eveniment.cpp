#include "Eveniment.h"

Eveniment::Eveniment()
{
	this->data = " ";
	this->loc = " ";
	this->nrLocDisp = 0;
	this->nrLocVandut = 0;
}

Eveniment::Eveniment(string d, string l, int nrLD, int nrLV)
{
	this->data = d;
	this->loc = l;
	this->nrLocDisp = nrLD;
	this->nrLocVandut = nrLV;
}

Eveniment::Eveniment(const Eveniment& e)
{
	this->data = e.data;
	this->loc = e.loc;
	this->nrLocDisp = e.nrLocDisp;
	this->nrLocVandut = e.nrLocVandut;
}


string Eveniment::getData()
{
	return this->data;
}

string Eveniment::getLoc()
{
	return this->loc;
}

int Eveniment::getNrLocDisp()
{
	return this->nrLocDisp;
}

int Eveniment::getNrLocVandut()
{
	return this->nrLocVandut;
}


void Eveniment::setData(string d)
{
	this->data = d;
}

void Eveniment::setLoc(string l)
{
	this->loc = l;
}

void Eveniment::setNrLocDisp(int nrLD)
{
	this->nrLocDisp = nrLD;
}

void Eveniment::setNrLocVandut(int nrLV)
{
	this->nrLocVandut = nrLV;
}

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		this->data = e.data;
		this->loc = e.loc;
		this->nrLocDisp = e.nrLocDisp;
		this->nrLocVandut = e.nrLocVandut;
	}
	return *this;
}

string Eveniment::toString(char delim)
{
	return this->data + delim + this->loc + delim + to_string(this->nrLocDisp) + delim + to_string(this->nrLocVandut);
}

ostream& operator<<(ostream& os, Eveniment ev)
{
	os << ev.data << " " << ev.loc << " " << ev.nrLocDisp << " " << ev.nrLocVandut << endl;
	return os;
}


Eveniment::~Eveniment()
{

}

int Eveniment::operator==(const Eveniment& e)
{
	return ((this->data == e.data) && (this->loc == e.loc) && (this->nrLocDisp == e.nrLocDisp) && (this->nrLocVandut == e.nrLocVandut));
}
