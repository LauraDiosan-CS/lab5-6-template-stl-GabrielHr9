#include "repo_template.h"
#include "service.h"
#include <assert.h>
#include <iostream>


using namespace std;

void test()
{

	RepoTemplate<Carte> r;
	char t[] = "vis", a[] = "dan";
	char t1[] = "aur", a1[] = "dan";
	bool ok = 0;
	Carte p(t, a, ok);
	Carte q(t1, a1, ok);
	assert(p.getStatut() == ok);
	char* c;
	c = p.getTitlu();
	assert(c[0] == 'v');
	assert(c[1] == 'i');
	assert(c[2] == 's');
	c = p.getAutor();
	assert(c[0] == 'd');
	assert(c[1] == 'a');
	assert(c[2] == 'n');


	//cout << "Run test";
	r.add(p);
	deque<Carte> all;


	int n = r.size();
	assert(n == 1);

	r.update(p, q);
	//all = r.getAll();
	deque<Carte>::iterator it;
	it = all.begin();
	//assert((*it) == q);
	//assert(all.at(0) == q);

	r.remove(q);
	assert(r.size() == 0);


}

void testservice()
{
	RepoTemplate <Carte> r;
	char t[] = "vis", a[] = "dan";
	char t1[] = "aur", a1[] = "dan";
	bool ok = 0;
	Service s(r);
	Carte c(t, a, ok);
	s.addCarte(c);
	deque<Carte> all = s.getAll();
	assert(all.size() == 1);
	//assert(r.size() == 1);
	assert(s.findOne(c) >= 0);
	s.delCarte(c);
	all = s.getAll();
	assert(r.size() == 0);
	cout << "Run test service" << '\n';

	s.addCarte(c);
	deque <Carte> rez;
	rez = s.filterByAutor(a);
	assert(rez.size() == 1);

}

