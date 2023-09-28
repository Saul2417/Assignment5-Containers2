#pragma once
#include <list>
#include "Student.h"

void listMenu();
char listMenuOption();
void studentFileReadList(list<student>& studentList, char frontOrBack);
void selectionSort(list<student>& studentList);