#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include "Agency.h"
#include "Sensor.h"
#include "Car.cpp"
#include "Agency.cpp"
#include "Sensor.cpp"

using namespace std;

//
//  main.cpp
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

// Agency agency;

void select(int &selection);
void handleMostExpensiveCar(Agency &agency);
void printAllSensors();

int main() {

    int selection = 0;

    Agency agency;

    do {

        cout << "[1] Read all data from file" << endl;
        cout << "[2] Print all cars to terminal" << endl;
        cout << "[3] Print total number of sensors to terminal" << endl;
        cout << "[4] Find most expensive available car" << endl;
        cout << "[5] Exit program" << endl;

        select(selection);

        switch (selection) {
            case 1:
                agency.ReadAllData();
                break;
            case 2:
                agency.PrintAllData();
                break;
            case 3:
                printAllSensors();
                break;
            case 4:
                handleMostExpensiveCar(agency);
                break;
            case 5:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Bad input" << endl;
        }

    } while (selection != 5);

    return 0;
}

void select(int &selection) {
    cout << "Selection: ";
    cin >> selection; // saves user selection
}

void printAllSensors() {
    Sensor sensor;
    sensor.printAllSensors();
}

Car* findMostExpensiveCar(Agency& agency) {
	float maxPrice = 0;
	Car *mostExpensiveCar = NULL;
	for(int i = 0; i < 5; i++) {
		Car& currentCar = agency[i];
		if(!currentCar.getMake()) {
			break;
		}
		//cout << "Checking car " << currentCar.getMake() << endl;
		if(currentCar.getFinalPrice() > maxPrice) {
			mostExpensiveCar = &currentCar;
			maxPrice = currentCar.getFinalPrice();
		}
	}
	return mostExpensiveCar;
}

void handleMostExpensiveCar(Agency& agency) {
	Car *mostExpensiveCar = findMostExpensiveCar(agency);
	if(mostExpensiveCar) {
		cin.ignore();
		cout << "Most expensive car: ";
		mostExpensiveCar->print();
		cout << "Would you like to lease it (Y/N) ";
		char entry[255];
		cin.getline(entry, 2);
		if(strlen(entry) == 1 && (*entry == 'Y' || *entry == 'y')) {
			cout << "Enter your name: ";
			cin >> entry;
			*mostExpensiveCar = *mostExpensiveCar + entry;
		}
		cin.clear();
	} else {
		cout << "No cars found" << endl;
	}
}

