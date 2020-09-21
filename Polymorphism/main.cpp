//
//  main.cpp
//
//  Created by Renat Norderhaug on 9/29/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include <iostream>
using namespace std;

class Car
{
public:
// virtual so it can be redefined in inherited classes
  virtual void drive()
  {
    cout << "Fish Swims!" << endl;
  }
};

class BMW:public Car
{
public:
  //override Fish::Swims
  void drive()
  {
    cout << "driving a BMW!" << endl;
  }
};

//Class Carp (demonstrates the use of virtual function)
class Maserati:public Car
{
public:
  void drive()
  {
    cout << "driving a Maserati!" << endl;
  }
};

void callCar(Car& firstCar)
{
  // the first car drive method
  firstCar.drive();
}

int main()
{
  BMW car1;
  Maserati car2;

  callCar(car1);
  callCar(car2);

  return 0;
}
