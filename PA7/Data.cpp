#include <vector>
#include <iostream>
#include <sstream>
#include "Data.hpp"

/// <summary>
/// default constructor for Data object
/// </summary>
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

/// <summary>
/// copy constructor for Data object
/// </summary>
/// <param name="copy">Data object to be copied</param>
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

/// <summary>
/// destructor for Data object - empty
/// </summary>
Data::~Data()
{}

/// <summary>
/// getter for mNumAbsences
/// </summary>
/// <returns>mNumAbsences</returns>
int Data::getNumAbsences()
{
	return mNumAbsences;
}

/// <summary>
/// getter for mRecordNum
/// </summary>
/// <returns>mRecordNum</returns>
int Data::getRecordNum()
{
	return mRecordNum;
}

/// <summary>
/// getter for IDNum
/// </summary>
/// <returns>mIDNum</returns>
int Data::getIDNum()
{
	return mIDNum;
}

/// <summary>
/// getter for mName
/// </summary>
/// <returns>mName</returns>
std::string Data::getName()
{
	return mName;
}

/// <summary>
/// getter for mEmail
/// </summary>
/// <returns>mEmail</returns>
std::string Data::getEmail()
{
	return mEmail;
}

/// <summary>
/// getter for mUnits
/// </summary>
/// <returns>mUnits</returns>
std::string Data::getUnits()
{
	return mUnits;
}

/// <summary>
/// getter for mProgram
/// </summary>
/// <returns>mProgram</returns>
std::string Data::getProgram()
{
	return mProgram;
}

/// <summary>
/// getter for mLevel
/// </summary>
/// <returns>mLevel</returns>
std::string Data::getLevel()
{
	return mLevel;
}

/// <summary>
/// getter for mAbsenceDates
/// </summary>
/// <returns>reference to a Stack labeled mAbsenceDates</returns>
Stack& Data::getAbsenceDates()
{
	return mAbsenceDates;
}

/// <summary>
/// setter for mNumAbsences
/// </summary>
/// <param name="newNum">new absence number</param>
void Data::setNumAbsences(int& newNum)
{
	mNumAbsences = newNum;
}

/// <summary>
/// setter for mRecordNum
/// </summary>
/// <param name="newNum">new RecordNum</param>
void Data::setRecordNum(int& newNum)
{
	mRecordNum = newNum;
}

/// <summary>
/// setter for mIDNum
/// </summary>
/// <param name="newNum">new IDNum</param>
void Data::setIDNum(int& newNum)
{
	mIDNum = newNum;
}

/// <summary>
/// setter for mName
/// </summary>
/// <param name="newName">new name</param>
void Data::setName(std::string newName)
{
	mName = newName;
}

/// <summary>
/// setter for mEmail
/// </summary>
/// <param name="newEmail">new email</param>
void Data::setEmail(std::string newEmail)
{
	mEmail = newEmail;
}

/// <summary>
/// setter for mUnits
/// </summary>
/// <param name="newUnits">new untis</param>
void Data::setUnits(std::string newUnits)
{
	mUnits = newUnits;
}

/// <summary>
/// setter for mProgram
/// </summary>
/// <param name="newProgram">new program</param>
void Data::setProgram(std::string newProgram)
{
	mProgram = newProgram;
}

/// <summary>
/// setter for mLevel
/// </summary>
/// <param name="newLevel">new level</param>
void Data::setLevel(std::string newLevel)
{
	mLevel = newLevel;
}

/// <summary>
/// member function that increments NumAbsences
/// </summary>
void Data::incrementNumAbsences(char sign)
{
	switch (sign)
	{
	case '+':
		mNumAbsences++;
	case '-':
		mNumAbsences--;
	}
	
}

/// <summary>
/// overloaded assignment operator for Data object
/// </summary>
/// <param name="rhs">Data object on right side of operator</param>
/// <returns>dereferenced this pointer</returns>
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

/// <summary>
/// overloaded stream extraction operator for Data object
/// </summary>
/// <param name="lhs"stream to be extracted from></param>
/// <param name="rhs">Data object to be extracted to</param>
/// <returns>original stream</returns>
std::istream& operator>>(std::istream& lhs, Data& rhs)
{
	std::string buffer;
	std::string line;
	std::vector<std::string> bufferSplit;//stores tokenized string values from a string stream 
	std::vector<std::string> bufferSplitRevDates;//stores tokenized string values, used to store and reverse specific data entries to from bufferSplit vector
	int bufferSplitInt[3]; // stores integer values from a string stream

	
	getline(lhs, line);//gets a single line from the stream on the left side of the operator
	std::stringstream imputSStream(line);//turns that line into a string stream
	
	int i = 0;	
	while (getline(imputSStream, buffer, ','))//splits the buffer into vectors with respect to the type, then sets Data's values from those vectors.
	{

		if (i < 3)
		{
			bufferSplitInt[i] = stoi(buffer);

		}
		else
		{
			bufferSplit.push_back(buffer);
		}
		i++;
	}
	rhs.setNumAbsences(bufferSplitInt[0]);
	rhs.setRecordNum(bufferSplitInt[1]);
	rhs.setIDNum(bufferSplitInt[2]);
	rhs.setName(bufferSplit[0] + ',' + bufferSplit[1]);//last and first name, seperated by a comma
	rhs.setEmail(bufferSplit[2]);
	rhs.setUnits(bufferSplit[3]);
	rhs.setProgram(bufferSplit[4]);
	rhs.setLevel(bufferSplit[5]);

	if (bufferSplit.size() > 6)// checks for absence dates
	{
		for (int j = 6; j < bufferSplit.size(); j++)//grabs the dates from the vector bufferSplit and pushes them into a new vector to reverse them. this is to make sure the most recent absence is at the top of the stack.
		{
			bufferSplitRevDates.push_back(bufferSplit[j]);
		}
		for (int k = 0; k < bufferSplitRevDates.size(); k++)
		{
			rhs.getAbsenceDates().push(bufferSplitRevDates[k]);//creates the stack stored witin Data object
		}
	}
		
	return lhs;
}

/// <summary>
/// overloaded stream insertion operator for a Data object
/// </summary>
/// <param name="lhs">stream to be inserted into</param>
/// <param name="rhs">Data object to be inserted</param>
/// <returns>original stream</returns>
std::ostream& operator<<(std::ostream& lhs, Data& rhs)
{
	lhs << rhs.getNumAbsences() << ',' << rhs.getRecordNum() << ',' << rhs.getIDNum() << ',' << rhs.getName() << ',' << rhs.getEmail() << ',' << rhs.getUnits() << ',' << rhs.getProgram() << ',' << rhs.getLevel() << ',';
	if (!rhs.getAbsenceDates().isEmpty())//checks if the mAbsenceDates stacks has entries, and if it does it calls the Stack objects insertion operator to insert them.
	{
		 lhs << rhs.getAbsenceDates();
	}
	
	return lhs;
}
