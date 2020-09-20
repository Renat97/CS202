
#include <iostream>
#include <iomanip>
#include <fstream>
#include "RentalCar.cpp"
#include "RentalAgency.h"

using namespace std;

const int AGENCIES_COUNT = 3;
const int CARS_COUNT = 5;

struct agency {
    char name[255];
    int zipcode[5];
    RentalCar inventory[5];
};

void select(int &selection);
 int myStringCompare(char *str1, char *str2);
void readFile(agency *agency_ptr);
void printData(agency *agency_ptr);
void printAvailableCarsToFile(agency *agency_ptr);
void estimatePrice(agency *agency_ptr);
void mostExpensive(agency *agency_ptr);
void myFavoriteAgency(agency *agency_ptr);

int main() {

    agency agencies[AGENCIES_COUNT];
    agency *agency_ptr = agencies; //create pointer to first agency

    int selection = 0;
    do {

        cout << "[1] Read data from file" << endl;
        cout << "[2] Print out all data for all agencies" << endl;
        cout << "[3] Estimate car rental cost" << endl;
        cout << "[4] Find most expensive car" << endl;
        cout << "[5] Print out only the available cars" << endl;
        cout << "[6] Print out your fav agency's first car" << endl;
        cout << "[7] Exit program" << endl;

        select(selection);
        // point it the agencies array of structs
        agency_ptr = agencies;

        switch (selection) {
            case 1:
                readFile(agency_ptr);
                break;
            case 2:
                printData(agency_ptr);
                break;
            case 3:
                estimatePrice(agency_ptr);
                break;
            case 4:
                mostExpensive(agency_ptr);
                break;
            case 5:
                printAvailableCarsToFile(agency_ptr);
                break;
            case 6:
                myFavoriteAgency(agency_ptr);
                break;
            case 7:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Bad input" << endl;
        }

    } while (selection != 7);

    return 0;
}

void select(int &selection) {
    cout << "Option: ";
    cin >> selection; // saves user selection
}

void readFile(agency *agency_ptr) {
    ifstream fin;
    char fileName[20];

    cout << "Enter input file name: ";
    cin >> fileName;
    fin.open(fileName);

    if (fin.is_open()) {
        for (int i = 0; i < AGENCIES_COUNT; i++) {
            int *zip_ptr = (*agency_ptr).zipcode; //creates pointer to first int in zip

            //reading zip char by char and converting to integers
            fin >> agency_ptr->name;
            for (int j = 0; j < 5; j++) {
                char c;
                fin >> c;
                int iZipNum = (int)c - 48;
                *zip_ptr = iZipNum;
                zip_ptr++;
            }

            cout << " Reading inventory for "<< (*agency_ptr).name << endl;
            for (int k = 0; k < CARS_COUNT; k++) {
            	RentalCar *car_ptr = agency_ptr->inventory + k;
            	fin >> *car_ptr;
				//car_ptr->print();  //print for troubleshooting
            }

            agency_ptr++;
        }
        cout << "Data successfully read from " << fileName << endl;
    } else { cout << "Failed to read data from " << fileName; }
}

void printData(agency *agency_ptr) {
    for (int i = 0; i < AGENCIES_COUNT; i++) {
        int *zip_ptr = (*agency_ptr).zipcode;

        cout << (*agency_ptr).name << " ";

        for (int j = 0; j < 5; j++) { // here we only need to print hence no conversion to int
            cout << *zip_ptr;
            zip_ptr++;
        }
        cout << endl;

        for (int k = 0; k < CARS_COUNT; k++) {
            RentalCar *car_ptr = agency_ptr->inventory + k;
            car_ptr->print();
        }
        agency_ptr++;
    }
}

