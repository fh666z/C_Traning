/*
 * Ex9.cpp
 *
 *  Created on: 2.06.2015 ã.
 *      Author: user1
 */


#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void Ex9_test(void)
{
	char first_name[30], last_name[30];
	char file_name[30];
	unsigned age;

	cout << endl << "Enter name of the file to store data: "; cin >> file_name;

	// Create an ofstream called People, open the stream for output.
	ofstream People(file_name);

	while (true)
	{
		// Collect the data.
		cout << "Enter First Name: "; cin >> first_name;
		cout << "Enter Last Name: "; cin >> last_name;
		cout << "Enter Age: "; cin >> age;

		// Write the output to the stream.
		People << first_name << last_name << age;

		char resp;
		cout << "Do you want to continue: (Y/N)? ";
		cin >> resp;
		if ((resp == 'N') || (resp == 'n'))
			break;
	}

	People.close();

	ifstream people_file(file_name);

	while (!people_file.eof())
	{
		people_file >> first_name >> last_name >> age;
		cout << first_name << endl << last_name << endl << age << endl;
	}
	people_file.close();

}


