#pragma once
// Object.h
#include <iostream>
using namespace std;

//general object class
class Object
{
private:
	int id;
	int securityLevel;
	int category;
	int value;
public:
	Object();
	~Object() {};

	//set methods
	void setID(int inID);
	void setSecLevel(int inSecLevel);
	void setCategory(int inCategory);
	void setValue(int inValue);
	
	//get methods
	int getID();
	int getSecLevel();
	int getCategory();
	int getValue();
	void display();

	//change level by one methods
	void secLevelUP();
	void secLevelDOWN();
};