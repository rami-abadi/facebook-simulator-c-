#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#include "friend.h"
#include "fanPage.h"

class FaceBook
{
private:
	int numOfFriends;
	int numOfCurrentMaxFriends;
	Friend** listOfFriends;

	int numOfFanPages;
	int numOfCurrentMaxFanPages;
	FanPage** listOfFanPages;
	
	void allocateNewFriendsArray();
	void allocateNewFanPagesArray();

public:
	FaceBook();
	~FaceBook();

	void printTenLatestStatusOfFriends() const;
	Friend* getFriendByName(const char* theName);
	FanPage* getFanPageByName(const char* theName);

	bool createFriend(const Friend& theFriend);
	void createFanPage(const FanPage& theFanPage);

	void printFriendsList();
	void printFanPagesList();
};
#endif
