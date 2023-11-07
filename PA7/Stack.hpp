#pragma once
#include <vector>
#include <string>

class Stack
{
public:
	
	std::string peek();
	void push(const std::string& date);
	std::string pop();
	bool isEmpty();

private:
	std::vector<std::string> mAbsenceDates;
};