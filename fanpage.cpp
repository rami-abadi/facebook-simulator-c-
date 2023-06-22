#include <iostream>
using namespace std;

#include "friend.h"

Friend::Friend(const char* theName) : dateOfCreation(Date::getCurrentDate())
{
	name = new char[strlen(theName) + 1];
	strcpy(name, theName);

	//this->dateOfCreation = getCurrentDate();

	maxStatuses = 2;
	numOfstatus = 0;
	listOfStatus = new Status * [maxStatuses];
}

Friend::Friend(const Friend& other) : dateOfCreation(other.dateOfCreation)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	//dateOfCreation = other.dateOfCreation;
	numOfstatus = other.numOfstatus;
	maxStatuses = other.maxStatuses;

	listOfStatus = new Status * [maxStatuses];

	for (int i = 0; i < numOfstatus; i++)
	{
		listOfStatus[i] = new Status(*(other.listOfStatus[i]));
	}
}

Friend::~Friend()
{
	delete[]name;

	for (int i = 0; i < numOfstatus; i++)
		delete listOfStatus[i];
	delete[]listOfStatus;
}

void Friend::print() const
{
	cout << "the friend '" << name << "' was created at ";
	dateOfCreation.print();
	cout << endl;
}

void Friend::uploadStatus(const Status& theStatus)
{
	if (numOfstatus == maxStatuses)
	{
		allocateNewArray();
	}
	
	listOfStatus[numOfstatus++] = new Status(theStatus);
}

void Friend::allocateNewArray()
{
	maxStatuses *= 2;
	Status** newArray = new Status * [maxStatuses];

	for (int i = 0; i < numOfstatus; i++)
	{
		newArray[i] = listOfStatus[i];
	}
	delete[]listOfStatus;
	listOfStatus = newArray;
}

void Friend::showAllStatus() const
{
	if (numOfstatus == 0)
	{
		cout << "\nthe friend '" << name << "' has no status\n";
	}
	else
	{

		cout << "\nstatuses of friend '" << name << "':\n";
		for (int i = 0; i < numOfstatus; i++)
		{
			cout << "\nstatus #" << i + 1<<endl;
			listOfStatus[i]->print();
			cout << endl;
		}
	}
}

void Friend::printStatus(int index) const
{
	if (index > numOfstatus) return;
	listOfStatus[index]->print();
}

const char* Friend::getName() const
{
	return name;
}

int Friend::getNumOfStatus() const
{
	return numOfstatus;
}
