//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   ticketOrder.h

#ifndef TICKETORDER_H
#define TICKETORDER_H

#include "Address.h"

class ticketOrder
{
private:
	string name;
	Address address;
	int number_of_tickets;
	static int sumTicket;
public:
	
	ticketOrder();
	ticketOrder(string, Address, int);
	ticketOrder(string, string, string, int, int);
	~ticketOrder();

	string getName();
	Address getAddress();
	int getNumber_of_tickets();
	int getSumOfTickets();

	void setName(string);
	void setAddress(Address);
	void setNumber_of_tickets(int);

	void Print();
	void Input();

	const ticketOrder operator=(const ticketOrder &);
	bool operator==(const ticketOrder &);
	bool operator!=(const ticketOrder &);

	friend ostream &operator<<(ostream &, const ticketOrder &);
};

#endif