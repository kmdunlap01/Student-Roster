#pragma once
#include "Student.h"
#include <array>

class Roster {
public:

	Roster();

	void add(string ID, string first, string last, string email, int age, int day0, int day1, int day2, Degree);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degree);

	int i = 0;

	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	~Roster();
};
