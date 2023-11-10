#pragma once
#include <iostream>;
#include <fstream>;
#include "Data.hpp";
#include "List.hpp";

class AttendanceManager
{
public:
	AttendanceManager();
	~AttendanceManager();

	void runApp();
	

private:
	void importRecords();//overrides masterlist with new data from classList.csv(absence data will be lost)
	void loadMasterList();//Loads the masterlist with data from masterList.csv(contains previous absence data)
	void storeMasterList();
	void markAbsence();
	void editAbsence();
	void generateReport();
	void menu();
	void displayMenu();
	void displayList();
	std::string getTodaysDate();

	List<Data>* mMasterList;
	std::ifstream mImput;
};