#pragma once
#include <string>
#include "Stack.hpp"

class Data
{
public:
	Data();


private:
	int mNumAbsences;
	int mRecordNum;
	int mIDNum;
	std::string mName;
	std::string mEmail;
	std::string mUnits;
	std::string mProgram;
	std::string mLevel;
	Stack* mAbsenceDates;
};