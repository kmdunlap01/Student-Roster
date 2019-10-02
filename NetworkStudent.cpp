#include "NetworkStudent.h"
#include "Student.h"
#include <iostream>
using namespace std;


NetworkStudent::NetworkStudent() {}

NetworkStudent::NetworkStudent(string ID, string first, string last, string email, int age, int* days, Degree degreeType) : Student(ID, first, last, email, age, days, degreeType) {
	degree = degreeType;
}

Degree NetworkStudent::GetDegreeProgram() {
	return degree;
}

void NetworkStudent::print() {

	this->Student::print();
	cout << "\t" << "Degree Program: Networking" << endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}