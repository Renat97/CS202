#ifndef NODESTACK_H
#define NODESTACK_H

// template for Stack of Node's class

#include <iostream>
#include <stdio.h>

using namespace std;

template <class T> class NodeStack;

template <class T>
class Node{
    friend class NodeStack<T>;
    public:
        Node();
        Node(const T& data);
        T& GetData();
        const T& GetData() const;
        Node<T> * GetNext();
        void SetNext( Node<T> * next );
    private:
        Node<T>* m_next;
        T m_data;
};

// Node constructor

template <class T>
Node<T> ::Node()
{
    m_next = NULL;
}
// parameterized constructor
template <class T>
Node<T> ::Node( const T & data )
{
    m_data = data;
    m_next = NULL;
}
// return the data of a node
template <class T>
T & Node<T> ::GetData()
{
    return m_data;
}

template <class T>
const T & Node<T> ::GetData() const
{
    return m_data;
}
// return next node
template <class T>
Node<T> * Node<T> ::GetNext()
{
    return m_next;
}
// change who the next node is
template <class T>
void Node<T> ::SetNext( Node<T> * next )
{
    m_next = next;
}

template <class T>
class NodeStack
{
    friend std::ostream& operator<<(std::ostream& os, const NodeStack<T>& nodeStack); //i
    public:
        NodeStack(); //(1)
        NodeStack(size_t count, const T& value); //(2)
        NodeStack(const NodeStack<T>& other); //(3)
        ~NodeStack(); //(4)
        NodeStack& operator= (const NodeStack<T>& rhs); //(5)
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
        Node<T>* m_top;
};

template <class T>
NodeStack<T> ::NodeStack()
{
    m_top = NULL;
}
// copy constructor to make a new nodeStack
template <class T>
NodeStack<T> ::NodeStack(const NodeStack<T>& other)
{
    m_top = NULL;
    Node<T>* ptr, * newNode, * last = NULL;
        for (ptr = other.m_top; ptr != NULL; ptr = ptr->GetNext())
        {
            newNode = new Node<T>(ptr->GetData());
            if (last == NULL)
                m_top = newNode;
            else
                last->SetNext(newNode);

            last = newNode;
        }
 }
// destructor to delete a NodeStack
template <class T>
NodeStack<T> ::~NodeStack()
{
    Node<T> *next;
    while (m_top)
        {
            next = m_top->GetNext();
            delete m_top;
            m_top = next;
        }
    m_top=NULL;
}
// assignment operator to set one NodeStack equal to another.
template <class T>
NodeStack<T>& NodeStack<T>::operator = (const NodeStack<T>& other)
{
    if (this != &other)
    {
        Node<T>* ptr, * newNode, * last = NULL;
        for (ptr = other.m_top; ptr != NULL; ptr = ptr->GetNext())
        {
            newNode = new Node<T>(ptr->GetData());
            if (last == NULL)
                m_top = newNode;
            else
                last->SetNext(newNode);

            last = newNode;
        }
    }
    return *this;
}
// returns the top node of a stack of nodes
template <class T>
T& NodeStack<T>::top(){
   if(m_top!=NULL)
   {
      return m_top->GetData();
   }
    else
        return m_top->GetData();
}
// adds a new node in
template <class T>
void NodeStack<T> ::push(const T& value)
{

    Node<T> * newNode = new Node<T>(value);
    if(m_top == NULL)
    {
      newNode->SetNext(NULL);
      m_top = newNode;
    }
    else {
       newNode->SetNext(m_top);
       m_top = newNode;
    }
}
// removes node from the top
template <class T>
void NodeStack<T> ::pop()
{
    if(m_top == NULL)
       return;
    else
    {
        Node<T> * temp = m_top;
        m_top = temp->GetNext();
        delete temp;
    }
}

template <class T>
NodeStack<T> ::NodeStack(size_t count, const T& value)
{
    m_top= new Node<T>(value);
    Node<T> *currNode = m_top;
    for(int i=1; i< count; i++)
    {
         currNode->SetNext(new Node<T>(value));
         currNode = currNode->GetNext();
    }
}
// returns size of the stack
template <class T>
size_t NodeStack<T>::size() const {
    int count=0;
    Node<T> *t=m_top;
    while(t->GetNext()!=NULL)
    {
         count++;
         t=t->GetNext();
    }
    count++;
    return count;
} //(9)

template <class T>
bool NodeStack<T>::empty() const {
      return m_top==NULL;
} //(10)

template <class T>
bool NodeStack<T>::full() const{
    return 0;
} //(11)

template <class T>
void NodeStack<T>::clear(){
    Node<T> *next;
    while (m_top->m_next!=NULL)
    {
      next = m_top->m_next;
      delete m_top;
      m_top = next;
    }
}//(12)
// print out the values of the node stack
template <class T>
void NodeStack<T>::serialize(std::ostream& os) const{

    Node<T> *temp;
    temp = m_top;
    for (int i=0; i< size();i++)
    {
        os<<temp->GetData()<<" ";
        temp=temp->GetNext();
    }
    os << endl;
}
// overloaded the insertion operator
template <class T>
std::ostream& operator<<(std::ostream& os, const NodeStack<T>& nodeStack)
{
    Node<T> *temp;
    temp = nodeStack.m_top;
    while(temp!=NULL)
    {
        os<<temp->GetData()<<" ";
        temp=temp->GetNext();
    }
    os<<temp->GetData()<< endl;
    return os;
}

#endif // NODESTACK_H
