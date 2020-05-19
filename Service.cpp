#include "Service.h"
#include<sstream>
#include "VectorException.h"
#include<iostream>
#include "User.h"
using namespace std;

Service::Service()
{
}

Service::Service(RepoFile<User> rUser, RepoFileTxt<Film> rFilmTxt, RepoFileTxt<Concert> rConcertTxt, RepoFileCsv<Film> rFilmCsv, RepoFileCsv<Concert> rConcertCsv)
{
	this->ru = rUser;
	this->rft = rFilmTxt;
	this->rct = rConcertTxt;
	this->rfc = rFilmCsv;
	this->rcc = rConcertCsv;
}

int Service::findUser(string nume)
{
	for (int i = 0; i < this->ru.getSize(); i++)
	{
		if (nume == this->ru.getAll()[i].getUserName())
			return i;
	}
	return -1;
}

int Service::findFilmTxt(string nume)
{
	for (int i = 0; i < this->rft.getSize(); i++)
	{
		if (nume == this->rft.getAll()[i].getTitlu())
			return i;
	}
	return -1;
}

int Service::findFilmCsv(string nume)
{
	for (int i = 0; i < this->rfc.getSize(); i++)
	{
		if (nume == this->rfc.getAll()[i].getTitlu())
			return i;
	}
	return -1;
}

int Service::findConcertTxt(string nume)
{
	for (int i = 0; i < this->rct.getSize(); i++)
	{
		if (nume == this->rct.getAll()[i].getNume())
			return i;
	}
	return -1;
}

int Service::findConcertCsv(string nume)
{
	for (int i = 0; i < this->rcc.getSize(); i++)
	{
		if (nume == this->rcc.getAll()[i].getNume())
			return i;
	}
	return -1;
}

Film Service::findFilmTxtByName(string nume)
{
	Film f;
	for (int i = 0; i < this->rft.getSize(); i++)
	{
		if (this->rft.getAll()[i].getTitlu() == nume)
		{
			return this->rft.getAll()[i];
		}
	}
	return f;
}

Film Service::findFilmCsvByName(string nume)
{
	Film f;
	for (int i = 0; i < this->rfc.getSize(); i++)
	{
		if (this->rfc.getAll()[i].getTitlu() == nume)
		{
			return this->rfc.getAll()[i];
		}
	}
	return f;
}

string Service::getParola(int poz)
{
	if (poz >= 0 && poz < this->ru.getSize())
		return this->ru.getAll()[poz].getPassword();
}

bool Service::creareCont(string user, string pass)
{
	if (this->findUser(user) != -1)
	{
		return false;


	}
	else
	{
		User aux(user, pass);
		this->ru.addElem(aux);
		return true;
	}
}


bool Service::LogIn(string nume, string parola)
{
	int val = this->findUser(nume);
	if (val == -1)
	{
		return false;
	}
	else
	{ 
		if (this->getParola(val) == parola)
		{
			return true;
		}
		return true;
	}
}

Repo<User> Service::getUsers()
{
	return this->ru;
}

RepoFileTxt<Film> Service::getFilmTxt()
{
	return this->rft;
}

RepoFileTxt<Concert> Service::getConcertTxt()
{
	return this->rct;
}

RepoFileCsv<Film> Service::getFilmCsv()
{
	return this->rfc;
}

RepoFileCsv<Concert> Service::getConcertCsv()
{
	return this->rcc;
}

void Service::loadFileTxt(string fileNameFilme, string fileNameConcerte)
{

	this->rft.setFileName(fileNameFilme);
	this->rft.loadFromFile();
	this->rct.setFileName(fileNameConcerte);
	this->rct.loadFromFile();
}

void Service::loadFileCsv(string fileNameFilme, string fileNameConcert)
{
	this->rfc.setFileName(fileNameFilme);
	this->rfc.loadFromFile();
	this->rcc.setFileName(fileNameConcert);
	this->rcc.loadFromFile();
}
void Service::saveFileTxt()
{
	this->rft.saveToFile();
	this->rct.saveToFile();
}

void Service::saveFileCsv()
{
	this->rfc.saveToFile();
	this->rcc.saveToFile();
}

void Service::addFilmTxt(Film f)
{
	rft.addElem(f);
}

void Service::addFilmCsv(Film f)
{
	rfc.addElem(f);
}

void Service::addConcertTxt(Concert c)
{
	rct.addElem(c);
}

void Service::addConcertCsv(Concert c)
{
	rcc.addElem(c);
}



bool Service::delUser(int poz)
{
	try {

		this->ru.remove(poz);
		return true;
	}
	catch (VectorException& exceptie)
	{
		cout << "exception :" << exceptie.what() << endl;
		return false;
	}
	
}

bool Service::delFilmTxt(int poz)
{
	try {

		this->rft.remove(poz);
		return true;
	}
	catch (VectorException& exceptie)
	{
		cout << "exception :" << exceptie.what() << endl;
		return false;
	}
}

