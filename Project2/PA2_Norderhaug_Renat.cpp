/*Project 2
CS202
by Renat Norderhaug
*/

#include <fstream>
#include <iostream>
#include "PA2_Norderhaug_Renat.h"

int main() {
  // declare a RentalCar struct of arrays
  RentalCar cars[5];
  // the file's name
  char fileName[5];
  // keep track of the days for each car
  int days;
  cout << "\nWhat's the name of your input file?\n";
  getInputFileName(fileName);
  // assign each array an individual file
  if(!readFrom(fileName, cars)) {
      cout << "Please try again and enter a valid file to read!" << endl;
      return 0;
  }

  cout << "\n" << endl;

  printAll(cars);
  cout << "lets sort the cars!" << endl;
  if(!sortAscending(cars)) {
    cout <<"Sorry that wasnt the right format!" << endl;
    cout <<"program exiting" << endl;
    return 0;
  }
  // prints to new fileName
  cout << "insert new fileName to output data" << endl;
  if(writeTo(cars)) {
    cout << "cars written!" << endl;
  } else {
    cout << "Error loading!" << endl;
    return 0;
  }

  // print out data for cars
  cout <<"Price ascending order" << endl;
  printAll(cars);

  days = 0;
  cout << "How many days do you want to rent the car for? " << endl;
  cin >> days;

  cout << "\n" << endl;

  // how many days to rent, print available cars sorted

  if(!selectCar(days, cars)) {
    cout << "Sorry theres no cars" << endl;
    return 0;
  }

  cout << "Thank you for using the program!" << endl;
  return 0;
}

/* assigns an array to the fileName */
void getInputFileName(char name[])
{
	cin.get(name, FILE_MAX, '\n');
	cin.ignore(100, '\n');
	if(strlen(name) > FILE_MAX)
	{
    // handles error case if fileName is too long
		while(strlen(name) > FILE_MAX)
		{
      cout << "INVALID ENTRY" << endl;
      cin.get(name, FILE_MAX, '\n');
      cin.ignore(100, '\n');
    }
	}
	return;
}

/*
	To check if your fileName is correct, enter a Y or N after.
*/
char correct(char name[])
{
	char answer = 'X';
	cout << "\nYou entered, " << name << ". Is this correct? (Y/N)" << endl;
	cin >> answer;
	cin.ignore();
  // always makes sure answer is uppercase
	answer = toupper(answer);
	return answer;
}

/*
    reads from an outside data file and holds the contents into an 2D array
*/
bool readArr(char file_name[], char name_table[][8])
{
  ifstream nameIn;
	nameIn.open(file_name);

	if(nameIn)
	{
		while(nameIn && !nameIn.eof())
		{
			int i = 0;
			while(i < 10)
			{
					nameIn.get(name_table[i], 8, '\n');
					nameIn.ignore(100, '\n');
				++i;
			}
		}
    cout << "Success!" << endl;
    nameIn.clear();
    nameIn.close();
    return true;
	}
	else
  {
		cout << "Couldn't open file!" << endl;
    nameIn.clear();
    nameIn.close();
    return false;
  }
}

/*
    // writes the data from the matrix out to a new file
*/
bool writeArr(char fileName[], char nameTable[][8])
{
  ofstream nameOut;
  cout << "\nNow for the file name to write out to, please enter it!" << endl;
  getInputFileName(fileName);
	nameOut.open(fileName);

	if(nameOut)
	{
		int i = 0;
		while(i < 10)
		{
			int j = 0;
			while (j < 8) {
      // write out the matrix to the file in loops for arrays and columns
				nameOut << nameTable[i][j++];
      }
      nameOut << endl;
      ++i;
		}
    cout << "\nIt worked!" << endl;
    // close the file
    nameOut.close();
    return true;
	}
	else
  {
		cout << "\nFile couldn't be opened!" << endl;
	  nameOut.close();
    return false;
  }
}

// places all the reads from the file into a struct
// returns a true value if it is successfully read.

bool readFrom(char fileName[], struct RentalCar cars[5])
{
  // input file stream file
  ifstream nameIn;
	nameIn.open(fileName);

	if(nameIn)
	{
		while(nameIn && !nameIn.eof())
		{
			int i = 0;
			while(i < 5)
			{
          //cout << "What is the year of the vehicle?" << endl;
					nameIn >> cars[i].year;


          //cout << "What is the make of the vehicle?" << endl;
          nameIn >> cars[i].make;


          //cout << "What is the model of the vehicle?" << endl;
          nameIn >> cars[i].model;

          //cout << "What is the price of the vehicle to rent?" << endl;
          nameIn >> cars[i].price;

          //cout << "Is this vehicle available?" << endl;
          nameIn >> cars[i].available;
          // clear the cache
          nameIn.ignore(100, '\n');
          cout << endl << endl;
				++i;
			}
		}
    cout << "\nSuccessfully Read" << endl;
    // to clear the errors and close file
    nameIn.clear();
    nameIn.close();
    return true;
	}
	else
  {
		cout << "\nCouldn't open file!" << endl;
    // clear the errors and close file
    nameIn.clear();
    nameIn.close();
    return false;
  }

}

