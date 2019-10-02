#pragma once
#include <string>
#include "Degree.h"
using namespace std;

class Student {
public:

	Student();
	Student(string ID, string first, string last, string email, int age, int* days, Degree degreeType);

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysInCourse[3];
	Degree degree;

	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetStudentAge();
	int* GetDaysInCourse();
	virtual Degree GetDegreeProgram();

	void SetStudentID(string ID);
	void SetFirstName(string first);
	void SetLastName(string last);
	void SetEmailAddress(string email);
	void SetStudentAge(int age);
	void SetDaysInCourse(int days1, int days2, int days3);
	void SetDegreeProgram(string degreeType);

	virtual void print();

	~Student();

};