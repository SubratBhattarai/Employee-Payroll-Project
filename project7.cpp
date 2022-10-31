#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<cstdlib>
#include<process.h>

using namespace std;
int main();


class ControlMenu {

public:
	void Add(); // adding 
	void Show();	// Showing
	void Update();	// updating
	void Delete();	// Deleting
	void Search();	// Searching
};
	
void ControlMenu::Add() {
	system("CLS");
	int id, hrs;
	string Ename, Address;
	float salary;
	cout << "\t\t\t\t\n Adding Employee" << endl;
	cout << "\n\n\n\n Enter Employee ID: "; cin >> id;
	cout << "Enter Employee Name: "; cin >> Ename;
	cout << "Enter Employee Working hours: "; cin >> hrs;
	cout << "Enter Employee Salary: "; cin >> salary;
	cout << "Enter Employee Address: "; cin >> Address;
	fstream file;
	file.open("employee.txt", ios::app);
	if (!file) {
		cout << "File not found" << endl;
	}
	else {
		file << id << "   " << Ename << "   " << hrs << "   " << salary << "   " << Address << endl;
	}
	cout << "\n\n\n\t\t Thank You! " << endl;
	file.close();
	char choose;
	cout << "Do you want to return:(y/n) "; cin >> choose;
	if (choose == 'y' || choose == 'Y') {
		system("ClS");
		main();
	}
	else {
		exit(0);
	}
 }	
void ControlMenu::Show() {
		system("CLS");
		int id, hrs;
		string Ename, Address;
		float salary;
		ifstream file;
		file.open("employee.txt");
		if (!file) {
			cout << "File not Found" << endl;
		}
		else {
			cout << " ID " << "		 " << "Name" << "		" << "Hours" << "		" << "Salary" << "		" << " Addresss" << endl;
			file >> id >> Ename >> hrs >> salary >> Address;
			while (!file.eof())
			{
				cout << id <<  "		" << Ename << "		" << hrs <<  "		" << salary << "		" << Address << endl;
				file >> id >> Ename >> hrs >> salary >> Address;
			}
		}
		file.close();
		cout << "\n\n\n\t\t Thank You! " << endl;
		char choose;
		cout << "Do you want to return:(y/n) "; cin >> choose;
		if (choose == 'y' || choose == 'Y') {
			system("ClS");
			main();
		}
		else {
			exit(0);
		}
	}
