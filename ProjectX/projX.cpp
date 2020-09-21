//
//  projX.cpp
//  Project11
//
//  Created by Renat Norderhaug on 12/12/17.
//  Copyright � 2017 Renat Norderhaug. All rights reserved.
//


#include <iostream>

#include "SmartPtr.h"
#include "DataType.h"
#include "DataType.cpp"
#include "SmartPtr.cpp"

using namespace std;

// code given to us in class for the main.cpp
int main(){

  cout << endl << "Testing SmartPtr Default ctor" << endl;
  SmartPtr sp1;  // Default-ctor
  sp1->SetIntVal(1);
  sp1->SetDoubleVal(0.25);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;

  cout << endl << "Testing SmartPtr Copy ctor" << endl;
  SmartPtr sp2 = sp1;  // Copy-initalization (Copy-ctor)
  sp2->SetIntVal(2);
  sp2->SetDoubleVal(0.5);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
  cout << "Dereference Smart Pointer 2: " << *sp2 << endl;

  cout << endl << "Testing SmartPtr Assignment operator" << endl;
  SmartPtr sp3;
  sp3 = sp1;  // Assignment operator tested
  sp3->SetIntVal(4);
  sp3->SetDoubleVal(0.0);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
  cout << "Dereference Smart Pointer 2: " << *sp2 << endl;
  cout << "Dereference Smart Pointer 3: " << *sp3 << endl;

  cout << endl << "Testing SmartPtr Parametrized ctor with NULL data" << endl;
  SmartPtr spNull( NULL );  // NULL-data initialization

  cout << endl << "Testing SmartPtr Copy ctor with NULL data SmartPtr" << endl;
  SmartPtr spNull_cpy( spNull );  // NULL-data copy constructor

  cout << endl << "Testing SmartPtr Assignment operator with NULL data SmartPtr" << endl;
  SmartPtr spNull_assign;
  spNull_assign = spNull;  // NULL-data assign

  cout << endl << "End-of-Scope, Destructors called in reverse order of SmartPtr object creation,\n(spNull_assign, spNull_cpy, spNull, sp3, sp2, sp1): " << endl;
}
