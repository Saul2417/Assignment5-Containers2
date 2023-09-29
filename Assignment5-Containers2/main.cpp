#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include "vectorTest.h"
#include "listTest.h"
#include "integerList.h"
#include "input.h"

using namespace std;
int menuOption();

/* TO DO LIST:
* Implement P, Q, S
* Fix Crashes With O, J, and M (erase(), end(), rend())
*/

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: vectorMenu(); break;
        case 2: listMenu(); break;
        case 3: integerListMenu(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "CMPR131 Chapter 5: Vector and List Container by Saul Merino" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. Vector Container" << endl;
    cout << string(100, char(196)) << endl;

    cout << "2. List Container" << endl;
    cout << string(100, char(196)) << endl;

    cout << "3. Application using Vector and/or List Container" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 3);
    return option;
}




