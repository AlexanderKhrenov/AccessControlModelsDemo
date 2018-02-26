#pragma once
// Session.h
#include <iostream>
#include "SystemBellaLaPadula.h"
#include "SystemBiba.h"

using namespace std;

/*simple function asking for more tests to provide*/
bool askForMore()
{
	char answer;
	cout << "Need more tests? y/n" << endl;
	cin >> answer;

	while (answer != 'y' && answer != 'n') {
		cout << "Please choose correct answer. " << endl;
		cin >> answer;
	}

	if (answer == 'n') {
		return true;
	}
	
	return false;
}


/*system test function*/
void testSystem(System* session, int subjectID, int objectNumber, bool useGrid)
{
	//SystemBellaLaPadula* session = new SystemBellaLaPadula(objectNumber, useGrid);
	//session->setCurrentSubject(subjectID);

	// show all existing objects
	cout << "All system objects: " << endl;
	session->displayAllObj();

	bool done = false;
	
	// tests for READ access
	cout << "Now testing READ rights: " << endl;
	while (!done) {
		cout << "Enter object ID for reading: " << endl;
		int objID;
		cin >> objID;
		session->accessREAD(objID);

		done = askForMore();
	}
	done = false;

	// tests for WRITE access
	cout << "Now testing WRITE rights: " << endl;
	while (!done) {
		cout << "Enter object ID for writing: " << endl;
		int objID2;
		cin >> objID2;
		cout << "Enter new value: " << endl;
		int value;
		cin >> value;
		session->accessWRITE(objID2, value);

		//check if need more attempts
		done = askForMore();

		int checkForDisplay;
		cout << "Please enter 1 if you want to display system objects and another number if you dont -> " << endl;
		cin >> checkForDisplay;
			if (checkForDisplay == 1) {
				cout << "All system objects: " << endl;
				session->displayAllObj();
		}
	}
}

//session function
void Session()
{
	int subjectID = -2;
	int objectNumber = 0;
	bool useGrid = false;
	int systemType = 0;

	cout << "Please enter test system parameters. " << endl;

	/*now collecting parameters to create system tester needs*/

	cout << "Enter number of objects in test system: " << endl;
	cin >> objectNumber;
	while (objectNumber < 2) {
		cout << "Need more objects!" << endl;
		cout << "Enter number of objects in test system: " << endl;
		cin >> objectNumber;
	}

	cout << "Do you need to use Grid? y/n" << endl;
	char answer;
	bool gridDone = false;
	cin >> answer;
	while (!gridDone) {
		if (answer == 'y' || answer == 'n') {
			gridDone = true;
			if (answer == 'y') {
				useGrid = true;
			}
		}
		else {
			cout << "Please choose correct variant. " << endl;
			cin >> answer;
		}
	}

	cout << "Set User ID: " << endl;
	cin >> subjectID;
	while (subjectID < 0) {
		cout << "ID value can not be under 0!" << endl;
		cout << "Please enter correct User ID" << endl;
		cin >> subjectID;
	}

	cout << "Bella - La Padula   OR   Biba ? 1/2" << endl;
	cin >> systemType;
	while (systemType != 1 && systemType != 2) {
		cout << "Please choose correct system type -> " << endl;
		cin >> systemType;
	}
	/*parameters are collected*/

	/*system tests*/
	if (systemType == 1) {	// for Bella La Padula system
		SystemBellaLaPadula* session = new SystemBellaLaPadula(objectNumber, useGrid);
		session->setCurrentSubject(subjectID);

		testSystem(session, subjectID, objectNumber, useGrid);
	}
	else {					// for Biba system
		SystemBiba* session = new SystemBiba(objectNumber, useGrid);
		session->setCurrentSubject(subjectID);

		testSystem(session, subjectID, objectNumber, useGrid);
	}
}
