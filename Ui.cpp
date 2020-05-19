#include "Service.h"
#include "Ui.h"
#include "User.h"
#include <stdlib.h>
#include <iostream>

using namespace std;



UI::UI()
{

}

UI::~UI()
{

}

UI::UI(Service serv)
{
	this->s = serv;
}

void UI::creareUser()
{
	cout << "Creaza un user!" << endl;
	string nume;
	string parola;
	cout << "Nume: "; cin >> nume; cout << endl;
	cout << "Parola: "; cin >> parola; cout << endl;
	User u = User(nume, parola);
	if (this->s.creareCont(nume, parola) == true)
	{
		cout << "Contul a fost creat!" << endl;
	}
}

int UI::menu()
{
	cout << endl;
	cout << "1.Creare User" << endl;
	cout << "2.Logare" << endl;
	cout << "0.exit" << endl;
	int op;
	cin >> op;
	return op;
}

void UI::loadFileTxt(string fileNameFilmeTxt, string fileNameConcerteTxt)
{
	this->s.loadFileTxt(fileNameFilmeTxt, fileNameConcerteTxt);
}

void UI::loadFileCsv(string fileNameFilmeCsv, string fileNameConcerteCsv)
{
	this->s.loadFileCsv(fileNameFilmeCsv, fileNameConcerteCsv);
}

void UI::run1()
{
	int aux = 0;
	while (aux == 0)
	{
		int op = menu();
		switch (op)
		{
			case 1:
			{
				this->creareUser();
				break;
			}
			case 2:
			{
				string numeUtiliz;
				string parolaUtiliz;
				cout << "Introduceti numele de utilizator: "; cin >> numeUtiliz; cout << endl;
				cout << "Intoduceti parola: "; cin >> parolaUtiliz; cout << endl;
				if (s.LogIn(numeUtiliz, parolaUtiliz))
				{
					int nr;
					cout << "Logat! :)" << endl;
						
						this->showDataTxt();
						this->optiuniTxt();
						
					
				}
				else
				{
					cout << "Nume de utilizator sau parola incorecta!" << endl;
				}
				break;
			}
			case 0:
			{
				aux = 1;
				break;
			}
			default:
			{
				cout << "optiune incorecta" << endl;
				break;
			}
		}
	}
	
}


void UI::run2()
{
	int aux = 0;
	while (aux == 0)
	{
		int op = menu();
		switch (op)
		{
		case 1:
		{
			this->creareUser();
			break;
		}
		case 2:
		{
			string numeUtiliz;
			string parolaUtiliz;
			cout << "Introduceti numele de utilizator: "; cin >> numeUtiliz; cout << endl;
			cout << "Intoduceti parola: "; cin >> parolaUtiliz; cout << endl;
			if (s.LogIn(numeUtiliz, parolaUtiliz))
			{
				int nr;
				cout << "Logat! :)" << endl;
				
				this->showDataCsv();
				this->optiuniCsv();
				

			}
			else
			{
				cout << "Nume de utilizator sau parola incorecta!" << endl;
			}
			break;
		}
		case 0:
		{
			aux = 1;
			break;
		}
		default:
		{
			cout << "optiune incorecta" << endl;
			break;
		}
		}
	}

}

void UI::showDataTxt()
{
	
	cout << "FILME: \n" << endl;
	for (int i = 0; i < this->s.getFilmTxt().getSize(); i++)
	{
		
			cout << this->s.getFilmTxt().getAll()[i].getTitlu() << " ";
			for (int j = 0; j < s.getFilmTxt().getAll()[i].getLista().size(); j++)
			{
				cout << s.getFilmTxt().getAll()[i	].getLista()[j].getNume() << " ";
			}
			cout << s.getFilmTxt().getAll()[i].getData() << " ";
			cout << s.getFilmTxt().getAll()[i].getLoc() << " ";
			cout << s.getFilmTxt().getAll()[i].getNrLocDisp() << " ";
			cout << s.getFilmTxt().getAll()[i].getNrLocVandut() << endl;
	}
	cout << endl;
	cout << "CONCERTE: \n" << endl;
	for (int i = 0; i < this->s.getConcertTxt().getSize(); i++)
	{
		
		cout << this->s.getConcertTxt().getAll()[i].getNume() << " ";
		cout << s.getConcertTxt().getAll()[i].getData() << " ";
		cout << s.getConcertTxt().getAll()[i].getLoc() << " ";
		cout << s.getConcertTxt().getAll()[i].getNrLocDisp() << " ";
		cout << s.getConcertTxt().getAll()[i].getNrLocVandut() << endl;
		
		
		
	}

	cout << endl;
}

