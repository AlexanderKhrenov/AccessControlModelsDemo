#pragma once
// SystemBiba.h
#include <iostream>
#include <vector>
#include "System.h"

class SystemBiba : public System
{
public:
	SystemBiba(int objNum, bool useG) : System(objNum, useG)
	{}
	bool checkForREAD(Object& inObj);
	bool checkForWRITE(Object& inObj);
};