bool Service::delFilmCsv(int poz)
{
	try {

		this->rfc.remove(poz);
		return true;
	}
	catch (VectorException& exceptie)
	{
		cout << "exception :" << exceptie.what() << endl;
		return false;
	}
}

bool Service::delConcertTxt(int poz)
{
	try {

		this->rct.remove(poz);
		return true;
	}
	catch (VectorException& exceptie)
	{
		cout << "exception :" << exceptie.what() << endl;
		return false;
	}
}

bool Service::delConcertCsv(int poz)
{
	try {

		this->rcc.remove(poz);
		return true;
	}
	catch (VectorException& exceptie)
	{
		cout << "exception :" << exceptie.what() << endl;
		return false;
	}
}


int Service::showDataTxt(int poz)
{
	this->rft.getElemPos(poz);
	return true;
}

bool Service::cumparareBiletFilmtxt(string nume, int nr)
{
	for (int i = 0; i < this->rft.getSize(); i++)
	{
		if (this->rft.getAll()[i].getTitlu() == nume)
		{
			if (rft.getAll()[i].getNrLocDisp() >= nr)
			{
				int nrLibere = this->rft.getAll()[i].getNrLocDisp();
				int nrOcupate = this->rft.getAll()[i].getNrLocVandut();
				nrLibere -= nr;
				nrOcupate += nr;

				Film f;
				f.setTitlu(nume);
				f.setData(this->rft.getAll()[i].getData());
				f.setLista(this->rft.getAll()[i].getLista());
				f.setLoc(this->rft.getAll()[i].getLoc());
				f.setNrLocDisp(nrLibere);
				f.setNrLocVandut(nrOcupate);
				this->rft.modify(i, f);
				this->rft.saveToFile();
				return true;
			}
		}
	}
	return false;
}

bool Service::cumparareBiletConcertTxt(string nume, int nr)
{
	for (int i = 0; i < this->rct.getSize(); i++)
	{
		if (this->rct.getAll()[i].getNume() == nume)
		{
			if (rct.getAll()[i].getNrLocDisp() >= nr)
			{
				int nrLibere = this->rct.getAll()[i].getNrLocDisp();
				int nrOcupate = this->rct.getAll()[i].getNrLocVandut();
				nrLibere -= nr;
				nrOcupate += nr;

				Concert c;
				c.setNume(nume);
				c.setData(this->rct.getAll()[i].getData());
				c.setLoc(this->rct.getAll()[i].getLoc());
				c.setNrLocDisp(nrLibere);
				c.setNrLocVandut(nrOcupate);
				this->rct.modify(i, c);
				this->rct.saveToFile();
				return true;
			}
		}
	}
	return false;
}

Concert Service::findArtistTxt(string artist)
{
	Concert c;
	for (int i = 0; i < this->rct.getSize(); i++)
	{
		if (this->rct.getAll()[i].getNume() == artist)
		{
			return this->rct.getAll()[i];
		}
	}
	return c;
}

Concert Service::findArtistCsv(string artist)
{
	Concert c;
	for (int i = 0; i < this->rcc.getSize(); i++)
	{
		if (this->rcc.getAll()[i].getNume() == artist)
		{
			return this->rcc.getAll()[i];
		}
	}
	return c;
}

bool Service::cumparareBiletFilmCsv(string nume, int nr)
{
	for (int i = 0; i < this->rfc.getSize(); i++)
	{
		if (this->rfc.getAll()[i].getTitlu() == nume)
		{
			if (rfc.getAll()[i].getNrLocDisp() >= nr)
			{
				int nrLibere = this->rfc.getAll()[i].getNrLocDisp();
				int nrOcupate = this->rfc.getAll()[i].getNrLocVandut();
				nrLibere -= nr;
				nrOcupate += nr;

				Film f;
				f.setTitlu(nume);
				f.setData(this->rfc.getAll()[i].getData());
				f.setLista(this->rfc.getAll()[i].getLista());
				f.setLoc(this->rfc.getAll()[i].getLoc());
				f.setNrLocDisp(nrLibere);
				f.setNrLocVandut(nrOcupate);
				this->rfc.modify(i, f);
				this->rfc.saveToFile();
				return true;
			}
		}
	}
	return false;
}


bool Service::cumparareBiletConcertCsv(string nume, int nr)
{
	for (int i = 0; i < this->rcc.getSize(); i++)
	{
		if (this->rcc.getAll()[i].getNume() == nume)
		{
			if (rcc.getAll()[i].getNrLocDisp() >= nr)
			{
				int nrLibere = this->rcc.getAll()[i].getNrLocDisp();
				int nrOcupate = this->rcc.getAll()[i].getNrLocVandut();
				nrLibere -= nr;
				nrOcupate += nr;

				Concert c;
				c.setNume(nume);
				c.setData(this->rcc.getAll()[i].getData());
				c.setLoc(this->rcc.getAll()[i].getLoc());
				c.setNrLocDisp(nrLibere);
				c.setNrLocVandut(nrOcupate);
				this->rcc.modify(i, c);
				this->rcc.saveToFile();
				return true;
			}
		}
	}
	return false;
}
