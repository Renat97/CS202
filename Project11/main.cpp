//
//  main.cpp
//  Project11+
//
//  Created by Renat Norderhaug on 12/11/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "VectorRecursion.h"


int main(){
    
    // Vector creation
    std::vector<int> vecInt;
    std::vector<int> vecIntCopy(vecInt);
    
    // Vector population with input values
    std::ifstream fin("RandomData.txt");
    while(fin){
        int fin_in;
        fin >> fin_in;
        if (!fin)
            break;
        vecInt.push_back( fin_in );
    }
    
    // Vector indexing and output ( using operator[] or at() )
    for (size_t i=0; i<vecInt.size(); ++i){
        std::cout << vecInt[i] << " same as " << vecInt.at(i) << std::endl;
    }
    
    // Vector indexing and output ( using iterator )
    for (std::vector<int>::iterator it=vecIntCopy.begin(); it!=vecIntCopy.end(); ++it){
        std::cout << *it << std::endl;
    }
    
    vector_resort(vecInt, 0, 100);
    
    for (size_t i=0; i<vecInt.size(); ++i){
        std::cout << " sorted " << vecInt.at(i) << std::endl;
    }
    
    std::cout << " searched " << vector_research(vecInt, 0 , 100, 108) << std::endl;
    
    return 0;
}


