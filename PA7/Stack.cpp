#include "Stack.hpp"



std::string Stack::peek()
{
	return mAbsenceDates[mAbsenceDates.size() - 1];
}

void Stack::push(const std::string& date)
{
	mAbsenceDates.push_back(date);
}

std::string Stack::pop()
{
	std::string date = mAbsenceDates[mAbsenceDates.size() - 1];
	mAbsenceDates.pop_back();
	return date;
}

bool Stack::isEmpty()
{
	bool success = false;
	if (mAbsenceDates.size() == 0)
	{
		success = true;
	}
	return success;
}

