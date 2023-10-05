#include <iostream>
#include <list>
#include <map>
#include "integerList.h"
#include "input.h"

void createFrequencyTable(map<int, int>& table, list<int> integerList);
void displayFrequencyTable(map<int, int> table);

//Precondtition: None
//Postcondition: None
void integerListMenu()
{
	list<int> integerList;
	list<int>::iterator it;
	map<int, int> frequencyTable;
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
				createFrequencyTable(frequencyTable, integerList);
				displayFrequencyTable(frequencyTable);
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
void createFrequencyTable(map<int, int>& table, list<int> integerList)
{
	for (auto it = integerList.begin(); it != integerList.end(); it++)
	{
		if (table.count(*it))
		{
			table.at(*it)++;
		}
		else
		{
			table.emplace(*it, 1);
		}
	}
}

//Precondtition: None
//Postcondition: None
void displayFrequencyTable(map<int, int> table)
{
	map<int, int>::iterator itt;
	cout << endl << "List: " << endl;
	for (itt = table.begin(); itt != table.end(); itt++)
	{
		cout << itt->first << ": " << itt->second << endl;
	}
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