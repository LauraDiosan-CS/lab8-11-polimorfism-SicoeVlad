#include <iostream>
#include <assert.h>
#include "Actor.h"
#include "Concert.h"
#include "Film.h"
#include "Repo.h"
#include "Teste.h"
#include "Service.h"
#include <vector>

using namespace std;

void runTest()
{
	void testActorSuccesful();
	void testFilmSuccesful();
	void testConcertSuccesful();
	void testRepoSuccesful();
	void testServiceSuccesful();
	cout << "Testele au trecut cu succes! :)" << endl;
}

void testActorSuccesful()
{
	void testSetGetActorSuccesful();
	void testCompareActorSuccesful();
}

void testSetGetActorSuccesful()
{
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	a1.setNume("Mihai");
	assert(a1.getNume() == "Mihai");
	assert(a2.getNume() == "Andrei");
}

void testCompareActorSuccesful()
{
	Actor a1 = Actor("George");
	Actor a2 = a1;
	assert(a2 == a1);
}

void testFilmSuccesful()
{
	void testSetGetFilmSuccesful();
	void testCompareFilmSuccesful();
}

void testSetGetFilmSuccesful()
{
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	vector<Actor> lista = vector <Actor>{ a1, a2 };
	Film f = Film("Titanic", lista, "12/05/2010", "Londra", 100, 100);
	f.setData("18/05/2010");
	f.setNrLocDisp(105);
	assert(f.getTitlu() == "Titanic");
	assert(f.getData() == "18/05/2010");
	assert(f.getLoc() == "Londra");
	assert(f.getNrLocDisp() == 105);
	assert(f.getNrLocVandut() == 100);
}

void testCompareFilmSuccesful()
{
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	vector<Actor> lista = vector <Actor>{ a1, a2 };
	Film f1 = Film("Titanic", lista, "12/05/2010", "Londra", 100, 100);
	Film f2 = f1;
	assert(f1 == f2);
}


void testConcertSuccesful()
{
	void testSetGetConcertSuccesful();
	void testCompareConcertSuccesful();
}

void testSetGetConcertSuccesful()
{
	Concert c1 = Concert("John Lenon", "10/04/1998", "Paris", 2000, 1998);
	c1.setLoc("Londra");
	c1.setNrLocVandut(2000);
	assert(c1.getNume() == "John Lenon");
	assert(c1.getData() == "10/04/1998");
	assert(c1.getNrLocDisp() == 2000);
	assert(c1.getNrLocVandut() == 2000);
}

void testCompareConcertSuccesful()
{
	Concert c1 = Concert("John Lenon", "10/04/1998", "Paris", 2000, 1998);
	Concert c2 = c1;
	assert(c1 == c2);
}

void testRepoSuccesful()
{
	void testRepoAddElemSuccesful();
	void testRepoDeleteElemSuccesful();
	void testRepoSetElemSuccesful();
}

void testRepoAddElemSuccesful()
{
	Repo <Film> r;
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	Actor a3 = Actor("Ioan");
	Actor a4 = Actor("Mihai");
	vector<Actor> lista = vector <Actor>{ a1, a2 };
	vector<Actor> lista2 = vector <Actor>{ a3, a4 };
	Film f1 = Film("Titanic", lista, "12/05/2010", "Londra", 100, 100);
	Film f2 = Film("The Greatest Showman", lista2, "04/08/2014", "Manchester", 1000, 1000);
	r.addElem(f1);
	r.addElem(f2);
	assert(r.getSize() == 2);
}

void testRepoDeleteElemSuccesful()
{
	Repo <Film> r;
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	Actor a3 = Actor("Ioan");
	Actor a4 = Actor("Mihai");
	vector<Actor> lista = vector <Actor>{ a1, a2 };
	vector<Actor> lista2 = vector <Actor>{ a3, a4 };
	Film f1 = Film("Titanic", lista, "12/05/2010", "Londra", 100, 100);
	Film f2 = Film("The Greatest Showman", lista2, "04/08/2014", "Manchester", 1000, 1000);
	r.addElem(f1);
	r.addElem(f2);
	r.remove(2);
	assert(r.getSize() == 1);
}

void testRepoSetElemSuccesful()
{
	Repo <Film> r;
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	Actor a3 = Actor("Ioan");
	Actor a4 = Actor("Mihai");
	vector<Actor> lista = vector <Actor>{ a1, a2 };
	vector<Actor> lista2 = vector <Actor>{ a3, a4 };
	Film f1 = Film("Titanic", lista, "12/05/2010", "Londra", 100, 100);
	Film f2 = Film("The Greatest Showman", lista2, "04/08/2014", "Manchester", 1000, 1000);
	r.addElem(f1);
	r.addElem(f2);
	r.setElemPos(3, f2);
	Film f3 = r.getElemPos(3);
	assert(f2 == f3);
}


void testServiceSuccesful()
{
	
	void testAddFilmSuccesful();
	void testAddConcertSuccesful();
	void testLogareSuccesful();
}



void testAddFilmSuccesful()
{
	Service serv;
	Repo<Film> rf;
	Actor a1 = Actor("George");
	Actor a2 = Actor("Andrei");
	vector<Actor> lista = vector <Actor>{ a1, a2 };
	Film f1 = Film("Titanic", lista, "12/05/2010", "Londra", 100, 100);
	serv.addFilmTxt(f1);
	assert(rf.getSize() == 1);
}

void testAddConcertSuccesful()
{
	Service serv;
	Repo<Concert> rc;
	Concert c1 = Concert("John Lenon", "10/04/1998", "Paris", 2000, 1998);
	serv.addConcertTxt(c1);
	assert(rc.getSize() == 1);
}

void testLogareSuccesful()
{
	Service serv;
	string nume, parola;
	nume = "Ana";
	parola = "123";
	assert(serv.LogIn(nume, parola));
}

