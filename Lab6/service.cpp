#include "service.h"
using namespace std;

Service::Service()
{
}

Service::Service(Repo<Carte>& r)
{
	repo = r;
}

void Service::addC(char* titlu, char* autor, bool status)
{
	Carte c(titlu, autor, status);
	repo.addCarte(c);
}

int Service::deleteC(Carte c)
{
	return repo.deleteCarte(c);
}

Carte Service::getC(int pos)
{
	return repo.getCarte(pos);
}

void Service::updateC(Carte c, char* titlu, char* autor, bool status)
{
	repo.updateCarte(c, titlu, autor, status);
}

void Service::setRepo(Repo<Carte>& r)
{
	repo = r;
}

int Service::getCarteAtPos(Carte c)
{
	return this->repo.findCarte(c);
}

int Service::getSizeC()
{
	return this->repo.size();
}

deque<Carte> Service::getAll()
{
	deque<Carte> rez = repo.getAll();
	deque<Carte> v(rez.begin(), rez.end());
	return v;
}

Service::~Service()
{
}
