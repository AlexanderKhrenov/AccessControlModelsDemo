// System.cpp
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>
#include "System.h"

using namespace std;

//random number generation function
int random(int from, int to)
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(from, to);
	int x = distribution(generator);
	return x;
}

//random number generation function when grid is in use
int random(int from, int to, bool useGrid)
{
	if (!useGrid) {
		random_device random_device;
		mt19937 generator(random_device());
		uniform_int_distribution<> distribution(from, to);
		int x = distribution(generator);
		return x;
	}
	else {
		int categories[12] = {60, 30, 20, 12, 15, 10, 6, 4, 5, 3, 2, 1};
		int randIndex = random(1, 11);
		return categories[randIndex];
	}
}

//get object by ID
Object& System::getObj(int id)
{
	for (int i = 0; i < objectNumber; i++) {
		if (systemObjects[i].getID() == id) {
			return systemObjects[i];
		}
	}
	cerr << "Incorrect Object ID!" << endl;
	throw exception();
}

//set the number of objects in system
void System::setObjNumber(int objNum)
{
	objectNumber = objNum;
}

//set if you use grid categories or not  
void System::setUseGrid(bool useG)
{
	useGrid = useG;
}

//system initialization
System::System(int objectNumber, bool useGrid)
{
	setObjNumber(objectNumber);
	setUseGrid(useGrid);

		for (int i = 0; i < objectNumber; i++) {
			Object tempObj;
			tempObj.setID(i);
			tempObj.setCategory(random(1, 4, useGrid));
			tempObj.setSecLevel(random(1, 3));
			tempObj.setValue(random(0, 100));
			systemObjects.push_back(tempObj);
		}
}

//set current subject
void System::setCurrentSubject(int inSubjID)
{
	currentSubject = getObj(inSubjID);
}

//set current subject
void System::setCurrentSubject(Object& inSubj)
{
	currentSubject = inSubj;
}

//display all objects of current system
void System::displayAllObj()
{
	for (int i = 0; i < objectNumber; i++) {
		systemObjects[i].display();
	}
}

//display object by some ID
void System::displayObjInfo(int id)
{
	getObj(id).display();
}

//read access operation
void System::accessREAD(int id) {
	Object& tempObj = getObj(id);
	if (checkForREAD(tempObj)) {
		tempObj.display();
	}
	else {
		cout << "Access Denied!" << endl;
	}
}

//write access operation
void System::accessWRITE(int id, int newValue) {
	Object& tempObj = getObj(id);
	if (checkForWRITE(tempObj)) {
		tempObj.setValue(newValue);
		cout << "Write operation is done!" << endl;
	}
	else {
		cout << "Access Denied!" << endl;
	}
}
