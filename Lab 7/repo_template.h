#pragma once
#include <list>
#include <algorithm>
using namespace std;
#include <fstream>
#include "Carte.h"
#include <deque>

template <typename T>
class RepoTemplate
{
private:
	deque<T> elem;

public:
	RepoTemplate<T>() {}
	void loadFromFile(const char* fileName);
	void add(const T&);
	int remove(const T&);
	int f(const T&);
	int size();
	void update(const T& s, const T& nou);
	deque<T> getAll();
	~RepoTemplate();
};





template<class T>
void RepoTemplate<T>::add(const T& e)
{
	elem.push_back(e);
}

template<class T>
int RepoTemplate<T>::remove(const T& t)
{
	//elem.remove(t);
	typename deque<T>::iterator it = find(elem.begin(), elem.end(), t);
	elem.erase(it);
	return 0;
}



template<class T>
int RepoTemplate<T>::f(const T& e)
{
	int index = 0;
	for (T crt : elem) {
		index++;
		if (crt == e) return index;
	}
	return -1;
}

template<class T>
int RepoTemplate<T>::size()
{
	return elem.size();
	return 0;
}

template<class T>
void RepoTemplate<T>::update(const T& vechi, const T& nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);

}

template<class T>
deque<T> RepoTemplate<T>::getAll()
{
	return elem;
	return deque<T>();
}

template <class T> RepoTemplate<T>::~RepoTemplate()
{
}

template<class T>
void RepoTemplate<T>::loadFromFile(const char* fileName)
{
	elem.clear();
	//fis = fileName;
	ifstream f(fileName);
	char* titlu = new char[10], * autor = new char[10];
	bool ok;
	while (!f.eof()) {
		f >> titlu >> autor >> ok;
		if (strcmp(titlu, "") != 0) {
			Carte s(titlu, autor, ok);
			elem.push_back(s);
		}
	}
	delete[] titlu;
	f.close();
}