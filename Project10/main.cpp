//
//  main.cpp
//  Project10
//
//  Created by Renat Norderhaug on 11/30/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

int main() {
    NodeStack<int> nStack; //1
    NodeStack<int> nStack1(4,6); //2
    cout <<"Node Stack's values: " << endl;
    nStack1.serialize(cout);
    NodeStack<int> nStack2(nStack1); //(3)
    cout << "Node Stack 2's values: " << endl;
    nStack2.serialize(cout);
    nStack=nStack2; //(5)
    cout << "Checking the assignment operator: " << endl;
    nStack.serialize(cout);
    cout << "Adding new Nodes and printing out " << endl;
    nStack.push(7);
    nStack.push(8);
    nStack.push(9);
    nStack.push(10);
    nStack.serialize(cout);

    cout<< "top: " << nStack.top()<< endl; //(6a)
    cout<< "size: " << nStack.size()<< endl; //(6a)
    cout<< "empty: " << nStack.empty()<< endl; //(6a)
    cout<< "full: " << nStack.full()<< endl; //(6a)
    nStack.pop();
    nStack.pop();
    nStack.pop();
    nStack.pop();
     cout << "After popping four times seeing new nodeStack's values" << endl;
    nStack.serialize(cout);

    // Making an Array Stack
    ArrayStack<int> aStack; //1
    ArrayStack<int> aStack1(4,6); //2
    cout <<"Array Stack's values: " << endl;
    aStack1.serialize(cout);
    ArrayStack<int> aStack2(aStack1); //(3)
    cout << "Array Stack 2's values: " << endl;
    aStack2.serialize(cout);

return 0;

}
