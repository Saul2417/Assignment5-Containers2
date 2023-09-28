#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "vectorTest.h"
#include "input.h"

/* TO DO LIST:
* Implement P, Q, S
* Fix Crashes With O, J, and M (erase(), end(), rend())
*/

void vectorMenu()
{
    system("cls");
    int index;
    int size;
    student newStudent;
    vector<student> studentVector;
    vector<student> vector2;
    vector<student>::iterator it;
    vector<student>::reverse_iterator rit;

    do
    {
        switch (vectorMenuOption())
        {
        case 'X': return; break;
        case 'A':
            studentVector.clear();
            std::cout << "Vector has been cleared." << endl;
            break;
        case 'B':
            studentVector.reserve(inputInteger("Enter the capacity to reserve (1..100): ", 1, 100));
            std::cout << "The vector has reserved the desired elements." << endl;
            break;
        case 'C':
            studentVector.resize(inputInteger("Enter the new size (1..100): ", 1, 100));
            std::cout << "The vector has been resize to the desired length." << endl;
            break;
        case 'D': studentFileReadVector(studentVector); break;
        case 'E':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "Element, " << studentVector.back() << " has been removed from the vector." << endl;
            studentVector.pop_back();
            break;
        case 'F':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "The element from the front of the vector: [0] " << studentVector.front() << endl;
            break;
        case 'G':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "The element from the back of the vector: [" << (studentVector.size() - 1) << "] " << studentVector.back() << endl;
            break;
        case 'H':
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
            break;
        case 'I':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "The iterator referring the first element: " << &*studentVector.begin() << " (" << *studentVector.begin() << ")" << endl;
            break;
        case 'J':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "The iterator referring the past-the-end element: " << &*studentVector.end() << endl;
            break;
        case 'K':
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
            break;
        case 'L':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "The reverse iterator pointing to the last element: " << &*studentVector.rbegin() << " (" << *studentVector.rbegin() << ")" << endl;
            break;
        case 'M':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            std::cout << "The reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &*studentVector.rend() << endl;
            break;
        case 'N':
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
            break;
        case 'O':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            studentVector.erase(it);
            std::cout << "An element after the begin iterator: " << *studentVector.begin() << " has been removed." << endl;
            break;
        case 'P':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            /*studentVector.erase(it, it); */
            break;
        case 'Q':
            /*studentVector.insert(it,); */
            break;
        case 'R':
            cout << "Vector (vector2) is initially empty." << endl << endl;
            studentVector.swap(vector2);
            cout << "Vector (studentVector) is empty after swapped with vector (vector2)." << endl << endl;
            cout << "Vector (vector2) after swapped with vector (studentVector):" << endl;
            for (index = 0; index < vector2.size(); index++)
            {
                cout << vector2[index] << endl;
            };
            break;
            break;
        case 'S':
            if (studentVector.empty())
            {
                cout << "Vector is empty. Please enter elements into the vector." << endl;
                break;
            }
            /*selectionSort(studentVector); */
            break;
        default: std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
            system("pause");
        }
    } while (true);
}

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
    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    char option = toupper(inputChar("Option: ", "ABCDEFGHIJKLMNOPQRSX"));
    return option;
}

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

void displayVector(vector<student> studentVector)
{
    std::cout << "The vector now has " << studentVector.size() << " elements." << endl << endl;

    for (int index = 0; index < studentVector.size(); index++)
    {
        std::cout << "[" << index << "]: " << studentVector[index] << endl;
    }
    std::cout << endl;
}

void selectionSort(vector<student>& studentVector)
{

}