/*
    // writes to a user specified file, the array of structs.
*/
bool writeTo(struct RentalCar cars[5])
{
  if(!cars)
    return false;

  char fileName[FILE_MAX];
  // output stream variable to write to a file
  ofstream nameOut;
  cout << endl << endl;
  cout << "\nPlease enter the file name to write to: " << endl;
  getInputFileName(fileName);
  nameOut.open(fileName);

  if(nameOut)
  {
    cout << "\nThe available cars are: " << endl << endl;
    int i = 0;
    while(i < 5)
    {
      nameOut << "Car " << i + 1 << ": " << endl;
      nameOut << cars[i].year << endl;
      nameOut << cars[i].make << endl;
      nameOut << cars[i].model << endl;
      nameOut << "$" << cars[i].price << "/day " << endl;
      nameOut << "In stock: ";
      if(cars[i].available)
        nameOut << "Yes" << endl;
      else
        nameOut << "Unavailable" << endl;
      nameOut << "--------------------------" << endl;
      ++i;
    }
    cout << "The File has been created and entered." << endl;
    return true;
  }
  else
  {
    cout << "Invalid data" << endl;
    return false;
  }
}

/// StrCopy function implemented

char* strCpy(char *dst, const char *src)
{
	while (*dst++ = *src++);
  return dst;
}

/// str Compare function implemented
int	strCmp(const char *str1, const char *str2)
{
	while ((unsigned char)*str1 &&
		((unsigned char)*str1 == (unsigned char)*str2))
	{
		++str1;
		++str2;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}

/*
 copies from one car struct to another, uses helper functions on the char arrays
*/
bool copyStruct(struct RentalCar *carDest, struct RentalCar *carSrc)
{
    struct RentalCar *src = carSrc;
    struct RentalCar *dest = carDest;

    dest->year = src->year;
    strCpy(dest->model, src->model);
    strCpy(dest->make, src->make);
    dest->price = src->price;
    dest->available = src->available;
    return true;
}

/*
  swaps the rental car structs
*/
bool swapCarStruct(struct RentalCar *carA, struct RentalCar *carB)
{
  if(!carA && !carB)
    return false;
  //assign temporary struct pointer
  struct RentalCar *temp = new RentalCar;
  //have temporary pointer pointing to stockA
  copyStruct(temp, carA);

  if(!copyStruct(carA, carB))
    {
      cout << "\ncopy failed!" << endl;
      delete temp;
      return false;
    }

  // car A -> car B from temp
  if(!copyStruct(carB, temp))
  {
    cout << "\nDidn't copy!" << endl;
    delete temp;
    return false;
  }
  delete temp;
  return true;
}

/*
  sortAscending:
   bubble sort algorithm applied to array of car structs

*/
bool sortAscending(struct RentalCar cars[5])
{
  if(!cars)
    return false;
 /// bubble sort algorithm that compares the next element in two while loops
  int j;
  int i = 0;
  while (i < 4)
  {
      j = 0;
      while(j < 5-i-1)
      {
        // bring j+1 closer to the front of the array
        if(cars[j].price > cars[j+1].price)
          swapCarStruct(&cars[j], &cars[j+1]);
        j++;
      }
    i++;
  }
  return true;
}

// prints data in the array of structs to terminal

void printAll(struct RentalCar cars[5])
{
  if(!cars)
    return;

  cout << "\nThe car inventory is: " << endl << endl;
  int i = 0;
  while(i < 5)
  {
    cout << "Car " << i + 1 << ": " << endl;
    cout << cars[i].year << endl;
    cout << cars[i].make << endl;
    cout << cars[i].model << endl;
    cout << "$" << cars[i].price << "/day " << endl;
    if(cars[i].available)
      cout << "yes available" << endl;
    else
      cout << "Unavailable!" << endl;
    cout << "--------------------------" << endl;
    ++i;
  }
}

void printCar(struct RentalCar car)
{
  cout << car.year << endl;
  cout << car.make << endl;
  cout << car.model << endl;
  cout << car.price << endl;
  if(car.available) {
    cout << "car is available" << endl;
  }
}

/*
  criteria to check when to use the print car function, only if car is available
  */
bool availableCars (int days, struct RentalCar cars[5])
{
  if(days < 0)
    return false;

  cout << "Available cars for " << days << " days:" << endl;
  int i = 0;
  while(i < 5)
  {
    if(cars[i].available)
    {
      cout << "Car # " << i+1 << ":" << endl;
      printCar(cars[i]);
      cout << "The Price estimate for " << days << " days: ";
      cout << "$" << (cars[i].price * days) << endl;
      cout << "-------------------------------" << endl;
      ++i;
    }
    else
      ++i;
  }
  return true;
}

/*
  user makes selection based on car number
  */
bool selectCar(int days, struct RentalCar cars[5])
{
  int selection = 0;
  if(days < 0) {
    return false;
  }

  cout << "Choose the car that you are interested in " << endl;
  cout << endl;
  availableCars(days, cars);
  cout << "Choose the number of the vehicle you want: ";
  cin >> selection;
  // check the range of cars
  while(!((selection >= 1) && (selection <= 5)))
  {
    cout << "That is out of range" << endl;
    cout << "Renter your selection" << endl;
    cin >> selection;
  }

  selection -= 1;
  if(cars[selection].available)
  {
    cout << endl << endl;
    cout << "you've successfully rented this vehicle!\n";
    cout << "The total price is: $\n";
    // price for car
    cout << (cars[selection].price * days) << endl;
    cout << "Thank you for your business!\n" << endl;
    cout << endl;
    cars[selection].available = false;
    return true;
  }
  else
  {
    cout << "That car is unavailable! please restart program" << endl;
    return false;
  }
}
