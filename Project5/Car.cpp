//
//  Car.cpp
//  Project5
//
//  Created by Renat Norderhaug on 9/29/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//
#include "Car.h"
#include <cstring>
#include <iostream>
// m_vin inherited for car
  Car::Car ()
  {
    setThrottle(0);
    cout << "Car: " << m_vin << ": Default-ctor" << endl;
  }

  //parameterized constructor
  Car::Car (const char * Plates, int src, float * lla):
  m_throttle(setThrottle(src))
  {
    strcpy(m_plates, Plates);
    setLongAt(lla);
    cout << "Car " << m_vin << ": Parametrized-ctor" << endl;
  }

  //copy constructor
  Car::Car (const Car& src):
    m_throttle(setThrottle(src.m_throttle))
  {
    strcpy(m_plates, src.m_plates);
    int i = 0;
    while (i < 3)
    {
      m_lla[i] = src.m_lla[i];
      i++;
    }

   cout << "Car " << m_vin << ": Copy-ctor" << endl;
  }

  //destructor
  Car::~Car ()
  {
    cout << "Car " << m_vin << ": Dtor" << endl;
  }

  //overloaded insertion operator
  ostream& operator<<(ostream& os, Car& src)
  {
    os << "Car: " << src.getVin();
    os << " Plates:" << src.getPlates();
    os << " Throttle:" << src.getThrottle();
    os << " LLA: @[";
    int i = 0;
    while(i < 2) {
      os << src.m_lla[i++] << ", ";
    }
    os << src.m_lla[i] << "]"<< endl;
    return os;
  }

// put contents of one car object into another
  Car& Car::operator=(const Car& srcCar)
  {
    strcpy(m_plates, srcCar.m_plates);
    setThrottle(srcCar.m_throttle);
    int i = 0;
    while (i < 3)
    {
      m_lla[i] = srcCar.m_lla[i];
      ++i;
    }
    cout << "Car " << m_vin << ": Assignment" << endl;
    return *this;
  }


//    Returns the plate
  char * Car::getPlates ()
  {
    return m_plates;
  }

  //get method for m_throttle
  int Car::getThrottle () const
  {
    return m_throttle;
  }

  bool Car::setPlates (const char * srcPlates)
  {
    if(!srcPlates)
      return false;
    strcpy(m_plates, srcPlates);
    return true;
  }

  int Car::setThrottle (const int srcThrottle)
  {
    if(srcThrottle < 0)
      return 0;
    m_throttle = srcThrottle;
    return m_throttle;
  }
  // set throttle speed
  bool Car::Drive (int throttle)
  {
    if(throttle > 0)
      m_throttle = throttle;
    else
      return false;
    return true;
  }

  //move method, takes a new longitude-latitude address for the car to travel
  void Car::Move(float * srcLLA)
  {
    cout << "Driving Car: " << m_vin << " from  [";

    int i = 0;
    while(i < 2)
      cout << m_lla[i++] << ", ";
    cout << m_lla[i] << "]";
    cout << " to  [";

    i = 0;
    while(i < 3)
    {
      m_lla[i] = srcLLA[i];
      ++i;
    }

    i = 0;
    while(i < 2)
      cout << m_lla[i++] << ", ";
    cout << m_lla[i] << "]"<< endl;
    Drive(75);
    cout << "Car is driving: " << m_throttle << " mph." << endl;
  }
