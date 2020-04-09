#include <iostream>
#include "teste.h"
#include "biblioteca.h"
#include "testeService.h"
#include "repo.h"
#include "UI.h"


using namespace std;

int main()
{
    TestRepo test;
    TestService testS;
    test.testAll();
    cout << "A mers testRepo" << endl;
    testS.testAll();
    cout << "A mers si testService" << endl << "Sa vedem acum programul cum merge...." << endl;
    UI ui;
    ui.showUI();
    return 0;
}
