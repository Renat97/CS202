//
//  ArrayStack.h
//  Project10
//
//  Created by Renat Norderhaug on 11/30/17.
//  Copyright � 2017 Renat Norderhaug. All rights reserved.
//

// template for Stack of array's class
// same thing as NodeStack but different logic because we are dealing with nodes.
// comments would be the same as NodeStack, so didn't comment.

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include <ostream>
using namespace std;

template <class T> class ArrayStack;

const size_t MAX_STACKSIZE = 1000;

template <class T>
class ArrayStack{
    friend std::ostream& operator<<(std::ostream& os, //(i)
                                    const ArrayStack<T>& arrayStack);
public:
    ArrayStack(); //(1)
    ArrayStack(size_t count, const T& value); //(2)
    ArrayStack(const ArrayStack<T>& other); //(3)
    ~ArrayStack(); //(4)
    T& operator= (const ArrayStack<T>& rhs); //(5)
    T& top(); //(6a)
    const T& top() const; //(6b)
    void push(const T& value); //(7)
    void pop(); //(8)
    size_t size() const; //(9)
    bool empty() const; //(10)
    bool full() const; //(11)
    void clear(); //(12)
    void serialize(std::ostream& os) const; //(13)
private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
};

template <class T>
ArrayStack<T>::ArrayStack() {
   m_top=-1;
}

template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T& value) {
      if (count > (MAX_STACKSIZE -1))
        return;
      m_top = -1;
      for (int index = 0; index < count; index++) {
        m_top++;
        m_container[index] = value;
      }
}

template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack& other) {
    for(int i = 0; i < size(); i++)
    {
        m_container[i] = other.m_container[i];
    }

}
template <class T>
ArrayStack<T>::~ArrayStack() {
  //  delete[] m_container;
}

template <class T>
T& ArrayStack<T>::operator=(const ArrayStack& rhs) {
  // if(this == *rhs) return;
  for(int i = 0; i < size(); i++)
    {
        m_container[i] = rhs.m_container[i];
    }
}

template <class T>
T& ArrayStack<T>::top() {
    return m_container[m_top];
}

template <class T>
const T& ArrayStack<T>::top() const {
    return m_container[m_top];
}

template <class T>
void ArrayStack<T>::push(const T& value) {
    m_top++;
    m_container[m_top]=value;
}

template <class T>
void ArrayStack<T>::pop() {
   if (!empty()) {
      m_top = m_top--;
   }

}
template <class T>
size_t ArrayStack<T>::size() const {
  return m_top+1;
}
template <class T>
bool ArrayStack<T>::empty() const {
  return (m_top == -1);
}

template <class T>
bool ArrayStack<T>::full() const {
  return m_top>=MAX_STACKSIZE;
}

template <class T>
void ArrayStack<T>::clear()  {
 //  delete[] m_container;
   m_top = -1;
}

template <class T>
void ArrayStack<T>::serialize(ostream& os) const {

    for(int i = 0; i < size(); i++)
    {
        os<<m_container[i]<<" ";
    }
    os << endl;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const  ArrayStack<T>& arrayStack)
{
    for(int i = 0; i < arrayStack.size(); i++)
    {
        os<<arrayStack.m_container[i]<<" ";
    }
        os << endl;
    return os;
}

#endif /* ArrayStack_hpp */

