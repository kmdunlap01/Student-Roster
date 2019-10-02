#pragma once
#include "Student.h"

class NetworkStudent : public Student {
public:

	NetworkStudent();
	NetworkStudent(string ID, string first, string last, string email, int age, int* days, Degree degreeType);

	Degree GetDegreeProgram();

	void print();

	~NetworkStudent();
};