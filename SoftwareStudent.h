#pragma once
#include "Student.h"

class SoftwareStudent : public Student {
public:

	SoftwareStudent();
	SoftwareStudent(string ID, string first, string last, string email, int age, int* days, Degree degreeType);

	Degree GetDegreeProgram();

	void print();

	~SoftwareStudent();

};