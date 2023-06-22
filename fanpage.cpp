#include <iostream>
using namespace std;

#include "fanPage.h"

FanPage::FanPage(const char* theName) : dateOfCreation(Date::getCurrentDate())
{
	name = new char[strlen(theName) + 1];
	strcpy(name, theName);

	//this->dateOfCreation = getCurrentDate();

	maxStatuses = 2;
	numOfstatus = 0;
	listOfStatus = new Status * [maxStatuses];
}

FanPage::FanPage(const FanPage& other) : dateOfCreation(other.dateOfCreation)
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

FanPage::~FanPage()
{
	delete[]name;

	for (int i = 0; i < numOfstatus; i++)
		delete listOfStatus[i];
	delete[]listOfStatus;
}

char* FanPage::getName() const
{
	return name;
}

void FanPage::print()
{
	cout << "the fanPage '" << name << "' was created at ";
	dateOfCreation.print();
	cout << endl;
}

void FanPage::uploadStatus(Status& theStatus)
{
	if (this == nullptr)
	{
		cout << "\nerror. status not uploaded\n";
		return;
	}
	if (numOfstatus == maxStatuses)
	{
		allocateNewArray();
	}
	listOfStatus[numOfstatus++] = new Status(theStatus.getContent());
}

void FanPage::allocateNewArray()
{
	maxStatuses*=2;
	Status** newArray = new Status * [maxStatuses];

	for (int i = 0; i < numOfstatus; i++)
	{
		newArray[i] = listOfStatus[i];
	}
	delete[]listOfStatus;

	listOfStatus = newArray;	

}

void FanPage::showAllStatus()
{
	if (numOfstatus == 0)
	{
		cout << "\n" << "the fanPage '" << name << "' has no status\n";
	}
	else
	{
		cout << "\nstatuses of fanPage '" << name << "':\n";
		for (int i = 0; i < numOfstatus; i++)
		{
			cout << "\nstatus #" << i + 1<<endl;
			listOfStatus[i]->print();
			cout << endl;
		}
	}
}
