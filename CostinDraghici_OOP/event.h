#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {
private:
	char* name;
	int* dateAndTime;
	int EventID;
	static int nextEventID;

public:
	Event(const std::string& name, int* dateAndTime);
	
	~Event();

	std::string getName() const;
	int getEventID() const;
	int getDateAndTime(int index) const;

	static int generateNextEventID();


};



#endif // !EVENT_H

