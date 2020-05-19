#pragma once
#include "Repo.h"
#include <cstring>
#include <string>
template<class T>
class RepoFileCsv : public Repo<T> {
public:
	RepoFileCsv();
	RepoFileCsv(string fileName);
	~RepoFileCsv();
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoFileCsv<T>::RepoFileCsv()
{

}

template<class T>
inline RepoFileCsv<T>::RepoFileCsv(string fileName)
{
	this->fileName = fileName;
}

template<class T>
inline RepoFileCsv<T>::~RepoFileCsv()
{

}

template<class T>
inline void RepoFileCsv<T>::loadFromFile()
{

	string a;
	a = this->fileName;

	ifstream f(a);
	if (f.is_open())
	{
		this->clearRepo();
		string linie;
		
		while (getline(f, linie))
		{
			T obj(linie, ',');
			this->addElem(obj);
		}
		f.close();
	}
}

template<class T>
inline void RepoFileCsv<T>::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{

		for (T v : this->v)

		{
			f << v.toString(',') << endl;
		}
	}
}

