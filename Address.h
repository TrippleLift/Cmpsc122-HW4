//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   Address.h

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>
using namespace std;

class Address
{
private:
	string street;
	string city;
	int zip_code;
public:
	Address();
	Address(string, string, int);
	Address(const Address &rhs);
	~Address();

	string getStreet();
	string getCity();
	int getZip_code();

	void setStreet(string);
	void setCity(string);
	void setZip_code(int);

	void Print();

	const Address operator=(const Address &);
	bool operator==(const Address &);

	friend ostream &operator<<(ostream &, const Address &);
	friend istream &operator>>(istream &, Address &);
};

#endif