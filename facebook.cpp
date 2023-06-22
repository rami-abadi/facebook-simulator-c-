#include <iostream>
using namespace std;

#include "faceBook.h"

#pragma warning(disable:4996 )

void FaceBook::printTenLatestStatusOfFriends() const 
{
	int counter = 0;
	int currentStatusToPrint = 0;
	int totalNumOfStatus=0;
	int countTo=0;

	for (int i = 0; i < numOfFriends; i++)
	{
		totalNumOfStatus += listOfFriends[i]->getNumOfStatus();
	}

	if (totalNumOfStatus >= 10)
	{
		countTo = 10;
	}
	else
	{
		countTo = totalNumOfStatus;
	}

	while (counter < countTo)
	{
		for (int i = 0; i < numOfFriends; i++)
		{
			if(listOfFriends[i]->getNumOfStatus()>currentStatusToPrint && counter<countTo)
			{
			listOfFriends[i]->printStatus(currentStatusToPrint);
			cout << endl;
			counter++;
			}
		}
		currentStatusToPrint++;
	}
}

bool FaceBook::createFriend(const Friend& theFriend) 
{
	Friend* temp = getFriendByName(theFriend.getName());
	if (temp)
	{
		return false;
	}
		
	if (numOfFriends == numOfCurrentMaxFriends)
	{
		allocateNewFriendsArray();
	}
	listOfFriends[numOfFriends++] = new Friend(theFriend);
	return true;
	
}

void FaceBook::allocateNewFriendsArray()
{
	numOfCurrentMaxFriends *=2;
	Friend** newArray = new Friend * [numOfCurrentMaxFriends];

	for (int i = 0; i < numOfFriends; i++)
	{
		newArray[i] = listOfFriends[i];
	}
	delete[]listOfFriends;
	listOfFriends = newArray;
}

void FaceBook::allocateNewFanPagesArray()
{
	numOfCurrentMaxFanPages *= 2;
	FanPage** newArray = new FanPage * [numOfCurrentMaxFanPages];
	for (int i = 0; i < numOfFanPages; i++)
	{
		newArray[i] = listOfFanPages[i];
	}
	delete[]listOfFanPages;
	listOfFanPages = newArray;
}

void FaceBook::createFanPage(const FanPage& theFanPage)
{
	for (int i = 0; i < numOfFanPages; i++)
	{
		if (strcmp(listOfFanPages[i]->getName(), theFanPage.getName()) == 0)
		{
			cout << "\nthis name is already taken. fanPage not created.\n";
			return;
		}
	}

	if (numOfFanPages == numOfCurrentMaxFanPages)
	{
		allocateNewFanPagesArray();
	}
	listOfFanPages[numOfFanPages++] = new FanPage(theFanPage);
}

void FaceBook::printFriendsList() 
{
	if (numOfFriends == 0)
	{
		cout << "\nno friends exist\n";
	}
	else
	{
		for (int i = 0; i < numOfFriends; i++)
		{
			listOfFriends[i]->print();
		}
	}
}

void FaceBook::printFanPagesList()
{
	if (numOfFanPages == 0)
	{
		cout << "\nno fanPages exist\n";
	}
	else
	{
		for (int i = 0; i < numOfFanPages; i++)
		{
			listOfFanPages[i]->print();
		}
	}
}

Friend* FaceBook::getFriendByName(const char* theName)
{
	for (int i = 0; i < numOfFriends; i++)
	{
		if (strcmp(listOfFriends[i]->getName(),theName)==0)
		{
			return listOfFriends[i];
		}
	}
	cout << "\nno friend by that name\n";
	return nullptr;
}

FanPage* FaceBook::getFanPageByName(const char* theName)
{
	for (int i = 0; i < numOfFanPages; i++)
	{
		if (strcmp(listOfFanPages[i]->getName(),theName)==0)
		{
			return listOfFanPages[i];
		}
	}
	cout << "\nno fanPage by that name\n";
	return nullptr;
}

FaceBook::FaceBook()
{
	numOfFriends = 0;
	numOfFanPages = 0;
	numOfCurrentMaxFanPages = 2;
	numOfCurrentMaxFriends = 2;
	listOfFriends = new Friend * [numOfCurrentMaxFriends];
	listOfFanPages = new FanPage * [numOfCurrentMaxFanPages];
}

FaceBook::~FaceBook()
{
	for (int i = 0; i < numOfFriends; i++)
		delete listOfFriends[i];
	delete[]listOfFriends;

	for (int i = 0; i < numOfFanPages; i++)
		delete listOfFanPages[i];
	delete[]listOfFanPages;
}
