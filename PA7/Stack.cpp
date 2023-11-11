#include "Stack.hpp"

Stack::Stack()
{
}

/// <summary>
/// copy constructor for a Stack object
/// </summary>
/// <param name="copy">Stack to be copied</param>
Stack::Stack(const Stack& copy)
{
	mAbsenceDates = copy.mAbsenceDates;
}

/// <summary>
/// destructor for Stack- empty
/// </summary>
Stack::~Stack()
{
	
}

/// <summary>
/// overloaded assignment operator for a Stack object
/// </summary>
/// <param name="rhs">The Stack on the right side of the operator</param>
/// <returns>dereferenced this pointer</returns>
Stack& Stack::operator=(const Stack& rhs)
{
	mAbsenceDates = rhs.mAbsenceDates;
	return *this;
}

/// <summary>
/// peek function for Stack object
/// </summary>
/// <returns>data value at the top of the stack</returns>
std::string Stack::peek()
{
	return mAbsenceDates[mAbsenceDates.size() - 1];
}

/// <summary>
/// pushes data entry to the top of the stack
/// </summary>
/// <param name="date">data entry to be pushed</param>
void Stack::push(const std::string& date)
{
	mAbsenceDates.push_back(date);
}

/// <summary>
/// pop function that removes the top of the stack
/// </summary>
/// <returns>data value stored at the top of the stack</returns>
std::string Stack::pop()
{
	std::string date = mAbsenceDates[mAbsenceDates.size() - 1];
	mAbsenceDates.pop_back();
	return date;
}

/// <summary>
/// function that checks if the stack is empty
/// </summary>
/// <returns>true if stack is empty</returns>
bool Stack::isEmpty()
{
	bool success = false;
	if (mAbsenceDates.empty())
	{
		success = true;
	}
	return success;
}

/// <summary>
/// stream insertion operator for a Stack object
/// </summary>
/// <param name="lhs">stream to be inserted into</param>
/// <param name="rhs">Stack object to be inserted</param>
/// <returns>original stream</returns>
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