void UI::start()
{
	int nr;
	cout << "Alegeti formatul dorit!" << endl;
	cout << "Pentru txt apsati 1, iar pentru csv, apasati 2!" << endl;
	cout << "nr="; cin >> nr;
	if (nr == 1)
	{
		this->loadTxt();
	}
	else if(nr == 2)
	{
		this->loadCsv();
	}
}
void UI::loadTxt()
{
	this->loadFileTxt("Filme.txt", "Concerte.txt");
	this->run1();
}

void UI::loadCsv()
{
	this->loadFileCsv("Filme.csv", "Concerte.csv");
	this->run2();
}



void UI::showDataCsv()
{

	cout << "FILME: \n" << endl;
	for (int i = 0; i < this->s.getFilmCsv().getSize(); i++)
	{

		cout << this->s.getFilmCsv().getAll()[i].getTitlu() << " ";
		for (int j = 0; j < s.getFilmCsv().getAll()[i].getLista().size(); j++)
		{
			cout << s.getFilmCsv().getAll()[i].getLista()[j].getNume() << " ";
		}
		cout << s.getFilmCsv().getAll()[i].getData() << " ";
		cout << s.getFilmCsv().getAll()[i].getLoc() << " ";
		cout << s.getFilmCsv().getAll()[i].getNrLocDisp() << " ";
		cout << s.getFilmCsv().getAll()[i].getNrLocVandut() << endl;
	}
	cout << endl;
	cout << "CONCERTE: \n" << endl;
	for (int i = 0; i < this->s.getConcertCsv().getSize(); i++)
	{

		cout << this->s.getConcertCsv().getAll()[i];


	}

	cout << endl;
}

int UI::printMenu()
{
	cout << endl;
	cout << "1.Adaugare Film!" << endl;
	cout << "2.Adaugare Concert" << endl;
	cout << "3.Eliminare Film!" << endl;
	cout << "4.Eliminare Concert!" << endl;
	cout << "5.Cumparare bilet Film!" << endl;
	cout << "6.Cumparare bilet Concert!" << endl;
	cout << "7.Logout!" << endl;
	int optiune;
	cin >> optiune;
	return optiune;
}


void UI::optiuniTxt()
{
	int aux2 = 0;
	while (aux2 == 0)
	{
		int optiune = printMenu();
		switch (optiune)
		{
			case 1:
			{
				this->addFilmTxt();
				break;
			}
			case 2:
			{
				this->addConcertTxt();
				break;
			}
			case 3:
			{
				this->delFilmTxt();
				break;
			}
			case 4:
			{
				this->delConcertTxt();
				break;
			}
			case 5:
			{
				this->cumparareBiletFilmTxt();
				break;
			}
			case 6:
			{
				this->cumparareBiletConcertTxt();
				break;
			}
			case 7:
			{
				aux2 = 1;
				
				break;
			}
		}
	}
	cout << "Delogat cu scces!" << endl;
	

}

void UI::addFilmTxt()
{
	Film f;
	string titlu, data, loc;
	int nrLd, nrLv;
	vector<Actor> actori;
	int nr, nrLocDisp, nrLocVandut;
	cout << "Introduceti tilul filmului!" << endl;
	cout << "Titlu:"; cin >> titlu;
	cout << endl;
	cout << "Introduceti numarul de actori!" << endl;
	cout << "nr="; cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		string nume;
		cout << "Introduceti numele actorilor: "; cin >> nume;
		Actor a;
		a.setNume(nume);
		actori.push_back(a);
	}

	cout << "Introduceti data!" << endl;
	cout << "Data:"; cin >> data;
	cout << endl;
	cout << "Introduceti locul!" << endl;
	cout << "Loc:"; cin >> loc;
	cout << endl;
	cout << "Introduceti numarul de locuri dosponibile!" << endl;
	cout << "nr:"; cin >> nrLd;
	cout << endl;
	cout << "Introduceti numarul de locuri vandute!" << endl;
	cout << "nr:"; cin >> nrLv;
	f.setTitlu(titlu);
	f.setLista(actori);
	f.setData(data);
	f.setLoc(loc);
	f.setNrLocDisp(nrLd);
	f.setNrLocVandut(nrLv);
	s.addFilmTxt(f);
	s.saveFileTxt();

}

