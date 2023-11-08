#include <sstream>
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
}

void AttendanceManager::markAbsence()
{
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
