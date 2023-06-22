#include <iostream>
using namespace std;

#include "date.h"

#pragma warning(disable: 4996)

Date::Date(int year, int month, int day, int hours, int minutes)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hours = hours;
	this->minutes = minutes;
}

void Date::print() const
{
	cout << day << "/" << month << "/" << year<<" "<<(hours<10 ? "0":"")<<hours<< ":" << (minutes<10 ? "0":"")<<minutes;
}

Date Date::getCurrentDate()
{
	time_t myTime = time(0);
	struct tm* now = localtime(&myTime);

	Date currentDate(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min);
	return currentDate;
}
