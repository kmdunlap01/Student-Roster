#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Degree.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "Roster.h"
using namespace std;

Roster::Roster() {}

void Roster::add(string ID, string first, string last, string email, int age, int days1, int days2, int days3, Degree degreeType) {

	int daysInCourse[] = { days1, days2, days3 };

	switch (degreeType)
	{
	case SECURITY:
		classRosterArray[i] = new SecurityStudent(ID, first, last, email, age, daysInCourse, degreeType);
		break;

	case NETWORKING:
		classRosterArray[i] = new NetworkStudent(ID, first, last, email, age, daysInCourse, degreeType);
		break;

	case SOFTWARE:
		classRosterArray[i] = new SoftwareStudent(ID, first, last, email, age, daysInCourse, degreeType);
		break;

	default:
		break;
	}
	++i;
};

void Roster::remove(string studentID) {

	bool found = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				found = true;
			}
		}
	}
	if (found != false) {
		cout << "ERROR: The student with ID " << studentID << " was not found." << endl;
	}
};

void Roster::printAll() {

	cout << "Current Student Roster: " << endl;
	cout << endl;

	if (classRosterArray[i] != nullptr) {
		for (int i = 0; i < 5; i++) {
			(this->classRosterArray[i])->print();
		}
	}
	cout << endl;
};

void Roster::printDaysInCourse(string studentID) {

	bool found = false;
	int average = 0;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			average = ((classRosterArray[i]->GetDaysInCourse()[0]) + (classRosterArray[i]->GetDaysInCourse()[1]) + (classRosterArray[i]->GetDaysInCourse()[2])) / 3;
			cout << "The student with ID number " << studentID << " takes an average of " << average << " days to finish a course." << endl;
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

	cout << "Invalid emails:" << endl;
	cout << endl;

	string email = "";
	bool invalid = false;

	for (int i = 0; i < 5; i++) {
		email = classRosterArray[i]->GetEmailAddress();
		
		if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
			invalid = true;
			cout << this->classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int degreeType) {

	if (degreeType == 0) {
		cout << "Students in the Security degree program: " << endl;
	}
	else if (degreeType == 1) {
		cout << "Students in the Networking degree program: " << endl;
	}
	else if (degreeType == 2) {
		cout << "Students in the Software degree program: " << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeType) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}


void main()
{
	cout << "C867: Scripting and Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Kathryn Dunlap" << endl;
	cout << "Student ID# 000929222" << endl;
	cout << endl;
	cout << endl;


	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kathryn,Dunlap,kmdunlap1@gmail.com,30,25,35,32,SOFTWARE"
	};

	Roster classRoster;

	for (int i = 0; i < 5; i++) {

		stringstream ss(studentData[i]);
		string input[9];
		string row;
		int j = 0;
		Degree degreeType = SECURITY;

		while (getline(ss, row, ',')) {
			input[j] = row;
			j++;
		}

		if (input[8] == "SECURITY") {
			degreeType = SECURITY;
		}
		else if (input[8] == "NETWORK") {
			degreeType = NETWORKING;
		}
		else if (input[8] == "SOFTWARE") {
			degreeType = SOFTWARE;
		}

		classRoster.add(input[0], input[1], input[2], input[3], stoi(input[4]), stoi(input[5]), stoi(input[6]), stoi(input[7]), degreeType);
	}



	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++) {
		
		if (i == 0) {
			classRoster.printDaysInCourse("A1");
		}
		if (i == 1) {
			classRoster.printDaysInCourse("A2");
		}
		if (i == 2) {
			classRoster.printDaysInCourse("A3");
		}
		if (i == 3) {
			classRoster.printDaysInCourse("A4");
		}
		if (i == 4) {
			classRoster.printDaysInCourse("A5");
		}
	}
	
	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.remove("A3");

	return;
}

Roster::~Roster() {}