#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	int year;
	int month;
	int day;
	int hours;
	int minutes;
public:
	Date(int year, int month, int day, int hours, int minutes);

	void print() const;

	static Date getCurrentDate();
};


#endif
