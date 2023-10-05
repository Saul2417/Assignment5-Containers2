#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Student.h"
#include "vectorTest.h"
#include "input.h"

//Precondtition: None
//Postcondition: None 
void vectorMenu()
{
	system("cls");
	student* pos;
	int index;
	int size;
	student newStudent;
	vector<student> studentVector;
	vector<student> vector2;
	vector<student>::iterator it;
	vector<student>::iterator it2;
	vector<student>::reverse_iterator rit;
	map<int, string> gradeLevel = { {1, "Freshman"}, {2, "Sophomore"}, {3, "Junior"}, {4, "Senior"} };

	do
	{
		switch (vectorMenuOption())
		{
		case '0': return; break;
		case 'A':// call studentVector.clear()
		{
			studentVector.clear();
			std::cout << "Vector has been cleared." << endl;
		}
		break;
		case 'B': // call studentVector.reserve()
		{
			studentVector.reserve(inputInteger("Enter the capacity to reserve (1..100): ", 1, 100));
			std::cout << "The vector has reserved the desired elements." << endl;
		}
		break;
		case 'C': // call studentVector.resize()
		{
			studentVector.resize(inputInteger("Enter the new size (1..100): ", 1, 100));
			std::cout << "The vector has been resize to the desired length." << endl;
		}
		break;
		case 'D': { studentFileReadVector(studentVector); } break; // call function to read input file to vector
		case 'E': // call studentVector.pop_back()
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "Element, " << studentVector.back() << " has been removed from the vector." << endl;
			studentVector.pop_back();
		}
		break;
		case 'F': // call studentVector.front()
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "The element from the front of the vector: [0] " << studentVector.front() << endl;
		}
		break;
		case 'G': // call studentVector.back()
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "The element from the back of the vector: [" << (studentVector.size() - 1) << "] " << studentVector.back() << endl;
		}
		break;
		case 'H': // call studentVector.at(index) & studentVector[index]
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "Enter the index(0.." << (studentVector.size() - 1) << "): ";
			size = (studentVector.size() - 1);
			index = inputInteger(" ", 0, size);
			cout << "vector.at(" << index << "): " << studentVector.at(index) << endl;
			cout << "vector[" << index << "]: " << studentVector[index] << endl;
		}
		break;
		case 'I': // call studentVector.begin()
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "The iterator referring the first element: " << &*studentVector.begin() << " (" << *studentVector.begin() << ")" << endl;
		}
		break;
		case 'J':
		{
			// call studentVector.end()
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			pos = studentVector.data();
			for (it = studentVector.begin(); it != studentVector.end(); it++)
			{
				pos++;
			};
			cout << "The iterator referring the past-the-end element: " << pos << endl;
		}
		break;
		case 'K': // use iterators to loop through the vector

		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "Using begin() and end(), the vector contains:" << endl;
			for (it = studentVector.begin(); it != studentVector.end(); it++)
			{
				cout << &*it << " (" << *it << ")" << endl;
			};
		}
		break;
		case 'L': // call studentVector.rbegin()
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "The reverse iterator pointing to the last element: " << &*studentVector.rbegin() << " (" << *studentVector.rbegin() << ")" << endl;
		}
		break;
		case 'M': // call studentVector.rend()
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			rit = studentVector.rend();
			std::cout << "The reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &*++rit.base() << endl;
		}
		break;
		case 'N': // use reverse iterators to loop through the vector
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::cout << "Using rbegin() and rend(), the vector contains reverse elements:" << endl;
			for (rit = studentVector.rbegin(); rit != studentVector.rend(); rit++)
			{
				cout << &*rit << " (" << *rit << ")" << endl;
			}
		}
		break;
		case 'O': // use an iterator to delete an element in the vector
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			it = studentVector.begin();
			std::cout << "An element after the begin iterator: " << &*studentVector.begin() << " has been removed." << endl;
			studentVector.erase(it);
		}
		break;

		case 'P': // use iterators to delete multiple elements in the vector
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			it = studentVector.begin();
			it2 = studentVector.end() - 1;
			std::cout << "All elements starting at begin iterator " << &*it << " and going up to end iterator " << &*it2 << " have been removed.";
			studentVector.erase(it, it2);
		}
		break;
		case 'Q': // set a new student element and use insert() to add it into the vector
		{
			it = studentVector.begin();
			newStudent.setName(inputString("Enter a new student name: ", true));
			newStudent.setGradeLevel(gradeLevel.at((inputInteger("Enter their grade level (1-Freshman, 2-Sophomore, 3-Junior, or 4-Senior): ", 1, 4))));
			newStudent.setGPA(inputDouble("Enter their GPA: ", 0.0, 4.0));
			studentVector.insert(++it, newStudent);
		}
		break;
		case 'R': // call swap() to exchange the elements in the vector with another vector of the same time
		{
			cout << "Vector (vector2) is initially empty." << endl << endl;
			studentVector.swap(vector2);
			cout << "Vector (studentVector) is empty after swapped with vector (vector2)." << endl << endl;
			cout << "Vector (vector2) after swapped with vector (studentVector):" << endl;
			for (index = 0; index < vector2.size(); index++)
			{
				cout << vector2[index] << endl;
			};
		}
		break;

		case 'S': // swap the elements in the vector
		{
			if (studentVector.empty())
			{
				cout << "Vector is empty. Please enter elements into the vector." << endl;
				break;
			}
			std::sort(studentVector.begin(), studentVector.end());
			displayVector(studentVector);
		}
		break;
		default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
			system("pause");
		}
	} while (true);
}

