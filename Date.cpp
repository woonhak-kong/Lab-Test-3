#include "Date.h"
#include <ctime>
#include <iostream>
#include <string>


Date::Date():
    m_month(0),
    m_year(0)
{
}

Date::Date(int month, int year):
    m_month(month),
    m_year(year)
{
}

Date::~Date()
{
}

int Date::getNumOfDays()
{
    switch (m_month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if (isLeapyear())
            {
                return 29;
            }
            else
            {
                return 28;
            }
            break;
        default:
            break;
    }
    return 0;
}

void Date::setCurrentTime()
{
    tm curr_tm;
    time_t curr_time = time(nullptr);

    localtime_s(&curr_tm, &curr_time);

    m_year = curr_tm.tm_year + 1900;
    m_month = curr_tm.tm_mon + 1;


}

void Date::printDate()
{
    std::string month;
    switch (m_month)
    {
        case 1:
            month = "January";
            break;
        case 2:
            month = "February";
            break;
        case 3:
            month = "March";
            break;
        case 4:
            month = "April";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "June";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "August";
            break;
        case 9:
            month = "September";
            break;
        case 10:
            month = "October";
            break;
        case 11:
            month = "November";
            break;
        case 12:
            month = "December";
            break;
        default:
            break;
    }
    std::cout << "Month, " << month << " " << m_year <<", has " << getNumOfDays() << " days.\n";
}

bool Date::isLeapyear()
{
    if ((m_year % 4) == 0)
    {
        if ((m_year % 100) == 0)
        {
            if ((m_year % 400) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}
