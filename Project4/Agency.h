//
//  Agency.h
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#ifndef Agency_h
#define Agency_h

#include <stdio.h>
#include "Car.h"

/* Agency_h */

class Agency {

private:
    char m_name[255];
    int m_zipcode;
    Car m_inventory[5];

public:
    Agency();// default constructor
    Agency(const int a);
    char *GetName();
    void SetName(const char* name);
    const int GetZipcode();
    void SetZipcode(int zipcode);
    void ReadAllData();
    void PrintAllData();
    void PrintAvailableCars();
    Car& operator[](const int index);
};
#endif //Agency_h
