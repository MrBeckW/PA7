#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#include "AttendanceManager.hpp"

/// <summary>
/// default constructor for AttendanceManager object
/// </summary>
AttendanceManager::AttendanceManager()
{
	mMasterList = new List<Data>();
	mImput.open("classList.csv");
}

/// <summary>
/// destructor for AttendanceManager, closes file and deletes list.
/// </summary>
AttendanceManager::~AttendanceManager()
{
	mImput.close();
	delete mMasterList;
}

/// <summary>
/// runs the app, calls menu function
/// </summary>
void AttendanceManager::runApp()
{
	menu();
}

/// <summary>
/// Import Records function, imports data from classList.csv file and creates a list with its contents. Overwrites any currently loaded list
/// </summary>
void AttendanceManager::importRecords()
{
	Data temp;
	std::string buffer, line;
	std::string bufferSplit[6];
	int bufferSplitInt[2];
	
	if (mMasterList->getpHead() != nullptr)
	{
		delete mMasterList;
	}
	
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

/// <summary>
/// creates a list from the data stored on masterList.csv
/// </summary>
void AttendanceManager::loadMasterList()
{
	if (mMasterList != nullptr)
	{
		std::ifstream masterImput;
		masterImput.open("masterList.csv");
		if (masterImput)//checks if filed opened correctly
		{
			std::string line;
			while (!masterImput.eof())
			{
				Data temp;
				masterImput >> temp;
				mMasterList->insertFront(temp);
			}
		}
		else
		{
			std::cout << "File failed to open\n";
		}
		masterImput.close();
	}
	else
	{
		std::cout << "Master List already loaded!\n";
	}
	
}

/// <summary>
/// stores currently loaded list to masterList.csv file
/// </summary>
void AttendanceManager::storeMasterList()
{
	if (mMasterList != nullptr)
	{
		std::ofstream masterOutput;
		masterOutput.open("masterList.csv");

		if (masterOutput)//checks if file opened correctly
		{
			ListNode<Data>* pCur = mMasterList->getpHead();
			while (pCur != nullptr)
			{
				masterOutput << *pCur; //writes node to file
				if (pCur->getpNext() != nullptr)
				{
					masterOutput << std::endl;//only adds a newline character if the current node is not the last node.
				}
				pCur = pCur->getpNext();

			}
		}
		else
		{
			std::cout << "File failed to open.\n";
		}

		masterOutput.close();
	}
	else
	{
		std::cout << "Master List is empty!\n";
	}
}

/// <summary>
/// traverses list and asks user if the person represented by each node was absent today. 
/// If they were it increments their total absences and adds a string containing todays date to the Stack containing thier absence dates
/// </summary>
void AttendanceManager::markAbsence()
{
	if (mMasterList != nullptr)
	{
		ListNode<Data>* pCur = mMasterList->getpHead();
		int selection = 0;
		Data temp;
		while (pCur != nullptr)
		{
			while (selection != 1 && selection != 2)//checks if user selection is out of bounds
			{
				std::cout << "\nWas " << pCur->getData().getName() << " absent today? YES: 1 NO: 2\n";
				std::cin >> selection;
				switch (selection)
				{
				case 1:
					temp = pCur->getData();//creates a temp Data object
					temp.incrementNumAbsences('+');//increments absence
					temp.getAbsenceDates().push(this->getTodaysDate());//adds todays date to stack of absences
					pCur->setData(temp);//updates node with updated data
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


/// <summary>
/// function generates reports about the absences of the students. Gives the user two options:
/// 1. generates report for every student
/// 2. generates report for every student that meets a certain absence number threshold. Asks the user for that threshold number.
/// </summary>
void AttendanceManager::generateReport()
{
	int selection = 0;
	while (selection != 3)
	{
		ListNode<Data>* pCur = mMasterList->getpHead();

		displayMenu(2);//displays submenu
		std::cin >> selection;

		switch (selection)
		{
		case 1:
			
			std::cout << "Students name: Most recent absence\n";//displays formatting 
			while (pCur != nullptr)
			{
				std::string temp;
				std::cout << pCur->getData().getName() << ": ";//displays name
				if (!pCur->getData().getAbsenceDates().isEmpty())
				{
					std::cout << pCur->getData().getAbsenceDates().peek() << std::endl;//displays most recent absence if it exists
				}
				else
				{
					std::cout << "N/A\n";//displays N/A if there are no absences 
				}
				pCur = pCur->getpNext();
			}
			break;
		case 2:
			int subSelection = 0;
			while (subSelection < 1)
			{
				std::cout << "Enter absence threshold for report.\n";//gathers absence threshold
				std::cin >> subSelection;
				if (subSelection < 1)
				{
					std::cout << "Threshold cannot be smaller than 1.\n";
				}
			}
			std::cout << "\nStudents name: Most recent absence\n";//displays formatting 
			while (pCur != nullptr)
			{
				if (pCur->getData().getNumAbsences() >= subSelection)//traverses list to find nodes that meet absence threshold 
				{
					std::cout << pCur->getData().getName() << ": " << pCur->getData().getAbsenceDates().peek() << std::endl;//displays name and most recent absence
				}
				pCur = pCur->getpNext();
			}
			break;
		}
	}
}

/// <summary>
/// menu function, collects users menu selection and calls respective functions
/// </summary>
void AttendanceManager::menu()
{
	int selection = 0;
	while (selection != 7)
	{
		displayMenu(1);//displays main menu
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
		case 5: generateReport();
			break;
		case 6: displayList();
			break;
		case 7:
			break;
		default: 
			std::cout << "\n---ERROR---\nSelection not valid\n";
		}
	}

}

/// <summary>
/// prints menu 
/// </summary>
/// <param name="menuSelect">1 for main menu, 2 for report menu </param>
void AttendanceManager::displayMenu(int menuSelect)
{
	switch (menuSelect)
	{
		case 1:
			std::cout << "\nWelcome to the Attendance Manager!\n\n"
				<< "---Main Menu---\n"
				<< "1. Import corse list\n"
				<< "2. Load master list\n"
				<< "3. Store master list\n"
				<< "4. Mark absences\n"
				<< "5. Generate report\n"
				<< "6. Display Master List\n"
				<< "7. Exit\n\n"
				<< "Enter Your Selection: ";
		break;
		case 2:
			std::cout << "\n---Report Menu---\n"
				<< "1. Generate report for all students.\n"
				<< "2. Generate report for students of a specific number of absences\n"
				<< "3. Exit\n\n";

	}
}

/// <summary>
/// calls the printlist function
/// </summary>
void AttendanceManager::displayList()
{
	mMasterList->printList();
}

/// <summary>
/// gets todays date and formats it into a single string
/// </summary>
/// <returns></returns>
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
