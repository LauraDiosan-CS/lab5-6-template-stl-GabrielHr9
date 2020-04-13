#include "service.h"
#include <algorithm> 

Service::Service()
{
}

Service::Service(const RepoTemplate<Carte>& r)
{
	repo = r;
}

void Service::setRepo(const RepoTemplate<Carte>& r)
{
	repo = r;
}



void Service::addCarte(Carte& s)
{
	repo.add(s);
}

int Service::delCarte(Carte& s)
{
	return repo.remove(s);
}

deque<Carte> Service::getAll()
{
	deque<Carte> rez = repo.getAll();
	deque<Carte> v(rez.begin(), rez.end());

	return v;
}

Carte Service::update(Carte s, char* n, char* q, bool a)
{
	Carte c(n, q, a);
	repo.update(s, c);
	return s;
}

int Service::findOne(Carte s)
{
	return repo.f(s);
}

deque<Carte> Service::filterByAutor(char* t)
{
	deque<Carte> rez;
	deque<Carte> all = repo.getAll();
	for (Carte current : all) {

		if ((strstr(current.getAutor(), t)) && current.getStatut() == 0) {
			rez.push_back(current);
		}
	}

	return rez;
}



Service::~Service()
{
}
