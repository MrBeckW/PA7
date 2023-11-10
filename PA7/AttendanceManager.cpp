#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#include "AttendanceManager.hpp"

AttendanceManager::AttendanceManager()
{
	mMasterList = new List<Data>();
	mImput.open("classList.csv");
}

AttendanceManager::~AttendanceManager()
{
	mImput.close();
	delete mMasterList;
}

void AttendanceManager::runApp()
{
	menu();
}

void AttendanceManager::importRecords()
{
	Data temp;
	std::string buffer, line;
	std::string bufferSplit[6];
	int bufferSplitInt[2];
	
	
	getline(mImput, line);//traverses past first line
	
	while (getline(mImput, line))//grabs whole line from file
	{
		std::stringstream imputSStream(line);//turns line into a string stream
		int i = 0;
		while (getline(imputSStream, buffer, ','))
		{
			if (i < 2)
			{
				bufferSplitInt[i] = (stoi(buffer));
			}
			else
			{
				bufferSplit[i - 2] = (buffer);
			}
			i++;
		}

		temp.setRecordNum(bufferSplitInt[0]);
		temp.setIDNum(bufferSplitInt[1]);
		temp.setName(bufferSplit[0] + "," + bufferSplit[1]);
		temp.setEmail(bufferSplit[2]);
		temp.setUnits(bufferSplit[3]);
		temp.setProgram(bufferSplit[4]);
		temp.setLevel(bufferSplit[5]);

		mMasterList->insertFront(temp);//inserts new node into List
	}
	
}

void AttendanceManager::loadMasterList()
{
}

void AttendanceManager::storeMasterList()
{
	std::ofstream masterOutput;
	masterOutput.open("masterList.csv");

	if (masterOutput)
	{
		ListNode<Data>* pCur = mMasterList->getpHead();
		while (pCur != nullptr)
		{
			masterOutput << *pCur << std::endl;
			pCur = pCur->getpNext();
		}
	}

	masterOutput.close();
}

void AttendanceManager::markAbsence()
{
	if (mMasterList != nullptr)
	{
		ListNode<Data>* pCur = mMasterList->getpHead();
		int selection = 0;
		Data temp;
		while (pCur != nullptr)
		{
			while (selection != 1 && selection != 2)
			{
				std::cout << "\nWas " << pCur->getData().getName() << " absent today? YES: 1 NO: 2\n";
				std::cin >> selection;
				switch (selection)
				{
				case 1:
					temp = pCur->getData();
					temp.incrementNumAbsences();
					temp.getAbsenceDates().push(this->getTodaysDate());
					pCur->setData(temp);
					break;
				case 2:
					break;
				default:
					std::cout << "Selection out of bounds\n";
				}
			}
			pCur = pCur->getpNext();
			selection = 0;
		}
	}
	else
	{
		std::cout << "\n---ERROR---\nThe Master List is not Loaded!\n";
	}
}

void AttendanceManager::editAbsence()
{
}

void AttendanceManager::generateReport()
{
}

void AttendanceManager::menu()
{
	int selection = 0;
	while (selection != 7)
	{
		displayMenu();
		std::cin >> selection;

		switch (selection)
		{
		case 1: importRecords();
			break;
		case 2: loadMasterList();
			break;
		case 3: storeMasterList();
			break;
		case 4: markAbsence();
			break;
		case 5: editAbsence();
			break;
		case 6: generateReport();
			break;
		case 7:
			break;
		case 999: displayList();
			break;
		default: 
			std::cout << "\n---ERROR---\nSelection not valid\n";
		}
	}

}

void AttendanceManager::displayMenu()
{
	std::cout << "\nWelcome to the Attendance Manager!\n\n"
		<< "---Main Menu---\n"
		<< "1. Import corse list\n"
		<< "2. Load master list\n"
		<< "3. Store master list\n"
		<< "4. Mark absences\n"
		<< "5. Edit absences\n"
		<< "6. Generate report\n"
		<< "7. Exit\n\n"
		<< "Enter Your Selection: ";
}

void AttendanceManager::displayList()
{
	mMasterList->printList();
}

std::string AttendanceManager::getTodaysDate()
{
	time_t t = time(0);
	struct tm* now = localtime(&t);
	
	int year = now->tm_year + 1900, day = now->tm_mday, month = now->tm_mon + 1;

	std::string date;
	std::string dateArr[5];
	dateArr[0] = std::to_string(month);
	dateArr[1] = '/';
	dateArr[2] = std::to_string(day);
	dateArr[3] = '/';
	dateArr[4] = std::to_string(year);

	for (int i = 0; i < 5; i++)
	{
		date.append(dateArr[i]);
	}
	return date;
}
