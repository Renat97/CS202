//
//  main.cpp
//  Project9+
//
//  Created by Renat Norderhaug on 11/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include <iostream>
#include "ArrayQueue.h"
#include "NodeQueue.h"
#include "DataType.h"
#include "ArrayQueue.cpp"
#include "NodeQueue.cpp"
#include "DataType.cpp"
#include <stdio.h>
using namespace std;

int main() {
    //1
    ArrayQueue defaultQueue;
    cout << "ArrayQueue default constructor: " << defaultQueue << endl;
    //2
    DataType def_value1(3000, 250.0);
    ArrayQueue ms_parameterized(5, def_value1);
    cout << "ArrayQueue parametrized constructor: " << ms_parameterized << endl;
    //3
    ArrayQueue copyQueue(ms_parameterized);
    cout << "ArrayQueue copy constructor: " << copyQueue << endl;
    //4
    DataType null_value(0, 0.0);
    ArrayQueue* ms_Pt = new ArrayQueue(5, null_value);
    delete ms_Pt;
    ms_Pt = NULL;
    //5
    DataType assign_value(840, 60.0), in_value(120, 25.0);
    ArrayQueue ms_assign(6, in_value);
    ms_assign = ArrayQueue(6, assign_value);
    cout << "ArrayQueue assign value: " << ms_assign << endl;
    //6
    cout << "ArrayQueue front" <<ms_assign.front() << endl;
    //7
     cout << "ArrayQueue back" <<ms_assign.back() << endl;
    //8
    ms_assign.push(in_value);
    cout << "ArrayQueue push" <<ms_assign << endl;
    //9
    ms_assign.pop();
    cout << "ArrayQueue pop once" <<ms_assign << endl;
    ms_assign.pop();
    cout << "ArrayQueue pop twice" <<ms_assign << endl;
    //10
    cout << "ArrayQueue size: " << ms_assign.size() << endl;
    //11
    cout << "ArrayQueue empty: " <<ms_assign.empty() << endl;
    //12
    cout << "ArrayQueue full: " <<ms_assign.full() << endl;
    //14
    ms_assign.serialize(cout);
    //13
    ms_assign.clear();
    cout << "ArrayQueue after clear: " <<ms_assign << endl;

    NodeQueue nodeDefaultQueue;
    cout << "NodeQueue default constructor: " << nodeDefaultQueue << endl;
    //2
    DataType def_value2(3000, 250.0);
    NodeQueue parameterized(5, def_value2);
    cout << "NodeQueue parametrized constructor: " << parameterized << endl;
    //3
    NodeQueue copyNodeQueue(parameterized);
    cout << "NodeQueue copy constructor: " << copyNodeQueue << endl;
    //4
    DataType null_value1(0, 0.0);
    NodeQueue* nq_Pt = new NodeQueue(5, null_value1);
    delete nq_Pt;
    nq_Pt = NULL;
    //5
    DataType assign_value1(840, 60.0), in_value1(120, 25.0);
    NodeQueue nq_assign(6, in_value1);
    nq_assign = NodeQueue(6, assign_value1);
    cout << "NodeQueue assign value: " << nq_assign << endl;
    //6
    cout << "NodeQueue front" <<nq_assign.front() << endl;
    //7
     cout << "NodeQueue back" <<nq_assign.back() << endl;
    //8
    nq_assign.push(in_value);
    cout << "NodeQueue push" <<nq_assign << endl;
    //9
    nq_assign.pop();
    cout << "NodeQueue pop once" <<nq_assign << endl;
    nq_assign.pop();
    cout << "NodeQueue pop twice" <<nq_assign << endl;
    //10
    cout << "NodeQueue size: " << nq_assign.size() << endl;
    //12
    cout << "NodeQueue full: " <<nq_assign.full() << endl;
    //14
    nq_assign.serialize(cout);
    //13
    nq_assign.clear();
    cout << "NodeQueue after clear: " << nq_assign << endl;

    return 0;
}
