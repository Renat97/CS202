//
//  Car.h
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//


#ifndef Car_h
#define Car_h
#include <stdio.h>
#include <cstdio>
#include "Sensor.h"
#include <fstream>

using namespace std;

class Car {
private:
    int m_year; //year
    char m_make[255]; //make
    char m_model[255]; //model
    float m_baseprice; // price per day for the sensorless vehicle
    float m_finalprice;// price per day with the increased cost of the car sensors
    bool m_available; //whether available
    Sensor m_sensors[3]; // a sensor class type
    int m_sensorcount;
    char m_owner[255];

public:
    Car(); //default constructor
    Car(int,const char*,const char*,float,bool,const char*); //parameterized constructor
    //getters and setters
    Car(const Car& car);
    bool isAvailable() const;
    void setAvailable(bool available);
    const char* getMake() const;
    const char* getModel() const;
    float getBasePrice() const;
    void setBasePrice(float price);
    float getFinalPrice() const;
    int getYear() const;
    void setYear(int year);
    const char* get_owner() const;
    void setowner(char *owner);

    void updatePrice();
    void print(); //prints car data
    float estimateCost(int); //estimates car rental cost
    Car& operator+(const Sensor& sensor);
    Car& operator+(const char owner[]);

    friend istream& operator >> (istream& in, Car& car);
};

#endif

