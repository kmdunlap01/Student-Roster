#pragma once
#include "Student.h"

class SecurityStudent : public Student {
public:

	SecurityStudent();
	SecurityStudent(string ID, string first, string last, string email, int age, int* days, Degree degreeType);

	Degree GetDegreeProgram();

	void print();

	~SecurityStudent();

};