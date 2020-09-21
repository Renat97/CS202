#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <cstring>
#include <iostream>

const int MAX = 255;

class Car: public Vehicle {
  private:
  char m_plates[MAX];
  int m_throttle;

  public:
  // default constructor
  Car();
  // parameterized
  Car(const char * Plates, int src, float* lla);
  // copy
  Car(const Car& car);
  // destructor
  ~Car();
  // assignment operator
  Car& operator= (const Car& src);
  // get and set m_plates
  int getThrottle () const;

  char * getPlates ();

  bool setPlates (const char* srcPlates);

  int setThrottle (const int srcThrottle);

  bool Drive(int throttle);

  void Move(float* lla);

  friend ostream& operator <<(ostream& os, const Car& src);

};

#endif