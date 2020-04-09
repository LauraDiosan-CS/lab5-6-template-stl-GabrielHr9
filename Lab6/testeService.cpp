#include "testeService.h"
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

void TestService::testAddCarte()
{
	Repo<Carte> repo;
	Service serv;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);
	assert(serv.getSizeC() == 2);
}

void TestService::testUpdateCarte()
{
	Repo<Carte> repo;
	Service serv;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	serv.addC(titlu1, autor1, true);

	serv.updateC(c1, titlu2, autor2, false);
	
	assert(serv.getC(0).getStatus() == false);
	assert(strcmp(serv.getC(0).getNume(), "baaab") == 0);
	assert(strcmp(serv.getC(0).getAutor(), "annna") == 0 );
}

void TestService::testDeleteCarte()
{
	Repo<Carte> repo;
	Service serv;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];

	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");

	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);

	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);

	assert(serv.getSizeC() == 2);

	serv.deleteC(c1);
	assert(serv.getSizeC() == 1);
}

void TestService::testAll()
{
	testAddCarte();
	testUpdateCarte();
	testDeleteCarte();
}
