//
//  Car.cpp
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>

#include "Car.h"

using namespace std;

//implementation of methods of RentalCar class

//Default constructor
Car::Car() {
    m_year=-1;
    strcpy(m_make,"");
    strcpy(m_model,"");
    m_baseprice=0.0;
    m_finalprice=0.0;
    m_available=false;
    m_sensorcount = 0;
    strcpy(m_owner,"");

}



//Parameterized constructor
Car::Car(int year, const char* make, const char* model, float baseprice,
                     bool available, const char* owner ) {
    m_year=year;
    strcpy(m_make,make);
    strcpy(m_model,model);
    m_baseprice=baseprice;
    m_available=available;
    m_sensorcount = 0;
    m_finalprice += m_baseprice;
}

Car::Car(const Car& car) {
    m_year=car.m_year;
    strcpy(m_make,car.m_make);
    strcpy(m_model,car.m_model);
    m_baseprice=car.m_baseprice;
    m_available=car.m_available;
    m_sensorcount = car.m_sensorcount;
    m_finalprice += m_baseprice;
}

//whether car is available
bool Car::isAvailable() const {
    return m_available;
}

//sets car availability
void Car::setAvailable(bool available) {
    m_available = available;
}

//returns make of car
const char* Car::getMake() const {
    return m_make;
}

//returns model of car
const char* Car::getModel() const {
    return m_model;
}

void Car::updatePrice() {
	m_finalprice = m_baseprice;
	for(int i = 0; i < m_sensorcount; i++) {
		m_finalprice += m_sensors[i].getExtraCost();
	}
}

//returns price of car
float Car::getFinalPrice() const {
    return m_finalprice;
}

//sets price of car
void Car::setBasePrice(float price) {
    m_baseprice = price;
}

//returns make year of car
int Car::getYear() const {
    return m_year;
}

//sets make year of car
void Car::setYear(int year) {
    m_year = year;
}

//prints car data
void Car::print() {
    //TODO need to loop through m_sensors and add print each sensor if any
    cout << m_year
    << " "<< m_make
    << " "<< m_model
    << ", $" << m_baseprice << " per day "
    << ", Available: ";
    if (m_available == 0)
        cout << "false" << endl;
    else
        cout << "true" << endl;
}

//estimates car rental cost
float Car::estimateCost(int days) {
    return (m_finalprice*days);
}

Car& Car::operator+(const Sensor& sensor) {
	if(m_sensorcount < 3) {
		m_sensors[m_sensorcount++] = sensor;
		m_finalprice += sensor.getExtraCost();
	}
	return *this;
}

Car& Car::operator+(const char owner[])
{
	strcpy(m_owner, owner);
	return *this;
}

std::istream& operator >> (std::istream& in, Car& car)
{
    in >> car.m_year
	>> car.m_make
    >> car.m_model
    >> car.m_baseprice;

    cout << "Reading car " << car.m_make << " " << car.m_model << " " << car.m_year << endl;

    bool end_of_sensors = false;
    do {
    	char raw_sensor_type[255];
    	in >> raw_sensor_type;

    	char *sensor_type = raw_sensor_type;

    	if(*sensor_type == '{') {
    		sensor_type++;
    	}

    	if(*(sensor_type + strlen(sensor_type) - 1) == '}') {
    		*(sensor_type + strlen(sensor_type) - 1) = 0;
    		end_of_sensors = true;
    	}

    	if(strlen(sensor_type) > 0) {
    		cout << "Adding sensor type: " << sensor_type << endl;
    		car = car + Sensor(sensor_type);
    	}

    } while(!end_of_sensors && in);

    in >> car.m_available;
    //cout << "Car available: " << car.m_available << endl;

    if(!car.m_available) {
    	in >> car.m_owner;
    	//cout << "Reading owner: " << car.m_owner << endl;
    }

    return in;
}