void UI::addConcertTxt()
{
	Concert c;
	string nume, data, loc;
	int nrLd, nrLv;
	cout << "Introduceti numele cantaretului: "; cin >> nume;
	cout << endl;
	cout << "Introduceti data: "; cin >> data;
	cout << endl;
	cout << "Introduceti locul: "; cin >> loc;
	cout << endl;
	cout << "Introduceti numarul locurilor disponibile:"; cin >> nrLd;
	cout << endl;
	cout << "Introduceti numarul locurilor vandute: "; cin >> nrLv;
	cout << endl;
	c.setNume(nume);
	c.setData(data);
	c.setLoc(loc);
	c.setNrLocDisp(nrLd);
	c.setNrLocVandut(nrLv);
	s.addConcertTxt(c);
	s.saveFileTxt();
}

void UI::delFilmTxt()
{
	string nume;
	cout << "Dati numele filmului pe care doriti sa il stergeti:"; cin >> nume;
	cout << endl;
	int nr;
	nr = s.findFilmTxt(nume);
	if (nr != -1)
	{
		s.delFilmTxt(nr);
		s.saveFileTxt();
	}
	else
	{
		cout << "Nu exista niciun film cu acest titlu!" << endl;
	}
}

void UI::delConcertTxt()
{
	string nume;
	cout << "Dati numele cantaretului:"; cin >> nume;
	cout << endl;
	int nr;
	nr = s.findConcertTxt(nume);
	if (nr != -1)
	{
		s.delConcertTxt(nr);
		s.saveFileTxt();
	}
	else
	{
		cout << "Nu exista niciun film cu acest titlu!" << endl;
	}
}



void UI::cumparareBiletFilmTxt()
{
	cout << "Introduceti nume filmului: ";
	string film;
	cin >> film;
	Film f;
	f = this->s.findFilmTxtByName(film);
	if (f.getTitlu() == "")
		cout << "Acest Film nu exista!\n";
	else
	{
		cout << "Introduceti numarul de bilete pe care doriti sa le cumparati:  ";
		int nr;
		cin >> nr;
		bool oper;
		oper = this->s.cumparareBiletFilmtxt(film, nr);
		if (oper == true)
		{
			this->s.saveFileTxt();
			cout << "Cumparare reusita!" << endl;
		}

		else
			cout << "Cumparare esuata!" << endl;
	}


}

void UI::cumparareBiletConcertTxt()
{
	cout << "Introduceti numele cantaretului: ";
	string cantaret;
	cin >> cantaret;
	Concert c;
	c = this->s.findArtistTxt(cantaret);
	if (c.getNume() == "")
		cout << "Acest cantaret nu exista in fisier !\n";
	else
	{
		cout << "Introduceti numarul de bilete pe care doriti sa le cumparati:  ";
		int nr;
		cin >> nr;
		bool oper;
		oper = this->s.cumparareBiletConcertTxt(cantaret, nr);

		if (oper == true)
		{
			this->s.saveFileTxt();
			cout << "Achizitionare reusita!" << endl;

		}

		else
			cout << "Achizitionare esuata! \n";
	}

}



void UI::optiuniCsv()
{
	int aux2 = 0;
	while (aux2 == 0)
	{
		int optiune = printMenu();
		switch (optiune)
		{
		case 1:
		{
			this->addFilmCsv();
			break;
		}
		case 2:
		{
			this->addConcertCsv();
			break;
		}
		case 3:
		{
			this->delFilmCsv();
			break;
		}
		case 4:
		{
			this->delConcertCsv();
			break;
		}
		case 5:
		{
			this->cumparareBiletFilmCsv();
			break;
		}
		case 6:
		{
			this->cumparareBiletConcertCsv();
			break;
		}
		case 7:
		{
			aux2 = 1;

			break;
		}
		}
	}
	cout << "Delogat cu scces!" << endl;


}

