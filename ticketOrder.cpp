//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   ticketOrder.cpp

#include "ticketOrder.h"

ticketOrder::ticketOrder()
{
	number_of_tickets = 0;
	name = "";
	Address a;
	address = a;
}

ticketOrder::ticketOrder(string na, Address ad, int NoT)
{
	number_of_tickets = NoT;
	name = na;
	address = ad;
	sumTicket += number_of_tickets;
}

ticketOrder::ticketOrder(string na, string st, string ci, int zip, int NoT)
{
	number_of_tickets = NoT;
	name = na;
	Address a(st, ci, zip);
	address = a;
	sumTicket += number_of_tickets;
}

ticketOrder::~ticketOrder()
{
}

string ticketOrder::getName()
{
	return name;
}

Address ticketOrder::getAddress()
{
	return address;
}

int ticketOrder::getNumber_of_tickets()
{
	return number_of_tickets;
}

int ticketOrder::getSumOfTickets()
{
	return sumTicket;
}

void ticketOrder::setName(string na)
{
	name = na;
}

void ticketOrder::setAddress(Address ad)
{
	address = ad;
}

void ticketOrder::setNumber_of_tickets(int NoT)
{
	sumTicket -= number_of_tickets;
	number_of_tickets = NoT;
	sumTicket += number_of_tickets;
}

void ticketOrder::Print()
{
	cout << *this << endl;
}

void ticketOrder::Input()
{
	cout << "Name: ";
	cin >> name;
	cout << "Number of tickets: ";
	cin >> number_of_tickets;
	cin >> address;
	sumTicket += number_of_tickets;
}

const ticketOrder ticketOrder::operator=(const ticketOrder &rhs)
{
	number_of_tickets = rhs.number_of_tickets;
	address = rhs.address;
	name = rhs.name;

	return *this;
}

bool ticketOrder::operator==(const ticketOrder &rhs)
{
	if (name == rhs.name && address == rhs.address)
		return true;
	else
		return false;
}

bool ticketOrder::operator!=(const ticketOrder &rhs)
{
	if (*this == rhs)
		return false;
	else
		return true;
}

ostream &operator<<(ostream &strm, const ticketOrder &obj)
{
	strm << "Name: " << obj.name << endl << "Number of tickets: " << obj.number_of_tickets << endl << obj.address;
	return strm;
}