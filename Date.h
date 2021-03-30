#pragma once

class Date
{
public:

	Date();
	Date(int month, int year);
	virtual ~Date();

	int getNumOfDays();
	void setCurrentTime();
	void printDate();


private:

	bool isLeapyear();

	int m_month;
	int m_year;


};