void UI::addFilmCsv()
{
	Film f;
	string titlu, data, loc;
	int nrLd, nrLv;
	vector<Actor> actori;
	int nr, nrLocDisp, nrLocVandut;
	cout << "Introduceti tilul filmului!" << endl;
	cout << "Titlu:"; cin >> titlu;
	cout << endl;
	cout << "Introduceti numarul de actori!" << endl;
	cout << "nr="; cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		string nume;
		cout << "Introduceti numele actorilor: "; cin >> nume;
		Actor a;
		a.setNume(nume);
		actori.push_back(a);
	}

	cout << "Introduceti data!" << endl;
	cout << "Data:"; cin >> data;
	cout << endl;
	cout << "Introduceti locul!" << endl;
	cout << "Loc:"; cin >> loc;
	cout << endl;
	cout << "Introduceti numarul de locuri dosponibile!" << endl;
	cout << "nr:"; cin >> nrLd;
	cout << endl;
	cout << "Introduceti numarul de locuri vandute!" << endl;
	cout << "nr:"; cin >> nrLv;
	f.setTitlu(titlu);
	f.setLista(actori);
	f.setData(data);
	f.setLoc(loc);
	f.setNrLocDisp(nrLd);
	f.setNrLocVandut(nrLv);
	s.addFilmCsv(f);
	s.saveFileCsv();
}


void UI::addConcertCsv()
{
	Concert c;
	string nume, data, loc;
	int nrLd, nrLv;
	cout << "Introduceti numele cantaretului: "; cin >> nume;
	cout << endl;
	cout << "Introduceti data: "; cin >> data;
	cout << endl;
	cout << "Introduceti locul: "; cin >> loc;
	cout << endl;
	cout << "Introduceti numarul locurilor disponibile:"; cin >> nrLd;
	cout << endl;
	cout << "Introduceti numarul locurilor vandute: "; cin >> nrLv;
	cout << endl;
	c.setNume(nume);
	c.setData(data);
	c.setLoc(loc);
	c.setNrLocDisp(nrLd);
	c.setNrLocVandut(nrLv);
	s.addConcertCsv(c);
	s.saveFileCsv();
}

void UI::delFilmCsv()
{
	string nume;
	cout << "Dati numele filmului pe care doriti sa il stergeti:"; cin >> nume;
	cout << endl;
	int nr;
	nr = s.findFilmCsv(nume);
	if (nr != -1)
	{
		s.delFilmCsv(nr);
		s.saveFileCsv();
	}
	else
	{
		cout << "Nu exista niciun film cu acest titlu!" << endl;
	}
}

void UI::delConcertCsv()
{
	string nume;
	cout << "Dati numele cantaretului:"; cin >> nume;
	cout << endl;
	int nr;
	nr = s.findConcertCsv(nume);
	if (nr != -1)
	{
		s.delConcertCsv(nr);
		s.saveFileCsv();
	}
	else
	{
		cout << "Nu exista niciun film cu acest titlu!" << endl;
	}
}


void UI::cumparareBiletFilmCsv()
{
	cout << "Introduceti nume filmului: ";
	string film;
	cin >> film;
	Film f;
	f = this->s.findFilmCsvByName(film);
	if (f.getTitlu() == "")
		cout << "Acest Film nu exista!\n";
	else
	{
		cout << "Introduceti numarul de bilete pe care doriti sa le cumparati:  ";
		int nr;
		cin >> nr;
		bool oper;
		oper = this->s.cumparareBiletFilmCsv(film, nr);
		if (oper == true)
		{
			this->s.saveFileCsv();
			cout << "Cumparare reusita!" << endl;
		}

		else
			cout << "Cumparare esuata!" << endl;
	}
}

void UI::cumparareBiletConcertCsv()
{
	cout << "Introduceti numele cantaretului: ";
	string cantaret;
	cin >> cantaret;
	Concert c;
	c = this->s.findArtistCsv(cantaret);
	if (c.getNume() == "")
		cout << "Acest cantaret nu exista in fisier !\n";
	else
	{
		cout << "Introduceti numarul de bilete pe care doriti sa le cumparati:  ";
		int nr;
		cin >> nr;
		bool oper;
		oper = this->s.cumparareBiletConcertCsv(cantaret, nr);

		if (oper == true)
		{
			this->s.saveFileCsv();
			cout << "Achizitionare reusita!" << endl;

		}

		else
			cout << "Achizitionare esuata! \n";
	}
}