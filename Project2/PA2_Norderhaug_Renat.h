#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;

// constraints on program
// make and model of car
const int MAX = 10;
// file name
const int FILE_MAX = 25;

// function prototypes to be implemented in cpp
void getInputFileName(char name[]);
void printCars(char twoDArray[][8]);
char correct(char name[]);
bool readArr(char fileName[], char nameTable[][8]);
bool writeArr(char fileName[], char nameTable[][8]);

// stores contents of file into struct
bool readFrom(char fileName[], struct RentalCar cars[5]);

// writes to the fileName given
bool writeTo(struct RentalCar cars[5]);

// strcpy
char *myStrCpy(char *destination, const char * src);

// strcmp
int mystrcmp(const char *str1, const char *str2);

// copy entire contens of car struct
bool copyStruct(struct RentalCar &stockDest, struct RentalCar &stockSrc);

// has two different structs and swaps contents
bool swapCarStruct(struct RentalCar *stockA, struct RentalCar *stockB);

// sort car based on the price per day
bool sortAscending(struct RentalCar cars[5]);

// print out items in the struct
void printAll(struct RentalCar cars[5]);

// lists all available cars after being given the days.
bool availableCars (int days, struct RentalCar cars[5]);

// goes through the menu selection process
bool selectCar(int days, struct RentalCar cars[5]);

// print out a single struct item
void printCar(struct RentalCar car);



struct RentalCar {
  int year;
  char make[MAX];
  char model[MAX];
  float price;
  bool available;
};