void ControlMenu::Update() {
	system("CLS");
	int id, hrs, Uid;
	string Ename, Address;
	float salary;
	int count = 0;
	ofstream file1;
	file1.open("employee1.txt");
	fstream file;
	file.open("employee.txt");
	if (!file) {
		cout << "File not Found" << endl;
	}
	else {
		cout << "Enter the ID you want to Update: "; cin >> Uid;
		file >> id >> Ename >> hrs >> salary >> Address;
		while (!file.eof())
		{
			if (Uid == id) {
				cout << "\t\t\t\t\n Updating An Account" << endl << endl << endl;
				cout << "Enter New Employee Name: "; cin >> Ename;
				cout << "Enter New Employee Working hours: "; cin >> hrs;
				cout << "Enter New Employee Salary: "; cin >> salary;
				cout << "Enter New Employee Address: "; cin >> Address;
				count++;
				file1 << id << "   " << Ename << "   " << hrs << "   " << salary << "   " << Address << endl;
			}
			else {
				file1 << id << "   " << Ename << "   " << hrs << "   " << salary << "   " << Address << endl;
			}
			file >> id >> Ename >> hrs >> salary >> Address;
		}
	}
		file.close();
		file1.close();
		remove("employee.txt");
		bool renamed = rename("employee1.txt", "employee.txt");
		if (count == 0) {
			cout << "File not Found " << endl;
		}
		cout << "\n\n\n\t\t Thank You! " << endl;
		char choose;
		cout << "\t\t\t\n\n\nDo you want to return:(y/n) "; cin >> choose;
		if (choose == 'y' || choose == 'Y') {
			system("ClS");
			main();
		}
		else {
			exit(0);
		}
} // ifstream changed
void ControlMenu::Delete() {
	system("CLS");
	int id, hrs;
	string Ename, Address;
	float salary;
	int count = 0;
	int del;
	ofstream file1;
	file1.open("employee1.txt");
	fstream file;
	file.open("employee.txt");
	cout << "\t\t\t\t\t\n\n\n\t\t\n Delelting Records" << endl << endl;
	if (!file) {
		cout << "File not Found" << endl;
	}
	else {
		cout << "Enter the id of the Account you want to delete: "; cin >> del;
		file >> id >> Ename >> hrs >> salary >> Address;
		while (!file.eof())
		{
			if (del == id) {
				cout << "\t\t\t\n Account Deleting" << endl;
				cout << "Account Deleting Successful!!!" << endl;
				count++;
			}
			else
			{
				file1 << id << "   " << Ename << "   " << hrs << "   " << salary << "   " << Address << endl;
			}
			file >> id >> Ename >> hrs >> salary >> Address;
		}
		file.close();
		file1.close();
		remove("employee.txt");
		bool renamed = rename("employee1.txt", "employee.txt");
		if (count == 0) {
			cout << "File not Found" << endl;
		}
	}
	cout << "\n\n\n\t\t Thank You! " << endl;
	char choose;
	cout << "Do you want to return:(y/n) "; cin >> choose;
	if (choose == 'y' || choose == 'Y') {
		system("ClS");
		main();
	}
	else {
		exit(0);
	}

}
void ControlMenu::Search() {
	system("CLS");
	int id, hrs;
	string Ename, Address;
	float salary;
	int count = 0;
	int Sel;
	fstream file;
	file.open("employee.txt");
	cout << "\t\t\t\t\t\n\n\n\t\t\n Searching Record" << endl << endl;
	if (!file) {
		cout << "File not Found" << endl;
	}
	else {
		cout << "Enter the id of the Account you want to Search: "; cin >> Sel;
		cout << endl << endl << endl;
		cout << " ID " << "		 " << "Name" << "		" << "Hours" << "		" << "Salary" << "		" << " Addresss" << endl;
		file >> id >> Ename >> hrs >> salary >> Address;
		while (!file.eof())
		{
			if (Sel == id) {
				cout << endl << id << "		" << Ename << "		" << hrs << "		" << salary << "		" << Address << endl;
				count++;
			}
			file >> id >> Ename >> hrs >> salary >> Address;
		}
		file.close();
		if (count == 0) {
			cout << "file not found" << endl;
		}
		cout << "\n\n\n\t\t Thank You! " << endl;
		char choose;
		cout << "Do you want to return:(y/n) "; cin >> choose;
		if (choose == 'y' || choose == 'Y') {
			system("ClS");
			main();
		}
		else {
			exit(0);
		}
	}
}


int main() {
	cout << "\t\t\t\t\n Employee PayRoll" << endl;
	cout << "\t\t\t\t\n1. Add Employee" << endl;
	cout << "\t\t\t\t\n2. Show Employee" << endl;
	cout << "\t\t\t\t\n3. Update Employee" << endl;
	cout << "\t\t\t\t\n4. Delete Employee" << endl;
	cout << "\t\t\t\t\n5. Search Employee" << endl;
	cout << "\t\t\t\t\n6. Exit" << endl;
	int option;
	cout << "\n\n\n\t Choose the option "; cin >> option;
		switch (option)
		{
		case 1: {
			ControlMenu Cu;
			Cu.Add();
			break;
		}
		case 2: {
			ControlMenu Cu;
			Cu.Show();
			break;
		}
		case 3: {
			ControlMenu Cu;
			Cu.Update();
			break;
		}
		case 4: {
			ControlMenu Cu;
			Cu.Delete();
			break;
		}
		case 5: {
			ControlMenu Cu;
			Cu.Search();
			break;
		}
		case 6: {
			exit(0);
			break;
		}
		default: {
			cout << "Invalid Request" << endl;
			break;
		}
	}
	return 0;
}