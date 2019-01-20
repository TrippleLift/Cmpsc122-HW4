//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   LL.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ticketOrder.h"
using namespace std;

// Node class
class Node {
public:
	ticketOrder data;
	Node* next;
	Node() { next = NULL; }
	Node(ticketOrder u) { data = u; }
	void SetData(ticketOrder aData) { data = aData; }
	void SetNext(Node* aNext) { next = aNext; }
	ticketOrder getData() { return data; }
	Node* getNext() { return next; }
		
};

// List class
class List {

public:
	Node *head;
	List() { head = NULL; }
	~List() {
		//cout << "Inside destructor" << endl;
		deletehead();
	}
	//get head
	Node* getHead() { return head; }
	void deletehead() {

		head = NULL;
	}
	//get specific node
	Node* getNode(ticketOrder d);
	void Print();
	void Append(ticketOrder data); //add at the end of the list
	void Delete(ticketOrder data); //delete a specific node
	bool isempty();
	void insert(Node *, ticketOrder d); //insert node after prev, with data d
	int search(Node *);
	
	//sum of tickets
	int sum_of_tickets();

	//true if someone has more than 4 tickets
	bool checkIfMore_than_four_tickets();

	//true if there is a name repeat
	bool checkIfName_repeat();
};

#endif