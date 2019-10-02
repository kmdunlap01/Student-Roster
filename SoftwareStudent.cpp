#include "SoftwareStudent.h"
#include "Student.h"
#include <iostream>
using namespace std;


SoftwareStudent::SoftwareStudent() {}

SoftwareStudent::SoftwareStudent(string ID, string first, string last, string email, int age, int* days, Degree degreeType) : Student(ID, first, last, email, age, days, degreeType) {
	degree = degreeType;
}

Degree SoftwareStudent::GetDegreeProgram() {
	return degree;
}

void SoftwareStudent::print() {

	this->Student::print();
	cout << "\t" << "Degree Program: Software" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}