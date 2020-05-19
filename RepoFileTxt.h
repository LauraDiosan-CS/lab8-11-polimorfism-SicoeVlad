#pragma once
#include<fstream>
#include"Actor.h"
#include"Film.h"
#include"Concert.h"
#include"Repo.h"
#include"User.h"
template<class T>

class RepoFileTxt : public Repo<T> {
public:
	RepoFileTxt();
	RepoFileTxt(string fileName);
	~RepoFileTxt();
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoFileTxt<T>::RepoFileTxt()
{

}

template<class T>
inline RepoFileTxt<T>::RepoFileTxt(string fileName)
{
	this->fileName = fileName;
}

template<class T>
inline RepoFileTxt<T>::~RepoFileTxt()
{

}

template<class T>
inline void RepoFileTxt<T>::loadFromFile()
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
			T obj(linie, ' ');
			this->addElem(obj);
		}
		f.close();
	}
}

template<class T>
inline void RepoFileTxt<T>::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{

		for (T v : this->v)

		{
			f << v.toString(' ') << endl;
		}
	}
}




