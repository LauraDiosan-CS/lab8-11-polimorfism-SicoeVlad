#pragma once
#include <vector>
#include <cstring>
#include "VectorException.h"
#include <algorithm>
using namespace std;

template <class T> class Repo {
protected:
	vector<T> v;
	string fileName;
public:
	Repo();
	Repo(string fileName);
	vector<T> getAll();
	void setFileName(string file);
	string getFileName();
	void addElem(T el);
	int find(T);
	//void update(T&, T&);
	void remove(int poz);
	int getSize();
	T getElemPos(int pos);
	void setElemPos(int pos, T);
	void loadFromFile() {}
	void saveToFile() {}
	void clearRepo();
	void modify(int,T);

};

template<class T>
Repo<T>::Repo()
{
}

template<class T>
inline Repo<T>::Repo(string file_name)
{
	this->fileName = file_name;
}



template<class T>
inline vector<T> Repo<T>::getAll()
{
	return this->v;
}

template<class T>
void Repo<T>::addElem(T el)
{
	this->v.push_back(el);
}

template<class T>
void Repo<T>::setFileName(string file)
{
	this->fileName = file;
}

template<class T>
inline string Repo<T>::getFileName()
{
	return this->fileName;
}


template<class T>
inline int Repo<T>::find(T e)
{
	auto it = std::find(v.begin(), v.end(), e);
	if (it != v.end()) return distance(v.begin(), it);
	return -1;
}

/*
template<class T>
inline void Repo<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}
*/
template<class T>
void Repo<T>::remove(int poz)throw (VectorException)
{
	if (poz > -1 && poz < v.size())
		v.erase(v.begin() + poz);
	else
	{


		VectorException exceptie("Pozitia nu este corecta!");
		throw exceptie;

	}
}

template<class T>
int Repo<T>::getSize()
{
	return this->v.size();
}

template <class T>T Repo<T>::getElemPos(int pos)
{
	return this->v[pos];
}

template <class T> void Repo<T>::setElemPos(int pos, T el)
{
	this->v[pos] = el;
}

template<class T>
inline void Repo<T>::clearRepo()
{
	this->v.clear();
}


template<class T>
void Repo<T>::modify(int poz, T el)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i == poz)
		{
			v[i] = el;
		}
	}
}