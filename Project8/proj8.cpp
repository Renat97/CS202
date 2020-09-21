//
//  proj8.cpp
//  Project8
//
//  Created by Renat Norderhaug on 10/19/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//


#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"
#include "ArrayList.cpp"
#include "DataType.h"
#include "NodeList.cpp"
#include "DataType.cpp"

using namespace std;

int main(){

    //(1)
    ArrayList ms_default;
    cout << ms_default << endl;
    NodeList nl_default;
    cout << nl_default << endl;
    //(2)
    DataType def_value1(3000, 250.0);
    DataType def_value2(300, 25.0);
    ArrayList ms_parameterized(5, def_value1);
    cout << ms_parameterized << endl;
    NodeList nl_parameterized(5, def_value2);
    cout << nl_parameterized << endl;
    //(3)
    ArrayList ms_copy(ms_parameterized);
    cout << ms_copy << endl;
    NodeList nl_copy(nl_parameterized);
    cout << nl_copy << endl;
    //(4)
    DataType null_value(0, 0.0);
    ArrayList* ms_Pt = new ArrayList(5, null_value);
    NodeList* nl_Pt = new NodeList(5, null_value);
    delete ms_Pt;
    ms_Pt = NULL;
    delete nl_Pt;
    nl_Pt = NULL;
    //(5),(6)
    DataType assign_value(840, 60.0), access_value(30, 10.0), in_value(120, 25.0);
    ArrayList ms_assign(6, in_value);
    ms_assign = ArrayList(6, assign_value);
    cout << ms_assign << endl;
    ArrayList ms_access(6, access_value);
    cout << ms_access << endl;

    NodeList nl_assign(6, in_value);
    nl_assign = NodeList(6, assign_value);
    cout << nl_assign << endl;
    NodeList nl_access(6, access_value);
    cout << nl_access << endl;
    //(7),(8)
    ArrayList ms_first_element(ms_assign), ms_last_element(ms_assign);
    DataType* print_first = ms_first_element.First();
    cout << *print_first << endl;
    DataType* print_last = ms_last_element.Last();
    cout << *print_last << endl;

    NodeList nl_first_element(nl_assign), nl_last_element(nl_assign);
    Node* print_fnode = nl_first_element.First();
    if (print_fnode != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    Node* print_lnode = nl_last_element.Last();
    if (print_lnode != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    //(9)
    DataType* prev_data = NULL;
    DataType* find_data = ms_access.Find(access_value, prev_data);
    cout << *find_data << endl;
    Node* prev_node = NULL;
    Node* find_node = nl_access.Find(access_value, prev_node);
    if (find_node != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    //(10),(11)
    DataType* ins_after = ms_assign.InsertAfter(assign_value, in_value);
    cout << *ins_after << endl;
    DataType* ins_before = ms_assign.InsertBefore(assign_value, in_value);
    cout << *ins_before << endl;

    Node* in_after = nl_assign.InsertAfter(assign_value, in_value);
    if (in_after != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    Node* in_before = nl_assign.InsertBefore(assign_value, in_value);
    if (in_before != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    //(12),(13)
    DataType* rem_back = ms_assign.Erase(assign_value);
    cout << *rem_back << endl;

    cout << "test1" << endl;
    Node* rem_fnode = nl_assign.Erase(assign_value);
    cout << "test2" << endl;
    if (rem_fnode != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    Node* rem_bnode = nl_assign.Erase(assign_value);
    if (rem_bnode != NULL)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    //(14)
    cout << ms_assign[2] << endl;
    cout << ms_access[2] << endl;
    cout << nl_assign[2] << endl;
    cout << nl_access[2] << endl;
    //(15)
    ArrayList ms_size(10, assign_value);
    cout << ms_size.size() << endl;
    NodeList nl_size(8, assign_value);
    cout << nl_size.size() << endl;
    //(16),(17)
    ms_access.clear();
    cout << boolalpha << ms_access.empty() << endl;

    nl_access.clear();
    cout << boolalpha << nl_access.empty() << endl;

    ms_assign.clear();
    nl_assign.clear();
    ms_parameterized.clear();
    nl_parameterized.clear();
    ms_copy.clear();
    nl_copy.clear();
    ms_first_element.clear();
    nl_first_element.clear();
    ms_last_element.clear();
    nl_last_element.clear();

    return 0;

}
