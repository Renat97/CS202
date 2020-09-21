//
//  SmartPtr.cpp
//  Project11
//
//  Created by Renat Norderhaug on 12/12/17.
//  Copyright � 2017 Renat Norderhaug. All rights reserved.
//

#include "SmartPtr.h"

#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;

// Default constructor which dynamically allocates a new DataType object, the pointer keeps track of the address. size_t vavriable is set to the value 1.
SmartPtr::SmartPtr()
{
  // m_ptr points to the dynamically allocated data
   m_ptr = new DataType;
   // how many smart pointer objects point to the same dynamic memory.
   // uses the new keyword to make a size_t pointer
   m_refcount = new size_t(1);
   cout << "SmartPtr Defult ctor" << "count is " << *m_refcount << endl;
}
// if object is the last object then deallocation will happen.
// decrement value pointed by m_refcount says one less SmartPtr is pointing to the object. So it makes sure
// that the refcount value is 0.
SmartPtr::~SmartPtr()
{
  // check to make sure last one is last one referencing to memory.
  if(*m_refcount > 0) {
    --(*m_refcount);
  } else {
    delete m_refcount;
    delete m_ptr;
  }
}
// takes in already pre-allocated data, and wraps itself around that raw pointer
SmartPtr::SmartPtr( DataType * data )
{
  m_ptr = data; // assign pointer here
  m_refcount = new size_t; // part b
  if(m_ptr)
  {
    *m_refcount = 1;
  }
  else
  {
    cout <<" Null pointer " << endl;
    *m_refcount = 0;
  }
}
// copy constructor for the smart pointer, takes another smartPtr as reference
SmartPtr:: SmartPtr(const SmartPtr& other)
{
  // if there exists another ptr
  if(other.m_ptr)
  {
    m_ptr = other.m_ptr; //(a) //to keep track of data directly
    m_refcount = other.m_refcount;
    (*m_refcount)++;
  }
  else
  {
    m_refcount = new size_t (0); // null ptr was passed
  }
  cout << "Copy Ctor worked! ref count is " << *m_refcount << endl; //(c)
}

SmartPtr& SmartPtr::operator=( const SmartPtr& rhs ) {
// if the methods this is already the parameter, just return the parameter
  if(this == &rhs) {
    return *this;
  }

  // else
  //{
  if(*m_refcount > 0) {
    --(*m_refcount); //(a)
  }
    //if the object is the last one, deallocation will happen
  else if(*m_refcount == 0)
    {
      cout << *m_refcount << endl;
      delete m_refcount;
      delete m_ptr;
    }

    if(!rhs.m_ptr)
    {
      cout << "null ptr passed" << endl;
      // set to 0
      m_refcount = new size_t (0);
    }
    else
    {
      // add ref count for new pointer assigned
      m_ptr = rhs.m_ptr;
      m_refcount = rhs.m_refcount;
      ++(*m_refcount);
    }
    cout << "SmartPtr Assigned with refCount of " << *m_refcount << endl;
  //}
  return *this;


  }
// both these methods deference the dynamic memory object encapsulated in SmartPtr
DataType& SmartPtr::operator*()
{
    return *m_ptr;
}

DataType* SmartPtr::operator->()
{
    return m_ptr;
}
