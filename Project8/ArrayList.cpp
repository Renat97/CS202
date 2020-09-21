//
//  ArrayList.cpp
//  Project8
//
//  Created by Renat Norderhaug on 10/19/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//


#include <stdio.h>
#include <cstdlib>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList()
{

    m_maxsize = 0;
    m_size = 0;
    m_array = NULL;
}

ArrayList::ArrayList(size_t count, const DataType& value)
{
   m_maxsize = count;
   m_array = new DataType[count]; //initialize empty array with max size = count
   m_size = count; // set m_size to count
   for (int i=0; i<m_size; i++)
   {
      m_array[i] = value;   // Initialize all elements to value.
   }
}

ArrayList::ArrayList(const ArrayList& other)
{
   m_maxsize = other.m_maxsize;
   m_array = new DataType[other.m_maxsize];
   m_size = other.m_size;
   for (int i=0; i<m_size; i++)
   {
      m_array[i] = other.m_array[i];
   }
}

ArrayList::~ArrayList()
{

    delete [] m_array;
}

ArrayList& ArrayList::operator= (const ArrayList& rhs)
{

    if(this == &rhs)
    {
       return *this;
    }

    delete[] m_array;
    m_array = new DataType[rhs.m_maxsize];
    m_size = rhs.m_size;
    for (int i=0; i<m_size; i++)
    {
        m_array[i] = rhs.m_array[i];
    }
    return *this;

}

bool ArrayList::empty() const
{
    return m_size == 0;
}

size_t ArrayList::size() const
{
    return m_size;
}

void ArrayList::clear( )
{
    delete [] m_array;
    m_size = 0;
    m_maxsize = 0;
    m_array = NULL;
}

DataType* ArrayList::First()
{
    return &m_array[0];
}

DataType* ArrayList::Last()
{
   if(m_size>0)
       return &m_array[m_size - 1];
    else
       return NULL;
}

DataType* ArrayList::Find(const DataType & target, DataType * & previous, const DataType * start)
{
   DataType *result = NULL;
   int strt_idx = -1;

    previous = NULL;

    //find start
    if(start)
    {
       for( int i = 0;  i < m_size; i++ )
       {
          if(m_array[i] == *start)
          {
             strt_idx = i;
             break;
          }
       }
    }

    for( int i = strt_idx + 1; i < m_size; i++ )
    {
       if(m_array[i] == target)
       {
          result = &m_array[i];
          if(i > 0)
            previous = &m_array[i - 1];

         break;
      }
    }
    return result;
}

DataType*  ArrayList::InsertAfter(const DataType& target,
                                  const DataType& value)
{
   int target_idx = -1;

   for( int i = 0; i < m_size; i++ )
    {
       if(m_array[i] == target)
       {
          target_idx = i;
         break;
      }
    }
    if(target_idx<0) //target not found
       return NULL;

    if(m_size>=m_maxsize) //resize
    {
       this->resize(m_maxsize + 1);
    }

    for( int i = m_size; i > target_idx; i-- ) //shift right
    {
       m_array[i+1] = m_array[i];
    }
    //insert
    m_array[target_idx+1] = value;
    m_size++;

    return &m_array[target_idx+1];
}

DataType*  ArrayList::InsertBefore(const DataType& target,
                                   const DataType& value)
{
   int target_idx = -1;

   for( int i = 0; i < m_size; i++ )
    {
       if(m_array[i] == target)
       {
          target_idx = i;
         break;
      }
    }
    if(target_idx<0) //target not found
       return NULL;

    if(m_size>=m_maxsize) //resize
    {
       this->resize(m_maxsize + 1);
    }

    for( int i = m_size; i >= target_idx; i-- ) //shift right
    {
       m_array[i+1] = m_array[i];
    }
    //insert
    m_array[target_idx] = value;
    m_size++;

    return &m_array[target_idx];

}
DataType*  ArrayList::Erase(const DataType& target)
{
   int target_idx = -1;

   for( int i = 0; i < m_size; i++ )
    {
       if(m_array[i] == target)
       {
          target_idx = i;
         break;
      }
    }
    if(target_idx<0) //target not found
       return NULL;

   for( int i = target_idx+1; i < m_size; i++ ) //shift left
    {
       m_array[i-1] = m_array[i];
    }
    m_array[m_size-1] = DataType();

    m_size--;
}


DataType&  ArrayList::operator[] (size_t position)
{
   if(position < m_size)
      return m_array[position];
   else
      throw "Out of bounds";
}

void ArrayList::resize(size_t count)
{
   if(m_maxsize == count)
      return;

   DataType *new_array = new DataType[count];
   int cnt = (count > m_size ? count: m_size);

   for(int i = 0; i < cnt; i++ ) //copy
    {
       new_array[i] = m_array[i];
    }

    delete [] m_array;
    m_array = new_array;
    m_maxsize = count;

    return;
}

std::ostream& operator<<(std::ostream& os, const ArrayList& arrayList)

{
    for (int i = 0; i < arrayList.m_size; i++)
    {
        os << arrayList.m_array[i] << " ";
    }
    return os;
}


