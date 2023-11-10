#pragma once
#include <string>
#include <iostream>
#include "Stack.hpp"

class Data
{
public:
	Data();
	Data(const Data& copy);
	~Data();

	int getNumAbsences();
	int getRecordNum();
	int getIDNum();
	std::string getName();
	std::string getEmail();
	std::string getUnits();
	std::string getProgram();
	std::string getLevel();
	Stack& getAbsenceDates();

	void setNumAbsences(int& newNum);
	void setRecordNum(int& newNum);
	void setIDNum(int& newNum);
	void setName(std::string newName);
	void setEmail(std::string newEmail);
	void setUnits(std::string newUnits);
	void setProgram(std::string newProgram);
	void setLevel(std::string newLevel);

	void incrementNumAbsences();

	Data& operator=(const Data& rhs);

private:
	int mNumAbsences;
	int mRecordNum;
	int mIDNum;
	std::string mName;
	std::string mEmail;
	std::string mUnits;
	std::string mProgram;
	std::string mLevel;
	Stack mAbsenceDates;
};

std::istream& operator>>(std::istream& lhs, Data& rhs);
std::ostream& operator<<(std::ostream& lhs, Data& rhs);