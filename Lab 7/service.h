#pragma once
#include "repo_Template.h"
#include "Carte.h"
#include <deque>
using namespace std;

class Service
{
private:
	RepoTemplate<Carte> repo;
public:
	Service();
	Service(const RepoTemplate<Carte>&);
	void setRepo(const RepoTemplate<Carte>&);

	void addCarte(Carte&);
	int delCarte(Carte&);
	deque<Carte> getAll();
	Carte update(Carte, char*, char*, bool);
	int findOne(Carte);
	deque<Carte> filterByAutor(char*);
	~Service();
};