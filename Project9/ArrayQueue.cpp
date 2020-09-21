//
//  ArrayQueue.cpp
//  Project9+
//
//  Created by Renat Norderhaug on 11/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include "ArrayQueue.h"
#include <cstdlib>
#include <cstring>

using namespace std;

ArrayQueue::ArrayQueue() // default constructor
{
    m_array[ARRAY_MAX];
    m_front = 0;
    m_back= 0;
    m_size =0;
}
ArrayQueue:: ArrayQueue(size_t count, const DataType& value) {
    for(int i = 0; i < count; i++) {
        m_array[i].SetIntVal(value.GetIntVal());
        m_array[i].SetDoubleVal(value.GetDoubleVal());
    }
    m_front = count - 1;
    m_back = 0;
    m_size = count;
}
ArrayQueue:: ArrayQueue(const ArrayQueue& other) {
    m_front = other.m_front;
    m_back= other.m_back;
    m_size = other.m_size;
    memcpy(m_array, other.m_array, sizeof(DataType) * m_size);
}
ArrayQueue:: ~ArrayQueue() {
    //delete [] &m_array;
}
ArrayQueue& ArrayQueue::operator= (const ArrayQueue& rhs)
{

    if (this == &rhs) return *this;
    if(!empty()) clear();
    m_array[ARRAY_MAX];
    m_size = rhs.m_size;
    memcpy(m_array, rhs.m_array, sizeof(DataType) * m_size);
    return *this;
}
DataType& ArrayQueue:: front() {
    return m_array[m_size-1];
}
const DataType& ArrayQueue:: front() const {
    return m_array[m_size -1];
}

DataType& ArrayQueue:: back() {
    return m_array[0];
}

const DataType& ArrayQueue:: back() const {
    return m_array[0];
}
void ArrayQueue:: push(const DataType& value) {
    if(full()) {
        return;
    }
    m_size = m_size+1;
        for (int i = 0; i < m_size; i++)
        {
            m_array[i+1] = m_array[i];
        }
    m_array[0] = value;
    m_front = m_front+1;
}

void ArrayQueue:: pop() {
    if(empty()) {
        return;
    }
    m_size = m_size-1;
    m_front = m_front-1;

}
size_t ArrayQueue:: size() const {
    return m_size;
}
bool ArrayQueue:: empty() const {
    return m_size == 0;
}
bool ArrayQueue:: full() const {
    return m_size == ARRAY_MAX;
}
void ArrayQueue:: clear() {
    m_array[ARRAY_MAX];
    m_front = 0;
    m_back = 0;
    m_size = 0;
}
void ArrayQueue:: serialize(std::ostream& os) const {
    for (int i = 0; i < m_size; i++)
    {
        os << m_array[i] << " ";
    }

}

ostream& operator<<(std::ostream& os, const ArrayQueue& arrayQueue)
{
    for (int i = 0; i < arrayQueue.m_size; i++)
    {
        os << arrayQueue.m_array[i] << " ";
    }
    return os;
}

