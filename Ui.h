#pragma once
#include "Service.h"
#include "Repo.h"
#include <iostream>
using namespace std;

class UI {
private:
	Service s;

public:
	UI();
	~UI();
	UI(Service serv);
	void creareUser();
	void loadFileTxt(string fileNameFilme, string fileNameConcerte);
	void loadFileCsv(string fileNameFilme, string fileNameConcerte);
	void run1();
	void run2();
	int menu();
	void showDataTxt();
	void showDataCsv();
	void loadTxt();
	void loadCsv();
	void addFilmTxt();
	void addConcertTxt();
	void delFilmTxt();
	void delConcertTxt();
	
	void start();
	int printMenu();
	void optiuniTxt();
	void optiuniCsv();

	void cumparareBiletFilmTxt();
	void cumparareBiletConcertTxt();

	void addFilmCsv();
	void addConcertCsv();
	void delFilmCsv();
	void delConcertCsv();
	void cumparareBiletFilmCsv();
	void cumparareBiletConcertCsv();
};