#include "UI.h"
#include <iostream>
using namespace std;

void addCarte(Service& s) {
	Carte stud;
	cout << "Dati cartea:";
	cin >> stud;
	s.addCarte(stud);
	cout << "Cartea a fost adaugata cu succes!" << endl;
}


void findCarte(Service& serv) {
	Carte stud;
	cout << "Dati Cartea:";
	cin >> stud;
	int rez = serv.findOne(stud);
	if (rez >= 0) cout << "Cartea a fost gasita!" << endl;
	else cout << "Cartea nu a fost gasita!" << endl;
}

void delCarte(Service& serv) {
	Carte stud;
	cout << "Dati studentul:";
	cin >> stud;
	int rez = serv.delCarte(stud);
	if (rez == 0) cout << "Cartea nu mai este in baza de date!" << endl;
	else cout << "Cartea NU a fost stearsa!" << endl;
}

void showAll(Service& serv) {
	deque<Carte> stud = serv.getAll();
	for (Carte s : stud)
		cout << s;
}

void update(Service& serv) {
	Carte c;
	char t[100], a[100];
	bool ok;
	cout << "Cartea de modificat:";
	cin >> c;
	cout << "Titlul:";
	cin >> t;
	cout << "Autor:";
	cin >> a;
	cout << "Statut:";
	cin >> ok;
	serv.update(c, t, a, ok);
}

void imprumut(Service& serv)
{

	char t[100], a[100];
	bool ok = 0;
	cout << "Ce carte doriti?:" << '\n';
	cout << "Titlul:";
	cin >> t;
	cout << "Autor:";
	cin >> a;
	Carte c(t, a, ok);
	int n = serv.findOne(c);
	if (n >= 0)
	{
		serv.update(c, t, a, 1);
		cout << "Cartea va apartine pentru 30 de zile!";
	}
	else
	{
		deque<Carte> rez;
		rez = serv.filterByAutor(a);
		if (rez.size()) {
			cout << "Aceasta carte nu exista, dar exista alte carti ale autorului:" << endl;
			for (Carte current : rez)
				cout << current << " ";
		}
		else
		{
			cout << "Va rugam alegeti alt autor";
		}
	}
}

void returnez(Service& serv)
{
	char t[100], a[100];
	bool ok = 1;
	cout << "Ce carte vreti sa returnati? " << endl;
	cout << "Titlul:";
	cin >> t;
	cout << "Autor:";
	cin >> a;
	Carte c(t, a, ok);
	int n = serv.findOne(c);
	if (n >= 0)
	{
		serv.update(c, t, a, 0);
		cout << "Cartea a fost returnata cu succes!";
	}
	else
	{
		cout << "Cartea nu se afla in baza noastra de date!" << '\n';
		cout << "Pentru a returna o alta care, apasati 1, daca nu, apasati 0"<<endl;
		bool opt = 0;
		cin >> opt;
		if (opt)
			returnez(serv);

	}
}

void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga carte " << endl;
		cout << "	2. Cauta cartea " << endl;
		cout << "	3. Sterge carte " << endl;
		cout << "	4. Afiseaza toate cartile " << endl;
		cout << "	5. Update" << endl;
		cout << "	6. Imprumuta o carte" << endl;
		cout << "	7. Returneaza o carte" << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addCarte(serv); break; }
		case 2: {findCarte(serv); break; }
		case 3: {delCarte(serv); break; }
		case 4: {showAll(serv); break; }
		case 5: {update(serv); break; }
		case 6: {imprumut(serv); break; }
		case 7: {returnez(serv); break; }
		case 0: {gata = true; cout << "Asta a fost!!!!" << endl; }
		}
	}
}
