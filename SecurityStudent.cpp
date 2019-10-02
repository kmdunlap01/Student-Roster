#include "SecurityStudent.h"
#include "Student.h"
#include <iostream>
using namespace std;


SecurityStudent::SecurityStudent() {}

SecurityStudent::SecurityStudent(string ID, string first, string last, string email, int age, int* days, Degree degreeType) : Student(ID, first, last, email, age, days, degreeType) {
	degree = degreeType;
}

Degree SecurityStudent::GetDegreeProgram() {
	return degree;
}

void SecurityStudent::print() {

	this->Student::print();
	cout << "\t" << "Degree Program: Security" << endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}