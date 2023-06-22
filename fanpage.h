#ifndef __FANPAGE_H
#define __FANPAGE_H

#pragma warning(disable:4996 )

#include "status.h"

class FanPage
{
	char* name;
	Status** listOfStatus;
	Date dateOfCreation; // I wanted to make this a const but then I cant init it, what to do?
	int numOfstatus;
	int maxStatuses;

	void allocateNewArray(); // ask keren if theres a way to write only funtion that friend and fanPage can use

public:
	FanPage(const char* theName);
	FanPage(const FanPage& other);
	~FanPage();

	char* getName() const;
	
	void uploadStatus(Status& theStatus);

	void print();
	void showAllStatus();
};


#endif