void printAvailableCarsToFile(agency *agency_ptr) {

    char OutputName[40];
    cout <<"What is the name of the output file?\n";
    cin >>OutputName;
    ofstream outFileStream (OutputName);

    for (int i = 0; i < AGENCIES_COUNT; i++) {
        int *zip_ptr = (*agency_ptr).zipcode;

        //cout << (*agency_ptr).name << " ";
        outFileStream << (*agency_ptr).name << " ";

        for (int j = 0; j < 5; j++) { // here we only need to print hence no conversion to int
            //cout << *zip_ptr;
            outFileStream << *zip_ptr;
            zip_ptr++;
        }
        //cout << endl;
        outFileStream << endl;

        for (int k = 0; k < CARS_COUNT; k++) {
            RentalCar *car_ptr = agency_ptr->inventory + k;
            if(car_ptr->isAvailable() ) {
              outFileStream << car_ptr->getYear()
              << " "<< car_ptr->getMake()
              << " "<< car_ptr->getModel()
              << ", $" << car_ptr->getPrice() << " per day "
              << endl;
            }
        }
        agency_ptr++;
    }
    cout << "Inventory of available cars is printed to file " << OutputName << endl;
}

void estimatePrice(agency *agency_ptr) {
    char agencyName[20];
    int carNumber;
    int dayCount;
    cout << "Enter agency name: ";
    cin >> agencyName;
    cout << "Enter car number (1-5): ";
    cin >> carNumber;
    cout << "Enter number of days to rent a car: ";
    cin >> dayCount;

    for (int i = 0; i < AGENCIES_COUNT; i++) {
        // check if the agency's name is same as the name entered
        // if stringCompare returns 1
        if (myStringCompare((*agency_ptr).name, agencyName)) {
            i = AGENCIES_COUNT;
            RentalCar *car_ptr = agency_ptr->inventory + (carNumber -1); // offset for array index
            cout << "Getting estimate for car number  " << carNumber << ": " << car_ptr ->getYear()
            << " " << car_ptr ->getMake() << " "<< car_ptr ->getModel()  << endl;
            float cost = car_ptr -> estimateCost(dayCount);
            cout << "Estimated total cost is: $" << cost << endl;
        } else {
            agency_ptr++;
            cout << "going to next Agency" << endl;
        }
    }
}

void mostExpensive(agency *agency_ptr) {
    float topPrice = 0.0f;
    RentalCar *most_exp_ptr; // this will point to the most expensive car

    for (int i = 0; i < AGENCIES_COUNT; i++) {
        for (int k = 0; k < CARS_COUNT; k++) {
            RentalCar *car_ptr = agency_ptr->inventory + k;
            if (car_ptr ->getPrice() > topPrice) {
                topPrice = car_ptr ->getPrice();
                most_exp_ptr = car_ptr;
            }
            car_ptr++;
        }
        agency_ptr++;
    }

    cout << most_exp_ptr ->getMake() << " "<< most_exp_ptr ->getModel()
         << " is the most expensive car at $" << most_exp_ptr ->getPrice() << endl;
}
void myFavoriteAgency(agency *agency_ptr) {
    char myFavoriteAgency[50];
    cout << "Enter your favorite agency's name" << endl;
    cin >> myFavoriteAgency;
    cout << (*agency_ptr).name << endl;
    for(int i = 0; i < AGENCIES_COUNT; i++) {
    if(myStringCompare((*agency_ptr).name, myFavoriteAgency)) {
        RentalCar *car_ptr = agency_ptr -> inventory;
        cout << "Your favorite agency's first car's price is " << car_ptr -> getPrice() << endl;
        break;
    }
    else {
        cout << "checking next agency" << endl;
        agency_ptr = agency_ptr+1;
    }
    }
}

// check both strings are equal

int myStringCompare(char * str1, char * str2)
{
    while(*str1==*str2) {
        if(*str1=='\0' || *str2=='\0') {
            break;
        } else {
        str1++;
        str2++;
        }
    if(*str1=='\0' && *str2=='\0') {
        return 1;
    }
 }
 return 0;
}

