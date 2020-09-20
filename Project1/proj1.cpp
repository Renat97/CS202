/*
Renat Norderhaug
CS 202 Project 1
*/

#include <iostream>
#include <fstream>

using namespace std;

//prototypes
void getName(char name[]);
void clear_screen();
char correct(char name[]);
bool readFrom(char fileName[], char nameTable[][8]);
bool writeTo(char fileName[], char nameTable[][8]);
void print_unordered(char nameTable[][8]);
size_t strLen(const char str[]);

size_t MAX_SIZE = 50;

int main()
{
	char fileName[MAX_SIZE];
	char nameTwoDArray[10][8];
	char answer;

  cout << "Please enter a file name below! " << endl;
  // grabs the file Name with the get_name function
	getName(fileName);
	cout << "The name of your file is " << fileName << endl;
  //error check values, if not correct, then it needs to be repeated
  // reads in y or n
	answer = correct(fileName);
	if(answer != 'Y')
	{
		while(answer != 'Y')
		{
			cout << "repeat file name" << endl;
			getName(fileName);
			answer = correct(fileName);
		}
	}
  //Open a file and read from it.
	cout << "I'll open a file for data entry called, " << fileName << endl;
  if(readFrom(fileName, nameTwoDArray))
    cout << "successful read!" << endl;

  if(writeTo(fileName, nameTwoDArray))
    cout << "successful write!" << endl;

  cout << "Here's what's in the file in unsorted order" << endl;
  print_unordered(nameTwoDArray);

	return 0;
}
int strLen(char a[]) {
  int count = 0;
  int i = 0;
  while(a[i] != '\0') {
    a[i++];
    count++;
  }
  return count;
}
/*
 get_name:
	pre: expects a character entry from the user
	post: will have assigned an array to the variable name
*/
void getName(char name[])
{
	//clear_screen();
	cout << "What's the name of the file that you want to read in/output data from/to?"
  << endl;
	cin.get(name, MAX_SIZE, '\n');
  // clear the buffer by 100 characters
	cin.ignore(100, '\n');
  // if the char arrays length is greater than 100
	if(strLen(name) > MAX_SIZE)
	{
    // keep reading the array in.
		while(strLen(name) > MAX_SIZE)
		{
			cout << "Invalid entry. Try again:";
			cin.get(name, MAX_SIZE, '\n');
			cin.ignore(100, '\n');
		}
	}
	return;
}


void clearScreen()
{
	int i = 0;
	while(++i < 100) {
		cout << '\n';
  }
}

// checks if a name entered is the correct name.

char correct(char name[])
{
	char answer = 'X';
	cout << "You entered, " << name << ". Type 'y' for yes and 'n' for no." << endl;
	cin >> answer;
  // clear buffer
	cin.ignore();
  // always has to take input and make it upper or lowerCase
	answer = toupper(answer);
	return answer;
}


// opens a file up with ifstream to read into. Then Reads in the file.
// returns either true or false.
// name_table 2D array only includes rows as file is read line by line.
bool readFrom(char fileName[], char nameTable[][8])
{
  ifstream nameIn;
	nameIn.open(fileName);
  // if file exists
	if(nameIn)
	{
    // if its not the end of the file
		while(nameIn && !nameIn.eof())
    // 10 names maximum so 10 rows
		{
			int i = 0;
			while(i < 10)
			{
					nameIn.get(nameTable[i], 8, '\n');
          // clear the input stream
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
    // clear resets the error flags on the stream variable.
    nameIn.clear();
    nameIn.close();
    return false;
  }
}

/*
  write_to:
    Writes data to external data files by using the stored values in the
    name_table array, filled by the read_from function early described.
    1 returned means a success, 0 is a failure.
*/
bool writeTo(char fileName[], char nameTable [][8])
{
  ofstream name_out;
  cout << "Please enter the file name you want to read out to: " << endl;
  getName(fileName);
	name_out.open(fileName);

  // go through the 10 names of files
	if(name_out)
	{
		int i = 0;
		while(i < 10)
		{
			int j = 0;
			while (j < 8) {
				name_out << nameTable[i][j++];
      }
      name_out << endl;
      ++i;
		}
    cout << "succeeded" << endl;
    name_out.close();
    return true;
	}
	else
  {
		cout << "The file couldn't be opened." << endl;
	  name_out.close();
    return false;
  }
}

// prints the data stored in a 2d array without the data being ordered from the file.
void print_unordered(char nameTable[][8])
{
  int j = 0;
  while(j < 10) {
    int k = 0;
    while(k < 8) {
      cout << nameTable[j][k++];
    }
      cout << endl;
      ++j;
    }
    return;
  }




