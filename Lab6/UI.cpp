#include "UI.h"
#include <iostream>

using namespace std;

void UI::addCartea()
{
	cout << "Dati cartea: " << endl;
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	cout << "Dati titlu: ";
	cin >> titlu;
	cout << "Dati autor: ";
	cin >> autor;
	cout << "Dati status(true/false): ";
	cin >> status;
	serv.addC(titlu, autor, status);
	cout << "Carte adaugata!" << endl;
	delete[] titlu;
	delete[] autor;
}

void UI::delCartea()
{
	Carte carte;
	cout << "Dati cartea: ";
	cin >> carte;
	int rez = serv.deleteC(carte);
	if (rez == 0)cout << "Carte stearsa!";
	else cout << "Cartea NU a fost stearsa!";
}

void UI::updCartea()
{
	Carte carte;
	cout << "Dati cartea: ";
	cin >> carte;

	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	cout << "Dati titlu: ";
	cin >> titlu;
	cout << "Dati autor: ";
	cin >> autor;
	cout << "Dati status(true/false): ";
	cin >> status;
	serv.updateC(carte, titlu, autor, status);
	cout << "Modificat cu succes!";
	delete[] titlu;
	delete[] autor;
}

void UI::showAll()
{
	cout << endl << "Elementele cozii sunt" << endl;
	for (int i = 0; i < serv.getSizeC(); i++)
	{
		cout << serv.getAll()[i];
	}
}

UI::UI()
{
}

UI::UI(Service&)
{
	this->serv = serv;
}

void UI::showUI()
{
	bool gata = false;
	int opt = 1;
	while (opt)
	{
		cout << "Optiuni: " << endl;
		cout << "0.Exit " << endl;
		cout << "1.Add " << endl;
		cout << "2.Delete " << endl;
		cout << "3.Update " << endl;
		cout << "4.Afisare " << endl;
		cout << "Dati optiunea: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			addCartea();
			break;
		case 2:
			delCartea();
			break;
		case 3:
			updCartea();
			break;
		case 4:
			showAll();
			break;
		case 0:
			cout << "Ceau pa!";
			break;
		}
	}
	

}
