#include <iostream>
#include "Date.h"


using namespace std;


int main()
{
	Date* date = nullptr;
	int month = 0;
	int year = 0;

	cout << "<If you enter \"0 0\", it will show current month and year and then be terminated.>\n\n";
	do
	{
		cout << "Enter month and year: ";
		cin >> month;
		cin >> year;

		if (month == 0 && year == 0)
		{
			date = new Date();
			date->setCurrentTime();
			cout << "The current ";
			date->printDate();
			delete date;
			date = nullptr;
		}
		else if (month < 1 || month > 12)
		{
			cout << "Please Enter 1 ~ 12\n";
		}
		else
		{
			date = new Date(month, year);
			cout << date->getNumOfDays() << " days\n";
			delete date;
			date = nullptr;
		}

	} while (month != 0 || year != 0);


	return 0;
}