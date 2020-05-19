#pragma once
#include "Actor.h"
#include "Concert.h"
#include "Film.h"
#include "Repo.h"
#include "RepoFile.h"
#include "RepoFileCsv.h"
#include "RepoFileTxt.h"
#include "User.h"
#include <vector>
#include <iostream>
using namespace std;

class Service
{
private:
	Repo<User> ru;
	RepoFileTxt<Film> rft;
	RepoFileTxt<Concert> rct;
	RepoFileCsv<Film> rfc;
	RepoFileCsv<Concert> rcc;
public:
	Service();
	Service(RepoFile<User> rUser, RepoFileTxt<Film> rFilmTxt, RepoFileTxt<Concert> rConcertTxt, RepoFileCsv<Film> rFilmCsv, RepoFileCsv<Concert> rConcertCsv);
	int findUser(string nume);
	int findFilmTxt(string nume);
	int findFilmCsv(string nume);
	int findConcertTxt(string nume);
	int findConcertCsv(string nume);
	Film findFilmTxtByName(string nume);
	Film findFilmCsvByName(string nume);
	Concert findArtistTxt(string artist);
	Concert findArtistCsv(string artist);
	string getParola(int poz);
	RepoFileTxt<Film> getFilmTxt();
	RepoFileTxt<Concert> getConcertTxt();
	RepoFileCsv<Film> getFilmCsv();
	RepoFileCsv<Concert> getConcertCsv();
	bool creareCont(string nume, string parola);
	bool LogIn(string nume, string parola);
	Repo<User> getUsers();
	
	void loadFileTxt(string fileNameFilme, string fileNameConcerte);
	void loadFileCsv(string fileNameTxt, string fileNameCsv);
	void saveFileTxt();
	void saveFileCsv();
	void addFilmTxt(Film f);
	void addFilmCsv(Film f);
	void addConcertTxt(Concert c);
	void addConcertCsv(Concert c);
	bool delUser(int poz);
	bool delFilmTxt(int poz);
	bool delFilmCsv(int poz);
	bool delConcertTxt(int poz);
	bool delConcertCsv(int poz);
	int showDataTxt(int poz);
	bool cumparareBiletFilmtxt(string nume, int nr);
	bool cumparareBiletConcertTxt(string nume, int nr);
	bool cumparareBiletFilmCsv(string nume, int nr);
	bool cumparareBiletConcertCsv(string nume, int nr);

	
	
	


};