#include <vector>
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
	mAbsenceDates = nullptr;
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

std::istream& operator>>(std::istream& lhs, Data& rhs)
{
	std::string buffer;
	std::vector<std::string> bufferSplit;
	std::vector<int> bufferSplitInt;
	int i = 0;

	while (getline(lhs, buffer, ','))//splits the buffer into vectors with respect to the type, then sets Data's values from those vectors.
	{
		
		if (i < 3)
		{
			bufferSplitInt.push_back(stoi(buffer));
			i++;
		}
		else
		{
			bufferSplit.push_back(buffer);
		}
		
	}
	rhs.setNumAbsences(bufferSplitInt[0]);
	rhs.setRecordNum(bufferSplitInt[1]);
	rhs.setIDNum(bufferSplitInt[2]);
	rhs.setName(bufferSplit[0]);
	rhs.setEmail(bufferSplit[1]);
	rhs.setUnits(bufferSplit[2]);
	rhs.setProgram(bufferSplit[3]);
	rhs.setLevel(bufferSplit[4]);
	
	return lhs;
}

std::ostream& operator<<(std::ostream& lhs, Data& rhs)
{
	lhs << rhs.getNumAbsences() << ',' << rhs.getRecordNum() << ',' << rhs.getIDNum() << ',' << rhs.getName() << ',' << rhs.getEmail() << ',' << rhs.getUnits() << ',' << rhs.getProgram() << ',' << rhs.getLevel() << std::endl;
	return lhs;
}
