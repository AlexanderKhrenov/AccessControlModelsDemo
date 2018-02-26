#pragma once
// System.h
#include <iostream>
#include <vector>
#include "Object.h"


using namespace std;

int random(int from, int to);           //random number generation function
int random(int from, int to, bool useGrid); //random number generation function when grid is in use

//general class for object System
class System
{
protected:
	int objectNumber;             //number of objects in system
	vector<Object> systemObjects; //vector that contains those Objects
	Object currentSubject;        //Obcject that will play as subject for current test
	bool useGrid;                 //mark if is grid category system in use
public:
	System(int objectNumber, bool useGrid); 
	~System();

	//for accessing System atributes
	void setObjNumber(int objNum);          //set the number of objects in system  
	void setUseGrid(bool useGrid);          //set if you use grid categories or not  
	void setCurrentSubject(int inSubjID);   //set current subject
	void setCurrentSubject(Object& inSubj);	
	void displayAllObj();                   //display objects
	void displayObjInfo(int id);            
	Object& getObj(int id);                 //get object by ID
	
	//for checking subject rights
	virtual bool checkForREAD(Object& inObj) = 0;
	virtual bool checkForWRITE(Object& inObj) = 0;

	//access operations
	void accessREAD(int id);                //read access operation
	void accessWRITE(int id, int newValue); //write access operation
};