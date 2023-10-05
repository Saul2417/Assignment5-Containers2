#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <string>
#include "Student.h"
#include "listTest.h"
#include "input.h"


/* TO DO LIST:
* Fix J (end())
* Further Testing
* ADD COMMENTS
*/

//Precondition: None
//Postcondition: None
void listMenu()
{
	system("cls");
	int index;
	int size;
	student* pos;
	student newStudent;
	list<student> studentList;
	list<student> list2;
	list<student>::iterator it;
	list<student>::iterator it2;
	list<student>::reverse_iterator rit;
	map<int, string> gradeLevel = { {1, "Freshman"}, {2, "Sophomore"}, {3, "Junior"}, {4, "Senior"} };

	do
	{
		switch (listMenuOption())
		{

		case '0': return; break;

		case 'A':
		{
			studentList.clear();
			std::cout << "List has been cleared." << endl;
		}
		break;
		case 'B':
		{
			studentList.resize(inputInteger("Enter the new size (1..100): ", 1, 100));
			std::cout << "The list has been resize to the desired length." << endl;
		}
		break;
		case 'C': {studentFileReadList(studentList, 'F'); } break;
		case 'D':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "Element, " << studentList.front() << " has been removed from the list." << endl;
			studentList.pop_front();
		}
		break;
		case 'E':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "The element from the front of the list: [0] " << studentList.front() << endl;
		}
		break;
		case 'F': studentFileReadList(studentList, 'B'); break;
		case 'G':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "Element, " << studentList.back() << " has been removed from the list." << endl;
			studentList.pop_back();
		}
		break;
		case 'H':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "The element from the back of the list: [" << (studentList.size() - 1) << "] " << studentList.back() << endl;
		}
		break;
		case 'I':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "The iterator referring the first element: " << &*studentList.begin() << " (" << *studentList.begin() << ")" << endl;
			break;
		}
		case 'J':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			it = studentList.end();
			std::cout << "The iterator referring the past-the-end element: " << next(&*--it)  << endl;
		}
		break;
		case 'K':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "Using begin() and end(), the list contains:" << endl;
			for (it = studentList.begin(); it != studentList.end(); it++)
			{
				cout << &*it << " (" << *it << ")" << endl;
			};
		}
		break;
		case 'L':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "The reverse iterator pointing to the last element: " << &*studentList.rbegin() << " (" << *studentList.rbegin() << ")" << endl;
		}
		break;
		case 'M':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			rit = studentList.rend();
			std::cout << "The reverse iterator pointing to the theoretical element preceding the first element in the list: " << &*++rit.base() << endl;
		}
		break;
		case 'N':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			std::cout << "Using rbegin() and rend(), the list contains reverse elements:" << endl;
			for (rit = studentList.rbegin(); rit != studentList.rend(); rit++)
			{
				cout << &*rit << " (" << *rit << ")" << endl;
			}
		}
		break;
		case 'O':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			it = studentList.begin();
			std::cout << "An element after the begin iterator: " << &*studentList.begin() << " has been removed." << endl;
			studentList.erase(it);
		}
		break;
		case 'P':
		{
			if (studentList.empty())
			{
				cout << "List is empty. Please enter elements into the list." << endl;
				break;
			}
			it = studentList.begin();
			it2 = prev(studentList.end());
			std::cout << "tAll elements starting at begin iterator " << &*it << " and going up to end iterator " << &*it2 << " have been removed.";
			studentList.erase(it, it2);
		}
		break;
		case 'Q':
		{
			it = studentList.begin();
			newStudent.setName(inputString("Enter a new student name: ", true));
			newStudent.setGradeLevel(gradeLevel.at((inputInteger("Enter their grade level (1-Freshman, 2-Sophomore, 3-Junior, or 4-Senior): ", 1, 4))));
			newStudent.setGPA(inputDouble("Enter their GPA: ", 0.0, 4.0));
			studentList.insert(++it, newStudent);
		}
		break;
		case 'R': // call swap() to exchange the elements in the list with another list of the same time
		{
			cout << "List (list2) is initially empty." << endl << endl;
			studentList.swap(list2);
			cout << "List (studentList) is empty after swapped with list (list2)." << endl << endl;
			cout << "List (list2) now has " << list2.size() << " elements" << endl;
		}
		break;
		case 'S': // Sort the list
		{
			if (studentList.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			studentList.sort();
			for (it = studentList.begin(); it != studentList.end(); it++)
			{
				cout << &*it << " (" << *it << ")" << endl;
			};
		}
		break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
			system("pause");
		}
	} while (true);
}

//Precondition: None
//Postcondition: Returns a char variable to represent user choice
char listMenuOption()
{
	cout << endl;
	cout << "List's Member Functions" << endl;
	cout << string(100, char(205)) << endl;
	cout << "A. clear(): Removes/Destroys all elements in the list" << endl;
	cout << "B. resize(n): Resizes the container to be able to contain n elements" << endl;
	cout << "C. Read input.dat and push_front(e): Adds a new element at the front of the list" << endl;
	cout << "D. pop_front(): Removes the first element in the list " << endl;
	cout << "E. fornt(): Returns a reference to the first element in the list" << endl;
	cout << "F. Read input.dat and push_back(e): Adds a new element at the end of the list" << endl;
	cout << "G. pop_back(): Removes the last element in the list " << endl;
	cout << "H. back(): Returns the last element in the list" << endl;
	cout << "I. begin(): Returns an iterator pointing to first element in the list" << endl;
	cout << "J. end(): Returns an iterator referring to the past-the-end element in the list" << endl;
	cout << "K. begin() and end(): Use both to return all elements in the list" << endl;
	cout << "L. rbegin(): Returns a reverse iterator pointing to the last element in the list" << endl;
	cout << "M. rend(): Returns a reverse iterator pointing to the theoretical element preceding the first element in the list" << endl;
	cout << "N. rbegin() and rend(): Use both to return all elements in the list" << endl;
	cout << "O. erase(it): Uses the iterator to remove a single element from the list" << endl;
	cout << "P. erase(start_it, end_it): Uses the iterator to remove a range of elements from the list" << endl;
	cout << "Q. insert(it, entry): Insert a new entry at the iterator." << endl;
	cout << "R. swap(): Exchanges the contents of the container with another list of the same data type " << endl;
	cout << "S. Sort: Sort the list" << endl;
	cout << string(100, char(196)) << endl;
	cout << "0. Return" << endl;
	cout << string(100, char(205)) << endl;
	char option = toupper(inputChar("Option: ", "ABCDEFGHIJKLMNOPQRS0"));
	return option;
}

//Precondition: Char variable (push front or back)
//Postcondition: None
void studentFileReadList(list<student>& studentList, char frontOrBack)
{
	fstream infile;
	string newName;
	string newGradeLevel;
	string newGPA;
	student newStudent;
	infile.open("input.dat", ios::in);
	cout << "Reading File, input.dat..." << endl;
	if (!infile)
	{
		cout << "Cannot Open Test File, input.dat" << endl;
		exit(1);
	}

	// use delimiters to read file
	while (!infile.eof())
	{
		getline(infile, newName, ',');
		newStudent.setName(newName);
		getline(infile, newGradeLevel, ',');
		newStudent.setGradeLevel(newGradeLevel);
		getline(infile, newGPA);
		newStudent.setGPA(stod(newGPA));
		if (frontOrBack == 'F')
		{
			studentList.push_front(newStudent);
		}
		else
		{
			studentList.push_back(newStudent);
		}
	}
	infile.close();
	std::cout << "The list now contains " << studentList.size() << " elements.";
}
