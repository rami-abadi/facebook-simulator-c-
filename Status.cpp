#include <iostream>
#include <time.h>
using namespace std;

#include "status.h"
#pragma warning(disable:4996 )


Status::Status(const char* content) : dateOfPosting(Date::getCurrentDate())
{
	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);

	//this->dateOfPosting = getCurrentDate();;
}

Status::Status(const Status& other) : dateOfPosting(other.dateOfPosting)
{
	content = new char[strlen(other.content) + 1];
	strcpy(content, other.content);
	//dateOfPosting = other.dateOfPosting;
}

Status::~Status()
{
	delete[]content;
}

const char* Status::getContent() const
{
	return content;
}

void Status::print() const
{
	cout << "status was posted at: ";
	dateOfPosting.print();
	cout << "\ncontent:\n"<<content<<endl;
}
