#include <iostream>
#include <string>
#include "Student.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "Degree.h"
using namespace std;

Student::Student() {}

Student::Student(string ID, string first, string last, string email, int age, int* days, Degree degreeType) {
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->studentAge = age;
	this->daysInCourse[0] = days[0];
	this->daysInCourse[1] = days[1];
	this->daysInCourse[2] = days[2];
	this->degree = degreeType;
}

//Getters
string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetStudentAge() {
	return studentAge;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

Degree Student::GetDegreeProgram() {
	return degree;
}


//Setters
void Student::SetStudentID(string ID) {
	studentID = ID;
}

void Student::SetFirstName(string first) {
	firstName = first;
}

void Student::SetLastName(string last) {
	lastName = last;
}

void Student::SetEmailAddress(string email) {
	emailAddress = email;
}

void Student::SetStudentAge(int age) {
	studentAge = age;
}

void Student::SetDaysInCourse(int days1, int days2, int days3) {
	daysInCourse[0] = days1;
	daysInCourse[1] = days2;
	daysInCourse[2] = days3;
}

void Student::SetDegreeProgram(string degreeType) {
	degreeType = degree;
}

void Student::print() {

	cout << "Student ID: " << GetStudentID();
	cout << "\t" << "First Name: " << GetFirstName();
	cout << "\t" << "Last Name: " << GetLastName();
	cout << "\t" << "Email Address: " << GetEmailAddress();
	cout << "\t" << "Age: " << GetStudentAge();
	cout << "\t" << "Days in Course: {"; cout << GetDaysInCourse()[0] << ", " << GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << "}";

}

Student::~Student() {}