#include "test.h"
#include "UI.h"

#include <iostream>


using namespace std;

void initService(Service& s)
{
	RepoTemplate<Carte> r;

	r.loadFromFile("Carti.txt");

	s.setRepo(r);
}

int main() {
	cout << "start..." << endl;
	/******TEST REPO FILE****/
	/*TestRepositoryFile test;
	test.testAddElem();
	test.testDelElem();
	test.testElemAtPos();
	test.testFindElem();
	test.testGetAll();
	test.testSize();
	test.testUpdateElem();*/

	/******** TEST SERVICE ******/
/*	TestService ts;
	ts.runTests();
	*/
	test();
	testservice();
	Service serv;
	initService(serv);
	showUI(serv);
	//cout << "succes";
	return 0;
}