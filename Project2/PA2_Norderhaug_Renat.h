#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;

const int MAX = 10;

struct RentalCar {
  int year;
  char make[MAX];
  char model[MAX];
  float price;
  bool available;
};

// constraints on program
// make and model of car
// file name
const int FILE_MAX = 25;

// function prototypes to be implemented in cpp
void getInputFileName(char name[]);
// print arrayOfStructs
void printCars(char twoDArray[][8]);
// stores contents of file into struct
bool readFrom(char fileName[], struct RentalCar cars[5]);

// writes to the fileName given
bool writeTo(struct RentalCar cars[5]);

// copy entire contens of car struct
bool copyStruct(struct RentalCar &stockDest, struct RentalCar &stockSrc);

// print out items in the struct
void printAll(struct RentalCar cars[5]);

// lists all available cars after being given the days.
bool availableCars (int days, struct RentalCar cars[5]);
// has two different structs and swaps contents
bool swapCarStruct(struct RentalCar *stockA, struct RentalCar *stockB);

// print out a single struct item
void printCar(struct RentalCar car);

// sort car based on the price per day
bool sortAscending(struct RentalCar cars[5]);

// goes through the menu selection process
bool selectCar(int days, struct RentalCar cars[5]);