//Precondtition: None
//Postcondition: None
char vectorMenuOption()
{
	cout << endl;
	cout << "Vector's Member Functions" << endl;
	cout << string(100, char(205)) << endl;
	cout << "A. clear(): Removes/Destroys all elements in the vector" << endl;
	cout << "B. reserve(n): Requests that the vector capacity be able to hold n elements" << endl;
	cout << "C. resize(n): Resizes the container to be able to contain n elements" << endl;
	cout << "D. Read input.dat and push_back(e): Adds a new element at the end of the vector" << endl;
	cout << "E. pop_back(): Removes the last element in the vector " << endl;
	cout << "F. fornt(): Returns a reference to the first element in the vector" << endl;
	cout << "G. back(): Returns a reference to the last element in the vector" << endl;
	cout << "H. index using at() or []: Returns a reference to the element at position n in the vector" << endl;
	cout << "I. begin(): Returns an iterator pointing to first element in the vector" << endl;
	cout << "J. end(): Returns an iterator referring to the past-the-end element in the vector" << endl;
	cout << "K. begin() and end(): Use both to return all elements in the vector" << endl;
	cout << "L. rbegin(): Returns a reverse iterator pointing to the last element in the vector" << endl;
	cout << "M. rend(): Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector" << endl;
	cout << "N. rbegin() and rend(): Use both to return all elements in the vector" << endl;
	cout << "O. erase(it): Uses the iterator to remove a single element from the vector" << endl;
	cout << "P. erase(start_it, end_it): Uses the iterator to remove a range of elements from the vector" << endl;
	cout << "Q. insert(it, entry): Insert a new entry at the iterator." << endl;
	cout << "R. swap(): Exchanges the contents of the container with another vector of the same data type " << endl;
	cout << "S. Sort: Sort the vector" << endl;
	cout << string(100, char(196)) << endl;
	cout << "0. Return" << endl;
	cout << string(100, char(205)) << endl;
	char option = toupper(inputChar("Option: ", "ABCDEFGHIJKLMNOPQRS0"));
	return option;
}

//Precondtition:
//Postcondition:
void studentFileReadVector(vector<student>& studentVector)
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
		studentVector.push_back(newStudent);
	}
	infile.close();
	displayVector(studentVector);
}

//Precondtition: None
//Postcondition: None
void displayVector(vector<student> studentVector)
{
	std::cout << "The vector now has " << studentVector.size() << " elements." << endl << endl;

	for (int index = 0; index < studentVector.size(); index++)
	{
		std::cout << "[" << index << "]: " << studentVector[index] << endl;
	}
	std::cout << endl;
}
