#include "Stack.hpp"



Stack::Stack()
{
	
}

Stack::Stack(const Stack& copy)
{
	mAbsenceDates = copy.mAbsenceDates;
}

Stack::~Stack()
{
	
}

Stack& Stack::operator=(const Stack& rhs)
{
	mAbsenceDates = rhs.mAbsenceDates;
	return *this;
}

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
	if (mAbsenceDates.empty())
	{
		success = true;
	}
	return success;
}

std::ostream& operator<<(std::ostream& lhs, Stack& rhs)
{
	std::vector<std::string> temp;
	while (!rhs.isEmpty())//fills a vector with the contents of the stack, then pops every item of the stack and inserts it into the stream along with a ,
	{
		temp.push_back(rhs.peek());
		lhs << rhs.pop() + ',';
	}
	if (temp.size() != 0)//recreates the original stack from the items in the vector
	{
		for (int i = temp.size(); i < 0; i--)
		{
			rhs.push(temp[i]);
		}
	}
	return lhs;
}
