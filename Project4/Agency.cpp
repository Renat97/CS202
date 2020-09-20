//
//  Agency.cpp
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "Agency.h"

using namespace std;

static int CAR_COUNT = 5;

Agency::Agency() : m_zipcode(0) // zipcode is initialized this way because it's a constant
{
    strcpy(m_name,"");

}// default constructor

//Agency::Agency(const int a ) {
 //   m_zipcode = a;
//}
//gets name of Agency
 char* Agency::GetName()  {
    return m_name;
}

//Sets name of Agency
void Agency::SetName(const char* name)  {
    strcpy(m_name, name);
}

//gets zipcode of Agency
const int Agency::GetZipcode()  {
    return m_zipcode;
}

Car& Agency::operator[](int index) {
   return m_inventory[index];
}

void Agency::ReadAllData() {
	char ifileName[20]; // Create var to hold input file name
	cout << "Enter input file name: ";
	cin >> ifileName; // Save user input to file name
	ifstream fin;
	//cout << "Used entered input file name: " << ifileName;
	fin.open(ifileName); // open user-definied file
	if (fin.is_open()) { // Check if file opened correctly

		fin >> m_name
			>> m_zipcode;

		fin.ignore();
		//cout << "Reading data for agency " << m_name << " in zipcode " << m_zipcode << endl;

		//Agency agency = *this;
		for (int i = 0; i < CAR_COUNT; i++) { // loop through each car in cars array
			/* Populate cars array with data from user-defined file*/
			fin >> (*this)[i];
		}
		//cout << "Data from " << ifileName << " read successfully" << endl;

	} else {
		cout << "Failed to open file named " << ifileName;
	}
	fin.close();
}

void Agency::PrintAvailableCars() {

	for (int i = 0; i < CAR_COUNT; i++) {
		Car car = (*this)[i];
		car.print();
	}
}

void Agency::PrintAllData() {
	PrintAvailableCars();
}


