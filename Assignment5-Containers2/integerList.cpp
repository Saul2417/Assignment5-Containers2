#include <iostream>
#include <list>
#include "integerList.h"
#include "input.h"

/* TO DO LIST:
* Implement D
* Further Testing
*/

//Precondtition: None
//Postcondition: None
void integerListMenu()
{
    list<int> integerList;
    list<int>::iterator it;
    int numToDelete;
    int tempSize;

    do
    {
        switch (integerListMenuOption())
        {
        case 'X': return; break; // return to main
        case 'A': integerList.push_back(inputInteger("Add an integer: ")); break; // push integer into the list
        case 'B': // use iterator to remove every instance of an integer from the list
        {       
            numToDelete = inputInteger("Delete an integer: ");
            tempSize = integerList.size();
            for (it = integerList.begin(); it != integerList.end(); it++)
            {
                if (*it == numToDelete)
                {
                    integerList.erase(it);
                    it = integerList.begin();
                }              
            };
            if (tempSize == integerList.size())
            {
                std::cout << "List does not contain " << numToDelete << endl;
            }
        }
            break;
        case 'C': // use iterator display the list
        {       
            if (integerList.empty())
            {
                std::cout << "List is empty " << endl;
            }
            else
            {
                std::cout << "List ";
                for (it = integerList.begin(); it != integerList.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << endl;
            }
        }
            break;
        case 'D': // CODE GOES INSIDE
        {     
            if (integerList.empty())
            {
                std::cout << "List is empty " << endl;
            }
            else
            {
                // Implement a frequency table or similar code
            } 
        }
            break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

//Precondtition: None
//Postcondition: None
char integerListMenuOption()
{
    cout << endl;
    cout << "3. Application using Vector and/or List Container" << endl;
    cout << string(100, char(205)) << endl;

    cout << "A. Add an Integer" << endl;
    cout << "B. Delete an Integer" << endl;
    cout << "C. Display Integer Container" << endl;
    cout << "D. Display Freqency of Integers" << endl;
    cout << string(100, char(196)) << endl;

    cout << "X. Quit" << endl;
    cout << string(100, char(205)) << endl;
    char option = toupper(inputChar("Option: ", "ABCDX"));
    return option;
}