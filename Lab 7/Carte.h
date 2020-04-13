#pragma once
#include <ostream>
using namespace std;

class Carte {
private:
	char* titlu;
	char* autor;
	bool statut;
public:
	Carte();
	Carte(char*, char*, bool);
	Carte(const Carte& s);
	~Carte();
	char* getTitlu();
	char* getAutor();
	bool getStatut();
	void setTitlu(char* titlu);
	void setAutor(char* autor);
	void setStatut(bool statut);
	Carte& operator=(const Carte& s);

	bool operator==(const Carte& s);
	friend ostream& operator<<(ostream& os, const Carte& s);
	friend istream& operator>>(istream&, Carte&);
};
