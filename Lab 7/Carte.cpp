#include "Carte.h"
#include <iostream>


using namespace std;

Carte::Carte() {
	this->titlu = NULL;
	this->autor = NULL;
	this->statut = false;
}

Carte::Carte(char* titlu, char* autor, bool statut)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(titlu), titlu);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, 1 + strlen(autor), autor);
	this->statut = statut;
}

Carte::Carte(const Carte& s) {
	//cout << "copy constructor" << endl;
	this->titlu = new char[strlen(s.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(s.titlu), s.titlu);
	this->autor = new char[strlen(s.autor) + 1];
	strcpy_s(this->autor, 1 + strlen(s.autor), s.autor);
	this->statut = s.statut;
}

Carte::~Carte() {
	if (this->titlu)
	{
		delete[] this->titlu;
		this->titlu = NULL;
	}
	if (this->autor)
	{
		delete[] this->autor;
		this->autor = NULL;
	}
}

char* Carte::getTitlu() {
	return this->titlu;
}

char* Carte::getAutor() {
	return this->autor;
}

bool Carte::getStatut() {
	return this->statut;
}


void Carte::setTitlu(char* titlu)
{
	if (this->titlu) {
		delete[] this->titlu;
		this->titlu = NULL;

	}
	if (titlu)
	{
		this->titlu = new char[strlen(titlu) + 1];

		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);

	}
}

void Carte::setAutor(char* autor)
{
	if (this->autor) {
		delete[] this->autor;
		this->autor = NULL;

	}
	if (autor)
	{
		this->autor = new char[strlen(autor) + 1];

		strcpy_s(this->autor, strlen(autor) + 1, autor);

	}
}


void Carte::setStatut(bool statut) {
	this->statut = statut;
}

Carte& Carte::operator=(const Carte& s) {
	this->setTitlu(s.titlu);
	this->setAutor(s.autor);
	this->setStatut(s.statut);
	return *this;
}



bool Carte:: operator==(const Carte& s) {
	return (strcmp(this->titlu, s.titlu) == 0 && this->statut == s.statut);
}

ostream& operator<<(ostream& os, const Carte& s)
{
	os << s.titlu << " " << s.autor << " " << s.statut << " ";
	return os;
}

istream& operator>>(istream& is, Carte& s)
{
	cout << "Dati titlul: ";
	char* nume = new char[10];
	is >> nume;
	cout << "Dati autorul: ";
	char* autor = new char[10];
	is >> autor;
	cout << "Este imprumutata cartea?";
	bool v;
	cin >> v;
	s.setTitlu(nume);
	s.setAutor(autor);
	s.setStatut(v);
	delete[] nume;
	delete[] autor;
	return is;
}
