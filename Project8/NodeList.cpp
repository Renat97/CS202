//
//  NodeList.cpp
//  Project8
//
//  Created by Renat Norderhaug on 10/19/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include "NodeList.h"
#include <cstdlib>
using namespace std;

NodeList::NodeList() {
    m_head = NULL;
}

NodeList:: NodeList(size_t count, const DataType& value) {
	Node *current = NULL;
    for(int i = 0; i < count; i++) {
    	Node *next = new Node(value);
			// adds node to the next after current if not null
    	if(current != NULL) {
    		current->m_next = next;
    	} else {
    		m_head = next;
    	}
    	current = next;
    }
}

NodeList:: NodeList(const NodeList& other) {
    m_head = other.m_head;
}

NodeList:: ~NodeList() {
		delete m_head;
}

NodeList& NodeList::operator= (const NodeList& other_nodeList)

{
    Node* temp1 = m_head;
    Node* temp2 = other_nodeList.m_head;
    if (this->size() < other_nodeList.size())
    {
        clear();
        DataType data0(0, 0.0);
        NodeList new1(other_nodeList.size(), data0);
        temp1 = new1.m_head;
    }
    while (temp2->m_next != NULL)
    {
        temp1->m_data = temp2->GetData();
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
    }
    return *this;
}

Node* NodeList:: First() {
    return m_head;
}

Node* NodeList:: Last() {
	Node *current = m_head;
    while(current->m_next != NULL) {
    	current = current->m_next;
    }
    return current;
}

Node* NodeList::Find(const DataType & target,Node * & previous, const Node * start) {
    bool startFound = start == NULL;
    Node *result = NULL;
    for(Node *current = m_head; current != NULL; current = current->m_next) {
    	if(!startFound) {
    		startFound = current == start;
    	}
    	if(!startFound) {
    		continue;
    	}
    	if(current->m_data == target) {
    		result = current;
    		break;
    	}
    	previous = current;
    }
    return result;
}

Node* NodeList::InsertAfter(const DataType& target, const DataType& value) {
	Node* previous = NULL;
	Node *result = Find(target, previous);
	Node *nodeToInsert = NULL;
	if(result != NULL) {
		nodeToInsert = new Node(value, result->m_next);
		result->m_next = nodeToInsert;
	}
	return nodeToInsert;
}

Node* NodeList:: InsertBefore(const DataType& target, const DataType& value) {
	Node* previous = NULL;
	Node *result = Find(target, previous);
	Node *nodeToInsert = NULL;
	if(result != NULL) {
		nodeToInsert = new Node(value, result);
		if(previous != NULL) {
			previous->m_next = nodeToInsert;
		}
	}
	return nodeToInsert;
}

Node* NodeList:: Erase(const DataType& target) {
	Node* previous = NULL;
	Node *result = Find(target, previous);
	if(result != NULL) {
		if(previous != NULL) {
			previous->m_next = result->m_next;
		}
		delete result;
	}
	return result;
}

DataType& NodeList:: operator[] (size_t position)  {

    Node* current = m_head;
    for (int i = 0; i < position; i++)
    {
        current = current->m_next;
    }
    return current->GetData();
}

const DataType& NodeList::operator[] (size_t position) const

{
    Node* current = m_head;
    for (int i = 0; i < position; i++)
    {
        current = current->m_next;
    }
    return current->GetData();
}

size_t NodeList:: size() const {
	int size = 0;
	for(Node *current = m_head; current != NULL; current = current->m_next) {
		size++;
	}
	return size;
}

bool NodeList:: empty() const {
    return size() == 0;
}

void NodeList:: clear() {
	for(Node *current = m_head; current != NULL; ) {
		Node *toDelete = current;
		current = current->m_next;
		delete toDelete;
	}
	m_head = NULL;
}

std::ostream& operator<<(std::ostream& os, const NodeList& nodeList)
{
    for (int i = 0; i < nodeList.size(); i++)
    {
        os << nodeList[i] << " ";
    }
    return os;
}
