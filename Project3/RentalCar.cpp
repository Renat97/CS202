//
//  RentalCar.cpp
//  Project 5
//
//  Created by Renat Norderhaug on 9/10/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include "RentalCar.h"

using namespace std;

//implementation of methods of RentalCar class

//Default constructor
RentalCar::RentalCar() {
   m_year=-1;
   strcpy(m_make,"");
   strcpy(m_model,"");
   m_price=0.0;
   m_available=false;
}

//Parameterized constructor
RentalCar::RentalCar(int year, const char* make, const char* model, float price,
       bool available) {
   m_year=year;
   strcpy(m_make,make);
   strcpy(m_model,model);
   m_price=price;
   m_available=available;
}

//whether car is available
bool RentalCar::isAvailable() const {
   return m_available;
}

//sets car availability
void RentalCar::setAvailable(bool available) {
   m_available = available;
}

//returns make of car
const char* RentalCar::getMake() const {
   return m_make;
}

//returns model of car
const char* RentalCar::getModel() const {
   return m_model;
}

//returns price of car
float RentalCar::getPrice() const {
   return m_price;
}

//sets price of car
void RentalCar::setPrice(float price) {
   m_price = price;
}

//returns make year of car
int RentalCar::getYear() const {
   return m_year;
}

//sets make year of car
void RentalCar::setYear(int year) {
   m_year = year;
}

//prints car data
void RentalCar::print() {
   cout << m_year
   << " "<< m_make
   << " "<< m_model
   << ", $" << m_price << " per day "
   << ", Available: ";
   if (m_available == 0)
   cout << "false" << endl;
   else
   cout << "true" << endl;
}

//estimates car rental cost
float RentalCar::estimateCost(int days) {
   return (m_price*days);
}

std::istream& operator >> (std::istream& in, RentalCar& car)
{
	std::string line;
	in >> car.m_year
		>> car.m_make
		>> car.m_model
		>> car.m_price
		>> car.m_available;
	in.ignore();

	return in;
}
