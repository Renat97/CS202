//
//  Vehicle.h
//  Project5
//
//  Created by Renat Norderhaug on 9/29/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#ifndef Vehicle_H
#define Vehicle_H

#include <iostream>
#include <fstream>


const float LLA = 0.0;

using namespace std;
class Vehicle {

  private:
  static int s_idgen;

  protected:
  // float m_lla[3]; // longitude - latitude, altitude
  const int m_vin; // unique Vehicle identification number

  public:
  float m_lla[3]; // longitude - latitude, altitude
  Vehicle();
  Vehicle(int vin, float* lla);

  Vehicle(const Vehicle& vehicle);

  ~Vehicle();

  friend ostream& operator <<(ostream& os, const Vehicle& src);

  Vehicle& operator= (const Vehicle& src);
  // return the vehicle vin
  int getVin () const;

  float * getLLA ();

  static int getIdgen();

  bool setLongAt(float* src);

  void Move(float * LLa);

  static int setVin(int vin);

};

#endif
// Vehicle_h
