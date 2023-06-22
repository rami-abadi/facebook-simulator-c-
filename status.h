#ifndef  __STATUS_H
#define __STATUS_H

#include "date.h"

class Status
{
private:
	Date dateOfPosting;
	char* content;

public:	
	Status(const char* content);
	Status(const Status& other);
	~Status();

	const char* getContent() const;
	
	void print() const;
};

#endif
