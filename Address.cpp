//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   Address.h

#include "Address.h"

Address::Address()
{
	street = "";
	city = "";
	zip_code = 0;
}

Address::Address(string st, string ci, int zip)
{
	street = st;
	city = ci;
	zip_code = zip;
}

Address::Address(const Address &rhs)
{
	street = rhs.street;
	city = rhs.city;
	zip_code = rhs.zip_code;
}

Address::~Address()
{
}

string Address::getStreet()
{
	return street;
}

string Address::getCity()
{
	return city;
}

int Address::getZip_code()
{
	return zip_code;
}

void Address::setStreet(string st)
{
	street = st;
}

void Address::setCity(string ci)
{
	city = ci;
}

void Address::setZip_code(int zip)
{
	zip_code = zip;
}

void Address::Print()
{
	cout << *this << endl;
}

const Address Address::operator=(const Address &rhs)
{
	if (this != &rhs)
	{
		street = rhs.street;
		city = rhs.city;
		zip_code = rhs.zip_code;
	}
	return *this;
}

bool Address::operator==(const Address &rhs)
{
	if (street == rhs.street && city == rhs.city && zip_code == rhs.zip_code)
		return true;
	else
		return false;
}

ostream &operator<<(ostream &strm, const Address &obj)
{
	strm << "Street: " << obj.street << "\nCity: " << obj.city << "\nZip code: " << obj.zip_code;
	return strm;
}

istream &operator>>(istream &strm, Address &obj)
{
	cout << "Street: ";
	cin.ignore();
	getline(cin, obj.street);
	cout << "City: ";
	getline(cin, obj.city);
	cout << "Zip code: ";
	strm >> obj.zip_code;

	return strm;
}