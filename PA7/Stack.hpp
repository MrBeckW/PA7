#pragma once
#include <vector>
#include <string>
#include <iostream>

class Stack
{
public:
	Stack();
	Stack(const Stack& copy);
	~Stack();
	Stack& operator= (const Stack& rhs);

	std::string peek();
	void push(const std::string& date);
	std::string pop();
	bool isEmpty();

private:
	std::vector<std::string> mAbsenceDates;
};

std::ostream& operator<<(std::ostream& lhs, Stack& rhs);