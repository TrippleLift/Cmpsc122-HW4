//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   LL.cpp

#include"LL.h"
#include <vector>

//print list
void List::Print() {

	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl << endl;
		temp = temp->next;
	}
	cout << endl;
}

//append at the end of the list
void List::Append(ticketOrder d) {
	Node *nnode = new Node();
	nnode->data = d;
	nnode->next = NULL;

	//if this is the head
	if (head == NULL) {
		head = nnode;
	}
	else  //not the head
	{
		Node *prev = head;
		Node *temp = prev->next;

		while (temp != NULL)
		{
			prev = temp; //order is very important
			temp = temp->next;


		}
		//now insert node
		prev->next = nnode;

	}
}
//delete data d(first d found will be deleted)
void List::Delete(ticketOrder d) {

	Node *prev = head;
	Node *temp = prev->next;
	//if the deleted node is the head
	if (prev->data == d) {
		delete head;
		head = temp;
	}
	else
	{
		while ((temp != NULL) && (temp->data != d)) {

			prev = temp;
			temp = temp->next;

		}
		if (temp != NULL)
		{ //make sure the node was found
			prev->next = temp->next;
			delete temp;

		}
		else
			cout << "Can't find the value to delete. List didn't change." << endl;
	}

}


//test if list is empty
bool List::isempty() {
	if (head == NULL) return true;
	else return false;
}

//insert after prev, data d
void List::insert(Node *prev, ticketOrder d) {
	Node *temp = head;
	Node *ne = new Node;
	ne->data = d;
	if (temp == NULL) {
		cout << "previous is null, exiting" << endl;
		exit(1);
	}
	else
		while (temp->data != prev->data) {

			temp = temp->next;
		}
	temp = temp->next;
	ne->next = temp;
	prev->next = ne;

}

//Search for a node and return the position where it was found
//or -1 if it wasn't found
int List::search(Node *n)
{
	Node *temp = head;
	int i = 0;
	if (n != NULL) {
		if (isempty()) {
			cout << "Empty list, Not found" << endl;
			return -1;
		}
		else
		{
			while (temp != NULL) {
				if (temp->data == n->data)
					return i;
				temp = temp->next;
				i = i + 1;
			}

		}
		if (temp == NULL)
			return -1;
		else
			return i;
	}
	else
		cout << "Searching for non-existent node, exiting now....." << endl;
	return -1;
}

//Return the node if it exists. 
Node* List::getNode(ticketOrder d) {
	Node *temp = head;
	if (head == NULL) {
		cout << "Empty list, exiting"; return NULL;
	}
	else
	{
		while (temp != NULL&&temp->data != d)
			temp = temp->next;
	}
	if (temp == NULL) {
		cout << "Trying to get a node that does not exist. Exiting" << endl; return NULL;
	}
	else
		return temp;
}

int List::sum_of_tickets()
{
	if (head == NULL)
		return 0;
	else
		return head->data.getSumOfTickets();
}

bool List::checkIfMore_than_four_tickets()
{
	Node *temp = head;
	bool status = false;
	if (head == NULL) {
		cout << "Empty list, exiting"; return false;
	}
	else
	{
		while (temp != NULL)
		{
			if ((temp->data.getNumber_of_tickets()) > 4)
			{
				cout << temp->data.getName() << " has " << temp->data.getNumber_of_tickets()
					<< " tickets.\nEnter the number of tickets again: ";
				cin.ignore();
				int tickets;
				cin >> tickets;
				while (tickets > 4)
				{
					cout << temp->data.getName() << " has " << tickets
						<< " tickets.\nEnter the number of tickets again: ";
					cin >> tickets;
				}
				temp->data.setNumber_of_tickets(tickets);
				status = true;
			}
			temp = temp->next;
		}

	}
	return status;
}


bool List::checkIfName_repeat()
{
	Node *temp = head;
	Node *prev = head;
	bool status = false;

	if (head == NULL) 
	{
		cout << "Empty list, exiting"; return false;
	}
	else
	{
		for (Node *tempHead = head; tempHead->next != NULL; tempHead = tempHead->next)
		{
			temp = tempHead;
			while (temp->next != NULL)
			{
				prev = temp;
				temp = temp->next;
				if (tempHead->data.getName() == temp->data.getName())
				{
					status = true;
					//delete temp Node
					prev->next = temp->next;
					delete temp;
					temp = prev;
					cout << temp->data.getName() << " has ordered more than once.\n";
					cout << "Cancell order:\n";
					temp->data.Print();
					cout << endl;
				}		
			}
		}
	}
	return status;
}