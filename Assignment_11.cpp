#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student 
{
	int rollNumber;
	string name;
	string division;
	string address;
public:

    Student()
    {
        rollNumber = 0;
        name = "";
        division = "";
		address = "";
    }

	void addStudent() 
	{
		Student s;
		cout << "Enter Roll Number: ";
		cin >> s.rollNumber;
		cout << "Enter Name: ";
		cin>>s.name;
		cout << "Enter Division: ";
		cin>>s.division;
		cout << "Enter Address: ";
		cin>>s.address;

		ofstream outFile("student_info.txt", ios::app);
		outFile << s.rollNumber << endl;
		outFile << s.name << endl;
		outFile << s.division << endl;
		outFile << s.address << endl;

		cout << "Student information added successfully." << endl;
		outFile.close();
	}

	void deleteStudent() 
	{
		int rollNumber;
		cout << "Enter Roll Number of the student to delete: ";
		cin >> rollNumber;

		ifstream inFile("student_info.txt");
		ofstream tempFile("temp.txt");

		int currentRollNumber;
		bool found = false;

		while (inFile >> currentRollNumber) 
		{
			string name, division, address;
			cin >> name;
			cin >> division;
			cin >> address;

			if (currentRollNumber != rollNumber) 
			{
				tempFile << currentRollNumber << endl;
				tempFile << name << endl;
				tempFile << division << endl;
				tempFile << address << endl;
			} 
			else 
			{
				found = true;
			}
		}

		inFile.close();
		tempFile.close();

		remove("student_info.txt");
		rename("temp.txt", "student_info.txt");

		if (found) {
			cout << "Student information deleted successfully." << endl;
		}
		else {
			cout << "Student not found." << endl;
		}
	}

	void displayStudent() 
	{
		int rollNumber;
		cout << "Enter Roll Number of the student to display: ";
		cin >> rollNumber;

		ifstream inFile("student_info.txt");

		int currentRollNumber;
		bool found = false;

		while (inFile >> currentRollNumber) 
		{
			string name, division, address;
			cin >> name;
			cin >> division;
			cin >> address;

			if (currentRollNumber == rollNumber) 
			{
				cout << "Roll Number: " << currentRollNumber << endl;
				cout << "Name: " << name << endl;
				cout << "Division: " << division << endl;
				cout << "Address: " << address << endl;
				found = true;
				break;
			}
		}

		inFile.close();

		if (!found) 
		{
			cout << "Student not found." << endl;
		}
	}
};

int main() 
{
	int choice;
	Student s;
	do 
    {
		cout << "\n***** Student Information System *****" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. Delete Student" << endl;
		cout << "3. Display Student Information" << endl;
		cout << "4. Delete File" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) 
        {
			case 1:
				s.addStudent();
				break;
			case 2:
				s.deleteStudent();
				break;
			case 3:
				s.displayStudent();
				break;
			case 4:
				remove("student_info.txt");
				cout<<"file removed";
				break;
			case 5:
				cout << "Exiting program. Goodbye!" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}while (choice != 5);
	return 0;
}