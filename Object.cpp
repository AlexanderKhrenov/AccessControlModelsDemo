// Object.cpp
#include "stdafx.h"
#include <iostream>
#include "Object.h"

using namespace std;

void Object::setID(int inID)
{
	id = inID;
}

void Object::setSecLevel(int inSecLevel)
{
	securityLevel = inSecLevel;
}

void Object::setCategory(int inCategory)
{
	category = inCategory;
}

void Object::setValue(int inValue)
{
	value = inValue;
}

Object::Object()
{
	setID(-1);
	setSecLevel(1);
	setCategory(1);
	setValue(0);
}

int Object::getID()
{
	return id;
}

int Object::getSecLevel()
{
	return securityLevel;
}

int Object::getCategory()
{
	return category;
}

int Object::getValue()
{
	return value;
}

void Object::display()
{
	cout << "id=" << id << " category=" << category << " securityLevel=" << securityLevel << " value=" << value << endl;
}

void Object::secLevelUP()
{
	securityLevel++;
}

void Object::secLevelDOWN()
{
	securityLevel--;
}