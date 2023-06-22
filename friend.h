
#ifndef __FRIEND_H
#define __FRIEND_H

#pragma warning(disable:4996 )

#include "status.h"

class Friend
{
private:
	char* name;
	Date dateOfCreation; // I wanted to make this a const but then I cant init it, what to do?
	Status** listOfStatus;
	int numOfstatus;
	int maxStatuses;

	void allocateNewArray();

public:
	Friend(const char* theName);
	Friend(const Friend& other);
	~Friend();

	const char* getName() const;
	int getNumOfStatus() const;
	
	void uploadStatus(const Status& theStatus);
	
	void print() const;
	void printStatus(int index) const;
	void showAllStatus() const;

};








#endif
