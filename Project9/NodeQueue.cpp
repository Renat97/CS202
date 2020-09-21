//
//  NodeQueue.cpp
//  Project9+
//
//  Created by Renat Norderhaug on 11/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include "NodeQueue.h"
#include <cstdlib>
using namespace std;

NodeQueue::NodeQueue() // default constructor
{
    m_front=m_back=new Node();
} //(1)

NodeQueue::NodeQueue(size_t size, const DataType& value)
{
    Node *node = new Node(value, NULL);
    m_front= node;
    for(int i=0; i<size; i++)
    {
         node->m_next = new Node(value, NULL);
    }
    m_back=node;
} //(2) NodeQueue(const NodeQueue& other); //(3)

NodeQueue:: ~NodeQueue()
{
    Node *next;
    while (m_front)
        {
            next = m_front->m_next;
            m_front = new Node;
            delete [] m_front;
            m_front = next;
        }
    m_front=m_back=NULL;
}//(4)

NodeQueue& NodeQueue::operator= (const NodeQueue& rhs)
    {
        Node *temp=rhs.m_front;
        Node *node;

        m_front=new Node(temp->m_data,NULL);
        m_back=m_front;
        temp=temp->m_next;

        while(temp!=NULL)
        {
            node=m_back;
            m_back=new Node(temp->m_data,NULL);
            node->m_next=m_back;
            temp=temp->m_next;
        }
        return *this;
}//(5)

DataType& NodeQueue::front(){

       return m_front->m_data;
}//(6a)

const DataType& NodeQueue::front() const{

      return m_front->m_data;

} //(6b)

DataType& NodeQueue::back(){
      return m_back->m_data;
}//(7a)

const DataType& NodeQueue::back() const{
      return m_back->m_data;
}//(7b)

void NodeQueue::push(const DataType& value){
   Node *p = new Node();
   p->m_data = value;
   p->m_next = NULL;
   if (m_front)
      m_back->m_next = p; // queue not empty
   else
      m_front = p;        // queue empty
   m_back= p;
} //(8)

void NodeQueue::pop(){
    // we can only pop if front is not empty
   if( m_front!=NULL) {
       Node *p = m_front;
       m_front = m_front->m_next;
       delete p;
   }
} //(9)

size_t NodeQueue::size() const{
    int count=0;
    Node *t=m_front;
    while(t!=m_back)
    {
         count++;
         t=t->m_next;
    }
    count++;
    return count;
} //(10) bool empty() const; //(11)

bool NodeQueue::full() const{
    // per requirement always returns false
    return 0;
} //(12)

void NodeQueue::clear(){
    Node *next;
    while (m_front)
    {
      next = m_front->m_next;
      delete m_front;
      m_front = next;
    }
    m_front=m_back=new Node();
} //(13)

void NodeQueue::serialize(std::ostream& os) const{
    Node *t=m_front;
    os << t->m_data << endl;
    while(t!=m_back)
    {
         t=t->m_next;
         os <<t->m_data << endl;
    }
}

ostream& operator<<(std::ostream& os, const NodeQueue& nodeQueue)
{
    nodeQueue.serialize(os);
    return os;
}
