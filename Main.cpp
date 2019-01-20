//Programmer:  Joseph Chang
//Section:     #001
//Activity:    #4
//Date:        Mar 19, 2018
//File name:   Main.cpp

#include <iostream>
#include "LL.h"

using namespace std;

int ticketOrder::sumTicket = 0;

int main()
{
	List list;
	do
	{
		ticketOrder order;
		order.Input();
		list.Append(order);
		bool a = list.checkIfMore_than_four_tickets();
	} while (list.sum_of_tickets() <= 100);
	cout << endl << endl;
	bool a = list.checkIfName_repeat();

	system("pause");
	return 0;
}