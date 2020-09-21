//
//  Vehicle.cpp
//  Project5
//
//  Created by Renat Norderhaug on 9/29/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//
#include <iostream>
#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle(): m_vin(GetIdgen())
{
  cout < "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

Vehicle::Vehicle(int vin, float *lla) : m_vin(SetVin(vin)) {
  setLongLat(lla);
  cout < "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle& vehicle) {
  int i = 0;
  while (i < 3)
    {
      m_lla[i] = Vehicle.m_lla[i];
      i++;
    }
  m_vin = vehicle.m_vin;
  cout < "Vehicle #" << m_vin << ":Copy-ctor" << endl;
}

// destructor for the vehicle
Vehicle::~Vehicle() {
    cout << "Vehicle " << m_vin << ": Dtor" << endl;
}

int Vehicle::GetVin() const {
  return m_vin;
}

float * Vehicle::GetLLA() {
  return m_lla;
}

// static int random number generator
int Vehicle::GetIdgen () {
  s_idgen = ((rand(%1335)) + 1335);
  return s_idgen;
}

// Move shows that a vehicle cant be moved
void Vehicle::Move (float* source) {
  if(!source) {
    return;
  }
  cout << "Vehicle " << m_vin << "cannot move" << endl;
}
// each vehicle has a unique vin number
 int Vehicle::SetVin (int source)
  {
    if(!(source >= 1335 && source <= 4000))
    {
      cout << "cant assign this value, assigning for you." << endl;
      return GetIdgen();
    }
    else
      return source;
  }
  bool Vehicle::SetLongLat (float * src)
  {
    int i = 0;
    if(!src)
    {
      while(i < 3)
        m_lla[i++] = DFLT_LLA;
    }
    else
    {
      int i = 0;
      while(i < 3)
      {
        m_lla[i] = src[i];
        ++i;
      }
    }
    return true;
  }

  // operator overload for the insertion operator of ostream type
  ostream& operator<< (ostream& os, const Vehicle& src)
  {
    os << "Vehicle " << src.m_vin << " @[";
    int i = 0;
    while(i < 2) {
      os << src.m_lla[i++] << ", ";
    }
    os << src.m_lla[i] << "]"<< endl;
    return os;
  }
 // operator overload for the equal operator.
 // to set to vehicles equal.
 Vehicle& Vehicle::operator= (const Vehicle& src)
  {
    int i = 0;
    while(i < 3)
    {
      m_lla[i] = src.m_lla[i];
      ++i;
    }
    SetVin(srcV.m_vin);
   // returns the vehicle you are setting.
    return *this;
  }