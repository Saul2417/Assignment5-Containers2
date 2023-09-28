#pragma once
#include <vector>
#include "Student.h"

void vectorMenu();
char vectorMenuOption();
void studentFileReadVector(vector<student>& studentVector);
void displayVector(vector<student> studentVector);
void selectionSort(vector<student>& studentVector);