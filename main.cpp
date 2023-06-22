
#include <iostream>
using namespace std;

#include "faceBook.h"
#include "messages.h"

#define  MAX_STATUS_SIZE 100
#define MAX_NAME_SIZE 20

void cleanBuffer();
void populateFacebook(FaceBook& theFacebook);

void main()
{
	FaceBook theFacebook;
	char friendName[MAX_NAME_SIZE];
	char fanPageName[MAX_NAME_SIZE];
	char whichFriend[MAX_NAME_SIZE];
	char statusContent[MAX_STATUS_SIZE];
	int myCase=0;

	populateFacebook(theFacebook);
	
	while (myCase != 9)
	{
		cout << "choose option:\n";
		cout << "1. add friend to facebook\n2.add fanPage to facebook\n3.add status to a friend\n4.add status to a fanPage\n5.show all statuses of a friend\n6.show all statuses of a fanPage\n7.show 10 most recent statuses(of friends)\n8.show all friends and fanPages\n9.exit\n";
		cin >> myCase;
		switch (myCase)
		{
		case 1: // add friend
		{
			cout << "\n------------\nenter friend's name:\n";
			cleanBuffer();
			cin.getline(friendName, MAX_NAME_SIZE);
			Friend myFriend(friendName);
			theFacebook.createFriend(myFriend);
			cout << "------------\n\n";
		}
		break;
		case 2:
		{
			cout << "\n------------\nenter fanPage's name:\n";
			cleanBuffer();
			cin.getline(fanPageName,MAX_NAME_SIZE);
			FanPage myFanPage(fanPageName);
			theFacebook.createFanPage(myFanPage);
			cout << "------------\n\n";
		}
		break;
		case 3:
		{
			cout << "\n------------\nchoose friend to upload status to: (write friend's name)\n";
			cleanBuffer();
			cin.getline(whichFriend, MAX_NAME_SIZE);
			cout << "\nwrite your status:\n";
			cin.getline(statusContent, MAX_STATUS_SIZE);
			Status myStatus(statusContent);
			theFacebook.getFriendByName(whichFriend)->uploadStatus(myStatus);
			cout << "------------\n\n";
		}
		break;
		case 4:
		{
			cout << "\n------------\nchoose fanPage to upload status to: (write fanPage's name)\n";
			cleanBuffer();
			cin.getline(whichFriend, MAX_NAME_SIZE);
			cout << "\nwrite your status:\n";
			cin.getline(statusContent, MAX_STATUS_SIZE);
			Status myStatus(statusContent);
			theFacebook.getFanPageByName(whichFriend)->uploadStatus(myStatus);
			cout << "------------\n\n";
		}
		break;
		case 5:
			cout << "\n------------\nchoose friend to print his statuses: (write friend's name)\n";
			cleanBuffer();
			cin.getline(whichFriend, MAX_NAME_SIZE);
			theFacebook.getFriendByName(whichFriend)->showAllStatus();
			cout << "------------\n\n";
			break;
		case 6:
			cout << "\n------------\nchoose fanPage to print his statuses: (write fanPage's name)\n";
			cleanBuffer();
			cin.getline(whichFriend, MAX_NAME_SIZE);
			theFacebook.getFanPageByName(whichFriend)->showAllStatus();
			cout << "------------\n\n";
			break;
		case 7:
			cout << "\n------------\n";
			theFacebook.printTenLatestStatusOfFriends();
			cout << "------------\n\n";
			break;
		case 8:
			cout << "\n------------\nfriends list:\n";
			theFacebook.printFriendsList();
			cout << "\nfanPages list:\n";
			theFacebook.printFanPagesList();
			cout << "------------\n\n";
			break;
		case 9:
			cout << "\n   -----   \n  GoodBye\n   -----   \n";
			break;
		default:
			cout << "\nselect option from the menu (1-9)\n";
			break;

		}
	}
}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void populateFacebook(FaceBook& theFacebook)
{
	Friend f1("toto");
	Friend f2("gogo");
	Friend f3("vovo");

	if (theFacebook.createFriend(f1) == false)
	{
		cout << MSG_FRIEND_ALREADY_EXISTS << endl;
	}
	theFacebook.createFriend(f2);
	theFacebook.createFriend(f3);

	Status s1("My wife told me to stop impersonating a flamingo. I had to put my foot down.");
	Status s2("I went to buy some camo pants but couldn't find any.");
	Status s3("I was wondering why the frisbee kept getting bigger and bigger, but then it hit me.");
	Status s4("what did one ocean say to the other? nothing, they just waved.");
	Status s5("what do you call a fish with no eyes? A fsh.");
	Status s6("what do you call a can opener that dosen't work? a can't opener!");
	Status s13("what do you get when you combine a rhetorical question and a joke? ...");
	Status s14("Don't trust children. they're here to replace us!");
	Status s15("I'm going to stop putting things off, starting tomorrow.");
	Status s16("work is just something I'm doing untill I win the lottery.");
	Status s17("I'm still waiting for the wisdom I was assured would come with age...");
	Status s18("kids, just because I don't care doesn't mean I'm not listening.");

	theFacebook.getFriendByName("toto")->uploadStatus(s1);
	theFacebook.getFriendByName("toto")->uploadStatus(s2);

	theFacebook.getFriendByName("gogo")->uploadStatus(s3);
	theFacebook.getFriendByName("gogo")->uploadStatus(s4);
	theFacebook.getFriendByName("gogo")->uploadStatus(s13);
	theFacebook.getFriendByName("gogo")->uploadStatus(s14);

	theFacebook.getFriendByName("vovo")->uploadStatus(s5);
	theFacebook.getFriendByName("vovo")->uploadStatus(s6);	
	theFacebook.getFriendByName("vovo")->uploadStatus(s15);
	theFacebook.getFriendByName("vovo")->uploadStatus(s16);
	theFacebook.getFriendByName("vovo")->uploadStatus(s17);
	theFacebook.getFriendByName("vovo")->uploadStatus(s18);

	FanPage fp1("cake master");
	FanPage fp2("CakeShop");
	FanPage fp3("I love cakes!");

	theFacebook.createFanPage(fp1);
	theFacebook.createFanPage(fp2);
	theFacebook.createFanPage(fp3);

	Status s7("strawberry cake recipe:\ntake a cake, add strawberries.");
	Status s8("when breaking the eggs always remember to accidentally drop a few shell pieces in the mix.");
	Status s9("we're all out of cakes :(");
	Status s10("note to self: learn how to make cakes before opening a cake business...");
	Status s11("drove 2 hours to get a cake from CakeShop and they were sold out...");
	Status s12("don't listen to cake master, he's gone haywire from all the sugar");

	theFacebook.getFanPageByName("cake master")->uploadStatus(s7);
	theFacebook.getFanPageByName("cake master")->uploadStatus(s8);

	theFacebook.getFanPageByName("CakeShop")->uploadStatus(s9);
	theFacebook.getFanPageByName("CakeShop")->uploadStatus(s10);

	theFacebook.getFanPageByName("I love cakes!")->uploadStatus(s11);
	theFacebook.getFanPageByName("I love cakes!")->uploadStatus(s12);
}
