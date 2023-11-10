#include <vector>
#include <iostream>
#include "Data.hpp"

Data::Data()
{
	mNumAbsences = 0;
	mRecordNum = 0;
	mIDNum = 0;
	mName = "";
	mEmail = "";
	mUnits = "";
	mProgram = "";
	mLevel = "";
	
}

Data::Data(const Data& copy)
{
	mNumAbsences = copy.mNumAbsences;
	mRecordNum = copy.mRecordNum;
	mIDNum = copy.mIDNum;
	mName = copy.mName;
	mEmail = copy.mEmail;
	mUnits = copy.mUnits;
	mProgram = copy.mProgram;
	mLevel = copy.mLevel;
	mAbsenceDates = copy.mAbsenceDates;
}

Data::~Data()
{
	
	
}

int Data::getNumAbsences()
{
	return mNumAbsences;
}

int Data::getRecordNum()
{
	return mRecordNum;
}

int Data::getIDNum()
{
	return mIDNum;
}

std::string Data::getName()
{
	return mName;
}

std::string Data::getEmail()
{
	return mEmail;
}

std::string Data::getUnits()
{
	return mUnits;
}

std::string Data::getProgram()
{
	return mProgram;
}

std::string Data::getLevel()
{
	return mLevel;
}

Stack& Data::getAbsenceDates()
{
	return mAbsenceDates;
}

void Data::setNumAbsences(int& newNum)
{
	mNumAbsences = newNum;
}

void Data::setRecordNum(int& newNum)
{
	mRecordNum = newNum;
}

void Data::setIDNum(int& newNum)
{
	mIDNum = newNum;
}

void Data::setName(std::string newName)
{
	mName = newName;
}

void Data::setEmail(std::string newEmail)
{
	mEmail = newEmail;
}

void Data::setUnits(std::string newUnits)
{
	mUnits = newUnits;
}

void Data::setProgram(std::string newProgram)
{
	mProgram = newProgram;
}

void Data::setLevel(std::string newLevel)
{
	mLevel = newLevel;
}

void Data::incrementNumAbsences()
{
	mNumAbsences++;
}

Data& Data::operator=(const Data& rhs)
{
	mNumAbsences = rhs.mNumAbsences;
	mRecordNum = rhs.mRecordNum;
	mIDNum = rhs.mIDNum;
	mName = rhs.mName;
	mEmail = rhs.mEmail;
	mUnits = rhs.mUnits;
	mProgram = rhs.mProgram;
	mLevel = rhs.mLevel;
	mAbsenceDates = rhs.mAbsenceDates;
	return *this;
}

std::istream& operator>>(std::istream& lhs, Data& rhs)
{
	std::string buffer;
	std::string bufferSplit[6];
	int bufferSplitInt[3];
	

	while (getline(lhs, buffer, ','))//splits the buffer into vectors with respect to the type, then sets Data's values from those vectors.
	{
		int i = 0;
		if (i < 3)
		{
			bufferSplitInt[i] = stoi(buffer);
			i++;
		}
		else
		{
			bufferSplit[i - 3] = buffer;
		}
		
	}
	rhs.setNumAbsences(bufferSplitInt[0]);
	rhs.setRecordNum(bufferSplitInt[1]);
	rhs.setIDNum(bufferSplitInt[2]);
	rhs.setName(bufferSplit[0] + ',' + bufferSplit[1]);
	rhs.setEmail(bufferSplit[2]);
	rhs.setUnits(bufferSplit[3]);
	rhs.setProgram(bufferSplit[4]);
	rhs.setLevel(bufferSplit[5]);
	
	return lhs;
}

std::ostream& operator<<(std::ostream& lhs, Data& rhs)
{
	lhs << rhs.getNumAbsences() << ',' << rhs.getRecordNum() << ',' << rhs.getIDNum() << ',' << rhs.getName() << ',' << rhs.getEmail() << ',' << rhs.getUnits() << ',' << rhs.getProgram() << ',' << rhs.getLevel() << ',';
	if (!rhs.getAbsenceDates().isEmpty())
	{
		 lhs << rhs.getAbsenceDates();
	}
	
	return lhs;
}
